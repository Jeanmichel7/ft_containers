/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:23:15 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/28 22:20:41 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#define N_BLACK 0
#define N_RED 1
#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define BLU "\033[0;34m"
#define MAG "\033[0;35m"
#define CYA "\033[0;36m"
#define END "\033[0m"

#include <iostream>
#include <math.h>
#include <deque>
#include <string.h>
#include <cstring>
#include <exception>

// #include "enable_if.hpp"

namespace ft
{

template <class T1, class T2>
struct pair 
{
	typedef T1 first_type;
	typedef T2 second_type;

	T1 first;
	T2 second;

	/* ************************************************************************** */
	/*                                                                            */
	/*                                MEMBER FUNCTION                             */
	/*                                                                            */
	/* ************************************************************************** */

	pair() : first(T1()), second(T2()) {}

	template <class U, class V>
	pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {}

	pair(const T1& a, const T2& b) : first(a), second(b) {}

	pair& operator=(const pair& pr)
	{
		if (*this == pr)
			return *this;
		this->first = pr.first;
		this->second = pr.second;
		return *this;
	}

	~pair() {}

	/* ************************************************************************** */
	/*                                                                            */
	/*                                    OPERATOR                                */
	/*                                                                            */
	/* ************************************************************************** */

	template <class T_1, class T_2>
	bool operator==(const pair<T_1, T_2> &rhs)
	{
		return (first == rhs.first && second == rhs.second);
	}
	
	template <class T_1, class T_2>
	bool operator!=(const pair<T_1, T_2> &rhs) 
	{
		return !(*this == rhs);
	}

	template <class T_1, class T_2>
	bool operator<( const pair<T_1, T_2> &rhs) const
	{
		return (first < rhs.first || (!(rhs.first < first) && second < rhs.second));
	}

	template <class T_1, class T_2>
	bool operator<=(const pair<T_1, T_2> &rhs)
	{
		return !(*this > rhs);
	}

	template <class T_1, class T_2>
	bool operator>(const pair<T_1, T_2> &rhs) const
	{
		return (rhs < *this);
	}

	template <class T_1, class T_2>
	bool operator>=(const pair<T_1, T_2> &rhs)
	{
		return !(*this <= rhs);
	}
};




template <class T1, class T2>
pair<T1, T2> make_pair(T1 x, T2 y)
{
	return (ft::pair<T1, T2>(x, y));
}



template <class InputIt1, class InputIt2>
bool equal(InputIt1 first1, InputIt1 last1,
		   InputIt2 first2)
{
	for (; first1 != last1; ++first1, ++first2) {
		if (!(*first1 == *first2)) {
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
	for (; first1 != last1; ++first1, ++first2) {
		if (first2 == last2 || *first2 < *first1) {
			return false;
		}
		if (*first1 < *first2) {
			return true;
		}
	}
	return first2 != last2;
}

template <class InputIt1, class InputIt2, class Compare>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
							 InputIt2 first2, InputIt2 last2, Compare comp)
{
	for (; first1 != last1; ++first1, ++first2) {
		if (first2 == last2 || comp(*first2, *first1)) {
			return false;
		}
		if (comp(*first1, *first2)) {
			return true;
		}
	}
	return first2 != last2;
}

template <typename T>
struct Node
{
	typedef T   value_type;
	value_type           _content;
	Node                *_parent;
	Node                *_left;
	Node                *_right;
	int                  _color;
	Node(Node *left, Node *right) 
	: _left(left), _right(right), _color(N_BLACK) {}
	
	Node(Node *parent, Node *left, Node *right) 
	: _parent(parent), _left(left), _right(right), _color(N_BLACK) {}
	Node(T content, Node *parent, Node *left, Node *right, int color) 
	: _content(content), _parent(parent), _left(left), _right(right), _color(color) {}
	Node(T const &content) 
	: _content(content), _parent(NULL), _left(NULL), _right(NULL), _color(N_RED) {}
	Node(T const &content, int color) 
	: _content(content), _parent(NULL), _left(NULL), _right(NULL), _color(color) {}
	Node(Node const &src) 
	:   _content(src._content),
		_parent(src._parent),
		_left(src._left),
		_right(src._right),
		_color(src._color)
	{
		return;
	}
	~Node() {}
	Node &operator=(Node const &rhs)
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

} // namespace ft

#endif