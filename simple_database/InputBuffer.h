//
//  InputBuffer.h
//  simple_database
//
//  Created by Abhiram Rishi Prattipati on 12/13/23.
//

#include <stdio.h>

#ifndef InputBuffer_h
#define InputBuffer_h

typedef struct InputBuffer {
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

InputBuffer* new_input_buffer();
void print_prompt();
void read_input(InputBuffer* input_buffer);
void close_input_buffer(InputBuffer* input_buffer);

#endif /* InputBuffer_h */
