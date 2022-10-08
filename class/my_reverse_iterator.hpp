/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_reverse_iterator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:25:38 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/08 19:50:53 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_REVERE_ITERATOR
# define MY_REVERE_ITERATOR

#include "Iterator_traits.hpp"

namespace ft
{
    template <typename _Iterator>
    class my_reverse_iterator
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

        my_reverse_iterator() : current() {}
        explicit my_reverse_iterator(iterator_type x) : current(x) {}
        my_reverse_iterator(const my_reverse_iterator &x) : current(x.current) {}

        template <typename _Iter>
        my_reverse_iterator(const my_reverse_iterator<_Iter> &__x)
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

        my_reverse_iterator &operator++()
        {
            --current;
            return *this;
        }

        my_reverse_iterator operator++(int)
        {
            my_reverse_iterator tmp = *this;
            --current;
            return tmp;
        }

        my_reverse_iterator &operator--()
        {
            ++current;
            return *this;
        }

        my_reverse_iterator operator--(int)
        {
            my_reverse_iterator tmp = *this;
            ++current;
            return tmp;
        }

        my_reverse_iterator operator+(difference_type n) const
        {
            return my_reverse_iterator(current - n);
        }

        my_reverse_iterator &operator+=(difference_type n)
        {
            current -= n;
            return *this;
        }

        my_reverse_iterator operator-(difference_type n) const
        {
            return my_reverse_iterator(current + n);
        }

        my_reverse_iterator &operator-=(difference_type n)
        {
            current += n;
            return *this;
        }

        reference operator[](difference_type n) const
        {
            return *(*this + n);
        }

        my_reverse_iterator operator-(const my_reverse_iterator &x) const
        {
            return my_reverse_iterator(x.current - current);
        }

        my_reverse_iterator operator+(const my_reverse_iterator &x) const
        {
            return my_reverse_iterator(x.current + current);
        }

        my_reverse_iterator &operator+=(const my_reverse_iterator &x)
        {
            current += x.current;
            return *this;
        }

        my_reverse_iterator &operator-=(const my_reverse_iterator &x)
        {
            current -= x.current;
            return *this;
        }

        // bool operator==(const my_reverse_iterator &x) const
        // {
        //     return current == x.current;
        // }

        // bool operator!=(const my_reverse_iterator &x) const
        // {
        //     return current != x.current;
        // }

        // bool operator<(const my_reverse_iterator &x) const
        // {
        //     return current > x.current;
        // }

        // bool operator>(const my_reverse_iterator &x) const
        // {
        //     return current < x.current;
        // }

        // bool operator<=(const my_reverse_iterator &x) const
        // {
        //     return current >= x.current;
        // }

        // bool operator>=(const my_reverse_iterator &x) const
        // {
        //     return current <= x.current;
        // }
    };

    template <typename _Iterator>
    inline bool operator==(const my_reverse_iterator<_Iterator> &x,
                           const my_reverse_iterator<_Iterator> &y)
    {
        return x.base() == y.base();
    }

    template <typename _Iterator>
    inline bool operator<(const my_reverse_iterator<_Iterator> &x,
                          const my_reverse_iterator<_Iterator> &y)
    {
        return x.base() > y.base();
    }

    template <typename _Iterator>
    inline bool operator!=(const my_reverse_iterator<_Iterator> &x,
                           const my_reverse_iterator<_Iterator> &y)
    {
        return x.base() != y.base();
    }

    template <typename _Iterator>
    inline bool operator>(const my_reverse_iterator<_Iterator> &x,
                          const my_reverse_iterator<_Iterator> &y)
    {
        return x.base() < y.base();
    }

    template <typename _Iterator>
    inline bool operator<=(const my_reverse_iterator<_Iterator> &x,
                           const my_reverse_iterator<_Iterator> &y)
    {
        return x.base() >= y.base();
    }

    template <typename _Iterator>
    inline bool operator>=(const my_reverse_iterator<_Iterator> &x,
                           const my_reverse_iterator<_Iterator> &y)
    {
        return x.base() <= y.base();
    }

    // template <typename _Iterator>
    // inline typename my_reverse_iterator<_Iterator>::difference_type operator-(const my_reverse_iterator<_Iterator> &x,
    //                                                                           const my_reverse_iterator<_Iterator> &y)
    // {
    //     return y.base() - x.base();
    // }

    // template <typename _Iterator>
    // inline my_reverse_iterator<_Iterator> operator+(typename my_reverse_iterator<_Iterator>::difference_type n,
    //                                                const my_reverse_iterator<_Iterator> &x)
    // {
    //     return my_reverse_iterator<_Iterator>(x.base() - n);
    // }

    // template <typename _IteratorL, typename _IteratorR>
    // inline bool operator==(const my_reverse_iterator<_IteratorL> &x,
    //                        const my_reverse_iterator<_IteratorR> &y)
    // {
    //     return x.base() == y.base();
    // }

    // template <typename _IteratorL, typename _IteratorR>
    // inline bool operator<(const my_reverse_iterator<_IteratorL> &x,
    //                       const my_reverse_iterator<_IteratorR> &y)
    // {
    //     return x.base() > y.base();
    // }

    template <typename _IteratorL, typename _IteratorR>
    inline bool operator!=(const my_reverse_iterator<_IteratorL> &x,
                           const my_reverse_iterator<_IteratorR> &y)
    {
        return x.base() != y.base();
    }

    // template <typename _IteratorL, typename _IteratorR>
    // inline bool operator>(const my_reverse_iterator<_IteratorL> &x,
    //                       const my_reverse_iterator<_IteratorR> &y)
    // {
    //     return x.base() < y.base();
    // }

    // template <typename _IteratorL, typename _IteratorR>
    // inline bool operator<=(const my_reverse_iterator<_IteratorL> &x,
    //                        const my_reverse_iterator<_IteratorR> &y)
    // {
    //     return x.base() >= y.base();
    // }

    // template <typename _IteratorL, typename _IteratorR>
    // inline bool operator>=(const my_reverse_iterator<_IteratorL> &x,
    //                        const my_reverse_iterator<_IteratorR> &y)
    // {
    //     return x.base() <= y.base();
    // }

    // template <typename _IteratorL, typename _IteratorR>
    // inline typename my_reverse_iterator<_IteratorL>::difference_type operator-(const my_reverse_iterator<_IteratorL> &x,
    //                                                                           const my_reverse_iterator<_IteratorR> &y)
    // {
    //     return y.base() - x.base();
    // }

    // template <typename _IteratorL, typename _IteratorR>
    // inline my_reverse_iterator<_IteratorL> operator+(typename my_reverse_iterator<_IteratorL>::difference_type n,
    //                                                const my_reverse_iterator<_IteratorR> &x)
    // {
    //     return my_reverse_iterator<_IteratorL>(x.base() - n);
    // }

    // template <typename _Iterator>
    // inline my_reverse_iterator<_Iterator> make_reverse_iterator(_Iterator x)
    // {
    //     return my_reverse_iterator<_Iterator>(x);
    // }
}

#endif