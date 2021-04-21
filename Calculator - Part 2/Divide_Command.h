// -*- C++ -*-
// $Id: Divide_Command.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Divide_Command.h
 */
//==============================================================================

#include "Binary_Command.h"

#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

/**
 * @class Divide_Command
 *
 * Child of Binary_Command
 */
class Divide_Command : public Binary_Command
{
public:
    /// Constructor (default)
    Divide_Command();

    /// Constructor (passed)
    Divide_Command(Stack<int> & stack) : Binary_Command(stack) {}

    /// Destructor
    ~Divide_Command() {}

protected:
    /// Evaluate method (pure virtual)
    int evaluate(int num1, int num2) const;

private:
    /// Constructor (copy)
    Divide_Command(Divide_Command &command);
};

#endif // !defined _DIVIDE_COMMAND_H_