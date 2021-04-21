// -*- C++ -*-
// $Id: Unary_Command.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Unary_Command.h
 */
//==============================================================================

#include "Command.h"
#include "Stack.h"

#ifndef _UNARY_COMMAND_H_
#define _UNARY_COMMAND_H_

/**
 * @class Unary_Command
 *
 * Base class for all binary commands (inherits from Command)
 */
class Unary_Command : public Command
{
public:
    /// Execute (inherited)
    void execute(void);

protected:

    /// Constructor (passed)
    Unary_Command(Stack<int> & stack) : stack_(stack) {}

    /// Evaluate method (pure virtual)
    virtual int evaluate(int num1) const = 0;

    /// Destructor
    ~Unary_Command() {}

private:
    /// Stack reference
    Stack<int> &stack_;

    /// Constructor (default)
    Unary_Command();

    /// Constructor (copy)
    Unary_Command(Unary_Command &command);
};

#endif // !defined _UNARY_COMMANDS_H_