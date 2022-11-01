/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:41:48 by jrasser           #+#    #+#             */
/*   Updated: 2022/11/01 23:10:50 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SET_HPP__
# define __SET_HPP__

#include "reverse_iterator.hpp"
#include "utils/rbtree.hpp"
#include "utils.hpp"


namespace ft
{

template <class Key,
          class Compare = std::less<Key>, 
          class Alloc = std::allocator<Key> 
>
class set
{
public:
  typedef Key         key_type;
  typedef Key         value_type;
  typedef Compare     key_compare;
  typedef Alloc       allocator_type;

  typedef typename Alloc::reference         reference;
  typedef typename Alloc::const_reference   const_reference;
  typedef typename Alloc::pointer           pointer;
  typedef typename Alloc::const_pointer     const_pointer;



	class value_compare
	{
		typedef bool 					result_type;
		typedef value_type 		first_argument_type;
		typedef value_type 		second_argument_type;

	protected:
		Compare _comp;

	public:
		value_compare() : _comp() {}
		value_compare( Compare c ) : _comp(c) {}
		bool operator() (const value_type& x, const value_type& y) const{
			return (this->_comp(x, y));
		}
	};

  typedef typename ft::RedBlackTree<key_type, key_type, key_type, value_compare > tree_type;

  typedef typename tree_type::iterator                iterator;
  typedef typename tree_type::const_iterator          const_iterator;
  typedef typename tree_type::reverse_iterator        reverse_iterator;
  typedef typename tree_type::const_reverse_iterator  const_reverse_iterator;
  typedef typename tree_type::size_type               size_type;	


private:
	allocator_type		_alloc;
	value_compare			_comp;
	tree_type					_tree;



public:
	/* *************************************************** */
	/*                                                     */
	/*                     CONSTRUCTOR                     */
	/*                                                     */
	/* *************************************************** */

  explicit set (const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type())
  : 
    _alloc(alloc),
    _comp(comp),
    _tree()
  {
    return;
  }

  template <class InputIterator>
  set (InputIterator first, InputIterator last,
       const key_compare& comp = key_compare(),
       const allocator_type& alloc = allocator_type())
      //  typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
  :
    _alloc(alloc),
    _comp(comp),
    _tree()
  {
    _tree.insert(first, last);
  }

  set (const set& other) 
  : 
    _alloc(other._alloc),
    _comp(other._comp),
    _tree(other._tree)
  {
    return;
  }

  ~set()
  {
    return;
  }

  set &operator=(const set &other)
  {
    if (this != &other)
    {
      clear();
      this->_alloc = other._alloc;
      this->_comp = other._comp;
      _tree.insert(other.begin(), other.end());
    }
    return (*this);
  }




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

	void swap( set& other ) {
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
			if (*it == key)
				return (it);
			it++;
		}
		return (end());
	};
	
	const_iterator find( const Key& key ) const {
		// std::cout << " const find()" << std::endl;
		const_iterator it = begin();
		while (it != end())
		{
			if (*it == key)
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
		// iterator it = begin();
		// while (it != end()) {
		// 	if (it->first >= key)
		// 		return it;
		// 	it++;
		// }
		// return it;
	}

	const_iterator lower_bound( const Key& key ) const {
		return (_tree.lower_bound(key));
		// std::cout << " const lower_bound()" << std::endl;
		// const_iterator it = begin();
		// while (it != end()) {
		// 	if (it->first >= key)
		// 		return it;
		// 	it++;
		// }
		// return it;
	}



	iterator upper_bound( const Key& key ) {
		return (_tree.upper_bound(key));
	// 	iterator it = begin();
	// 	while (it != end()) {
	// 		if (it->first > key)
	// 			return it;
	// 		it++;
	// 	}
	// 	return it;
	}
	
	const_iterator upper_bound( const Key& key ) const {
		return (_tree.upper_bound(key));
		// // std::cout << " const upper_bound()" << std::endl;
		// const_iterator it = begin();
		// while (it != end()) {
		// 	if (it->first > key)
		// 		return it;
		// 	it++;
		// }
		// return it;
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
		_tree.display_tree_set(msg);
	}

	void display_tree() const
	{
		_tree.display_tree_set("");
		// _tree.display_tree< key_type, mapped_type >("");
	}
};





/* *************************************************** */
/*                                                     */
/*                 NON MEMBER FUNCTION                 */
/*                                                     */
/* *************************************************** */


template< class Key, class Compare, class Alloc >
bool operator==( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs ) {
	if (lhs.size() != rhs.size())
		return (false);
	typename set<Key,Compare,Alloc>::const_iterator it = lhs.begin();
	typename set<Key,Compare,Alloc>::const_iterator ite = lhs.end();
	typename set<Key,Compare,Alloc>::const_iterator it2 = rhs.begin();
	while (it != ite) {
		if (*it != *it2)
			return (false);
		it++;
		it2++;
	}
	return (true);
}

template< class Key, class Compare, class Alloc >
bool operator!=( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs ) {
	return (!(lhs == rhs));
}

template< class Key, class Compare, class Alloc >
bool operator<( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs ) {
	typename set<Key,Compare,Alloc>::const_iterator it = lhs.begin();
	typename set<Key,Compare,Alloc>::const_iterator ite = lhs.end();
	typename set<Key,Compare,Alloc>::const_iterator it2 = rhs.begin();
	while (it != ite)
	{
		if (*it < *it2)
			return (true);
		if (*it > *it2)
			return (false);
		if (*it < *it2)
			return (true);
		if (*it > *it2)
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

template< class Key, class Compare, class Alloc >
bool operator<=( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs ) {
	return ((lhs < rhs) || (lhs == rhs));
}

template< class Key, class Compare, class Alloc >
bool operator>( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs ) {
	return (!(lhs <= rhs));
}

template< class Key, class Compare, class Alloc >
bool operator>=( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs ) {
	return (!(lhs < rhs));
}

template< class Key, class Compare, class Alloc >
void swap( set<Key,Compare,Alloc>& x, set<Key,Compare,Alloc>& y ) {
	x.swap(y);
}





} // namespace ft

#endif