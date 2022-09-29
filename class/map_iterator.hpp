/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:27:13 by jrasser           #+#    #+#             */
/*   Updated: 2022/09/29 09:20:31 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_ITERATOR_HPP__
# define __MAP_ITERATOR_HPP__

#include "Iterator_traits.hpp"
#include "map.hpp"

namespace ft 
{


template <class _TreeIterator>
class map_iterator
{
protected:
	_TreeIterator                                       	it;
	typedef ft::iterator_traits<_TreeIterator>          	traits_type;

public:
	typedef _TreeIterator                                   iterator_type;
	typedef typename traits_type::iterator_category         iterator_category;
	typedef typename traits_type::value_type                value_type;
	typedef typename traits_type::difference_type           difference_type;
	typedef typename traits_type::pointer                   pointer;
	typedef typename traits_type::reference                 reference;

	// typedef std::bidirectional_iterator_tag                      iterator_category;
	// typedef typename ft::node                						value_type;
	// typedef typename _TreeIterator::difference_type              difference_type;
	// typedef value_type											&reference;
	// typedef value_type        									*pointer;

	map_iterator() : it() {}
	map_iterator(const _TreeIterator& __x) : it(__x) {}

	reference operator*() const {return it->__get_value();}
	pointer operator->() const {
		return std::addressof(it->__get_value());
	};

	map_iterator& operator++() 
	{
		++it;
		return *this;
	}
	map_iterator operator++(int)
	{
		map_iterator __t(*this);
		++(*this);
		return __t;
	}
	map_iterator& operator--() 
	{
		--it;
		return *this;
	}
	map_iterator operator--(int)
	{
		map_iterator __t(*this);
		--(*this);
		return __t;
	}

	friend bool operator==(const map_iterator& __x, const map_iterator& __y)
		{return __x.it == __y.it;}
	friend bool operator!=(const map_iterator& __x, const map_iterator& __y)
		{return __x.it != __y.it;}

	template <class, class, class, class> friend class map;
	template <class> friend class map_const_iterator;
};


template <class _TreeIterator>
class  map_const_iterator
{
	typedef typename _TreeIterator::_NodeTypes                   _NodeTypes;
	typedef typename _TreeIterator::__pointer_traits             __pointer_traits;

	_TreeIterator it;

public:
	typedef std::bidirectional_iterator_tag                      iterator_category;
	typedef typename _NodeTypes::__map_value_type                value_type;
	typedef typename _TreeIterator::difference_type              difference_type;
	typedef const value_type&                                    reference;
	typedef typename _NodeTypes::__const_map_value_type_pointer  pointer;

	map_const_iterator() {}
	// map_const_iterator(const _TreeIterator& __x) : it(__x) {}
	map_const_iterator(_TreeIterator __i) : it(__i) {}

	map_const_iterator(map_iterator<
		typename _TreeIterator::__non_const_iterator> __i)
		: it(__i.it) {}

	reference operator*() const {return it->__get_value();}

	pointer operator->() const {
		return std::addressof(it->__get_value());
	};
	// pointer operator->() const {return std::pointer_traits<pointer>::pointer_to(it->__get_value());}

	map_const_iterator& operator++() {++it; return *this;}
	map_const_iterator operator++(int)
	{
		map_const_iterator __t(*this);
		++(*this);
		return __t;
	}

	
	map_const_iterator& operator--() {--it; return *this;}
	map_const_iterator operator--(int)
	{
		map_const_iterator __t(*this);
		--(*this);
		return __t;
	}

	friend bool operator==(const map_const_iterator& __x, const map_const_iterator& __y)
		{return __x.it == __y.it;}
	friend bool operator!=(const map_const_iterator& __x, const map_const_iterator& __y)
		{return __x.it != __y.it;}

	template <class, class, class, class> friend class map;
	template <class, class, class, class> friend class multimap;
	template <class, class, class> friend class __tree_const_iterator;
};



}



#endif