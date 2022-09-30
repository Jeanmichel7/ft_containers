/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:54:45 by jrasser           #+#    #+#             */
/*   Updated: 2022/09/30 19:22:42 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <iostream>
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


template <class T, class Compare = std::less<T>, class Node = ft::Node<T>,
			class Type_Alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
class RedBlackTree
{
public:

	/* Self type */
	typedef RedBlackTree  self;

	/* A reference to the self type */
	typedef self&   self_reference;
	
	/* The first template argument */
	typedef T   value_type;

	/* Stored Node type */
	typedef Node node_type;

	/* Pointer to stored node */
	typedef Node *  NodePtr;
	
	/* Node allocator */
	typedef Node_Alloc  node_alloc;

	/* Size_t */
	typedef size_t size_type;

	typedef ft::RB_iterator<Node, Compare> 			iterator;
	typedef ft::RB_const_iterator<Node, Compare> 	const_iterator;

private:
	NodePtr root;
	NodePtr TNULL;

public:
	void initializeNULLNode(NodePtr node, NodePtr _parent)
	{
		node->_content = 0;
		node->_parent = _parent;
		node->_left = nullptr;
		node->_right = nullptr;
		node->_color = 0;
	}

	// Preorder
	void preOrderHelper(NodePtr node)
	{
		if (node != TNULL)
		{
			cout << node->_content << " ";
			preOrderHelper(node->_left);
			preOrderHelper(node->_right);
		}
	}

	// Inorder
	void inOrderHelper(NodePtr node)
	{
		if (node != TNULL)
		{
			inOrderHelper(node->_left);
			cout << node->_content << " ";
			inOrderHelper(node->_right);
		}
	}

	// Post order
	void postOrderHelper(NodePtr node)
	{
		if (node != TNULL)
		{
			postOrderHelper(node->_left);
			postOrderHelper(node->_right);
			cout << node->_content << " ";
		}
	}

	NodePtr searchTreeHelper(NodePtr node, int key)
	{
		if (node == TNULL || key == node->_content)
		{
			return node;
		}

		if (key < node->_content)
		{
			return searchTreeHelper(node->_left, key);
		}
		return searchTreeHelper(node->_right, key);
	}

	// For balancing the tree after deletion
	void deleteFix(NodePtr x)
	{
		NodePtr s;
		while (x != root && x->_color == 0)
		{
			if (x == x->_parent->_left)
			{
				s = x->_parent->_right;
				if (s->_color == 1)
				{
					s->_color = 0;
					x->_parent->_color = 1;
					_leftRotate(x->_parent);
					s = x->_parent->_right;
				}

				if (s->_left->_color == 0 && s->_right->_color == 0)
				{
					s->_color = 1;
					x = x->_parent;
				}
				else
				{
					if (s->_right->_color == 0)
					{
						s->_left->_color = 0;
						s->_color = 1;
						_rightRotate(s);
						s = x->_parent->_right;
					}

					s->_color = x->_parent->_color;
					x->_parent->_color = 0;
					s->_right->_color = 0;
					_leftRotate(x->_parent);
					x = root;
				}
			}
			else
			{
				s = x->_parent->_left;
				if (s->_color == 1)
				{
					s->_color = 0;
					x->_parent->_color = 1;
					_rightRotate(x->_parent);
					s = x->_parent->_left;
				}

				if (s->_right->_color == 0 && s->_right->_color == 0)
				{
					s->_color = 1;
					x = x->_parent;
				}
				else
				{
					if (s->_left->_color == 0)
					{
						s->_right->_color = 0;
						s->_color = 1;
						_leftRotate(s);
						s = x->_parent->_left;
					}

					s->_color = x->_parent->_color;
					x->_parent->_color = 0;
					s->_left->_color = 0;
					_rightRotate(x->_parent);
					x = root;
				}
			}
		}
		x->_color = 0;
	}

	void rbTransplant(NodePtr u, NodePtr v)
	{
		if (u->_parent == nullptr)
		{
			root = v;
		}
		else if (u == u->_parent->_left)
		{
			u->_parent->_left = v;
		}
		else
		{
			u->_parent->_right = v;
		}
		v->_parent = u->_parent;
	}

	void deleteNodeHelper(NodePtr node, int key)
	{
		NodePtr z = TNULL;
		NodePtr x, y;
		while (node != TNULL)
		{
			if (node->_content == key)
			{
				z = node;
			}

			if (node->_content <= key)
			{
				node = node->_right;
			}
			else
			{
				node = node->_left;
			}
		}

		if (z == TNULL)
		{
			cout << "Key not found in the tree" << endl;
			return;
		}

		y = z;
		int y_original__color = y->_color;
		if (z->_left == TNULL)
		{
			x = z->_right;
			rbTransplant(z, z->_right);
		}
		else if (z->_right == TNULL)
		{
			x = z->_left;
			rbTransplant(z, z->_left);
		}
		else
		{
			y = minimum(z->_right);
			y_original__color = y->_color;
			x = y->_right;
			if (y->_parent == z)
			{
				x->_parent = y;
			}
			else
			{
				rbTransplant(y, y->_right);
				y->_right = z->_right;
				y->_right->_parent = y;
			}

			rbTransplant(z, y);
			y->_left = z->_left;
			y->_left->_parent = y;
			y->_color = z->_color;
		}
		delete z;
		if (y_original__color == 0)
		{
			deleteFix(x);
		}
	}

	// For balancing the tree after insertion
	void insertFix(NodePtr k)
	{
		NodePtr u;
		while (k->_parent->_color == 1)
		{
			if (k->_parent == k->_parent->_parent->_right)
			{
				u = k->_parent->_parent->_left;
				if (u->_color == 1)
				{
					u->_color = 0;
					k->_parent->_color = 0;
					k->_parent->_parent->_color = 1;
					k = k->_parent->_parent;
				}
				else
				{
					if (k == k->_parent->_left)
					{
						k = k->_parent;
						_rightRotate(k);
					}
					k->_parent->_color = 0;
					k->_parent->_parent->_color = 1;
					_leftRotate(k->_parent->_parent);
				}
			}
			else
			{
				u = k->_parent->_parent->_right;

				if (u->_color == 1)
				{
					u->_color = 0;
					k->_parent->_color = 0;
					k->_parent->_parent->_color = 1;
					k = k->_parent->_parent;
				}
				else
				{
					if (k == k->_parent->_right)
					{
						k = k->_parent;
						_leftRotate(k);
					}
					k->_parent->_color = 0;
					k->_parent->_parent->_color = 1;
					_rightRotate(k->_parent->_parent);
				}
			}
			if (k == root)
			{
				break;
			}
		}
		root->_color = 0;
	}

	void printHelper(NodePtr root, string indent, bool last)
	{
		if (root != TNULL)
		{
			cout << indent;
			if (last)
			{
				cout << "R----";
				indent += "   ";
			}
			else
			{
				cout << "L----";
				indent += "|  ";
			}

			string s_color = root->_color ? "RED" : "BLACK";
			cout << root->_content << "(" << s_color << ")" << endl;
			printHelper(root->_left, indent, false);
			printHelper(root->_right, indent, true);
		}
	}

