/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:14:05 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/03 14:39:22 by jrasser          ###   ########.fr       */
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



	

};	// namespace ft



#endif