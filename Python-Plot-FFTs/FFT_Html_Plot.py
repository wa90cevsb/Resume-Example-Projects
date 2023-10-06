import matplotlib.pyplot as plt
import numpy as np
from http.server import HTTPServer,BaseHTTPRequestHandler
from mimetypes import MimeTypes
import urllib
import random
from time import sleep,perf_counter

import matplotlib.style as pltstyle
pltstyle.use('fast')


# sampling rate
sr = 20000
# sampling interval
ts = 1.0/sr
t = np.arange(0,1,ts)
x = 0
X = 0
freq = 0
refresh_rate = 3

class PlotRequestHandler(BaseHTTPRequestHandler):
    # Function override for GET request handler
    def do_GET(self):
        # path '/' means homepage
        if self.path == '/':
            # HTML string
            html =  f'''<html>
                            <title>
                                COM Module Server
                            </title>
                            <head>
                                <meta http-equiv="refresh" content="{refresh_rate};URL=\'http://{self.server.server_name}:{self.server.server_port}{self.path}\'" />
                            </head>
                            <body>
                                <img src="plt.png" />
                            </body>
                        '''
            # Send 200 (OK) response
            self.send_response(200)
            # Send header type text/html
            self.send_header('Content-type', 'text/html')
            self.end_headers()
            # wfile is a writeable file where we send the data to
            self.wfile.write(html.encode('utf-8'))
        
        # path for file retrieval
        elif self.path == '/plt.png':
            # Image filepath, but remove the leading '/'
            img = self.path[1:]
            # Open image file
            imgf = open(img, 'rb').read()
            # Get media type of file
            mimetype = MimeTypes().guess_type(img)[0]
            # Serve image file with the associated MIME type
            self.send_response(200)
            self.send_header('Content-type', mimetype)
            self.end_headers()
            # Output to wfile
            self.wfile.write(imgf)
        
        # Unknown path, send 404
        else:
            self.send_response(404)
            self.send_header("Content-type", "text/html")
            self.end_headers()

# Thread for running the HTTP server
def http_serve_thread(address, port):
    httpd = HTTPServer((address, port), PlotRequestHandler)
    print(f'Serving on http://{httpd.server_name}:{httpd.server_port} ...')
    httpd.serve_forever()

# Thread for graphing and saving the plot
def plot_graph_thread():
    while 1:
        # 2s loop
        sleep(2)

        # Benchmark performance
        start = perf_counter()
        # Create the plot
        figure, ax = plt.subplots(2, 1)

        # Plot the first 8000 data points of the input wave
        ax[0].plot(t[:8000], x[:8000])
        ax[0].set_title(f'Input Wave (composed of 60Hz and other random numbers)')
        ax[0].set_xlabel('T (s)')

        # plot the first 300 data points of the transformed wave
        ax[1].stem(freq[:300], np.abs(X[:300]), 'b', \
                        markerfmt=" ", basefmt="-b")
        ax[1].set_xlabel('1/T (Hz)')
        ax[1].set_ylabel('FFT Amplitude |X(freq)|')
        ax[1].set_xlim(0, 120)
        ax[1].set_title("FFT")

        # Save the image to plt.png
        plt.savefig("plt.png")
        plt.close()

        # Benchmark performance
        end = perf_counter()
        print(f'Image creation: {end-start} seconds')

def uC_status_thread():
    while 1:
        sleep(1)



import threading
from numpy.fft import fft
import plac

@plac.opt('address', 'HTTP server address', type=str)
@plac.opt('port', 'HTTP server port', type=int)
@plac.opt('refresh', 'Refresh rate of server', type=int)
def main(address='', port=5000, refresh=3):
    global refresh_rate
    refresh_rate = refresh
    # Create and run the plotting thread
    t1 = threading.Thread(target=plot_graph_thread)
    t1.start()
    # Create and run the http thread
    t2 = threading.Thread(target=http_serve_thread,args=(address, port))
    t2.start()
    # Create and run the uC status thread
    t3 = threading.Thread(target=uC_status_thread)
    t3.start()

    # Global variables accessed by the graphing thread
    global x
    global X
    global t
    global freq
    while 1:
        # Create a random wave
        wave = random.randrange(0, 1200)*0.1
        amp = random.randrange(1, 30)*0.1
        x = amp*np.sin(2*np.pi*wave*t)

        wave = random.randrange(0, 1200)*0.1
        amp = random.randrange(1, 30)*0.1
        x += amp*np.sin(2*np.pi*wave*t)

        wave = 60
        amp = random.randrange(30, 80)*0.1
        x += amp*np.sin(2*np.pi*wave*t)

        # Perform FFT and benchmark performance
        start = perf_counter()
        X = fft(x)
        N = len(X)
        n = np.arange(N)
        T = N/sr
        freq = n/T
        end = perf_counter()
        print(f'FFT Time: {end-start} seconds')

        sleep(3)

    # Wait for all threads to complete
    t1.join()
    t2.join()
    t3.join()

if __name__ == '__main__':
    plac.call(main)