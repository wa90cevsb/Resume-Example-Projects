#include "BT_Audio.h"

// Variable for sprintf
uint8_t pr[100];
// Variables for Serial()
uint8_t ch,comm[20],count;
// Variables for Parse()
uint8_t *prscmd,code[20],arg1[20],arg2[20],i;


void print(uint8_t *s)
{
    while (*s)
        EUSART1_Write(*s++);
}

void Parse()
{
    prscmd = strtok(comm, " ");
    
    for (i = 0; prscmd; i++)
    {
        if (!i)
            strcpy(code,prscmd);
        else if (i == 1)
            strcpy(arg1,prscmd);
        else if (i ==2)
            strcpy(arg2,prscmd);
        prscmd = strtok(NULL, " ");
    }
    
    if (code[0] == 'h')
    {   // Help command
        print("\n  h - help message\n"
                "  d - display status\n"
                "  v - set volume\n"
                "  s - switch bt/aux\n"
                "  m - toggle mute\n"
                "  ");
    }
    else if (code[0] == 'd')
    {   // Display command
        print("\nStatus:");
        uint8_t voltage = GetVoltage();
        sprintf(pr, "\n  Input: %d.%dV", voltage/10, voltage%10);
        print(pr);
        sprintf(pr,"\n  Volume:  Path:  Mute:"
                   "\n  %3d/%-3d   ", vol, min_vol);
        print(pr);
        print(SWITCH_STATE_GetValue() ? " BT    " : "AUX    ");
        print(SWITCH_EN_GetValue() ? "Y" : "N");
        print("\n");
    }
    else if (code[0] == 'v')
    {
        print("\nSet volume to ");
        print(arg1);
        vol = atoi(arg1);
        SetVolume(atoi(arg1), 0);
        SetVolume(atoi(arg1), 1);
    }
    else if (code[0] == 's')
    {
        print("\nSwitching audio path");
        SWITCH_STATE_Toggle();
    }
    else if (code[0] == 'm')
    {
        print("\nToggling mute");
        SWITCH_EN_Toggle();
    }
    print(PROMPT);
}

void Serial()
{
    if (EUSART1_is_rx_ready())
    {
        ch = EUSART1_Read();
        
        if (ch == '\b')
        {   // Backspace
            if (count)
            {
                count--;
                print("\b \b");
            }
        }
        else if (ch == '\r')
        {   // Return, execute command
            comm[count] = '\0';
            count = 0;
            Parse();
        }
        else if (count < 20)
        {   // Append input char to command
            comm[count++] = ch;
            EUSART1_Write(ch);
        }
    }
}
