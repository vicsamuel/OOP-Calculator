// -*- C++ -*-
// $Id: Command.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Command.h
 */
//==============================================================================

#ifndef _COMMAND_H_
#define _COMMAND_H_

/**
 * @class Command
 *
 * Command interface (pure virtual)
 */
class Command
{
public:
    /// Virtual execute function
    virtual void execute(void) = 0;
};

#endif // !defined _COMMAND_H_