/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_iterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:23:50 by jrasser           #+#    #+#             */
/*   Updated: 2022/09/11 22:32:58 by jrasser          ###   ########.fr       */
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
		_Iter                                           it;
		typedef ft::iterator_traits<_Iter>              traits_type;

	public:
		typedef _Iter                                   iterator_type;
		typedef typename traits_type::iterator_category iterator_category;
		typedef typename traits_type::value_type        value_type;
		typedef typename traits_type::difference_type   difference_type;
		typedef typename traits_type::pointer           pointer;
		typedef typename traits_type::reference         reference;


		// template <typename U> 
		// my_iterator(my_iterator<U>) {};


		// Allow iterator to const_iterator conversion					REAL
		// template <typename _Iter>
		// __normal_iterator(const __normal_iterator<_Iter,
		// 										  typename __enable_if<
		// 											  (std::__are_same<_Iter, typename _Container::pointer>::__value),
		// 											  _Container>::__type> &__i) _GLIBCXX_NOEXCEPT
		// 	: _M_current(__i.base()) {}






		// template <typename U>											// MIEN
		// my_iterator(const my_iterator<U, typename enable_if<(std::__are_same<U, iterator_type>::value)>::type> &__i)
		// : it(__i.base()) {}






		// celui qui marche...											SEB

		template <typename U>
		my_iterator( my_iterator<U> const &u,
						typename enable_if<std::is_convertible<U, iterator_type>::value>::type * = NULL) :
		it(u.base()) {}






		my_iterator() : it() {}
		my_iterator(iterator_type it) : it(it) {}
		// my_iterator(const my_iterator &src) : it(src.it) {}
		my_iterator(const my_iterator &src) : it(src.it) {}
		~my_iterator() {}

		iterator_type base() const { return (it); }

		my_iterator &operator=(const my_iterator &rhs)                  // a revoir ?
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
		my_iterator &operator++() const
		{
			// it++;
			// return (*this);


			my_iterator tmp(*this);
			tmp++;
			return (tmp);

			// it++;
			// return (*this);
		}
		my_iterator operator++(int)
		{
			my_iterator tmp(*this);
			++(*this);
			return (tmp);
			// ++it;
			// return (*this);
		}
		my_iterator operator++(int) const
		{
			// my_iterator tmp(*this);
			// ++(*this);
			// return (tmp);
			
			my_iterator tmp(*this);
			++tmp;
			return (tmp);
		}
		my_iterator &operator--()
		{
			it--;
			return (*this);
		}

		my_iterator operator--(int)
		{
			my_iterator tmp(*this);
			--(*this);
			return (tmp);
			// --it;
			// return (*this);
		}

		my_iterator operator+(difference_type n)
		{
			it += n;
			return (*this);
		}

		my_iterator operator+(difference_type n) const
		{
			my_iterator tmp(*this);
			tmp += n;
			return (tmp);
			// it += n;
			// return (*this);
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