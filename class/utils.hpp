/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:23:15 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/23 13:03:04 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#define N_BLACK 0
#define N_RED 1
#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define BLU "\033[0;34m"
#define MAG "\033[0;35m"
#define CYA "\033[0;36m"
#define END "\033[0m"

#include <iostream>
#include <math.h>
#include "enable_if.hpp"

namespace ft
{

	
template <class T1, class T2>
struct pair 
{
	typedef T1 first_type;
	typedef T2 second_type;

	T1 first;
	T2 second;

	/* ************************************************************************** */
	/*                                                                            */
	/*                                MEMBER FUNCTION                             */
	/*                                                                            */
	/* ************************************************************************** */

	pair() : first(T1()), second(T2()) {}

	template <class U, class V>
	pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {}

	pair(const T1& a, const T2& b) : first(a), second(b) {}

	pair& operator=(const pair& pr)
	{
		if (*this == pr)
			return *this;
		this->first = pr.first;
		this->second = pr.second;
		return *this;
	}



	~pair() {}

	// template <class T>
	// void swap (T& a, T& b)
	// {
	//     T c(a); a=b; b=c;
	// };

	// C++ 11
	// void swap (pair& pr) 
	// noexcept ( noexcept(swap(first,pr.first)) && noexcept(swap(second,pr.second)) ) 
	// {
	//     std::swap(first, pr.first);
	//     std::swap(second, pr.second);
	// }


	/* ************************************************************************** */
	/*                                                                            */
	/*                                    OPERATOR                                */
	/*                                                                            */
	/* ************************************************************************** */


	template <class T_1, class T_2>
	bool operator==(const pair<T_1, T_2> &rhs)
	{
		return (first == rhs.first && second == rhs.second);
	}
	
	template <class T_1, class T_2>
	bool operator!=(const pair<T_1, T_2> &rhs) 
	{
		return !(*this == rhs);
	}

	template <class T_1, class T_2>
	bool operator<( const pair<T_1, T_2> &rhs) const
	{
		return (first < rhs.first || (!(rhs.first < first) && second < rhs.second));
	}

	template <class T_1, class T_2>
	bool operator<=(const pair<T_1, T_2> &rhs)
	{
		return !(*this > rhs);
	}

	template <class T_1, class T_2>
	bool operator>(const pair<T_1, T_2> &rhs) const
	{
		return (rhs < *this);
	}

	template <class T_1, class T_2>
	bool operator>=(const pair<T_1, T_2> &rhs)
	{
		return !(*this <= rhs);
	}

	// C++ 11
	// template <class T_1, class T_2>
	// void swap(pair<T_1, T_2> &x, pair<T_1, T_2> &y) noexcept(noexcept(x.swap(y)))
	// {
	//     x.swap(y);
	// };

};

// template <class T1, class T2>
// std::ostream& operator<<(std::ostream& os, const pair<T1, T2>& pair)
// {
// 	os << pair.first << " " << pair.second;
// 	return os;
// };


template <class T1, class T2>
pair<T1, T2> make_pair(T1 x, T2 y)
{
	return (ft::pair<T1, T2>(x, y));
}

	template <class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1,
			   InputIt2 first2)
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if (!(*first1 == *first2))
			{
				return false;
			}
		}
		return true;
	}

	template <class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if (!p(*first1, *first2))
			{
				return false;
			}
		}
		return true;
	}

	template <class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								 InputIt2 first2, InputIt2 last2)
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if (first2 == last2 || *first2 < *first1)
			{
				return false;
			}
			if (*first1 < *first2)
			{
				return true;
			}
		}
		return first2 != last2;
	}

	template <class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								 InputIt2 first2, InputIt2 last2, Compare comp)
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if (first2 == last2 || comp(*first2, *first1))
			{
				return false;
			}
			if (comp(*first1, *first2))
			{
				return true;
			}
		}
		return first2 != last2;
	}

	template <typename T>
	struct Node
	{
		typedef T   value_type;

		value_type           _content;
		Node                *_parent;
		Node                *_left;
		Node                *_right;
		int                  _color;

		Node(Node *left, Node *right) 
		: _left(left), _right(right), _color(N_BLACK) {}
		
		Node(Node *parent, Node *left, Node *right) 
		: _parent(parent), _left(left), _right(right), _color(N_BLACK) {}

		Node(T content, Node *parent, Node *left, Node *right, int color) 
		: _content(content), _parent(parent), _left(left), _right(right), _color(color) {}

		Node(T const &content) 
		: _content(content), _parent(NULL), _left(NULL), _right(NULL), _color(N_RED) {}

		Node(T const &content, int color) 
		: _content(content), _parent(NULL), _left(NULL), _right(NULL), _color(color) {}


		Node(Node const &src) 
		:   _content(src._content),
			_parent(src._parent),
			_left(src._left),
			_right(src._right),
			_color(src._color)
		{
			return;
		}

		~Node() {}

		Node &operator=(Node const &rhs)
		{
			if (this != &rhs)
			{
				this->_content = rhs._content;
				this->_parent = rhs._parent;
				this->_left = rhs._left;
				this->_right = rhs._right;
				this->_color = rhs._color;
			}
			return (*this);
		}
	};
}







































