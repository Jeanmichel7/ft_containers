/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_set.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:33:24 by jrasser           #+#    #+#             */
/*   Updated: 2022/11/01 19:18:28 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "tester.hpp"


template <typename S1, typename S2>
void	comp_set( S1 &set, S2 &ft_set, std::string msg) {
  std::stringstream sstr;
	std::stringstream ft_sstr;

	typename S1::const_iterator it = set.begin();
	typename S2::const_iterator ft_it = ft_set.begin();

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
	display_title("SET < char >");
	tester_set_type< char >();

  display_title("SET < Int >");
	tester_set_type< int >();

	display_title("SET < string >");
	tester_set_type< std::string >();

	display_title("SET < float >");
	tester_set_type< float >();

}





#define T1 int

struct ft_more {
	bool	operator()(const T1 &first, const T1 &second) const {
		return (first > second);
	}
};


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
  typedef typename std_set_t::const_iterator          std_cit_t;
  typedef typename std_set_t::reverse_iterator        std_rit_t;
  typedef typename std_set_t::const_reverse_iterator  std_crit_t;

  typedef typename ft_set_t::iterator                 ft_it_t;
  typedef typename ft_set_t::const_iterator           ft_cit_t;
  typedef typename ft_set_t::reverse_iterator         ft_rit_t;
  typedef typename ft_set_t::const_reverse_iterator   ft_crit_t;
  








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
	/* ***************************************************** */

	// ft_set.display_tree();
	std::cout << MAG "\n\nTEST insert( value )" END << std::endl;

	std::pair< std_it_t, bool > ret_insert_value;
	ft::pair< ft_it_t, bool > 	ft_ret_insert_value;


	/* insert ("b") */
	chrono.stl_start_chrono();
	ret_insert_value 		= std_set.insert( convert<type_value>("b") );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ret_insert_value 	= ft_set.insert( convert<type_value>("b") );
	chrono.ft_end_chrono();

	str_comp(tostr(*ret_insert_value.first), tostr(*ft_ret_insert_value.first), "insert(value(ft_pair(\"b\", 2))) -> first -> first");
	str_comp(tostr(ret_insert_value.second), tostr(ft_ret_insert_value.second), "insert(value(ft_pair(\"b\", 2)))");
	chrono.diff_chrono();



	/* insert ("a") */
	chrono.stl_start_chrono();
	ret_insert_value 		= std_set.insert( convert<type_value>("a") );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ret_insert_value 	= ft_set.insert( convert<type_value>("a") );
	chrono.ft_end_chrono();

	str_comp(tostr(*ret_insert_value.first), tostr(*ft_ret_insert_value.first), "insert(value(ft_pair(\"a\", 1))) -> first -> first");
	str_comp(tostr(ret_insert_value.second), tostr(ft_ret_insert_value.second), "insert(value(ft_pair(\"a\", 1)))");
	chrono.diff_chrono();



	/* insert c */
	chrono.stl_start_chrono();
	ret_insert_value 		= std_set.insert( convert<type_value>("c") );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ret_insert_value 	= ft_set.insert( convert<type_value>("c") );
	chrono.ft_end_chrono();

	str_comp(tostr(*ret_insert_value.first), tostr(*ft_ret_insert_value.first), "insert(value(ft_pair(\"c\", 3))) -> first -> first");
	str_comp(tostr(ret_insert_value.second), tostr(ft_ret_insert_value.second), "insert(value(ft_pair(\"c\", 3)))");
	chrono.diff_chrono();



	/* insert e */
	chrono.stl_start_chrono();
	ret_insert_value 		= std_set.insert( convert<type_value>("e") );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ret_insert_value 	= ft_set.insert( convert<type_value>("e") );
	chrono.ft_end_chrono();

	str_comp(tostr(*ret_insert_value.first), tostr(*ft_ret_insert_value.first), "insert(value(ft_pair(\"e\", 5))) -> first -> first");
	str_comp(tostr(ret_insert_value.second), tostr(ft_ret_insert_value.second), "insert(value(ft_pair(\"e\", 5)))");
	chrono.diff_chrono();



	/* insert d */
	chrono.stl_start_chrono();
	ret_insert_value 		= std_set.insert( convert<type_value>("d") );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ret_insert_value 	= ft_set.insert( convert<type_value>("d") );
	chrono.ft_end_chrono();

	str_comp(tostr(*ret_insert_value.first), tostr(*ft_ret_insert_value.first), "insert(value(ft_pair(\"d\", 4))) -> first -> first");
	str_comp(tostr(ret_insert_value.second), tostr(ft_ret_insert_value.second), "insert(value(ft_pair(\"d\", 4)))");



	/* insert d  doublon*/
	chrono.stl_start_chrono();
	ret_insert_value 		= std_set.insert( convert<type_value>("d") );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ret_insert_value 	= ft_set.insert( convert<type_value>("d") );
	chrono.ft_end_chrono();

	str_comp(tostr(*ret_insert_value.first), tostr(*ft_ret_insert_value.first), "insert(value(ft_pair(\"d\", 4))) -> first -> first");
	str_comp(tostr(ret_insert_value.second), tostr(ft_ret_insert_value.second), "insert(value(ft_pair(\"d\", 4)))");
	chrono.diff_chrono();



	/* insert many value */
	chrono.stl_start_chrono();
	for (int i = 0; i < 10; i++)
		std_set.insert( convert<type_value>(tostr(i)) );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	for (int i = 0; i < 10; i++)
		ft_set.insert( convert<type_value>(tostr(i)) );
	chrono.ft_end_chrono();

	chrono.diff_chrono();
	comp_set(std_set, ft_set, "comp set - ft_set");
	std::cout << std::endl;



	// ft_set.display_tree();


	/* insert random value */
	std::string key_str;
	int 				nb_test = 20;
	int 				i = 0;

	srand (time(NULL));
	while (i < nb_test)
	{
		std::cout << "\033[1K\r";
		std::cout << "test " << i + 1 << "/" << nb_test << " " << std::flush;
		key_str = tostr(rand() % 200 + 1);

		chrono.stl_start_chrono();
		std_set.insert( convert<type_value>(key_str) );
		chrono.stl_break_chrono();

		chrono.ft_start_chrono();
		ft_set.insert( convert<type_value>(key_str) );
		chrono.ft_break_chrono();

		i++;
	}

	comp_set(std_set, ft_set, "comp set - ft_set");
	chrono.diff_addition_chrono();

















	// std::cout << MAG "TEST  " END << std::endl;


	// ft_it_t 	iter = ft_set.begin();
	// ft_cit_t citer = ft_set.end();

	// for(; iter != citer; iter++) {
	// 	std::cout << *iter << std::endl;
	// }
	

















	




	/* ***************************************************** */
	/*                  INSERT(hint, value)                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST insert( hint, value )" END << std::endl;

	std_it_t ret_std_it;
	ft_it_t  ret_ft_it;

	/* insert begin(), 01 */
	chrono.stl_start_chrono();
	ret_std_it 		= std_set.insert( std_set.begin(), convert<type_value>("01") );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ret_ft_it 		= ft_set.insert( ft_set.begin(), convert<type_value>("01") );
	chrono.ft_end_chrono();

	str_comp(tostr(*ret_std_it), tostr(*ret_ft_it), "insert(hint, value(ft_pair(\"01\", 1)))");
	chrono.diff_chrono();


	// ft_set.display_tree("insert all value");





	/* insert begin() 11*/
	chrono.stl_start_chrono();
	ret_std_it 		= std_set.insert( std_set.begin(), convert<type_value>("11") );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ret_ft_it 		= ft_set.insert( ft_set.begin(), convert<type_value>("11") );
	chrono.ft_end_chrono();

	str_comp(tostr(*ret_std_it), tostr(*ret_ft_it), "insert(hint, value(ft_pair(\"11\", 1)))");
	chrono.diff_chrono();


	// ft_set.display_tree("insert all value");





	/* insert begin() 22222*/
	chrono.stl_start_chrono();
	ret_std_it 		= std_set.insert( std_set.begin(), convert<type_value>("22222") );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ret_ft_it 		= ft_set.insert( ft_set.begin(), convert<type_value>("22222") );
	chrono.ft_end_chrono();

	str_comp(tostr(*ret_std_it), tostr(*ret_ft_it), "insert(hint, value(ft_pair(\"22222\", 1)))");
	chrono.diff_chrono();




	// ft_set.display_tree("insert all value");





	/* insert end() 12*/
	chrono.stl_start_chrono();
	ret_std_it 		= std_set.insert( std_set.end(), convert<type_value>("12") );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ret_ft_it 		= ft_set.insert( ft_set.end(), convert<type_value>("12") );
	chrono.ft_end_chrono();

	str_comp(tostr(*ret_std_it), tostr(*ret_ft_it), "insert(hint, value(ft_pair(\"12\", 1)))");
	chrono.diff_chrono();




	// ft_set.display_tree("insert all value");


	/* insert end()  */
	chrono.stl_start_chrono();
	ret_std_it 		= std_set.insert( std_set.end(), convert<type_value>("end") );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ret_ft_it 		= ft_set.insert( ft_set.end(), convert<type_value>("end") );
	chrono.ft_end_chrono();

	str_comp(tostr(*ret_std_it), tostr(*ret_ft_it), "insert(hint, value(ft_pair(\"end\", 1)))");
	chrono.diff_chrono();
	std::cout << std::endl;
	// ft_set.display_tree("insert all value");




	/* random hint */
	nb_test 	= 20;
	int 				hint 		= 0;
	std_it_t 		it_rand_hint;
	ft_it_t		 	ft_it_rand_hint;

	srand (time(NULL));
	for(int i = 0; i < nb_test; i++) {

		std::cout << "\033[1K\r";
		std::cout << "test " << i + 1 << "/" << nb_test << " " << std::flush;
		
		/* set random hint */
		it_rand_hint 		= std_set.begin();
		ft_it_rand_hint = ft_set.begin();
		hint = rand() % std_set.size();
		while (hint--)
		{
			it_rand_hint++;
			ft_it_rand_hint++;
		}

		/* set random value */
		key_str = tostr(rand() % 500 + 1);

		chrono.stl_start_chrono();
		for(int i = 0; i < nb_test; i++) {
			ret_std_it = std_set.insert( it_rand_hint, convert<type_value>(key_str) );
			sstr << tostr(*ret_std_it) << ", ";
		}
		chrono.stl_break_chrono();

		chrono.ft_start_chrono();
		for(int i = 0; i < nb_test; i++) {
			ret_ft_it = ft_set.insert( ft_it_rand_hint, convert<type_value>(key_str) );
			ft_sstr << tostr(*ret_ft_it) << ", ";
		}
		chrono.ft_break_chrono();
	}

	str_comp(sstr.str(), ft_sstr.str(), "insert(hint, value(ft_pair(\"random\", 1)))");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	chrono.diff_chrono();


	/* compare set */
	comp_set(std_set, ft_set, "compare set after insert(hint, value(ft_pair(\"random\", 1)))");

	// ft_set.display_tree("insert all value");









	/* ***************************************************** */
	/*                  INSERT(first, last)                  */
	/* ***************************************************** */

	std::cout << MAG "\n\nTEST insert( first, last )" END << std::endl;

	std_set_t std_set_insert_range;
  ft_set_t  ft_set_insert_range;





	/* insert empty range */
	chrono.stl_start_chrono();
	std_set_insert_range.insert( std_set.begin(), std_set.begin() );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set_insert_range.insert( ft_set.begin(), ft_set.begin() );
	chrono.ft_end_chrono();

	comp_set(std_set_insert_range, ft_set_insert_range, "insert empty range");
	chrono.diff_chrono();



	/* insert begin begin+3 */
	std_it_t std_it_end = std_set.begin();
	ft_it_t  ft_it_end  = ft_set.begin();
	for(int i = 0; i < 3; i++) { std_it_end++; ft_it_end++; }

	chrono.stl_start_chrono();
	std_set_insert_range.insert( std_set.begin(), std_it_end );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set_insert_range.insert( ft_set.begin(), ft_it_end );
	chrono.ft_end_chrono();

	comp_set(std_set_insert_range, ft_set_insert_range, "insert begin begin+3");
	chrono.diff_chrono();


	/* insert begin+2  begin+7 */
	std_it_t std_it_begin = std_set.begin();
	ft_it_t  ft_it_begin  = ft_set.begin();
	for(int i = 0; i < 2; i++) { std_it_begin++; ft_it_begin++; }
	std_it_end = std_set.begin();
	ft_it_end  = ft_set.begin();
	for(int i = 0; i < 7; i++) { std_it_end++; ft_it_end++; }

	chrono.stl_start_chrono();
	std_set_insert_range.insert( std_it_begin, std_it_end );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set_insert_range.insert( ft_it_begin, ft_it_end );
	chrono.ft_end_chrono();

	comp_set(std_set_insert_range, ft_set_insert_range, "insert begin+2  begin+7");
	chrono.diff_chrono();


	



	/* insert with const iterator begin - begin + 3 */

	std_cit_t	std_cit_begin = std_set.begin();
	ft_cit_t		ft_cit_begin  = ft_set.begin();

	std_cit_t	std_cit_end = std_set.begin();
	ft_cit_t		ft_cit_end  = ft_set.begin();
	for(int i = 0; i < 3; i++) { std_cit_end++; ft_cit_end++; }

	chrono.stl_start_chrono();
	std_set_insert_range.insert( std_cit_begin, std_cit_end );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set_insert_range.insert( ft_cit_begin, ft_cit_end );
	chrono.ft_end_chrono();

	comp_set(std_set_insert_range, ft_set_insert_range, "insert with const iterator begin - begin + 3");
	chrono.diff_chrono();





	/* insert with const iterator begin+2 - begin + 7 */

	std_cit_begin = std_set.begin();
	ft_cit_begin  = ft_set.begin();
	for(int i = 0; i < 2; i++) { std_cit_begin++; ft_cit_begin++; }

	std_cit_end = std_set.begin();
	ft_cit_end  = ft_set.begin();
	for(int i = 0; i < 7; i++) { std_cit_end++; ft_cit_end++; }

	chrono.stl_start_chrono();
	std_set_insert_range.insert( std_cit_begin, std_cit_end );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set_insert_range.insert( ft_cit_begin, ft_cit_end );
	chrono.ft_end_chrono();

	comp_set(std_set_insert_range, ft_set_insert_range, "insert with const iterator begin+2 - begin + 7");
	chrono.diff_chrono();




	/* insert with reverse iterator */
	chrono.stl_start_chrono();
	std_set_insert_range.insert( std_set.rbegin(), std_set.rend() );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set_insert_range.insert( ft_set.rbegin(), ft_set.rend() );
	chrono.ft_end_chrono();

	comp_set(std_set_insert_range, ft_set_insert_range, "insert with reverse iterator");
	chrono.diff_chrono();


	/* compare set */
	comp_set(std_set, ft_set, "compare set after insert(first, last)");
	comp_set(std_set_insert_range, ft_set_insert_range, "compare set after insert(first, last)");







	/* ***************************************************** */
	/*                       ITERATOR                        */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST iterator" END << std::endl;
	


	/* begin */
	std_it_t std_it_begin_set = std_set.begin();
	ft_it_t  ft_it_begin_set  = ft_set.begin();
	str_comp(tostr( *std_it_begin_set ), tostr(*ft_it_begin_set), "begin");


	/* begin + 2 */
	chrono.stl_start_chrono();
	std_it_begin_set = std_set.begin(); std_it_begin_set++; std_it_begin_set++;
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it_begin_set  = ft_set.begin(); ft_it_begin_set++; ft_it_begin_set++;
	chrono.ft_end_chrono();

	str_comp(tostr( *std_it_begin_set), tostr(*ft_it_begin_set), "begin + 2");
	chrono.diff_chrono();



	/* end -- */
	chrono.stl_start_chrono();
	std_it_t std_it_end_set = std_set.end(); std_it_end_set--;
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it_t  ft_it_end_set  = ft_set.end(); ft_it_end_set--;
	chrono.ft_end_chrono();

	str_comp(tostr( *std_it_end_set), tostr(*ft_it_end_set), "end --");
	chrono.diff_chrono();



	/* end-- x3 */
	chrono.stl_start_chrono();
	std_it_end_set = std_set.end(); std_it_end_set--; std_it_end_set--; std_it_end_set--;
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it_end_set  = ft_set.end(); ft_it_end_set--; ft_it_end_set--; ft_it_end_set--;
	chrono.ft_end_chrono();

	str_comp(tostr( *std_it_end_set), tostr(*ft_it_end_set), "end-- x3");
	chrono.diff_chrono();




	/* begin - end */
	chrono.stl_start_chrono();
	for(std_it_begin_set = std_set.begin(); std_it_begin_set != std_set.end(); std_it_begin_set++) {
		sstr << *std_it_begin_set << " ";
	}
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	for(ft_it_begin_set = ft_set.begin(); ft_it_begin_set != ft_set.end(); ft_it_begin_set++) {
		ft_sstr << *ft_it_begin_set << " ";
	}
	chrono.ft_end_chrono();

	str_comp(sstr.str(), ft_sstr.str(), "begin - end");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	chrono.diff_chrono();











	/* ***************************************************** */
	/*                    CONST_ITERATOR                     */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST const iterator" END << std::endl;



	/* const begin */
	chrono.stl_start_chrono();
	std_cit_t std_cit_begin_set = std_set.begin();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_cit_t  ft_cit_begin_set  = ft_set.begin();
	chrono.ft_end_chrono();

	str_comp(tostr( *std_cit_begin_set ), tostr(*ft_cit_begin_set), "const begin");
	chrono.diff_chrono();


	/* conversion begin -> const begin */
	std_it_t 	std_it 	= std_set.begin();
	std_cit_t std_cit = std_it;
	ft_it_t 	ft_it 	= ft_set.begin();
	ft_cit_t 	ft_cit 	= ft_it;

	str_comp(tostr( *std_cit ), tostr(*ft_cit), "conversion begin -> const begin");
	


	/* const begin + 2 */
	chrono.stl_start_chrono();
	std_cit_begin_set = std_set.begin(); std_cit_begin_set++; std_cit_begin_set++;
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_cit_begin_set  = ft_set.begin(); ft_cit_begin_set++; ft_cit_begin_set++;
	chrono.ft_end_chrono();

	str_comp(tostr( *std_cit_begin_set), tostr(*ft_cit_begin_set), "const begin + 2");
	chrono.diff_chrono();



	/* const end-- */
	chrono.stl_start_chrono();
	std_cit_t std_cit_end_set = std_set.end(); std_cit_end_set--;
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_cit_t  ft_cit_end_set  = ft_set.end(); ft_cit_end_set--;
	chrono.ft_end_chrono();

	str_comp(tostr( *std_cit_end_set), tostr(*ft_cit_end_set), "const end--");
	chrono.diff_chrono();








	/* ****************** */
	/*     CONST set      */
	/* ****************** */
	std::cout << MAG "\n\nTEST const set" END << std::endl;

	std_set_t const std_cset(std_set);
  ft_set_t  const ft_cset(ft_set);

	/* const begin */
	chrono.stl_start_chrono();
	std_cit_t std_cit_begin_cset = std_cset.begin();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_cit_t  ft_cit_begin_cset  = ft_cset.begin();
	chrono.ft_end_chrono();

	str_comp(tostr( *std_cit_begin_cset ), tostr(*ft_cit_begin_cset), "const begin");
	chrono.diff_chrono();


	/* begin -> end */
	chrono.stl_start_chrono();
	for(std_cit_begin_cset = std_cset.begin(); std_cit_begin_cset != std_cset.end(); std_cit_begin_cset++) {
		sstr << *std_cit_begin_cset << " ";
	}
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	for(ft_cit_begin_cset = ft_cset.begin(); ft_cit_begin_cset != ft_cset.end(); ft_cit_begin_cset++) {
		ft_sstr << *ft_cit_begin_cset << " ";
	}
	chrono.ft_end_chrono();

	str_comp(sstr.str(), ft_sstr.str(), "begin -> end");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	chrono.diff_chrono();

	







	/* ***************************************************** */
	/*                   REVERSE_ITERATOR                    */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST reverse iterator" END << std::endl;

	/* rbegin */
	chrono.stl_start_chrono();
	std_rit_t std_rit_begin_set = std_set.rbegin();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_rit_t  ft_rit_begin_set  = ft_set.rbegin();
	chrono.ft_end_chrono();

	str_comp(tostr( *std_rit_begin_set ), tostr(*ft_rit_begin_set), "rbegin");
	chrono.diff_chrono();


	/* rbegin ++ */
	chrono.stl_start_chrono();
	std_rit_begin_set++;
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_rit_begin_set++;
	chrono.ft_end_chrono();

	str_comp(tostr( *std_rit_begin_set ), tostr(*ft_rit_begin_set), "rbegin ++");
	chrono.diff_chrono();


	/* rend-- */
	chrono.stl_start_chrono();
	std_rit_t std_rit_end_set = std_set.rend(); std_rit_end_set--;
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_rit_t  ft_rit_end_set  = ft_set.rend(); ft_rit_end_set--;
	chrono.ft_end_chrono();

	str_comp(tostr( *std_rit_end_set), tostr(*ft_rit_end_set), "rend--");
	chrono.diff_chrono();








	/* ***************************************************** */
	/*                REVERSE_CONST_ITERATOR                 */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST const reverse iterator" END << std::endl;

	/* const rbegin */
	chrono.stl_start_chrono();
	std_crit_t std_rit_begin_cset = std_set.rbegin();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_crit_t  ft_rit_begin_cset  = ft_set.rbegin();
	chrono.ft_end_chrono();

	str_comp(tostr( *std_rit_begin_cset ), tostr(*ft_rit_begin_cset), "const rbegin");
	chrono.diff_chrono();





	/* const rbegin + 4 */
	chrono.stl_start_chrono();
	std_rit_begin_cset++; std_rit_begin_cset++; std_rit_begin_cset++; std_rit_begin_cset++;
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_rit_begin_cset++; ft_rit_begin_cset++; ft_rit_begin_cset++; ft_rit_begin_cset++;
	chrono.ft_end_chrono();

	str_comp(tostr( *std_rit_begin_cset ), tostr(*ft_rit_begin_cset), "const rbegin + 4");
	chrono.diff_chrono();




	/* const rend()-- */
	chrono.stl_start_chrono();
	std_crit_t std_rit_end_cset = std_set.rend(); std_rit_end_cset--;
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_crit_t  ft_rit_end_cset  = ft_set.rend(); ft_rit_end_cset--;
	chrono.ft_end_chrono();

	str_comp(tostr( *std_rit_end_cset), tostr(*ft_rit_end_cset), "const rend()--");
	chrono.diff_chrono();



	/* consr rbegin rend */
	chrono.stl_start_chrono();
	for(std_rit_begin_cset = std_set.rbegin(); std_rit_begin_cset != std_set.rend(); std_rit_begin_cset++) {
		sstr << *std_rit_begin_cset << " ";
	}
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	for(ft_rit_begin_cset = ft_set.rbegin(); ft_rit_begin_cset != ft_set.rend(); ft_rit_begin_cset++) {
		ft_sstr << *ft_rit_begin_cset << " ";
	}
	chrono.ft_end_chrono();

	str_comp(sstr.str(), ft_sstr.str(), "consr rbegin rend");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	chrono.diff_chrono();








	/* ****************** */
	/*     CONST set      */
	/* ****************** */

	std::cout << MAG "\n\nTEST const set" END << std::endl;

	/* const rbegin */
	chrono.stl_start_chrono();
	std_crit_t std_crit_begin_set = std_cset.rbegin();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_crit_t  ft_crit_begin_set  = ft_cset.rbegin();
	chrono.ft_end_chrono();

	str_comp(tostr( *std_crit_begin_set ), tostr(*ft_crit_begin_set), "const begin");
	chrono.diff_chrono();



	/* const rbegin + 2 */
	chrono.stl_start_chrono();
	std_crit_begin_set++; std_crit_begin_set++;
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_crit_begin_set++; ft_crit_begin_set++;
	chrono.ft_end_chrono();

	str_comp(tostr( *std_crit_begin_set ), tostr(*ft_crit_begin_set), "const begin + 2");
	chrono.diff_chrono();




	/* const rend()-- */
	chrono.stl_start_chrono();
	std_crit_t std_crit_end_set = std_cset.rend(); std_crit_end_set--;
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_crit_t  ft_crit_end_set  = ft_cset.rend(); ft_crit_end_set--;
	chrono.ft_end_chrono();

	str_comp(tostr( *std_crit_end_set), tostr(*ft_crit_end_set), "const rend()--");
	chrono.diff_chrono();




	/* consr rbegin rend */
	chrono.stl_start_chrono();
	for(std_crit_begin_set = std_cset.rbegin(); std_crit_begin_set != std_cset.rend(); std_crit_begin_set++) {
		sstr << *std_crit_begin_set << " ";
	}
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	for(ft_crit_begin_set = ft_cset.rbegin(); ft_crit_begin_set != ft_cset.rend(); ft_crit_begin_set++) {
		ft_sstr << *ft_crit_begin_set << " ";
	}
	chrono.ft_end_chrono();

	str_comp(sstr.str(), ft_sstr.str(), "consr rbegin rend");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	chrono.diff_chrono();







	/* ***************************************************** */
	/*                      find(value)                      */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST find(value)" END << std::endl;

	std_it_t std_it_find;
	ft_it_t  ft_it_find;

	/* find 1 */
	chrono.stl_start_chrono();
	std_it_find = std_set.find(convert<type_value>("1"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it_find  = ft_set.find(convert<type_value>("1"));
	chrono.ft_end_chrono();

	str_comp(tostr( *std_it_find ), tostr(*ft_it_find), "find 1");
	chrono.diff_chrono();



	/* find 2 */
	chrono.stl_start_chrono();
	std_it_find = std_set.find(convert<type_value>("2"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it_find  = ft_set.find(convert<type_value>("2"));
	chrono.ft_end_chrono();

	str_comp(tostr( *std_it_find ), tostr(*ft_it_find), "find 2");
	chrono.diff_chrono();



	// ft_set.display_tree();



	/* find "inexist "*/
	chrono.stl_start_chrono();
	std_it_find = std_set.find(convert<type_value>("inexist"));
	chrono.stl_end_chrono();
	
	chrono.ft_start_chrono();
	ft_it_find  = ft_set.find(convert<type_value>("inexist"));
	chrono.ft_end_chrono();

	if (std_it_find == std_set.end() && ft_it_find == ft_set.end())
		std::cout << GRN "[OK] " END;
	else {
		std::cout << RED "[KO] " END;
		std::cout << "\nstd: " << *std_it_find << std::endl;
		std::cout << "ft : " << *ft_it_find << std::endl << std::endl;
	}
	chrono.diff_chrono();





	/* ***************************************************** */
	/*                   const find(value)                   */
	/* ***************************************************** */


	std_cit_t std_cit_find;
	ft_cit_t  ft_cit_find;

	/* const find 1 */
	chrono.stl_start_chrono();
	std_cit_find = std_cset.find(convert<type_value>("1"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_cit_find  = ft_cset.find(convert<type_value>("1"));
	chrono.ft_end_chrono();

	str_comp(tostr( *std_cit_find ), tostr(*ft_cit_find), "const find 1");
	chrono.diff_chrono();


	/* const find 5*/
	chrono.stl_start_chrono();
	std_cit_find = std_cset.find(convert<type_value>("5"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_cit_find  = ft_cset.find(convert<type_value>("5"));
	chrono.ft_end_chrono();

	str_comp(tostr( *std_cit_find ), tostr(*ft_cit_find), "const find 5");
	chrono.diff_chrono();




	/* ***************************************************** */
	/*                       erase(pos)                      */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST erase(pos)" END << std::endl;


	/* erase 1 */
	chrono.stl_start_chrono();
	std_set.erase(std_set.begin());
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set.erase(ft_set.begin());
	chrono.ft_end_chrono();

	comp_set(std_set, ft_set, "erase 1");
	chrono.diff_chrono();



	/* erase end-- */
	chrono.stl_start_chrono();
	std_set.erase(--std_set.end());
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set.erase(--ft_set.end());
	chrono.ft_end_chrono();

	comp_set(std_set, ft_set, "erase end--");
	chrono.diff_chrono();



	// ft_set.display_tree();






	/*erase root*/
	std_it_t std_it_root = std_set.begin();
	ft_it_t  ft_it_root	 = ft_set.begin();
	while (ft_it_root._node->_parent != NULL)
	{ std_it_root++; ft_it_root++; }

	chrono.stl_start_chrono();
	std_set.erase(std_it_root);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set.erase(ft_it_root);
	chrono.ft_end_chrono();

	comp_set(std_set, ft_set, "erase root");
	chrono.diff_chrono();


	// ft_set.display_tree();



	/* erase 5 */
	chrono.stl_start_chrono();
	std_set.erase(std_set.find(convert<type_value>("5")));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set.erase(ft_set.find(convert<type_value>("5")));
	chrono.ft_end_chrono();

	comp_set(std_set, ft_set, "erase 5");
	chrono.diff_chrono();







	/* ***************************************************** */
	/*                   erase(first, last)                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST erase(first, last)" END << std::endl;

	// ft_set.display_tree();

	/* erase begin begin + 1 */
	chrono.stl_start_chrono();
	std_set.erase(std_set.begin(), ++std_set.begin());
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set.erase(ft_set.begin(), ++ft_set.begin());
	chrono.ft_end_chrono();

	comp_set(std_set, ft_set, "erase begin begin + 1");
	chrono.diff_chrono();

	// ft_set.display_tree();




	/* erase end-- end */
	chrono.stl_start_chrono();
	std_set.erase(--std_set.end(), std_set.end());
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set.erase(--ft_set.end(), ft_set.end());
	chrono.ft_end_chrono();

	comp_set(std_set, ft_set, "erase end-- end");
	chrono.diff_chrono();




	/* erase begin begin */
	chrono.stl_start_chrono();
	std_set.erase(std_set.begin(), std_set.begin());
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set.erase(ft_set.begin(), ft_set.begin());
	chrono.ft_end_chrono();

	comp_set(std_set, ft_set, "erase begin begin");
	chrono.diff_chrono();



	/* erase end end */
	chrono.stl_start_chrono();
	std_set.erase(std_set.end(), std_set.end());
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set.erase(ft_set.end(), ft_set.end());
	chrono.ft_end_chrono();

	comp_set(std_set, ft_set, "erase end end");
	chrono.diff_chrono();



	// ft_set.display_tree();


	/* erase root-2 root+2 */

	std_it_root = std_set.begin();
	ft_it_root	 = ft_set.begin();
	while (ft_it_root._node->_parent != NULL)
	{ std_it_root++; ft_it_root++; }

	std_it_begin = std_it_root;
	ft_it_begin  = ft_it_root;
	for (int i = 0; i < 2; i++) { std_it_begin--; ft_it_begin--; }

	std_it_end = std_it_root;
	ft_it_end  = ft_it_root;
	for (int i = 0; i < 2; i++) { std_it_end++; ft_it_end++; }


	chrono.stl_start_chrono();
	std_set.erase(std_it_begin, std_it_end);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set.erase(ft_it_begin, ft_it_end);
	chrono.ft_end_chrono();

	comp_set(std_set, ft_set, "erase root -2 root + 2");
	chrono.diff_chrono();








	/* ***************************************************** */
	/*                      erase(key)                       */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST erase(key)" END << std::endl;


	/* erase 2 */
	chrono.stl_start_chrono();
	std_set.erase(convert<type_value>("2"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set.erase(convert<type_value>("2"));
	chrono.ft_end_chrono();

	comp_set(std_set, ft_set, "erase 2");
	chrono.diff_chrono();



	/* erase root */
	std_it_root = std_set.begin();
	ft_it_root	 = ft_set.begin();
	while (ft_it_root._node->_parent != NULL)
	{ std_it_root++; ft_it_root++; }

	chrono.stl_start_chrono();
	std_set.erase(*std_it_root);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set.erase(*ft_it_root);
	chrono.ft_end_chrono();

	comp_set(std_set, ft_set, "erase root");
	chrono.diff_chrono();




	/* erase inexist */
	chrono.stl_start_chrono();
	std_set.erase(convert<type_value>("inexist"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set.erase(convert<type_value>("inexist"));
	chrono.ft_end_chrono();

	comp_set(std_set, ft_set, "erase inexist");
	chrono.diff_chrono();









	/* ***************************************************** */
	/*                      swap()                           */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST swap()" END << std::endl;

	/* swap empty */
	std_set_t std_set2;
	ft_set_t ft_set2;

	chrono.stl_start_chrono();
	std_set.swap(std_set2);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set.swap(ft_set2);
	chrono.ft_end_chrono();

	comp_set(std_set, ft_set, "swap empty");
	comp_set(std_set2, ft_set2, "swap empty");
	chrono.diff_chrono();


	std_set.swap(std_set2);
	ft_set.swap(ft_set2);


	/* swap not empty */
	std_set_t std_set3(std_set_insert_range);
	ft_set_t ft_set3(ft_set_insert_range);

	chrono.stl_start_chrono();
	std_set2.swap(std_set3);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set2.swap(ft_set3);
	chrono.ft_end_chrono();

	comp_set(std_set, ft_set, "swap not empty");
	comp_set(std_set2, ft_set2, "swap not empty");
	comp_set(std_set3, ft_set3, "swap not empty");
	chrono.diff_chrono();








	/* ***************************************************** */
	/*                constructor(first, last)               */
	/* ***************************************************** */

	std::cout << MAG "\n\nTEST constructor(first, last)" END << std::endl;
	// ft_set.display_tree();





	/* constructor(first, last) */
	chrono.stl_start_chrono();
	std_set_t std_set4(std_set.begin(), std_set.end());
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set_t ft_set4(ft_set.begin(), ft_set.end());
	chrono.ft_end_chrono();

	comp_set(std_set, ft_set, "constructor(first, last)");
	comp_set(std_set4, ft_set4, "constructor(first, last)");
	chrono.diff_chrono();


	/* constructor const */
	chrono.stl_start_chrono();
	std_set_t const std_set5(std_set.begin(), std_set.end());
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set_t const ft_set5(ft_set.begin(), ft_set.end());
	chrono.ft_end_chrono();

	comp_set(std_set5, ft_set5, "constructor const");
	chrono.diff_chrono();



	/* constructor empty */
	chrono.stl_start_chrono();
	std_set_t std_set6(std_set.begin(), std_set.begin());
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set_t ft_set6(ft_set.begin(), ft_set.begin());
	chrono.ft_end_chrono();

	comp_set(std_set6, ft_set6, "constructor empty");
	chrono.diff_chrono();


	/* construtor reverse it */
	chrono.stl_start_chrono();
	std_set_t std_set7(std_set.rbegin(), std_set.rend());
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set_t ft_set7(ft_set.rbegin(), ft_set.rend());
	chrono.ft_end_chrono();

	comp_set(std_set7, ft_set7, "constructor reverse it");
	chrono.diff_chrono();




	/* ***************************************************** */
	/*                   copy constructor                    */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST copy constructor" END << std::endl;

	/* copy constructor */
	chrono.stl_start_chrono();
	std_set_t std_set8(std_set);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set_t ft_set8(ft_set);
	chrono.ft_end_chrono();

	comp_set(std_set, ft_set, "copy constructor");
	comp_set(std_set8, ft_set8, "copy constructor");
	chrono.diff_chrono();


	/* check good copy */
	std_set8.insert(convert<type_value>("copy"));
	ft_set8.insert(convert<type_value>("copy"));

	comp_set(std_set, ft_set, "check good copy");
	comp_set(std_set8, ft_set8, "check good copy");








	/* ***************************************************** */
	/*                     tests empty                       */
	/* ***************************************************** */

	std::cout << MAG "\n\nTEST capacity" END << std::endl;

	bool std_empty;
	bool ft_empty;

	/* not empty */
	chrono.stl_start_chrono();
	std_empty = std_set8.empty();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_empty = ft_set8.empty();
	chrono.ft_end_chrono();

	str_comp(tostr(std_empty), tostr(ft_empty), "empty");
	comp_set(std_set8, ft_set8, "empty");
	chrono.diff_chrono();


	/*clear set8 */
	std_set8.clear();
	ft_set8.clear();

	chrono.stl_start_chrono();
	std_empty = std_set8.empty();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_empty = ft_set8.empty();
	chrono.ft_end_chrono();

	str_comp(tostr(std_empty), tostr(ft_empty), "empty");
	comp_set(std_set8, ft_set8, "empty");
	chrono.diff_chrono();

	


	/* empty */
	std_set_t std_set9;
	ft_set_t ft_set9;

	chrono.stl_start_chrono();
	std_empty = std_set9.empty();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_empty = ft_set9.empty();
	chrono.ft_end_chrono();

	str_comp(tostr(std_empty), tostr(ft_empty), "empty");
	comp_set(std_set9, ft_set9, "empty");
	chrono.diff_chrono();









	/* ***************************************************** */
	/*                      tests size                       */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	
	std::cout << MAG "\n\nTEST size - max_size" END << std::endl;

	size_t std_size;
	size_t ft_size;

	/* size set8*/
	chrono.stl_start_chrono();
	std_size = std_set8.size();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_size = ft_set8.size();
	chrono.ft_end_chrono();

	str_comp(tostr(std_size), tostr(ft_size), "size");
	chrono.diff_chrono();

	str_comp(tostr(std_set7.size()), tostr(ft_set7.size()), "size set 7");
	str_comp(tostr(std_set6.size()), tostr(ft_set6.size()), "size set 6");
	str_comp(tostr(std_set3.size()), tostr(ft_set3.size()), "size set 3");
	str_comp(tostr(std_set.size()), tostr(ft_set.size()), "size ft_set");

	

	/* max size */
	chrono.stl_start_chrono();
	std_size = std_set8.max_size();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_size = ft_set8.max_size();
	chrono.ft_end_chrono();

	str_comp(tostr(std_size), tostr(ft_size), "max size");
	chrono.diff_chrono();

	str_comp(tostr(std_set7.max_size()), tostr(ft_set7.max_size()), "max size set 7");
	str_comp(tostr(std_set6.max_size()), tostr(ft_set6.max_size()), "max size set 6");
	str_comp(tostr(std_set3.max_size()), tostr(ft_set3.max_size()), "max size set 3");
	str_comp(tostr(std_set.max_size()), tostr(ft_set.max_size()), "max size ft_set");










	/* ********************************************** */
	/*                    LOWER BOUND                 */
	/* ********************************************** */
	std::cout << MAG "\n\nTEST lower_bound()" END << std::endl;

	std_it_t 	ret_std_lb;
	ft_it_t 	ret_ft_lb;

	/* lower_bound pos before first*/
	chrono.stl_start_chrono();
	ret_std_lb = std_set.lower_bound(convert<type_value>("-10"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ret_ft_lb = ft_set.lower_bound(convert<type_value>("-10"));
	chrono.ft_end_chrono();

	str_comp(tostr(*ret_std_lb), 
	tostr(*ret_ft_lb), "lower_bound pos before first");
	chrono.diff_chrono();
	std::cout << std::endl;

	/* random */
	nb_test = 100;
	hint 		= 0;
	for(int j = 0; j < nb_test; j++) {
		std::cout << "\033[1K\r";
		std::cout << "test " << j + 1 << "/" << nb_test << " " << std::flush;

		hint = rand() % 100;
		chrono.stl_start_chrono();
		ret_std_lb = std_set.lower_bound(convert<type_value>(tostr(hint)));
		sstr << tostr(*ret_std_lb) << " ";
		chrono.stl_break_chrono();

		chrono.ft_start_chrono();
		ret_ft_lb = ft_set.lower_bound(convert<type_value>(tostr(hint)));
		ft_sstr << tostr(*ret_ft_lb) << " ";
		chrono.ft_break_chrono();
	}

	str_comp(sstr.str(), ft_sstr.str(), "lower_bound random");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	chrono.diff_addition_chrono();

	


	/* ******************* */
	/* const lower bound() */
	/* ******************* */
	std_cit_t 	ret_std_clb;
	ft_cit_t 	ret_ft_clb;

	/* lower_bound pos before first*/
	chrono.stl_start_chrono();
	ret_std_clb = std_set.lower_bound(convert<type_value>("-10"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ret_ft_clb = ft_set.lower_bound(convert<type_value>("-10"));
	chrono.ft_end_chrono();

	str_comp(tostr(*ret_std_clb), tostr(*ret_ft_clb), "const lower_bound pos before first");
	chrono.diff_chrono();
	std::cout << std::endl;



	/* random */
	nb_test = 100;
	hint 		= 0;
	for(int j = 0; j < nb_test; j++) {
		std::cout << "\033[1K\r";
		std::cout << "test const " << j + 1 << "/" << nb_test << " " << std::flush;

		hint = rand() % 100;
		chrono.stl_start_chrono();
		ret_std_clb = std_set.lower_bound(convert<type_value>(tostr(hint)));
		sstr << tostr(*ret_std_clb) << " ";
		chrono.stl_break_chrono();

		chrono.ft_start_chrono();
		ret_ft_clb = ft_set.lower_bound(convert<type_value>(tostr(hint)));
		ft_sstr << tostr(*ret_ft_clb) << " ";
		chrono.ft_break_chrono();
	}

	str_comp(sstr.str(), ft_sstr.str(), "const lower_bound random");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	chrono.diff_addition_chrono();
	




	/* ********************************************** */
	/*                    UPPER BOUND                 */
	/* ********************************************** */
	std::cout << MAG "\n\nTEST upper_bound()" END << std::endl;

	std_it_t 	ret_std_ub;
	ft_it_t 	ret_ft_ub;

	/* upper_bound pos before first*/
	chrono.stl_start_chrono();
	ret_std_ub = std_set.upper_bound(convert<type_value>("-10"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ret_ft_ub = ft_set.upper_bound(convert<type_value>("-10"));
	chrono.ft_end_chrono();

	str_comp(tostr(*ret_std_ub), tostr(*ret_ft_ub), "upper_bound pos before first");
	chrono.diff_chrono();
	std::cout << std::endl;



	/* random */
	nb_test = 100;
	hint 		= 0;
	for(int j = 0; j < nb_test; j++) {
		std::cout << "\033[1K\r";
		std::cout << "test " << j + 1 << "/" << nb_test << " " << std::flush;

		hint = rand() % 100;
		chrono.stl_start_chrono();
		ret_std_ub = std_set.upper_bound(convert<type_value>(tostr(hint)));
		sstr << tostr(*ret_std_ub) << " ";
		chrono.stl_break_chrono();

		chrono.ft_start_chrono();
		ret_ft_ub = ft_set.upper_bound(convert<type_value>(tostr(hint)));
		ft_sstr << tostr(*ret_ft_ub) << " ";
		chrono.ft_break_chrono();
	}

	str_comp(sstr.str(), ft_sstr.str(), "upper_bound random");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	chrono.diff_addition_chrono();





	/* ******************* */
	/*        C ONST       */
	/* ******************* */
	std_cit_t 	ret_std_cub;
	ft_cit_t 	ret_ft_cub;

	/* upper_bound pos before first*/
	chrono.stl_start_chrono();
	ret_std_cub = std_set.upper_bound(convert<type_value>("-10"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ret_ft_cub = ft_set.upper_bound(convert<type_value>("-10"));
	chrono.ft_end_chrono();

	str_comp(tostr(*ret_std_cub), tostr(*ret_ft_cub), "const upper_bound pos before first");
	chrono.diff_chrono();
	std::cout << std::endl;



	/* random */
	nb_test = 100;
	hint 		= 0;
	for(int j = 0; j < nb_test; j++) {
		std::cout << "\033[1K\r";
		std::cout << "test const " << j + 1 << "/" << nb_test << " " << std::flush;

		hint = rand() % 100;
		chrono.stl_start_chrono();
		ret_std_cub = std_set.upper_bound(convert<type_value>(tostr(hint)));
		sstr << tostr(*ret_std_cub) << " ";
		chrono.stl_break_chrono();

		chrono.ft_start_chrono();
		ret_ft_cub = ft_set.upper_bound(convert<type_value>(tostr(hint)));
		ft_sstr << tostr(*ret_ft_cub) << " ";
		chrono.ft_break_chrono();
	}

	str_comp(sstr.str(), ft_sstr.str(), "const upper_bound random");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	chrono.diff_addition_chrono();










	/* ********************************************** */
	/*                    EQUAL RANG                  */
	/* ********************************************** */
	std::cout << MAG "\n\nTEST equal_range()" END << std::endl;

	std::pair <std_it_t, std_it_t> 	ret_std_er;
	ft::pair <ft_it_t, ft_it_t> 		ret_ft_er;

	/* equal_range pos before first*/
	chrono.stl_start_chrono();
	ret_std_er = std_set.equal_range(convert<type_value>("-10"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ret_ft_er = ft_set.equal_range(convert<type_value>("-10"));
	chrono.ft_end_chrono();

	str_comp(tostr(*ret_std_er.first), tostr(*ret_ft_er.first), "equal_range pos before first");
	str_comp(tostr(*ret_std_er.second), tostr(*ret_ft_er.second), "equal_range pos before first");
	chrono.diff_chrono();
	std::cout << std::endl;





	/* random */
	nb_test = 100;
	hint 		= 0;
	for(int j = 0; j < nb_test; j++) {
		std::cout << "\033[1K\r";
		std::cout << "test " << j + 1 << "/" << nb_test << " " << std::flush;

		hint = rand() % 100;
		chrono.stl_start_chrono();
		ret_std_er = std_set.equal_range(convert<type_value>(tostr(hint)));
		sstr << tostr(*ret_std_er.first) << ", " << tostr(*ret_std_er.second) << " ";
		chrono.stl_break_chrono();

		chrono.ft_start_chrono();
		ret_ft_er = ft_set.equal_range(convert<type_value>(tostr(hint)));
		ft_sstr << tostr(*ret_ft_er.first) << ", " << tostr(*ret_ft_er.second) << " ";
		chrono.ft_break_chrono();
	}

	str_comp(sstr.str(), ft_sstr.str(), "equal_range random");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	chrono.diff_addition_chrono();






	/* ******************* */
	/* const equal range() */
	/* ******************* */
	std::pair <std_cit_t, std_cit_t> 	ret_std_cer;
	ft::pair <ft_cit_t, ft_cit_t> 		ret_ft_cer;

	/* equal_range pos before first*/
	chrono.stl_start_chrono();
	ret_std_cer = std_set.equal_range(convert<type_value>("-10"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ret_ft_cer = ft_set.equal_range(convert<type_value>("-10"));
	chrono.ft_end_chrono();

	str_comp(tostr(*ret_std_cer.first), tostr(*ret_ft_cer.first), "const equal_range pos before first");
	str_comp(tostr(*ret_std_cer.second), tostr(*ret_ft_cer.second), "const equal_range pos before first");
	chrono.diff_chrono();
	std::cout << std::endl;



	/* random */
	nb_test = 100;
	hint 		= 0;
	for(int j = 0; j < nb_test; j++) {
		std::cout << "\033[1K\r";
		std::cout << "test const " << j + 1 << "/" << nb_test << " " << std::flush;

		hint = rand() % 100;
		chrono.stl_start_chrono();
		ret_std_cer = std_set.equal_range(convert<type_value>(tostr(hint)));
		sstr << tostr(*ret_std_cer.first) << ", " << tostr(*ret_std_cer.second) << " ";
		chrono.stl_break_chrono();

		chrono.ft_start_chrono();
		ret_ft_cer = ft_set.equal_range(convert<type_value>(tostr(hint)));
		ft_sstr << tostr(*ret_ft_cer.first) << ", " << tostr(*ret_ft_cer.second) << " ";
		chrono.ft_break_chrono();
	}

	str_comp(sstr.str(), ft_sstr.str(), "const equal_range random");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	chrono.diff_addition_chrono();

	







	/* ***************************************************** */
	/*                      key_comp()                       */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST key_comp()" END << std::endl;

	bool ret_std_kc;
	bool ret_ft_kc;

	/* key_comp */
	chrono.stl_start_chrono();
	ret_std_kc = std_set.key_comp()(convert<type_value>("-10"), convert<type_value>("10"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ret_ft_kc = ft_set.key_comp()(convert<type_value>("-10"), convert<type_value>("10"));
	chrono.ft_end_chrono();

	str_comp(tostr(ret_std_kc), tostr(ret_ft_kc), "key_comp");
	chrono.diff_chrono();
	std::cout << std::endl;

	/* random */
	nb_test = 1000;
	int n1 	= 0;
	int n2 	= 0;
	for(int j = 0; j < nb_test; j++) {
		std::cout << "\033[1K\r";
		std::cout << "test " << j + 1 << "/" << nb_test << " " << std::flush;

		n1 = rand() % 100;
		n2 = rand() % 100;
		chrono.stl_start_chrono();
		ret_std_kc = std_set.key_comp()(
			convert<type_value>(tostr(n1)),
			convert<type_value>(tostr(n2))
		);
		sstr << tostr(ret_std_kc) << " ";
		chrono.stl_break_chrono();

		chrono.ft_start_chrono();
		ret_ft_kc = ft_set.key_comp()(
			convert<type_value>(tostr(n1)),
			convert<type_value>(tostr(n2))
		);
		ft_sstr << tostr(ret_ft_kc) << " ";
		chrono.ft_break_chrono();
	}

	str_comp(sstr.str(), ft_sstr.str(), "key_comp random");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	chrono.diff_addition_chrono();






	/* ***************************************************** */
	/*                     value_comp()                      */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST value_comp()" END << std::endl;

	bool ret_std_vc;
	bool ret_ft_vc;

	/* value_comp */
	chrono.stl_start_chrono();
	ret_std_vc = std_set.value_comp()(convert<type_value>("-10"), convert<type_value>("10"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ret_ft_vc = ft_set.value_comp()(convert<type_value>("-10"), convert<type_value>("10"));
	chrono.ft_end_chrono();

	str_comp(tostr(ret_std_vc), tostr(ret_ft_vc), "value_comp");
	chrono.diff_chrono();
	std::cout << std::endl;

	/* random */
	nb_test = 1000;
	n1 		= 0;
	n2 		= 0;
	for(int j = 0; j < nb_test; j++) {
		std::cout << "\033[1K\r";
		std::cout << "test " << j + 1 << "/" << nb_test << " " << std::flush;

		n1 = rand() % 100;
		n2 = rand() % 100;
		chrono.stl_start_chrono();
		ret_std_vc = std_set.value_comp()(
			convert<type_value>(tostr(n1)),
			convert<type_value>(tostr(n2))
		);
		sstr << tostr(ret_std_vc) << " ";
		chrono.stl_break_chrono();

		chrono.ft_start_chrono();
		ret_ft_vc = ft_set.value_comp()(
			convert<type_value>(tostr(n1)),
			convert<type_value>(tostr(n2))
		);
		ft_sstr << tostr(ret_ft_vc) << " ";
		chrono.ft_break_chrono();
	}

	str_comp(sstr.str(), ft_sstr.str(), "value_comp random");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	chrono.diff_addition_chrono();







	/* ***************************************************** */
	/*                    relational op                      */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST relational operation" END << std::endl;

	std_set_t std_set_10;
	ft_set_t 	ft_set_10;

	std_set_t std_set_11;
	ft_set_t 	ft_set_11;

	/* insert 10 random values*/
	for (int i = 0; i < 10; i++)
	{
		std::string key_str = tostr(rand() % 200 + 1);

		std_set_10.insert( convert<type_value>(key_str) );
		ft_set_10.insert( convert<type_value>(key_str) );
		std_set_11.insert( convert<type_value>(key_str) );
		ft_set_11.insert( convert<type_value>(key_str) );
	}

	// ft_set_10.display_tree("");

	/* relational op */
	str_comp(tostr(std_set_10 == std_set_11), tostr(ft_set_10 == ft_set_11), "==");
	str_comp(tostr(std_set_10 != std_set_11), tostr(ft_set_10 != ft_set_11), "!=");
	str_comp(tostr(std_set_10 < std_set_11), tostr(ft_set_10 < ft_set_11), "<");
	str_comp(tostr(std_set_10 <= std_set_11), tostr(ft_set_10 <= ft_set_11), "<=");
	str_comp(tostr(std_set_10 > std_set_11), tostr(ft_set_10 > ft_set_11), ">");
	str_comp(tostr(std_set_10 >= std_set_11), tostr(ft_set_10 >= ft_set_11), ">=");


	/* set 10 < set 11 */
	std_set_11.erase(std_set_11.begin());
	ft_set_11.erase(ft_set_11.begin());
	std_set_11.insert(std_set_11.begin(), convert<type_value>("-10"));
	ft_set_11.insert(ft_set_11.begin(), convert<type_value>("-10"));

	str_comp(tostr(std_set_10 == std_set_11), tostr(ft_set_10 == ft_set_11), "==");
	str_comp(tostr(std_set_10 != std_set_11), tostr(ft_set_10 != ft_set_11), "!=");
	str_comp(tostr(std_set_10 < std_set_11), tostr(ft_set_10 < ft_set_11), "<");
	str_comp(tostr(std_set_10 <= std_set_11), tostr(ft_set_10 <= ft_set_11), "<=");
	str_comp(tostr(std_set_10 > std_set_11), tostr(ft_set_10 > ft_set_11), ">");
	str_comp(tostr(std_set_10 >= std_set_11), tostr(ft_set_10 >= ft_set_11), ">=");
	














	/* ***************************************************** */
	/*                       clear()                         */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST clear" END << std::endl;

	/* clear */
	chrono.stl_start_chrono();
	std_set.clear();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set.clear();
	chrono.ft_end_chrono();

	str_comp(tostr(std_set.size()), tostr(ft_set.size()), "clear");
	comp_set(std_set, ft_set, "clear");
	chrono.diff_chrono();


	/* clear empty */
	std_set_t std_set_tmp;
	ft_set_t 	ft_set_tmp;

	chrono.stl_start_chrono();
	std_set.clear();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_set.clear();
	chrono.ft_end_chrono();

	str_comp(tostr(std_set.size()), tostr(ft_set.size()), "clear empty");
	comp_set(std_set, ft_set, "clear empty");
	chrono.diff_chrono();





		/* AVERAGE TIME */
	chrono.display_average();

}