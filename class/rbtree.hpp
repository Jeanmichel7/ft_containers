/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:54:45 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/06 01:52:57 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "utils.hpp"
#include "rbtree_iterator.hpp"

using namespace std;

namespace ft
{

// struct Node
// {
// 	int     _content;
// 	Node 	*_parent;
// 	Node 	*_left;
// 	Node 	*_right;
// 	int 	_color;
// };


template <class T,
		  class Compare = std::less<T>,
		  class Node = ft::Node<T>,
		  class Type_Alloc = std::allocator<T>,
		  class Node_Alloc = std::allocator<Node>
>
class RedBlackTree
{
public:

	/* Self type */
	typedef RedBlackTree  							self;

	/* A reference to the self type */
	typedef self&   								self_reference;
	
	/* The first template argument */
	typedef T   									value_type;

	/* Stored Node type */
	typedef Node 									node_type;

	/* Pointer to stored node */
	typedef Node 									*node_pointer;

	typedef Node const 								*node_const_pointer;
	
	/* Node allocator */
	typedef Node_Alloc  							node_alloc;

	/* Size_t */
	typedef size_t 									size_type;

	typedef ft::RB_iterator<Node, Compare> 			iterator;
	typedef ft::RB_const_iterator<Node, Compare> 	const_iterator;
	typedef ft::my_reverse_iterator<iterator> 		reverse_iterator;
	typedef ft::my_reverse_iterator<const_iterator> const_reverse_iterator;

private:
	// last_node parent = root of tree, last_node right = last node, last_node left = first node
	node_alloc      _node_alloc;
	node_pointer	_root;
	// node_pointer    _node;
	node_pointer	_last_node;
	Compare         _comp;
	size_type       _size;

	node_pointer	TNULL;



public:

	/* *************************************************** */
	/*                                                     */
	/*                     CONSTRUCTOR                     */
	/*                                                     */
	/* *************************************************** */

	RedBlackTree(const node_alloc &node_alloc_init = node_alloc())
	:
		_node_alloc(node_alloc_init),
		_root(NULL),
		// _node(NULL),
		_last_node(NULL),
		_size(0),
		TNULL(NULL)
	{
		// _node = _node_alloc.allocate(1);
		// _node_alloc.construct(_node, Node());
	}

	/* Copy constructor */
	// RedBlackTree(const self& x) : _node_a(_node_alloc.allocate(1))
	// {
	// 	_node_alloc.construct(_node_alloc, Node());
	// 	_node->_content = x._node->_content;
	// 	_node->_parent = x._node->_parent;
	// 	_node->_left = x._node->_left;
	// 	_node->_right = x._node->right;
	// 	_node->_color = x._node->_color;
	// 	// *this = x;
	// }


	RedBlackTree &operator=(const RedBlackTree &x);

	/* Destructor */
	~RedBlackTree()
	{
		node_pointer current = _root;
		node_pointer prev = NULL;

		while (current != NULL)
		{
			if (current->_left) {
				current = current->_left;
			}
			else if (current->_right) {
				current = current->_right;
			}
			else if (current == _root)
			{
				_node_alloc.destroy(_root);
				_node_alloc.deallocate(_root, 1);

				// _node_alloc.destroy(_last_node);
				// _node_alloc.deallocate(_last_node, 1);
				return;
			}
			if ((current->_left == NULL && current->_right == NULL)) {
				prev = current;
				current = current->_parent;
				if (current->_left == prev)
					current->_left = NULL;
				else if (current->_right == prev)
					current->_right = NULL;
				_node_alloc.destroy(prev);
				_node_alloc.deallocate(prev, 1);
			}
		}
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
		while (current->_left != NULL)
			current = current->_left;
		return iterator(current, _last_node);
	}

	iterator end() {
		node_pointer current = _root;
		while (current->_right != NULL)
			current = current->_right;
		_last_node = current;
		return iterator(TNULL, _last_node);
	}
	
	const_iterator begin() const {
		node_pointer current = _root;
		while (current->_left != NULL)
			current = current->_left;
		return const_iterator(current, _last_node);
	}

