/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_stack.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:38:03 by jrasser           #+#    #+#             */
/*   Updated: 2022/11/05 02:11:08 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

template< typename S1, typename S2 >
void comp_stack(S1 &std_stack, S2 &ft_stack, std::string msg) {

  S1 std_stack_copy = std_stack;
  S2 ft_stack_copy = ft_stack;

	std::stringstream sstr;
	std::stringstream ft_sstr;

  while (!std_stack_copy.empty()) {
     sstr << ' ' << std_stack_copy.top();
    std_stack_copy.pop();
  }
  while (!ft_stack_copy.empty()) {
    ft_sstr << ' ' << ft_stack_copy.top();
    ft_stack_copy.pop();
  }

  str_comp(sstr.str(), ft_sstr.str(), msg);
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
}


template < typename S >
void stack_display (S &stack, std::string msg) {
  S new_stack = stack;
	std::cout << "\n--------------- " << msg << " ---------------" << std::endl;
  while (!new_stack.empty()) {
    std::cout << ' ' << new_stack.top();
    new_stack.pop();
  }
  std::cout << '\n';
}


void tester_stack(void) 
{
  display_title("STACK < Int >");
	tester_stack_type< int >();

  display_title("STACK < Char >");
	tester_stack_type< char >();

	display_title("STACK < String >");
	tester_stack_type< std::string >();

  display_title("STACK < Int, std::deque >");
	tester_stack_container_type< int, std::deque<int> >();

  display_title("STACK < String, std::list >");
	tester_stack_container_type< std::string, std::list<std::string> >();

  display_title("STACK < char, std::vector >");
	tester_stack_container_type< char, std::vector<char> >();
}





template< typename type_value >
void tester_stack_type() {

  std::stringstream 	sstr;
	std::stringstream 	ft_sstr;
	std::string 				str;
	std::string 				ft_str;
	struct s_time_diff 	chrono;

  /* define type stack */
  typedef std::stack< type_value >  std_stack_t;
  typedef ft::stack< type_value >   ft_stack_t;








	/* ***************************************************** */
	/*                       CONSTRUCTORS                    */
	/* ***************************************************** */
	std::cout <<  "\n\nTEST constructor stack() "  << std::endl;

  /* constructr default container */
  std_stack_t std_stack;
  ft_stack_t  ft_stack;
  comp_stack(std_stack, ft_stack, "stack with custom container");









  /* *************************************************** */
  /*                       PUSH                          */
  /* *************************************************** */
  std::cout <<  "\n\nTEST Push() "  << std::endl;

  /* push 10 */
  chrono.stl_start_chrono();
  std_stack.push(convert<type_value>("10"));
  chrono.stl_end_chrono();

  chrono.ft_start_chrono();
  ft_stack.push(convert<type_value>("10"));
  chrono.ft_end_chrono();

  comp_stack(std_stack, ft_stack, "push");
  chrono.diff_chrono();





  /* push 20 */
  chrono.stl_start_chrono();
  std_stack.push(convert<type_value>("20"));
  chrono.stl_end_chrono();

  chrono.ft_start_chrono();
  ft_stack.push(convert<type_value>("20"));
  chrono.ft_end_chrono();

  comp_stack(std_stack, ft_stack, "push");
  chrono.diff_chrono();




  /* push random value */
	std::string value_str;
  int 	i = 0;
	srand (time(NULL));

	while (i < 20)
	{
		value_str = tostr(rand() % 200 + 1);

		chrono.stl_start_chrono();
		std_stack.push( convert< type_value >(value_str));
		chrono.stl_end_chrono();

		chrono.ft_start_chrono();
		ft_stack.push( convert< type_value >(value_str));
		chrono.ft_end_chrono();

		comp_stack(std_stack, ft_stack, "push");
		chrono.diff_chrono();
		i++;
	}

  // stack_display(std_stack, "std_stack");
  // stack_display(ft_stack , "ft_stack");



  /* *************************************************** */
  /*                       CANONIQUE                     */
  /* *************************************************** */
  std::cout <<  "\n\nTEST copy + affectation() "  << std::endl;

  /* constructor de copy */
  chrono.stl_start_chrono();
  std_stack_t std_stack_copy(std_stack);
  chrono.stl_end_chrono();

  chrono.ft_start_chrono();
  ft_stack_t ft_stack_copy(ft_stack);
  chrono.ft_end_chrono();

  comp_stack(std_stack_copy, ft_stack_copy, "stack with custom container");
  chrono.diff_chrono();



  /* test add value*/
  chrono.stl_start_chrono();
  std_stack_copy.push(convert<type_value>("100"));
  chrono.stl_end_chrono();

  chrono.ft_start_chrono();
  ft_stack_copy.push(convert<type_value>("100"));
  chrono.ft_end_chrono();

  comp_stack(std_stack_copy, ft_stack_copy, "stack with custom container");
  chrono.diff_chrono();



  /* affectation */
  chrono.stl_start_chrono();
  std_stack_t std_stack_copy2 = std_stack;
  chrono.stl_end_chrono();

  chrono.ft_start_chrono();
  ft_stack_t ft_stack_copy2 = ft_stack;
  chrono.ft_end_chrono();

  comp_stack(std_stack_copy2, ft_stack_copy2, "stack with custom container");
  chrono.diff_chrono();

  
  
  
  /* new constructor d'affectation */
  chrono.stl_start_chrono();
  std_stack_t std_stack_assign = std_stack_copy;
  chrono.stl_end_chrono();

  chrono.ft_start_chrono();
  ft_stack_t ft_stack_assign = ft_stack_copy;
  chrono.ft_end_chrono();

  comp_stack(std_stack_assign, ft_stack_assign, "stack with custom container");
  chrono.diff_chrono();






  /* *************************************************** */
  /*                       POP                           */
  /* *************************************************** */
  std::cout <<  "\n\nTEST Pop() "  << std::endl;

  /* pop */
  chrono.stl_start_chrono();
  std_stack.pop();
  chrono.stl_end_chrono();

  chrono.ft_start_chrono();
  ft_stack.pop();
  chrono.ft_end_chrono();

  comp_stack(std_stack, ft_stack, "pop");
  chrono.diff_chrono();



  /* randon pop */
	srand (time(NULL));
  int  end = rand() % std_stack.size() /2;

  for( int i = 0; i < end; i++) {
    chrono.stl_start_chrono();
    std_stack.pop();
    chrono.stl_end_chrono();

    chrono.ft_start_chrono();
    ft_stack.pop();
    chrono.ft_end_chrono();

    comp_stack(std_stack, ft_stack, "pop");
    chrono.diff_chrono();
  }


  //   stack_display(std_stack, "std_stack");
  // stack_display(ft_stack , "ft_stack");







  /* *************************************************** */
  /*                                                     */
  /*                     ELEMENT ACCESS                  */
  /*                                                     */
  /* *************************************************** */
  std::cout <<  "\n\nTEST top "  << std::endl;

  type_value std_top;
  type_value ft_top;

  chrono.stl_start_chrono();
  std_top = std_stack.top();
  chrono.stl_end_chrono();

  chrono.ft_start_chrono();
  ft_top = ft_stack.top();
  chrono.ft_end_chrono();

  // std::cout << "std_top = " << std_top << std::endl;
  // std::cout << "ft_top = " << ft_top << std::endl;

  str_comp(tostr(std_top), tostr(ft_top), "top");
  chrono.diff_chrono();







  /* *************************************************** */
  /*                     CAPACITY                        */
  /* *************************************************** */
  std::cout <<  "\n\nTEST Capacity "  << std::endl;

  bool stl_bool;
	bool ft_bool;

  /* empty */
  chrono.stl_start_chrono();
  stl_bool = std_stack.empty();
  chrono.stl_end_chrono();

  chrono.ft_start_chrono();
  ft_bool = ft_stack.empty();
  chrono.ft_end_chrono();

  str_comp(tostr(stl_bool), tostr(ft_bool), "empty()");
  chrono.diff_chrono();


  /* size */
  chrono.stl_start_chrono();
  size_t stl_size = std_stack.size();
  chrono.stl_end_chrono();

  chrono.ft_start_chrono();
  size_t ft_size = ft_stack.size();
  chrono.ft_end_chrono();

  str_comp(tostr(stl_size), tostr(ft_size), "size()");
  chrono.diff_chrono();



  /* AVERAGE TIME */
	chrono.display_average();

}











