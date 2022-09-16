/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:14:05 by jrasser           #+#    #+#             */
/*   Updated: 2022/09/16 23:59:28 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __MAP_HPP__
# define __MAP_HPP__

#include "map_iterator.hpp"
#include "my_reverse_iterator.hpp"

// #include <memory>
// #include <cstddef>
// #include <iterator>
#include <iostream>
#include <exception>

// #include <limits>

namespace ft
{

/*
Member type					Definition
key_type					Key
mapped_type					T
value_type					std::pair<const Key, T>

size_type					Unsigned integer type (usually std::size_t)

difference_type				Signed integer type (usually std::ptrdiff_t)
key_compare					Compare
allocator_type				Allocator

reference					value_type&
const_reference	const 		value_type&

pointer	 					Allocator::pointer
const_pointer	  			Allocator::const_pointer

iterator					LegacyBidirectionalIterator to value_type
const_iterator				LegacyBidirectionalIterator to const value_type

reverse_iterator			std::reverse_iterator<iterator>
const_reverse_iterator		std::reverse_iterator<const_iterator>
*/

template <
	typename Key,
	typename T,
	typename Compare = std::less<Key>,
	typename Allocator = std::allocator<std::pair<const Key, T> >
>
class map
{
	enum _Rb_tree_color { _S_red = false, _S_black = true };

	struct _Rb_tree_node_base
	{
		typedef _Rb_tree_node_base 			*_Base_ptr;
		typedef const _Rb_tree_node_base 	*_Const_Base_ptr;

		_Rb_tree_color _M_color;
		_Base_ptr _M_parent;
		_Base_ptr _M_left;
		_Base_ptr _M_right;

		static _Base_ptr
		_S_minimum(_Base_ptr __x)
		{
			while (__x->_M_left != 0)
				__x = __x->_M_left;
			return __x;
		}

		static _Const_Base_ptr
		_S_minimum(_Const_Base_ptr __x)
		{
			while (__x->_M_left != 0)
				__x = __x->_M_left;
			return __x;
		}

		static _Base_ptr
		_S_maximum(_Base_ptr __x)
		{
			while (__x->_M_right != 0)
				__x = __x->_M_right;
			return __x;
		}

		static _Const_Base_ptr
		_S_maximum(_Const_Base_ptr __x)
		{
			while (__x->_M_right != 0)
				__x = __x->_M_right;
			return __x;
		}
	};

	// Helper type offering value initialization guarantee on the compare functor.
	template <typename _Key_compare>
	struct _Rb_tree_key_compare
	{
		_Key_compare _M_key_compare;

		_Rb_tree_key_compare()
			// _GLIBCXX_NOEXCEPT_IF( std::is_nothrow_default_constructible<_Key_compare>::value )
			: _M_key_compare()
		{
		}

		_Rb_tree_key_compare(const _Key_compare &__comp)
			: _M_key_compare(__comp)
		{
		}


		// Copy constructor added for consistency with C++98 mode.
		_Rb_tree_key_compare(const _Rb_tree_key_compare &) {};

		// _Rb_tree_key_compare(_Rb_tree_key_compare &&__x) 
		// // noexcept(std::is_nothrow_copy_constructible<_Key_compare>::value)
		// 	: _M_key_compare(__x._M_key_compare)
		// {
		// }
	};

	// template <typename _Val>
	// struct node : public _Rb_tree_node_base
	// {
	// 	typedef node<_Val> 					*_Link_type;
	// 	typedef const node<_Val> 			*_Const_Link_type;
	// 	typedef _Val 						value_type;
	// 	typedef value_type 					*pointer;
	// 	typedef const value_type 			*const_pointer;
	// 	typedef value_type 					&reference;
	// 	typedef const value_type 			&const_reference;
	// 	typedef std::size_t 				size_type;
	// 	typedef std::ptrdiff_t 				difference_type;

	// 	value_type _M_value_field;


	// 	// __gnu_cxx::__aligned_membuf<_Val> 	_M_storage;

	// 	node(const value_type &__v)
	// 		: _Rb_tree_node_base(), _M_value_field(__v)
	// 	{
	// 	}

