// -*- C++ -*-
// $Id: Exp_Node.h 02/11/21Victor Samuel

//==============================================================================
/**
 * @file       Exp_Node.h
 */
//==============================================================================

#ifndef _EXP_NODE_H_
#define _EXP_NODE_H_

#include "Visitor.h"
#include <iostream>


class Exp_Node
{
public:
    /// Use for tree traversal
    virtual int solve(void) = 0;

    /// Accept visitor function
    virtual int accept_visitor(Visitor &visitor) = 0;

    /// Destructor
    virtual ~Exp_Node(void) { }
};

#endif // !define _EXP_NODE_H_
