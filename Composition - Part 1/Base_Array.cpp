// -*- C++ -*-
// $Id: Base_Array.cpp 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Base_Array.cpp
 */
//==============================================================================

#include "Base_Array.h"
#include <cstring>
#include <stdexcept>

//
// Constructor (default)
//
template <typename T>
Base_Array<T>::Base_Array(void)
    : max_size_{DEFAULT_MAX},
      cur_size_{DEFAULT_MAX},
      data_{new T[DEFAULT_MAX]}
{
}

//
// Constructor (length)
//
template <typename T>
Base_Array<T>::Base_Array(size_t length)
    : max_size_{length},
      cur_size_{length},
      data_{new T[length]}
{
}

//
// Constructor (length, fill)
//
template <typename T>
Base_Array<T>::Base_Array(size_t length, T fill)
    : max_size_{length},
      cur_size_{length},
      data_{new T[length]}
{
    for (int i = 0; i < cur_size_; i++)
    {
        data_[i] = fill;
    }
}

//
// Array (copy with passed array)
//
template <typename T>
Base_Array<T>::Base_Array(const Base_Array &array)
    : max_size_{array.max_size()},
      cur_size_{array.size()},
      data_{new T[array.max_size()]}
{
    for (int i = 0; i < cur_size_; i++)
    {
        data_[i] = array.data_[i];
    }
}

//
// Destructor
//
template <typename T>
Base_Array<T>::~Base_Array(void)
{
    delete[] data_;
}

//
// operator =
//
template <typename T>
const Base_Array<T> &Base_Array<T>::operator=(const Base_Array &rhs)
{
    // Possible err
    if (this != &rhs)
    {
        delete[] data_;
        data_ = new T[rhs.max_size_];
        cur_size_ = rhs.cur_size_;
        max_size_ = rhs.max_size_;
        for (int i = 0; i < max_size_; i++)
        {
            data_[i] = rhs.data_[i];
        }
    }
    return *this;
}

//
// operator []
//
template <typename T>
T &Base_Array<T>::operator[](size_t index)
{
    if (index >= cur_size_)
    {
        throw std::out_of_range("Caught an out of range in the operator[](size_t index) function of index value: " + index);
    }
    return data_[index];
}

//
// operator []
//
template <typename T>
const T &Base_Array<T>::operator[](size_t index) const
{
    if (index >= cur_size_)
    {
        throw std::out_of_range("Caught an out of range in the operator[](size_t index) const function of index value: " + index);
    }
    return data_[index];
}

//
// get
//
template <typename T>
T Base_Array<T>::get(size_t index) const
{
    if (index >= cur_size_)
    {
        throw std::out_of_range("Caught an out of range in the 'get(size_t index) const' function of index value: " + index);
    }
    return data_[index];
}

//
// set
//
template <typename T>
void Base_Array<T>::set(size_t index, T value)
{
    if (index >= cur_size_)
    {
        throw std::out_of_range("Caught an out of range in the 'set(size_t index, T value)' function of index value: " + index);
    }
    data_[index] = value;
}

//
// find functions (type T needs == operator for this)
//
template <typename T>
int Base_Array<T>::find(T value) const
{
    for (int i = 0; i < cur_size_; i++)
    {
        if (data_[i] == value)
        {
            return i;
        }
    }
    return -1;
}

//
// find functions (type T needs == operator for this)
//
template <typename T>
int Base_Array<T>::find(T val, size_t start) const
{
    if (start >= cur_size_)
    {
        throw std::out_of_range("Caught an out of range in the 'find(T val, size_t start)' const function of start value: " + start);
    }
    for (int i = start; i < cur_size_; i++)
    {
        if (val == data_[i])
        {
            return i;
        }
    }
    return -1;
}

//
// operator functions (type T needs == operator for this)
//
template <typename T>
bool Base_Array<T>::operator==(const Base_Array &rhs) const
{
    if (cur_size_ == rhs.cur_size_)
    {
        for (int i = 0; i < cur_size_; i++)
        {
            if (data_[i] != rhs.data_[i])
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}

//
// operator functions (type T needs == operator for this)
//
template <typename T>
bool Base_Array<T>::operator!=(const Base_Array &rhs) const
{
    if (cur_size_ == rhs.cur_size_)
    {
        for (int i = 0; i < cur_size_; i++)
        {
            if (data_[i] != rhs.data_[i])
            {
                return true;
            }
        }
    }
    else
    {
        return true;
    }

    return false;
}

//
// fill (input value)
//
template <typename T>
void Base_Array<T>::fill(T value)
{
    for (int i = 0; i < cur_size_; i++)
    {
        data_[i] = value;
    }
}