	// 	node()
	// 		: _Rb_tree_node_base(), _M_value_field()
	// 	{
	// 	}

	// 	node(const node &__x)
	// 		: _Rb_tree_node_base(), _M_value_field(__x._M_value_field)
	// 	{
	// 	}

	// 	node(node &&__x)
	// 		: _Rb_tree_node_base(), _M_value_field(std::move(__x._M_value_field))
	// 	{
	// 	}

	// 	~node()
	// 	{
	// 	}


	// 	// _Val *_M_valptr()
	// 	// {
	// 	// 	return _M_storage._M_ptr();
	// 	// }

	// 	// const _Val *_M_valptr() const
	// 	// {
	// 	// 	return _M_storage._M_ptr();
	// 	// }
	// };



public:
	typedef 	Key 											key_type;
	typedef 	T 												mapped_type;
	typedef 	Compare 										key_compare;
	typedef 	Allocator 										allocator_type;
	typedef 	std::pair<const Key, T> 						value_type;
	
	class value_compare : public std::binary_function<value_type, value_type, bool>
	{
		// friend class map<Key, T, Compare, Allocator>;

	protected:
		Compare comp;

		value_compare(Compare __c)
			: comp(__c) {}

	public:
		bool operator()(const value_type &__x, const value_type &__y) const
		{
			return comp(__x.first, __y.first);
		}
	};




	// template <>
	class node
	{
	public:
		// node() : _M_parent(NULL), _M_left(NULL), _M_right(NULL) {};
		node();
		
		node(std::pair<const Key, T> data);
		node(const Key &key, const T &value);
		node(const node &src);
		~node();
		node &operator=(const node &rhs);

	// private:
		node 						*_M_parent;
		node 						*_M_left;
		node 						*_M_right;
		std::pair<const Key, T> 	_M_value_field;
		bool 						_M_color;
		// std::pair<const Key, T>     data;

	};


private:
	typedef 	typename allocator_type::template rebind<value_type>::other 	alloc_value_type;
	typedef 	typename allocator_type::template rebind<node>::other 			alloc_node_type;
	typedef 	typename allocator_type::template rebind<node* >::other 		alloc_node_ptr_type;
	typedef 	typename allocator_type::template rebind<node** >::other 		alloc_node_ptr_ptr_type;

	typedef 	node 								node_type;
	typedef 	node* 								node_ptr_type;
	typedef 	node** 								node_ptr_ptr_type;

public:
	typedef 	typename alloc_value_type::pointer 				pointer;
	typedef 	typename alloc_value_type::const_pointer 		const_pointer;
	typedef 	typename alloc_value_type::reference 			reference;
	typedef 	typename alloc_value_type::const_reference 		const_reference;
	typedef 	typename alloc_value_type::size_type 			size_type;
	typedef 	typename alloc_value_type::difference_type 		difference_type;

	typedef 	map_iterator<value_type> 						iterator;
	typedef 	map_iterator<const value_type> 					const_iterator;
	typedef 	my_reverse_iterator<iterator> 					reverse_iterator;
	typedef 	my_reverse_iterator<const_iterator> 			const_reverse_iterator;


private:
	alloc_value_type			_alloc_value_type;
	alloc_node_type				_alloc_node_type;
	alloc_node_ptr_type			_alloc_node_ptr_type;
	alloc_node_ptr_ptr_type		_alloc_node_ptr_ptr_type;

	node_ptr_type				_root;
	node_ptr_type				_end;
	node_ptr_type				_begin;
	size_type					_size;
	key_compare					_comp;

	pointer 			_map;


// private:
// 	/// This turns a red-black tree into a [multi]map.
// 	typedef typename ft::__alloc_traits<_alloc>::template rebind<value_type>::other 				_Pair_alloc_type;
// 	typedef _Rb_tree<key_type, value_type, _Select1st<value_type>, key_compare, _Pair_alloc_type> 	_Rep_type;

// 	/// The actual tree structure.
// 	_Rep_type _M_t;

// 	typedef __gnu_cxx::__alloc_traits<_Pair_alloc_type> _Alloc_traits;


public:

