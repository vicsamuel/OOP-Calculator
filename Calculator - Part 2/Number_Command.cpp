// -*- C++ -*-
// $Id: Number_Command.cpp 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Number_Command.cpp
 */
//==============================================================================

#include "Number_Command.h"

//
// Execute (implementation)
//
void Number_Command::execute()
{
    stack_.push(number_);
}