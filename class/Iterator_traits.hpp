/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:24:21 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/08 23:42:44 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITERATOR_TRAIT__
# define __ITERATOR_TRAIT__

#include <typeinfo>
#include <memory>
#include <cstddef>
#include <iterator>
#include <iostream>
#include <limits>

namespace ft
{

typedef __SIZE_TYPE__       size_t;
typedef __PTRDIFF_TYPE__    ptrdiff_t;


template <typename _Category, typename _Tp, typename _Distance = ptrdiff_t,
		  typename _Pointer = _Tp *, typename _Reference = _Tp &>
struct iterator
{
	typedef _Category iterator_category;
	typedef _Tp value_type;
	typedef _Distance difference_type;
	typedef _Pointer pointer;
	typedef _Reference reference;
};

template <typename _Iterator>
struct iterator_traits
{
    typedef typename std::random_access_iterator_tag    iterator_category;
    // typedef typename std::bidirectional_iterator_tag       iterator_category;
    typedef typename _Iterator::value_type              value_type;
    typedef typename _Iterator::difference_type         difference_type;
    typedef typename _Iterator::pointer                 pointer;
    typedef typename _Iterator::reference               reference;
};

/// Partial specialization for pointer types.
template <typename _Tp>
struct iterator_traits<_Tp *>
{
    typedef std::random_access_iterator_tag     iterator_category;
    typedef _Tp                                 value_type;
    typedef ptrdiff_t                           difference_type;
    typedef _Tp                                 *pointer;
    typedef _Tp                                 &reference;
};

/// Partial specialization for const pointer types.
template <typename _Tp>
struct iterator_traits<const _Tp *>
{
    typedef std::random_access_iterator_tag     iterator_category;
    typedef _Tp                                 value_type;
    typedef ptrdiff_t                           difference_type;
    typedef const _Tp                           *pointer;
    typedef const _Tp                           &reference;
};

struct input_iterator_tag  {};
struct output_iterator_tag {};
struct forward_iterator_tag       : public input_iterator_tag         {};
struct bidirectional_iterator_tag : public forward_iterator_tag       {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

}
#endif