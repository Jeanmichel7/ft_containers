/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:14:05 by jrasser           #+#    #+#             */
/*   Updated: 2022/11/04 13:26:02 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_HPP__
# define __MAP_HPP__

#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "utils/rbtree.hpp"
#include "utils.hpp"

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
	typedef typename Allocator::const_pointer const		const_pointer;


	class value_compare
	{
		typedef bool 					result_type;
		typedef value_type 		first_argument_type;
		typedef value_type 		second_argument_type;

	protected:
		Compare _comp;

	public:

		// value_compare() : _comp() {}
		value_compare( Compare c ) : _comp(c) {}

		bool operator() (const value_type& x, const value_type& y) const {
			return (this->_comp(x.first, y.first));
		}

		// bool operator() (const key_type& x, const value_type& y) const {
		// 	return (this->_comp(x, y.first));
		// }

		// bool operator() (const value_type& x, const key_type& y) const {
		// 	return (this->_comp(x.first, y));
		// }

		// bool operator() (const key_type& x, const key_type& y) const {
		// 	return (this->_comp(x, y));
		// }
	};

	
	typedef typename ft::RedBlackTree<value_type, key_type, mapped_type, Compare>	tree_type;

	typedef typename tree_type::iterator 									iterator;
	typedef typename tree_type::const_iterator						const_iterator;
	typedef typename tree_type::reverse_iterator					reverse_iterator;
	typedef typename tree_type::const_reverse_iterator		const_reverse_iterator;


private:
	allocator_type		_alloc;
	Compare						_comp;
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
	};

	template <class InputIt>
	map(InputIt first, InputIt last,
		const Compare &comp = Compare(),
		const Allocator &alloc = Allocator()) 
	: _alloc(alloc), _comp(comp), _tree()
	{
		_tree.insert(first, last);
	};

	map(const map &other)
	: _alloc(other._alloc), _comp(other._comp), _tree(other._tree)
	{
	};

	~map() {
	};

	map& operator=( const map& other )
	{
		if (this != &other) {
			clear();
			this->_alloc = other._alloc;
			this->_comp = other._comp;
			_tree.insert(other.begin(), other.end());
		}
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
		return (_tree.begin());
	}

	iterator end() {
		return (_tree.end());
	}

	const_iterator end() const {
		return (_tree.end());
	}

	reverse_iterator rbegin() {
		return (_tree.rbegin());
	}

	const_reverse_iterator rbegin() const {
		return (_tree.rbegin());
	}

	reverse_iterator rend() {
		return (_tree.rend());
	}

	const_reverse_iterator rend() const {
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
				throw std::out_of_range("map::at:  key not found");
			return (it->second);
	}

	const T& at( const Key& key ) const {
			const_iterator it = find(key);
			if (it == end())
				throw std::out_of_range("map::at:  key not found");
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
			return ( _tree.insert_pair(value) );
		}
		catch (std::exception &e) {
			throw;
		}
	}

	iterator insert( iterator hint, const value_type& value ) {
		try {
			return (_tree.insert_hint(hint, value));
		}
		catch (std::exception &e) {
			throw;
		}
	}

	template< class InputIt >
	void insert( InputIt first, InputIt last ) {
		tree_type tmp = _tree;
		try {
			_tree.insert(first, last);
		}
		catch (std::exception &e) {
			_tree = tmp;
			throw;
		}
	};

	void erase( iterator pos ) {
		try {
			_tree.erase(pos);
		}
		catch (std::exception &e) {
			throw;
		}
	}

	void erase( iterator first, iterator last ) {
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
		if (it == end())
			return (0);
		try {
			_tree.erase(it);
		}
		catch (std::exception &e) {
			throw;
		}
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
	};
	
	const_iterator find( const Key& key ) const {
		const_iterator it = begin();
		while (it != end())
		{
			if (it->first == key)
				return (it);
			it++;
		}
		return (end());
	}

	ft::pair<iterator,iterator> equal_range( const Key& key ) {
		return (_tree.equal_range(key));
	}

	ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const {
		return (_tree.equal_range(key));
	}


	iterator lower_bound( const Key& key ) {
		return (_tree.lower_bound(key));
	}

	const_iterator lower_bound( const Key& key ) const {
		return (_tree.lower_bound(key));
	}


	iterator upper_bound( const Key& key ) {
		return (_tree.upper_bound(key));
	}
	
	const_iterator upper_bound( const Key& key ) const {
		return (_tree.upper_bound(key));
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
	if (lhs.size() < rhs.size())
		return (true);
	if (lhs.size() > rhs.size())
		return (false);
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