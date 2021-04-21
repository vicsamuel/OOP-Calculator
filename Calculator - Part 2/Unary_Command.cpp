// -*- C++ -*-
// $Id: Unary_Command.cpp 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Unary_Command.cpp
 */
//==============================================================================

#include "Unary_Command.h"

//
// Execute (implementation)
//
void Unary_Command::execute()
{
    stack_.push(this->evaluate(stack_.pop()));
}