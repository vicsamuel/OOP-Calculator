// -*- C++ -*-
// $Id: Expresion_Facade.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Expresion_Facade.h
 */
//==============================================================================

#include "Binary_Command.h"
#include "Abstract_Factory.h"
#include "Stack_Factory.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Modulus_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"


#ifndef _EXPRESSION_FACADE_H_
#define _EXPRESSION_FACADE_H_

/**
 * @class Expresion_Facade
 *
 * Child of Binary_Command
 */
class Expression_Facade
{
public:
    /// Constructor (passed)
    Expression_Facade(Stack<int> & stack, char sign) : stack_(stack), sign_(sign) {}

    /// Destructor
    ~Expression_Facade() {}

    /// Evaluate expression
    Command* evaluate_expression(Stack<int> &stack, char sign);

private:
    /// Constructor (default)
    Expression_Facade();

    /// Constructor (copy)
    Expression_Facade(Expression_Facade &command);

    Stack<int> stack_;
    char sign_;
    

    /// Commands
    Add_Command *add;
    Subtract_Command *subtract;
    Modulus_Command *modulus;
    Multiply_Command *multiply;
    Divide_Command *divide;
};

#endif // !defined _EXPRESSION_FACADE_H_