	/* *************************************************** */
	/*                                                     */
	/*                     CONSTRUCTOR                     */
	/*                                                     */
	/* *************************************************** */

	explicit map (const key_compare& comp = key_compare(),
				  const allocator_type& alloc = allocator_type()) :
		_alloc_value_type(alloc),
		_alloc_node_type(alloc),
		_alloc_node_ptr_type(alloc),
		_alloc_node_ptr_ptr_type(alloc),
		_root(NULL),
		_end(NULL),
		_begin(NULL),
		_size(0),
		_comp(comp),
		_map(NULL)
	{
		std::cout << "Constructor map(comp, alloc)" << std::endl;


	};

	template <class InputIt>
	map(InputIt first, InputIt last,
		const Compare &comp = Compare(),
		const Allocator &alloc = Allocator())
		{
			std::cout << "Constructor map(first, last, comp, alloc)" << std::endl;

		};


	map( const map& other )
	{
		
	};

	~map()
	{
		
	};


	map &operator=(const map &__x)
	{
		
	};

	// /* *************************************************** */
	// /*                                                     */
	// /*                     ITERATORS                       */
	// /*                                                     */
	// /* *************************************************** */
	

	// iterator begin()
	// {
	// 	return (iterator(_begin));
	// }

	// const_iterator begin() const
	// {
	// 	return (const_iterator(_begin));
	// }

	// iterator end()
	// {
	// 	return (iterator(_end));
	// }

	// const_iterator end() const
	// {
	// 	return (const_iterator(_end));
	// }

	// reverse_iterator rbegin()
	// {
	// 	return (reverse_iterator(end()));
	// }

	// const_reverse_iterator rbegin() const
	// {
	// 	return (const_reverse_iterator(end()));
	// }

	// reverse_iterator rend()
	// {
	// 	return (reverse_iterator(begin()));
	// }

	// const_reverse_iterator rend() const
	// {
	// 	return (const_reverse_iterator(begin()));
	// }

	// bool empty() const
	// {
	// 	return (_size == 0);
	// }

	// size_type size() const
	// {
	// 	return (_size);
	// }

	// size_type max_size() const
	// {
	// 	return (_alloc_value_type.max_size());
	// }



	// // /* *************************************************** */
	// // /*                                                     */
	// // /*                     ELEMENT ACCESS                  */
	// // /*                                                     */
	// // /* *************************************************** */

	// T& at( const Key& key )
	// {
	// 	iterator it = find(key);
	// 	if (it == end())
	// 		throw std::out_of_range("map::at");
	// 	return (*it);
	// };

	// mapped_type &operator[](const key_type &__k)
	// {
	// 	iterator it = lower_bound(__k);
	// 	if (it == end() || _comp(__k, (*it).first))
	// 		it = insert(it, value_type(__k, mapped_type()));
	// 	return ((*it).second);
	// }

	// // /* *************************************************** */
	// // /*                                                     */
	// // /*                     MODIFIERS                       */
	// // /*                                                     */
	// // /* *************************************************** */




	// /* *************************************************** */
	// /*                                                     */
	// /*                     OBSERVERS                       */
	// /*                                                     */
	// /* *************************************************** */


	// key_compare key_comp() const
	// {
	// 	return (_comp);
	// }

	// value_compare value_comp() const
	// {
	// 	return (value_compare(_comp));
	// }



	// /* *************************************************** */
	// /*                                                     */
	// /*                       LOOKUP                        */
	// /*                                                     */
	// /* *************************************************** */


	// iterator find(const key_type &__k)
	// {
	// 	node_ptr_type tmp = _root;

	// 	while (tmp != nullptr)
	// 	{
	// 		if (_comp(__k, tmp->_M_valptr()->first))
	// 			tmp = tmp->_M_left;
	// 		else if (_comp(tmp->_M_valptr()->first, __k))
	// 			tmp = tmp->_M_right;
	// 		else
	// 			return (iterator(tmp));
	// 	}
	// 	return (end());
	// }

	// const_iterator find(const key_type &__k) const
	// {
	// 	node_ptr_type tmp = _root;

