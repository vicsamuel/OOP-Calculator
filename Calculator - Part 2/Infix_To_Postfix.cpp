// -*- C++ -*-
// $Id: Infix_To_Postfix.cpp 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Infix_To_Postfix.cpp
 */
//==============================================================================

#include "Infix_To_Postfix.h"

//
// op_priority
//
int op_priority(char entry)
{
    switch (entry)
    {
    case '(':
        return 3;
    case ')':
        return 3;
    case '%':
        return 2;    
    case '*':
        return 2;
    case '/':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    default:
        return 0;
    }
}

//
// op_precedence
//
bool op_precedence(char operator1, char operator2)
{
    if (operator1 == 0 || operator2 == 0)
    {
        throw std::runtime_error("Invalid Operator provided! Cannot perform operation.");
    }
    else if (op_priority(operator1) >= op_priority(operator2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//
// op_command
//
Command *op_command(char op, Stack_Factory &fac)
{
   
    Command *cmd; 
    switch (op)
    {
    case '%':
        cmd = fac.make_mod_cmd();
        break;
    case '*':
        cmd = fac.make_mul_cmd();
        break;
    case '/':
        cmd = fac.make_div_cmd();
        break;
    case '+':
        cmd = fac.make_add_cmd();
        break;
    case '-':
        cmd = fac.make_sub_cmd();
        break;
    default:
        throw std::runtime_error("Abstract factory command initialization error: Invalid Operator");
    }
    return cmd;
}

//
// infix_to_postfix
//
void infix_to_postfix(std::string in)
{
    bool is_valid = true;

    Stack<int> ans;
    Stack<char> op_stk;
    Stack_Factory abs_fac(ans);
    Queue<Command *> cmds;

    std::stringstream in_ss(in);
    std::string tok;
    std::stringstream tok_ss;

    char in_op;
    int in_num;

    while (getline(in_ss, tok, ' '))
    {
        tok_ss.str(tok);
        in_num = atoi(tok.c_str());
        tok_ss >> in_op;

        if (in_num == 0 && in_op != '0')
        {
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
                        cmds.enqueue(op_command(tos, abs_fac));

                        if (!op_stk.is_empty())
                        {
                            tos = op_stk.pop();
                        }
                        else
                        {
                            throw std::runtime_error("Operator stack is empty! Invalid expression!");
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
                while (!op_stk.is_empty() && op_stk.top() != '(' && op_precedence(op_stk.top(), in_op))
                {
                    char tos = op_stk.pop();
                    cmds.enqueue(op_command(tos, abs_fac));
                }
                op_stk.push(in_op);
            }
        }
        else
        {
            cmds.enqueue(abs_fac.make_num_cmd(in_num));
        }
    }
    while (!op_stk.is_empty())
    {
        char tos = op_stk.pop();

        if (tos == '(' || tos == ')')
        {
            throw std::runtime_error("Invalid parenthesis placement");
        }
        else
        {
            cmds.enqueue(op_command(tos, abs_fac));
        }
    }

    while (!cmds.is_empty())
    {
        Command *cur_cmd = cmds.dequeue();

        if (is_valid)
        {
            try
            {
                cur_cmd->execute();
            }
            catch (const std::exception &e)
            {
                std::cout << "Command Error" << '\n';
                is_valid = false;
            }
        }
    }

    if (!ans.is_empty() && is_valid)
    {
        std::cout << "Answer: " << ans.top() << '\n';
    }
}
