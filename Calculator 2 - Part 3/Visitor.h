// -*- C++ -*-
// $Id: Visitor.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Visitor.h
 */
//==============================================================================

#ifndef _VISITOR_H_
#define _VISITOR_H_

// Forward declaration of classes
class Add_Exp_Node;
class Subtract_Exp_Node;
class Divide_Exp_Node;
class Multiply_Exp_Node;
class Modulus_Exp_Node;
class Num_Node;

class Visitor
{
public:

    /// Addition node with visitor pattern
    virtual int Vis_Add_Node(Add_Exp_Node &node) = 0;

    /// Subtraction node with visitor pattern
    virtual int Vis_Sub_Node(Subtract_Exp_Node &node) = 0;
    
    /// Division node with visitor pattern
    virtual int Vis_Div_Node(Divide_Exp_Node &node) = 0;

    /// Multiplication node with visitor pattern
    virtual int Vis_Mul_Node(Multiply_Exp_Node &node) = 0;

    /// Modulus node with visitor pattern
    virtual int Vis_Mod_Node(Modulus_Exp_Node &node) = 0;

    /// Number node with visitor pattern
    virtual int Vis_Num_Node(Num_Node &node) = 0;
};

#endif // !define _VISITOR_H_
