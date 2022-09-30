/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:23:15 by jrasser           #+#    #+#             */
/*   Updated: 2022/09/30 18:53:07 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include "enable_if.hpp"

namespace ft
{

    template <class InputIt1, class InputIt2>
    bool equal(InputIt1 first1, InputIt1 last1,
               InputIt2 first2)
    {
        for (; first1 != last1; ++first1, ++first2)
        {
            if (!(*first1 == *first2))
            {
                return false;
            }
        }
        return true;
    }

    template <class InputIt1, class InputIt2, class BinaryPredicate>
    bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
    {
        for (; first1 != last1; ++first1, ++first2)
        {
            if (!p(*first1, *first2))
            {
                return false;
            }
        }
        return true;
    }

    template <class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                 InputIt2 first2, InputIt2 last2)
    {
        for (; first1 != last1; ++first1, ++first2)
        {
            if (first2 == last2 || *first2 < *first1)
            {
                return false;
            }
            if (*first1 < *first2)
            {
                return true;
            }
        }
        return first2 != last2;
    }

    template <class InputIt1, class InputIt2, class Compare>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                 InputIt2 first2, InputIt2 last2, Compare comp)
    {
        for (; first1 != last1; ++first1, ++first2)
        {
            if (first2 == last2 || comp(*first2, *first1))
            {
                return false;
            }
            if (comp(*first1, *first2))
            {
                return true;
            }
        }
        return first2 != last2;
    }

    template <typename T>
    struct Node
    {
    public:
        typedef T   value_type;
        
        T _content;
        Node<T> *_parent;
        Node<T> *_left;
        Node<T> *_right;
        int _color;

        Node() : _content(), _parent(NULL), _left(NULL), _right(NULL), _color(0) {}
        Node(T content) : _content(content), _parent(NULL), _left(NULL), _right(NULL), _color(0) {}
        Node(T content, Node<T> *parent, Node<T> *left, Node<T> *right, int color) : _content(content), _parent(parent), _left(left), _right(right), _color(color) {}
        Node(Node<T> const &src) { *this = src; }
        ~Node() {}

        Node<T> &operator=(Node<T> const &rhs)
        {
            if (this != &rhs)
            {
                this->_content = rhs._content;
                this->_parent = rhs._parent;
                this->_left = rhs._left;
                this->_right = rhs._right;
                this->_color = rhs._color;
            }
            return (*this);
        }
    };
}

#endif