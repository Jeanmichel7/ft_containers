/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:54:45 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/20 19:09:23 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "utils.hpp"
#include "rbtree_iterator.hpp"
#include "map.hpp"

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
		// _node(NULL),
		_last_node(NULL),
		_comp(Compare()),
		_size(0)
	{
		_nil = _node_alloc.allocate(1);
		_node_alloc.construct(_nil, Node(NULL, NULL));
		_root = _nil;
		_last_node = _root;

		// std::cout << "Constructor tree called" << std::endl;
		// std::cout << "Root: " << _root->_content.first << std::endl;
	}


	RedBlackTree(const self& x)
	:
		_node_alloc(node_alloc()),
		// _node(NULL),
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
		// _node = x._node;
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
		// clear();

		node_pointer current = _root;
		node_pointer prev;

		// std::cout << "current : " << current->_content.first << std::endl;
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
	/*                     ELEMENT ACCESS                  */
	/*                                                     */
	/* *************************************************** */








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
		std::cout << "const rbegin" << std::endl;
		return const_reverse_iterator(end());
	}

	reverse_iterator rend() {
		return reverse_iterator(begin());
	}
	

	const_reverse_iterator rend() const {
		std::cout << "const rend" << std::endl;
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

	// node_pointer insert_node(node_pointer y, const value_type& val) {
	// 	// if (_size == 0) {
	// 	// 	_nil = _node_alloc.allocate(1);
	// 	// 	_node_alloc.construct(_nil, Node(NULL, NULL));
	// 	// 	_root = _nil;
	// 	// 	_last_node = _root;
	// 	// }

	// 	std::cout << "insert_node : " << val.first << std::endl;

	// 	node_pointer new_node = _node_alloc.allocate(1);
	// 	_node_alloc.construct(new_node, Node(val, y, _nil, _nil, N_RED));
	// 	if (_size == 0) {
	// 		_root = new_node;
	// 		_root->_color = N_BLACK;
	// 		_size++;
	// 		return new_node;
	// 	}
	// 	else if (val.first < y->_content.first) {
	// 		std::cout << "insert_node : left" << std::endl;
	// 		y->_left = new_node;
	// 	}
	// 	else {
	// 		std::cout << "insert_node : right" << std::endl;
	// 		y->_right = new_node;
	// 	}
	// 	_size ++;


  //  if (new_node->_parent == NULL) {
  //     new_node->_color = 0;
	// 		node_pointer c = _root;
	// 		while (c && c->_right != _nil)
	// 			c = c->_right;
	// 		_last_node = c;
  //     return new_node;
  //   }

  //   if (new_node->_parent->_parent == NULL) {
	// 		node_pointer c = _root;
	// 		while (c && c->_right != _nil)
	// 			c = c->_right;
	// 		_last_node = c;
  //     return new_node;
  //   }

  //   insertFix(new_node);



	// 	// display_tree(val.first);

	// 	// std::cout << "test new node : " << new_node->_content.first << std::endl;
	// 	// std::cout << "test new node parent : " << new_node->_parent->_content.first << std::endl;

  //  	// if (new_node->_parent == _root) {
  //   //   new_node->_color = 0; 
  //   // }
	// 	// // if (new_node != _root && new_node->_parent->_color == N_RED)
	// 	// else 
  //   // 	insertFix(new_node);
	// 	// _size++;

	// 	// set last node
	// 	node_pointer c = _root;
	// 	while (c && c->_right != _nil)
	// 		c = c->_right;
	// 	_last_node = c;

	// 	return new_node;
	// }






	// ft::pair<iterator, bool> insert_pair(const value_type& val) {
	// 	node_pointer y = _root;
	// 	node_pointer x = _root;

	// 	std::cout << "insert pair " << val.first << ":" << val.second << std::endl;

	// 	if (_size == 0) {
	// 		_nil = _node_alloc.allocate(1);
	// 		_node_alloc.construct(_nil, Node(NULL, NULL));
	// 		_root = _nil;
	// 		_last_node = _root;
	// 		return ft::make_pair(iterator(insert_node(y, val), _last_node, _nil), true);
	// 	}

	// 	while (x != _nil) {
	// 		y = x;
	// 		if (val.first < x->_content.first) {
	// 			x = x->_left;
	// 		} else if (x->_content.first < val.first) {
	// 			x = x->_right;
	// 		} else {
	// 			return ft::make_pair(iterator(x, _last_node, _nil), false);
	// 		}
	// 	}
	// 	return ft::make_pair(iterator(insert_node(y, val), _last_node, _nil), true);
	// }






	ft::pair<iterator, bool> insert_pair(const value_type& val ) {

		ft::pair<iterator, bool> 	ret;
    node_pointer 							x = this->_root;
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
				return ft::make_pair(iterator(x, _last_node, _nil), false);
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
      node->_color = 0;
			ret = ft::make_pair(iterator(node, _last_node, _nil), true);
			_last_node = node;
      return ret;
    }

    if (node->_parent->_parent == NULL) {
			ret = ft::make_pair(iterator(node, _last_node, _nil), true);
			_last_node = node;
			return ret;
    }

    insertFix(node);
		// display_tree("");

		ret = ft::make_pair(iterator(node, _last_node, _nil), true);
		return ret;
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
      node->_color = 0;
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
		
		// si to_insert est compri entre parent et grand parent
		if ( p && gp &&
			(( gp > p && _comp(p->_content.first, to_insert.first) 
				&& _comp(to_insert.first, gp->_content.first)) 
			||
			(p < gp && _comp(gp->_content.first, to_insert.first) 
				&& _comp(to_insert.first, p->_content.first)))) {
			std::cout << "hint is good";
			// node_pointer current = insert_node(hint._node, to_insert);
			// return iterator(insert_node(hint._node, to_insert), _last_node);
			return insert_pair_pos(hint._node, to_insert);
		} else {
			std::cout << "hint not good";
			return insert_pair(to_insert).first;
		}
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

		// if (_root == _nil) {
		// 	_last_node = _nil;
		// 	_node_alloc.destroy(_nil);
		// 	_node_alloc.deallocate(_nil, 1);
		// }

  }
