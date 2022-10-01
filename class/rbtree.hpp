/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:54:45 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/01 17:29:32 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	node_pointer    _last_node;
	node_alloc      _node_alloc;

public:
	/* Default constructor */
	// RedBlackTree() : _last_node(_node_alloc.allocate(1))
	// {
	// 	_last_node->_parent = _last_node;
	// 	_last_node->_left = _last_node;
	// 	_last_node->_right = _last_node;
	// 	_last_node->_color = BLACK;
	// }

	RedBlackTree(const node_alloc &node_alloc_init = node_alloc()) : _node_alloc(node_alloc_init)
	{
		_last_node = _node_alloc.allocate(1);

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
		Node *new_node = _node_alloc.allocate(1);

		_node_alloc.construct(new_node, Node(to_insert));

		return (ft::make_pair(iterator(new_node), true));
	}

	iterator insert(value_type to_insert)
	{
		Node *new_node = _node_alloc.allocate(1);

		_node_alloc.construct(new_node, Node(to_insert));

		return (iterator(new_node));
	}

	iterator begin()
	{
		return (iterator(_last_node->_left));
	}

	iterator end()
	{
		return (iterator(_last_node));
	}
	
	const_iterator begin() const
	{
		return (const_iterator(_last_node->_left));
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



/*
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:54:45 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/01 17:27:03 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
