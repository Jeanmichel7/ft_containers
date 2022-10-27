/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_stack.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:38:03 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/27 12:34:27 by jrasser          ###   ########.fr       */
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
	display_title("STACK < String, Container >");
	tester_stack_type< std::string >();
}

// template< typename type_value, typename type_container >
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
	std::cout << MAG "\n\nTEST constructor stack() " END << std::endl;

  /* constructr default container */
  chrono.stl_start_chrono();
  std_stack_t std_stack;
  chrono.stl_end_chrono();
  chrono.ft_start_chrono();
  ft_stack_t  ft_stack;
  chrono.ft_end_chrono();

  chrono.diff_chrono();

  // std::cout << "std_stack.size() = " << std_stack.size() << std::endl;
  // std::cout << "ft_stack.size() = " << ft_stack.size() << std::endl;


  
  /* constuctor with container */
  // std_stack_t std_stack_container(std::deque<type_value>(
  //   3,
  //   convert<type_value>("10"))
  // );

  // ft_stack_t ft_stack_container(std::deque<type_value>(
  //   3,
  //   convert<type_value>("10"))
  // );




  /* *************************************************** */
  /*                       PUSH                          */
  /* *************************************************** */
  std::cout << MAG "\n\nTEST Push() " END << std::endl;

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

  stack_display(std_stack, "std_stack");
  stack_display(ft_stack , "ft_stack");



  /* *************************************************** */
  /*                       POP                           */
  /* *************************************************** */
  std::cout << MAG "\n\nTEST Pop() " END << std::endl;

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







  /* *************************************************** */
  /*                                                     */
  /*                     ELEMENT ACCESS                  */
  /*                                                     */
  /* *************************************************** */
  std::cout << MAG "\n\nTEST top " END << std::endl;

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
  std::cout << MAG "\n\nTEST Capacity " END << std::endl;

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
  /*                     ELEMENT ACCESS                  */
  /* *************************************************** */




}