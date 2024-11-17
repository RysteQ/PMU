#ifndef argumentsh
#define argumentsh

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "buffer.h"

#define DAEMON_OUTPUT_FILENAME_LENGTH 1024

typedef enum MODE
{
    Terminal,
    Daemon,
    Mode_NaN
} MODE;

typedef enum PLATFORM
{
    RP5,
    x86,
    Platforn_NaN
} PLATFORM;

/// @brief Validates the arguments provided
/// @param argc Argument counter 
/// @param argv Arguments
/// @return False if the arguments are invalid, otherwise true
bool ValidateArguments(int argc, char** argv);

/// @brief Displays the invalid arguments error message
void InvalidArguments();

/// @brief Displays the help message
void HelpMenu();

/// @brief Checks the mode provided
/// @param first_argument The first argument provided in the main parameter argv
/// @return The mode specified by the user
MODE GetMode(char* first_argument);

/// @brief Checks the platform provided
/// @param first_argument The second argument provided in the main parameter argv
/// @return The platform specified by the user
PLATFORM GetPlatform(char* second_argument);

/// @brief Gets the filename the daemon process data should be saved at
/// @param third_parameter The third argument of the main parameter argv
/// @return A copy of the filename
char* GetFilename(char* third_argument);

/// @brief Get the time that the daemon process should run for
/// @param fourth_argument The fourth argument of the main parameter argv
/// @return The time in minutes
int GetRuntime(char* fourth_argument);

#endif