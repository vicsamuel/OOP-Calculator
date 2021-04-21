// -*- C++ -*-
// $Id: Abstract_Factory.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Abstract_Factory.h
 */
//==============================================================================

#ifndef _ABSTRACT_FACTORY_H_
#define _ABSTRACT_FACTORY_H_

#include "Binary_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"
#include "Number_Command.h"

/**
 * @class Abstract_Factory
 *
 * Interface for the abstract factory for the calculator
 */
class Abstract_Factory
{
public:
    /// Number command creation (pure virtual)
    virtual Number_Command * make_num_cmd(int num) = 0;

    /// Add Command creation (pure virtual)
    virtual Add_Command * make_add_cmd(void) = 0;
    
    /// Subtract Command creation (pure virtual)
    virtual Subtract_Command * make_sub_cmd(void) = 0;
    
    /// Multiply Command creation (pure virtual)
    virtual Multiply_Command * make_mul_cmd(void) = 0;

    /// Divide Command creation (pure virtual)
    virtual Divide_Command * make_div_cmd(void) = 0;

    /// Modulus Command creation (pure virtual)
    virtual Modulus_Command * make_mod_cmd(void) = 0;
    
};

#endif // !defined _ABSTRACT_FACTORY_H_
