// -*- C++ -*-
// $Id: Multiply_Command.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Multiply_Command.h
 */
//==============================================================================

#include "Binary_Command.h"

#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

/**
 * @class Multiply_Command
 *
 * Child of Binary_Command
 */
class Multiply_Command : public Binary_Command
{
public:
    /// Constructor (default)
    Multiply_Command();
    
    /// Constructor (passed)
    Multiply_Command(Stack<int> &stack) : Binary_Command(stack) {}

    /// Destructor
    ~Multiply_Command() {}

protected:
    /// Evaluate method (pure virtual)
    int evaluate(int num1, int num2) const;

private:
    /// Constructor (copy)
    Multiply_Command(Multiply_Command &command);
};

#endif // !defined _MULTIPLY_COMMAND_H_