// -*- C++ -*-
// $Id: Num_Node.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Num_Node.h
 */
//==============================================================================

#ifndef _NUM_NODE_H_
#define _NUM_NODE_H_

#include "Exp_Node.h"

class Num_Node : public Exp_Node
{
public:

    /// Constructor (passed int)
    Num_Node(int num);

    /// Accept visitor function
    virtual int accept_visitor(Visitor &visitor);

    /// Solve function (inherited)
    int solve(void);

    /// Get number function
    int get_num(void);

    /// Destructor
    ~Num_Node() { }

private:
    int num_;
};

#endif // !define _NUM_NODE_H_
