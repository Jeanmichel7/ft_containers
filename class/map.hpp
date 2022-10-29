/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:14:05 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/29 23:50:54 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_HPP__
# define __MAP_HPP__

// #include "map_iterator.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "utils/rbtree.hpp"
#include "utils.hpp"

// #include <memory>
// #include <cstddef>
// #include <iterator>
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

	typedef Key																				key_type;
	typedef T																					mapped_type;
	typedef typename ft::pair<const Key, T>						value_type;
	typedef typename std::size_t											size_type;
	typedef typename std::ptrdiff_t										difference_type;
	typedef Compare																		key_compare;
	typedef Allocator																	allocator_type;

	typedef value_type																&reference;
	typedef value_type const													&const_reference;
	typedef typename Allocator::pointer								pointer;
	typedef typename Allocator::const_pointer const			const_pointer;


	class value_compare
	{
		typedef bool 					result_type;
		typedef value_type 		first_argument_type;
		typedef value_type 		second_argument_type;

	protected:
		Compare _comp;

	public:
		value_compare( Compare c ) : _comp(c) {}

		bool operator() (const value_type& x, const value_type& y) const{
			return (this->_comp(x.first, y.first));
		}
	};



	// typedef typename Allocator::template rebind<Node>::other			node_alloc_type;
	typedef typename ft::RedBlackTree<value_type, key_compare>			tree_type;

	typedef typename tree_type::iterator 									iterator;
	typedef typename tree_type::const_iterator						const_iterator;
	typedef typename tree_type::reverse_iterator					reverse_iterator;
	typedef typename tree_type::const_reverse_iterator		const_reverse_iterator;



private:
	allocator_type		_alloc;
	key_compare				_comp;
	tree_type					_tree;



