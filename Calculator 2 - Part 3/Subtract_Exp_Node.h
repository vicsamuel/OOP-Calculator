// -*- C++ -*-
// $Id: Subtract_Exp_Node.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Subtract_Exp_Node.h
 */
//==============================================================================

#ifndef _SUBTRACT_EXP_NODE_H_
#define _SUBTRACT_EXP_NODE_H_

#include "Binary_Exp_Node.h"

class Subtract_Exp_Node : public Binary_Exp_Node
{
public:
    /// Constructor (passed left and right node pointers)
    Subtract_Exp_Node (Exp_Node *right, Exp_Node *left);

    /// Accept visitor function
    virtual int accept_visitor(Visitor &visitor);

    /// solve (overloaded)
    int solve(int num1, int num2);

private:
    /// Constructor (default)
    Subtract_Exp_Node(void);
};

#endif // !define _SUBTRACT_EXP_NODE_H_