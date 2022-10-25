/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_iterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:23:50 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/25 01:15:12 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_ITERATOR
#define MY_ITERATOR

#include "enable_if.hpp"

namespace ft
{
	template <class _Iter>
	class my_iterator
	{

	protected:
		iterator_type                                   it;

	public:
		typedef _Iter                                   iterator_type;
		typedef ft::iterator_traits<iterator_type>      traits_type;

		typedef typename traits_type::iterator_category iterator_category;
		typedef typename traits_type::value_type        value_type;
		typedef typename traits_type::difference_type   difference_type;
		typedef typename traits_type::pointer           pointer;
		typedef typename traits_type::reference         reference;


		my_iterator()
		: 
			it()
		{
			return ;
		}

		my_iterator(iterator_type it)
		:
		it(it)
		{}

		my_iterator(const my_iterator &src) : it(src.it) {}

		~my_iterator() {}

		iterator_type base() const { return (it); }

		my_iterator &operator=(const my_iterator &rhs)
		{
			if (this != &rhs)
				this->it = rhs.it;
			return (*this);
		}

		reference operator*() const { return (*it); }
		pointer operator->() const { return (it); }

		my_iterator &operator++()
		{
			it++;
			return (*this);
		}

		my_iterator operator++(int)
		{
			++it;
			return (*this);
		}

		my_iterator &operator--()
		{
			it--;
			return (*this);
		}

		my_iterator operator--(int)
		{
			--it;
			return (*this);
		
		}

		my_iterator operator+(difference_type n)
		{
			it += n;
			return (*this);
		}

		difference_type operator+(const my_iterator &rhs) const
		{
			return (this->it + rhs.it);
		}

		my_iterator operator-(difference_type n)
		{
			it -= n;
			return (*this);
		}

		difference_type operator-(const my_iterator &rhs) const
		{
			return (it - rhs.it);
		}

		my_iterator &operator+=(difference_type n)
		{
			it += n;
			return (*this);
		}

		my_iterator &operator-=(difference_type n)
		{
			it -= n;
			return (*this);
		}

		reference operator[](difference_type n) const {
			return (it[n]);
		}

		bool operator==(const my_iterator &rhs) const { return (it == rhs.it); }
		bool operator!=(const my_iterator &rhs) const { return (it != rhs.it); }
		bool operator<(const my_iterator &rhs)  const { return (it < rhs.it); }
		bool operator<=(const my_iterator &rhs) const { return (it <= rhs.it); }
		bool operator>(const my_iterator &rhs)  const { return (it > rhs.it); }
		bool operator>=(const my_iterator &rhs) const { return (it >= rhs.it); }
	};
}

#endif