public:
	/* *************************************************** */
	/*                                                     */
	/*                     CONSTRUCTOR                     */
	/*                                                     */
	/* *************************************************** */

	explicit map(const Compare &comp = Compare(),
				 const Allocator &alloc = Allocator())
	:
		_alloc(alloc),
		_comp(comp),
		_tree()
	{
		// std::cout << "CONSTRUCTOR map()" << std::endl;
	};

	template <class InputIt>
	map(InputIt first, InputIt last,
		const Compare &comp = Compare(),
		const Allocator &alloc = Allocator()) 
	: _alloc(alloc), _comp(comp), _tree()
	{
		// std::cout << "CONSTRUCTOR map(first, last)" << std::endl;
		_tree.insert(first, last);
	};

	map(const map &other)
	: _alloc(other._alloc), _comp(other._comp), _tree(other._tree)
	{
		// std::cout << "CONSTRUCTOR copie " << std::endl;
		// _tree.insert(other.begin(), other.end());
	};

	~map() {
		// std::cout << "DESTRUCTOR map()" << std::endl;
	};

	map& operator=( const map& other )
	{
		clear();
		_tree.insert(other.begin(), other.end());
		return (*this);
	};

	allocator_type get_allocator() const
	{
		return (this->_alloc);
	};












	/* *************************************************** */
	/*                                                     */
	/*                     ITERATORS                       */
	/*                                                     */
	/* *************************************************** */

	iterator begin() {
		return (_tree.begin());
	}

	const_iterator begin() const {
		// std::cout << "const begin()" << std::endl;
		return (_tree.begin());
	}

	iterator end() {
		return (_tree.end());
	}

	const_iterator end() const {
		// std::cout << "const end()" << std::endl;
		return (_tree.end());
	}

	reverse_iterator rbegin() {
		return (_tree.rbegin());
	}

	const_reverse_iterator rbegin() const {
		// std::cout << "const_reverse_iterator rbegin() const" << std::endl;
		return (_tree.rbegin());
	}

	reverse_iterator rend() {
		return (_tree.rend());
	}

	const_reverse_iterator rend() const {
		// std::cout << "const_reverse_iterator rend() const" << std::endl;
		return (_tree.rend());
	}






	/* *************************************************** */
	/*                                                     */
	/*                     CAPACITY                        */
	/*                                                     */
	/* *************************************************** */

	bool empty() const {
		return (_tree.empty());
	}

	size_type size() const {
		return (_tree.size());
	}

	size_type max_size() const {
		return _tree.max_size();
	}






	/* *************************************************** */
	/*                                                     */
	/*                     ELEMENT ACCESS                  */
	/*                                                     */
	/* *************************************************** */

	T& at( const Key& key ) {
			iterator it = find(key);
			if (it == end())
				throw std::out_of_range("map::at");
			return (it->second);
	}

	const T& at( const Key& key ) const {
			const_iterator it = find(key);
			if (it == end())
				throw std::out_of_range("map::at");
			return (it->second);
	}

	T& operator[]( const Key& key ) {
		iterator it = find(key);
			if (it == end()) {
				try {
					it = insert(ft::make_pair(key, T())).first;
				}
				catch (std::exception &e) {
					throw ;
				}
			}
		return (it->second);
	}







	/* *************************************************** */
	/*                                                     */
	/*                       MODIFY                        */
	/*                                                     */
	/* *************************************************** */

	void clear() {
		_tree.clear();
	}

	ft::pair<iterator, bool> insert( const value_type& value ) {
		try {
			ft::pair<iterator, bool> ret = _tree.insert_pair(value);
			return ( ret );
		}
		catch (std::exception &e) {
			throw;
		}
		// display_tree("after insert");
	}

	iterator insert( iterator hint, const value_type& value ) {
		try {
			return (_tree.insert_hint(hint, value));
		}
		catch (std::exception &e) {
			throw;
		}
		// return (_tree.insert_hint(hint, value));
	}

	template< class InputIt >
	void insert( InputIt first, InputIt last ) {
		/* save tree */
		tree_type tmp = _tree;
		// tmp.clear();
		try {
			_tree.insert(first, last);
		}
		catch (std::exception &e) {
			_tree = tmp;
			throw;
		}
	};

	void erase( iterator pos ) {
		// std::cout << "erase(" << pos->first << ", " << pos->second << ")" << std::endl;
		try {
			_tree.erase(pos);
		}
		catch (std::exception &e) {
			throw;
		}
	}

	void erase( iterator first, iterator last ) {
		/* save tree */
		tree_type tmp = _tree;

		try {
			_tree.erase(first, last);
		}
		catch (std::exception &e) {
			_tree = tmp;
			throw;
		}
	}

	size_type erase( const Key& key ) {
		iterator it = find(key);
		// size_type ret = size();
		if (it == end())
			return (0);
		try {
			_tree.erase(it);
		}
		catch (std::exception &e) {
			throw;
		}
		// return (ret - size());
		return (1);
	}

	void swap( map& other ) {
		_tree.swap(other._tree);
	}






	/* *************************************************** */
	/*                                                     */
	/*                       LOOKUP                        */
	/*                                                     */
	/* *************************************************** */

	size_type count( const Key& key ) const {
		if (find(key) != end())
			return (1);
		return (0);
	}

	iterator find( const Key& key )
	{
		iterator it = begin();
		while (it != end())
		{
			if (it->first == key)
				return (it);
			it++;
		}
		return (end());

		// try {
		// 	iterator it = begin();
		// 	while (it != end())
		// 	{
		// 		if (it->first == key)
		// 			return it;
		// 		it++;
		// 	}
		// 	throw std::out_of_range("key not found");
		// }
		// catch (std::exception &e){
		// 	std::cout << e.what() << std::endl;
		// }
		// return end();
	};
	
	const_iterator find( const Key& key ) const {
		// std::cout << " const find()" << std::endl;
		const_iterator it = begin();
		while (it != end())
		{
			if (it->first == key)
				return (it);
			it++;
		}
		return (end());
		// try {
		// 	const_iterator it = begin();
		// 	while (it != end())
		// 	{
		// 		if (it->first == key)
		// 			return it;
		// 		it++;
		// 	}
		// 	throw std::out_of_range("key not found");
		// }
		// catch (std::exception &e){
		// 	std::cout << e.what() << std::endl;
		// }
		// return end();
	}

	ft::pair<iterator,iterator> equal_range( const Key& key ) {
		// iterator it = find(key);
		// if (it == end())
		// 	return (ft::make_pair(end(), end()));
		// return (ft::make_pair(it, ++it));
		return (_tree.equal_range(key));
	}

	ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const {
		// std::cout << " const equal rang()" << std::endl;

		// const_iterator it = find(key);
		// if (it == end())
		// 	return (ft::make_pair(end(), end()));
		// return (ft::make_pair(it, ++it));
		return (_tree.equal_range(key));
	}



	iterator lower_bound( const Key& key ) {
		iterator it = begin();
		while (it != end()) {
			if (it->first >= key)
				return it;
			it++;
		}
		return it;
	}

	const_iterator lower_bound( const Key& key ) const {
		// std::cout << " const lower_bound()" << std::endl;
		const_iterator it = begin();
		while (it != end()) {
			if (it->first >= key)
				return it;
			it++;
		}
		return it;
	}



	iterator upper_bound( const Key& key ) {
		iterator it = begin();
		while (it != end()) {
			if (it->first > key)
				return it;
			it++;
		}
		return it;
	}
	
	const_iterator upper_bound( const Key& key ) const {
		// std::cout << " const upper_bound()" << std::endl;
		const_iterator it = begin();
		while (it != end()) {
			if (it->first > key)
				return it;
			it++;
		}
		return it;
	}










	/* *************************************************** */
	/*                                                     */
	/*                      OBSERVER                       */
	/*                                                     */
	/* *************************************************** */

	key_compare key_comp() const {
		return (Compare());
	}

	value_compare value_comp() const {
		return (value_compare(key_comp()));
	}







	/* *************************************************** */
	/*                                                     */
	/*                       DISPLAY                       */
	/*                                                     */
	/* *************************************************** */
	void display_tree(std::string msg) const
	{
		_tree.display_tree(msg);
	}

	void display_tree() const
	{
		_tree.display_tree("");
		// _tree.display_tree< key_type, mapped_type >("");
	}

};




