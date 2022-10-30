/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:25:38 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/30 21:51:03 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_REVERE_ITERATOR
# define MY_REVERE_ITERATOR

# include "iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category 	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type 					value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type 		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer 						pointer;
		typedef typename ft::iterator_traits<Iterator>::reference 					reference;

	private:
		iterator_type _elem;

	public:
		/* *************************************************** */
		/*                                                     */
		/*                     CONSTRUCTOR                     */
		/*                                                     */
		/* *************************************************** */

		reverse_iterator()
		: _elem()
		{
		}

		explicit reverse_iterator(iterator_type it)
				: _elem(it)
		{
		}

		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_it)
				: _elem(rev_it.base())
		{
		}

		virtual ~reverse_iterator() {}

		iterator_type base() const
		{
			return (_elem);
		}

		reference operator*() const
		{
			iterator_type tmp = _elem;
			return (*(--tmp));
		}

		// reverse_iterator operator+(difference_type n)
		// { return (reverse_iterator(_elem - n)); }

		reverse_iterator operator+(difference_type n) const 
		{ return (reverse_iterator(_elem - n)); }

		reverse_iterator &operator++()
		{
			--_elem;
			return (*this);
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator tmp = *this;
			++(*this);
			return (tmp);
		}

		reverse_iterator &operator+=(difference_type n)
		{
			_elem -= n;
			return (*this);
		}

		// reverse_iterator operator-(difference_type n)
		// {
		// 	return (reverse_iterator(_elem + n));
		// }

		reverse_iterator operator-(difference_type n) const 
		{ return (reverse_iterator(_elem + n)); }


		reverse_iterator &operator--()
		{
			++_elem;
			return (*this);
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator tmp = *this;
			--(*this);
			return (tmp);
		}

		reverse_iterator &operator-=(difference_type n)
		{
			_elem += n;
			return (*this);
		}

		pointer operator->() const 
		{ return &(operator*()); }

		reference operator[](difference_type n) const 
		{ return (this->base()[-n - 1]); }

		// operator reverse_iterator< const iterator_type >() const {
		// 	return (reverse_iterator< const iterator_type >(this->_elem));
		// }

		operator reverse_iterator< const iterator_type >() const {
			return (reverse_iterator< const iterator_type >(const_cast<iterator_type>(this->_elem)));
		}

	};

	template <typename _Iterator>
	inline bool operator==(const reverse_iterator<_Iterator> &x, const reverse_iterator<_Iterator> &y)
	{
		return x.base() == y.base();
	}


	template <typename _Iterator>
	inline bool operator<(const reverse_iterator<_Iterator> &x,
												const reverse_iterator<_Iterator> &y)
	{
		return x.base() > y.base();
	}

	template <typename _Iterator>
	inline bool operator!=(const reverse_iterator<_Iterator> &x,
												 const reverse_iterator<_Iterator> &y)
	{
		return x.base() != y.base();
	}

	template <typename _Iterator>
	inline bool operator>(const reverse_iterator<_Iterator> &x,
												const reverse_iterator<_Iterator> &y)
	{
		return x.base() < y.base();
	}

	template <typename _Iterator>
	inline bool operator<=(const reverse_iterator<_Iterator> &x,
												 const reverse_iterator<_Iterator> &y)
	{
		return x.base() >= y.base();
	}

	template <typename _Iterator>
	inline bool operator>=(const reverse_iterator<_Iterator> &x,
												 const reverse_iterator<_Iterator> &y)
	{
		return x.base() <= y.base();
	}



	/* const it - it */
	template <class Iterator_L, class Iterator_R>
	bool operator==(const reverse_iterator<Iterator_L> &lhs, const reverse_iterator<Iterator_R> &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator!=(const reverse_iterator<Iterator_L> &lhs, const reverse_iterator<Iterator_R> &rhs) 
	{ 
		return (lhs.base() != rhs.base()); 
	}

	template <class Iterator_L, class Iterator_R>
	bool operator<(const reverse_iterator<Iterator_L> &lhs, const reverse_iterator<Iterator_R> &rhs) 
	{ 
		return (lhs.base() > rhs.base()); 
	}

	template <class Iterator_L, class Iterator_R>
	bool operator<=(const reverse_iterator<Iterator_L> &lhs, const reverse_iterator<Iterator_R> &rhs) 
	{ 
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator>(const reverse_iterator<Iterator_L> &lhs, const reverse_iterator<Iterator_R> &rhs) 
	{ 
		return (lhs.base() < rhs.base());
	}

	template <class Iterator_L, class Iterator_R>
	bool operator>=(const reverse_iterator<Iterator_L> &lhs, const reverse_iterator<Iterator_R> &rhs) 
	{
		return (lhs.base() <= rhs.base());
	}





	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
	{
		return (reverse_iterator<Iterator>(rev_it.base() - n));
	}

	template <typename _IteratorL, typename _IteratorR>
	inline reverse_iterator<_IteratorL> operator+(typename reverse_iterator<_IteratorL>::difference_type n,
																								const reverse_iterator<_IteratorR> &x)
	{
		return reverse_iterator<_IteratorL>(x.base() - n);
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator-(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
	{
		return (reverse_iterator<Iterator>(rev_it.base() + n));
	}

	template <typename _IteratorL, typename _IteratorR>
	inline reverse_iterator<_IteratorL> operator-(typename reverse_iterator<_IteratorL>::difference_type n,
																								const reverse_iterator<_IteratorR> &x)
	{
		return reverse_iterator<_IteratorL>(x.base() + n);
	}


	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator+(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (rhs.base() - lhs.base());
	}



	/* operation between const / non const it */
	template <typename _IteratorL, typename _IteratorR>
	typename reverse_iterator<_IteratorL>::difference_type operator+(const reverse_iterator<_IteratorL> &x,
																																					const reverse_iterator<_IteratorR> &y)
	{
		return ( reverse_iterator<_IteratorL>(x.base()) + reverse_iterator<_IteratorL>(y.base()) );
	}


	template <typename IteratorL, typename IteratorR>
	typename reverse_iterator<IteratorL>::difference_type operator-(const reverse_iterator<IteratorL> &x,
																																	const reverse_iterator<IteratorR> &y)
	{
		return ( reverse_iterator<IteratorL>(x.base()) - reverse_iterator<IteratorL>(y.base()) );
	}

	// template <typename IteratorL, typename IteratorR>
	// typename reverse_iterator< IteratorL >::difference_type operator+ (const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	// {
	// 	return (lhs.base() + rhs.base());
	// }

	// template <typename IteratorL, typename IteratorR>
	// typename reverse_iterator< IteratorL >::difference_type operator- (const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	// {
	// 	return (lhs.base() - rhs.base());
	// }

} // namespace ft

#endif