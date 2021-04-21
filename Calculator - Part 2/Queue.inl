// -*- C++ -*-
// $Id: Queue.inl 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Queue.inl
 */
//==============================================================================

//
// size
//
template <typename T>
inline size_t Queue<T>::size(void) const
{
    return (back_ - front_);
}

//
// is_empty
//
template <typename T>
inline bool Queue<T>::is_empty(void) const
{
    if (front_ == back_)
    {
        return true;
    }
    return false;
}