/* *************************************************** */
/*                                                     */
/*                 NON MEMBER FUNCTION                 */
/*                                                     */
/* *************************************************** */

template <class Key, class T, class Compare, class Alloc>
bool operator==(const map<Key, T, Compare, Alloc> &lhs,
								const map<Key, T, Compare, Alloc> &rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	typename map<Key, T, Compare, Alloc>::const_iterator it = lhs.begin();
	typename map<Key, T, Compare, Alloc>::const_iterator ite = lhs.end();
	typename map<Key, T, Compare, Alloc>::const_iterator it2 = rhs.begin();
	while (it != ite)
	{
		if (it->first != it2->first || it->second != it2->second)
			return (false);
		it++;
		it2++;
	}
	return (true);
}

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const map<Key, T, Compare, Alloc> &lhs,
								const map<Key, T, Compare, Alloc> &rhs)
{
	return (!(lhs == rhs));
}

template <class Key, class T, class Compare, class Alloc>
bool operator<(const map<Key, T, Compare, Alloc> &lhs,
			   const map<Key, T, Compare, Alloc> &rhs) {
	if (lhs.size() < rhs.size())
		return (true);
	if (lhs.size() > rhs.size())
		return (false);
	typename map<Key, T, Compare, Alloc>::const_iterator it = lhs.begin();
	typename map<Key, T, Compare, Alloc>::const_iterator ite = lhs.end();
	typename map<Key, T, Compare, Alloc>::const_iterator it2 = rhs.begin();
	while (it != ite)
	{
		if (it->first < it2->first)
			return (true);
		if (it->first > it2->first)
			return (false);
		if (it->second < it2->second)
			return (true);
		if (it->second > it2->second)
			return (false);
		it++;
		it2++;
	}
	return (false);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<=(const map<Key, T, Compare, Alloc> &lhs,
								const map<Key, T, Compare, Alloc> &rhs)
{
	return (!(rhs < lhs));
}

template <class Key, class T, class Compare, class Alloc>
bool operator>(const map<Key, T, Compare, Alloc> &lhs,
							 const map<Key, T, Compare, Alloc> &rhs)
{
	return (rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>=(const map<Key, T, Compare, Alloc> &lhs,
								const map<Key, T, Compare, Alloc> &rhs)
{
	return (!(lhs < rhs));
}

template <class Key, class T, class Compare, class Alloc>
void swap(map<Key, T, Compare, Alloc> &lhs,
					map<Key, T, Compare, Alloc> &rhs)
{
	lhs.swap(rhs);
}

} // namespace ft

#endif