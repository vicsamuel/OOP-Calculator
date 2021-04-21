// -*- C++ -*-
// $Id: Modulus_Command.cpp 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Modulus_Command.cpp
 */
//==============================================================================

#include "Modulus_Command.h"

//
// Execute (implementation)
//
int Modulus_Command::evaluate(int num1, int num2) const
{
    if (num2 == 0)
    {
        throw std::runtime_error("Division by zero! Cannot complete evaluation.");
    }
    return (num1 % num2);
}
