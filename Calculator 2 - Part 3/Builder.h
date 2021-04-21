// -*- C++ -*-
// $Id: Builder.h 02/11/21Victor Samuel

//==============================================================================
/**
 * @file       Builder.h
 */
//==============================================================================

#ifndef _BUILDER_H_
#define _BUILDER_H_

#include "Exp_Node.h"
#include "Stack.h"

class Builder
{
public:
    /// Builds an expression tree structure
    virtual Exp_Node * build_exp_tree() = 0;

    /// Add operation (builder with postfix stack reference)
    virtual Exp_Node * build_add_op(Stack<std::string> & post_stk_) = 0;

    /// Add operation (builder with postfix stack reference)
    virtual Exp_Node * build_sub_op(Stack<std::string> & post_stk_) = 0;

    /// Add operation (builder with postfix stack reference)
    virtual Exp_Node * build_mul_op(Stack<std::string> & post_stk_) = 0;

    /// Add operation (builder with postfix stack reference)
    virtual Exp_Node * build_div_op(Stack<std::string> & post_stk_) = 0;

    /// Add operation (builder with postfix stack reference)
    virtual Exp_Node * build_mod_op(Stack<std::string> & post_stk_) = 0;

    /// Number operation (passed int)
    virtual Exp_Node * build_num(int num) = 0;

};

#endif // !define _BUILDER_H_
