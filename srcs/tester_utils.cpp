/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_utils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:50:43 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/24 10:26:46 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void display_title(std::string title) {
	std::cout << "\n\n\n\n\n" << BLU
						<< "/* ***************************************************** */" << std::endl
						<< "/*                                                       */" << std::endl
						<< "/* ";

						for (int i = 0; i < (int)((53 - title.length()) / 2); i++)
							std::cout << " ";
						std::cout << title ;
						for (int i = 0; i < (int)((53 - title.length()) / 2); i++)
							std::cout << " ";
						std::cout << ((53 - title.length()) % 2 != 0 ? " " : "");
						std::cout << " */" << std::endl
						<< "/*                                                       */" << std::endl
						<< "/* ***************************************************** */\n" END << std::endl;
}

// template< typename T1, typename T2>
// void sstr_comp(T1 it, T2 ft_it, std::string msg) {

// 	std::stringstream sstr;
// 	std::stringstream ft_sstr;

// 	sstr << it->first << " " << it->second;
// 	ft_sstr << ft_it->first << " " << ft_it->second;
// 	str_comp(sstr.str(), ft_sstr.str(), msg);
// 	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
// }



// void str_comp(std::string str, std::string ft_str, std::string msg) {
// 	if (str.compare(ft_str) != 0)
// 	{
// 		std::cout << RED "\n[KO] " END << msg << std::endl;
		
// 		std::cout << "std::map = " << str << std::endl;
// 		std::cout << "ft::map  = " << ft_str << std::endl << std::endl;
// 	}
// 	else {
// 		std::cout << GRN "[OK] " END ;
// 		// std::cout << str << std::endl << ft_str << std::endl << msg << std::endl;
// 	}
// }