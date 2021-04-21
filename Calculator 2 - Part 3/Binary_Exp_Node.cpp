// -*- C++ -*-
// $Id: Binary_Exp_Node.cpp 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Binary_Exp_Node.cpp
 */
//==============================================================================

#include "Binary_Exp_Node.h"

//
// Constructor (passed left and right node pointers)
//
Binary_Exp_Node::Binary_Exp_Node(Exp_Node *right, Exp_Node *left)
    :   right_(right), left_(left)
{
}

//
// solve (includes overload)
//
int Binary_Exp_Node::solve()
{
    int num2 = right_->solve();
    int num1 = left_->solve();

    return this->solve(num1, num2);
}

//
// get_left_node
//
Exp_Node * Binary_Exp_Node::get_left_node()
{
    return left_;
}

//
// get_right_node
//
Exp_Node * Binary_Exp_Node::get_right_node()
{
    return right_;
}

Binary_Exp_Node::~Binary_Exp_Node()
{
    delete right_;
    delete left_;
}