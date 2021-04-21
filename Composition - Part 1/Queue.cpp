// -*- C++ -*-
// $Id: Queue.cpp 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Queue.cpp
 */
//==============================================================================

#include "Queue.h"
#include "Stack.h"

template <typename T>
Queue<T>::Queue(void)
    : front_{-1},
      back_{-1}
{
}

template <typename T>
Queue<T>::Queue(const Queue &queue)
    : front_{-1},
      back_{-1}
{
    queue_.resize(queue.size());

    for (int i = 0; i < queue.size(); i++)
    {
        enqueue(queue.queue_[i]);
    }
}

template <typename T>
Queue<T>::~Queue(void)
{
}

template <typename T>
const Queue<T> &Queue<T>::operator=(const Queue &rhs)
{
    queue_ = rhs.queue_;
    front_ = rhs.front_;
    back_ = rhs.back_;
}

template <typename T>
void Queue<T>::enqueue(T element)
{
    if (back_ == queue_.size() - 1)
    {
        if (front_ == -1)
        {
            queue_.resize(queue_.size() * 2);
        }
        else
        {
            for (int i = front_, j = 0; i <= back_; i++, j++)
            {
                queue_[j] = queue_[i];
            }

            back_ = back_ - front_ - 1;
        }
    }

    queue_[++back_] = element;
}

template <typename T>
void Queue<T>::dequeue()
{
    if (is_empty())
    {
        throw empty_exception("Cannot dequeue! Queue is empty!");
    }
    else
    {
        ++front_;
    }
}

template <typename T>
void Queue<T>::clear()
{
    front_ = -1;
    back_ = -1;
}

template <typename T>
void Queue<T>::print(void) const
{
    int temp = -1;
    if (is_empty())
    {
        throw empty_exception("PRINT ERROR");
    }
    while (++temp <= front_)
    {
        std::cout << queue_[temp] << ", ";
    }
}