template< typename type_value, class type_container >
void tester_stack_container_type() {

  std::stringstream 	sstr;
	std::stringstream 	ft_sstr;
	std::string 				str;
	std::string 				ft_str;
	struct s_time_diff 	chrono;

  /* define type stack */
  typedef std::stack< type_value, type_container >  std_stack_t;
  typedef ft::stack< type_value, type_container >   ft_stack_t;





	/* ***************************************************** */
	/*                       CONSTRUCTORS                    */
	/* ***************************************************** */
	std::cout <<  "\n\nTEST constructor stack() "  << std::endl;

  /* constructr default container */
  std_stack_t std_stack;
  ft_stack_t  ft_stack;
  comp_stack(std_stack, ft_stack, "stack with custom container");


  
  /* constuctor with container */
  chrono.stl_start_chrono();
  std_stack_t std_stack_container(type_container(
    3,
    convert<type_value>("10"))
  );
  chrono.stl_end_chrono();

  chrono.ft_start_chrono();
  ft_stack_t ft_stack_container(type_container(
    3,
    convert<type_value>("10"))
  );
  chrono.ft_end_chrono();

  comp_stack(std_stack_container, ft_stack_container, 
  "stack with custom container");
  chrono.diff_chrono();


  
  // stack_display(std_stack_container, "std_stack");
  // stack_display(ft_stack_container , "ft_stack");


  /* constructor de copy */
  chrono.stl_start_chrono();
  std_stack_t std_stack_copy(std_stack_container);
  chrono.stl_end_chrono();

  chrono.ft_start_chrono();
  ft_stack_t ft_stack_copy(ft_stack_container);
  chrono.ft_end_chrono();

  comp_stack(std_stack_copy, ft_stack_copy, "stack with custom container");
  chrono.diff_chrono();

  
  
  /* new onstructor d'affectation */
  chrono.stl_start_chrono();
  std_stack_t std_stack_assign = std_stack_copy;
  chrono.stl_end_chrono();

  chrono.ft_start_chrono();
  ft_stack_t ft_stack_assign = ft_stack_copy;
  chrono.ft_end_chrono();

  comp_stack(std_stack_assign, ft_stack_assign, "stack with custom container");
  chrono.diff_chrono();







  /* *************************************************** */
  /*                       PUSH                          */
  /* *************************************************** */
  std::cout <<  "\n\nTEST Push() "  << std::endl;

  /* push 10 */
  chrono.stl_start_chrono();
  std_stack.push(convert<type_value>("10"));
  chrono.stl_end_chrono();

  chrono.ft_start_chrono();
  ft_stack.push(convert<type_value>("10"));
  chrono.ft_end_chrono();

  comp_stack(std_stack, ft_stack, "push");
  chrono.diff_chrono();





  /* push 20 */
  chrono.stl_start_chrono();
  std_stack.push(convert<type_value>("20"));
  chrono.stl_end_chrono();

  chrono.ft_start_chrono();
  ft_stack.push(convert<type_value>("20"));
  chrono.ft_end_chrono();

  comp_stack(std_stack, ft_stack, "push");
  chrono.diff_chrono();




  /* push random value */
	std::string value_str;
  int 	i = 0;
	srand (time(NULL));

	while (i < 20)
	{
		value_str = tostr(rand() % 200 + 1);

		chrono.stl_start_chrono();
		std_stack.push( convert< type_value >(value_str));
		chrono.stl_end_chrono();

		chrono.ft_start_chrono();
		ft_stack.push( convert< type_value >(value_str));
		chrono.ft_end_chrono();

		comp_stack(std_stack, ft_stack, "push");
		chrono.diff_chrono();
		i++;
	}

  // stack_display(std_stack, "std_stack");
  // stack_display(ft_stack , "ft_stack");



  /* *************************************************** */
  /*                       POP                           */
  /* *************************************************** */
  std::cout <<  "\n\nTEST Pop() "  << std::endl;

  /* pop */
  chrono.stl_start_chrono();
  std_stack.pop();
  chrono.stl_end_chrono();

  chrono.ft_start_chrono();
  ft_stack.pop();
  chrono.ft_end_chrono();

  comp_stack(std_stack, ft_stack, "pop");
  chrono.diff_chrono();



  //   stack_display(std_stack, "std_stack");
  // stack_display(ft_stack , "ft_stack");


  /* randon pop */
	srand (time(NULL));
  int  end = rand() % std_stack.size() /2;

  for( int i = 0; i < end; i++) {
    chrono.stl_start_chrono();
    std_stack.pop();
    chrono.stl_end_chrono();

    chrono.ft_start_chrono();
    ft_stack.pop();
    chrono.ft_end_chrono();

    comp_stack(std_stack, ft_stack, "pop");
    chrono.diff_chrono();
  }




  /* *************************************************** */
  /*                                                     */
  /*                     ELEMENT ACCESS                  */
  /*                                                     */
  /* *************************************************** */
  std::cout <<  "\n\nTEST top() "  << std::endl;

  type_value std_top;
  type_value ft_top;

  chrono.stl_start_chrono();
  std_top = std_stack.top();
  chrono.stl_end_chrono();

  chrono.ft_start_chrono();
  ft_top = ft_stack.top();
  chrono.ft_end_chrono();

  str_comp(tostr(std_top), tostr(ft_top), "top");
  chrono.diff_chrono();







  /* *************************************************** */
  /*                     CAPACITY                        */
  /* *************************************************** */
  std::cout <<  "\n\nTEST Capacity "  << std::endl;

  bool stl_bool;
	bool ft_bool;

  /* empty */
  chrono.stl_start_chrono();
  stl_bool = std_stack.empty();
  chrono.stl_end_chrono();

  chrono.ft_start_chrono();
  ft_bool = ft_stack.empty();
  chrono.ft_end_chrono();

  str_comp(tostr(stl_bool), tostr(ft_bool), "empty()");
  chrono.diff_chrono();


  /* size */
  chrono.stl_start_chrono();
  size_t stl_size = std_stack.size();
  chrono.stl_end_chrono();

  chrono.ft_start_chrono();
  size_t ft_size = ft_stack.size();
  chrono.ft_end_chrono();

  str_comp(tostr(stl_size), tostr(ft_size), "size()");
  chrono.diff_chrono();






  /* *************************************************** */
  /*                     RELATIONAL                      */
  /* *************************************************** */
  std::cout <<  "\n\nTEST Relational "  << std::endl;

  std_stack_t std_stack10;
  ft_stack_t  ft_stack10;
  std_stack_t std_stack11;
  ft_stack_t  ft_stack11;

  /* insert 10 values */
  for (int i = 0; i < 10; i++) {
    std_stack10.push(convert<type_value>(tostr(i)));
    ft_stack10.push(convert<type_value>(tostr(i)));
    std_stack11.push(convert<type_value>(tostr(i)));
    ft_stack11.push(convert<type_value>(tostr(i)));
  }

  str_comp(tostr(std_stack10 == std_stack11), tostr(ft_stack10 == ft_stack11), "==");
  str_comp(tostr(std_stack10 != std_stack11), tostr(ft_stack10 != ft_stack11), "!=");
  str_comp(tostr(std_stack10 < std_stack11), tostr(ft_stack10 < ft_stack11), "<");
  str_comp(tostr(std_stack10 <= std_stack11), tostr(ft_stack10 <= ft_stack11), "<=");
  str_comp(tostr(std_stack10 > std_stack11), tostr(ft_stack10 > ft_stack11), ">");
  str_comp(tostr(std_stack10 >= std_stack11), tostr(ft_stack10 >= ft_stack11), ">=");

  std_stack11.push(convert<type_value>(tostr(10)));
  ft_stack11.push(convert<type_value>(tostr(10)));

  str_comp(tostr(std_stack10 == std_stack11), tostr(ft_stack10 == ft_stack11), "==");
  str_comp(tostr(std_stack10 != std_stack11), tostr(ft_stack10 != ft_stack11), "!=");
  str_comp(tostr(std_stack10 < std_stack11), tostr(ft_stack10 < ft_stack11), "<");
  str_comp(tostr(std_stack10 <= std_stack11), tostr(ft_stack10 <= ft_stack11), "<=");
  str_comp(tostr(std_stack10 > std_stack11), tostr(ft_stack10 > ft_stack11), ">");
  str_comp(tostr(std_stack10 >= std_stack11), tostr(ft_stack10 >= ft_stack11), ">=");





/* AVERAGE TIME */
	chrono.display_average();


}