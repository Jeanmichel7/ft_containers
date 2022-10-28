/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:25:38 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/27 22:20:23 by jrasser          ###   ########.fr       */
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

		reverse_iterator operator+(difference_type n)
		{ return (reverse_iterator(_elem - n)); }

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

		reverse_iterator operator-(difference_type n)
		{
			return (reverse_iterator(_elem + n));
		}

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

	

	};

	template <typename _Iterator>
	inline bool operator==(const reverse_iterator<_Iterator> &x,
												 const reverse_iterator<_Iterator> &y)
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

	template <typename _Iterator>
	inline typename reverse_iterator<_Iterator>::difference_type operator-(const reverse_iterator<_Iterator> &x,
																																				 const reverse_iterator<_Iterator> &y)
	{
		return y.base() - x.base();
	}

	template <typename _Iterator>
	inline reverse_iterator<_Iterator> operator+(typename reverse_iterator<_Iterator>::difference_type n,
																							 const reverse_iterator<_Iterator> &x)
	{
		return reverse_iterator<_Iterator>(x.base() - n);
	}

	template <typename _IteratorL, typename _IteratorR>
	inline bool operator==(const reverse_iterator<_IteratorL> &x,
												 const reverse_iterator<_IteratorR> &y)
	{
		return x.base() == y.base();
	}

	template <typename _IteratorL, typename _IteratorR>
	inline bool operator<(const reverse_iterator<_IteratorL> &x,
												const reverse_iterator<_IteratorR> &y)
	{
		return x.base() > y.base();
	}

	template <typename _IteratorL, typename _IteratorR>
	inline bool operator!=(const reverse_iterator<_IteratorL> &x,
												 const reverse_iterator<_IteratorR> &y)
	{
		return x.base() != y.base();
	}

	template <typename _IteratorL, typename _IteratorR>
	inline bool operator>(const reverse_iterator<_IteratorL> &x,
												const reverse_iterator<_IteratorR> &y)
	{
		return x.base() < y.base();
	}

	template <typename _IteratorL, typename _IteratorR>
	inline bool operator<=(const reverse_iterator<_IteratorL> &x,
												 const reverse_iterator<_IteratorR> &y)
	{
		return x.base() >= y.base();
	}

	template <typename _IteratorL, typename _IteratorR>
	inline bool operator>=(const reverse_iterator<_IteratorL> &x,
												 const reverse_iterator<_IteratorR> &y)
	{
		return x.base() <= y.base();
	}

	template <typename _IteratorL, typename _IteratorR>
	inline typename reverse_iterator<_IteratorL>::difference_type operator-(const reverse_iterator<_IteratorL> &x,
																																					const reverse_iterator<_IteratorR> &y)
	{
		return y.base() - x.base();
	}

	template <typename _IteratorL, typename _IteratorR>
	inline reverse_iterator<_IteratorL> operator+(typename reverse_iterator<_IteratorL>::difference_type n,
																								const reverse_iterator<_IteratorR> &x)
	{
		return reverse_iterator<_IteratorL>(x.base() - n);
	}

	template <typename _Iterator>
	inline reverse_iterator<_Iterator> make_reverse_iterator(_Iterator x)
	{
		return reverse_iterator<_Iterator>(x);
	}

	/*
	template <typename _Iterator>
	class reverse_iterator
			: public std::iterator<typename ft::iterator_traits<_Iterator>::iterator_category,
														typename ft::iterator_traits<_Iterator>::value_type,
														typename ft::iterator_traits<_Iterator>::difference_type,
														typename ft::iterator_traits<_Iterator>::pointer,
														typename ft::iterator_traits<_Iterator>::reference>
	{

	protected:
			_Iterator                           current;
			typedef iterator_traits<_Iterator>  __traits_type;

	public:
			typedef _Iterator iterator_type;
			typedef typename __traits_type::difference_type difference_type;
			typedef typename __traits_type::pointer pointer;
			typedef typename __traits_type::reference reference;

			reverse_iterator() : current() {}
			explicit reverse_iterator(iterator_type x) : current(x) {}
			reverse_iterator(const reverse_iterator &x) : current(x.current) {}

			template <typename _Iter>
			reverse_iterator(const reverse_iterator<_Iter> &__x)
					: current(__x.base()) {}

			iterator_type base() const { return current; }

			reference operator*() const
			{
					_Iterator tmp = current;
					return *--tmp;
			}

			pointer operator->() const
			{
					return &(operator*());
			}

			reverse_iterator &operator++()
			{
					--current;
					return *this;
			}

			reverse_iterator operator++(int)
			{
					reverse_iterator tmp = *this;
					--current;
					return tmp;
			}

			reverse_iterator &operator--()
			{
					++current;
					return *this;
			}

			reverse_iterator operator--(int)
			{
					reverse_iterator tmp = *this;
					++current;
					return tmp;
			}

			reverse_iterator operator+(difference_type n) const
			{
					return reverse_iterator(current - n);
			}

			reverse_iterator &operator+=(difference_type n)
			{
					current -= n;
					return *this;
			}

			reverse_iterator operator-(difference_type n) const
			{
					return reverse_iterator(current + n);
			}

			reverse_iterator &operator-=(difference_type n)
			{
					current += n;
					return *this;
			}

			reference operator[](difference_type n) const
			{
					return *(*this + n);
			}

			reverse_iterator operator-(const reverse_iterator &x) const
			{
					return reverse_iterator(x.current - current);
			}

			reverse_iterator operator+(const reverse_iterator &x) const
			{
					return reverse_iterator(x.current + current);
			}

			reverse_iterator &operator+=(const reverse_iterator &x)
			{
					current += x.current;
					return *this;
			}

			reverse_iterator &operator-=(const reverse_iterator &x)
			{
					current -= x.current;
					return *this;
			}

			// bool operator==(const reverse_iterator &x) const
			// {
			//     return current == x.current;
			// }

			// bool operator!=(const reverse_iterator &x) const
			// {
			//     return current != x.current;
			// }

			// bool operator<(const reverse_iterator &x) const
			// {
			//     return current > x.current;
			// }

			// bool operator>(const reverse_iterator &x) const
			// {
			//     return current < x.current;
			// }

			// bool operator<=(const reverse_iterator &x) const
			// {
			//     return current >= x.current;
			// }

			// bool operator>=(const reverse_iterator &x) const
			// {
			//     return current <= x.current;
			// }
	};

	template <typename _Iterator>
	inline bool operator==(const reverse_iterator<_Iterator> &x,
												 const reverse_iterator<_Iterator> &y)
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

	// template <typename _Iterator>
	// inline typename reverse_iterator<_Iterator>::difference_type operator-(const reverse_iterator<_Iterator> &x,
	//                                                                           const reverse_iterator<_Iterator> &y)
	// {
	//     return y.base() - x.base();
	// }

	// template <typename _Iterator>
	// inline reverse_iterator<_Iterator> operator+(typename reverse_iterator<_Iterator>::difference_type n,
	//                                                const reverse_iterator<_Iterator> &x)
	// {
	//     return reverse_iterator<_Iterator>(x.base() - n);
	// }

	// template <typename _IteratorL, typename _IteratorR>
	// inline bool operator==(const reverse_iterator<_IteratorL> &x,
	//                        const reverse_iterator<_IteratorR> &y)
	// {
	//     return x.base() == y.base();
	// }

	// template <typename _IteratorL, typename _IteratorR>
	// inline bool operator<(const reverse_iterator<_IteratorL> &x,
	//                       const reverse_iterator<_IteratorR> &y)
	// {
	//     return x.base() > y.base();
	// }

	template <typename _IteratorL, typename _IteratorR>
	inline bool operator!=(const reverse_iterator<_IteratorL> &x,
												 const reverse_iterator<_IteratorR> &y)
	{
			return x.base() != y.base();
	}

	// template <typename _IteratorL, typename _IteratorR>
	// inline bool operator>(const reverse_iterator<_IteratorL> &x,
	//                       const reverse_iterator<_IteratorR> &y)
	// {
	//     return x.base() < y.base();
	// }

	// template <typename _IteratorL, typename _IteratorR>
	// inline bool operator<=(const reverse_iterator<_IteratorL> &x,
	//                        const reverse_iterator<_IteratorR> &y)
	// {
	//     return x.base() >= y.base();
	// }

	// template <typename _IteratorL, typename _IteratorR>
	// inline bool operator>=(const reverse_iterator<_IteratorL> &x,
	//                        const reverse_iterator<_IteratorR> &y)
	// {
	//     return x.base() <= y.base();
	// }

	// template <typename _IteratorL, typename _IteratorR>
	// inline typename reverse_iterator<_IteratorL>::difference_type operator-(const reverse_iterator<_IteratorL> &x,
	//                                                                           const reverse_iterator<_IteratorR> &y)
	// {
	//     return y.base() - x.base();
	// }

	// template <typename _IteratorL, typename _IteratorR>
	// inline reverse_iterator<_IteratorL> operator+(typename reverse_iterator<_IteratorL>::difference_type n,
	//                                                const reverse_iterator<_IteratorR> &x)
	// {
	//     return reverse_iterator<_IteratorL>(x.base() - n);
	// }

	// template <typename _Iterator>
	// inline reverse_iterator<_Iterator> make_reverse_iterator(_Iterator x)
	// {
	//     return reverse_iterator<_Iterator>(x);
	// }
	*/
}

#endif