	// 	while (tmp != nullptr)
	// 	{
	// 		if (_comp(__k, tmp->_M_valptr()->first))
	// 			tmp = tmp->_M_left;
	// 		else if (_comp(tmp->_M_valptr()->first, __k))
	// 			tmp = tmp->_M_right;
	// 		else
	// 			return (const_iterator(tmp));
	// 	}
	// 	return (end());
	// }

	// size_type count(const key_type &__k) const
	// {
	// 	if (find(__k) == end())
	// 		return (0);
	// 	return (1);
	// }

	// iterator lower_bound(const key_type &__k)
	// {
	// 	iterator it = begin();

	// 	while (it != end())
	// 	{
	// 		if (!_comp(it->first, __k))
	// 			return (it);
	// 		it++;
	// 	}
	// 	return (end());
	// }

	// const_iterator lower_bound(const key_type &__k) const
	// {
	// 	const_iterator it = begin();

	// 	while (it != end())
	// 	{
	// 		if (!_comp(it->first, __k))
	// 			return (it);
	// 		it++;
	// 	}
	// 	return (end());
	// }

	// iterator upper_bound(const key_type &__k)
	// {
	// 	iterator it = begin();

	// 	while (it != end())
	// 	{
	// 		if (_comp(__k, it->first))
	// 			return (it);
	// 		it++;
	// 	}
	// 	return (end());
	// }

	// const_iterator upper_bound(const key_type &__k) const
	// {
	// 	const_iterator it = begin();

	// 	while (it != end())
	// 	{
	// 		if (_comp(__k, it->first))
	// 			return (it);
	// 		it++;
	// 	}
	// 	return (end());
	// }

	// pair<const_iterator, const_iterator> equal_range(const key_type &__k) const
	// {
	// 	return (make_pair(lower_bound(__k), upper_bound(__k)));
	// }

	// pair<iterator, iterator> equal_range(const key_type &__k)
	// {
	// 	return (make_pair(lower_bound(__k), upper_bound(__k)));
	// }


	// /* *************************************************** */
	// /*                                                     */
	// /*                     OPERATOR                        */
	// /*                                                     */
	// /* *************************************************** */

	// template <class O_Key, class O_T, class  O_Compare, class  O_Alloc>
	// bool operator==( const std::map<O_Key, O_T,  O_Compare,  O_Alloc> &rhs )
	// {
	// 	if (size() != rhs.size())
	// 		return (false);
	// 	typename std::map<O_Key, O_T,  O_Compare,  O_Alloc>::const_iterator it = begin();
	// 	typename std::map<O_Key, O_T,  O_Compare,  O_Alloc>::const_iterator ite = end();
	// 	typename std::map<O_Key, O_T,  O_Compare,  O_Alloc>::const_iterator it2 = rhs.begin();
	// 	while (it != ite)
	// 	{
	// 		if (*it != *it2)
	// 			return (false);
	// 		it++;
	// 		it2++;
	// 	}
	// 	return (true);
	// };

	// template <class O_Key, class O_T, class  O_Compare, class  O_Alloc>
	// bool operator!=(const std::map<O_Key, O_T,  O_Compare,  O_Alloc> &rhs)
	// {
	// 	return (!(*this == rhs));
	// };

	// template <class O_Key, class O_T, class  O_Compare, class  O_Alloc>
	// bool operator<( const std::map<O_Key, O_T,  O_Compare,  O_Alloc> &rhs )
	// {
	// 	typename std::map<O_Key, O_T,  O_Compare,  O_Alloc>::const_iterator it = begin();
	// 	typename std::map<O_Key, O_T,  O_Compare,  O_Alloc>::const_iterator ite = end();
	// 	typename std::map<O_Key, O_T,  O_Compare,  O_Alloc>::const_iterator it2 = rhs.begin();
	// 	while (it != ite)
	// 	{
	// 		if (it2 == rhs.end() || *it2 < *it)
	// 			return (false);
	// 		else if (*it < *it2)
	// 			return (true);
	// 		it++;
	// 		it2++;
	// 	}
	// 	return (it2 != rhs.end());
	// };

