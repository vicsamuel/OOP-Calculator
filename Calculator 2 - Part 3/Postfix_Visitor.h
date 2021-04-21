// -*- C++ -*-
// $Id: Postfix_Visitor.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Postfix_Visitor.h
 */
//==============================================================================

#ifndef _POSTFIX_VISITOR_H_
#define _POSTFIX_VISITOR_H_

#include "Visitor.h"
#include "Exp_Node.h"
#include "Add_Exp_Node.h"
#include "Subtract_Exp_Node.h"
#include "Multiply_Exp_Node.h"
#include "Divide_Exp_Node.h"
#include "Modulus_Exp_Node.h"
#include "Num_Node.h"

class Postfix_Visitor: public Visitor
{
public:
    /// Constructor (default)
    Postfix_Visitor();

    /// Vis_Add_Node (inherited)
    virtual int Vis_Add_Node(Add_Exp_Node &node);
    
    /// Vis_Subtract_Node (inherited)
    virtual int Vis_Sub_Node(Subtract_Exp_Node &node);

    /// Vis_Div_Node (inherited)
    virtual int Vis_Div_Node(Divide_Exp_Node &node);

    /// Vis_Mul_Node (inherited)
    virtual int Vis_Mul_Node(Multiply_Exp_Node &node);

    /// Vis_Mod_Node(inherited)
    virtual int Vis_Mod_Node(Modulus_Exp_Node &node);

    /// Vis_Num_Node (inherited)
    virtual int Vis_Num_Node(Num_Node &node);
};

#endif // !define _POSTFIX_VISITOR_H_
