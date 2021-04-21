// -*- C++ -*-
// $Id: Binary_Command.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Binary_Command.h
 */
//==============================================================================

#include "Command.h"
#include "Stack.h"

#ifndef _BINARY_COMMAND_H_
#define _BINARY_COMMAND_H_

/**
 * @class Binary_Command
 *
 * Base class for all binary commands (inherits from Command)
 */
class Binary_Command : public Command
{
public:
    /// Constructor (default)
    Binary_Command();
    /// Execute (inherited)
    void execute(void);

protected:
    /// Constructor (passed)
    Binary_Command(Stack<int> & stack) : stack_(stack) {}

    /// Evaluate method (pure virtual)
    virtual int evaluate(int num1, int num2) const = 0;

    /// Destructor
    ~Binary_Command() {}

private:
    /// Stack reference
    Stack<int> &stack_;

    /// Constructor (copy)
    Binary_Command(Binary_Command &command);
};

#endif // !defined _BINARY_COMMANDS_H_