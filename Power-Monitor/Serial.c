#include "HD_Power.h"

uint8_t ch,com[COM_LENGTH],com_count;
uint8_t test_unlock;

void print(char *s)
{
    while (*s)
        EUSART1_Write(*s++);
}

void ExecuteCommand()
{
    uint8_t *prscmd,code[10],arg1[10],arg2[10],count;
    char pr[50];
    count = 1;
    
    prscmd = strtok(com, " ");
    while (prscmd != NULL)
    {
        if (count == 1)
        {
            strcpy(code,prscmd);
        }
        else if (count == 2)
        {
            strcpy(arg1,prscmd);
        }
        else if (count == 3)
        {
            strcpy(arg2,prscmd);
        }
        prscmd = strtok(NULL, " ");
        count++;
    }
            
    if (code[0] == 'h')
    {
        print("\nhelp");
    }
    if (code[0] == 'd')
    {
        sprintf(pr,"\nIgn ADC: %d.%dV", GetIgnition()/10, GetIgnition()%10);
        print(pr);
        sprintf(pr,"\nVolt ADC: %d.%dV", GetVoltage()/10, GetVoltage()%10);
        print(pr);
        sprintf(pr,"\nTimeout: %d min", GetTimeout()/60);
        print(pr);
        sprintf(pr,"\nThreshold: %dV", GetVoltThresh()/10);
        print(pr);        
    }
    if (code[0] == 't')
    {
        switch (arg1[0])
        {
            case '4':
                ACC4_Toggle();
                print("\nACC4 turned ");
                print(ACC4_GetValue() ? "on" : "off");;
                break;
            case '5':
                ACC5_Toggle();
                print("\nACC5 turned ");
                print(ACC5_GetValue() ? "on" : "off");;
                break;
            case '6':
                ACC6_Toggle();
                print("\nACC6 turned ");
                print(ACC6_GetValue() ? "on" : "off");;
                break;
            case '7':
                ACC7_Toggle();
                print("\nACC7 turned ");
                print(ACC7_GetValue() ? "on" : "off");;
                break;
            case '8':
                ACC8_Toggle();
                print("\nACC8 turned ");
                print(ACC8_GetValue() ? "on" : "off");;
                break;
            case '9':
                ACC9_Toggle();
                print("\nACC9 turned ");
                print(ACC9_GetValue() ? "on" : "off");;
                break;
            case '1':
                ACC10_Toggle();
                print("\nACC10 turned ");
                print(ACC10_GetValue() ? "on" : "off");;
                break;
            case 'a':
                ACC4_Toggle();
                print("\nACC4 turned ");
                print(ACC4_GetValue() ? "on" : "off");;
                ACC5_Toggle();
                print("\nACC5 turned ");
                print(ACC5_GetValue() ? "on" : "off");;
                ACC6_Toggle();
                print("\nACC6 turned ");
                print(ACC6_GetValue() ? "on" : "off");;
                ACC7_Toggle();
                print("\nACC7 turned ");
                print(ACC7_GetValue() ? "on" : "off");;
                ACC8_Toggle();
                print("\nACC8 turned ");
                print(ACC8_GetValue() ? "on" : "off");;
                ACC9_Toggle();
                print("\nACC9 turned ");
                print(ACC9_GetValue() ? "on" : "off");;
                ACC10_Toggle();
                print("\nACC10 turned ");
                print(ACC10_GetValue() ? "on" : "off");;
                break;
        }
    }
    if (code[0] == '?')
    {
        sprintf(pr, "\nACC4:  %3d / %-3d", current[0], 7*AMPS);
        print(pr);
        sprintf(pr, "\nACC5:  %3d / %-3d", current[1], 5*AMPS);
        print(pr);
        sprintf(pr, "\nACC6:  %3d / %-3d", current[2], 5*AMPS);
        print(pr);
        sprintf(pr, "\nACC7:  %3d / %-3d", current[3], 3*AMPS);
        print(pr);
        sprintf(pr, "\nACC8:  %3d / %-3d", current[4], 3*AMPS);
        print(pr);
        sprintf(pr, "\nACC9:  %3d / %-3d", current[5], 2*AMPS);
        print(pr);
        sprintf(pr, "\nACC10: %3d / %-3d", current[6], 2*AMPS);
        print(pr);
    }
}

void ProcessSerial()
{
    if (EUSART1_is_rx_ready())
    {
        ch = EUSART1_Read();
        if (ch == '\r')
        {
            com[com_count] = 0;
            com_count = 0;
            ExecuteCommand();
            print(PROMPT);
        }
        else if (ch == '\b')
        {
            if (com_count)
            {
                print("\b \b");
                com_count--;
            }
        }
        else if (com_count < COM_LENGTH-1)
        {
            EUSART1_Write(ch);
            com[com_count] = ch;
            com_count++;
        }
    }
}