	// template <class O_Key, class O_T, class  O_Compare, class  O_Alloc>
	// bool operator<=( const std::map<O_Key, O_T,  O_Compare,  O_Alloc> &rhs )

	// {
	// 	return (!(rhs < *this));
	// };

	// template <class O_Key, class O_T, class  O_Compare, class  O_Alloc>
	// bool operator>(const std::map<O_Key, O_T,  O_Compare,  O_Alloc> &rhs)
	// {
	// 	return (rhs < *this);
	// };

	// template <class O_Key, class O_T, class  O_Compare, class  O_Alloc>
	// bool operator>=( const std::map<O_Key, O_T,  O_Compare,  O_Alloc> &rhs )
	// {
	// 	return (!(*this < rhs));
	// };










	/* ************************************************************************* */

	// /* *************************************************** */
	// /*                                                     */
	// /*                     CONSTRUCTOR                     */
	// /*                                                     */
	// /* *************************************************** */


	// explicit map(const key_compare &__comp = key_compare(),
	// 			 const allocator_type &__a = allocator_type())
	// 	: _alloc_value_type(__a), _alloc_node_type(__a), _alloc_node_ptr_type(__a), _alloc_node_ptr_ptr_type(__a),
	// 	_root(nullptr), _end(nullptr), _begin(nullptr), _size(0), _comp(__comp)
	// {
	// 	std::cout << "flkndslksdnflsdkfnsdlfknfklsdnf" << std::endl;
	// 	// _end = _alloc_node_type.allocate(1);
	// 	// _end->_M_color = _S_red;
	// 	// _end->_M_parent = nullptr;
	// 	// _end->_M_left = nullptr;
	// 	// _end->_M_right = nullptr;
	// 	// _end->_M_valptr() = nullptr;
	// 	// _begin = _end;
	// }

	// template <typename _InputIterator>
	// map(_InputIterator __first, _InputIterator __last,
	// 	const key_compare &__comp = key_compare(),
	// 	const allocator_type &__a = allocator_type())
	// 	: _alloc_value_type(__a), _alloc_node_type(__a), _alloc_node_ptr_type(__a), _alloc_node_ptr_ptr_type(__a),
	// 	_root(nullptr), _end(nullptr), _begin(nullptr), _size(0), _comp(__comp)
	// {
	// 	_end = _alloc_node_type.allocate(1);
	// 	_end->_M_color = _S_red;
	// 	_end->_M_parent = nullptr;
	// 	_end->_M_left = nullptr;
	// 	_end->_M_right = nullptr;
	// 	_end->_M_valptr() = nullptr;
	// 	_begin = _end;
	// 	insert(__first, __last);
	// }

	// map(const map &__x)
	// 	: _alloc_value_type(__x._alloc_value_type), _alloc_node_type(__x._alloc_node_type), _alloc_node_ptr_type(__x._alloc_node_ptr_type), _alloc_node_ptr_ptr_type(__x._alloc_node_ptr_ptr_type),
	// 	_root(nullptr), _end(nullptr), _begin(nullptr), _size(0), _comp(__x._comp)
	// {
	// 	_end = _alloc_node_type.allocate(1);
	// 	_end->_M_color = _S_red;
	// 	_end->_M_parent = nullptr;
	// 	_end->_M_left = nullptr;
	// 	_end->_M_right = nullptr;
	// 	_end->_M_valptr() = nullptr;
	// 	_begin = _end;
	// 	insert(__x.begin(), __x.end());
	// }

	// ~map()
	// {
	// 	clear();
	// 	_alloc_node_type.deallocate(_end, 1);
	// }

	// map &operator=(const map &__x)
	// {
	// 	if (this != &__x)
	// 	{
	// 		clear();
	// 		insert(__x.begin(), __x.end());
	// 	}
	// 	return (*this);
	// }


	// /* *************************************************** */
	// /*                                                     */
	// /*                     ITERATORS                       */
	// /*                                                     */
	// /* *************************************************** */
	

	// iterator begin()
	// {
	// 	return (iterator(_begin));
	// }

