// -*- C++ -*-
// $Id: Postfix_Visitor.cpp 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Postfix_Visitor.cpp
 */
//==============================================================================

#include "Postfix_Visitor.h"

//
// Constructor (default)
//
Postfix_Visitor::Postfix_Visitor()
{
}

//
// Vis_Add_Node (inherited)
//
int Postfix_Visitor::Vis_Add_Node(Add_Exp_Node &node)
{
    int num1 = node.get_left_node()->accept_visitor(*this);
    int num2 = node.get_right_node()->accept_visitor(*this);
    return (num1 + num2);
}

//
// Vis_Sub_Node (inherited)
//
int Postfix_Visitor::Vis_Sub_Node(Subtract_Exp_Node &node)
{
    int num1 = node.get_left_node()->accept_visitor(*this);
    int num2 = node.get_right_node()->accept_visitor(*this);
    return (num1 - num2);
}

//
// Vis_Mul_Node (inherited)
//
int Postfix_Visitor::Vis_Mul_Node(Multiply_Exp_Node &node)
{
    int num1 = node.get_left_node()->accept_visitor(*this);
    int num2 = node.get_right_node()->accept_visitor(*this);
    return (num1 * num2);
}

//
// Vis_Div_Node (inherited)
//
int Postfix_Visitor::Vis_Div_Node(Divide_Exp_Node &node)
{
    int num1 = node.get_left_node()->accept_visitor(*this);
    int num2 = node.get_right_node()->accept_visitor(*this);
    if (num2 == 0)
    {
        throw std::runtime_error("Invalid Expression: Cannot divide by 0!\n");
    }
    else
    {
        return (num1 / num2);
    }
}

//
// Vis_Div_Node (inherited)
//
int Postfix_Visitor::Vis_Mod_Node(Modulus_Exp_Node &node)
{
    int num1 = node.get_left_node()->accept_visitor(*this);
    int num2 = node.get_right_node()->accept_visitor(*this);
    if (num2 == 0)
    {
        throw std::runtime_error("Invalid Expression: Modulus divide by 0 occured!\n");
    }
    else
    {
        return (num1 % num2);
    }
}

//
// Vis_Num_Node (inherited)
//
int Postfix_Visitor::Vis_Num_Node(Num_Node &node)
{
    int retval = node.get_num();
    return retval;
}
