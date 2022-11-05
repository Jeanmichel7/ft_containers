/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendu_tester_stack.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 01:49:39 by jrasser           #+#    #+#             */
/*   Updated: 2022/11/05 02:18:53 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.hpp"


template< typename S >
void display_stack(S &std_stack) {

  S std_stack_copy = std_stack;
  while (!std_stack_copy.empty()) {
     std::cout << ' ' << std_stack_copy.top();
    std_stack_copy.pop();
  }
  std::cout << std::endl;
}


void rendu_tester_stack( void ) {
  display_title("STACK < Int >");
	rendu_tester_stack_type< int >();

  display_title("STACK < Char >");
	rendu_tester_stack_type< char >();

	display_title("STACK < String >");
	rendu_tester_stack_type< std::string >();

  display_title("STACK < Int, std::deque >");
	rendu_tester_stack_container_type< int, std::deque<int> >();

  display_title("STACK < String, std::list >");
	rendu_tester_stack_container_type< std::string, std::list<std::string> >();

  display_title("STACK < char, std::vector >");
	rendu_tester_stack_container_type< char, std::vector<char> >();
}


template< typename type_value >
void rendu_tester_stack_type() {

  typedef STL_TYPE::stack< type_value >  std_stack_t;

  std_stack_t std_stack;

  std::cout << MAG "\n\nTEST Push() " END << std::endl;
  std_stack.push(convert<type_value>("10"));
  std_stack.push(convert<type_value>("20"));
  std_stack.push(convert<type_value>("3"));
  std_stack.push(convert<type_value>("10"));
  std_stack.push(convert<type_value>("30"));
  std_stack.push(convert<type_value>("5"));
  std_stack.push(convert<type_value>("300"));
  std_stack.push(convert<type_value>("242"));


  display_stack(std_stack);

  std::cout << MAG "\n\nTEST copy + affectation() " END << std::endl;
  std_stack_t std_stack_copy(std_stack);
  std_stack_copy.push(convert<type_value>("100"));
  std_stack_copy.push(convert<type_value>("200"));
  display_stack(std_stack_copy);


  std_stack_t std_stack_copy2 = std_stack;
  display_stack(std_stack_copy2);


  std_stack_t std_stack_assign = std_stack_copy;

  std::cout << MAG "\n\nTEST Pop() " END << std::endl;
  std_stack.pop();
  display_stack(std_stack);
  std_stack.pop();
  display_stack(std_stack);


  std::cout << MAG "\n\nTEST top " END << std::endl;
  type_value std_top;
  std_top = std_stack.top();
  std::cout << "std_stack.top() = " << std_top << std::endl;


  std::cout << MAG "\n\nTEST Capacity " END << std::endl;
  bool stl_bool;
  stl_bool = std_stack.empty();
  std::cout << "std_stack.empty() = " << stl_bool << std::endl;
  


  size_t stl_size = std_stack.size();
  std::cout << "std_stack.size() = " << stl_size << std::endl;
}



template< typename type_value, class type_container >
void rendu_tester_stack_container_type() {
  typedef STL_TYPE::stack< type_value, type_container >  std_stack_t;

	std::cout << MAG "\n\nTEST constructor stack() " END << std::endl;
  std_stack_t std_stack;

  std_stack_t std_stack_container(type_container(
    3,
    convert<type_value>("10"))
  );
  display_stack(std_stack_container);



  std_stack_t std_stack_copy(std_stack_container);
  display_stack(std_stack_copy);

  std_stack_t std_stack_assign = std_stack_copy;
  display_stack(std_stack_assign);


  std::cout << MAG "\n\nTEST Push() " END << std::endl;
  std_stack.push(convert<type_value>("10"));
  std_stack.push(convert<type_value>("20"));
  std_stack.push(convert<type_value>("30"));
  display_stack(std_stack);

  std_stack.push(convert<type_value>("0"));
  std_stack.push(convert<type_value>("1"));
  std_stack.push(convert<type_value>("2"));
  display_stack(std_stack);


  std::cout << MAG "\n\nTEST Pop() " END << std::endl;
  std_stack.pop();
  display_stack(std_stack);
  std_stack.pop();
  display_stack(std_stack);


  std::cout << MAG "\n\nTEST top() " END << std::endl;
  type_value std_top;
  std_top = std_stack.top();
  std::cout << "std_stack.top() = " << std_top << std::endl;


  std::cout << MAG "\n\nTEST Capacity " END << std::endl;
  bool stl_bool;
  stl_bool = std_stack.empty();
  std::cout << "std_stack.empty() = " << stl_bool << std::endl;


  size_t stl_size = std_stack.size();
  std::cout << "std_stack.size() = " << stl_size << std::endl;


  std::cout << MAG "\n\nTEST Relational " END << std::endl;

  std_stack_t std_stack10;
  std_stack_t std_stack11;

  for (int i = 0; i < 10; i++) {
    std_stack10.push(convert<type_value>(tostr(i)));
    std_stack11.push(convert<type_value>(tostr(i)));
  }

  std::cout << "std_stack10 == std_stack11 = " << (std_stack10 == std_stack11) << std::endl;
  std::cout << "std_stack10 != std_stack11 = " << (std_stack10 != std_stack11) << std::endl;
  std::cout << "std_stack10 < std_stack11 = " << (std_stack10 < std_stack11) << std::endl;
  std::cout << "std_stack10 <= std_stack11 = " << (std_stack10 <= std_stack11) << std::endl;
  std::cout << "std_stack10 > std_stack11 = " << (std_stack10 > std_stack11) << std::endl;
  std::cout << "std_stack10 >= std_stack11 = " << (std_stack10 >= std_stack11) << std::endl;

  std_stack11.push(convert<type_value>("10"));

  std::cout << "std_stack10 == std_stack11 = " << (std_stack10 == std_stack11) << std::endl;
  std::cout << "std_stack10 != std_stack11 = " << (std_stack10 != std_stack11) << std::endl;
  std::cout << "std_stack10 < std_stack11 = " << (std_stack10 < std_stack11) << std::endl;
  std::cout << "std_stack10 <= std_stack11 = " << (std_stack10 <= std_stack11) << std::endl;
  std::cout << "std_stack10 > std_stack11 = " << (std_stack10 > std_stack11) << std::endl;
  std::cout << "std_stack10 >= std_stack11 = " << (std_stack10 >= std_stack11) << std::endl;

  std_stack11.pop();
  std_stack11.pop();

  std::cout << "std_stack10 == std_stack11 = " << (std_stack10 == std_stack11) << std::endl;
  std::cout << "std_stack10 != std_stack11 = " << (std_stack10 != std_stack11) << std::endl;
  std::cout << "std_stack10 < std_stack11 = " << (std_stack10 < std_stack11) << std::endl;
  std::cout << "std_stack10 <= std_stack11 = " << (std_stack10 <= std_stack11) << std::endl;
  std::cout << "std_stack10 > std_stack11 = " << (std_stack10 > std_stack11) << std::endl;
  std::cout << "std_stack10 >= std_stack11 = " << (std_stack10 >= std_stack11) << std::endl;
}