	// const_iterator begin() const
	// {
	// 	return (const_iterator(_begin));
	// }

	// iterator end()
	// {
	// 	return (iterator(_end));
	// }

	// const_iterator end() const
	// {
	// 	return (const_iterator(_end));
	// }

	// reverse_iterator rbegin()
	// {
	// 	return (reverse_iterator(end()));
	// }

	// const_reverse_iterator rbegin() const
	// {
	// 	return (const_reverse_iterator(end()));
	// }

	// reverse_iterator rend()
	// {
	// 	return (reverse_iterator(begin()));
	// }

	// const_reverse_iterator rend() const
	// {
	// 	return (const_reverse_iterator(begin()));
	// }

	// bool empty() const
	// {
	// 	return (_size == 0);
	// }

	// size_type size() const
	// {
	// 	return (_size);
	// }

	// size_type max_size() const
	// {
	// 	return (_alloc_value_type.max_size());
	// }



	// /* *************************************************** */
	// /*                                                     */
	// /*                     ELEMENT ACCESS                  */
	// /*                                                     */
	// /* *************************************************** */

	// T& at( const Key& key )
	// {
	// 	iterator it = find(key);
	// 	if (it == end())
	// 		throw std::out_of_range("map::at");
	// 	return (*it);
	// };

	// mapped_type &operator[](const key_type &__k)
	// {
	// 	iterator it = lower_bound(__k);
	// 	if (it == end() || _comp(__k, (*it).first))
	// 		it = insert(it, value_type(__k, mapped_type()));
	// 	return ((*it).second);
	// }



	// /* *************************************************** */
	// /*                                                     */
	// /*                     MODIFIERS                       */
	// /*                                                     */
	// /* *************************************************** */

	// void clear()
	// {
	// 	erase(begin(), end());
	// }

	// std::pair<iterator, bool> insert(const value_type &__x)
	// {
	// 	node_ptr_type tmp = _root;
	// 	node_ptr_type parent = nullptr;
	// 	bool left = true;

	// 	while (tmp != nullptr)
	// 	{
	// 		parent = tmp;
	// 		if (_comp(__x.first, tmp->_M_valptr()->first))
	// 		{
	// 			tmp = tmp->_M_left;
	// 			left = true;
	// 		}
	// 		else if (_comp(tmp->_M_valptr()->first, __x.first))
	// 		{
	// 			tmp = tmp->_M_right;
	// 			left = false;
	// 		}
	// 		else
	// 			return (std::pair<iterator, bool>(iterator(tmp), false));
	// 	}
	// 	node_ptr_type new_node = _alloc_node_type.allocate(1);
	// 	_alloc_value_type.construct(new_node->_M_valptr(), __x);
	// 	new_node->_M_color = _S_red;
	// 	new_node->_M_parent = parent;
	// 	new_node->_M_left = nullptr;
	// 	new_node->_M_right = nullptr;
	// 	if (parent == nullptr)
	// 		_root = new_node;
	// 	else if (left)
	// 		parent->_M_left = new_node;
	// 	else
	// 		parent->_M_right = new_node;
	// 	_size++;
	// 	if (_begin == _end || _comp(__x.first, _begin->_M_valptr()->first))
	// 		_begin = new_node;
	// 	_insert_fixup(new_node);
	// 	return (std::pair<iterator, bool>(iterator(new_node), true));
	// }

	// iterator insert(iterator __position, const value_type &__x)
	// {
	// 	(void)__position;
	// 	return (insert(__x).first);
	// }

	// template <typename _InputIterator>

	// void insert(_InputIterator __first, _InputIterator __last)
	// {
	// 	while (__first != __last)
	// 	{
	// 		insert(*__first);
	// 		__first++;
	// 	}
	// }

	// // void erase(iterator __position)
	// // {
	// // 	node_ptr_type node = __position._node;
	// // 	node_ptr_type y = node;
	// // 	node_ptr_type x = nullptr;
	// // 	node_ptr_type x_parent = nullptr;
	// // 	// color_type y_original_color = y->_M_color;

