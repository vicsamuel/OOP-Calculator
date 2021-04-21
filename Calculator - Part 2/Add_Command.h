// -*- C++ -*-
// $Id: Add_Command.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Add_Command.h
 */
//==============================================================================

#include "Binary_Command.h"

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

/**
 * @class Add_Command
 *
 * Child of Binary_Command
 */
class Add_Command : public Binary_Command
{
public:
    /// Constructor (default)
    Add_Command();
    
    /// Constructor (passed)
    Add_Command(Stack<int> & stack) : Binary_Command(stack) {}

    /// Destructor
    ~Add_Command() {}

    /// Evaluate method (pure virtual)
    int evaluate(int num1, int num2) const;

private:
    /// Constructor (copy)
    Add_Command(Add_Command &command);
};

#endif // !defined _ADD_COMMAND_H_