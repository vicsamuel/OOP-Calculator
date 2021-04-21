// -*- C++ -*-
// $Id: Expression_Facade.cpp 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Expression_Facade.cpp
 */
//==============================================================================

#include "Expression_Facade.h"

Command* Expression_Facade::evaluate_expression(Stack<int> &stack, char sign)
{
    Command* cmd;
    
    switch (sign)
    {
    case '%':
        modulus = new Modulus_Command(stack);
        return modulus;
    case '*':
        multiply = new Multiply_Command(stack);
        return multiply;
    case '/':
        divide = new Divide_Command(stack);
        return divide;
    case '+':
        add = new Add_Command(stack);
        return add;
    case '-':
        subtract = new Subtract_Command(stack);
        return subtract;
    default:
        std::cout << "Evaluation of expression failed!" << '\n';
    }
    return cmd;
}