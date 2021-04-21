// -*- C++ -*-
// $Id: Array.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Array.h
 */
//==============================================================================

#include "Stack.h"
#include "Array.h"

//
// Stack
//
template <typename T>
Stack<T>::Stack(void)
    : top_{-1}
{
}

//
// Stack
//
template <typename T>
Stack<T>::Stack(const Stack &stack)
{
    stack_.resize(stack.size());

    for (int i = 0; i < stack.size(); i++)
    {
        stack_[i] = stack.stack_[i];
    }
    top_ = stack.top();
}

//
// ~Stack
//
template <typename T>
Stack<T>::~Stack(void)
{
}

//
// push
//
template <typename T>
void Stack<T>::push(T element)
{
    if (stack_.size() == ++top_)
    {
        stack_.resize(stack_.size() * 2);
    }

    stack_[top_] = element;
}

//
// pop
//
template <typename T>
T Stack<T>::pop(void)
{
    if (is_empty())
    {
        throw empty_exception("Cannot pop! Stack is empty!");
    }
    else
    {
        T item = stack_[top_];
        top_--;
        return item;
    }
}

//
// operator =
//
template <typename T>
const Stack<T> &Stack<T>::operator=(const Stack &rhs)
{
    stack_ = rhs.stack_;
    top = rhs.top();
}

//
// clear
//
template <typename T>
void Stack<T>::clear(void)
{
    while (!is_empty())
    {
        pop();
    }
}

template <typename T>
void Stack<T>::print(void) const
{
    int temp = -1;
    if (is_empty())
    {
        throw empty_exception("PRINT ERROR");
    }
    while (++temp <= top_)
    {
        std::cout << stack_[temp] << ", ";
    }
}