	// // 	if (node->_M_left == nullptr)
	// // 	{
	// // 		x = node->_M_right;
	// // 		_transplant(node, node->_M_right);
	// // 	}
	// // 	else if (node->_M_right == nullptr)
	// // 	{
	// // 		x =
	// // 			node->_M_left;
	// // 		_transplant(node, node->_M_left);
	// // 	}
	// // 	else
	// // 	{
	// // 		y = _minimum(node->_M_right);
	// // 		y_original_color = y->_M_color;
	// // 		x = y->_M_right;
	// // 		if (y->_M_parent == node)
	// // 			x_parent = y;
	// // 		else
	// // 		{
	// // 			x_parent = y->_M_parent;
	// // 			_transplant(y, y->_M_right);
	// // 			y->_M_right = node->_M_right;
	// // 			y->_M_right->_M_parent = y;
	// // 		}
	// // 		_transplant(node, y);
	// // 		y->_M_left = node->_M_left;
	// // 		y->_M_left->_M_parent = y;
	// // 		y->_M_color = node->_M_color;
	// // 	}
	// // 	if (y_original_color == _S_black)
	// // 		_erase_fixup(x, x_parent);
	// // 	_alloc_value_type.destroy(node->_M_valptr());
	// // 	_alloc_node_type.deallocate(node, 1);
	// // 	_size--;
	// // }

	// size_type erase(const key_type &__x)
	// {
	// 	iterator it = find(__x);
	// 	if (it == end())
	// 		return (0);
	// 	erase(it);
	// 	return (1);
	// }

	// void erase(iterator __first, iterator __last)
	// {
	// 	while (__first != __last)
	// 		erase(__first++);
	// }

	// void swap(map &__x)
	// {
	// 	node_ptr_type tmp_root = _root;
	// 	node_ptr_type tmp_begin = _begin;
	// 	node_ptr_type tmp_end = _end;
	// 	size_type tmp_size = _size;

	// 	_root = __x._root;
	// 	_begin = __x._begin;
	// 	_end = __x._end;
	// 	_size = __x._size;

	// 	__x._root = tmp_root;
	// 	__x._begin = tmp_begin;
	// 	__x._end = tmp_end;
	// 	__x._size = tmp_size;
	// }

	

	// /* *************************************************** */
	// /*                                                     */
	// /*                     OBSERVERS                       */
	// /*                                                     */
	// /* *************************************************** */


	// key_compare key_comp() const
	// {
	// 	return (_comp);
	// }

	// value_compare value_comp() const
	// {
	// 	return (value_compare(_comp));
	// }



	// /* *************************************************** */
	// /*                                                     */
	// /*                       LOOKUP                        */
	// /*                                                     */
	// /* *************************************************** */


	// iterator find(const key_type &__k)
	// {
	// 	node_ptr_type tmp = _root;

	// 	while (tmp != nullptr)
	// 	{
	// 		if (_comp(__k, tmp->_M_valptr()->first))
	// 			tmp = tmp->_M_left;
	// 		else if (_comp(tmp->_M_valptr()->first, __k))
	// 			tmp = tmp->_M_right;
	// 		else
	// 			return (iterator(tmp));
	// 	}
	// 	return (end());
	// }

	// const_iterator find(const key_type &__k) const
	// {
	// 	node_ptr_type tmp = _root;

	// 	while (tmp != nullptr)
	// 	{
	// 		if (_comp(__k, tmp->_M_valptr()->first))
	// 			tmp = tmp->_M_left;
	// 		else if (_comp(tmp->_M_valptr()->first, __k))
	// 			tmp = tmp->_M_right;
	// 		else
	// 			return (const_iterator(tmp));
	// 	}
	// 	return (end());
	// }

	// size_type count(const key_type &__k) const
	// {
	// 	if (find(__k) == end())
	// 		return (0);
	// 	return (1);
	// }

	// iterator lower_bound(const key_type &__k)
	// {
	// 	iterator it = begin();

	// 	while (it != end())
	// 	{
	// 		if (!_comp(it->first, __k))
	// 			return (it);
	// 		it++;
	// 	}
	// 	return (end());
	// }

