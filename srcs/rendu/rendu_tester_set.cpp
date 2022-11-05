/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendu_tester_set.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:18:04 by jrasser           #+#    #+#             */
/*   Updated: 2022/11/05 01:30:11 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.hpp"

template <typename S>
void display_set(S &set) {
  typename S::iterator it = set.begin();
  typename S::iterator ite = set.end();
  std::cout << "set contains:";
  while (it != ite) {
    std::cout << " " << *it;
    ++it;
  }
  std::cout << std::endl;
}

void rendu_tester_set(void)
{
	// display_title("SET < char >");
	// rendu_tester_set_type< char >();

  // display_title("SET < Int >");
	// rendu_tester_set_type< int >();

	// display_title("SET < string >");
	// rendu_tester_set_type< std::string >();

	// display_title("SET < float >");
	// rendu_tester_set_type< float >();
}


template< typename type_value >
void rendu_tester_set_type() {

  /* define type set */
  typedef STL_TYPE::set< type_value >                 std_set_t;

  /* define type iterator */
  typedef typename std_set_t::iterator                std_it_t;
  typedef typename std_set_t::const_iterator          std_cit_t;
  typedef typename std_set_t::reverse_iterator        std_rit_t;
  typedef typename std_set_t::const_reverse_iterator  std_crit_t;





	/* ***************************************************** */
	/*                                                       */
	/*                       CONSTRUCTORS                    */
	/*                                                       */
	/* ***************************************************** */

  std_set_t std_set;

	std::cout <<  "\n\nTEST insert( value )"  << std::endl;
	STL_TYPE::pair< std_it_t, bool > ret_insert_value;
	ret_insert_value 		= std_set.insert( convert<type_value>("b") );
  std::cout << "insert( b ) : " << ret_insert_value.second << std::endl;


	ret_insert_value 		= std_set.insert( convert<type_value>("a") );
  std::cout << "insert( a ) : " << ret_insert_value.second << std::endl;

	ret_insert_value 		= std_set.insert( convert<type_value>("c") );
  std::cout << "insert( c ) : " << ret_insert_value.second << std::endl;

	ret_insert_value 		= std_set.insert( convert<type_value>("e") );
  std::cout << "insert( e ) : " << ret_insert_value.second << std::endl;

	ret_insert_value 		= std_set.insert( convert<type_value>("d") );
  std::cout << "insert( d ) : " << ret_insert_value.second << std::endl;


  for (int i = 0; i < 10; i++)
		std_set.insert( convert<type_value>(tostr(i)) );

  display_set(std_set);






	std::cout <<  "\n\nTEST insert( hint, value )"  << std::endl;
	std_it_t ret_std_it;
	ret_std_it 		= std_set.insert( std_set.begin(), convert<type_value>("01") );
  std::cout << "insert( begin, 01 ) : " << *ret_std_it << std::endl;


	ret_std_it 		= std_set.insert( std_set.begin(), convert<type_value>("11") );
  std::cout << "insert( begin, 11 ) : " << *ret_std_it << std::endl;


	ret_std_it 		= std_set.insert( std_set.begin(), convert<type_value>("22222") );
  std::cout << "insert( begin, 22222 ) : " << *ret_std_it << std::endl;


	ret_std_it 		= std_set.insert( std_set.end(), convert<type_value>("12") );
  std::cout << "insert( end, 12 ) : " << *ret_std_it << std::endl;


	ret_std_it 		= std_set.insert( std_set.end(), convert<type_value>("end") );
  std::cout << "insert( end, end ) : " << *ret_std_it << std::endl;

  display_set(std_set);







	std::cout <<  "\n\nTEST insert( first, last )"  << std::endl;

	std_set_t std_set_insert_range;
	std_set_insert_range.insert( std_set.begin(), std_set.begin() );
  display_set(std_set_insert_range);


	std_it_t std_it_end = std_set.begin();
	for(int i = 0; i < 3; i++) { std_it_end++; }
	std_set_insert_range.insert( std_set.begin(), std_it_end );
  display_set(std_set_insert_range);


	std_it_t std_it_begin = std_set.begin();
	for(int i = 0; i < 2; i++) { std_it_begin++; }
	std_it_end = std_set.begin();
	for(int i = 0; i < 7; i++) { std_it_end++; }
	std_set_insert_range.insert( std_it_begin, std_it_end );
  display_set(std_set_insert_range);



	std_cit_t	std_cit_begin = std_set.begin();
	std_cit_t	std_cit_end = std_set.begin();
	for(int i = 0; i < 3; i++) { std_cit_end++; }
	std_set_insert_range.insert( std_cit_begin, std_cit_end );
  display_set(std_set_insert_range);



	std_cit_begin = std_set.begin();
	for(int i = 0; i < 2; i++) { std_cit_begin++; }
	std_cit_end = std_set.begin();
	for(int i = 0; i < 7; i++) { std_cit_end++; }
	std_set_insert_range.insert( std_cit_begin, std_cit_end );
  display_set(std_set_insert_range);


	std_set_insert_range.insert( std_set.rbegin(), std_set.rend() );
  display_set(std_set_insert_range);









	std::cout <<  "\n\nTEST iterator"  << std::endl;

	std_it_t std_it_begin_set = std_set.begin();
	std_it_begin_set = std_set.begin(); std_it_begin_set++; std_it_begin_set++;
  std::cout << "begin()++ : " << *std_it_begin_set << std::endl;

	std_it_t std_it_end_set = std_set.end(); std_it_end_set--;
  std::cout << "end()-- : " << *std_it_end_set << std::endl;

	std_it_end_set = std_set.end(); std_it_end_set--; std_it_end_set--; std_it_end_set--;
  std::cout << "end()--- : " << *std_it_end_set << std::endl;

  std::cout << "iterator : ";
	for(std_it_begin_set = std_set.begin(); std_it_begin_set != std_set.end(); std_it_begin_set++) {
    std::cout << *std_it_begin_set ;
  }
  std::cout << std::endl;





	std::cout <<  "\n\nTEST const iterator"  << std::endl;
	std_cit_t std_cit_begin_set = std_set.begin();
  std::cout << "begin() : " << *std_cit_begin_set << std::endl;

	std_it_t 	std_it 	= std_set.begin();
	std_cit_t std_cit = std_it;
	std_cit_begin_set = std_set.begin(); std_cit_begin_set++; std_cit_begin_set++;
  std::cout << "begin()++ : " << *std_cit_begin_set << std::endl;

	std_cit_t std_cit_end_set = std_set.end(); std_cit_end_set--;
  std::cout << "end()-- : " << *std_cit_end_set << std::endl;







	std::cout <<  "\n\nTEST const set"  << std::endl;

	std_set_t const std_cset(std_set);
	std_cit_t std_cit_begin_cset = std_cset.begin();
  std::cout << "begin() : " << *std_cit_begin_cset << std::endl;


  std::cout << "iterator : ";
	for(std_cit_begin_cset = std_cset.begin(); std_cit_begin_cset != std_cset.end(); std_cit_begin_cset++) {
		std::cout << *std_cit_begin_cset << " ";
	}
  std::cout << std::endl;





	std::cout <<  "\n\nTEST reverse iterator"  << std::endl;

	std_rit_t std_rit_begin_set = std_set.rbegin();
  std::cout << "rbegin() : " << *std_rit_begin_set << std::endl;

	std_rit_begin_set++;
  std::cout << "rbegin()++ : " << *std_rit_begin_set << std::endl;

	std_rit_t std_rit_end_set = std_set.rend(); std_rit_end_set--;
  std::cout << "rend()-- : " << *std_rit_end_set << std::endl;




	std::cout <<  "\n\nTEST const reverse iterator"  << std::endl;

	std_crit_t std_rit_begin_cset = std_set.rbegin();
  std::cout << "rbegin() : " << *std_rit_begin_cset << std::endl;


	std_rit_begin_cset++; std_rit_begin_cset++; std_rit_begin_cset++; std_rit_begin_cset++;
  std::cout << "rbegin()++++ : " << *std_rit_begin_cset << std::endl;

	std_crit_t std_rit_end_cset = std_set.rend(); std_rit_end_cset--;
  std::cout << "rend()-- : " << *std_rit_end_cset << std::endl;

  std::cout << "reverse iterator : ";
	for(std_rit_begin_cset = std_set.rbegin(); std_rit_begin_cset != std_set.rend(); std_rit_begin_cset++) {
		std::cout << *std_rit_begin_cset << " ";
	}
  std::cout << std::endl;





	std::cout <<  "\n\nTEST const set"  << std::endl;

	std_crit_t std_crit_begin_set = std_cset.rbegin();
  std::cout << "rbegin() : " << *std_crit_begin_set << std::endl;

	std_crit_begin_set++; std_crit_begin_set++;
  std::cout << "rbegin()++ : " << *std_crit_begin_set << std::endl;


	std_crit_begin_set++; std_crit_begin_set++;
  std::cout << "rbegin()++++ : " << *std_crit_begin_set << std::endl;


	std_crit_t std_crit_end_set = std_cset.rend(); std_crit_end_set--;
  std::cout << "rend()-- : " << *std_crit_end_set << std::endl;

  std::cout << "const reverse iterator : ";
	for(std_crit_begin_set = std_cset.rbegin(); std_crit_begin_set != std_cset.rend(); std_crit_begin_set++) {
		std::cout << *std_crit_begin_set << " ";
	}
  std::cout << std::endl;









	/* ***************************************************** */
	/*                      find(value)                      */
	/* ***************************************************** */
	std::cout <<  "\n\nTEST find(value)"  << std::endl;

	std_it_t std_it_find;
	std_it_find = std_set.find(convert<type_value>("1"));
  std::cout << "find(1) : " << *std_it_find << std::endl;


	std_it_find = std_set.find(convert<type_value>("2"));
  std::cout << "find(2) : " << *std_it_find << std::endl;

	std_it_find = std_set.find(convert<type_value>("inexist"));
  if (std_it_find == std_set.end())
    std::cout << "find(inexist) : " << "not found" << std::endl;
  else
    std::cout << "find(inexist) : " << *std_it_find << std::endl;





	std_cit_t std_cit_find;
	std_cit_find = std_cset.find(convert<type_value>("1"));
  std::cout << "find(1) : " << *std_cit_find << std::endl;


	std_cit_find = std_cset.find(convert<type_value>("5"));
  std::cout << "find(5) : " << *std_cit_find << std::endl;








	std::cout <<  "\n\nTEST erase(pos)"  << std::endl;

	std_set.erase(std_set.begin());
  display_set(std_set);

	std_set.erase(--std_set.end());
  display_set(std_set);


	std_set.erase(std_set.find(convert<type_value>("5")));
  display_set(std_set);












	std::cout <<  "\n\nTEST erase(first, last)"  << std::endl;

	std_set.erase(std_set.begin(), ++std_set.begin());
  display_set(std_set);

	std_set.erase(--std_set.end(), std_set.end());
  display_set(std_set);

	std_set.erase(std_set.begin(), std_set.begin());
  display_set(std_set);

	std_set.erase(std_set.end(), std_set.end());
  display_set(std_set);

  std_it_end = std_set.begin();
  for(int i = 0; i < 2; i++) {
    std_it_end++;
  }
  
  std_set.erase(std_set.begin(), std_it_end);
  display_set(std_set);









	std::cout <<  "\n\nTEST erase(key)"  << std::endl;

	std_set.erase(convert<type_value>("2"));
  display_set(std_set);


  std_set.erase(convert<type_value>("inexist"));
  display_set(std_set);






	std::cout <<  "\n\nTEST swap()"  << std::endl;


	std_set_t std_set2;

	std_set.swap(std_set2);
  display_set(std_set);
  display_set(std_set2);



	std_set_t std_set3(std_set_insert_range);
	std_set2.swap(std_set3);
  display_set(std_set3);
  display_set(std_set_insert_range);







	std::cout <<  "\n\nTEST constructor(first, last)"  << std::endl;

	std_set_t std_set4(std_set.begin(), std_set.end());
  display_set(std_set4);

	std_set_t const std_set5(std_set.begin(), std_set.end());
  display_set(std_set5);

	std_set_t std_set6(std_set.begin(), std_set.begin());
  display_set(std_set6);

	std_set_t std_set7(std_set.rbegin(), std_set.rend());
  display_set(std_set7);





	std::cout <<  "\n\nTEST copy constructor"  << std::endl;
	
  std_set_t std_set8(std_set);
  display_set(std_set8);

	std_set8.insert(convert<type_value>("copy"));
  display_set(std_set8);
  display_set(std_set);







	std::cout <<  "\n\nTEST capacity"  << std::endl;

	bool std_empty;
	std_empty = std_set8.empty();
  std::cout << "empty : " << std_empty << std::endl;

	std_set8.clear();
  display_set(std_set8);
  std::cout << "empty : " << std_set8.empty() << std::endl;

	std_set_t std_set9;
	std_empty = std_set9.empty();
  std::cout << "empty : " << std_empty << std::endl;









	std::cout <<  "\n\nTEST size - max_size"  << std::endl;

	size_t std_size;

	std_size = std_set8.size();
  std::cout << "size : " << std_size << std::endl;

  std::cout << "size set   : " << std_set.size() << std::endl;
  std::cout << "size set 4 : " << std_set4.size() << std::endl;
  std::cout << "size set 5 : " << std_set5.size() << std::endl;
  std::cout << "size set 7 : " << std_set7.size() << std::endl;



  std::cout << "max size : " << std_set.max_size() << std::endl;
  std::cout << "max size : " << std_set4.max_size() << std::endl;
  std::cout << "max size : " << std_set6.max_size() << std::endl;










	std::cout <<  "\n\nTEST lower_bound()"  << std::endl;

  std_set.insert(convert<type_value>("1"));
  std_set.insert(convert<type_value>("2"));
  std_set.insert(convert<type_value>("42"));
  std_set.insert(convert<type_value>("1000"));
  std_set.insert(convert<type_value>("100"));
  

	std_it_t 	ret_std_lb;
	ret_std_lb = std_set.lower_bound(convert<type_value>("-10"));
  std::cout << "lower_bound(-10) : " << *ret_std_lb << std::endl;

  ret_std_lb = std_set.lower_bound(convert<type_value>("42"));
  std::cout << "lower_bound(42) : " << *ret_std_lb << std::endl;

  ret_std_lb = std_set.lower_bound(convert<type_value>("1"));
  std::cout << "lower_bound(1) : " << *ret_std_lb << std::endl;

  ret_std_lb = std_set.lower_bound(convert<type_value>("100"));
  std::cout << "lower_bound(2) : " << *ret_std_lb << std::endl;






	std_cit_t 	ret_std_clb;
	ret_std_clb = std_set.lower_bound(convert<type_value>("-10"));
  std::cout << "lower_bound(-10) : " << *ret_std_clb << std::endl;

  ret_std_clb = std_set.lower_bound(convert<type_value>("42"));
  std::cout << "lower_bound(42) : " << *ret_std_clb << std::endl;

  ret_std_clb = std_set.lower_bound(convert<type_value>("1"));
  std::cout << "lower_bound(1) : " << *ret_std_clb << std::endl;

  ret_std_clb = std_set.lower_bound(convert<type_value>("10"));
  std::cout << "lower_bound(2) : " << *ret_std_clb << std::endl;






	std::cout <<  "\n\nTEST upper_bound()"  << std::endl;
	std_it_t 	ret_std_ub;
	ret_std_ub = std_set.upper_bound(convert<type_value>("-10"));
  std::cout << "upper_bound(-10) : " << *ret_std_ub << std::endl;

  ret_std_ub = std_set.upper_bound(convert<type_value>("42"));
  std::cout << "upper_bound(42) : " << *ret_std_ub << std::endl;

  ret_std_ub = std_set.upper_bound(convert<type_value>("1"));
  std::cout << "upper_bound(1) : " << *ret_std_ub << std::endl;

  ret_std_ub = std_set.upper_bound(convert<type_value>("10"));
  std::cout << "upper_bound(2) : " << *ret_std_ub << std::endl;


	std_cit_t 	ret_std_cub;
	ret_std_cub = std_set.upper_bound(convert<type_value>("-10"));
  std::cout << "upper_bound(-10) : " << *ret_std_cub << std::endl;

  ret_std_cub = std_set.upper_bound(convert<type_value>("42"));
  std::cout << "upper_bound(42) : " << *ret_std_cub << std::endl;

  ret_std_cub = std_set.upper_bound(convert<type_value>("1"));
  std::cout << "upper_bound(1) : " << *ret_std_cub << std::endl;

  ret_std_cub = std_set.upper_bound(convert<type_value>("10"));
  std::cout << "upper_bound(2) : " << *ret_std_cub << std::endl;











	std::cout <<  "\n\nTEST equal_range()"  << std::endl;
	STL_TYPE::pair <std_it_t, std_it_t> 	ret_std_er;
	ret_std_er = std_set.equal_range(convert<type_value>("-10"));
  std::cout << "equal_range(-10) : " << *ret_std_er.first << " " << *ret_std_er.second << std::endl;

  ret_std_er = std_set.equal_range(convert<type_value>("42"));
  std::cout << "equal_range(42) : " << *ret_std_er.first << " " << *ret_std_er.second << std::endl;

  ret_std_er = std_set.equal_range(convert<type_value>("1"));
  std::cout << "equal_range(1) : " << *ret_std_er.first << " " << *ret_std_er.second << std::endl;

  ret_std_er = std_set.equal_range(convert<type_value>("10"));
  std::cout << "equal_range(2) : " << *ret_std_er.first << " " << *ret_std_er.second << std::endl;





	STL_TYPE::pair <std_cit_t, std_cit_t> 	ret_std_cer;
	ret_std_cer = std_set.equal_range(convert<type_value>("-10"));
  std::cout << "equal_range(-10) : " << *ret_std_cer.first << " " << *ret_std_cer.second << std::endl;

  ret_std_cer = std_set.equal_range(convert<type_value>("42"));
  std::cout << "equal_range(42) : " << *ret_std_cer.first << " " << *ret_std_cer.second << std::endl;

  ret_std_cer = std_set.equal_range(convert<type_value>("1"));
  std::cout << "equal_range(1) : " << *ret_std_cer.first << " " << *ret_std_cer.second << std::endl;

  ret_std_cer = std_set.equal_range(convert<type_value>("10"));
  std::cout << "equal_range(2) : " << *ret_std_cer.first << " " << *ret_std_cer.second << std::endl;







	std::cout <<  "\n\nTEST key_comp()"  << std::endl;
	bool ret_std_kc;
	ret_std_kc = std_set.key_comp()(convert<type_value>("-10"), convert<type_value>("10"));
  std::cout << "key_comp(-10, 10) : " << ret_std_kc << std::endl;

  ret_std_kc = std_set.key_comp()(convert<type_value>("10"), convert<type_value>("-10"));
  std::cout << "key_comp(10, -10) : " << ret_std_kc << std::endl;

  ret_std_kc = std_set.key_comp()(convert<type_value>("0"), convert<type_value>("0"));
  std::cout << "key_comp(0, 0) : " << ret_std_kc << std::endl;

  ret_std_kc = std_set.key_comp()(convert<type_value>("0"), convert<type_value>("1"));
  std::cout << "key_comp(0, 1) : " << ret_std_kc << std::endl;

  ret_std_kc = std_set.key_comp()(convert<type_value>("1"), convert<type_value>("0"));
  std::cout << "key_comp(1, 0) : " << ret_std_kc << std::endl;









	std::cout <<  "\n\nTEST relational operation"  << std::endl;

	std_set_t std_set_10;
	std_set_t std_set_11;


  for (int i = 0; i < 10; i++)
	{
		std::string key_str = tostr(rand() % 200 + 1);
		std_set_10.insert( convert<type_value>(key_str) );
		std_set_11.insert( convert<type_value>(key_str) );
	}

  std::cout << "stl_it == stl_it2 : " << (std_set_10 == std_set_11) << std::endl;
  std::cout << "stl_it != stl_it2 : " << (std_set_10 != std_set_11) << std::endl;
  std::cout << "stl_it < stl_it2 : " << (std_set_10 < std_set_11) << std::endl;
  std::cout << "stl_it <= stl_it2 : " << (std_set_10 <= std_set_11) << std::endl;
  std::cout << "stl_it > stl_it2 : " << (std_set_10 > std_set_11) << std::endl;
  std::cout << "stl_it >= stl_it2 : " << (std_set_10 >= std_set_11) << std::endl;

  std_set_11.erase(std_set_11.begin());
  std_set_11.insert( convert<type_value>("1000") );
  std::cout << "stl_it == stl_it2 : " << (std_set_10 == std_set_11) << std::endl;
  std::cout << "stl_it != stl_it2 : " << (std_set_10 != std_set_11) << std::endl;
  std::cout << "stl_it < stl_it2 : " << (std_set_10 < std_set_11) << std::endl;
  std::cout << "stl_it <= stl_it2 : " << (std_set_10 <= std_set_11) << std::endl;
  std::cout << "stl_it > stl_it2 : " << (std_set_10 > std_set_11) << std::endl;
  std::cout << "stl_it >= stl_it2 : " << (std_set_10 >= std_set_11) << std::endl;










	std::cout <<  "\n\nTEST clear"  << std::endl;

	std_set.clear();
  display_set(std_set);

	std_set_t std_set_tmp;
	std_set_tmp.clear();
  display_set(std_set_tmp);

















}