/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_tree.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:58:53 by jrasser           #+#    #+#             */
/*   Updated: 2022/11/04 14:59:59 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_ITERATOR_HPP
# define RBTREE_ITERATOR_HPP

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

			T *				_node;
			T *				_last_node;
			T *				_nil;
			Compare		_comp;

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
			{
			}

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

			/* test */
			void get_last_node() const {
				std::cout << "last node : " << _last_node->content.first << " : " << _last_node->_content.second << std::endl;
			}


			/* *************************************************** */
			/*                                                     */
			/*                      OPERATOR                       */
			/*                                                     */
			/* *************************************************** */

			// bool operator==(const RB_iterator& tree_it)
			// { return (_node == tree_it._node); }

			// bool operator!=(const RB_iterator& tree_it)
			// { return (_node != tree_it._node); }

			reference operator*() const
			{ return (_node->_content); }

			pointer operator->() const
			{ return (&_node->_content); }

			RB_iterator& operator++(void)
			{
				if (_node == _last_node) {
					_node = _last_node->_right;
					return (*this);
				}
				if (_node != _nil && _node->_right != _nil)
				{
					_node = _node->_right;
					while (_node->_left != _nil)
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

			RB_iterator operator++(int)
			{
				RB_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			RB_iterator& operator--(void)
			{
				if (_node == _nil)
				{
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
	};

	template <typename T, class Compare >
	class RB_const_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public :

			typedef typename T::value_type     value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category 	iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, const value_type>::pointer  	const		pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, const value_type>::reference  const		reference;

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

			RB_const_iterator(T * node_p, T * last_node, T *nil, const Compare& comp = Compare())
			:
				_node(node_p),
				_last_node(last_node),
				_nil(nil),
				_comp(comp)
			{
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
				_comp()
			{
			}

			virtual ~RB_const_iterator() { }


			RB_const_iterator &operator=(const RB_const_iterator& tree_it)
			{
				if (*this == tree_it)
					return (*this);
				_node = tree_it._node;
				_nil = tree_it._nil;
				_last_node = tree_it._last_node;
				_comp = tree_it._comp;
				return (*this);
			}

			RB_const_iterator &operator=(const RB_iterator<T, Compare>& tree_it) {
				_node = const_cast<T*>(tree_it._node);
				_nil = const_cast<T*>(tree_it._nil);
				_last_node = const_cast<T*>(tree_it._last_node);
				_comp = tree_it._comp;
				return (*this);
			}


			iterator
			_tree_const_cast() const {
				return (iterator(const_cast<T*>(_node), const_cast<T*>(_last_node), _comp));
			}


			/* test */
			void get_last_node() const {
				std::cout << "last node const it : " << _last_node->_content.first << " : " << _last_node->_content.second << std::endl;
			}

			/* *************************************************** */
			/*                                                     */
			/*                      OPERATOR                       */
			/*                                                     */
			/* *************************************************** */

			// bool operator==(const RB_const_iterator& tree_it)
			// { return (_node == tree_it._node); }

			// bool operator!=(const RB_const_iterator& tree_it)
			// { return (_node != tree_it._node); }

			reference operator*() const
			{ return (_node->_content); }

			pointer operator->() const
			{ return (&_node->_content); }

			RB_const_iterator& operator++(void)
			{
				if (_node == _last_node) {
					_node = _last_node->_right;
					return (*this);
				}
				if (_node->_right != _nil)
				{
					_node = _node->_right;
					while (_node->_left != _nil)
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

			RB_const_iterator operator++(int)
			{
				RB_const_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			RB_const_iterator& operator--(void)
			{
				if (_node == _nil) {
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

			RB_const_iterator operator--(int)
			{
				RB_const_iterator tmp(*this);
				operator--();
				return (tmp);
			}

			T const *      _node;
			T const *      _last_node;
			T const *	 	_nil;
			Compare     _comp;
	};



	/* it -> it */
	template <class T, class Compare>
	bool operator==(const RB_iterator<T, Compare> &lhs, const RB_iterator<T, Compare> &rhs)
	{
		return (lhs._node == rhs._node);
	}

	template <class T, class Compare>
	bool operator!=(const RB_iterator<T, Compare> &lhs, const RB_iterator<T, Compare> &rhs)
	{
		return (lhs._node != rhs._node);
	}

	template <class T, class Compare>
	bool operator<(const RB_iterator<T, Compare> &lhs, const RB_iterator<T, Compare> &rhs)
	{
		return (lhs._node < rhs._node);
	}

	template <class T, class Compare>
	bool operator<=(const RB_iterator<T, Compare> &lhs, const RB_iterator<T, Compare> &rhs)
	{
		return (lhs._node <= rhs._node);
	}

	template <class T, class Compare>
	bool operator>(const RB_iterator<T, Compare> &lhs, const RB_iterator<T, Compare> &rhs)
	{
		return (lhs._node > rhs._node);
	}

	template <class T, class Compare>
	bool operator>=(const RB_iterator<T, Compare> &lhs, const RB_iterator<T, Compare> &rhs)
	{
		return (lhs._node >= rhs._node);
	}



	/* const it -> const it */
	template <class T, class Compare>
	bool operator==(const RB_const_iterator<T, Compare> &lhs, const RB_const_iterator<T, Compare> &rhs)
	{
		return (lhs._node == rhs._node);
	}

	template <class T, class Compare>
	bool operator!=(const RB_const_iterator<T, Compare> &lhs, const RB_const_iterator<T, Compare> &rhs)
	{
		return (lhs._node != rhs._node);
	}

	template <class T, class Compare>
	bool operator<(const RB_const_iterator<T, Compare> &lhs, const RB_const_iterator<T, Compare> &rhs)
	{
		return (lhs._node < rhs._node);
	}

	template <class T, class Compare>
	bool operator<=(const RB_const_iterator<T, Compare> &lhs, const RB_const_iterator<T, Compare> &rhs)
	{
		return (lhs._node <= rhs._node);
	}

	template <class T, class Compare>
	bool operator>(const RB_const_iterator<T, Compare> &lhs, const RB_const_iterator<T, Compare> &rhs)
	{
		return (lhs._node > rhs._node);
	}

	template <class T, class Compare>
	bool operator>=(const RB_const_iterator<T, Compare> &lhs, const RB_const_iterator<T, Compare> &rhs)
	{
		return (lhs._node >= rhs._node);
	}


	/* it -> const it */
	template <class T, class Compare>
	bool operator==(const RB_iterator<T, Compare> &lhs, const RB_const_iterator<T, Compare> &rhs)
	{
		return (lhs._node == rhs._node);
	}

	template <class T, class Compare>
	bool operator!=(const RB_iterator<T, Compare> &lhs, const RB_const_iterator<T, Compare> &rhs)
	{
		return (lhs._node != rhs._node);
	}

	template <class T, class Compare>
	bool operator<(const RB_iterator<T, Compare> &lhs, const RB_const_iterator<T, Compare> &rhs)
	{
		return (lhs._node < rhs._node);
	}

	template <class T, class Compare>
	bool operator<=(const RB_iterator<T, Compare> &lhs, const RB_const_iterator<T, Compare> &rhs)
	{
		return (lhs._node <= rhs._node);
	}

	template <class T, class Compare>
	bool operator>(const RB_iterator<T, Compare> &lhs, const RB_const_iterator<T, Compare> &rhs)
	{
		return (lhs._node > rhs._node);
	}

	template <class T, class Compare>
	bool operator>=(const RB_iterator<T, Compare> &lhs, const RB_const_iterator<T, Compare> &rhs)
	{
		return (lhs._node >= rhs._node);
	}


	/* const it -> it */
	template <class T, class Compare>
	bool operator==(const RB_const_iterator<T, Compare> &lhs, const RB_iterator<T, Compare> &rhs)
	{
		return (lhs._node == rhs._node);
	}

	template <class T, class Compare>
	bool operator!=(const RB_const_iterator<T, Compare> &lhs, const RB_iterator<T, Compare> &rhs)
	{
		return (lhs._node != rhs._node);
	}

	template <class T, class Compare>
	bool operator<(const RB_const_iterator<T, Compare> &lhs, const RB_iterator<T, Compare> &rhs)
	{
		return (lhs._node < rhs._node);
	}

	template <class T, class Compare>
	bool operator<=(const RB_const_iterator<T, Compare> &lhs, const RB_iterator<T, Compare> &rhs)
	{
		return (lhs._node <= rhs._node);
	}

	template <class T, class Compare>
	bool operator>(const RB_const_iterator<T, Compare> &lhs, const RB_iterator<T, Compare> &rhs)
	{
		return (lhs._node > rhs._node);
	}

	template <class T, class Compare>
	bool operator>=(const RB_const_iterator<T, Compare> &lhs, const RB_iterator<T, Compare> &rhs)
	{
		return (lhs._node >= rhs._node);
	}



}	// namespace ft

#endif