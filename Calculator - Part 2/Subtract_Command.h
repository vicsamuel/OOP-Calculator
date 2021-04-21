// -*- C++ -*-
// $Id: Subtract_Command.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Subtract_Command.h
 */
//==============================================================================

#include "Binary_Command.h"

#ifndef _SUBTRACT_COMMAND_H_
#define _SUBTRACT_COMMAND_H_

/**
 * @class Subtract_Command
 *
 * Child of Binary_Command
 */
class Subtract_Command : public Binary_Command
{
public:
    /// Constructor (default)
    Subtract_Command();

    /// Constructor (passed)
    Subtract_Command(Stack<int> &stack) : Binary_Command(stack) {}

    /// Destructor
    ~Subtract_Command() {}

protected:
    /// Evaluate method (pure virtual)
    int evaluate(int num1, int num2) const;

private:
    /// Constructor (copy)
    Subtract_Command(Subtract_Command &command);
};

#endif // !defined _SUBTRACT_COMMAND_H_