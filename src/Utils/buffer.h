#ifndef bufferh
#define bufferh

#include <stdlib.h>

/// @brief Dynamically allocated a new buffer
/// @param size The size of the new buffer
/// @return The newly made buffer
char* CreateBuffer(int size);

/// @brief Empties the buffer with all zeroes
/// @param buffer The buffer to empty
/// @param size The size of the buffer
void EmptyBuffer(char buffer[], int size);

#endif