/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:54:45 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/23 22:00:39 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "utils.hpp"
#include "rbtree_iterator.hpp"
#include "map.hpp"
# include "convert.hpp"

using namespace std;

namespace ft
{

template <class T,
		  class Compare = std::less<T>,
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
	typedef ft::RB_iterator<Node, Compare> 				iterator;
	typedef ft::RB_const_iterator<Node, Compare>  const_iterator;
	typedef ft::reverse_iterator<iterator> 				reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>  const_reverse_iterator;


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
		_node_alloc.construct(_nil, Node(NULL, NULL));
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
		_node_alloc.construct(_nil, Node(NULL, NULL));
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
    node_pointer 							x = this->_root;
    node_pointer 							y = NULL;
		node_pointer 							node;

    while (x != _nil) {
      y = x;
      if (val.first < x->_content.first) {
        x = x->_left;
      } else if (x->_content.first < val.first){
        x = x->_right;
      } else {
				return ft::pair<iterator, bool>(iterator(x, _last_node, _nil), false);
			}
    }

		node = _node_alloc.allocate(1);
		_node_alloc.construct(node, Node(val, NULL, _nil, _nil, N_RED));
    node->_parent = y;
    if (y == NULL) {
      _root = node;
    } else if (node->_content < y->_content) {
      y->_left = node;
    } else {
      y->_right = node;
    }
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
    insertFix(node);
		return ft::make_pair(iterator(node, _last_node, _nil), true);
	}




	iterator insert_pair_pos( node_pointer start, const value_type& val ) {
    node_pointer 							x = start;
    node_pointer 							y = NULL;

		node_pointer node = _node_alloc.allocate(1);
		_node_alloc.construct(node, Node(val, NULL, _nil, _nil, N_RED));

    while (x != _nil) {
      y = x;
      if (node->_content < x->_content) {
        x = x->_left;
      } else if (x->_content.first < val.first){
        x = x->_right;
      } else {
				_node_alloc.destroy(node);
				_node_alloc.deallocate(node, 1);
				return iterator(x, _last_node, _nil);
			}
    }

    node->_parent = y;
    if (y == NULL) {
      _root = node;
    } else if (node->_content < y->_content) {
      y->_left = node;
    } else {
      y->_right = node;
    }
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

    insertFix(node);
		// display_tree("");
		return iterator(node, _last_node, _nil);
	}
  





	iterator insert_hint( iterator hint, const value_type &to_insert ) {
		if (hint._node == _root || hint._node == _root->_left || hint._node == _root->_right)
			return insert_pair(to_insert).first;

		node_pointer x = _root;
		while (x != _nil) {
			if (to_insert.first < x->_content.first) {
				x = x->_left;
			} else if (x->_content.first < to_insert.first) {
				x = x->_right;
			} else {
				return iterator(x, _last_node, _nil);
			}
		}

		if (hint == end()) {
			if (_comp(_last_node->_content.first, to_insert.first)) {
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
		if (hint == begin()) {
			if (_comp(to_insert.first, p->_content.first)) {
				// std::cout << "hint is good";
				return insert_pair_pos(hint._node, to_insert);
			}
			else {
				// std::cout << "hint not good";
				return insert_pair(to_insert).first;
			}
		}

		if (hint._node == p->_left) {
			if (_comp(to_insert.first, p->_content.first) && _comp(p->_content.first, gp->_content.first)) {
				// std::cout << "hint is good1";
				return insert_pair_pos(hint._node, to_insert);
			}
			else {
				// std::cout << "hint not good1";
				return insert_pair(to_insert).first;
			}
		} else {
			if (_comp(gp->_content.first, p->_content.first) && _comp(p->_content.first, to_insert.first)) {
				// std::cout << "hint is good2";
				return insert_pair_pos(hint._node, to_insert);
			}
			else {
				// std::cout << "hint not good2";
				return insert_pair(to_insert).first;
			}
		}

		// 	if ( p && gp &&
		// 	(( gp > p && _comp(p->_content.first, to_insert.first) 
		// 		&& _comp(to_insert.first, gp->_content.first)) 
		// 	||
		// 	(p < gp && _comp(gp->_content.first, to_insert.first) 
		// 		&& _comp(to_insert.first, p->_content.first)))) {
		// 	std::cout << "hint is good";
		// 	return insert_pair_pos(hint._node->_parent, to_insert);
		// } else {
		// 	std::cout << "hint not good";
		// 	return insert_pair(to_insert).first;
		// }
		
	
	}





	template< class InputIt >
	void insert( InputIt first, InputIt last ) {
		while (first != last && _size < max_size()) {
			// std::cout << "insert " << first->first << std::endl;
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
      if (current->_content.first == pos->first) {
        z = current;
				break;
      } else if (current->_content.first < pos->first) {
        current = current->_right;
      } else {
        current = current->_left;
      }
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

		_node_alloc.destroy(z);
		_node_alloc.deallocate(z, 1);
		_size--;

		//set last node
		if (_size == 0) {
			_last_node = _nil;
		}
		else {
			_last_node = _root;
			while (_last_node->_right != _nil) {
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
		if (first._node == _last_node) {
			// std::cout << "iterator node == last node" << std::endl;
		}
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
			if (current->_content.first == to_find.first)
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
			if (current->_content.first == to_find.first)
				return const_iterator(current, _nil);
			else if (current->_content < to_find)
				current = current->_right;
			else
				current = current->_left;
		}
		return end();
	}

	ft::pair<iterator,iterator> equal_range( const typename value_type::first_type& key ) {
		node_pointer x = this->_root;
    node_pointer y = x;
		iterator it1;
		iterator it2;

    while (x != _nil) {
			// std::cout << "x->first : " << x->_content.first << std::endl;
      y = x;
      if (key < x->_content.first) {
        x = x->_left;
      } else if (x->_content.first < key){
        x = x->_right;
      } else {
				it1 = iterator(x, _last_node, _nil);
				it2 = iterator(x, _last_node, _nil);
				return ft::pair<iterator,iterator>(it1, ++it2);
			}
    }
		it2 = iterator(y, _last_node, _nil);
		return ft::pair<iterator,iterator>(it2, ++it2);
	}

	ft::pair<const_iterator,const_iterator> equal_range( const typename value_type::first_type& key ) const {
		
		node_pointer 							x = this->_root;
		node_pointer 							y = x;
		const_iterator it1;
		const_iterator it2;

		while (x != _nil) {
			// std::cout << "x->first : " << x->_content.first << std::endl;
			y = x;
			if (key < x->_content.first) {
				x = x->_left;
			} else if (x->_content.first < key){
				x = x->_right;
			} else {
				it1 = const_iterator(x, _last_node, _nil);
				it2 = const_iterator(x, _last_node, _nil);
				return ft::pair<const_iterator,const_iterator>(it1, ++it2);
			}
		}
		it1 = const_iterator(y, _last_node, _nil);
		it2 = const_iterator(y, _last_node, _nil);
		return ft::pair<const_iterator,const_iterator>(it2, ++it2);
	}










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

  void insertFix(node_pointer current) {
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


	void display_tree(std::string msg)
	{
		std::cout << "\n**********  Display tree (" << msg << ") ************\n" << std::endl;
		// std::cout << "len tree : " << _size << std::endl << std::endl;
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

			// std::cout << RED "\n\nlast node" END << std::endl
			// << "content	:" << _last_node->_content.first << std::endl
			// << "color	:" << _last_node->_color << std::endl
			// << "parent	:"<< (_last_node->_parent != NULL ? _last_node->_parent->_content.first : "") << std::endl
			// << "left	:" << (_last_node->_left == _nil ? "NIL" : _last_node->_left->_content.first) << std::endl
			// << "right	:" << (_last_node->_right == _nil ? "NIL" : _last_node->_right->_content.first) << std::endl;
		}
		std::cout << "\n**********  End display tree ************\n" << std::endl;
	}


	void display_tree(node_pointer current, int space_root, bool is_last)
	{
		// bool is_not_nil = 0;
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
};

} // namespace ft


#endif
