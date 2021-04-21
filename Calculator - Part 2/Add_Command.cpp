// -*- C++ -*-
// $Id: Add_Command.cpp 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Add_Command.cpp
 */
//==============================================================================

#include "Add_Command.h"

//
// Execute (implementation)
//
int Add_Command::evaluate(int num1, int num2) const
{
    return (num1 + num2);
}
