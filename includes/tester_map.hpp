/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_map.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 23:17:32 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/23 23:26:31 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_MAP_HPP
# define TESTER_MAP_HPP

#include "main.hpp"





// template< typename T1, typename T2>
// void sstr_comp(T1 it, T2 ft_it, std::string msg) {

// 	std::stringstream sstr;
// 	std::stringstream ft_sstr;

// 	sstr << it->first << " " << it->second;
// 	ft_sstr << ft_it->first << " " << ft_it->second;
// 	str_comp(sstr.str(), ft_sstr.str(), msg);
// 	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
// }


// template <typename M1, typename M2>
// void	comp_map( M1 &map, M2 &ft_map, std::string msg) {
// 	std::stringstream sstr;
// 	std::stringstream ft_sstr;

// 	typename M1::iterator it = map.begin();
// 	typename M2::iterator ft_it = ft_map.begin();

// 	for(; it != map.end(); it++) {
// 		sstr << it->first << ":" << it->second << " ";
// 	}
// 	for(; ft_it != ft_map.end(); ft_it++) {
// 		ft_sstr << ft_it->first << ":" << ft_it->second << " ";
// 	}
// 	str_comp(sstr.str(), ft_sstr.str(), msg);
// 	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
// }


// /* insert 20 values following and 20 random*/
// template < typename T_map, typename T_pair, typename type_key_map, typename type_value_map>
// void fill_map(T_map *map) {

// 	int 	i = 0;
// 	char 	c = 'a';

// 	std::string key_str = "g";
// 	std::string value_str = "1";

// 	while(i < 20) {
// 		key_str = c;
// 		value_str = c;

// 		map->insert(T_pair(
// 			convert<type_key_map>(key_str),
// 		 	convert<type_value_map>(value_str)
// 		));
// 		i++;
// 		c++;
// 	}



// 	// insert random values
// 	// i = 0;
// 	// while(i < 20) {
// 	// 	key_str = tostr(rand() % 1000);
// 	// 	value_str = tostr(rand() % 1000);

// 	// 	map->insert(T_pair(
// 	// 		convert<type_key_map>(key_str),
// 	// 	 	convert<type_value_map>(value_str)
// 	// 	));
// 	// 	i++;
// 	// }



// 	// map->insert(T_pair("g", 1));
// 	// map->insert(T_pair("h", 2));
// 	// map->insert(T_pair("i", 3));
// 	// map->insert(T_pair("j", 4));
// 	// map->insert(T_pair("k", 5));
// 	// map->insert(T_pair("l", 6));
// 	// map->insert(T_pair("m", 7));
// 	// map->insert(T_pair("n", 8));
// 	// map->insert(T_pair("o", 9));
// 	// map->insert(T_pair("p", 10));
// 	// map->insert(T_pair("q", 11));
// 	// map->insert(T_pair("r", 12));
// 	// map->insert(T_pair("s", 13));
// 	// map->insert(T_pair("t", 14));
// 	// map->insert(T_pair("u", 15));
// 	// map->insert(T_pair("v", 16));
// 	// map->insert(T_pair("w", 17));
// 	// map->insert(T_pair("x", 18));
// 	// map->insert(T_pair("y", 19));
// 	// map->insert(T_pair("aa", 1));
// 	// map->insert(T_pair("ab", 1));
// 	// map->insert(T_pair("za", 1));
// 	// map->insert(T_pair("zaa", 1));
// 	// map->insert(T_pair("zab", 1));
// 	// map->insert(T_pair("zac", 1));
// 	// map->insert(T_pair("zad", 1));
// 	// map->insert(T_pair("zae", 1));
// 	// map->insert(T_pair("zaf", 1));
// 	// map->insert(T_pair("zag", 1));
// 	// map->insert(T_pair("zah", 1));
// 	// map->insert(T_pair("zai", 1));
// 	// map->insert(T_pair("zaj", 1));
// 	// map->insert(T_pair("zak", 1));
// 	// map->insert(T_pair("zal", 1));
// 	// map->insert(T_pair("zb", 1));
// 	// map->insert(T_pair("zbq", 1));
// 	// map->insert(T_pair("zs", 1));
// 	// map->insert(T_pair("zs", 1));
// 	// map->insert(T_pair("zsa", 1));
// 	// map->insert(T_pair("zsb", 1));
// 	// map->insert(T_pair("zsc", 1));
// 	// map->insert(T_pair("zsd", 1));
// 	// map->insert(T_pair("zse", 1));
// 	// map->insert(T_pair("zsf", 1));
// 	// map->insert(T_pair("zsg", 1));
// 	// map->insert(T_pair("zsh", 1));
// 	// map->insert(T_pair("zsha", 1));
// 	// map->insert(T_pair("zshb", 1));
// 	// map->insert(T_pair("zshc", 1));
// 	// map->insert(T_pair("zshd", 1));
// 	// map->insert(T_pair("zshq", 1));
// 	// map->insert(T_pair("zshw", 1));
// 	// map->insert(T_pair("zshe", 1));
// 	// map->insert(T_pair("zshr", 1));
// 	// map->insert(T_pair("zsht", 1));
// 	// map->insert(T_pair("zshy", 1));
// 	// map->insert(T_pair("zshu", 1));
// 	// map->insert(T_pair("zshi", 1));
// 	// map->insert(T_pair("zsho", 1));
// 	// map->insert(T_pair("zshp", 1));
// 	// map->insert(T_pair("zsha", 1));
// 	// map->insert(T_pair("zshs", 1));
// 	// map->insert(T_pair("zshd", 1));
// 	// map->insert(T_pair("zshf", 1));
// 	// map->insert(T_pair("zshg", 1));
// 	// map->insert(T_pair("zshh", 1));
// 	// map->insert(T_pair("zshj", 1));
// 	// map->insert(T_pair("zshk", 1));
// 	// map->insert(T_pair("zci", 1));
// }


#endif