	const_iterator end() const {
		node_pointer current = _root;
		while (current->_right != NULL)
			current = current->_right;
		_last_node = current;
		return const_iterator(TNULL, _last_node);
	}

	reverse_iterator rbegin() {
		return reverse_iterator(end());
	}

	reverse_iterator rend() {
		return reverse_iterator(begin());
	}
	
	const_reverse_iterator rbegin() const {
		return const_reverse_iterator(end());
	}

	const_reverse_iterator rend() const {
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

	bool empty() const;







	/* *************************************************** */
	/*                                                     */
	/*                       MODIFY                        */
	/*                                                     */
	/* *************************************************** */

	node_pointer insert_node(node_pointer current, const value_type &val)
	{
		node_pointer parent = NULL;

		while (current != NULL)
		{
			parent = current;
			if (_comp(val.first, current->_content.first))
				current = current->_left;
			else if (_comp(current->_content.first, val.first))
				current = current->_right;
			else
				return current;
		}

		current = _node_alloc.allocate(1);
		_node_alloc.construct(current, Node(val));
		current->_parent = parent;
		
		if (_comp(val.first, parent->_content.first))
			parent->_left = current;
		else
			parent->_right = current;

		_size++;

		// display_tree("insert before fixed");
		fix_tree(current);
		// display_tree("insert after fixed");

		return current;
	}


	ft::pair<iterator, bool> insert_pair(const value_type& val)
	{
		if (_size == 0)
		{
			node_pointer new_node = _node_alloc.allocate(1);
			_node_alloc.construct(new_node, Node(val, N_BLACK));
			_root = new_node;
			_size++;
			_last_node = _root;
			return ft::make_pair(iterator(_root, _last_node), true);
		}

		// node_pointer current = insert_node(_root, val);
		return ft::make_pair(iterator(insert_node(_root, val), _last_node), true);
	}


	iterator insert( iterator hint, const value_type &to_insert ) {
		

		if (hint._node == _root || hint._node == _root->_left || hint._node == _root->_right)
			return insert_pair(to_insert).first;

		if (hint == end()) {
			if (_comp(_last_node->_content.first, to_insert.first)) {
				// std::cout << "hint is good";
				return iterator(insert_node(_last_node, to_insert), _last_node);
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
				return iterator(insert_node(hint._node, to_insert), _last_node);
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
			return iterator(insert_node(hint._node, to_insert), _last_node);
		} else {
			std::cout << "hint not good";
			return insert_pair(to_insert).first;
		}
	}

	template< class InputIt >
	void insert( InputIt first, InputIt last ) {
		while (first != last) {
			insert_pair(*first);
			first++;
		}
	};

	void clear();

	void erase(iterator position);

	void erase(iterator first, iterator last);

	void erase(value_type to_erase);

	void swap(RedBlackTree &x);









	/* *************************************************** */
	/*                                                     */
	/*                       LOOKUP                        */
	/*                                                     */
	/* *************************************************** */


	iterator find(value_type to_find)
	{
		iterator it = begin();
		while (it != end())
		{
			if (*it == to_find)
				return it;
			it++;
		}
		return it;
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

	void leftRotate(node_pointer x)
	{
		// std::cout << "left rotate" << std::endl;
		node_pointer y = x->_right;
		x->_right = y->_left;

		// display_tree("befor left rotate");
		
		if (y->_left != TNULL)
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
		if (y->_right != TNULL)
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

	//fixe tree
	node_pointer fix_tree(node_pointer c)
	{
		node_pointer u;
		while (c->_parent && c->_parent->_color == 1)
		{
			if (c->_parent == c->_parent->_parent->_right)
			{
				u = c->_parent->_parent->_left;
				// std::cout << "test : " << u << std::endl;
				if (u && u->_color == 1)
				{
					u->_color = 0;
					c->_parent->_color = 0;
					c->_parent->_parent->_color = 1;
					c = c->_parent->_parent;
				}
				else
				{
					if (c == c->_parent->_left)
					{
						c = c->_parent;
						rightRotate(c);
					}
					c->_parent->_color = 0;
					c->_parent->_parent->_color = 1;
					leftRotate(c->_parent->_parent);
				}
			}
			else
			{
				// std::cout << "left" << std::endl;
				u = c->_parent->_parent->_right;

				if (u && u->_color == 1)
				{
					u->_color = 0;
					c->_parent->_color = 0;
					c->_parent->_parent->_color = 1;
					c = c->_parent->_parent;
				}
				else
				{
					if (c == c->_parent->_right)
					{
						c = c->_parent;
						leftRotate(c);
					}
					c->_parent->_color = 0;
					c->_parent->_parent->_color = 1;
					rightRotate(c->_parent->_parent);
				}
			}
			if (c == _root)
			{
				break;
			}
		}
		_root->_color = 0;

		// set last node
		while (c->_right != NULL)
			c = c->_right;
		_last_node = c;

		return c;
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

		int space_root = 50 + _size;
		int level = 0;
		int node_in_line = 0;

		if (current == NULL)
			std::cout << "Tree is empty" << std::endl;
		else {
			display_tree(parent = _root, space_root, level, node_in_line);
		}
		// for(size_t i = 0; i <= _size; i++)
		// {
		// 	if (current == _root) {
		// 		std::cout << "			" <<current->_content << std::endl;
		// 		parent = current;
		// 	}
		// 	if (current->_left) {
		// 		std::cout << "left " << current->_content << std::endl;
		// 		current = current->_left;
		// 	}
		// 	else if (current->_right) {
		// 		std::cout << "right " << current->_content << std::endl;
		// 		current = current->_right;
		// 	}
		// 	// else
		// 	// 	break;
			
		// }
		// std::cout << "			" << _root->_content.first << " : " << _root->_content.second << std::endl;
	}


	void display_tree(node_pointer parent, int space_root, int level, int node_in_line)
	{
		if (parent == NULL)
			return;
		space_root -= 10;
		
		display_tree(parent->_left, space_root, level + 1, node_in_line);
		// std::cout << std::endl;
		for (int i = 10; i < space_root; i++)
			std::cout << " ";
		if (parent->_color == N_RED)
			std::cout << RED;
		std::cout << parent->_content.first << " : " << parent->_content.second << std::endl;
		// std::cout << parent->_content.first << " : " << parent->_content.second << " c: " << parent->_color << std::endl;
		std::cout << END ;

		display_tree(parent->_right, space_root, level + 1, node_in_line);
	}
	// {
	// 	if (parent == NULL)
	// 		return;
		
	// 	// int display_r = 0;
	// 	// int display_l = 0;

	// 	int space_between = 3;

	// 	// if (parent == _root) {
	// 		for(int i = 0; i < space_root; i++) std::cout << " ";
	// 		std::cout <<parent->_content.first << std::endl;
	// 		for(int i = 0; i < space_root - 2 ; i++) std::cout << " ";
	// 		std::cout << "/" ;
	// 		for(int i = 0; i < space_between ; i++) std::cout << " ";
	// 		std::cout << "\\";
	// 		if (node_in_line == pow(level, 2)) 
	// 			std::cout << std::endl;
	// 	// }

	// 	display_tree(parent->_left, space_root - 3, level + 1, node_in_line++);
	// 	display_tree(parent->_right, space_root + 3, level + 1, node_in_line++);

	// 	if (parent->_left != NULL) {
	// 		// for(int i = 0; i < space_root - (level * 3) - 1; i++) std::cout << " ";
	// 		// std::cout << parent->_left->_content.first;
	// 		// for(int i = 0; i < space_between + (3 * level); i++) std::cout << " ";
	// 		node_in_line++;

	// 		// display_l = 1;
	// 	}
	// 	else
	// 		for(int i = 0; i < space_root + (level * 3); i++) std::cout << " ";


	// 	if (parent->_right != NULL) {
	// 		// std::cout <<parent->_right->_content.first;
	// 		node_in_line++;
			
	// 		// display_r = 1;
	// 	}
	// 	else {
	// 		// if (node_in_line == pow(level, 2))
	// 		std::cout << std::endl;
	// 		level++;
	// 	}
			
	// }

};

} // namespace ft


#endif






#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <iostream>
#include "utils.hpp"
#include "rbtree_iterator.hpp"

using namespace std;

#define RED 0
#define BLACK 1

namespace ft
{

// struct Node
// {
// 	int     _content;
// 	Node 	*_parent;
// 	Node 	*_left;
// 	Node 	*_right;
// 	int 	_color;
// };


template <class T, class Compare = std::less<T>, class Node = ft::Node<T>,
			class Type_Alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
class RedBlackTree
{
public:

	/* Self type */
	typedef RedBlackTree  							self;

	/* A reference to the self type */
	typedef self&   								self_reference;
	
	/* The first template argument */
	typedef T   									value_type;

	/* Stored Node type */
	typedef Node 									node_type;

	/* Pointer to stored node */
	typedef Node 									*node_pointer;

	typedef Node const 								*node_const_pointer;
	
	/* Node allocator */
	typedef Node_Alloc  							node_alloc;

	/* Size_t */
	typedef size_t 									size_type;

	typedef ft::RB_iterator<Node, Compare> 			iterator;
	typedef ft::RB_const_iterator<Node, Compare> 	const_iterator;

private:
	
	// last_node parent = root of tree, last_node right = last node, last_node left = first node
	node_alloc      _node_alloc;
	node_pointer    _last_node;
	node_pointer	_root;
	size_type		_size;
	Compare			_comp;
	

public:
	/* Default constructor */
	// RedBlackTree() : _last_node(_node_alloc.allocate(1))
	// {
	// 	_last_node->_parent = _last_node;
	// 	_last_node->_left = _last_node;
	// 	_last_node->_right = _last_node;
	// 	_last_node->_color = BLACK;
	// }

	RedBlackTree(const node_alloc &node_alloc_init = node_alloc())
	:
		_node_alloc(node_alloc_init),
		_last_node(_node_alloc.allocate(1)),
		_root(_last_node),
		_size(0)
	{

		// const_cast<type*>(this)->i = v;
		// node_const_pointer const_node = const_cast<node_pointer>(_last_node);

		// node_const_pointer &const_node = _last_node;
		// std::cout << "last_node = " << _last_node << std::endl;
		_node_alloc.construct(_last_node, Node());
	}

	/* Copy constructor */
	// RedBlackTree(const self& x) : _last_node(_node_alloc.allocate(1))
	// {
	// 	_last_node->_parent = _last_node;
	// 	_last_node->_left = _last_node;
	// 	_last_node->_right = _last_node;
	// 	_last_node->_color = BLACK;
	// 	*this = x;
	// }

	/* Destructor */
	~RedBlackTree()
	{
		_node_alloc.deallocate(_last_node, 1);
	}

	ft::pair<iterator, bool> insert_pair(value_type to_insert)
	{
		Node * new_node = _node_alloc.allocate(1);
		Node * prev_node = _last_node;

		_node_alloc.construct(new_node, Node(to_insert));

		return (ft::make_pair(iterator(new_node, prev_node), true));
	}

	iterator insert(value_type to_insert)
	{
		Node *new_node = _node_alloc.allocate(1);

		_node_alloc.construct(new_node, Node(to_insert));

		return (iterator(new_node));
	}

	iterator begin()
	{
		return (iterator(_root));
	}

	iterator end()
	{
		return (iterator(_last_node));
	}
	
	const_iterator begin() const
	{
		return (const_iterator(_root));
	}

	const_iterator end() const
	{
		return (const_iterator(_last_node));
	}

	iterator find(value_type to_find)
	{
		iterator it = begin();
		iterator ite = end();

		while (it != ite)
		{
			if (*it == to_find)
				return (it);
			it++;
		}
		return (it);
	}

	const_iterator find(value_type to_find) const
	{
		const_iterator it = begin();
		const_iterator ite = end();

		while (it != ite)
		{
			if (*it == to_find)
				return (it);
			it++;
		}
		return (it);
	}

	size_type size() const
	{
		size_type size = 0;

		const_iterator it = begin();
		const_iterator ite = end();

		std::cout << "size = " << size << std::endl;
		while (it != ite)
		{
			size++;
			it++;
		}
		return (size);
	}

	bool empty() const
	{
		return (size() == 0);
	}

	
	
};

} // namespace ft


#endif
