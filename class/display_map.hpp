// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   display_map.hpp                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/10/02 18:17:57 by jrasser           #+#    #+#             */
// /*   Updated: 2022/10/02 18:18:41 by jrasser          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #ifndef DISPLAY_MAP_HPP
// # define DISPLAY_MAP_HPP

// #include "utils.hpp"

// /* *************************************************** */
// /*                                                     */
// /*                      DISPLAY                        */
// /*                                                     */
// /* *************************************************** */

// 	void display_tree(std::string msg)
// 	{
// 		std::cout << "\n**********  Display tree (" << msg << ") ************\n" << std::endl;
// 		// std::cout << "len tree : " << _size << std::endl << std::endl;
// 		node_pointer current = _root;
// 		node_pointer parent = NULL;

// 		int space_root = 70;
// 		int level = 0;
// 		int node_in_line = 0;

// 		if (current == NULL)
// 			std::cout << "Tree is empty" << std::endl;
// 		else {
// 			display_tree(parent = _root, space_root, level, node_in_line);
// 		}
// 		// for(size_t i = 0; i <= _size; i++)
// 		// {
// 		// 	if (current == _root) {
// 		// 		std::cout << "			" <<current->_content << std::endl;
// 		// 		parent = current;
// 		// 	}
// 		// 	if (current->_left) {
// 		// 		std::cout << "left " << current->_content << std::endl;
// 		// 		current = current->_left;
// 		// 	}
// 		// 	else if (current->_right) {
// 		// 		std::cout << "right " << current->_content << std::endl;
// 		// 		current = current->_right;
// 		// 	}
// 		// 	// else
// 		// 	// 	break;
			
// 		// }
// 		// std::cout << "			" << _root->_content.first << " : " << _root->_content.second << std::endl;
// 	}


// 	void display_tree(node_pointer parent, int space_root, int level, int node_in_line)
// 	{
// 		if (parent == NULL)
// 			return;
// 		space_root -= 10;
		
// 		display_tree(parent->_left, space_root, level + 1, node_in_line);
// 		std::cout << std::endl;
// 		for (int i = 10; i < space_root; i++)
// 			std::cout << " ";
// 		if (parent->_color == RED)
// 			std::cout << C_RED;
// 		std::cout << parent->_content.first << " : " << parent->_content.second << std::endl;
// 		// std::cout << parent->_content.first << " : " << parent->_content.second << " c: " << parent->_color << std::endl;
// 		std::cout << END << std::endl;

// 		display_tree(parent->_right, space_root, level + 1, node_in_line);
// 	}

// #endif