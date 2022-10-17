/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:40:08 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/17 19:52:29 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP
#include <utility>

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

template <class T1, class T2>
std::ostream& operator<<(std::ostream& os, const pair<T1, T2>& pair)
{
    os << pair.first << " " << pair.second;
    return os;
};



// template <class _Tp>
// struct decay
// {
// private:
//     typedef typename std::remove_reference<_Tp>::type _Up;
// public:
//     typedef typename std::__decay<_Up, std::__is_referenceable<_Up>::value>::type type;
// };

// template <class _Tp>
// struct __unwrap_ref_decay: std::__unwrap_reference<typename decay<_Tp>::type>
// { };

// template <class _T1, class _T2>
// inline pair<typename decay<_T1>::type, typename decay<_T2>::type>
// make_pair(_T1 __x, _T2 __y)
// {
//     typedef typename decay<_T1>::type __decay_t1;
//     typedef typename decay<_T2>::type __decay_t2;
//     return pair<__decay_t1, __decay_t2>(std::forward<_T1>(__x),
//                                         std::forward<_T2>(__y));
// }

// pair<typename __unwrap_ref_decay<_T1>::type, typename __unwrap_ref_decay<_T2>::type>
// make_pair(_T1&& __t1, _T2&& __t2)
// {
//     return pair<typename __unwrap_ref_decay<_T1>::type, typename __unwrap_ref_decay<_T2>::type>
//                (_VSTD::forward<_T1>(__t1), _VSTD::forward<_T2>(__t2));
// }

template <class T1, class T2>
pair<T1, T2> make_pair(T1 x, T2 y)
{
    return (ft::pair<T1, T2>(x, y));
}

} // namespace ft


#endif