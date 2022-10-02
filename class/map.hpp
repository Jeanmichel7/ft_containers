/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:14:05 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/02 23:58:04 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_HPP__
# define __MAP_HPP__



// #include "map_iterator.hpp"
#include "my_reverse_iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "pair.hpp"

#include "rbtree.hpp"
#include "utils.hpp"
// #include <memory>
// #include <cstddef>
// #include <iterator>
#include <exception>
// #include <limits>

namespace ft
{

template <
	typename Key,
	typename T,
	typename Compare = std::less<Key>,
	typename Allocator = std::allocator<std::pair<const Key, T> >
>
class map
{
public:
	/* DEFINITION */

	typedef Key												key_type;
	typedef T												mapped_type;
	typedef typename ft::pair<const Key, T>					value_type;
	typedef typename std::size_t							size_type;
	typedef typename std::ptrdiff_t							difference_type;
	typedef Compare											key_compare;
	typedef Allocator										allocator_type;

	typedef value_type										&reference;
	typedef value_type const								&const_reference;
	typedef typename Allocator::pointer						pointer;
	typedef typename Allocator::const_pointer				const_pointer;


	class value_compare
	{
		typedef bool 			result_type;
		typedef value_type 		first_argument_type;
		typedef value_type 		second_argument_type;

	protected:
		Compare _comp;

	public:
		// value_compare( Compare c ) : comp(c) {}
		value_compare( Compare c );
		// bool operator() (const value_type& x, const value_type& y) const
		// { return (comp(x.first, y.first)); }
		bool operator() (const value_type& x, const value_type& y) const;
	};
	// typedef typename Allocator::template rebind<Node>::other			node_alloc_type;

	typedef typename ft::RedBlackTree<value_type, key_compare>::iterator 		iterator;
	typedef typename ft::RedBlackTree<value_type, key_compare>::const_iterator 	const_iterator;
	typedef typename ft::my_reverse_iterator<iterator>    						reverse_iterator;
	typedef typename ft::my_reverse_iterator<const_iterator> 					const_reverse_iterator;

private:
	allocator_type				_alloc;
	// node_alloc_type			_node_alloc;

	key_compare								_comp;
	// size_type							_size;
	RedBlackTree<value_type, key_compare>	_tree;
	
	// Node					*_root;
	// Node					*_end;


public:
	/* *************************************************** */
	/*                                                     */
	/*                     CONSTRUCTOR                     */
	/*                                                     */
	/* *************************************************** */

	explicit map(const Compare &comp = Compare(),
				 const Allocator &alloc = Allocator())
	:
		_alloc(alloc), _comp(comp), _tree()
	{
		std::cout << "CONSTRUCTOR map()" << std::endl;
	};

	template <class InputIt>
	map(InputIt first, InputIt last,
		const Compare &comp = Compare(),
		const Allocator &alloc = Allocator()) 
		: _alloc(alloc), _comp(comp)
	{
		std::cout << "CONSTRUCTOR map(first, last)" << std::endl;
	};

	map(const map &other)
	{
		std::cout << "Constructor map(&other)" << std::endl;

	};

	~map()
	{
		
	};

	map& operator=( const map& other )
	{
		
	};

	allocator_type get_allocator() const
	{
		
	};








	/* *************************************************** */
	/*                                                     */
	/*                     ELEMENT ACCESS                  */
	/*                                                     */
	/* *************************************************** */

	T& at( const Key& key );

	const T& at( const Key& key ) const;

	T& operator[]( const Key& key );






	/* *************************************************** */
	/*                                                     */
	/*                     ITERATORS                       */
	/*                                                     */
	/* *************************************************** */

	iterator begin() {
		return (_tree.begin());
	}

	const_iterator begin() const;

	iterator end() {
		// iterator tmp = _tree.end();
		// // tmp++;
		// return (tmp);
		return (_tree.end());
	}

	const_iterator end() const;

	reverse_iterator rbegin();

	const_reverse_iterator rbegin() const;

	reverse_iterator rend();

	const_reverse_iterator rend() const;






	/* *************************************************** */
	/*                                                     */
	/*                     CAPACITY                        */
	/*                                                     */
	/* *************************************************** */

	bool empty() const;

	size_type size() const
	{
		return (_tree.size());
	};

	size_type max_size() const;




	/* *************************************************** */
	/*                                                     */
	/*                       MODIFY                        */
	/*                                                     */
	/* *************************************************** */

	void clear();

	ft::pair<iterator, bool> insert( const value_type& value )
	{
		std::cout << "value [" << value.first << "] = " << value.second << std::endl;
		return (_tree.insert_pair(value));
	}

	iterator insert( iterator hint, const value_type& value )
	{
		(void)hint;
		return (insert(value).first);
	}

	template< class InputIt >
	void insert( InputIt first, InputIt last );

