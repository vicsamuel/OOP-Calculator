// -*- C++ -*-
// $Id: my_shared_lib.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       my_shared_lib.h
 */
//==============================================================================

#include <string>

#include "my_shared_lib_export.h" // include export header

MY_SHARED_LIB_Export void print_message(const std::string &msg);

class MY_SHARED_LIB_Export Greeting
{
public:
    Greeting(void);
    ~Greeting(void);

    void say_message(const std::string &msg);
};
