// -*- C++ -*-
// $Id: Postfix_Builder.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Postfix_Builder.h
 */
//==============================================================================

#ifndef _POSTFIX_BUILDER_H_
#define _POSTFIX_BUILDER_H_

#include "Builder.h"
#include "Stack.h"

class Postfix_Builder : public Builder
{
public:
    /// Constructor (passed infix)
    Postfix_Builder(std::string &infix);

    /// Build Expression tree
    Exp_Node *build_exp_tree();

    /// Build Add operation
    virtual Exp_Node *build_add_op(Stack<std::string> &post_stk);

    /// Build Subtract operation
    virtual Exp_Node *build_sub_op(Stack<std::string> &post_stk);

    /// Build Multiply operation
    virtual Exp_Node *build_mul_op(Stack<std::string> &post_stk);

    /// Build Divide operation
    virtual Exp_Node *build_div_op(Stack<std::string> &post_stk);

    /// Build Modulus operation
    virtual Exp_Node *build_mod_op(Stack<std::string> &post_stk);

    virtual Exp_Node *build_num(int num);

    /// Destructor CHECK THIS!!!!!
    ~Postfix_Builder() {}

private:
    /// Infix reference
    std::string &infix_;

    /// Constructor (default)
    Postfix_Builder() = delete;

    /// Infix_Postfix function
    void infix_postfix(Stack<std::string> &stack);

    /// Postfix tree builder
    Exp_Node *build_postfix(Stack<std::string> &post_stk);

    /// Get node function
    Exp_Node *get_node(char op, Stack<std::string> &post_stk);

};

#endif // !define _POSTFIX_BUILDER_H_
