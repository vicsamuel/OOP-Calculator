// -*- C++ -*-
// $Id: my_shared_lib.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       my_shared_lib.h
 */
//==============================================================================

#include "my_shared_lib.h"

int main(int argc, char *argv[])
{
    print_message("Hello, World!");

    Greeting g;
    g.say_message("Hello, World!");

    return 0;
}