/*
	void erase(iterator position) {
		// display_tree("---------------------befor delete---------------------");
		node_pointer current = _root;

		while(current != _nil) {
			if (_comp(position->first, current->_content.first))
				current = current->_left;
			else if (_comp(current->_content.first, position->first))
				current = current->_right;
			else
				break;
		}

		if (current == _nil) {
			std::cout << "element not found" << std::endl;
			return;
		}
		// std::cout << "position to del : " << current->_content.first << std::endl;
		// std::cout << "current->left: " << current->_left->_content.first << std::endl;

		int y_original_color = current->_color;

		if (current->_left == _nil && current->_right == _nil) {
			// std::cout << "\nno child" << std::endl;
			if (current->_parent == NULL) {
				_root = _nil;
			}
			else if (current->_parent->_left == current)
				current->_parent->_left = _nil;
			else
				current->_parent->_right = _nil;
			// display_tree("befor fix tree");

			if (y_original_color == 0 && current->_parent != NULL)
				del_fix_tree(current->_parent);
			// del_fix_tree(current->_parent);

			// node_pointer c = _root;
			// while (c->_right != _nil)
			// 	c = c->_right;
			// _last_node = c;
			// del_fix_tree(current);


			// std::cout << "end of no child" << std::endl;
		}

		else if (current->_left == _nil || current->_right == _nil) {
			// std::cout << "\none child" << std::endl;
			node_pointer child = current->_left == _nil ? current->_right : current->_left;
			if (current->_parent == NULL) {
				_root = child;
				child->_parent = NULL;
			}
			else if (current->_parent->_left == current) {
				current->_parent->_left = child;
				child->_parent = current->_parent;
			}
			else {
				current->_parent->_right = child;
				child->_parent = current->_parent;
			}
			// display_tree("befor fix tree");

			if (y_original_color == 0)
				del_fix_tree(child);
			// std::cout << "end of one child" << std::endl;

			
		}

		else {
			// std::cout << "\ntwo child" << std::endl;
			
			node_pointer successor = current->_right;
			while (successor->_left != _nil)
				successor = successor->_left;

			if (successor->_parent != current) {
				successor->_parent->_left = successor->_right;
				if (successor->_right != _nil)
					successor->_right->_parent = successor->_parent;
				successor->_right = current->_right;
				current->_right->_parent = successor;
			}

			if (current->_parent == NULL) {
				_root = successor;
				_last_node = _root;
			}
			else if (current->_parent->_left == current)
				current->_parent->_left = successor;
			else
				current->_parent->_right = successor;
			successor->_parent = current->_parent;
			successor->_left = current->_left;
			current->_left->_parent = successor;
			// display_tree("befor fix tree");

			if (y_original_color == 0)
				del_fix_tree(successor);
		}

		// display_tree("after fix tree");

		_node_alloc.destroy(current);
		_node_alloc.deallocate(current, 1);
		_size--;

		if (_root == _nil) {
			_last_node = _nil;
			_node_alloc.destroy(_nil);
			_node_alloc.deallocate(_nil, 1);
		}
		else {
			node_pointer c = _root;
			while (c->_right != _nil)
				c = c->_right;
			_last_node = c;
		}
	};
*/



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


