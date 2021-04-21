// -*- C++ -*-
// $Id: Binary_Exp_Node.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Binary_Exp_Node.h
 */
//==============================================================================

#ifndef _BINARY_EXP_NODE_H_
#define _BINARY_EXP_NODE_H_

#include "Exp_Node.h"
#include <stdexcept>

class Binary_Exp_Node : public Exp_Node
{
public:
    /// Constructor (passed right and left nodes)
    Binary_Exp_Node(Exp_Node *right, Exp_Node *left);

    /// Accept visitor function
    virtual int accept_visitor(Visitor &visitor) = 0;

    /// solve function
    int solve(void);

    /// Overloaded solve function
    virtual int solve(int num1, int num2) = 0;

    /// Get left node pointer
    Exp_Node * get_left_node(void);

    /// Get right node pointer
    Exp_Node * get_right_node(void);

    /// Destructor
    ~Binary_Exp_Node(void);
    
protected:
    /// Ponters to left and right node
    Exp_Node *right_;
    Exp_Node *left_;
};

#endif // !define _BINARY_EXP_NODE_H_