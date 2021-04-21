// -*- C++ -*-
// $Id: Array.h 11/29/2020 Victor Samuel

//==============================================================================
/**
 * @file       Array.h
 */
//==============================================================================

#include "Array.h"
#include <stdexcept> // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array<T>::Array(void)
    : Base_Array<T>()
{
}

//
// Array (size_t)
//
template <typename T>
Array<T>::Array(size_t length)
    : Base_Array<T>{length}
{
}

//
// Array (size_t, char)
//
template <typename T>
Array<T>::Array(size_t length, T fill)
    : Base_Array<T>{length, fill}
{
}

//
// Array (const Array &)
//
template <typename T>
Array<T>::Array(const Array &array)
{
}

//
// ~Array
//
template <typename T>
Array<T>::~Array(void)
{
}

//
// operator =
//
template <typename T>
const Array<T> &Array<T>::operator=(const Array &rhs)
{
    Base_Array<T>::operator=(rhs);
    return *this;
}

//
// resize
//
template <typename T>
void Array<T>::resize(size_t new_size)
{
    if (new_size > this->max_size_)
    {
        T *arr = new T[new_size * 10];

        for (int i = 0; i < this->cur_size_; i++)
        {
            arr[i] = this->data_[i];
        }

        delete[] this->data_;

        this->data_ = arr;
        this->cur_size_ = new_size;
        this->max_size_ = (new_size * 10);
    }
    else if (new_size >= 0 && new_size <= this->max_size_)
    {
        this->cur_size_ = new_size;
    }
    else
    {
        throw std::out_of_range("Resize of array is invalid!");
    }
}