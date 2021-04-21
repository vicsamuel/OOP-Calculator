// -*- C++ -*-
// $Id: Multiply_Exp_Node.cpp 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Multiply_Exp_Node.cpp
 */
//==============================================================================

#include "Multiply_Exp_Node.h"

/// Forward declaration of postfix class
class Postfix_Tree_Visitor;

//
// Constructor (passed left and right node pointers)
//
Multiply_Exp_Node::Multiply_Exp_Node(Exp_Node *right, Exp_Node *left)
    :   Binary_Exp_Node(right, left)
{
}

//
// solve (overloaded)
//
int Multiply_Exp_Node::solve(int num1, int num2)
{
    return (num1 * num2);
}

//
// accept_visitor (passed visitor object)
//
int Multiply_Exp_Node::accept_visitor(Visitor &visitor)
{
    return visitor.Vis_Mul_Node(*this);
}