/*

// Implementing Red-Black Tree in C++

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *parent;
	Node *left;
	Node *right;
	int color;
};

typedef Node *NodePtr;

class RedBlackTree
{
private:
	NodePtr root;
	NodePtr TNULL;

	void initializeNULLNode(NodePtr node, NodePtr parent)
	{
		node->data = 0;
		node->parent = parent;
		node->left = nullptr;
		node->right = nullptr;
		node->color = 0;
	}

	// Preorder
	void preOrderHelper(NodePtr node)
	{
		if (node != TNULL)
		{
			cout << node->data << " ";
			preOrderHelper(node->left);
			preOrderHelper(node->right);
		}
	}

	// Inorder
	void inOrderHelper(NodePtr node)
	{
		if (node != TNULL)
		{
			inOrderHelper(node->left);
			cout << node->data << " ";
			inOrderHelper(node->right);
		}
	}

	// Post order
	void postOrderHelper(NodePtr node)
	{
		if (node != TNULL)
		{
			postOrderHelper(node->left);
			postOrderHelper(node->right);
			cout << node->data << " ";
		}
	}

	NodePtr searchTreeHelper(NodePtr node, int key)
	{
		if (node == TNULL || key == node->data)
		{
			return node;
		}

		if (key < node->data)
		{
			return searchTreeHelper(node->left, key);
		}
		return searchTreeHelper(node->right, key);
	}

	// For balancing the tree after deletion
	void deleteFix(NodePtr x)
	{
		NodePtr s;
		while (x != root && x->color == 0)
		{
			if (x == x->parent->left)
			{
				s = x->parent->right;
				if (s->color == 1)
				{
					s->color = 0;
					x->parent->color = 1;
					leftRotate(x->parent);
					s = x->parent->right;
				}

				if (s->left->color == 0 && s->right->color == 0)
				{
					s->color = 1;
					x = x->parent;
				}
				else
				{
					if (s->right->color == 0)
					{
						s->left->color = 0;
						s->color = 1;
						rightRotate(s);
						s = x->parent->right;
					}

					s->color = x->parent->color;
					x->parent->color = 0;
					s->right->color = 0;
					leftRotate(x->parent);
					x = root;
				}
			}
			else
			{
				s = x->parent->left;
				if (s->color == 1)
				{
					s->color = 0;
					x->parent->color = 1;
					rightRotate(x->parent);
					s = x->parent->left;
				}

				if (s->right->color == 0 && s->right->color == 0)
				{
					s->color = 1;
					x = x->parent;
				}
				else
				{
					if (s->left->color == 0)
					{
						s->right->color = 0;
						s->color = 1;
						leftRotate(s);
						s = x->parent->left;
					}

					s->color = x->parent->color;
					x->parent->color = 0;
					s->left->color = 0;
					rightRotate(x->parent);
					x = root;
				}
			}
		}
		x->color = 0;
	}

	void rbTransplant(NodePtr u, NodePtr v)
	{
		if (u->parent == nullptr)
		{
			root = v;
		}
		else if (u == u->parent->left)
		{
			u->parent->left = v;
		}
		else
		{
			u->parent->right = v;
		}
		v->parent = u->parent;
	}

	void deleteNodeHelper(NodePtr node, int key)
	{
		NodePtr z = TNULL;
		NodePtr x, y;
		while (node != TNULL)
		{
			if (node->data == key)
			{
				z = node;
			}

			if (node->data <= key)
			{
				node = node->right;
			}
			else
			{
				node = node->left;
			}
		}

		if (z == TNULL)
		{
			cout << "Key not found in the tree" << endl;
			return;
		}

		y = z;
		int y_original_color = y->color;
		if (z->left == TNULL)
		{
			x = z->right;
			rbTransplant(z, z->right);
		}
		else if (z->right == TNULL)
		{
			x = z->left;
			rbTransplant(z, z->left);
		}
		else
		{
			y = minimum(z->right);
			y_original_color = y->color;
			x = y->right;
			if (y->parent == z)
			{
				x->parent = y;
			}
			else
			{
				rbTransplant(y, y->right);
				y->right = z->right;
				y->right->parent = y;
			}

			rbTransplant(z, y);
			y->left = z->left;
			y->left->parent = y;
			y->color = z->color;
		}
		delete z;
		if (y_original_color == 0)
		{
			deleteFix(x);
		}
	}

	// For balancing the tree after insertion
	void insertFix(NodePtr k)
	{
		NodePtr u;
		while (k->parent->color == 1)
		{
			if (k->parent == k->parent->parent->right)
			{
				u = k->parent->parent->left;
				if (u->color == 1)
				{
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else
				{
					if (k == k->parent->left)
					{
						k = k->parent;
						rightRotate(k);
					}
					k->parent->color = 0;
					k->parent->parent->color = 1;
					leftRotate(k->parent->parent);
				}
			}
			else
			{
				u = k->parent->parent->right;

				if (u->color == 1)
				{
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else
				{
					if (k == k->parent->right)
					{
						k = k->parent;
						leftRotate(k);
					}
					k->parent->color = 0;
					k->parent->parent->color = 1;
					rightRotate(k->parent->parent);
				}
			}
			if (k == root)
			{
				break;
			}
		}
		root->color = 0;
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

			string sColor = root->color ? "RED" : "BLACK";
			cout << root->data << "(" << sColor << ")" << endl;
			printHelper(root->left, indent, false);
			printHelper(root->right, indent, true);
		}
	}

public:
	RedBlackTree()
	{
		TNULL = new Node;
		TNULL->color = 0;
		TNULL->left = nullptr;
		TNULL->right = nullptr;
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
		while (node->left != TNULL)
		{
			node = node->left;
		}
		return node;
	}

	NodePtr maximum(NodePtr node)
	{
		while (node->right != TNULL)
		{
			node = node->right;
		}
		return node;
	}

	NodePtr successor(NodePtr x)
	{
		if (x->right != TNULL)
		{
			return minimum(x->right);
		}

		NodePtr y = x->parent;
		while (y != TNULL && x == y->right)
		{
			x = y;
			y = y->parent;
		}
		return y;
	}

	NodePtr predecessor(NodePtr x)
	{
		if (x->left != TNULL)
		{
			return maximum(x->left);
		}

		NodePtr y = x->parent;
		while (y != TNULL && x == y->left)
		{
			x = y;
			y = y->parent;
		}

		return y;
	}

	void leftRotate(NodePtr x)
	{
		NodePtr y = x->right;
		x->right = y->left;
		if (y->left != TNULL)
		{
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr)
		{
			this->root = y;
		}
		else if (x == x->parent->left)
		{
			x->parent->left = y;
		}
		else
		{
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
	}

	void rightRotate(NodePtr x)
	{
		NodePtr y = x->left;
		x->left = y->right;
		if (y->right != TNULL)
		{
			y->right->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr)
		{
			this->root = y;
		}
		else if (x == x->parent->right)
		{
			x->parent->right = y;
		}
		else
		{
			x->parent->left = y;
		}
		y->right = x;
		x->parent = y;
	}

	// Inserting a node
	void insert(int key)
	{
		NodePtr node = new Node;
		node->parent = nullptr;
		node->data = key;
		node->left = TNULL;
		node->right = TNULL;
		node->color = 1;

		NodePtr y = nullptr;
		NodePtr x = this->root;

		while (x != TNULL)
		{
			y = x;
			if (node->data < x->data)
			{
				x = x->left;
			}
			else
			{
				x = x->right;
			}
		}

		node->parent = y;
		if (y == nullptr)
		{
			root = node;
		}
		else if (node->data < y->data)
		{
			y->left = node;
		}
		else
		{
			y->right = node;
		}

		if (node->parent == nullptr)
		{
			node->color = 0;
			return;
		}

		if (node->parent->parent == nullptr)
		{
			return;
		}

		insertFix(node);
	}

	NodePtr getRoot()
	{
		return this->root;
	}

	void deleteNode(int data)
	{
		deleteNodeHelper(this->root, data);
	}

	void printTree()
	{
		if (root)
		{
			printHelper(this->root, "", true);
		}
	}
};

int main() {
  RedBlackTree bst;
  bst.insert(55);
  bst.insert(40);
  bst.insert(65);
  bst.insert(60);
  bst.insert(75);
  bst.insert(57);

  bst.printTree();
  cout << endl
	 << "After deleting" << endl;
  bst.deleteNode(40);
  bst.printTree();
}

*/
#endif