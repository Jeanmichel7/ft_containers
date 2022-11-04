/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_utils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:50:43 by jrasser           #+#    #+#             */
/*   Updated: 2022/11/04 16:23:35 by jrasser          ###   ########.fr       */
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