	// const_iterator lower_bound(const key_type &__k) const
	// {
	// 	const_iterator it = begin();

	// 	while (it != end())
	// 	{
	// 		if (!_comp(it->first, __k))
	// 			return (it);
	// 		it++;
	// 	}
	// 	return (end());
	// }

	// iterator upper_bound(const key_type &__k)
	// {
	// 	iterator it = begin();

	// 	while (it != end())
	// 	{
	// 		if (_comp(__k, it->first))
	// 			return (it);
	// 		it++;
	// 	}
	// 	return (end());
	// }

	// const_iterator upper_bound(const key_type &__k) const
	// {
	// 	const_iterator it = begin();

	// 	while (it != end())
	// 	{
	// 		if (_comp(__k, it->first))
	// 			return (it);
	// 		it++;
	// 	}
	// 	return (end());
	// }

	// pair<const_iterator, const_iterator> equal_range(const key_type &__k) const
	// {
	// 	return (make_pair(lower_bound(__k), upper_bound(__k)));
	// }

	// pair<iterator, iterator> equal_range(const key_type &__k)
	// {
	// 	return (make_pair(lower_bound(__k), upper_bound(__k)));
	// }



	// /* *************************************************** */
	// /*                                                     */
	// /*                     OPERATOR                        */
	// /*                                                     */
	// /* *************************************************** */

	// template <class O_Key, class O_T, class  O_Compare, class  O_Alloc>
	// bool operator==( const std::map<O_Key, O_T,  O_Compare,  O_Alloc> &rhs )
	// {
	// 	if (size() != rhs.size())
	// 		return (false);
	// 	typename std::map<O_Key, O_T,  O_Compare,  O_Alloc>::const_iterator it = begin();
	// 	typename std::map<O_Key, O_T,  O_Compare,  O_Alloc>::const_iterator ite = end();
	// 	typename std::map<O_Key, O_T,  O_Compare,  O_Alloc>::const_iterator it2 = rhs.begin();
	// 	while (it != ite)
	// 	{
	// 		if (*it != *it2)
	// 			return (false);
	// 		it++;
	// 		it2++;
	// 	}
	// 	return (true);
	// };

	// template <class O_Key, class O_T, class  O_Compare, class  O_Alloc>
	// bool operator!=(const std::map<O_Key, O_T,  O_Compare,  O_Alloc> &rhs)
	// {
	// 	return (!(*this == rhs));
	// };

	// template <class O_Key, class O_T, class  O_Compare, class  O_Alloc>
	// bool operator<( const std::map<O_Key, O_T,  O_Compare,  O_Alloc> &rhs )
	// {
	// 	typename std::map<O_Key, O_T,  O_Compare,  O_Alloc>::const_iterator it = begin();
	// 	typename std::map<O_Key, O_T,  O_Compare,  O_Alloc>::const_iterator ite = end();
	// 	typename std::map<O_Key, O_T,  O_Compare,  O_Alloc>::const_iterator it2 = rhs.begin();
	// 	while (it != ite)
	// 	{
	// 		if (it2 == rhs.end() || *it2 < *it)
	// 			return (false);
	// 		else if (*it < *it2)
	// 			return (true);
	// 		it++;
	// 		it2++;
	// 	}
	// 	return (it2 != rhs.end());
	// };

	// template <class O_Key, class O_T, class  O_Compare, class  O_Alloc>
	// bool operator<=( const std::map<O_Key, O_T,  O_Compare,  O_Alloc> &rhs )

	// {
	// 	return (!(rhs < *this));
	// };

	// template <class O_Key, class O_T, class  O_Compare, class  O_Alloc>
	// bool operator>(const std::map<O_Key, O_T,  O_Compare,  O_Alloc> &rhs)
	// {
	// 	return (rhs < *this);
	// };

	// template <class O_Key, class O_T, class  O_Compare, class  O_Alloc>
	// bool operator>=( const std::map<O_Key, O_T,  O_Compare,  O_Alloc> &rhs )
	// {
	// 	return (!(*this < rhs));
	// };


};

}	// namespace ft



#endif