public:
	RedBlackTree()
	{
		TNULL = new Node;
		TNULL->_color = 0;
		TNULL->_left = nullptr;
		TNULL->_right = nullptr;
		root = TNULL;
	}

	void preorder()
	{
		preOrderHelper(this->root);
	}

	void inorder()
	{
		inOrderHelper(this->root);
	}

	void postorder()
	{
		postOrderHelper(this->root);
	}

	NodePtr searchTree(int k)
	{
		return searchTreeHelper(this->root, k);
	}

	NodePtr minimum(NodePtr node)
	{
		while (node->_left != TNULL)
		{
			node = node->_left;
		}
		return node;
	}

	NodePtr maximum(NodePtr node)
	{
		while (node->_right != TNULL)
		{
			node = node->_right;
		}
		return node;
	}

	NodePtr successor(NodePtr x)
	{
		if (x->_right != TNULL)
		{
			return minimum(x->_right);
		}

		NodePtr y = x->_parent;
		while (y != TNULL && x == y->_right)
		{
			x = y;
			y = y->_parent;
		}
		return y;
	}

	NodePtr predecessor(NodePtr x)
	{
		if (x->_left != TNULL)
		{
			return maximum(x->_left);
		}

		NodePtr y = x->_parent;
		while (y != TNULL && x == y->_left)
		{
			x = y;
			y = y->_parent;
		}

		return y;
	}

	void _leftRotate(NodePtr x)
	{
		NodePtr y = x->_right;
		x->_right = y->_left;
		if (y->_left != TNULL)
		{
			y->_left->_parent = x;
		}
		y->_parent = x->_parent;
		if (x->_parent == nullptr)
		{
			this->root = y;
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

	void _rightRotate(NodePtr x)
	{
		NodePtr y = x->_left;
		x->_left = y->_right;
		if (y->_right != TNULL)
		{
			y->_right->_parent = x;
		}
		y->_parent = x->_parent;
		if (x->_parent == nullptr)
		{
			this->root = y;
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

	// Inserting a node
	// void insert(int key)
	ft::pair<iterator, bool> insert_node( const value_type& value )
	{
		NodePtr node = new Node;
		node->_parent = nullptr;
		node->_content = value;
		node->_left = TNULL;
		node->_right = TNULL;
		node->_color = 1;

		NodePtr y = nullptr;
		NodePtr x = this->root;

		while (x != TNULL)
		{
			y = x;
			if (node->_content < x->_content)
			{
				x = x->_left;
			}
			else
			{
				x = x->_right;
			}
		}

		node->_parent = y;
		if (y == nullptr)
		{
			root = node;
		}
		else if (node->_content < y->_content)
		{
			y->_left = node;
		}
		else
		{
			y->_right = node;
		}

		if (node->_parent == nullptr)
		{
			node->_color = 0;
			return ft::make_pair(iterator(node), true);;
		}

		if (node->_parent->_parent == nullptr)
		{
			return ft::make_pair(iterator(node), true);;
		}

		insertFix(node);
		return ft::make_pair(iterator(node), true);
	}

	NodePtr getRoot()
	{
		return this->root;
	}

	void deleteNode(int _content)
	{
		deleteNodeHelper(this->root, _content);
	}

	void printTree()
	{
		if (root)
		{
			printHelper(this->root, "", true);
		}
	}
};

}


#endif