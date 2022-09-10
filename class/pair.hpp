/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:40:08 by jrasser           #+#    #+#             */
/*   Updated: 2022/09/10 23:28:36 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{
    
template <class T1, class T2>
struct pair 
{
    typedef T1 first_type;
    typedef T2 second_type;

    T1 first;
    T2 second;

    pair() : first(T1()), second(T2()) {}

    pair(const T1& a, const T2& b) : first(a), second(b) {}
    
    template <class U, class V>
    pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {}
    pair& operator=(const pair& pr)
    {
        first = pr.first;
        second = pr.second;
        return *this;
    }

    ~pair() {}

    // template <class T>
    // void swap (T& a, T& b)
    // {
    //     T c(a); a=b; b=c;
    // };


    void swap (pair& pr) 
    noexcept ( noexcept(swap(first,pr.first)) && noexcept(swap(second,pr.second)) ) 
    {
        std::swap(first, pr.first);
        std::swap(second, pr.second);
    }

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

    template <class T_1, class T_2>
    void swap(pair<T_1, T_2> &x, pair<T_1, T_2> &y) noexcept(noexcept(x.swap(y)))
    {
        x.swap(y);
    };
};

template <class T1, class T2>
pair<T1, T2> make_pair(T1 x, T2 y)
{
    return (pair<T1, T2>(x, y));
}


} // namespace ft


#endif