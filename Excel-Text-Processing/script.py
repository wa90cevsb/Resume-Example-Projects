import sys
import os

parts_list = []
lines = []
footprints = {}
feeders = {}
rotation_offsets = {}
ban_list = []



# footprints file
with open("C:/Users/maste/Desktop/PickPlace_format/footprints.txt") as f:
    lines = f.readlines()
# For each line in footprint file
for line in lines:
    line = line.strip()
    if line:
        # Altium footprints become a key to machine footprints
        temp_list = [item.strip() for item in line.split(',')]
        footprints[temp_list[0]] = temp_list[1]

# feeder locations (part specific)
with open('C:/Users/maste/Desktop/PickPlace_format/feeders.txt') as f:
    lines = f.readlines()
# For each line in feeders file
for line in lines:
    line = line.strip()
    if line:
        # Comment/part name is stored as a key to the feeder value
        temp_list = [item.strip() for item in line.split(',')]
        feeders[temp_list[0]] = temp_list[1]

# rotation offsets
with open('C:/Users/maste/Desktop/PickPlace_format/rotations.txt') as f:
    lines = f.readlines()
for line in lines:
    line = line.strip()
    if line:
        temp_list = [item.strip() for item in line.split(',')]
        # Comment of the part becomes a key to the offset value
        rotation_offsets[temp_list[0]] = int(temp_list[1])

# the ban list disallows some parts from entering the program
with open('C:/Users/maste/Desktop/PickPlace_format/ban_list.txt') as f:
    lines = f.readlines()
for line in lines:
    line = line.strip()
    if line:
        ban_list.append(line)

if sys.argv[1]:
    # Open data file
    file_path = sys.argv[1]
    with open(file_path) as f:
        lines = f.readlines()
else:
    file_path = input('Enter file to parse: ')
    # Open data file
    with open(file_path) as f:
        lines = f.readlines()

# Header columns
columns = []
for index, line in enumerate(lines):
    line = line.strip()
    if line:
        # At line 13 we have the headers
        if index == 12:
            columns = [item.strip().replace('"','') for item in line.split(',')]
            columns.append('Feeder')
        # Part data
        elif index > 12:
            d = {}
            skip_flag = 0
            skip_times = 0
            # Create a list containing the part data and remove the quotes
            data = [item.strip().replace('"','') for item in line.split(',')]
            for i, elem in enumerate(data):
                # Skip flag means part had a , in the comment
                # If no flag, run as normal
                if not(skip_flag):
                    # If data is a key in footprints, replace the footprint
                    try:
                        d[columns[i-skip_times]] = footprints[elem]
                    # otherwise, store the data and replace spaces
                    except KeyError:
                        d[columns[i-skip_times]] = elem.replace(' ','_')
                
                # If skip_flag is set, do nothing
                else:
                    skip_flag = 0
                    
                # Parts that need to skip a data
                if elem == 'BZX84-C10':
                    skip_times += 1
                    skip_flag = 1
            
            # If the footprint is banned, skip the part
            if d['Footprint'] in ban_list:
                print("Skipping: " + str(d))
            else:
                try:                 # Check if the comment has an assigned feeder
                    d['Feeder'] = feeders[d['Comment']]
                except KeyError:     # Otherwise set feeder to 0 (auto)
                    d['Feeder'] = 0
                    
                d['Rotation'] = int(d['Rotation'])
                try:                 # Check if the comment needs a rotation offset
                    d['Rotation'] += rotation_offsets[d['Comment']]
                except KeyError:
                    pass             # Otherwise pass
                
                try:                 # Rotation offset for bottom layer components
                    if (d['Layer'] == 'BottomLayer'):
                        d['Rotation'] -= 45
                except KeyError:
                    pass
                    
                # Constrain rotation to 0-359 degrees
                d['Rotation'] = d['Rotation'] % 360
                
                # Add the dictionary to our parts list
                print('Appending: ' + str(d))
                parts_list.append(d)

import re
# Sort key takes in a dict object and returns a human legible
# alphanumeric sort of the value at value
def sort_key(value):
    convert = lambda text: int(text) if text.isdigit() else text
    g = lambda obj: tuple(convert(c) for c in re.split('([0-9]+)', obj[value]))
    return g
# Sort the list
parts_list = sorted(parts_list, key=sort_key('Designator'))

# Find output file path
file_path = file_path.replace('.csv','.txt')
print('\nOutput will save to: ' + file_path)
while True:
    ch = input('Ok? Y/N: ')
    if ch.lower() == 'y':
        break
    elif ch.lower() == 'n':
        file_path = input('Input file path: ')
        break

# If layer is present, treat board as double-sided
if 'Layer' in columns:
    # Define file paths
    file_path_top = file_path.replace('.txt',' - Top.txt')
    file_path_bottom = file_path.replace('.txt',' - Bottom.txt')
    # Open files
    with open(file_path_top, 'w') as f_t, open(file_path_bottom, 'w') as f_b:
        for part in parts_list:
            # If in top layer, write to to layer file
            if part['Layer'] == 'TopLayer':
                for i in range(len(part)):
                    if not columns[i] == 'Layer':
                        f_t.write(str(part[columns[i]]) + '  ')
                f_t.write('\n')
            # If in bottom layer or is a via, write to bottom layer file
            if (part['Layer'] == 'BottomLayer') or (part['Footprint'] == 'Via'):
                for i in range(len(part)):
                    if not columns[i] == 'Layer':
                        f_b.write(str(part[columns[i]]) + '  ')
                f_b.write('\n')

# Single-sided board output
else:
    with open(file_path, 'w') as f:
        for part in parts_list:
            for i in range(len(part)):
                f.write(str(part[columns[i]]) + '  ')
            f.write('\n')
    
        
print('\nDone saving output.')
os.system('pause')