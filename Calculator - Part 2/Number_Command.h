// -*- C++ -*-
// $Id: Number_Command.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Number_Command.h
 */
//==============================================================================

#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include "Command.h"
#include "Stack.h"

/**
 * @class Number_Command
 *
 * Base class for all binary commands (inherits from Command)
 */
class Number_Command : public Command
{
public:
    /// Execute (inherited)
    void execute(void);

    /// Constructor (passed)
    Number_Command(Stack<int> & stack, int num) : stack_(stack), number_(num) {}

    /// Destructor
    ~Number_Command() {}

private:
    /// Number for calculator
    int number_;

    /// Stack reference
    Stack<int> &stack_;

    /// Constructor (default)
    Number_Command();

    /// Constructor (copy)
    Number_Command(Number_Command &command);
};

#endif // !defined _NUMBER_COMMAND_H_