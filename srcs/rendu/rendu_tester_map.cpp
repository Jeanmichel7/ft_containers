/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendu_tester_map.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:36:39 by jrasser           #+#    #+#             */
/*   Updated: 2022/11/04 19:46:34 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.hpp"


void rendu_tester_map( void ) {
	display_title("MAP < String, Int >");
	rendu_tester_map_type< std::string, int >();

	display_title("MAP < Int, String >");
	rendu_tester_map_type< int, std::string >();

	display_title("MAP < String, String >");
	rendu_tester_map_type< std::string, std::string >();

	display_title("MAP < Int, Int >");
	rendu_tester_map_type< int, int >();

	display_title("MAP < Int, Float >");
	rendu_tester_map_type< int, float >();
}

template< typename type_key_map, typename type_value_map >
void rendu_tester_map_type() {
  std::cout << "bloublou" << std::endl;
}