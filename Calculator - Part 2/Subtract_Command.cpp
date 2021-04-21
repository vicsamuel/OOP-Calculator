// -*- C++ -*-
// $Id: Subtract_Command.cpp 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Subtract_Command.cpp
 */
//==============================================================================

#include "Subtract_Command.h"

//
// Execute (implementation)
//
int Subtract_Command::evaluate(int num1, int num2) const
{
    return (num2 - num1);
}
