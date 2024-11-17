#include "arguments.h"

bool ValidateArguments(int argc, char** argv) {
    int is_digit_check_index = 0;
    
    if (argc == 1 || argc > 5) {
        return false;
    }

    if (argc == 2 && (strcmp(argv[1], "-h") != 0 && strcmp(argv[1], "-t") != 0)) {
        return false;
    }

    if (argc < 5 && strcmp(argv[1], "-d") == 0) {
        return false;
    }

    // terminal mode checks
    if (argc < 3 && strcmp(argv[1], "-t") == 0) {
        return false;
    }

    // daemon mode checks
    if (argc == 5) {
        if (strcmp(argv[1], "-d") != 0) {
            return false;
        }

        if (strcmp(argv[2], "-rp5") != 0 && strcmp(argv[2], "-x86") != 0) {
            return false;
        }

        while (argv[4][is_digit_check_index] != '\0') {
            if (argv[4][is_digit_check_index] < '0' || argv[4][is_digit_check_index] > '9') {
                return false;
            }

            is_digit_check_index++;
        }
    }

    return true;
}

void InvalidArguments() {
    printf("Invalid arguments, use -h for help\n");
}

void HelpMenu() {
    printf("./pmu [1] [2] [3] [4]\n");
    printf("\t[1] -h: Displays all of the available arguments\n");
    printf("\t[1] -[t or d]: Specifies the mode the application should run at (t: terminal, d: daemon)\n");
    printf("\t[2] -[rp5 or x86]: Specifies the platform\n");
    printf("\t[3] -filename: Specifies the filename the task should save the data ar, only available in daemon mode\n");
    printf("\t[4] -number: Specifies the time the task should run for, only available in daemon mode\n");

    printf("\n");
    printf("Note: Terminal mode requires only the parameter [2], whilst daemon mode requires all of the parameters\n");
}

MODE GetMode(char* first_argument) {
    if (strcmp(first_argument, "-t") == 0) {
        return Terminal;
    }

    if (strcmp(first_argument, "d") == 0) {
        return Daemon;
    }

    return Mode_NaN;
}

PLATFORM GetPlatform(char* second_argument) {
    if (strcmp(second_argument, "-rp5") == 0) {
        return RP5;
    }

    if (strcmp(second_argument, "-x86") == 0) {
        return x86;
    }

    return Platforn_NaN;
}

char* GetFilename(char* third_argument) {
    char* filename = CreateBuffer(DAEMON_OUTPUT_FILENAME_LENGTH);

    strcpy(filename, third_argument);

    return filename;
}

int GetRuntime(char* fourth_argument) {
    return atoi(fourth_argument);
}