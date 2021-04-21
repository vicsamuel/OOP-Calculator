// -*- C++ -*-
// $Id: Modulus_Exp_Node.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Modulus_Exp_Node.h
 */
//==============================================================================

#ifndef _MODULUS_EXP_NODE_H_
#define _MODULUS_EXP_NODE_H_

#include "Binary_Exp_Node.h"

class Modulus_Exp_Node : public Binary_Exp_Node
{
public:
    /// Constructor (passed left and right node pointers)
    Modulus_Exp_Node (Exp_Node *right, Exp_Node *left);

    /// Accept visitor function
    virtual int accept_visitor(Visitor &visitor);

    /// solve (overloaded)
    int solve(int num1, int num2);

private:
    /// Constructor (default)
    Modulus_Exp_Node(void);
};

#endif // !define _MODULUS_EXP_NODE_H_