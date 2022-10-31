/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_set.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:33:24 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/31 20:22:49 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

template <typename M1, typename M2>
void	comp_set( M1 &set, M2 &ft_set, std::string msg) {
  std::stringstream sstr;
	std::stringstream ft_sstr;

	typename M1::const_iterator it = set.begin();
	typename M2::const_iterator ft_it = ft_set.begin();

  for(; it != set.end(); it++) {
		sstr << *it << " ";
	}
	for(; ft_it != ft_set.end(); ft_it++) {
		ft_sstr << *ft_it << " ";
	}
	str_comp(sstr.str(), ft_sstr.str(), msg);
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
}

void tester_set(void)
{
  display_title("SET < Int >");
	tester_set_type< int >();



}

template< typename type_value >
void tester_set_type() {

  std::stringstream 	sstr;
	std::stringstream 	ft_sstr;
	std::string 				str;
	std::string 				ft_str;
	struct s_time_diff 	chrono;

  /* define type set */
  typedef std::set< type_value >  std_set_t;
  typedef ft::set< type_value >   ft_set_t;

  /* define type iterator */
  typedef typename std_set_t::iterator                std_it_t;
  typedef typename std_set_t::const_iterator          std_const_it_t;
  typedef typename std_set_t::reverse_iterator        std_rev_it_t;
  typedef typename std_set_t::const_reverse_iterator  std_const_rev_it_t;

  typedef typename ft_set_t::iterator                 ft_it_t;
  typedef typename ft_set_t::const_iterator           ft_const_it_t;
  typedef typename ft_set_t::reverse_iterator         ft_rev_it_t;
  typedef typename ft_set_t::const_reverse_iterator   ft_const_rev_it_t;
  



  /* ***************************************************** */
	/*                                                       */
	/*                       CONSTRUCTORS                    */
	/*                                                       */
	/* ***************************************************** */

	std::cout << MAG "TEST constructor set() " END << std::endl;

  std_set_t std_set;
  ft_set_t  ft_set;
  comp_set(std_set, ft_set, "constructor set()");







	/* ***************************************************** */
	/*                     INSERT(value)                     */
	/*                  pair< string, int >                  */
	/* ***************************************************** */

	// ft_set.display_tree();
	std::cout << MAG "\n\nTEST insert( value )" END << std::endl;



	/* insert ("b", 2) */
	// chrono.stl_start_chrono();
	// std::pair< std_it_t, bool > ret_insert_value 		= std_set.insert( convert<type_value>("b") );
	// chrono.stl_end_chrono();

	// chrono.ft_start_chrono();
	// ft::pair< ft_it_t, bool > ft_ret_insert_value 	= ft_set.insert( convert<type_value>("b") );
	// chrono.ft_end_chrono();

	// // str_comp(tostr(ret_insert_value.first), tostr(ft_ret_insert_value.first), "insert(value(ft_pair(\"b\", 2))) -> first -> first");
	// // str_comp(tostr(ret_insert_value.first->second), tostr(ft_ret_insert_value.first->second), "insert(value(ft_pair(\"b\", 2)))  -> first-> second");
	// // str_comp(tostr(ret_insert_value.second), tostr(ft_ret_insert_value.second), "insert(value(ft_pair(\"b\", 2)))");
	// chrono.diff_chrono();






}