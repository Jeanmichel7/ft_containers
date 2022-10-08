/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:58:53 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/08 20:04:24 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_ITERATOR_HPP
# define RBTREE_ITERATOR_HPP

namespace ft
{

template <typename T, class Compare >
	class RB_iterator : std::iterator<std::bidirectional_iterator_tag, T>
	{
		public :
			typedef typename T::value_type    value_type;

			/* The iterator category */
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::iterator_category 	iterator_category;

			/* The difference type */
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::difference_type 	difference_type;

			/* The pointer to the value */
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::pointer			pointer;

			/* The reference to the value */
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::reference 			reference;

			/*
			** @brief Default.
			** Create an iterator that pointing to inisialized 
			** binary search tree.
			*/
			RB_iterator(const Compare& comp = Compare())
			:
				_node(),
				_last_node(),
				_comp(comp)
			{}

			/*
			** @brief Create an iterator on "node_p".
			*/
			RB_iterator(T * node_p,
						const Compare& comp = Compare())
			:
				_node(node_p),
				_last_node(),
				_comp(comp)
			{}


			/*
			** @brief Create an iterator on "node_p".
			*/
			RB_iterator(T * node_p, T * last_node,
						const Compare& comp = Compare())
			:
				_node(node_p),
				_last_node(last_node),
				_comp(comp)
			{}


			/*
			** @brief Copy constructor.
			** Create a new Binary search tree iterator to be 
			** a copy of another.
			**
			** @param bst_it the binary search tree to be inpired by.
			*/
			RB_iterator(const RB_iterator& bst_it)
			:
				_node(bst_it._node),
				_last_node(bst_it._last_node),
				_comp()
			{}

			// Added for subject
			virtual ~RB_iterator() { }

			/*
			** @brief Assignement operator.
			** Create an iterator that will iterate the same than
			** "bst_it".
			**
			** @param bst_it the binary search tree to be inpired by.
			** @return a reference to this.
			*/
			RB_iterator &operator=(const RB_iterator& bst_it)
			{
				if (*this == bst_it)
					return (*this);
				_node = bst_it._node;
				_last_node = bst_it._last_node;
				_comp = bst_it._comp;
				return (*this);
			}

			/*
			** @brief Strictment equal operator.
			** Return a boolean that contains : if this iterator
			** and another one contains two equal binary search tree.
			**
			** @param bst_it the other binaray search tree iterator.
			** @return true if the two iterator iterate on two equal
			** tree, otherwise false.
			*/
			bool operator==(const RB_iterator& bst_it)
			{ return (_node == bst_it._node); }

			/*
			** @brief Different operator.
			** Return a boolean that contains : if this iterator
			** and another one contains two different binary search tree.
			**
			** @param bst_it the other binaray search tree iterator.
			** @return true if the two iterator iterate on two different
			** tree, otherwise false.
			*/
			bool operator!=(const RB_iterator& bst_it)
			{ return (_node != bst_it._node); }

			/*
			** @brief Give a reference to the value that contains
			** the binary search tree (value on a node) at the iterator
			** position.
			**
			** @return the const reference.
			*/
			reference operator*() const
			{ return (_node->_content); }

			/*
			** @brief Give a pointer to the value that contain
			** the binary search tree (value on a node) at the iterator
			** position.
			**
			** @return the const pointer.
			*/
			pointer operator->() const
			{ return (&_node->_content); }

			/*
			** @brief Increment the iterator to the next value
			** after the value in the tree at iterator position.
			**
			** @return a reference to this.
			*/
			RB_iterator& operator++(void)
			{
				if (_node == NULL) {
					_node = _last_node;
					return (*this);
				}
				if (_node->_right != NULL)
				{
					_node = _node->_right;
					while (_node->_left != NULL)
						_node = _node->_left;
				}
				else
				{
					while (_node->_parent != NULL && _node->_parent->_right == _node)
						_node = _node->_parent;
					_node = _node->_parent;
				}
				return (*this);
			}

