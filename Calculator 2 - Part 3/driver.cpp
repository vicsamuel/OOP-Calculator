#include <iostream>
#include "Postfix_Builder.h"
#include "Postfix_Visitor.h"

//
// main
//
int main(int argv, char *argc[])
{
    std::string in = "";

    std::getline(std::cin, in);

    while (in.compare("QUIT") != 0)
    {
        bool valid_exp = true;
        bool valid_ans = true;
        
        Postfix_Builder build_post(in);

        Exp_Node *post_tree;
        
        int answer = 0;

        try
        {
            post_tree = build_post.build_exp_tree();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            valid_exp = false;
        }

        if (valid_exp)
        {
            Postfix_Visitor visitor;

            try
            {
                answer = post_tree->accept_visitor(visitor);
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
                valid_ans = false;
                delete post_tree;
            }
        }

        if (valid_exp && valid_ans)
        {
            std::cout << answer << std::endl;
            delete post_tree;
        }
        std::getline(std::cin, in);
    }
    return 0;
}
