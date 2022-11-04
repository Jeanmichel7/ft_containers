/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendu_main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:38:23 by jrasser           #+#    #+#             */
/*   Updated: 2022/11/04 19:56:17 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"


void display_title(std::string title) {
	std::cout << "\n\n\n\n\n"
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
	<< "/* ***************************************************** */\n" << std::endl;
}


int main()
{
  rendu_tester_vector();
	rendu_tester_map();
  return 0;
}