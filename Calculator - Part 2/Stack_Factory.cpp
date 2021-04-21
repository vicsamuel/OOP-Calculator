// -*- C++ -*-
// $Id: Stack_Factory.cpp 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Stack_Factory.cpp
 */
//==============================================================================

#include "Stack_Factory.h"

Stack_Factory::Stack_Factory(Stack<int> &stack)
    :   stack_(stack)
{
}

Number_Command *Stack_Factory::make_num_cmd(int num)
{
    return new Number_Command(stack_, num);
}

Add_Command *Stack_Factory::make_add_cmd(void)
{
    return new Add_Command(stack_);
}

Subtract_Command *Stack_Factory::make_sub_cmd(void)
{
    return new Subtract_Command(stack_);
}

Multiply_Command *Stack_Factory::make_mul_cmd(void)
{
    return new Multiply_Command(stack_);
}

Divide_Command *Stack_Factory::make_div_cmd(void)
{
    return new Divide_Command(stack_);
}

Modulus_Command *Stack_Factory::make_mod_cmd(void)
{
    return new Modulus_Command(stack_);
}

Stack_Factory::~Stack_Factory()
{
}