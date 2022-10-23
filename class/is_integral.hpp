/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:42:48 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/23 23:40:47 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft {

template <class T> struct is_integral           { static const bool value = false; };
template <> struct is_integral<bool>            { static const bool value = true; };
template <> struct is_integral<char>            { static const bool value = true; };
template <> struct is_integral<signed char>     { static const bool value = true; };
template <> struct is_integral<unsigned char>   { static const bool value = true; };
template <> struct is_integral<wchar_t>         { static const bool value = true; };
template <> struct is_integral<short>           { static const bool value = true; };
template <> struct is_integral<unsigned short>  { static const bool value = true; };
template <> struct is_integral<int>             { static const bool value = true; };
template <> struct is_integral<unsigned int>    { static const bool value = true; };
template <> struct is_integral<long>            { static const bool value = true; };
template <> struct is_integral<unsigned long>   { static const bool value = true; };
template <> struct is_integral<long long>       { static const bool value = true; };
template <> struct is_integral<unsigned long long> { static const bool value = true; };

}

#endif