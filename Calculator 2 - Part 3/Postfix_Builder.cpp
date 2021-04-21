// -*- C++ -*-
// $Id: Postfix_Builder.cpp 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Postfix_Builder.cpp
 */
//==============================================================================

#include "Postfix_Builder.h"
#include "Stack.h"
#include "Queue.h"
#include "Add_Exp_Node.h"
#include "Subtract_Exp_Node.h"
#include "Multiply_Exp_Node.h"
#include "Divide_Exp_Node.h"
#include "Modulus_Exp_Node.h"
#include "Num_Node.h"
#include "Infix_Postfix_Helper.h"

#include <stdlib.h>
#include <sstream>

//
// Constructor (passed infix)
//
Postfix_Builder::Postfix_Builder(std::string &infix)
    : infix_(infix)
{
}

//
// build_exp_tree
//
Exp_Node *Postfix_Builder::build_exp_tree()
{
    Stack<std::string> post_stk;

    infix_postfix(post_stk);

    Exp_Node *root = build_postfix(post_stk);

    return root;
}

//
// get_node
//
Exp_Node *Postfix_Builder::get_node(char op, Stack<std::string> &post_stk)
{
    Exp_Node *node;
    switch (op)
    {
    case '+':
        node = build_add_op(post_stk);
        break;
    case '-':
        node = build_sub_op(post_stk);
        break;
    case '*':
        node = build_mul_op(post_stk);
        break;
    case '/':
        node = build_div_op(post_stk);
        break;
    case '%':
        node = build_mod_op(post_stk);
        break;
    default:
        throw std::runtime_error("Error in get_node function from Postfix_Builder");
        break;
    }
    return node;
}

//
// build_postfix_tree
//
Exp_Node *Postfix_Builder::build_postfix(Stack<std::string> &post_stk)
{
    std::stringstream tok_ss;
    std::string tok = post_stk.pop();
    int num;
    char op;

    tok_ss.str(tok);

    num = atoi(tok.c_str());
    tok_ss >> op;

    if (num == 0 && is_operator(op))
    {
        return get_node(op, post_stk);
    }
    else
    {
        return build_num(num);
    }
}

//
// build_add_op
//
Exp_Node *Postfix_Builder::build_add_op(Stack<std::string> &post_stk)
{
    return new Add_Exp_Node(build_postfix(post_stk), build_postfix(post_stk));
}

//
// build_sub_op
//
Exp_Node *Postfix_Builder::build_sub_op(Stack<std::string> &post_stk)
{
    return new Subtract_Exp_Node(build_postfix(post_stk), build_postfix(post_stk));
}

//
// build_mul_op
//
Exp_Node *Postfix_Builder::build_mul_op(Stack<std::string> &post_stk)
{
    return new Multiply_Exp_Node(build_postfix(post_stk), build_postfix(post_stk));
}

//
// build_div_op
//
Exp_Node *Postfix_Builder::build_div_op(Stack<std::string> &post_stk)
{
    return new Divide_Exp_Node(build_postfix(post_stk), build_postfix(post_stk));
}

//
// build_mod_op
//
Exp_Node *Postfix_Builder::build_mod_op(Stack<std::string> &post_stk)
{
    return new Modulus_Exp_Node(build_postfix(post_stk), build_postfix(post_stk));
}

//
// build_num
//
Exp_Node *Postfix_Builder::build_num(int num)
{
    return new Num_Node(num);
}

//
// infix_postfix
//
void Postfix_Builder::infix_postfix(Stack<std::string> &stack)
{
    op_precedence();

    // Operator stack declaration
    Stack<char> op_stk;

    std::string postfix;

    Queue<exp_tok> postfix_queue;

    Array<var> arr(26);

    int arr_index = 0;
    int valid_cnt = 0;

    // Stringstream variables to extract tokens
    std::stringstream infix_ss(infix_);
    std::string tok;
    std::stringstream tok_ss;

    // ASCII for input
    char in_op;
    int in_num;

    // Tokenize
    while (getline(infix_ss, tok, ' '))
    {
        tok_ss.str(tok);
        in_num = atoi(tok.c_str());
        tok_ss >> in_op;

        // If input is operator
        if (in_num == 0 && is_operator(in_op))
        {
            // If token is parenthesis
            if (in_op == '(')
            {
                op_stk.push(in_op);
            }
            else if (in_op == ')')
            {
                if (!op_stk.is_empty())
                {
                    char tos = op_stk.pop();
                    while (tos != '(')
                    {
                        postfix_queue.enqueue({tos, false});
                        if (valid_cnt > 1)
                        {
                            valid_cnt--;
                        }
                        else
                        {
                            throw std::runtime_error("Invalid operator");
                        }
                        if (!op_stk.is_empty())
                        {
                            tos = op_stk.pop();
                        }
                        else
                        {
                            throw std::runtime_error("Invalid expression");
                        }
                    }
                }
                else
                {
                    throw std::runtime_error("Invalid expression");
                }
            }
            else
            {
                while (!op_stk.is_empty() && op_priority(op_stk.top(), in_op) && op_stk.top() != '(')
                {
                    char tos = op_stk.pop();
                    postfix_queue.enqueue({tos, false});

                    if (valid_cnt > 1)
                    {
                        valid_cnt--;
                    }
                    else
                    {
                        throw std::runtime_error("Invalid operator");
                    }
                }
                op_stk.push(in_op);
            }
        }
        else if (in_num == 0 && is_letter(in_op))
        {
            postfix_queue.enqueue({in_op, false});
            valid_cnt++;

            if (arr.find({0, in_op}) == -1)
            {
                var variable = {0, in_op};
                arr[arr_index++] = variable;
            }
        }
        else
        {
            postfix_queue.enqueue({in_num, true});
            valid_cnt++;
        }
    }

    while (!op_stk.is_empty())
    {
        char tos = op_stk.pop();
        if (tos == '(' || tos == ')')
        {
            throw std::runtime_error("Invalid Expression");
        }
        else
        {
            postfix_queue.enqueue({tos, false});

            if (valid_cnt > 1)
            {
                valid_cnt--;
            }
            else
            {
                throw std::runtime_error("Invalid Operator");
            }
        }
    }

    if (valid_cnt != 1)
    {
        throw std::runtime_error("No valid variables");
    }

    for (int i = 0; i < arr_index; i++)
    {
        std::cout << arr[i].name << " = ";
        std::cin >> arr[i].val;
        std::getchar();
    }

    // Generate postfix
    while (!postfix_queue.is_empty())
    {
        exp_tok token = postfix_queue.dequeue();
        if (!token.is_num && is_letter(token.exp_val))
        {
            int value = 0;
            for (int i = 0; i < arr_index; i++)
            {
                if (arr[i].name == token.exp_val)
                {
                    value = arr[i].val;
                    break;
                }
            }
            postfix = postfix + std::to_string(value) + " ";
            stack.push(std::to_string(value));
        }
        else if (!token.is_num && is_operator(token.exp_val))
        {
            postfix = postfix + (char)token.exp_val;
            std::string va;
            va += (char)token.exp_val;
            stack.push(va);
        }
        else
        {
            postfix = postfix + std::to_string(token.exp_val) + " ";
            stack.push(std::to_string(token.exp_val));
        }
    }
}