	iterator erase( iterator pos );

	iterator erase( iterator first, iterator last );

	size_type erase( const Key& key );

	void swap( map& other );






	/* *************************************************** */
	/*                                                     */
	/*                       LOOKUP                        */
	/*                                                     */
	/* *************************************************** */

	size_type count( const Key& key ) const;

	iterator find( const Key& key )
	{
		return (_tree.find(key));
	};
	
	const_iterator find( const Key& key ) const;

	std::pair<iterator,iterator> equal_range( const Key& key );
	std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;

	iterator lower_bound( const Key& key );
	const_iterator lower_bound( const Key& key ) const;

	iterator upper_bound( const Key& key );
	const_iterator upper_bound( const Key& key ) const;










	/* *************************************************** */
	/*                                                     */
	/*                      OBSERVER                       */
	/*                                                     */
	/* *************************************************** */

	key_compare key_comp() const;

	value_compare value_comp() const;







	/* *************************************************** */
	/*                                                     */
	/*                      OPERATOR                       */
	/*                                                     */
	/* *************************************************** */

	// template <class O_Key, class O_T, class O_Compare, class O_Alloc>
	// bool operator==(const map<O_Key, O_T, O_Compare, O_Alloc> &lhs,
	// 				const map<O_Key, O_T, O_Compare, O_Alloc> &rhs);

	// template <class O_Key, class O_T, class O_Compare, class O_Alloc>
	// bool operator!=(const map<O_Key, O_T, O_Compare, O_Alloc> &lhs,
	// 				const map<O_Key, O_T, O_Compare, O_Alloc> &rhs);

	// template <class O_Key, class O_T, class O_Compare, class O_Alloc>
	// bool operator<(const map<O_Key, O_T, O_Compare, O_Alloc> &lhs,
	// 			   const map<O_Key, O_T, O_Compare, O_Alloc> &rhs);

	// template <class O_Key, class O_T, class O_Compare, class O_Alloc>
	// bool operator<=(const map<O_Key, O_T, O_Compare, O_Alloc> &lhs,
	// 				const map<O_Key, O_T, O_Compare, O_Alloc> &rhs);

	// template <class O_Key, class O_T, class O_Compare, class O_Alloc>
	// bool operator>(const smap<O_Key, O_T, O_Compare, O_Alloc> &lhs,
	// 			   const smap<O_Key, O_T, O_Compare, O_Alloc> &rhs);

	// template <class O_Key, class O_T, class O_Compare, class O_Alloc>
	// bool operator>=(const map<O_Key, O_T, O_Compare, O_Alloc> &lhs,
	// 				const map<O_Key, O_T, O_Compare, O_Alloc> &rhs);



	/* *************************************************** */
	/*                                                     */
	/*                       DISPLAY                       */
	/*                                                     */
	/* *************************************************** */
	void display_tree()
	{
		_tree.display_tree("");
	}

};




	/* *************************************************** */
	/*                                                     */
	/*                 NON MEMBER FUNCTION                 */
	/*                                                     */
	/* *************************************************** */

	template <class O_Key, class O_T, class O_Compare, class O_Alloc>
	bool operator==(const map<O_Key, O_T, O_Compare, O_Alloc> &lhs,
					const map<O_Key, O_T, O_Compare, O_Alloc> &rhs);

	template <class O_Key, class O_T, class O_Compare, class O_Alloc>
	bool operator!=(const map<O_Key, O_T, O_Compare, O_Alloc> &lhs,
					const map<O_Key, O_T, O_Compare, O_Alloc> &rhs);

	template <class O_Key, class O_T, class O_Compare, class O_Alloc>
	bool operator<(const map<O_Key, O_T, O_Compare, O_Alloc> &lhs,
				   const map<O_Key, O_T, O_Compare, O_Alloc> &rhs);

	template <class O_Key, class O_T, class O_Compare, class O_Alloc>
	bool operator<=(const map<O_Key, O_T, O_Compare, O_Alloc> &lhs,
					const map<O_Key, O_T, O_Compare, O_Alloc> &rhs);

	template <class O_Key, class O_T, class O_Compare, class O_Alloc>
	bool operator>(const map<O_Key, O_T, O_Compare, O_Alloc> &lhs,
				   const map<O_Key, O_T, O_Compare, O_Alloc> &rhs);

	template <class O_Key, class O_T, class O_Compare, class O_Alloc>
	bool operator>=(const map<O_Key, O_T, O_Compare, O_Alloc> &lhs,
					const map<O_Key, O_T, O_Compare, O_Alloc> &rhs);

	template <class Key, class T, class Compare, class Alloc>
	void swap(std::map<Key, T, Compare, Alloc> &lhs,
			  std::map<Key, T, Compare, Alloc> &rhs);



	

}	// namespace ft

















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











#endif