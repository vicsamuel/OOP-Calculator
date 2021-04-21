// -*- C++ -*-
// $Id: Binary_Command.cpp 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Binary_Command.cpp
 */
//==============================================================================

#include "Binary_Command.h"

//
// Execute (implementation)
//
void Binary_Command::execute()
{
    int number1 = stack_.pop();
    int number2 = stack_.pop();

    stack_.push(this->evaluate(number1, number2));
}