			/*
			** @brief Post increment the iterator to the next value
			** after the value in the tree at iterator position.
			**
			** @return this before the incrementation.
			*/
			RB_iterator operator++(int)
			{
				RB_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			/*
			** @brief decrement the iterator to the previous value
			** before the value in the tree at iterator position.
			**
			** @return a reference to this.
			*/
			RB_iterator& operator--(void)
			{
				if (_node == NULL) {
					_node = _last_node;
					return (*this);
				}
				if (_node->_left != NULL)
				{
					_node = _node->_left;
					while (_node->_right != NULL)
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

			/*
			** @brief Post decrement the iterator to the previous value
			** before the value in the tree at iterator position.
			**
			** @return this before the decrementation.
			*/
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
			Compare		_comp;
	};

	template <typename T, class Compare >
	class RB_const_iterator : std::iterator<std::bidirectional_iterator_tag, T>
	{
		public :

			typedef typename T::value_type    value_type;

			/* The iterator category */
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::iterator_category 	iterator_category;

			/* The difference type */
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::difference_type	difference_type;

			/* The pointer to the value */
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::pointer			pointer;

			/* The reference to the value */
			typedef typename std::iterator<std::bidirectional_iterator_tag, value_type>::reference			reference;

			
			/*
			** @brief Default.
			** Create an iterator that pointing to inisialized 
			** binary search tree.
			*/
			RB_const_iterator(const Compare& comp = Compare())
			:
				_node(),
				_last_node(),
				_comp(comp)
			{}

			/*
			** @brief Create an iterator on "node_p".
			*/
			RB_const_iterator(T * node_p,
						const Compare& comp = Compare())
			:
				_node(node_p),
				_last_node(),
				_comp(comp)
			{}

			/*
			** @brief Create an iterator on "node_p".
			*/
			RB_const_iterator(T * node_p, T * last_node,
						const Compare& comp = Compare())
			:
				_node(node_p),
				_last_node(last_node),
				_comp(comp)
			{}

			/*
			** @brief Copy constructor.
			** Create a new Binary search tree iterator to be 
			** a copy of another.
			**
			** @param bst_it the binary search tree to be inpired by.
			*/
			RB_const_iterator(const RB_const_iterator& bst_it)
			:
				_node(bst_it._node),
				_last_node(bst_it._last_node),
				_comp()
			{}

			RB_const_iterator(const RB_iterator<T, Compare>& bst_it)
			:
				_node(bst_it._node),
				_last_node(bst_it._last_node),
				_comp()
			{}

			// Added for subject
			virtual ~RB_const_iterator() { }

			/*
			** @brief Assignement operator.
			** Create an iterator that will iterate the same than
			** "bst_it".
			**
			** @param bst_it the binary search tree to be inpired by.
			** @return a reference to this.
			*/
			RB_const_iterator &operator=(const RB_const_iterator& bst_it)
			{
				if (*this == bst_it)
					return (*this);
				_node = bst_it._node;
				_last_node = bst_it._last_node;
				_comp = bst_it._comp;
				return (*this);
			}
			
			/*
			** @brief Strictment equal operator.
			** Return a boolean that contains : if this iterator
			** and another one contains two equal binary search tree.
			**
			** @param bst_it the other binaray search tree iterator.
			** @return true if the two iterator iterate on two equal
			** tree, otherwise false.
			*/
			bool operator==(const RB_const_iterator& bst_it)
			{ return (_node == bst_it._node); }

			/*
			** @brief Different operator.
			** Return a boolean that contains : if this iterator
			** and another one contains two different binary search tree.
			**
			** @param bst_it the other binaray search tree iterator.
			** @return true if the two iterator iterate on two different
			** tree, otherwise false.
			*/
			bool operator!=(const RB_const_iterator& bst_it)
			{ return (_node != bst_it._node); }

			/*
			** @brief Give a reference to the value that contains
			** the binary search tree (value on a node) at the iterator
			** position.
			**
			** @return the const reference.
			*/
			reference operator*() const
			{ return (_node->_content); }

			/*
			** @brief Give a pointer to the value that contain
			** the binary search tree (value on a node) at the iterator
			** position.
			**
			** @return the const pointer.
			*/
			pointer operator->() const
			{ return (&_node->_content); }

			/*
			** @brief Increment the iterator to the next value
			** after the value in the tree at iterator position.
			**
			** @return a reference to this.
			*/
			RB_const_iterator& operator++(void)
			{
				// T * cursor = _node;

				// if (_node->_right == _last_node)
				// {
				// 	cursor = _node->_parent;
				// 	while (cursor != _last_node
				// 		&& _comp(cursor->_content.first, _node->_content.first))
				// 		cursor = cursor->_parent;
				// 	_node = cursor;
				// }
				// else if (cursor == _last_node)
				// 	_node = _last_node->_right;
				// else
				// {
				// 	cursor = _node->_right;
				// 	if (cursor == _last_node->_parent
				// 		&& cursor->_right == _last_node)
				// 		_node = cursor;
				// 	else
				// 	{
				// 		while (cursor->_left != _last_node)
				// 			cursor = cursor->_left;
				// 	}
				// 	_node = cursor;
				// }
				// return (*this);

				if (_node == NULL) {
					std::cout << "Error: incrementing a NULL iterator" << std::endl;
					_node = _last_node;
					return (*this);
				}
				if (_node->_right != NULL)
				{
					std::cout << "go right" << std::endl;
					_node = _node->_right;
					while (_node->_left != NULL)
						_node = _node->_left;
				}
				else
				{
					std::cout << "go up" << std::endl;
					while (_node->_parent != NULL && _node->_parent->_right == _node)
						_node = _node->_parent;
					_node = _node->_parent;
				}
				return (*this);
			}

			/*
			** @brief Post increment the iterator to the next value
			** after the value in the tree at iterator position.
			**
			** @return this before the incrementation.
			*/
			RB_const_iterator operator++(int)
			{
				RB_const_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			/*
			** @brief decrement the iterator to the previous value
			** before the value in the tree at iterator position.
			**
			** @return a reference to this.
			*/
			RB_const_iterator& operator--(void)
			{
				if (_node == NULL) {
					_node = _last_node;
					return (*this);
				}
				if (_node->_left != NULL)
				{
					_node = _node->_left;
					while (_node->_right != NULL)
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

			/*
			** @brief Post decrement the iterator to the previous value
			** before the value in the tree at iterator position.
			**
			** @return this before the decrementation.
			*/
			RB_const_iterator operator--(int)
			{
				RB_const_iterator tmp(*this);
				operator--();
				return (tmp);
			}            

			T *         _node;
			T *         _last_node;
			Compare     _comp;
	};
}

#endif /* BST_ITERATOR_HPP */