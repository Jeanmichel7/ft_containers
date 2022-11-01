/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:54:45 by jrasser           #+#    #+#             */
/*   Updated: 2022/11/01 20:10:11 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
# define RBTREE_HPP

# include "../utils.hpp"
# include "iterator_tree.hpp"

using namespace std;

namespace ft
{

template <class T,
					class T_key,
					class T_value,
					class Compare,
					class Node = ft::Node<T>,
					class Type_Alloc = std::allocator<T>,
					class Node_Alloc = std::allocator<Node>
>
class RedBlackTree
{
public:
	typedef RedBlackTree  												self;
	typedef self&   															self_reference;
	typedef T   																	value_type;
	typedef Node 																	node_type;
	typedef Node 																	*node_pointer;
	typedef Node const 														*node_const_pointer;
	typedef Node_Alloc  													node_alloc;
	typedef size_t 																size_type;

	typedef ft::RB_iterator< Node, Compare > 							iterator;
	typedef ft::RB_const_iterator< Node, Compare>  				const_iterator;
	typedef ft::reverse_iterator< iterator > 							reverse_iterator;
	typedef ft::reverse_iterator< const_iterator >  			const_reverse_iterator;


private:
	// last_node parent = root of tree, last_node right = last node, last_node left = first node
	node_alloc      _node_alloc;
	node_pointer		_root;
	// node_pointer		_node;
	node_pointer		_last_node;
	Compare         _comp;
	size_type       _size;
	node_pointer		_nil;

public:

	/* *************************************************** */
	/*                                                     */
	/*                     CONSTRUCTOR                     */
	/*                                                     */
	/* *************************************************** */

	RedBlackTree(const node_alloc &node_alloc_init = node_alloc())
	:
		_node_alloc(node_alloc_init),
		_last_node(NULL),
		_comp(Compare()),
		_size(0)
	{
		// std::cout << "Constructor tree called" << std::endl;
		_nil = _node_alloc.allocate(1);
		_node_alloc.construct(_nil, Node());
		_root = _nil;
		_last_node = _root;
	}


	RedBlackTree(const self& x)
	:
		_node_alloc(node_alloc()),
		_comp(Compare()),
		_size(0)
	{
		// std::cout << "construcotr tree called" << std::endl;
		_nil = _node_alloc.allocate(1);
		_node_alloc.construct(_nil, Node());
		_root = _nil;
		_last_node = _root;
		insert(x.begin(), x.end());
	}


	RedBlackTree &operator=(const RedBlackTree &x) {
		_node_alloc = x._node_alloc;
		_root = x._root;
		_last_node = x._last_node;
		_comp = x._comp;
		_size = x._size;
		_nil = x._nil;
		return *this;
	}

	/* Destructor */
	~RedBlackTree()
	{
		// clear();
		// std::cout << "Destructor called" << std::endl;
		node_pointer current = _root;
		node_pointer prev;

		while (current != _nil)
		{
			if (current->_left != _nil) {
				current = current->_left;
			}
			else if (current->_right != _nil) {
				current = current->_right;
			}
			else if (current == _root)
			{
				_node_alloc.destroy(_root);
				_node_alloc.deallocate(_root, 1);
				break;
			}
			if ((current->_left == _nil && current->_right == _nil)) {
				prev = current;
				current = current->_parent;
				if (current->_left == prev)
					current->_left = _nil;
				else if (current->_right == prev)
					current->_right = _nil;
				_node_alloc.destroy(prev);
				_node_alloc.deallocate(prev, 1);
			}
		}
		_node_alloc.destroy(_nil);
		_node_alloc.deallocate(_nil, 1);
	}





	/* *************************************************** */
	/*                                                     */
	/*                     ITERATORS                       */
	/*                                                     */
	/* *************************************************** */

	iterator begin() {
		node_pointer current = _root;
		if (_root == _nil)
			return iterator(current, _last_node, _nil);
		while (current->_left != _nil)
			current = current->_left;
		return iterator(current, _last_node, _nil);
	}

	const_iterator begin() const {
		// std::cout << "const begin" << std::endl;
		node_pointer current = _root;
		if (_root == _nil)
			return const_iterator(current, _last_node, _nil);
		while (current->_left != _nil)
			current = current->_left;
		return (const_iterator(current, _last_node, _nil));
	}

	iterator end() {
		node_pointer current = _root;
		if (current == _nil)
			return iterator(current, _last_node, _nil);
		while (current->_right != _nil)
			current = current->_right;
		current = current->_right;
		return (iterator(current, _last_node, _nil));
	}

	const_iterator end() const {
		// std::cout << "const end" << std::endl;
		node_pointer current = _root;
		if (current == _nil)
			return const_iterator(current, _last_node, _nil);
		while (current->_right != _nil)
			current = current->_right;
		current = current->_right;
		return (const_iterator(current, _last_node, _nil));
	}



	reverse_iterator rbegin() {
		return reverse_iterator(end());
	}

	const_reverse_iterator rbegin() const {
		// std::cout << "const rbegin" << std::endl;
		return const_reverse_iterator(end());
	}

	reverse_iterator rend() {
		return reverse_iterator(begin());
	}

	const_reverse_iterator rend() const {
		// std::cout << "const rend" << std::endl;
		return const_reverse_iterator(begin());
	}





	/* *************************************************** */
	/*                                                     */
	/*                     CAPACITY                        */
	/*                                                     */
	/* *************************************************** */

	size_type size() const {
		return _size;
	}

	size_type max_size() const {
		return _node_alloc.max_size();
	}

	bool empty() const {
		return _size == 0;
	}





	/* *************************************************** */
	/*                                                     */
	/*                       MODIFY                        */
	/*                                                     */
	/* *************************************************** */

	ft::pair<iterator, bool> insert_pair(const value_type& val ) {

		ft::pair<iterator, bool> 	ret;
    node_pointer	x = this->_root;
    node_pointer	y = NULL;
		node_pointer	node;


		while (x != this->_nil) {
			y = x;
			if (this->_comp(val, x->_content))
				x = x->_left;
			else if (this->_comp(x->_content, val))
				x = x->_right;
			else
				return ft::pair<iterator, bool>(iterator(x, _last_node, _nil), false);
		}

		try {
			node = _node_alloc.allocate(1);
			_node_alloc.construct(node, Node(val, NULL, _nil, _nil, N_RED));
		} catch (std::exception &e) {
			throw;
			return ft::pair<iterator, bool>(iterator(x, _last_node, _nil), false);
		}

		node->_parent = y;
		if (y == NULL)
			_root = node;
		else if (node->_content < y->_content)
			y->_left = node;
		else
			y->_right = node;
		_size++;

    if (node->_parent == NULL) {
      node->_color = N_BLACK;
			_last_node = node;

      return ft::make_pair(iterator(node, _last_node, _nil), true);
    }

    if (node->_parent->_parent == NULL) {
			if (node->_parent->_left == node)
				_last_node = node->_parent;
			else if (node->_parent->_right == node)
				_last_node = _root->_right;
			return ft::make_pair(iterator(node, _last_node, _nil), true);
		}
    insert_fix(node);
		return ft::make_pair(iterator(node, _last_node, _nil), true);
	}





	iterator insert_pair_pos( node_pointer start, const value_type& val ) {
    node_pointer	x = start;
    node_pointer	y = NULL;
		node_pointer	node;

    while (x != _nil) {
      y = x;
     if (this->_comp(val, x->_content))
				x = x->_left;
			else if (this->_comp(x->_content, val))
				x = x->_right;
      else 
				return iterator(x, _last_node, _nil);
    }

		try {
			node = _node_alloc.allocate(1);
			_node_alloc.construct(node, Node(val, NULL, _nil, _nil, N_RED));
		} catch (std::exception &e) {
			throw;
			return (iterator(x, _last_node, _nil));
		}

    node->_parent = y;
    if (y == NULL)
      _root = node;
    else if (node->_content < y->_content)
      y->_left = node;
    else
      y->_right = node;
		_size++;
		
    if (node->_parent == NULL) {
      node->_color = N_BLACK;
			_last_node = node;
      return iterator(node, _last_node, _nil);
    }

    if (node->_parent->_parent == NULL) {
			_last_node = node;
			return iterator(node, _last_node, _nil);
    }

    insert_fix(node);
		// display_tree("");
		return iterator(node, _last_node, _nil);
	}
  





	iterator insert_hint( iterator hint, const value_type &to_insert ) {
		if (hint._node == _root || hint._node == _root->_left || hint._node == _root->_right)
			return insert_pair(to_insert).first;

		node_pointer x = _root;
		while (x != _nil) {
			if (this->_comp(to_insert, x->_content))
				x = x->_left;
			else if (this->_comp(x->_content, to_insert))
				x = x->_right;
			else 
				return iterator(x, _last_node, _nil);
		}

		if (hint == end()) {
			if (_comp(_last_node->_content, to_insert)) {
				// std::cout << "hint is good";
				return insert_pair_pos(_last_node, to_insert);
			}
			else {
				// std::cout << "hint not good";
				return insert_pair(to_insert).first;
			}
		} 

		node_pointer p = hint._node->_parent;
		node_pointer gp = p->_parent;
		if ( p && gp &&
			(( gp > p && _comp(p->_content, to_insert) 
				&& _comp(to_insert, gp->_content)) 
			||
			(p < gp && _comp(gp->_content, to_insert) 
				&& _comp(to_insert, p->_content)))) {
			// std::cout << "hint is good";
			return insert_pair_pos(hint._node->_parent, to_insert);
		} else {
			// std::cout << "hint not good";
			return insert_pair(to_insert).first;
		}
	}





	template< class InputIt >
	void insert( InputIt first, InputIt last ) {
		while (first != last && _size < max_size()) {
			insert_pair(*first);
			first++;
		}
	};





	void clear() {
		iterator it = begin();

		while (it != end()){
			erase(it++);
		}
		_size = 0;
		_root = _nil;
		_last_node = _nil;
	}





	void erase(iterator pos) {
		node_pointer current = _root;
    node_pointer z = _nil;
    node_pointer x, y;

    while (current != _nil) {
			if (current->_content == pos._node->_content) {
				z = current;
				break;
			}
			if (this->_comp(pos._node->_content, current->_content))
				current = current->_left;
			else if (this->_comp(current->_content, pos._node->_content))
				current = current->_right;
    }
    if (z == _nil) {
      cout << "Key not found in the tree" << endl;
      return;
    }
		// std::cout << "node : " << z->_content.first << std::endl;

    y = z;
    int y_original_color = y->_color;
    if (z->_left == _nil) {
      x = z->_right;
      rbTransplant(z, z->_right);
    } else if (z->_right == _nil) {
      x = z->_left;
      rbTransplant(z, z->_left);
    } else {
      y = minimum(z->_right);
      y_original_color = y->_color;
      x = y->_right;
      if (y->_parent == z) {
        x->_parent = y;
      } else {
        rbTransplant(y, y->_right);
        y->_right = z->_right;
        y->_right->_parent = y;
      }

      rbTransplant(z, y);
      y->_left = z->_left;
      y->_left->_parent = y;
      y->_color = z->_color;
    }

		if (z == _last_node && z != _root) {
			_last_node = _last_node->_parent;
		} else if (z == _root) {
			_root = x;
		}

		if (y_original_color == N_BLACK) {
			del_fix_tree(x);
		}


		try {
			_node_alloc.destroy(z);
			_node_alloc.deallocate(z, 1);
		} catch (std::exception &e) {
			throw;
			return;
		}
		_size--;

		//set last node
		if (_size == 0) {
			_last_node = _nil;
		}
		else {
			_last_node = _root;
			while ( _last_node->_right != _nil) {
				_last_node = _last_node->_right;
			}
		}

  }





	void erase(iterator first, iterator last) {
		iterator next = first;
		if (next != last)
			next++;
		while (first != last && next != last) {
			// std::cout << "erase(" << first->first << ")" << std::endl;
			erase(first);
			first = next;
			next++;
		}
		// std::cout << "erase last (" << first->first << ")" << std::endl;
		if (first != last)
			erase(first);
	}





	void swap(RedBlackTree &x) {
		if (&x == this)
			return ;

		std::swap(_root, x._root);
		std::swap(_nil, x._nil);
		std::swap(_size, x._size);
		std::swap(_last_node, x._last_node);

		if (_root == _nil)
			_last_node = _nil;
		if (x._root == x._nil)
			x._last_node = x._nil;
	}







	/* *************************************************** */
	/*                                                     */
	/*                       LOOKUP                        */
	/*                                                     */
	/* *************************************************** */

	iterator find(value_type to_find) {
		if (_root == NULL)
			return end();
		node_pointer current = _root;
		while (current != NULL) {
			if (current == to_find)
				return iterator(current, _nil);
			else if (current->_content < to_find)
				current = current->_right;
			else
				current = current->_left;
		}
		return end();
	}

	const_iterator find(value_type to_find) const {
		if (_root == NULL)
			return end();
		node_pointer current = _root;
		while (current != NULL) {
			if (current == to_find)
				return const_iterator(current, _nil);
			else if (current->_content < to_find)
				current = current->_right;
			else
				current = current->_left;
		}
		return end();
	}



	iterator lower_bound(const T_key &key) {
		node_pointer x = _root;
    node_pointer y = _nil;

		while (x != _nil) {
			if (!this->_comp(x->_content, key)) {
				y = x;
				x = x->_left;
			} else {
				x = x->_right;
			}
		}
		return iterator(y, _nil);
	}

	const_iterator lower_bound(const T_key &key) const {
		node_pointer x = _root;
		node_pointer y = _nil;

		while (x != _nil) {
			if (!this->_comp(x->_content, key)) {
				y = x;
				x = x->_left;
			} else {
				x = x->_right;
			}
		}
		return const_iterator(y, _nil);
	}

	iterator upper_bound(const T_key &key) {
		node_pointer x = _root;
		node_pointer y = _nil;

		while (x != _nil) {
			if (this->_comp(key, x->_content)) {
				y = x;
				x = x->_left;
			} else {
				x = x->_right;
			}
		}
		return iterator(y, _nil);
	}

	const_iterator upper_bound(const T_key &key) const {
		node_pointer x = _root;
		node_pointer y = _nil;

		while (x != _nil) {
			if (this->_comp(key, x->_content)) {
				y = x;
				x = x->_left;
			} else {
				x = x->_right;
			}
		}
		return const_iterator(y, _nil);
	}

	ft::pair<iterator, iterator> equal_range(const T_key &key) {
		return ft::make_pair(lower_bound(key), upper_bound(key));
	}

	ft::pair<const_iterator, const_iterator> equal_range(const T_key &key) const {
		return ft::make_pair(lower_bound(key), upper_bound(key));
	}






	// ft::pair<iterator, iterator> equal_range( const T_key &key ) {
	// 	node_pointer 	x = this->_root;
  //   node_pointer 	y = x;
	// 	iterator 			it1;
	// 	iterator 			it2;

	// 	std::cout << "key : " << key << std::endl;

	// 	while (x != _nil && _comp(key, x->_content)) {
	// 		y = x;
	// 		if (this->_comp(key, x->_content))
	// 			x = x->_left;
	// 		else if (this->_comp(x->_content, key))
	// 			x = x->_right;
	// 		else {
	// 			it1 = iterator(x, _last_node, _nil);
	// 			it2 = it1;
	// 			it2++;
	// 			return ft::make_pair<iterator, iterator>(it1, it2);
	// 		}
	// 	}
	// 	if (y == minimum(_root)) {
	// 		it1 = begin();
	// 		return ft::make_pair<iterator, iterator>(it1, it1);
	// 	}
	// 	if (y == _last_node) {
	// 		return ft::pair<iterator, iterator>(end(), end());
	// 	}
	// 	it1 = iterator(y, _last_node, _nil);
	// 	it1++;
	// 	return ft::make_pair<iterator, iterator>(it1, it1);
	// }

	// ft::pair<const_iterator, const_iterator> equal_range( const T_key& key ) const {
	// 	node_pointer 		x = this->_root;
	// 	node_pointer 		y = x;
	// 	node_pointer 		node_min = _root;
	// 	node_pointer 		node_min_p = _root;
	// 	const_iterator 	it1;
	// 	const_iterator 	it2;

	// 	while (x != _nil) {
	// 		y = x;
	// 		if (this->_comp(key, x->_content))
	// 			x = x->_left;
	// 		else if (this->_comp(x->_content, key))
	// 			x = x->_right;
	// 		else {
	// 			it1 = const_iterator(x, _last_node, _nil);
	// 			it2 = it1;
	// 			it2++;
	// 			return ft::make_pair<const_iterator, const_iterator>(it1, it2);
	// 		}
	// 	}

	// 	std::cout << "on passe ici" << std::endl;

	// 	if (y == _last_node) {
	// 		return ft::pair<const_iterator, const_iterator>(end(), end());
	// 	}

	// 	/* find min node */
	// 	while(node_min != _nil) {
	// 		node_min_p = node_min;
	// 		if (node_min->_content.first < key) {
	// 			node_min = node_min->_right;
	// 		} else {
	// 			node_min = node_min->_left;
	// 		}
	// 	}
	// 	if (y == node_min_p) {
	// 		return ft::make_pair< const_iterator, const_iterator>(begin(), begin());
	// 	}

	// 	it1 = const_iterator(y, _last_node, _nil);
	// 	it1++;
	// 	return ft::pair<const_iterator, const_iterator>(it1, it1);
	// }










	/* *************************************************** */
	/*                                                     */
	/*                      OPERATOR                       */
	/*                                                     */
	/* *************************************************** */

	bool operator==(const self& x) const {
		if (this->_size != x._size)
			return false;
		const_iterator it1 = this->begin();
		const_iterator it2 = x.begin();
		while (it1 != this->end()) {
			if (*it1 != *it2)
				return false;
			it1++;
			it2++;
		}
		return true;
	}

	bool operator!=(const self& x) const {
		return !(*this == x);
	}

	bool operator<(const self& x) const {
		const_iterator it1 = this->begin();
		const_iterator it2 = x.begin();
		while (it1 != this->end() && it2 != x.end()) {
			if (*it1 < *it2)
				return true;
			else if (*it2 < *it1)
				return false;
			it1++;
			it2++;
		}
		if (it1 == this->end() && it2 != x.end())
			return true;
		return false;
	}

	bool operator<=(const self& x) const {
		return (*this < x || *this == x);
	}

	bool operator>(const self& x) const {
		return !(*this <= x);
	}

	bool operator>=(const self& x) const {
		return !(*this < x);
	}





	
	/* *************************************************** */
	/*                                                     */
	/*                       UTILS                         */
	/*                                                     */
	/* *************************************************** */

	node_pointer minimum(node_pointer node) {
    while (node->_left != _nil) {
      node = node->_left;
    }
    return node;
  }

	void leftRotate(node_pointer x)
	{
		// std::cout << "left rotate : " << x->_content.first << std::endl;
		node_pointer y = x->_right;
		x->_right = y->_left;
		if (y->_left != _nil)
		{
			if (y->_left && y->_left->_parent) {
				y->_left->_parent = x;
			}
		}
		y->_parent = x->_parent;
		if (x->_parent == NULL)
		{
			this->_root = y;
		}
		else if (x == x->_parent->_left)
		{
			x->_parent->_left = y;
		}
		else
		{
			x->_parent->_right = y;
		}
		y->_left = x;
		x->_parent = y;
	}

	void rightRotate(node_pointer x)
	{
		// std::cout << "right rotate" << std::endl;
		node_pointer y = x->_left;
		x->_left = y->_right;
		if (y->_right != _nil)
		{
			if (y->_right && y->_right->_parent) {
				y->_right->_parent = x;
			}
		}
		y->_parent = x->_parent;
		if (x->_parent == NULL)
		{
			this->_root = y;
		}
		else if (x == x->_parent->_right)
		{
			x->_parent->_right = y;
		}
		else
		{
			x->_parent->_left = y;
		}
		y->_right = x;
		x->_parent = y;
	}

	void rbTransplant(node_pointer u, node_pointer v) {
    if (u->_parent == NULL) {
      _root = v;
    } else if (u == u->_parent->_left) {
      u->_parent->_left = v;
    } else {
      u->_parent->_right = v;
    }
    v->_parent = u->_parent;
  }

  void insert_fix(node_pointer current) {
    node_pointer u;
    while (current->_parent->_color == N_RED && current->_parent != NULL) {
      if (current->_parent == current->_parent->_parent->_right) {
        u = current->_parent->_parent->_left;
        if (u->_color == N_RED) {
          u->_color = N_BLACK;
          current->_parent->_color = N_BLACK;
          current->_parent->_parent->_color = N_RED;
          current = current->_parent->_parent;
        } else {
          if (current == current->_parent->_left) {
            current = current->_parent;
            rightRotate(current);
          }
          current->_parent->_color = N_BLACK;
          current->_parent->_parent->_color = N_RED;
          leftRotate(current->_parent->_parent);
        }
      } else {
        u = current->_parent->_parent->_right;
        if (u->_color == N_RED) {
          u->_color = N_BLACK;
          current->_parent->_color = N_BLACK;
          current->_parent->_parent->_color = N_RED;
          current = current->_parent->_parent;
        } else {
          if (current == current->_parent->_right) {
            current = current->_parent;
            leftRotate(current);
          }
          current->_parent->_color = N_BLACK;
          current->_parent->_parent->_color = N_RED;
          rightRotate(current->_parent->_parent);
        }
      }
      if (current == _root) {
        break;
      }
    }
    _root->_color = N_BLACK;

		// set last node
		node_pointer c = _root;
		while (c->_right != _nil)
			c = c->_right;
		_last_node = c;
  }


	// For balancing the tree after deletion
  void del_fix_tree(node_pointer current) {
		node_pointer s;
		while (current != _root && current->_color == N_BLACK) {
			if (current == current->_parent->_left) {
				s = current->_parent->_right;
				if (s->_color == N_RED) {
					s->_color = N_BLACK;
					current->_parent->_color = N_RED;
					leftRotate(current->_parent);
					s = current->_parent->_right;
				}

				if (s->_left->_color == N_BLACK && s->_right->_color == N_BLACK) {
					s->_color = N_RED;
					current = current->_parent;
				} else {
					if (s->_right->_color == N_BLACK) {
						s->_left->_color = N_BLACK;
						s->_color = N_RED;
						rightRotate(s);
						s = current->_parent->_right;
					}

					s->_color = current->_parent->_color;
					current->_parent->_color = N_BLACK;
					s->_right->_color = N_BLACK;
					leftRotate(current->_parent);
					current = _root;
				}
			} else {
				s = current->_parent->_left;
				if (s->_color == N_RED) {
					s->_color = N_BLACK;
					current->_parent->_color = N_RED;
					rightRotate(current->_parent);
					s = current->_parent->_left;
				}

				if (s->_left->_color == N_BLACK && s->_right->_color == N_BLACK) {
					s->_color = N_RED;
					current = current->_parent;
				} else {
					if (s->_left->_color == N_BLACK) {
						s->_right->_color = N_BLACK;
						s->_color = N_RED;
						leftRotate(s);
						s = current->_parent->_left;
					}
					s->_color = current->_parent->_color;
					current->_parent->_color = N_BLACK;
					s->_left->_color = N_BLACK;
					rightRotate(current->_parent);
					current = _root;
				}
			}
		}
		current->_color = N_BLACK;

		// set last node
		node_pointer c = _root;
		while (c && c->_right != _nil)
			c = c->_right;
		_last_node = c;
  }



	/* *************************************************** */
	/*                                                     */
	/*                      DISPLAY                        */
	/*                                                     */
	/* *************************************************** */

	void display_tree(std::string msg) const
	{
		std::cout << "\n**********  Display tree (" << msg << ") ************\n" << std::endl;
		node_pointer current = _root;
		node_pointer parent = NULL;

		int space_root = 60 + _size;
		if (current == NULL )
			std::cout << "Tree is NULL" << std::endl;
		else if (current == _nil)
			std::cout << "Tree is empty" << std::endl;
		else if (!empty()){
			display_tree(parent = _root, space_root, 0);
		}

		if (_last_node == _nil)
			std::cout << "\n\nlast node is nil" << std::endl;
		else if (_last_node == _root)
			std::cout << "\n\nlast node is root" << std::endl;
		else if ( _last_node == NULL)
			std::cout << "\n\nlast node is NULL" << std::endl;
		else {
			std::cout << "\n\nlast node : " << std::endl;
			display_tree(parent = _last_node, 30, 1);
		}
		std::cout << "\n**********  End display tree ************\n" << std::endl;
	}


	void display_tree(node_pointer current, int space_root, bool is_last) const
	{
		if (current == NULL)
			return;
		space_root -= 8;
		
		display_tree(current->_left, space_root, is_last);
		// std::cout << std::endl;
		for (int i = 10; i < space_root; i++)
			std::cout << " ";
		if (current->_color == N_RED)
			std::cout << RED;
		
		if (current != _nil) {
			std::cout << current->_content.first << " : " << current->_content.second;
			if (current == _last_node && is_last) {
				current->_parent->_color == N_RED ? std::cout << RED : std::cout << END ;
				std::cout << "	" << current->_parent->_content.first 
									<< " : " << current->_parent->_content.second;
			}
			std::cout << std::endl;
		} else
			std::cout << "NIL" << std::endl;
		std::cout << END ;
		display_tree(current->_right, space_root, is_last);
	}



	void display_tree_set(std::string msg) const
	{
		std::cout << "\n**********  Display tree (" << msg << ") ************\n" << std::endl;
		node_pointer current = _root;
		node_pointer parent = NULL;

		int space_root = 60 + _size;
		if (current == NULL )
			std::cout << "Tree is NULL" << std::endl;
		else if (current == _nil)
			std::cout << "Tree is empty" << std::endl;
		else if (!empty()){
			display_tree_set(parent = _root, space_root, 0);
		}

		if (_last_node == _nil)
			std::cout << "\n\nlast node is nil" << std::endl;
		else if (_last_node == _root)
			std::cout << "\n\nlast node is root" << std::endl;
		else if ( _last_node == NULL)
			std::cout << "\n\nlast node is NULL" << std::endl;
		else {
			std::cout << "\n\nlast node : " << std::endl;
			display_tree_set(parent = _last_node, 30, 1);
		}
		std::cout << "\n**********  End display tree ************\n" << std::endl;
	}


	void display_tree_set(node_pointer current, int space_root, bool is_last) const
	{
		if (current == NULL)
			return;
		space_root -= 8;
		
		display_tree_set(current->_left, space_root, is_last);
		// std::cout << std::endl;
		for (int i = 10; i < space_root; i++)
			std::cout << " ";
		if (current->_color == N_RED)
			std::cout << RED;
		
		if (current != _nil) {
			std::cout << current->_content;
			if (current == _last_node && is_last) {
				current->_parent->_color == N_RED ? std::cout << RED : std::cout << END ;
				std::cout << "	" << current->_parent->_content;
			}
			std::cout << std::endl;
		} else
			std::cout << "NIL" << std::endl;
		std::cout << END ;
		display_tree_set(current->_right, space_root, is_last);
	}
















};

} // namespace ft


#endif
