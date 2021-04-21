// -*- C++ -*-
// $Id: Stack.h 02/11/21 Victor Samuel

//==============================================================================
/**
 * @file       Stack.h
 */
//==============================================================================

#ifndef _STACK_H_
#define _STACK_H_

#include <exception>
#include "Array.h"
#include <iostream> /// ONLY FOR TESTING REMOVE BEFORE SUBMISSION

/**
 * @class Stack
 *
 * Basic stack for abitrary elements.
 */
template <typename T>
class Stack
{
public:
  /// Type definition of the type.
  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the stack is empty.
   */
  class empty_exception : public std::runtime_error
  {
  public:
    /// Default constructor.
    empty_exception(void)
        : std::runtime_error("Default stack constuctor empty_exception error") {}

    /**
     * Initializing constructor.
     *
     * @param[in]      msg         Error message.
     */
    empty_exception(const char *msg)
        : std::runtime_error(msg) {}
  };

  /// Default constructor.
  Stack(void);

  /// Copy constructor.
  Stack(const Stack &s);

  /// Destructor.
  ~Stack(void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Stack &operator=(const Stack &rhs);

  /**
   * Push a new \a element onto the stack. The element is inserted
   * before all the other elements in the list.
   *
   * @param[in]      element       Element to add to the list
   */
  void push(T element);

  /**
   * Remove the top-most element from the stack.
   *
   * @exception      empty_exception    The stack is empty.
   */
  T pop(void);

  /**
   * Get the top-most element on the stack. If there are no element 
   * on the stack, then the stack_is_empty exception is thrown.
   *
   * @return         Element on top of the stack.
   * @exception      empty_exception    The stack is empty
   */
  T top(void) const;

  /**
   * Test if the stack is empty
   *
   * @retval         true          The stack is empty
   * @retval         false         The stack is not empty
   */
  bool is_empty(void) const;

  /**
   * Number of element on the stack.
   *
   * @return         Size of the stack.
   */
  size_t size(void) const;

  /// Remove all elements from the stack.
  void clear(void);

  /// Print function
  void print(void) const;

private:
  /// Array<T> to initialize stack
  Array<T> stack_;

  /// Top of stack
  int top_;
};

// include the inline files
#include "Stack.inl"

// include the source file since template class
#include "Stack.cpp"

#endif // !defined _STACK_H_
