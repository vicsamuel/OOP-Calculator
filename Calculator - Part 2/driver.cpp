#include <iostream>
#include "Infix_To_Postfix.h"

int main(int argv, char* argc[])
{
    std::string in = "";

    std::getline(std::cin, in);

    while(in.compare("QUIT") != 0)
    {
        try
        {
            infix_to_postfix(in);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::getline(std::cin, in);
    }
    return 0;
}