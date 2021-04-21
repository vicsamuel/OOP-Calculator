// -*- C++ -*-
// $Id: Fixed_Array.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Fixed_Array.h
 */
//==============================================================================
#include "Base_Array.h"
#include "Fixed_Array.h"

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(void)
{
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(const Fixed_Array<T, N> &arr)
{
    for (int i = 0; i < cur_size_; i++)
    {
        data_[i] = arr.data_[i];
    }
}

//
// Fixed_Array
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array<T, N>::Fixed_Array(const Fixed_Array<T, M> &arr)
{
    for (int i = 0; i < cur_size_; i++)
    {
        data_[i] = arr.data_[i];
    }
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T, N>::Fixed_Array(T fill)
{
    this->Base_Array<T>::fill(fill);
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array<T, N>::~Fixed_Array(void)
{
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array<T, N> &Fixed_Array<T, N>::operator=(const Fixed_Array<T, N> &rhs)
{
    this->Base_Array<T>::operator=(rhs);
    return *this;
}
