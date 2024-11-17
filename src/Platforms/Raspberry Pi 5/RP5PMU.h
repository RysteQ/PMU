#ifndef rpmuh
#define rpmuh

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <time.h>

#include "../../Utils/buffer.h"

#define PMU_READINGS_DIGIT_ACCURACY 4 // DO NOT INCREASE THIS BEYOND 8
#define PMU_BUFFER_SIZE 8
#define PMU_GENCMD_BUFFER_SIZE 1024

/// @param genc_result The output of the PMIC
/// @return Returns the ampers the processor is currently running at
double RP5_GetAmpers(char* genc_result);

/// @param genc_result The output of the PMIC
/// @return Returns the voltage the processor is currently running at
double RP5_GetVoltage(char* genc_result);

/// @brief Executes the basic set of instructions to get the PMIC data to the result buffer
/// @param result Must be supplied with a buffer of size 1024, works as an output
void RP5_gencmd(char* result);

/// @brief Runs the terminal mode RP5 platform PMU tasl
void RP5_TerminalMode();

/// @brief Runs the daemon mode RP5 platform PMU task
/// @param filename The filename to save the data as (will be saved as filename + the minute)
/// @param minutes_to_run The minutes to run the task before it exits
void RP5_DaemonMode(const char* filename, int minutes_to_run);

#endif