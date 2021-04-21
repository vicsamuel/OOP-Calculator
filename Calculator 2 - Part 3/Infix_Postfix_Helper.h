// -*- C++ -*-
// $Id: Infix_Postfix_Helper.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Infix_Postfix_Helper.h
 */
//==============================================================================

#ifndef _INFIX_POSTFIX_HELPER_H_
#define _INFIX_POSTFIX_HELPER_H_

#include <stdio.h>

/// Struct to keep track of variables
typedef struct var
{
    int val;
    char name;
    bool operator==(struct var &RHS)
    {
        return (this->val == RHS.val && this->name == RHS.name) ? true : false;
    }
} var;

typedef struct exp_tok
{
    int exp_val;
    bool is_num;
} exp_tok;

/// Sets the operator precedence
void op_precedence(void);

/// Checks if value is operator (passed char)
bool is_operator(char tok);

/// Checks if value is letter (passed char)
bool is_letter(char tok);

/// Checks the operator priority
bool op_priority(int top_op, int bottom_op);

#endif // !define _INFIX_POSTFIX_HELPER_H_