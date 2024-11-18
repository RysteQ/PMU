#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include "Platforms/Raspberry Pi 5/RP5PMU.h"
#include "Platforms/x86/x86PMU.h"
#include "Utils/buffer.h"
#include "Utils/arguments.h"

int main(int argc, char** argv)
{
    if (ValidateArguments(argc, argv) == false)
    {
        InvalidArguments();
        exit(-1);
    }

    if (strcmp(argv[1], "-h") == 0)
    {
        HelpMenu();
        exit(0);
    }

    MODE mode = GetMode(argv[1]);
    PLATFORM platform = GetPlatform(argv[2]);
    char* filename;
    int time = 0;

    if (platform == x86)
    {
        // x86 requires sudo mode unlike the RPI mode
        if (getuid())
        {
            printf("x86 mode needs sudo privileges\n");
            return 0;
        }
    }

    if (mode == Terminal)
    {
        switch (platform)
        {
            case RPI:
                RP5_TerminalMode();
                break;
            
            case x86:
                X86_TerminalMode();
                break;

            default:
                printf("Error reading the platform\n");
                exit(-1);
                break;
        }
    }
    else
    {
        filename = GetFilename(argv[3]);
        time = GetRuntime(argv[4]);

        switch (platform)
        {
            case RPI:
                RP5_DaemonMode(filename, time);
                break;
            
            case x86:
                X86_DaemonMode(filename, time);
                break;

            default:
                printf("Error reading the platform\n");
                exit(-1);
                break;
        }
    }

    return 0;
}