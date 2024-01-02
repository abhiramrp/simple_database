//
//  Keywords.h
//  simple_database
//
//  Created by Abhiram Rishi Prattipati on 12/13/23.
//

#ifndef Keywords_h
#define Keywords_h

#include <stdio.h>

#include "InputBuffer.h"
#include "Table.h"
#include "Cursor.h"

#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255

typedef enum ExecuteResult {
    EXECUTE_SUCCESS,
    EXECUTE_TABLE_FULL
} ExecuteResult;

typedef enum MetaCommandResult{
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

typedef enum PrepareResult{
    PREPARE_SUCCESS,
    PREPARE_SYNTAX_ERROR,
    PREPARE_NEGATIVE_ID,
    PREPARE_STRING_TOO_LONG,
    PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT }
StatementType;

typedef struct Statement{
    StatementType type;
    Row row_to_insert;
} Statement;

MetaCommandResult do_meta_command(InputBuffer* input_buffer, Table *table);
PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);

ExecuteResult execute_insert(Statement* statement, Table* table);
ExecuteResult execute_select(Statement* statement, Table* table);
ExecuteResult execute_statement(Statement* statement, Table* table);

#endif /* Keywords_h */