/*
	node_alloc      _node_alloc;
	node_pointer		_root;
	node_pointer		_node;
	node_pointer		_last_node;
	Compare         _comp;
	size_type       _size;
	node_pointer		_nil;
*/



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


	iterator find(value_type to_find)
	{
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

	const_iterator find(value_type to_find) const;




	/* *************************************************** */
	/*                                                     */
	/*                      OBSERVER                       */
	/*                                                     */
	/* *************************************************** */




	




	/* *************************************************** */
	/*                                                     */
	/*                      OPERATOR                       */
	/*                                                     */
	/* *************************************************** */




	/* Comparison operators */
	bool operator==(const self& x) const;
	bool operator!=(const self& x) const;

	bool operator<(const self& x) const;
	bool operator<=(const self& x) const;

	bool operator>(const self& x) const;
	bool operator>=(const self& x) const;
	/* Allocator */

	// allocator_type get_allocator() const
	// {
	// 	return (_node_alloc);
	// }





	
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
		if (x->_parent == u_nullptr)
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
		if (x->_parent == u_nullptr)
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

  void insertFix(node_pointer k) {
		// std::cout << "fix node : " << k->_content.first << std::endl;
		// display_tree("fix");


    node_pointer u;
    while (k->_parent->_color == 1 && k->_parent != NULL) {
      if (k->_parent == k->_parent->_parent->_right) {
        u = k->_parent->_parent->_left;
        if (u->_color == 1) {
          u->_color = 0;
          k->_parent->_color = 0;
          k->_parent->_parent->_color = 1;
          k = k->_parent->_parent;
        } else {
          if (k == k->_parent->_left) {
            k = k->_parent;
            rightRotate(k);
          }
          k->_parent->_color = 0;
          k->_parent->_parent->_color = 1;
          leftRotate(k->_parent->_parent);
        }
      } else {
        u = k->_parent->_parent->_right;


        if (u->_color == 1) {
          u->_color = 0;
          k->_parent->_color = 0;
          k->_parent->_parent->_color = 1;
          k = k->_parent->_parent;
        } else {
          if (k == k->_parent->_right) {
            k = k->_parent;
            leftRotate(k);
          }
          k->_parent->_color = 0;
          k->_parent->_parent->_color = 1;
          rightRotate(k->_parent->_parent);
        }
      }
      if (k == _root) {
        break;
      }
    }
    _root->_color = 0;

		// set last node
		node_pointer c = _root;
		while (c->_right != _nil)
			c = c->_right;
		_last_node = c;
  }


	// For balancing the tree after deletion
  void del_fix_tree(node_pointer x) {
		// std::cout << "fix node : "<< std::endl
		// 	<< "content	:" << x->_content.first << std::endl
		// 	<< "color	:" <<   x->_color << std::endl
		// 	<< "parent	:"<< (x->_parent != NULL ? x->_parent->_content.first : "") << std::endl;
		// 	// << "left	:" << ( x->_left && x->_left == _nil ? "NIL" : x->_left->_content.first) << std::endl
		// 	// << "right	:" << ( x->_right == _nil ? "NIL" : x->_right->_content.first) << std::endl;

		node_pointer s;
		while (x != _root && x->_color == 0) {
			if (x == x->_parent->_left) {
				s = x->_parent->_right;
				if (s->_color == 1) {
					s->_color = 0;
					x->_parent->_color = 1;
					leftRotate(x->_parent);
					s = x->_parent->_right;
				}

				if (s->_left->_color == 0 && s->_right->_color == 0) {
					s->_color = 1;
					x = x->_parent;
				} else {
					if (s->_right->_color == 0) {
						s->_left->_color = 0;
						s->_color = 1;
						rightRotate(s);
						s = x->_parent->_right;
					}

					s->_color = x->_parent->_color;
					x->_parent->_color = 0;
					s->_right->_color = 0;
					leftRotate(x->_parent);
					x = _root;
				}
			} else {
				s = x->_parent->_left;
				if (s->_color == 1) {
					s->_color = 0;
					x->_parent->_color = 1;
					rightRotate(x->_parent);
					s = x->_parent->_left;
				}

				if (s->_right->_color == 0 && s->_right->_color == 0) {
					s->_color = 1;
					x = x->_parent;
				} else {
					if (s->_left->_color == 0) {
						s->_right->_color = 0;
						s->_color = 1;
						leftRotate(s);
						s = x->_parent->_left;
					}
					s->_color = x->_parent->_color;
					x->_parent->_color = 0;
					s->_left->_color = 0;
					rightRotate(x->_parent);
					x = _root;
				}
			}
		}
		x->_color = 0;

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
		int level = 0;
		int node_in_line = 0;

		std::cout << "current : " << current->_content.first << std::endl;


		if (current == NULL )
			std::cout << "Tree is NULL" << std::endl;
		else if (current == _nil)
			std::cout << "Tree is empty" << std::endl;
		else if (!empty()){
			display_tree(parent = _root, space_root, level, node_in_line);
		}

		if (_last_node == _nil)
			std::cout << RED "\n\nlast node is nil" END << std::endl;
		if (_last_node == _root)
			std::cout << RED "\n\nlast node is root" END << std::endl;
		else if ( _last_node == NULL)
			std::cout << RED "\n\nlast node is NULL" END << std::endl;
		else {
			std::cout << RED "\n\nlast node" END << std::endl
			<< "content	:" << _last_node->_content.first << std::endl
			<< "color	:" << _last_node->_color << std::endl
			<< "parent	:"<< (_last_node->_parent != NULL ? _last_node->_parent->_content.first : "") << std::endl
			<< "left	:" << (_last_node->_left == _nil ? "NIL" : _last_node->_left->_content.first) << std::endl
			<< "right	:" << (_last_node->_right == _nil ? "NIL" : _last_node->_right->_content.first) << std::endl;
		}
		std::cout << "\n**********  End display tree ************\n" << std::endl;
	}


	void display_tree(node_pointer parent, int space_root, int level, int node_in_line)
	{

		if (parent == NULL)
			return;
		space_root -= 8;
		
		display_tree(parent->_left, space_root, level + 1, node_in_line);
		// std::cout << std::endl;
		for (int i = 10; i < space_root; i++)
			std::cout << " ";
		if (parent->_color == N_RED)
			std::cout << RED;
		// std::cout << parent->_content.first << " : " << parent->_content.second << " c: " << parent->_color << std::endl;
		if (parent->_content.second != 0) {
			std::cout << parent->_content.first << " : " << parent->_content.second << std::endl;
		} else
			std::cout << "NIL" << std::endl;
		std::cout << END ;

		display_tree(parent->_right, space_root, level + 1, node_in_line);
	}
	/*
	{
		if (parent == NULL)
			return;
		
		// int display_r = 0;
		// int display_l = 0;

		int space_between = 3;

		// if (parent == _root) {
			for(int i = 0; i < space_root; i++) std::cout << " ";
			std::cout <<parent->_content.first << std::endl;
			for(int i = 0; i < space_root - 2 ; i++) std::cout << " ";
			std::cout << "/" ;
			for(int i = 0; i < space_between ; i++) std::cout << " ";
			std::cout << "\\";
			if (node_in_line == pow(level, 2)) 
				std::cout << std::endl;
		// }

		display_tree(parent->_left, space_root - 3, level + 1, node_in_line++);
		display_tree(parent->_right, space_root + 3, level + 1, node_in_line++);

		if (parent->_left != NULL) {
			// for(int i = 0; i < space_root - (level * 3) - 1; i++) std::cout << " ";
			// std::cout << parent->_left->_content.first;
			// for(int i = 0; i < space_between + (3 * level); i++) std::cout << " ";
			node_in_line++;

			// display_l = 1;
		}
		else
			for(int i = 0; i < space_root + (level * 3); i++) std::cout << " ";


		if (parent->_right != NULL) {
			// std::cout <<parent->_right->_content.first;
			node_in_line++;
			
			// display_r = 1;
		}
		else {
			// if (node_in_line == pow(level, 2))
			std::cout << std::endl;
			level++;
		}
			
	}
	*/
};

} // namespace ft


#endif
