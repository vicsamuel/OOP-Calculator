// -*- C++ -*-
// $Id: Modulus_Command.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Modulus_Command.h
 */
//==============================================================================

#include "Binary_Command.h"

#ifndef _MODULUS_COMMAND_H_
#define _MODULUS_COMMAND_H_

/**
 * @class Modulus_Command
 *
 * Child of Binary_Command
 */
class Modulus_Command : public Binary_Command
{
public:
    /// Constructor (default)
    Modulus_Command();

    /// Constructor (passed)
    Modulus_Command(Stack<int> & stack) : Binary_Command(stack) {}

    /// Destructor
    ~Modulus_Command() {}

protected:
    /// Evaluate method (pure virtual)
    int evaluate(int num1, int num2) const;

private:
    /// Constructor (copy)
    Modulus_Command(Modulus_Command &command);
};

#endif // !defined _Modulus_Command_H_