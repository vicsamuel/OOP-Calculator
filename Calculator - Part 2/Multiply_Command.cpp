// -*- C++ -*-
// $Id: Multiply_Command.cpp 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Multiply_Command.cpp
 */
//==============================================================================

#include "Multiply_Command.h"

//
// Execute (implementation)
//
int Multiply_Command::evaluate(int num1, int num2) const
{
    return (num1 * num2);
}
