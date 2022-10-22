/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:58:53 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/23 00:39:19 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_ITERATOR_HPP
# define RBTREE_ITERATOR_HPP

#include "Iterator_traits.hpp"

namespace ft
{

template <typename T, class Compare >
	class RB_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public :
			typedef typename T::value_type    value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category 	iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type 	difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference 			reference;


			/* *************************************************** */
			/*                                                     */
			/*                     CONSTRUCTOR                     */
			/*                                                     */
			/* *************************************************** */

			RB_iterator(const Compare& comp = Compare())
			:
				_node(),
				_last_node(),
				_nil(NULL),
				_comp(comp)
			{}

			RB_iterator(T *node_p, T *nil, const Compare& comp = Compare())
			:
				_node(node_p),
				_last_node(),
				_nil(nil),
				_comp(comp)
			{
				_last_node = _node;
				while (_last_node->_right && _last_node->_right != _nil)
					_last_node = _last_node->_right;
			}

			RB_iterator(T *node_p, T *last_node, T *nil, const Compare& comp = Compare())
			:
				_node(node_p),
				_last_node(last_node),
				_nil(nil),
				_comp(comp)
			{
			}

			RB_iterator(const RB_iterator& tree_it)
			:
				_node(tree_it._node),
				_last_node(tree_it._last_node),
				_nil(tree_it._nil),
				_comp()
			{}

			virtual ~RB_iterator() { }

			RB_iterator &operator=(const RB_iterator& tree_it)
			{
				if (*this == tree_it)
					return (*this);
				_node = tree_it._node;
				_nil = tree_it._nil;
				_last_node = tree_it._last_node;
				_comp = tree_it._comp;
				return (*this);
			}



			/* *************************************************** */
			/*                                                     */
			/*                      OPERATOR                       */
			/*                                                     */
			/* *************************************************** */

			bool operator==(const RB_iterator& tree_it)
			{ return (_node == tree_it._node); }

			bool operator!=(const RB_iterator& tree_it)
			{ return (_node != tree_it._node); }

			reference operator*() const
			{ return (_node->_content); }

			pointer operator->() const
			{ return (&_node->_content); }

			RB_iterator& operator++(void)
			{
				// std::cout << "actuel node : " << _node->_content.first << std::endl;
				// std::cout << "last node : " << _last_node->_content.first << std::endl;
				if (_node == _last_node) {
					// std::cout << "Error: incrementing a NULL iterator" << std::endl;
					_node = _last_node->_right;
					return (*this);
				}
				if (_node->_right != _nil)
				{
					// std::cout << "go right" << std::endl;
					_node = _node->_right;
					while (_node->_left != _nil)
						_node = _node->_left;
					// _node = _node->_left;
				}
				else
				{
					// std::cout << "go up" << std::endl;
					while (_node->_parent != NULL && _node->_parent->_right == _node)
						_node = _node->_parent;
					_node = _node->_parent;
				}
				// std::cout << "after node : " << _node->_content.first << std::endl;

				return (*this);
			}

			RB_iterator operator++(int)
			{
				// std::cout << "operator++(int)" << std::endl;
				RB_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			RB_iterator& operator--(void)
			{
				// std::cout << "last node" 
				// 					<< "\ncontent : "<< _last_node->_content.first 
				// 					<< "\nparent : " << _last_node->_parent->_content.first
				// 					<< "\nleft : " << _last_node->_left->_content.first
				// 					<< "\nright : " << _last_node->_right->_content.first
				// 					<< std::endl << std::endl;

				if (_node == _nil)
				{
					// std::cout << "Error: decrementing a NULL iterator" << std::endl;
					_node = _last_node;
					return (*this);
				}
				if (_node->_left != _nil)
				{
					_node = _node->_left;
					while (_node->_right != _nil)
						_node = _node->_right;
				}
				else
				{
					while (_node->_parent != NULL && _node->_parent->_left == _node)
						_node = _node->_parent;
					_node = _node->_parent;
				}
				return (*this);
				
			}

			RB_iterator operator--(int)
			{
				RB_iterator tmp(*this);
				operator--();
				return (tmp);
			}

			RB_iterator& operator+=(difference_type n)
			{
				if (n < 0)
					return (*this += n);
				while (n--)
					operator++();
				return (*this);
			}

			RB_iterator& operator-=(difference_type n)
			{
				if (n < 0)
					return (*this -= n);
				while (n--)
					operator--();
				return (*this);
			}



			T *			_node;
			T *			_last_node;
			T *			_nil;
			Compare		_comp;
	};

	template <typename T, class Compare >
	class RB_const_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public :

			typedef typename T::value_type    value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category 	iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer const 			pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference const 		reference;

			typedef RB_iterator<T, Compare> iterator;
			

			/* *************************************************** */
			/*                                                     */
			/*                     CONSTRUCTOR                     */
			/*                                                     */
			/* *************************************************** */

			RB_const_iterator(const Compare& comp = Compare())
			:
				_node(),
				_last_node(),
				_nil(NULL),
				_comp(comp)
			{
				// std::cout << "RB_const_iterator()" << std::endl;
			}

			RB_const_iterator(T *node_p, T *nil, const Compare& comp = Compare())
			:
				_node(node_p),
				_last_node(),
				_nil(nil),
				_comp(comp)
			{
				_last_node = _node;
				while (_last_node->_right && _last_node->_right != _nil)
					_last_node = _last_node->_right;
			}

