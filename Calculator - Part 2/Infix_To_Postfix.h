// -*- C++ -*-
// $Id: Infix_To_Postfix.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Infix_To_Postfix.h
 */
//==============================================================================

#include <iostream>
#include <sstream>
#include <string>

#include "Stack.h"
#include "Queue.h"
#include "Abstract_Factory.h"
#include "Stack_Factory.h"
#include "Expression_Facade.h"

#ifndef _INFIX_TO_POSTFIX_H_
#define _INFIX_TO_POSTFIX_H_

/// Creates command through stack factory based on operator
Command *op_command(char op, Stack_Factory &fac);

/// Infix to postfix function
void infix_to_postfix(std::string input);

#endif // !defined _INFIX_TO_POSFIX_H_