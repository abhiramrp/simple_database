//
//  Cursor.h
//  simple_database
//
//  Created by Abhiram Rishi Prattipati on 1/2/24.
//

#ifndef Cursor_h
#define Cursor_h

#include <stdio.h>
#include <stdbool.h>

#include "Table.h"


typedef struct Cursor {
    Table* table;
    uint32_t row_num;
    bool end_of_table;
} Cursor;

Cursor* table_start(Table* table);
Cursor* table_end(Table* table);

void* cursor_value(Cursor* cursor);
void cursor_advance(Cursor* cursor);

#endif /* Cursor_h */
