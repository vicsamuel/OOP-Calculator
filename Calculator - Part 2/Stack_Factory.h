// -*- C++ -*-
// $Id: Stack_Factory.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Stack_Factory.h
 */
//==============================================================================

#ifndef _STACK_FACTORY_H_
#define _STACK_FACTORY_H_

#include "Abstract_Factory.h"
#include "Expression_Facade.h"
#include "Stack.h"

/**
 * @class Stack_Factory
 *
 * Interface for the abstract factory for the calculator
 */
class Stack_Factory : public Abstract_Factory
{
public:
    /// Constructor (passed)
    Stack_Factory(Stack<int> &stack);

    /// Number command creation (pure virtual)
    virtual Number_Command * make_num_cmd(int num);

    /// Add Command creation (pure virtual)
    virtual Add_Command * make_add_cmd(void);
    
    /// Subtract Command creation (pure virtual)
    virtual Subtract_Command * make_sub_cmd(void);
    
    /// Multiply Command creation (pure virtual)
    virtual Multiply_Command * make_mul_cmd(void);

    /// Divide Command creation (pure virtual)
    virtual Divide_Command * make_div_cmd(void);

    /// Modulus Command creation (pure virtual)
    virtual Modulus_Command * make_mod_cmd(void);

    /// Destructor
    ~Stack_Factory();

private:
    /// Stack (reference)
    Stack<int> &stack_;

    /// Constructor (default)
    Stack_Factory();

    /// Constructor (copy)
    Stack_Factory(Stack_Factory &abs_fac);
};

#endif // !defined _STACK_FACTORY_H_