			// RB_const_iterator(T * node_p, const Compare& comp = Compare())
			// :
			// 	_node(node_p),
			// 	_last_node(),
			// 	_comp(comp)
			// {
			// 	// std::cout << "RB_const_iterator(T * node_p)" << std::endl;
			// }

			RB_const_iterator(T * node_p, T * last_node, T *nil, const Compare& comp = Compare())
			:
				_node(node_p),
				_last_node(last_node),
				_nil(nil),
				_comp(comp)
			{
				// std::cout << "RB_const_iterator(T * node_p, T * last_node)" << std::endl;
			}

			RB_const_iterator(const RB_const_iterator& tree_it)
			:
				_node(tree_it._node),
				_last_node(tree_it._last_node),
				_nil(tree_it._nil),
				_comp()
			{}

			RB_const_iterator(const RB_iterator<T, Compare>& tree_it)
			:
				_node(tree_it._node),
				_last_node(tree_it._last_node),
				_nil(tree_it._nil),
				_comp(tree_it._comp)
			{
				// std::cout << "RB_const_iterator(const RB_iterator<T, Compare>& tree_it)" << std::endl;
			}

			virtual ~RB_const_iterator() { }


			RB_const_iterator &operator=(const RB_const_iterator& tree_it)
			{
				if (*this == tree_it)
					return (*this);
				_node = tree_it._node;
				_last_node = tree_it._last_node;
				_comp = tree_it._comp;
				return (*this);
			}

			iterator
			_tree_const_cast() const {
				return (iterator(const_cast<T*>(_node), const_cast<T*>(_last_node), _comp));
			}




			/* *************************************************** */
			/*                                                     */
			/*                      OPERATOR                       */
			/*                                                     */
			/* *************************************************** */

			bool operator==(const RB_const_iterator& tree_it)
			{ return (_node == tree_it._node); }

			bool operator!=(const RB_const_iterator& tree_it)
			{ return (_node != tree_it._node); }

			reference operator*() const
			{ return (_node->_content); }

			pointer operator->() const
			{ return (&_node->_content); }

			RB_const_iterator& operator++(void)
			{
				// std::cout << "const operator++" << std::endl;
				// std::cout << "last node" 
				// 					<< "\ncontent : "<< _last_node->_content.first 
				// 					<< "\nparent : " << _last_node->_parent->_content.first
				// 					<< "\nleft : " << _last_node->_left->_content.first
				// 					<< "\nright : " << _last_node->_right->_content.first
				// 					<< std::endl << std::endl;

				// std::cout << "node" 
				// 					<< "\ncontent : "<< _node->_content.first 
				// 					// << "\nparent : " << _node->_parent->_content.first
				// 					<< "\nleft : " << _node->_left->_content.first
				// 					<< "\nright : " << _node->_right->_content.first
				// 					<< std::endl << std::endl;

				if (_node == _last_node) {
					// std::cout << "Error: incrementing a NULL iterator" << std::endl;
					_node = _last_node->_right;
					return (*this);
				}
				if (_node->_right != _nil)
				{
					// std::cout << BLU "go right" END<< std::endl;
					_node = _node->_right;
					while (_node->_left && _node->_left != _nil)
						_node = _node->_left;
				}
				else
				{
					// std::cout << "go up" << std::endl;
					while (_node->_parent != NULL && _node->_parent->_right == _node)
						_node = _node->_parent;
					_node = _node->_parent;
				}

				// std::cout << "node after content : "<< _node->_content.first << std::endl;
				return (*this);
			}

			RB_const_iterator operator++(int)
			{
				// std::cout << "const operator++(int)" << std::endl;

				RB_const_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			RB_const_iterator& operator--(void)
			{
				// std::cout << "const operator--" << std::endl;
				// std::cout << "last node" 
				// 					<< "\ncontent : "<< _last_node->_content.first 
				// 					<< "\nparent : " << _last_node->_parent->_content.first
				// 					<< "\nleft : " << _last_node->_left->_content.first
				// 					<< "\nright : " << _last_node->_right->_content.first
				// 					<< std::endl << std::endl;

				// std::cout << "node" 
				// 					<< "\ncontent : "<< _node->_content.first 
				// 					// << "\nparent : " << _node->_parent->_content.first
				// 					// << "\nleft : " << _node->_left->_content.first
				// 					// << "\nright : " << _node->_right->_content.first
				// 					<< std::endl << std::endl;

				if (_node == _nil) {
					_node = _last_node;
					return (*this);

					// RB_const_iterator tmp = this;
					// return (tmp);
				}
				if (_node->_left != _nil)
				{
					_node = _node->_left;
					while (_node->_right != _nil)
						_node = _node->_right;
				}
				else
				{
					while (_node->_parent != NULL && _node->_parent->_left == _node)
						_node = _node->_parent;
					_node = _node->_parent;
				}
				// RB_const_iterator tmp = this;
				// return (tmp);
				return (*this);
			}

			RB_const_iterator operator--(int)
			{
				// std::cout << "const operator--(int)" << std::endl;

				RB_const_iterator tmp(*this);
				operator--();
				return (tmp);
			}

			T *         _node;
			T *         _last_node;
			T *				 	_nil;
			Compare     _comp;
	};
}

#endif /* BST_ITERATOR_HPP */