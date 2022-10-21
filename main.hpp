/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:57:17 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/21 19:44:26 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAIN_HPP__
# define __MAIN_HPP__

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define BLU "\033[0;34m"
# define MAG "\033[0;35m"
# define CYA "\033[0;36m"
# define END "\033[0m"
# define BILLION 1000000000L

# include <iostream>
# include <sstream>
# include <string>

# include <map>
# include "map.hpp"
# include "chrono.hpp"





/* CHRONO */

/* VECTOR */
void tester_vector(void);

/* include vector
#include "utils.hpp"
#include "pair.hpp"

#include <vector>
#include "vector.hpp"

// #include <typeinfo>     // typeid
*/



/* MAP */
template <typename T>
std::string to_string(T value);

void str_comp(std::string str, std::string ft_str, std::string msg);

template<class T1, class T2>
void sstr_comp(T1 it, T2 ft_it, std::string msg);

template <class M1, class M2>
void	comp_map( M1 &map, M2 &ft_map, std::string msg);

template < class T_map, class T_pair>
void fill_map(T_map *map);

void tester_map(void);

#endif