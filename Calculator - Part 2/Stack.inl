// -*- C++ -*-
// $Id: Array.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Array.h
 */
//==============================================================================
//
// size
//
template <typename T>
inline size_t Stack<T>::size(void) const
{
    return (top_ + 1);
}

//
// top
//
template <typename T>
inline T Stack<T>::top(void) const
{
    if (is_empty())
    {
        throw empty_exception("Cannot view top! Stack is empty!");
        return stack_[top_];
    }
    else
    {
        return stack_[top_];
    }
}

//
// is_empty
//
template <typename T>
inline bool Stack<T>::is_empty(void) const
{
    if (top_ == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
