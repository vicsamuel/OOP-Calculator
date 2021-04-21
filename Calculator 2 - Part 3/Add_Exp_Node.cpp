// -*- C++ -*-
// $Id: Add_Exp_Node.cpp 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Add_Exp_Node.cpp
 */
//==============================================================================

#include "Add_Exp_Node.h"

// Forward declaration of postfix class
class Postfix_Tree_Visitor;

//
// Constructor (passed left and right node pointers)
//
Add_Exp_Node::Add_Exp_Node(Exp_Node *right, Exp_Node *left)
    :   Binary_Exp_Node(right, left)
{
}

//
// solve (overloaded)
//
int Add_Exp_Node::solve(int num1, int num2)
{
    return (num1 + num2);
}

//
// accept_visitor (passed visitor object)
//
int Add_Exp_Node::accept_visitor(Visitor &visitor)
{
    return visitor.Vis_Add_Node(*this);
}