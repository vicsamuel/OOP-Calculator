// -*- C++ -*-
// $Id: Infix_Postfix_Helper.cpp 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Infix_Postfix_Helper.cpp
 */
//==============================================================================

#include "Infix_Postfix_Helper.h"

/// Array of operator precedence
int op_prec[127];

//
// op_precedence()
//
void op_precedence()
{
    op_prec['('] = 3;
    op_prec[')'] = 3;
    op_prec['%'] = 2;
    op_prec['*'] = 2;
    op_prec['/'] = 2;
    op_prec['+'] = 1;
    op_prec['-'] = 1;
}

//
// is_operator()
//
bool is_operator(char tok)
{
    switch (tok)
    {
    case ')':
        return true;
    case '(':
        return true;
    case '%':
        return true;
    case '*':
        return true;
    case '/':
        return true;
    case '+':
        return true;
    case '-':
        return true;
    default:
        return false;
    }
}

//
// is_letter (passed char)
//
bool is_letter(char tok)
{
    return (tok >= 'a' && tok <= 'z') ? true : false;
}

//
// op_priority
//
bool op_priority(int top_op, int bottom_op)
{
    return (op_prec[top_op] >= op_prec[bottom_op]);
}