// -*- C++ -*-
// $Id: Base_Array.inl 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Base_Array.inl
 */
//==============================================================================

//
// size
//
template <typename T>
inline size_t Base_Array<T>::size(void) const
{
    return cur_size_;
}

//
// max_size
//
template <typename T>
inline size_t Base_Array<T>::max_size(void) const
{
    return max_size_;
}
