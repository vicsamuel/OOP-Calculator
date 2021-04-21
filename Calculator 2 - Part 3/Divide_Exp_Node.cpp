// -*- C++ -*-
// $Id: Divide_Exp_Node.cpp 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Divide_Exp_Node.cpp
 */
//==============================================================================

#include "Divide_Exp_Node.h"

/// Forward declaration of postfix class
class Postfix_Tree_Visitor;

//
// Constructor (passed left and right node pointers)
//
Divide_Exp_Node::Divide_Exp_Node(Exp_Node *right, Exp_Node *left)
    :   Binary_Exp_Node(right, left)
{
}

//
// solve (overloaded)
//
int Divide_Exp_Node::solve(int num1, int num2)
{
    if (num2 == 0)
    {
        throw std::runtime_error("Invalid Expresion: Cannot divide by 0\n");
    }
    return (num1 / num2);
}

//
// accept_visitor (passed visitor object)
//
int Divide_Exp_Node::accept_visitor(Visitor &visitor)
{
    return visitor.Vis_Div_Node(*this);
}