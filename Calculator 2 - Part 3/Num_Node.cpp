// -*- C++ -*-
// $Id: Num_Node.cpp 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Num_Node.cpp
 */
//==============================================================================

#include "Num_Node.h"

//
// Constructor (passed int)
//
Num_Node::Num_Node(int num)
    :   num_(num)
{
}

//
// solve
//
int Num_Node::solve()
{
    return num_;
}

//
// accept_visistor
//
int Num_Node::accept_visitor(Visitor &visitor)
{
    return visitor.Vis_Num_Node(*this);
}

//
// get_num
//
int Num_Node::get_num()
{
    return num_;
}
