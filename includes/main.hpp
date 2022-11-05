/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:57:17 by jrasser           #+#    #+#             */
/*   Updated: 2022/11/05 01:22:35 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAIN_HPP__
# define __MAIN_HPP__


# define RED "\033[0;31m"
# define REDB "\033[31;1m"
# define GRN "\033[0;32m"
# define GRNB "\033[32;1m"
# define YEL "\033[0;33m"
# define BLU "\033[0;34m"
# define MAG "\033[0;35m"
# define CYA "\033[0;36m"
# define CYAB "\033[36;1m"
# define WHT "\033[0;37m"
# define END "\033[0m"
# define BILLION 1000000000L

# if defined(__linux__)
#  define USE_CHRONO 1
# else
#  define USE_CHRONO 0
# endif



# include <iostream>
# include <sstream>
# include <string>
# include <list>
# include <queue>

# include <vector>
# include "../class/vector.hpp"
# include <map>
# include "../class/map.hpp"
# include <stack>
# include "../class/stack.hpp"
# include <set>
# include "../class/set.hpp"

# include "../class/utils.hpp"
# include "chrono.hpp"
# include "convert.hpp"

/* ***************************************************** */
/*                        VECTOR                         */
/* ***************************************************** */
void tester_vector(void);

template< typename vector_type >
void tester_vector_type();





void rendu_tester_vector(void);

template< typename vector_type >
void rendu_tester_vector_type();




/* ***************************************************** */
/*                         MAP                           */
/* ***************************************************** */

void tester_map(void);

template< typename type_key_map, typename type_value_map >
void tester_map_type();

template< typename T1, typename T2>
void sstr_comp(T1 it, T2 ft_it, std::string msg);

template <typename M1, typename M2>
void	comp_map( M1 &map, M2 &ft_map, std::string msg);

template < typename T_map, typename T_pair, typename type_key_map, typename type_value_map>
void fill_map(T_map *map);






void rendu_tester_map( void );

template< typename type_key_map, typename type_value_map >
void rendu_tester_map_type();

template <typename M1>
void	display_map_list( M1 &map );


/* ***************************************************** */
/*                        STACK                          */
/* ***************************************************** */

void tester_stack(void);

template< typename type_value, class type_container >
void tester_stack_container_type();

template< typename type_value >
void tester_stack_type();




/* ***************************************************** */
/*                         SET                           */
/* ***************************************************** */
void tester_set(void);

template< typename type_value >
void tester_set_type();



void rendu_tester_set(void);

template< typename type_value >
void rendu_tester_set_type();

/* ***************************************************** */
/*                        UTILS                          */
/* ***************************************************** */
void display_title(std::string title);


template <typename T>
std::string to_string(T value);

void str_comp(std::string str, std::string ft_str, std::string msg);



/* ***************************************************** */
/*                       CONVERT                         */
/* ***************************************************** */

// template <typename T>
// std::string tostr(T value);

#endif