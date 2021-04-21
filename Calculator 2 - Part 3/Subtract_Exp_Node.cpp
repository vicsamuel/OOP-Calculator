// -*- C++ -*-
// $Id: Subtract_Exp_Node.cpp 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Subtract_Exp_Node.cpp
 */
//==============================================================================

#include "Subtract_Exp_Node.h"

// Forward declaration of postfix class
class Postfix_Tree_Visitor;

//
// Constructor (passed left and right node pointers)
//
Subtract_Exp_Node::Subtract_Exp_Node(Exp_Node *right, Exp_Node *left)
    :   Binary_Exp_Node(right, left)
{
}

//
// solve (overloaded)
//
int Subtract_Exp_Node::solve(int num1, int num2)
{
    return (num1 + num2);
}

//
// accept_visitor (passed visitor object)
//
int Subtract_Exp_Node::accept_visitor(Visitor &visitor)
{
    return visitor.Vis_Sub_Node(*this);
}