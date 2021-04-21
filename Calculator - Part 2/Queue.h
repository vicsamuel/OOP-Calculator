// -*- C++ -*-
// $Id: Queue.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Queue.h
 */
//==============================================================================

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Array.h"

#include <exception>

/**
 * @class Queue
 *
 * Basic Queue for abitrary elements.
 */
template <typename T>
class Queue
{
public:
    /// Type definition of the type.
    typedef T type;

    /**
   * @class empty_exception
   *
   * Exception thrown to indicate the queue is empty.
   */
    class empty_exception : public std::runtime_error
    {
    public:
        /// Default constructor.
        empty_exception(void)
            : std::runtime_error("Default queue constuctor empty_exception error")
        {
        }

        /**
     * Initializing constructor.
     *
     * @param[in]      msg         Error message.
     */
        empty_exception(const char *msg)
            : std::runtime_error(msg)
        {
        }
    };

    /// Default constructor
    Queue(void);

    /// Copy constructor
    Queue(const Queue &q);

    /// Destructor
    ~Queue(void);

    /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
    const Queue &operator=(const Queue &rhs);

    /**
   * Enqueue a new \a element onto the queue. The element is inserted
   * after all the other elements in the list.
   *
   * @param[in]      element       Element to add to the list
   */
    void enqueue(T element);

    /**
   * Remove the first element from the front of queue.
   *
   * @exception      empty_exception    The queue is empty.
   */
    T dequeue(void);

    /**
   * Test if the queue is empty
   *
   * @retval         true          The queue is empty
   * @retval         false         The queue is not empty
   */
    bool is_empty(void) const;

    /**
   * Number of element in the queue.
   *
   * @return         Size of the queue.
   */
    size_t size(void) const;

    /// Remove all elements from the queue.
    void clear(void);

    // THIS MUST BE REMOVED
    void print(void) const;

private:
    /// Array for queue
    Array<T> queue_;

    /// Front of queue
    int front_;

    /// Back of queue
    int back_;
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif // !defined _QUEUE_H_
