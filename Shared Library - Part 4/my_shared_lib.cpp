// -*- C++ -*-
// $Id: my_shared_lib.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       my_shared_lib.h
 */
//==============================================================================

#include "my_shared_lib.h"
#include <iostream>

void print_message(const std::string &msg)
{
    std::cout << msg << std::endl;
}

Greeting::Greeting(void) {}
Greeting::~Greeting(void) {}

void Greeting::say_message(const std::string &msg)
{
    std::cerr << msg << std::endl;
}
