/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:13:00 by jrasser           #+#    #+#             */
/*   Updated: 2022/11/01 21:04:03 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __STACK_HPP__
# define __STACK_HPP__

# include "utils.hpp"
# include "vector.hpp"
namespace ft
{


template <class T, class Container = ft::vector<T> >
class stack {

public:
  typedef T			    value_type;
  typedef Container	container_type;
  typedef size_t		size_type;


// private:
  container_type c;





public:
  /* *************************************************** */
  /*                                                     */
  /*                     CONSTRUCTION                    */
  /*                                                     */
  /* *************************************************** */

  explicit stack(container_type const &ctnr = container_type())
  : c(ctnr)
   {}

  // explicit stack (const container_type& ctnr = container_type()) {
  //   c = ctnr;
  // }

  ~stack() {}

  stack(const stack &src) {
    *this = src;
  }

  stack &operator=(const stack &rhs) {
    if (this != &rhs) {
      this->c = rhs.c;
    }
    return (*this);
  }

  /* *************************************************** */
  /*                                                     */
  /*                     CAPACITY                        */
  /*                                                     */
  /* *************************************************** */

  bool empty() const {
    return (c.empty());
  }

  size_type size() const {
    return (c.size());
  }

  /* *************************************************** */
  /*                                                     */
  /*                     ELEMENT ACCESS                  */
  /*                                                     */
  /* *************************************************** */

  value_type& top() {
    return (c.back());
  }

  const value_type& top() const {
    return (c.back());
  }

  /* *************************************************** */
  /*                                                     */
  /*                     MODIFIERS                       */
  /*                                                     */
  /* *************************************************** */

  void push (const value_type& val) {
    c.push_back(val);
  }

  void pop() {
    c.pop_back();
  }
};

/* *************************************************** */
/*                                                     */
/*                  RELATIONAL OPERATORS               */
/*                                                     */
/* *************************************************** */
template <class T1, class Container1>
bool operator== (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs) {
  return (lhs.c == rhs.c);
}

template <class T1, class Container1>
bool operator!= (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs) {
  return (lhs.c != rhs.c);
}

template <class T1, class Container1>
bool operator<  (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs) {
  return (lhs.c < rhs.c);
}

template <class T1, class Container1>
bool operator<= (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs) {
  return (lhs.c <= rhs.c);
}

template <class T1, class Container1>
bool operator>  (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs) {
  return (lhs.c > rhs.c);
}

template <class T1, class Container1>
bool operator>= (const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs) {
  return (lhs.c >= rhs.c);
}

} // namespace ft

#endif