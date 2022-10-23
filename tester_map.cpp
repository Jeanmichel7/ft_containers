/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_map.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:16:17 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/23 22:48:41 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

template <typename T>
std::string tostr(T value)
{
	std::ostringstream os ;
	os << value ;
	return os.str() ;
}


void str_comp(std::string str, std::string ft_str, std::string msg) {
	if (str.compare(ft_str) != 0)
	{
		std::cout << RED "\n[KO] " END << msg << std::endl;
		
		std::cout << "std::map = " << str << std::endl;
		std::cout << "ft::map  = " << ft_str << std::endl << std::endl;
	}
	else {
		std::cout << GRN "[OK] " END ;
		// std::cout << str << std::endl << ft_str << std::endl << msg << std::endl;
	}
}



template<class T1, class T2>
void sstr_comp(T1 it, T2 ft_it, std::string msg) {

	std::stringstream sstr;
	std::stringstream ft_sstr;

	sstr << it->first << " " << it->second;
	ft_sstr << ft_it->first << " " << ft_it->second;
	str_comp(sstr.str(), ft_sstr.str(), msg);
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
}



template <class M1, class M2>
void	comp_map( M1 &map, M2 &ft_map, std::string msg) {
	std::stringstream sstr;
	std::stringstream ft_sstr;

	typename M1::iterator it = map.begin();
	typename M2::iterator ft_it = ft_map.begin();

	for(; it != map.end(); it++) {
		sstr << it->first << ":" << it->second << " ";
	}
	for(; ft_it != ft_map.end(); ft_it++) {
		ft_sstr << ft_it->first << ":" << ft_it->second << " ";
	}
	str_comp(sstr.str(), ft_sstr.str(), msg);
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
}


/* insert 20 values following and 20 random*/
template < class T_map, class T_pair, typename type_key_map, typename type_value_map>
void fill_map(T_map *map) {

	int 	i = 0;
	char 	c = 'a';

	std::string key_str = "g";
	std::string value_str = "1";

	while(i < 20) {
		key_str = c;
		value_str = c;

		map->insert(T_pair(
			convert<type_key_map>(key_str),
		 	convert<type_value_map>(value_str)
		));
		i++;
		c++;
	}



	// insert random values
	// i = 0;
	// while(i < 20) {
	// 	key_str = tostr(rand() % 1000);
	// 	value_str = tostr(rand() % 1000);

	// 	map->insert(T_pair(
	// 		convert<type_key_map>(key_str),
	// 	 	convert<type_value_map>(value_str)
	// 	));
	// 	i++;
	// }



	// map->insert(T_pair("g", 1));
	// map->insert(T_pair("h", 2));
	// map->insert(T_pair("i", 3));
	// map->insert(T_pair("j", 4));
	// map->insert(T_pair("k", 5));
	// map->insert(T_pair("l", 6));
	// map->insert(T_pair("m", 7));
	// map->insert(T_pair("n", 8));
	// map->insert(T_pair("o", 9));
	// map->insert(T_pair("p", 10));
	// map->insert(T_pair("q", 11));
	// map->insert(T_pair("r", 12));
	// map->insert(T_pair("s", 13));
	// map->insert(T_pair("t", 14));
	// map->insert(T_pair("u", 15));
	// map->insert(T_pair("v", 16));
	// map->insert(T_pair("w", 17));
	// map->insert(T_pair("x", 18));
	// map->insert(T_pair("y", 19));
	// map->insert(T_pair("aa", 1));
	// map->insert(T_pair("ab", 1));
	// map->insert(T_pair("za", 1));
	// map->insert(T_pair("zaa", 1));
	// map->insert(T_pair("zab", 1));
	// map->insert(T_pair("zac", 1));
	// map->insert(T_pair("zad", 1));
	// map->insert(T_pair("zae", 1));
	// map->insert(T_pair("zaf", 1));
	// map->insert(T_pair("zag", 1));
	// map->insert(T_pair("zah", 1));
	// map->insert(T_pair("zai", 1));
	// map->insert(T_pair("zaj", 1));
	// map->insert(T_pair("zak", 1));
	// map->insert(T_pair("zal", 1));
	// map->insert(T_pair("zb", 1));
	// map->insert(T_pair("zbq", 1));
	// map->insert(T_pair("zs", 1));
	// map->insert(T_pair("zs", 1));
	// map->insert(T_pair("zsa", 1));
	// map->insert(T_pair("zsb", 1));
	// map->insert(T_pair("zsc", 1));
	// map->insert(T_pair("zsd", 1));
	// map->insert(T_pair("zse", 1));
	// map->insert(T_pair("zsf", 1));
	// map->insert(T_pair("zsg", 1));
	// map->insert(T_pair("zsh", 1));
	// map->insert(T_pair("zsha", 1));
	// map->insert(T_pair("zshb", 1));
	// map->insert(T_pair("zshc", 1));
	// map->insert(T_pair("zshd", 1));
	// map->insert(T_pair("zshq", 1));
	// map->insert(T_pair("zshw", 1));
	// map->insert(T_pair("zshe", 1));
	// map->insert(T_pair("zshr", 1));
	// map->insert(T_pair("zsht", 1));
	// map->insert(T_pair("zshy", 1));
	// map->insert(T_pair("zshu", 1));
	// map->insert(T_pair("zshi", 1));
	// map->insert(T_pair("zsho", 1));
	// map->insert(T_pair("zshp", 1));
	// map->insert(T_pair("zsha", 1));
	// map->insert(T_pair("zshs", 1));
	// map->insert(T_pair("zshd", 1));
	// map->insert(T_pair("zshf", 1));
	// map->insert(T_pair("zshg", 1));
	// map->insert(T_pair("zshh", 1));
	// map->insert(T_pair("zshj", 1));
	// map->insert(T_pair("zshk", 1));
	// map->insert(T_pair("zci", 1));
}


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

void tester_map(void)
{
	display_title("MAP < String, Int >");
	tester_map_type< std::string, int >();

	display_title("MAP < Int, String >");
	tester_map_type< int, std::string >();

	display_title("MAP < String, String >");
	tester_map_type< std::string, std::string >();

	display_title("MAP < Int, Int >");
	tester_map_type< int, int >();

	display_title("MAP < Int, Float >");
	tester_map_type< int, float >();

{
  // 	/* ***************************************************** */
  // 	/*                                                       */
  // 	/*                          MAPS                         */
  // 	/*                  std::map< int, int >                 */
  // 	/*                                                       */
  // 	/* ***************************************************** */

  // 	/* define type map */
  // 	typedef std::map<int, int>							std_map_int_int;
  // 	typedef  ft::map<int, int>							ft_map_int_int;
  
  // 	/* define type iterator */
  // 	typedef std_map_int_int::iterator 					it_type2;
  // 	typedef std_map_int_int::const_iterator 			const_it_type2;
  // 	typedef std_map_int_int::reverse_iterator 			r_it_type2;
  // 	typedef std_map_int_int::const_reverse_iterator 	const_r_it_type2;

  // 	typedef  ft_map_int_int::iterator 					ft_it_type2;
  // 	typedef  ft_map_int_int::const_iterator 			ft_const_it_type2;
  // 	typedef  ft_map_int_int::reverse_iterator 			ft_r_it_type2;
  // 	typedef  ft_map_int_int::const_reverse_iterator 	ft_const_r_it_type2;
  
  // 	/* define type pair */
  // 	typedef std::pair<int, int> 						pair2;
  // 	typedef  ft::pair<int, int> 						ft_pair2;



  // 	std::cout << BLU "\n\n\nCreate map<int, int> " END << std::endl;

  // 	std_map_int_int map2;
  // 	 ft_map_int_int ft_map2;

  // 	// std::cout << BLU "\nTEST insert(value) : " END << std::endl;
  // 	map2.insert(pair2(1, 1));
  // 	map2.insert(pair2(2, 2));
  // 	map2.insert(pair2(3, 3));
  // 	map2.insert(pair2(4, 4));
  // 	map2.insert(pair2(5, 5));

  // 	ft_map2.insert(ft_pair2(1, 1));
  // 	ft_map2.insert(ft_pair2(2, 2));
  // 	ft_map2.insert(ft_pair2(3, 3));
  // 	ft_map2.insert(ft_pair2(4, 4));
  // 	ft_map2.insert(ft_pair2(5, 5));







  // /* ***************************************************** */
  // /*                                                       */
  // /*                     pair<INT, INT>                    */
  // /*                                                       */
  // /* ***************************************************** */
  // std::cout << MAG "\n\nTEST iterator" END << std::endl;


  // 	/* ***************************************************** */
  // 	/*                       ITERATOR                        */
  // 	/*                    pair< int, int >                   */
  // 	/* ***************************************************** */
  

  // 	/* begin() */
  // 	it_type2 it2 		= map2.begin();
  // 	ft_it_type2 ft_it2 	= ft_map2.begin();
  // 	sstr_comp< it_type2, ft_it_type2 >(it2, ft_it2, "begin()");

  // 	/* end()-- */
  // 	it2 = map2.end(); it2--;
  // 	ft_it2 = ft_map2.end(); ft_it2--;
  // 	sstr_comp< it_type2, ft_it_type2 >(it2, ft_it2, "end()--");

  // 	/* end()++ */
  // 	// it2 = map2.end(); it2++;
  // 	// ft_it2 = ft_map2.end(); ft_it2++;
  // 	// sstr_comp< it_type2, ft_it_type2 >(it2, ft_it2, "end()++");

  // 																						// gerer test segfault
  // 	// it2 = map2.end(); it2++; it2++;
  // 	// ft_it2 = ft_map2.end(); ft_it2++; ft_it2++;
  // 	// sstr_comp< it_type2, ft_it_type2 >(it2, ft_it2, "end()++");

  // 	/* begin() -> end() */
  // 	for (it2 = map2.begin(); it2 != map2.end(); it2++)
  // 		sstr << it2->first << ":" << it2->second << " ";
  // 	for (ft_it2 = ft_map2.begin(); ft_it2 != ft_map2.end(); ft_it2++)
  // 		ft_sstr << ft_it2->first << ":" << ft_it2->second << " ";
  
  // 	str_comp(sstr.str(), ft_sstr.str(), "begin() -> end()");
  // 	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();






  // 	/* ***************************************************** */
  // 	/*                    REVERSE_ ITERATOR                  */
  // 	/*                    pair< int, int >                   */
  // 	/* ***************************************************** */
  

  // 	/* rbegin() */
  // 	r_it_type2 		r_it2 		= map2.rbegin();
  // 	ft_r_it_type2 	ft_r_it2 	= ft_map2.rbegin();
  // 	sstr_comp< r_it_type2, ft_r_it_type2 >(r_it2, ft_r_it2, "rbegin()");

  // 	/* rend()-- */
  // 	r_it2 		= map2.rend(); r_it2--;
  // 	ft_r_it2 	= ft_map2.rend(); ft_r_it2--;
  // 	sstr_comp< r_it_type2, ft_r_it_type2 >(r_it2, ft_r_it2, "rend()--");

  // 	/* rend()++  sur linux */
  // 	// r_it2 		= map2.rend(); r_it2++;
  // 	// ft_r_it2 	= ft_map2.rend(); ft_r_it2++;
  // 	// sstr_comp< r_it_type2, ft_r_it_type2 >(r_it2, ft_r_it2, "rend()++");

  // 	/* rbegin() -> rend() */
  // 	for (r_it2 = map2.rbegin(); r_it2 != map2.rend(); r_it2++)
  // 		sstr << r_it2->first << ":" << r_it2->second << " ";
  // 	for (ft_r_it2 = ft_map2.rbegin(); ft_r_it2 != ft_map2.rend(); ft_r_it2++)
  // 		ft_sstr << ft_r_it2->first << ":" << ft_r_it2->second << " ";

  // 	str_comp(sstr.str(), ft_sstr.str(), "rbegin() -> rend()");
  // 	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();












  // 	/* ***************************************************** */
  // 	/*                    CONST_ITERATOR                     */
  // 	/*                    pair<int, int>                     */
  // 	/* ***************************************************** */
  

  // 	/* begin() */
  // 	const_it_type2 		const_it2 		= map2.begin();
  // 	ft_const_it_type2 	const_ft_it2 	= ft_map2.begin();
  // 	sstr_comp< const_it_type2, ft_const_it_type2 >(const_it2, const_ft_it2, "const begin()");

  // 	/* end()-- */
  // 	const_it2 		= map2.end(); const_it2--;
  // 	const_ft_it2 	= ft_map2.end(); const_ft_it2--;
  // 	sstr_comp< const_it_type2, ft_const_it_type2 >(const_it2, const_ft_it2, "const end()--");

  // 	/* end()++ */
  // 	// const_it2 		= map2.end(); const_it2++;
  // 	// const_ft_it2 	= ft_map2.end(); const_ft_it2++;
  // 	// sstr_comp< const_it_type2, ft_const_it_type2 >(const_it2, const_ft_it2, "const end()++");

  // 	/* begin() -> end() */
  // 	for (const_it2 = map2.begin(); const_it2 != map2.end(); const_it2++)
  // 		sstr << const_it2->first << ":" << const_it2->second << " ";
  // 	for (const_ft_it2 = ft_map2.begin(); const_ft_it2 != ft_map2.end(); const_ft_it2++)
  // 		ft_sstr << const_ft_it2->first << ":" << const_ft_it2->second << " ";

  // 	str_comp(sstr.str(), ft_sstr.str(), "const begin() -> end()");
  // 	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();




  // 	/* ***************************************************** */
  // 	/*                CONST_REVERSE_ITERATOR                 */
  // 	/*                    pair<int, int>                     */
  // 	/* ***************************************************** */
  


  // 	/* rbegin() */
  // 	const_r_it_type2 	const_r_it2 = map2.rbegin();
  // 	ft_const_r_it_type2 const_ft_r_it2 = ft_map2.rbegin();
  // 	sstr_comp< const_r_it_type2, ft_const_r_it_type2 >(const_r_it2, const_ft_r_it2, "const rbegin()");
  
  // 	/* rend()-- */
  // 	const_r_it2 	= map2.rend(); const_r_it2--;
  // 	const_ft_r_it2	= ft_map2.rend(); const_ft_r_it2--;
  // 	sstr_comp< const_r_it_type2, ft_const_r_it_type2 >(const_r_it2, const_ft_r_it2, "const rend()--");

  // 	/* rend()++  sur linux */
  // 	// const_r_it2 	= map2.rend(); const_r_it2++;
  // 	// const_ft_r_it2 	= ft_map2.rend(); const_ft_r_it2++;
  // 	// sstr_comp< const_r_it_type2, ft_const_r_it_type2 >(const_r_it2, const_ft_r_it2, "const rend()++");

  // 	/* rbegin() -> rend() */
  // 	for (const_r_it2 = map2.rbegin(); const_r_it2 != map2.rend(); const_r_it2++)
  // 		sstr << const_r_it2->first << ":" << const_r_it2->second << " ";
  // 	for (const_ft_r_it2 = ft_map2.rbegin(); const_ft_r_it2 != ft_map2.rend(); const_ft_r_it2++)
  // 		ft_sstr << const_ft_r_it2->first << ":" << const_ft_r_it2->second << " ";
  
  // 	str_comp(sstr.str(), ft_sstr.str(), "const rbegin() -> rend()");
  // 	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
}

}



template< typename type_key_map, typename type_value_map >
void tester_map_type() {
	
	std::stringstream 	sstr;
	std::stringstream 	ft_sstr;
	std::string 				str;
	std::string 				ft_str;
	struct s_time_diff 	chrono;


	/* define type map */
	typedef std::map< type_key_map, type_value_map > 				std_map_t;
	typedef  ft::map< type_key_map, type_value_map > 				ft_map_t;

	/* define type iterator */
	typedef typename std_map_t::iterator 										it_type;
	typedef typename std_map_t::const_iterator 							const_it_type;
	typedef typename std_map_t::reverse_iterator 						r_it_type;
	typedef typename std_map_t::const_reverse_iterator 			const_r_it_type;

	typedef typename  ft_map_t::iterator 										ft_it_type;
	typedef typename  ft_map_t::const_iterator 							ft_const_it_type;
	typedef typename  ft_map_t::reverse_iterator 						ft_r_it_type;
	typedef typename  ft_map_t::const_reverse_iterator  		ft_const_r_it_type;

	/* define type pair */
	typedef std::pair< type_key_map, type_value_map > 			pair;
	typedef  ft::pair< type_key_map, type_value_map > 			ft_pair;







	/* ***************************************************** */
	/*                                                       */
	/*                       CONSTRUCTORS                    */
	/*                                                       */
	/* ***************************************************** */

	std::cout << MAG "TEST constructor map() " END << std::endl;

	chrono.stl_start_chrono();
	std_map_t map;
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map_t ft_map;
	chrono.ft_end_chrono();

	chrono.diff_chrono();







	/* ***************************************************** */
	/*                     INSERT(value)                     */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	// ft_map.display_tree();
	std::cout << MAG "\n\nTEST insert( value )" END << std::endl;



	/* insert ("b", 2) */
	chrono.stl_start_chrono();
	std::pair< it_type, bool > ret_insert_value 		= map.insert(pair(
		convert<type_key_map>("b"),
		convert<type_value_map>("2")));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft::pair< ft_it_type, bool > ft_ret_insert_value 	= ft_map.insert(ft_pair(
		convert<type_key_map>("b"),
		convert<type_value_map>("2")));
	chrono.ft_end_chrono();

	str_comp(tostr(ret_insert_value.first->first), tostr(ft_ret_insert_value.first->first), "insert(value(ft_pair(\"b\", 2))) -> first -> first");
	str_comp(tostr(ret_insert_value.first->second), tostr(ft_ret_insert_value.first->second), "insert(value(ft_pair(\"b\", 2)))  -> first-> second");
	str_comp(tostr(ret_insert_value.second), tostr(ft_ret_insert_value.second), "insert(value(ft_pair(\"b\", 2)))");
	chrono.diff_chrono();







	/* insert ("a", 1) */
	chrono.stl_start_chrono();
	ret_insert_value 	= map.insert(pair(
		convert<type_key_map>("a"),
		convert<type_value_map>("1")));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ret_insert_value = ft_map.insert(ft_pair(
		convert<type_key_map>("a"),
		convert<type_value_map>("1")));
	chrono.ft_end_chrono();

	str_comp(tostr(ret_insert_value.first->first), tostr(ft_ret_insert_value.first->first), "insert(value(ft_pair(\"a\", 1))) -> first -> first");
	// std::cout << "\ninsert(value(ft_pair(\"a\", 1))) -> first : " << ret_insert_value.first->first << " | " << ft_ret_insert_value.first->first << std::endl;
	str_comp(tostr(ret_insert_value.first->second), tostr(ft_ret_insert_value.first->second), "insert(value(ft_pair(\"a\", 1)))  -> first-> second");
	// std::cout << "\ninsert(value(ft_pair(\"a\", 1))) -> sec : " << ret_insert_value.first->second << " | " << ft_ret_insert_value.first->second << std::endl;
	str_comp(tostr(ret_insert_value.second), tostr(ft_ret_insert_value.second), "insert(value(ft_pair(\"a\", 1))) -> second");
	chrono.diff_chrono();

	





	/* insert ("c", 3) */
	chrono.stl_start_chrono();
	ret_insert_value 	= map.insert(pair(
		convert<type_key_map>("c"),
		convert<type_value_map>("3")));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ret_insert_value = ft_map.insert(ft_pair(
		convert<type_key_map>("c"),
		convert<type_value_map>("3")));
	chrono.ft_end_chrono();

	str_comp(tostr(ret_insert_value.first->first), tostr(ft_ret_insert_value.first->first), "insert(value(ft_pair(\"c\", 3))) -> first -> first");
	str_comp(tostr(ret_insert_value.first->second), tostr(ft_ret_insert_value.first->second), "insert(value(ft_pair(\"c\", 3)))  -> first-> second");
	str_comp(tostr(ret_insert_value.second), tostr(ft_ret_insert_value.second), "insert(value(ft_pair(\"c\", 3))) -> second");
	chrono.diff_chrono();






	/* insert ("e", 5) */
	chrono.stl_start_chrono();
	ret_insert_value 	= map.insert(pair(
		convert<type_key_map>("e"),
		convert<type_value_map>("5")));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ret_insert_value = ft_map.insert(ft_pair(
		convert<type_key_map>("e"),
		convert<type_value_map>("5")));
	chrono.ft_end_chrono();

	str_comp(tostr(ret_insert_value.first->first), tostr(ft_ret_insert_value.first->first), "insert(value(ft_pair(\"e\", 5))) -> first -> first");
	str_comp(tostr(ret_insert_value.first->second), tostr(ft_ret_insert_value.first->second), "insert(value(ft_pair(\"e\", 5)))  -> first-> second");
	str_comp(tostr(ret_insert_value.second), tostr(ft_ret_insert_value.second), "insert(value(ft_pair(\"e\", 5))) -> second");
	chrono.diff_chrono();








	/* insert ("d", 4) */
	chrono.stl_start_chrono();
	ret_insert_value 	= map.insert(pair(
		convert<type_key_map>("d"),
		convert<type_value_map>("4")));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ret_insert_value = ft_map.insert(ft_pair(
		convert<type_key_map>("d"),
		convert<type_value_map>("4")));
	chrono.ft_end_chrono();

	str_comp(tostr(ret_insert_value.first->first), tostr(ft_ret_insert_value.first->first), "insert(value(ft_pair(\"d\", 4))) -> first -> first");
	str_comp(tostr(ret_insert_value.first->second), tostr(ft_ret_insert_value.first->second), "insert(value(ft_pair(\"d\", 4)))  -> first-> second");
	str_comp(tostr(ret_insert_value.second), tostr(ft_ret_insert_value.second), "insert(value(ft_pair(\"d\", 4))) -> second");
	chrono.diff_chrono();






	/* insert ("d", 4) DOUBLON*/
	chrono.stl_start_chrono();
	ret_insert_value 	= map.insert(pair(
		convert<type_key_map>("d"),
		convert<type_value_map>("4")));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ret_insert_value = ft_map.insert(ft_pair(
		convert<type_key_map>("d"),
		convert<type_value_map>("4")));
	chrono.ft_end_chrono();

	str_comp(tostr(ret_insert_value.first->first), tostr(ft_ret_insert_value.first->first), "insert(value(ft_pair(\"d\", 4))) -> firs -> firstt");
	str_comp(tostr(ret_insert_value.first->second), tostr(ft_ret_insert_value.first->second), "insert(value(ft_pair(\"d\", 4))) -> first -> second");
	str_comp(tostr(ret_insert_value.second), tostr(ft_ret_insert_value.second), "insert(value(ft_pair(\"d\", 4))) -> second");
	chrono.diff_chrono();





	/* insert ("d", 10) DOUBLON*/
	chrono.stl_start_chrono();
	ret_insert_value 	= map.insert(pair(
		convert<type_key_map>("d"),
		convert<type_value_map>("10")));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ret_insert_value = ft_map.insert(ft_pair(
		convert<type_key_map>("d"),
		convert<type_value_map>("10")));
	chrono.ft_end_chrono();

	str_comp(tostr(ret_insert_value.first->first), tostr(ft_ret_insert_value.first->first), "insert(value(ft_pair(\"d\", 10))) -> first -> first");
	str_comp(tostr(ret_insert_value.first->second), tostr(ft_ret_insert_value.first->second), "insert(value(ft_pair(\"d\", 10)))  -> first -> second");
	str_comp(tostr(ret_insert_value.second), tostr(ft_ret_insert_value.second), "insert(value(ft_pair(\"d\", 10))) -> second");
	chrono.diff_chrono();







	/* insert many value */
	chrono.stl_start_chrono();
	fill_map< std_map_t, pair, type_key_map, type_value_map >(&map);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	fill_map< ft_map_t, ft_pair, type_key_map, type_value_map >(&ft_map);
	chrono.ft_end_chrono();

	comp_map(map, ft_map, "comp map - ft_map");
	chrono.diff_chrono();





	/* insert random value */
	std::string key_str;
	std::string value_str;
	int 	i = 0;
	srand (time(NULL));

	while (i < 10)
	{
		key_str = tostr(rand() % 200 + 1);
		value_str = tostr(rand() % 200 + 1);

		chrono.stl_start_chrono();
		map.insert(pair(
			convert<type_key_map>(key_str),
			convert<type_value_map>(value_str)));
		chrono.stl_end_chrono();

		chrono.ft_start_chrono();
		ft_map.insert(ft_pair(
			convert<type_key_map>(key_str),
			convert<type_value_map>(value_str)));
		chrono.ft_end_chrono();

		comp_map(map, ft_map, "comp map - ft_map");
		chrono.diff_chrono();
		i++;
	}






	// ft_map.display_tree("insert all value");






	/* ***************************************************** */
	/*                  INSERT(hint, value)                  */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST insert( hint, value )" END << std::endl;


	/* insert(begin(), 1) */
	chrono.stl_start_chrono();
	it_type it_insert_hint = map.insert(
		map.begin(),
		pair(
			convert<type_key_map>("A"),
			convert<type_value_map>("1")
		)
	);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it_type ft_it_insert_hint = ft_map.insert(
		ft_map.begin(),
		ft_pair(
			convert<type_key_map>("A"),
			convert<type_value_map>("1")
		)
	);
	chrono.ft_end_chrono();

	str_comp(tostr(it_insert_hint->first), tostr(ft_it_insert_hint->first), "insert(begin(), value(ft_pair(\"A\", 1))) -> first");
	str_comp(tostr(it_insert_hint->second), tostr(ft_it_insert_hint->second), "insert(begin(), value(ft_pair(\"A\", 1))) -> second");
	chrono.diff_chrono();
	// ft_map.display_tree("insert begin");



	/* insert(begin(), 1) */
	chrono.stl_start_chrono();
	it_insert_hint = map.insert(
		map.begin(),
		pair(
			convert<type_key_map>("AA"),
			convert<type_value_map>("10")
		)
	);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it_insert_hint = ft_map.insert(
		ft_map.begin(),
		ft_pair(
			convert<type_key_map>("AA"),
			convert<type_value_map>("10")
		)
	);
	chrono.ft_end_chrono();

	str_comp(tostr(it_insert_hint->first), tostr(ft_it_insert_hint->first), "insert(begin(), value(ft_pair(\"AA\", 10))) -> first");
	str_comp(tostr(it_insert_hint->second), tostr(ft_it_insert_hint->second), "insert(begin(), value(ft_pair(\"AA\", 10))) -> second");
	chrono.diff_chrono();






	/* insert(begin(), "z") */
	chrono.stl_start_chrono();
	it_insert_hint = map.insert(
		map.begin(),
		pair(
			convert<type_key_map>("z"),
			convert<type_value_map>("1")
		)
	);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it_insert_hint = ft_map.insert(
		ft_map.begin(),
		ft_pair(
			convert<type_key_map>("z"),
			convert<type_value_map>("1")
		)
	);
	chrono.ft_end_chrono();

	str_comp(tostr(it_insert_hint->first), tostr(ft_it_insert_hint->first), "insert(begin(), value(ft_pair(\"z\", 1))) -> first");
	str_comp(tostr(it_insert_hint->second), tostr(ft_it_insert_hint->second), "insert(begin(), value(ft_pair(\"z\", 1))) -> second");
	chrono.diff_chrono();





	/* insert(end(), 1) */
	chrono.stl_start_chrono();
	it_insert_hint = map.insert(
		map.end(),
		pair(
			convert<type_key_map>("z"),
			convert<type_value_map>("1")
		)
	);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it_insert_hint = ft_map.insert(
		ft_map.end(),
		ft_pair(
			convert<type_key_map>("z"),
			convert<type_value_map>("1")
		)
	);
	chrono.ft_end_chrono();

	str_comp(tostr(it_insert_hint->first), tostr(ft_it_insert_hint->first), "insert(end(), value(ft_pair(\"z\", 1))) -> first");
	str_comp(tostr(it_insert_hint->second), tostr(ft_it_insert_hint->second), "insert(end(), value(ft_pair(\"z\", 1))) -> second");
	chrono.diff_chrono();






	/* insert(end(), "za") */
	chrono.stl_start_chrono();
	it_insert_hint = map.insert(
		map.end(),
		pair(
			convert<type_key_map>("za"),
			convert<type_value_map>("1")
		)
	);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it_insert_hint = ft_map.insert(
		ft_map.end(),
		ft_pair(
			convert<type_key_map>("za"),
			convert<type_value_map>("1")
		)
	);
	chrono.ft_end_chrono();

	str_comp(tostr(it_insert_hint->first), tostr(ft_it_insert_hint->first), "insert(end(), value(ft_pair(\"za\", 1))) -> first");
	str_comp(tostr(it_insert_hint->second), tostr(ft_it_insert_hint->second), "insert(end(), value(ft_pair(\"za\", 1))) -> second");
	chrono.diff_chrono();








	/* insert(end(), "c") */
	chrono.stl_start_chrono();
	it_insert_hint = map.insert(
		map.end(),
		pair(
			convert<type_key_map>("c"),
			convert<type_value_map>("1")
		)
	);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it_insert_hint = ft_map.insert(
		ft_map.end(),
		ft_pair(
			convert<type_key_map>("c"),
			convert<type_value_map>("1")
		)
	);
	chrono.ft_end_chrono();

	str_comp(tostr(it_insert_hint->first), tostr(ft_it_insert_hint->first), "insert(end(), value(ft_pair(\"c\", 1))) -> first");
	str_comp(tostr(it_insert_hint->second), tostr(ft_it_insert_hint->second), "insert(end(), value(ft_pair(\"c\", 1))) -> second");
	chrono.diff_chrono();



	// ft_map.display_tree();



	/* insert begin()+5, "ee" hint not good*/
	// std::string key_to_insert = "ee";
	// int 		pos_to_insert = 17;
	// int			value_to_insert = 42;


	// it_type 		it_hint 		= map.begin();
	// ft_it_type 	ft_it_hint 	= ft_map.begin();
	// for(int i = 0; i < pos_to_insert; i++) { it_hint++; ft_it_hint++; }

	// std::cout << "hint : " << it_hint->first << std::endl;
	// std::cout << "ft_hint : " << ft_it_hint->first << std::endl;
	// std::cout << "value to insert : " << key_to_insert << std::endl;

	// chrono.stl_start_chrono();
	// it_type 		it_hint2 		= map.insert(it_hint, pair(
	// 	convert<type_key_map>(key_to_insert),
	// 	convert<type_value_map>(tostr(value_to_insert))
	// ));
	// chrono.stl_end_chrono();

	// chrono.ft_start_chrono();
	// ft_it_type 	ft_it_hint2 = ft_map.insert(ft_it_hint, ft_pair(
	// 	convert<type_key_map>(key_to_insert),
	// 	convert<type_value_map>(tostr(value_to_insert))
	// ));
	// chrono.ft_end_chrono();

	// sstr << it_hint2->first << ":" << it_hint2->second << std::endl;
	// ft_sstr << ft_it_hint2->first << ":" << ft_it_hint2->second << std::endl;
	// str_comp(sstr.str(), ft_sstr.str(), "begin() -> end()");
	// sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	// chrono.diff_chrono();



	// ft_map.display_tree();



	// /* insert begin()+7, "ef" hint good*/
	// key_to_insert = "ef";
	// pos_to_insert = 7;
	// value_to_insert = 42;

	// it_hint 		= map.begin();
	// ft_it_hint 	= ft_map.begin();
	// for(int i = 0; i < pos_to_insert; i++) { it_hint++; ft_it_hint++; }

	// chrono.stl_start_chrono();
	// it_hint2 		= map.insert(it_hint, pair(key_to_insert, value_to_insert));
	// chrono.stl_end_chrono();

	// chrono.ft_start_chrono();
	// ft_it_hint2 = ft_map.insert(ft_it_hint, ft_pair(key_to_insert, value_to_insert));
	// chrono.ft_end_chrono();

	// sstr << it_hint2->first << ":" << it_hint2->second << std::endl;
	// ft_sstr << ft_it_hint2->first << ":" << ft_it_hint2->second << std::endl;
	// str_comp(sstr.str(), ft_sstr.str(), "begin() -> end()");
	// sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	// chrono.diff_chrono();





	/* compare maps */
	comp_map(map, ft_map, "compare map - ft_map");






	/* ***************************************************** */
	/*                  INSERT(first, last)                  */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST insert( first, last )" END << std::endl;

	std_map_t map_insert_f_l;
	ft_map_t ft_map_insert_f_l;









	/* insert with iterator + 3 */
	it_type it_insert_f_l_end 		= map.begin();
	ft_it_type ft_it_insert_f_l_end = ft_map.begin();

	for(int i = 0; i < 3; i++) { it_insert_f_l_end++; ft_it_insert_f_l_end++; }

	chrono.stl_start_chrono();
	map_insert_f_l.insert(map.begin(), it_insert_f_l_end);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_map_insert_f_l.insert(ft_map.begin(), ft_it_insert_f_l_end);
	chrono.ft_end_chrono();

	for (it_type it = map_insert_f_l.begin(); it != map_insert_f_l.end(); it++)
		sstr << it->first << ":" << it->second << " ";
	for (ft_it_type it = ft_map_insert_f_l.begin(); it != ft_map_insert_f_l.end(); it++)
		ft_sstr << it->first << ":" << it->second << " ";
		
	str_comp(sstr.str(), ft_sstr.str(), "insert( first, first + 3 )");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	chrono.diff_chrono();
	// ft_map_insert_f_l.display_tree();




	// /* insert with iterator + 7 */
	it_insert_f_l_end 		= map.begin();
	ft_it_insert_f_l_end 	= ft_map.begin();

	for(int i = 0; i < 7; i++) { it_insert_f_l_end++; ft_it_insert_f_l_end++; }
	chrono.stl_start_chrono();
	map_insert_f_l.insert(map.begin(), it_insert_f_l_end);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_map_insert_f_l.insert(ft_map.begin(), ft_it_insert_f_l_end);
	chrono.ft_end_chrono();

	for (it_type it = map_insert_f_l.begin(); it != map_insert_f_l.end(); it++)
		sstr << it->first << ":" << it->second << " ";
	for (ft_it_type it = ft_map_insert_f_l.begin(); it != ft_map_insert_f_l.end(); it++)
		ft_sstr << it->first << ":" << it->second << " ";

	str_comp(sstr.str(), ft_sstr.str(), "insert( first, first + 7 )");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	chrono.diff_chrono();
	// ft_map_insert_f_l.display_tree();





	/* insert with const iterator */
	it_type 					it_end 				= map.begin();
	ft_it_type 				ft_it_end 		= ft_map.begin();
	for(int i = 0; i < 6; i++) { it_end++; ft_it_end++; }
	const_it_type 		cit_end1 			= it_end;
	ft_const_it_type 	ft_cit_end1 	= ft_it_end;
	const_it_type 		cit_begin 		= map.begin();
	ft_const_it_type 	ft_cit_begin 	= ft_map.begin();

	chrono.stl_start_chrono();
	map_insert_f_l.insert(cit_begin, cit_end1);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_map_insert_f_l.insert(ft_cit_begin, ft_cit_end1);
	chrono.ft_end_chrono();

	comp_map(map_insert_f_l, ft_map_insert_f_l, "insert( const_iterator, const_iterator + 6 )");
	chrono.diff_chrono();
	// ft_map_insert_f_l.display_tree();





	/* insert with reverse iterator + 3 */
	r_it_type 	 rit_insert_f_l 	= map.rbegin();
	ft_r_it_type ft_rit_insert_f_l 	= ft_map.rbegin();
	for(int i = 0; i < 3; i++) { rit_insert_f_l++; ft_rit_insert_f_l++; }

	chrono.stl_start_chrono();
	map_insert_f_l.insert(map.rbegin(), rit_insert_f_l);
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map_insert_f_l.insert(ft_map.rbegin(), ft_rit_insert_f_l);
	chrono.ft_end_chrono();

	comp_map(map_insert_f_l, ft_map_insert_f_l, "insert( reverse_iterator, reverse_iterator )");
	chrono.diff_chrono();
	// ft_map_insert_f_l.display_tree();





	/* insert with reverse iterator */
	chrono.stl_start_chrono();
	map_insert_f_l.insert(map.rbegin(), map.rend());
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_map_insert_f_l.insert(ft_map.rbegin(), ft_map.rend());
	chrono.ft_end_chrono();

	comp_map(map_insert_f_l, ft_map_insert_f_l, "insert( reverse_iterator, reverse_iterator )");
	chrono.diff_chrono();
	// ft_map_insert_f_l.display_tree();





	/* compare maps */
	comp_map(map, ft_map, "compare map - ft_map");
	comp_map(map_insert_f_l, ft_map_insert_f_l, "compare map_insert_f_l - ft_map_insert_f_l");





	/* ***************************************************** */
	/*                       ITERATOR                        */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST iterator" END << std::endl;
	

	/* begin() */
	chrono.stl_start_chrono();
	it_type 	it		= map.begin();
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_it_type 	ft_it 	= ft_map.begin();
	chrono.ft_end_chrono();

	// std::cout << "	it->first: " << it->first << " \n	ft_it->first: " << ft_it->first << std::endl;
	sstr_comp< it_type, ft_it_type >(it, ft_it, "begin()");
	chrono.diff_chrono();



	/* begin() ++*/
	chrono.stl_start_chrono();
	it		= map.begin(); it++;
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_it 	= ft_map.begin(); ft_it++;
	chrono.ft_end_chrono();

	// std::cout << "	it->first: " << it->first << " \n	ft_it->first: " << ft_it->first << std::endl;
	sstr_comp< it_type, ft_it_type >(it, ft_it, "begin()++");
	chrono.diff_chrono();



	// /* end() --*/
	chrono.stl_start_chrono();
	it 		= map.end(); it--;
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_it 	= ft_map.end(); ft_it--;
	chrono.ft_end_chrono();

	// std::cout << "\n	it->first: " << it->first << " \n	ft_it->first: " << ft_it->first << std::endl;
	sstr_comp< it_type, ft_it_type >(it, ft_it, "end()--");
	chrono.diff_chrono();


	/* end --; --;*/
	chrono.stl_start_chrono();
	it 		= map.end(); it--; it--;
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_it 	= ft_map.end(); ft_it--; ft_it--;
	chrono.ft_end_chrono();

	// std::cout << "\n	it->first: " << it->first << " \n	ft_it->first: " << ft_it->first << std::endl;
	sstr_comp< it_type, ft_it_type >(it, ft_it, "end()-- x2");
	chrono.diff_chrono();




	/* end()--x3 */
	
	chrono.stl_start_chrono();
	it 		= map.end(); it--; it--; it--;
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_it 	= ft_map.end(); ft_it--; ft_it--; ft_it--;
	chrono.ft_end_chrono();

	// std::cout << "\n	it->first: " << it->first << " \n	ft_it->first: " << ft_it->first << std::endl;
	sstr_comp< it_type, ft_it_type >(it, ft_it, "end()--x3");
	chrono.diff_chrono();



	/* end()--x4 */
	chrono.stl_start_chrono();
	it 		= map.end(); it--; it--; it--;  it--;
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_it 	= ft_map.end(); ft_it--; ft_it--; ft_it--; ft_it--;
	chrono.ft_end_chrono();

	// std::cout << "\n	it->first: " << it->first << " \n	ft_it->first: " << ft_it->first << std::endl;
	sstr_comp< it_type, ft_it_type >(it, ft_it, "end()--x4");
	chrono.diff_chrono();




	// it 		= map.end(); it--; it--; it--; it--;  it--;
	// ft_it 	= ft_map.end(); ft_it--; ft_it--; ft_it--; ft_it--; ft_it--;
	// std::cout << "\n	it->first: " << it->first << " \n	ft_it->first: " << ft_it->first << std::endl;
	// sstr_comp< it_type, ft_it_type >(it, ft_it, "end()--x3");

	// 	it 		= map.end(); it--; it--; it--; it--;  it--; it--;
	// std::cout << "\n	it->first: " << it->first <<  std::endl;
	// ft_it 	= ft_map.end(); ft_it--; ft_it--; ft_it--; ft_it--; ft_it--; ft_it--;
	// std::cout << "\n	ft_it->first: " << ft_it->first << std::endl;
	// sstr_comp< it_type, ft_it_type >(it, ft_it, "end()--x3");

	// it = map.end(); it++;
	// ft_it 	= ft_map.end(); ft_it++;
	// sstr_comp< it_type, ft_it_type >(it, ft_it, "end()++");

																						// gerer test segfault
	// it = map.end(); it++; it++;
	// ft_it = ft_map.end(); ft_it++; ft_it++;
	// sstr_comp< it_type, ft_it_type >(it, ft_it, "end()++");




	/* begin() -> end() */
	chrono.stl_start_chrono();
	for (it = map.begin(); it != map.end(); it++){
		// std::cout << it->first << " : " << it->second << std::endl;
		sstr << it->first << ":" << it->second << " ";
	}
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	for (ft_it = ft_map.begin(); ft_it != ft_map.end(); ft_it++) {
		// std::cout << ft_it->first << " : " << ft_it->second << std::endl;
		ft_sstr << ft_it->first << ":" << ft_it->second << " ";
	}
	chrono.ft_end_chrono();

	str_comp(sstr.str(), ft_sstr.str(), "begin() -> end()");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	chrono.diff_chrono();








	// /* ***************************************************** */
	// /*                    CONST_ITERATOR                     */
	// /*                  pair< string, int >                  */
	// /* ***************************************************** */
	std::cout << MAG "\n\nTEST const iterator" END << std::endl;

	/* const begin() */
	chrono.stl_start_chrono();
	const_it_type 		const const_it3 	= map.begin();
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_const_it_type 	const const_ft_it3 	= ft_map.begin();
	chrono.ft_end_chrono();

	// std::cout << "const_r_it: " << const_r_it->first << ":" << const_r_it->second << std::endl;
	// std::cout << "const_ft_r_it: " << const_ft_r_it->first << ":" << const_ft_r_it->second << std::endl;
	sstr_comp< const_it_type, ft_const_it_type >(const_it3, const_ft_it3, "const begin()");
	chrono.diff_chrono();



	/* const begin() */
	it_type 	it_to_constit		= map.begin();
	ft_it_type 	ft_it_to_constit 	= ft_map.begin();
	
	chrono.stl_start_chrono();
	const_it_type 		const_it		= it_to_constit;
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_const_it_type 	const_ft_it 	= ft_it_to_constit;
	chrono.ft_end_chrono();

	sstr_comp< const_it_type, ft_const_it_type >(const_it, const_ft_it, "const begin()");
	chrono.diff_chrono();



	/* const bengin() ++ */
	chrono.stl_start_chrono();
	const_it_type 	 cit_end 		= map.begin(); cit_end++;
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_const_it_type ft_cit_end 	= ft_map.begin(); ft_cit_end++;
	chrono.ft_end_chrono();

	sstr_comp< const_it_type, ft_const_it_type >(cit_end, ft_cit_end, "const begin()++");
	chrono.diff_chrono();



	/* const bengin() ++ x2 */
	chrono.stl_start_chrono();
	cit_end 		= map.begin(); cit_end++; cit_end++;
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_cit_end 	= ft_map.begin(); ft_cit_end++; ft_cit_end++;
	chrono.ft_end_chrono();

	sstr_comp< const_it_type, ft_const_it_type >(cit_end, ft_cit_end, "const begin()++ x2");
	chrono.diff_chrono();




	/*const  end()-- */
	chrono.stl_start_chrono();
	cit_end 			= map.end(); 	cit_end--;
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_cit_end 	= ft_map.end(); ft_cit_end--;
	chrono.ft_end_chrono();

	sstr_comp< const_it_type, ft_const_it_type >(cit_end, ft_cit_end, "const end()--");
	chrono.diff_chrono();



	/*const end()++  only linux */
	// it_end 		= map.end(); 	it_end++;
	// ft_it_end 	= ft_map.end(); ft_it_end++;
	// const_it_type 		const_it_end_p 		= it_end;
	// ft_const_it_type 	const_ft_it_end_p 	= ft_it_end;
	// sstr_comp< const_it_type, ft_const_it_type >(const_it_end_p, const_ft_it_end_p, "const end()++");



	/* const end()-- x2 */
	chrono.stl_start_chrono();
	cit_end				= map.end(); cit_end--; cit_end--;
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_cit_end		= ft_map.end(); ft_cit_end--; ft_cit_end--;
	chrono.ft_end_chrono();

	sstr_comp< const_it_type, ft_const_it_type >(cit_end, ft_cit_end, "const end()-- x2");
	chrono.diff_chrono();








	// /* ***************************************************** */
	// /*                   REVERSE_ITERATOR                    */
	// /*                  pair< string, int >                  */
	// /* ***************************************************** */
	std::cout << MAG "\n\nTEST reverse iterator" END << std::endl;
	

	/* rbegin() */
	chrono.stl_start_chrono();
	r_it_type 		r_it 	= map.rbegin();
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_r_it_type 	ft_r_it = ft_map.rbegin();
	chrono.ft_end_chrono();

	sstr_comp< r_it_type, ft_r_it_type >(r_it, ft_r_it, "rbegin()");
	chrono.diff_chrono();



	/* rend()  SEGV */
	// r_it 	= map.rend();
	// ft_r_it = ft_map.rend();
	// sstr_comp< r_it_type, ft_r_it_type >(r_it, ft_r_it, "rend()");




	/* rend()-- */
	chrono.stl_start_chrono();
	r_it 	= map.rend(); r_it--;
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_r_it = ft_map.rend(); ft_r_it--;
	chrono.ft_end_chrono();

	sstr_comp< r_it_type, ft_r_it_type >(r_it, ft_r_it, "rend()--");
	chrono.diff_chrono();
	
	
	/* rend()++  sur linux */
	// r_it 	= map.rend(); r_it++;
	// ft_r_it = ft_map.rend(); ft_r_it++;
	// sstr_comp< r_it_type, ft_r_it_type >(r_it, ft_r_it, "rend()++");




	/* rbegin() -> rend() */
	chrono.stl_start_chrono();
	for (r_it = map.rbegin(); r_it != map.rend(); r_it++)
		sstr << r_it->first << ":" << r_it->second << " ";
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	for (ft_r_it = ft_map.rbegin(); ft_r_it != ft_map.rend(); ft_r_it++)
		ft_sstr << ft_r_it->first << ":" << ft_r_it->second << " ";
	chrono.ft_end_chrono();


	str_comp(sstr.str(), ft_sstr.str(), "rbegin() -> rend()");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	chrono.diff_chrono();








	/* ***************************************************** */
	/*                REVERSE_CONST_ITERATOR                 */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST const reverse iterator" END << std::endl;

	/* rbegin() */
	chrono.stl_start_chrono();
	const_r_it_type 	const_r_it 		= map.rbegin();
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_const_r_it_type 	const_ft_r_it 	= ft_map.rbegin();
	chrono.ft_end_chrono();
	// std::cout << "const_r_it: " << const_r_it->first << ":" << const_r_it->second << std::endl;
	// std::cout << "const_ft_r_it: " << const_ft_r_it->first << ":" << const_ft_r_it->second << std::endl;

	sstr_comp< const_r_it_type, ft_const_r_it_type >(const_r_it, const_ft_r_it, "const rbegin()");
	chrono.diff_chrono();



	/* rbegin() + 4 */
	r_it_type		r_it4 		= map.rbegin(); r_it4++; r_it4++; r_it4++; r_it4++;
	ft_r_it_type	ft_r_it4 	= ft_map.rbegin(); ft_r_it4++; ft_r_it4++; ft_r_it4++; ft_r_it4++;
	const_r_it_type 	const_r_it4 	= r_it4;
	ft_const_r_it_type 	const_ft_r_it4 	= ft_r_it4;
	sstr_comp< const_r_it_type, ft_const_r_it_type >(const_r_it4, const_ft_r_it4, "const rbegin() + 4");




	/* rend()-- */
	chrono.stl_start_chrono();
	const_r_it_type 	const_r_it2 		= map.rend(); const_r_it2 --;
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_const_r_it_type 	const_ft_r_it2 		= ft_map.rend(); const_ft_r_it2 --;
	chrono.ft_end_chrono();

	sstr_comp< const_r_it_type, ft_const_r_it_type >(const_r_it2, const_ft_r_it2, "const rend()--");
	chrono.diff_chrono();



	// /* rend()++  sur linux */
	// const_r_it 		= map.rend(); const_r_it++;
	// const_ft_r_it 	= ft_map.rend(); const_ft_r_it++;
	// sstr_comp< const_r_it_type, ft_const_r_it_type >(const_r_it, const_ft_r_it, "const rend()++");



	/* rbegin() -> rend() */
	chrono.stl_start_chrono();
	for (const_r_it = map.rbegin(); const_r_it != map.rend(); const_r_it++)
		sstr << const_r_it->first << ":" << const_r_it->second << " ";
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	for (const_ft_r_it = ft_map.rbegin(); const_ft_r_it != ft_map.rend(); const_ft_r_it++)
		ft_sstr << const_ft_r_it->first << ":" << const_ft_r_it->second << " ";
	chrono.ft_end_chrono();
	
	str_comp(sstr.str(), ft_sstr.str(), "const rbegin() -> rend()");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	chrono.diff_chrono();
	





	// ft_map.display_tree();





	/* ***************************************************** */
	/*                      find(value)                      */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST find(value)" END << std::endl;

	/* find("a") */
	chrono.stl_start_chrono();
	it_type ret_find 		= map.find(convert<type_key_map>("a"));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_it_type ft_ret_find 	= ft_map.find(convert<type_key_map>("a"));
	chrono.ft_end_chrono();

	str_comp(tostr(ret_find->first), tostr(ft_ret_find->first), "find(\"a\")");
	str_comp(tostr(ret_find->second), tostr(ft_ret_find->second), "find(\"a\")");
	chrono.diff_chrono();



	/* find("za") */
	chrono.stl_start_chrono();
	ret_find 		= map.find(convert<type_key_map>("za"));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_ret_find 	= ft_map.find(convert<type_key_map>("za"));
	chrono.ft_end_chrono();

	str_comp(tostr(ret_find->first), tostr(ft_ret_find->first), "find(\"za\")");
	str_comp(tostr(ret_find->second), tostr(ft_ret_find->second), "find(\"za\")");
	chrono.diff_chrono();




	/* find("inexist") */
	chrono.stl_start_chrono();
	ret_find		= map.find(convert<type_key_map>("inexist"));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_ret_find		= ft_map.find(convert<type_key_map>("inexist"));
	chrono.ft_end_chrono();

	if (ret_find == map.end() && ft_ret_find == ft_map.end())
		std::cout << GRN "[OK] " END ;
	else 
		std::cout << RED "[KO]" END << " find(\"inexist\") ? you're awesome" << std::endl;

	ret_find--;
	ft_ret_find--;
	str_comp(tostr(ret_find->first), tostr(ft_ret_find->first), "find(\"inexist\")--");
	str_comp(tostr(ret_find->second), tostr(ft_ret_find->second), "find(\"inexist\")--");
	chrono.diff_chrono();






	/* ***************************************************** */
	/*                   const find(value)                   */
	/*                  pair< string, int >                  */
	/* ***************************************************** */

	/* find("a") */
	chrono.stl_start_chrono();
	const_it_type 	ret_const_find			= map.find(convert<type_key_map>("a"));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_const_it_type ft_ret_const_find 	= ft_map.find(convert<type_key_map>("a"));
	chrono.ft_end_chrono();

	str_comp(tostr(ret_const_find->first), tostr(ft_ret_const_find->first), "const find(\"a\")");
	str_comp(tostr(ret_const_find->second), tostr(ft_ret_const_find->second), "const find(\"a\")");
	chrono.diff_chrono();




	/* find("za") */
	chrono.stl_start_chrono();
	const_it_type 	 ret_const_find2 		= map.find(convert<type_key_map>("za"));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_const_it_type ft_ret_const_find2 	= ft_map.find(convert<type_key_map>("za"));
	chrono.ft_end_chrono();

	str_comp(tostr(ret_const_find2->first), tostr(ft_ret_const_find2->first), "const find(\"za\")");
	str_comp(tostr(ret_const_find2->second), tostr(ft_ret_const_find2->second), "const find(\"za\")");
	chrono.diff_chrono();





	// ft_map.display_tree();





	/* ***************************************************** */
	/*                       erase(pos)                      */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST erase(pos)" END << std::endl;

	// ft_map.display_tree();


	/* erase("a") */
	chrono.stl_start_chrono();
	map.erase(map.begin());
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map.erase(ft_map.begin());
	chrono.ft_end_chrono();

	comp_map(map, ft_map, "erase begin()");
	chrono.diff_chrono();


	/* erase("inexist") SEGV */
	// map.erase(map.find("inexist"));
	// ft_map.erase(ft_map.find("inexist"));
	// comp_map(map, ft_map, "erase find(\"inexist\")");


	/* std::map SEGV */
	// map.erase(map.end());
	// ft_map.erase(ft_map.end());
	// comp_map(map, ft_map, "erase end()");



	/* erase("erase end()--") */
	it = map.end(); it--;
	ft_it = ft_map.end(); ft_it--;
	
	chrono.stl_start_chrono();
	map.erase(it);
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map.erase(ft_it);
	chrono.ft_end_chrono();

	comp_map(map, ft_map, "erase end()--");
	chrono.diff_chrono();



	/* erase("z") */
	chrono.stl_start_chrono();
	map.erase(map.find(convert<type_key_map>("z")));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map.erase(ft_map.find(convert<type_key_map>("z")));
	chrono.ft_end_chrono();

	comp_map(map, ft_map, "erase find(\"z\")");
	chrono.diff_chrono();



	/* erase("n")  SEGV si existe pas*/
	// map.erase(map.find("n"));
	// ft_map.erase(ft_map.find("n"));
	// comp_map(map, ft_map, "erase find(\"n\")");
	// // ft_map.display_tree();



	/* erase("g") */
	chrono.stl_start_chrono();
	map.erase(map.find(convert<type_key_map>("d")));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map.erase(ft_map.find(convert<type_key_map>("d")));
	chrono.ft_end_chrono();

	comp_map(map, ft_map, "erase find(\"d\")");
	chrono.diff_chrono();



	/*erase q*/
	// map.erase(map.find("q"));
	// ft_map.erase(ft_map.find("q"));
	// comp_map(map, ft_map, "erase find(\"q\")");



	/* erase("AA") */
	chrono.stl_start_chrono();
	map.erase(map.find(convert<type_key_map>("AA")));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map.erase(ft_map.find(convert<type_key_map>("AA")));
	chrono.ft_end_chrono();

	comp_map(map, ft_map, "erase find(\"AA\")");
	chrono.diff_chrono();



	/* erase("a") */
	chrono.stl_start_chrono();
	map.erase(map.find(convert<type_key_map>("a")));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map.erase(ft_map.find(convert<type_key_map>("a")));
	chrono.ft_end_chrono();

	comp_map(map, ft_map, "erase find(\"a\")");
	chrono.diff_chrono();


	/* erase c */
	chrono.stl_start_chrono();
	map.erase(map.find(convert<type_key_map>("c")));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map.erase(ft_map.find(convert<type_key_map>("c")));
	chrono.ft_end_chrono();


	comp_map(map, ft_map, "erase find(\"c\")");
	chrono.diff_chrono();



	// /* erase "b" */
	// map.erase(map.find("b"));
	// ft_map.erase(ft_map.find("b"));
	// comp_map(map, ft_map, "erase find(\"b\")");

	// /* erase("e") */
	// map.erase(map.find("e"));
	// ft_map.erase(ft_map.find("e"));
	// comp_map(map, ft_map, "erase find(\"e\")");

	// /* erase("g") */
	// map.erase(map.find("g"));
	// ft_map.erase(ft_map.find("g"));
	// comp_map(map, ft_map, "erase find(\"g\")");





	/* erase("h") */
	chrono.stl_start_chrono();
	map.erase(map.find(convert<type_key_map>("h")));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map.erase(ft_map.find(convert<type_key_map>("h")));
	chrono.ft_end_chrono();

	comp_map(map, ft_map, "erase find(\"h\")");
	chrono.diff_chrono();









	/* ***************************************************** */
	/*                  erase(first, last)                   */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST erase(first, last)" END << std::endl;


	/* erase begin() -> begin++*/
	it_type 		it_erase_end 		= map.begin(); it_erase_end++;
	ft_it_type 	ft_it_erase_end = ft_map.begin(); ft_it_erase_end++;

	chrono.stl_start_chrono();
	map.erase(map.begin(), it_erase_end);
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map.erase(ft_map.begin(), ft_it_erase_end);
	chrono.ft_end_chrono();

	comp_map(map, ft_map, "erase(begin(), begin()++)");
	chrono.diff_chrono();



	/*erase end()--, end()  */
	it_erase_end = map.end(); it_erase_end--;
	ft_it_erase_end = ft_map.end(); ft_it_erase_end--;

	chrono.stl_start_chrono();
	map.erase(it_erase_end, map.end());
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map.erase(ft_it_erase_end, ft_map.end());
	chrono.ft_end_chrono();

	comp_map(map, ft_map, "erase(end()--, end())");
	chrono.diff_chrono();



	/* erase begin(), begin() */
	chrono.stl_start_chrono();
	map.erase(map.begin(), map.begin());
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map.erase(ft_map.begin(), ft_map.begin());
	chrono.ft_end_chrono();

	comp_map(map, ft_map, "erase(begin(), begin())");
	chrono.diff_chrono();



	/* erase end(), end() */
	chrono.stl_start_chrono();
	map.erase(map.end(), map.end());
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map.erase(ft_map.end(), ft_map.end());
	chrono.ft_end_chrono();

	comp_map(map, ft_map, "erase(end(), end())");
	chrono.diff_chrono();



	/* erase begin() + 2, begin() + 5 */
	it_type 		it_erase_begin 		= map.begin();
	ft_it_type 	ft_it_erase_begin = ft_map.begin();
	for(int i = 0; i < 2; i++) { it_erase_begin++; ft_it_erase_begin++;	}
	it_erase_end = map.begin();
	ft_it_erase_end = ft_map.begin();
	for ( int i = 0; i < 5; i++ ) { it_erase_end++; ft_it_erase_end++; }

	chrono.stl_start_chrono();
	map.erase(it_erase_begin, it_erase_end);
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map.erase(ft_it_erase_begin, ft_it_erase_end);
	chrono.ft_end_chrono();

	comp_map(map, ft_map, "erase(begin() + 2, begin() + 5)");
	chrono.diff_chrono();



	/* erase begin() + 5 -> end() - 5 */
	it_erase_begin 		= map.begin();
	ft_it_erase_begin = ft_map.begin();
	for(int i = 0; i < 5; i++) { it_erase_begin++; ft_it_erase_begin++;	}

	it_erase_end 			= map.end();
	ft_it_erase_end 	= ft_map.end();
	for(int i = 0; i < 5; i++) { it_erase_end--; ft_it_erase_end--;	}

	chrono.stl_start_chrono();
	map.erase(it_erase_begin, it_erase_end);
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map.erase(ft_it_erase_begin, ft_it_erase_end);
	chrono.ft_end_chrono();

	comp_map(map, ft_map, "erase(begin() + 5, end() - 5)");
	chrono.diff_chrono();
	




	// ft_map.display_tree("erase first last");


	

	/* ***************************************************** */
	/*                      erase(key)                       */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST erase(key)" END << std::endl;


	/* erase("a") */

	chrono.stl_start_chrono();
	size_t ret = map.erase(convert<type_key_map>("w"));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	size_t ft_ret = ft_map.erase(convert<type_key_map>("w"));
	chrono.ft_end_chrono();

	str_comp(tostr(ret), tostr(ft_ret), "ret rase(\"w\")");
	comp_map(map, ft_map, "erase(\"w\")");
	chrono.diff_chrono();



	/* erase("b") */
	chrono.stl_start_chrono();
	ret = map.erase(convert<type_key_map>("b"));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_ret = ft_map.erase(convert<type_key_map>("b"));
	chrono.ft_end_chrono();

	str_comp(tostr(ret), tostr(ft_ret), "ret rase(\"b\")");
	comp_map(map, ft_map, "erase(\"b\")");
	chrono.diff_chrono();



	/* erase("e") */
	chrono.stl_start_chrono();
	ret =   map.erase(convert<type_key_map>("e"));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_ret =ft_map.erase(convert<type_key_map>("e"));
	chrono.ft_end_chrono();

	str_comp(tostr(ret), tostr(ft_ret), "ret rase(\"e\")");
	comp_map(map, ft_map, "erase(\"e\")");
	chrono.diff_chrono();



	/* erase("f") */
	chrono.stl_start_chrono();
	ret =    map.erase(convert<type_key_map>("inexist"));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_ret = ft_map.erase(convert<type_key_map>("inexist"));
	chrono.ft_end_chrono();

	str_comp(tostr(ret), tostr(ft_ret), "ret rase(\"f\")");
	comp_map(map, ft_map, "erase(\"f inexisant\")");
	chrono.diff_chrono();





	// ft_map.display_tree();






	/* ***************************************************** */
	/*                      swap()                           */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST swap()" END << std::endl;


	std_map_t map_swap(map);
	ft_map_t ft_map_swap(ft_map);

	map_swap.insert(pair(
		convert<type_key_map>("@"),
		convert<type_value_map>("777")
		)
	);
	ft_map_swap.insert(ft_pair(
		convert<type_key_map>("@"),
		convert<type_value_map>("777")
		)
	);

	/* swap() */
	// ft_map.display_tree("ft_map avant");
	// ft_map_swap.display_tree("ft_map_swap avant");
	chrono.stl_start_chrono();
	map.swap(map_swap);
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map.swap(ft_map_swap);
	chrono.ft_end_chrono();

	// ft_map.display_tree("ft_map apres");
	// ft_map_swap.display_tree("ft_map_swap apres");
	comp_map(map, ft_map, "map swap()");
	comp_map(map_swap, ft_map_swap, "swap original");
	chrono.diff_chrono();


	/* swap with empty */
	std_map_t map_swap2;
	ft_map_t ft_map_swap2;

	map_swap.insert(pair(
		convert<type_key_map>("&&"),
		convert<type_value_map>("1234")
		)
	);
	ft_map_swap.insert(ft_pair(
		convert<type_key_map>("&&"),
		convert<type_value_map>("1234")
		)
	);


	// ft_map_swap.display_tree("ft_map_swap avant");
	// ft_map_swap2.display_tree("ft_map_swap2 avant");
	chrono.stl_start_chrono();
	map_swap.swap(map_swap2);
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map_swap.swap(ft_map_swap2);
	chrono.ft_end_chrono();

	// ft_map_swap.display_tree("ft_map_swap apres");
	// ft_map_swap2.display_tree("ft_map_swap2 apres");
	comp_map(map_swap, ft_map_swap, "map swap2");
	comp_map(map_swap2, ft_map_swap2, "map_swap2 original");
	chrono.diff_chrono();








	// ft_map.display_tree();


	/* ***************************************************** */
	/*                constructor(first, last)               */
	/*                  pair< string, int >                  */
	/* ***************************************************** */

	std::cout << MAG "\n\nTEST constructor(first, last)" END << std::endl;

	/* constructor(first, last) */
	chrono.stl_start_chrono();
	std_map_t map_construct(map.begin(), map.end());
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map_t ft_map_construct(ft_map.begin(), ft_map.end());
	chrono.ft_end_chrono();

	comp_map(map_construct, ft_map_construct, "constructor(first, last)");
	chrono.diff_chrono();



	/*construct(begin, begin + 2) */
	it_end = map.begin();
	ft_it_end = ft_map.begin();
	for(int i = 0; i < 2; i++) { it_end++; ft_it_end++; }
	
	chrono.stl_start_chrono();
	std_map_t map_construct2(map.begin(), it_end);
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map_t ft_map_construct2(ft_map.begin(), ft_it_end);
	chrono.ft_end_chrono();

	comp_map(map_construct2, ft_map_construct2, "constructor(begin, begin + 2)");
	chrono.diff_chrono();



	/*construct(begin + 2, end - 2) */
	it_type it_begin = map.begin();
	ft_it_type ft_it_begin = ft_map.begin();
	for(int i = 0; i < 2; i++) { it_begin++; ft_it_begin++; }
	it_end = map.end();
	ft_it_end = ft_map.end();
	for(int i = 0; i < 2; i++) { it_end--; ft_it_end--; }

	chrono.stl_start_chrono();
	std_map_t map_construct3(it_begin, it_end);
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map_t ft_map_construct3(ft_it_begin, ft_it_end);
	chrono.ft_end_chrono();

	comp_map(map_construct3, ft_map_construct3, "constructor(begin + 2, end - 2)");
	chrono.diff_chrono();



	/* constructor const */
	const_it_type 	 cit_begin2 = map.begin();
	ft_const_it_type ft_cit_begin2 = ft_map.begin();
	const_it_type 	 cit_end2 = map.end();
	ft_const_it_type ft_cit_end2 = ft_map.end();

	chrono.stl_start_chrono();
	std_map_t map_construct10(cit_begin2, cit_end2);
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map_t ft_map_construct10(ft_cit_begin2, ft_cit_end2);
	chrono.ft_end_chrono();

	comp_map(map_construct10, ft_map_construct10, "constructor const");
	chrono.diff_chrono();





	/* construct(reverse begin, revse end) */
	chrono.stl_start_chrono();
	std_map_t map_construct4(map.rbegin(), map.rend());
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map_t ft_map_construct4(ft_map.rbegin(), ft_map.rend());
	chrono.ft_end_chrono();

	comp_map(map_construct4, ft_map_construct4, "constructor(reverse begin, revse end)");
	chrono.diff_chrono();



	/* construct(reverse begin + 2, revse end - 2) */
	r_it = map.rbegin();
	ft_r_it = ft_map.rbegin();
	for(int i = 0; i < 2; i++) { r_it++; ft_r_it++; }
	r_it_type 	 r_it_end = map.rend();
	ft_r_it_type ft_r_it_end = ft_map.rend();
	for(int i = 0; i < 2; i++) { r_it_end--; ft_r_it_end--; }

	chrono.stl_start_chrono();
	std_map_t map_construct5(r_it, r_it_end);
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map_t ft_map_construct5(ft_r_it, ft_r_it_end);
	chrono.ft_end_chrono();

	comp_map(map_construct5, ft_map_construct5, "constructor(reverse begin + 2, revse end - 2)");
	chrono.diff_chrono();









	/* ***************************************************** */
	/*                   copy constructor                    */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	
	/* test constructor copy */
	std::cout << MAG "\n\nTEST copy constructor" END << std::endl;
	
	/* cpy map */
	chrono.stl_start_chrono();
	std_map_t map_cp(map);
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map_t ft_map_cp(ft_map);
	chrono.ft_end_chrono();

	comp_map(map_cp, ft_map_cp, "copy constructor");
	comp_map(map, ft_map, "original maps");
	chrono.diff_chrono();



	/* cpy map_cp */
	chrono.stl_start_chrono();
	std_map_t map_cp_cp(map_cp);
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map_t ft_map_cp_cp(ft_map_cp);
	chrono.ft_end_chrono();

	comp_map(map_cp_cp, ft_map_cp_cp, "copy constructor");
	comp_map(map_cp, ft_map_cp, "original maps");
	chrono.diff_chrono();







	/* ***************************************************** */
	/*                     tests empty                       */
	/*                  pair< string, int >                  */
	/* ***************************************************** */

	std::cout << MAG "\n\nTEST empty" END << std::endl;

	std_map_t empty_map;
	ft_map_t 	ft_empty_map;

	
	str_comp( tostr(map.empty()), tostr(ft_map.empty()), "empty()");
	str_comp( tostr(map_cp.empty()), tostr(ft_map_cp.empty()), "empty()");
	str_comp( tostr(map_construct2.empty()), tostr(ft_map_construct2.empty()), "empty()");
	str_comp( tostr(empty_map.empty()), tostr(ft_empty_map.empty()), "empty()");
	map_cp.clear();
	ft_map_cp.clear();
	str_comp( tostr(map_cp.empty()), tostr(ft_map_cp.empty()), "empty() after clear()");
	





	// ft_map.display_tree();


	/* ***************************************************** */
	/*                     test at && []                     */
	/*                  pair< string, int >                  */
	/* ***************************************************** */

	std::cout << MAG "\n\nTEST at && []" END << std::endl;

	/* at @ */
	chrono.stl_start_chrono();
	type_value_map ret_at = map.at(convert<type_key_map>("@"));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	type_value_map ft_ret_at = ft_map.at(convert<type_key_map>("@"));
	chrono.ft_end_chrono();

	str_comp( tostr(ret_at), tostr(ft_ret_at), "at(\"@\")");
	chrono.diff_chrono();



	/* at s */
	chrono.stl_start_chrono();
	ret_at = map.at(convert<type_key_map>("s"));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_ret_at = ft_map.at(convert<type_key_map>("s"));
	chrono.ft_end_chrono();
	
	str_comp( tostr(ret_at), tostr(ft_ret_at), "at(\"s\")");
	chrono.diff_chrono();



	// // /* at a */																																		tester excetion
	// // ret_at = map.at("a");
	// // ft_ret_at = ft_map.at("a");
	// // str_comp( tostr(ret_at), tostr(ft_ret_at), "at(\"a\")");
	// // str_comp( tostr(map.at("a")), tostr(ft_map.at("a")), "at(\"a\")");




	/* at inexist */
	try {
		chrono.stl_start_chrono();
		ret_at = map.at(convert<type_key_map>("inexist"));
		chrono.stl_end_chrono();
	}
	catch (std::exception &e) {
		std::cout << RED "\nstl exception: " << e.what() << END;
	}

	try {
		chrono.ft_start_chrono();
		ft_ret_at = ft_map.at(convert<type_key_map>("inexist"));
		chrono.ft_end_chrono();
	}
	catch (std::exception &e) {
		std::cout << RED "\nft exception: " <<  e.what() << END << std::endl;
	}

	str_comp( tostr(ret_at), tostr(ft_ret_at), "at(\"inexist\")");
	chrono.diff_chrono();

	// chrono.stl_start_chrono();
	// ret_at = map.at(convert<type_key_map>("inexist"));
	// chrono.stl_end_chrono();
	// chrono.ft_start_chrono();
	// ft_ret_at = ft_map.at(convert<type_key_map>("inexist"));
	// chrono.ft_end_chrono();

	// str_comp( tostr(ret_at), tostr(ft_ret_at), "at(\"inexist\")");
	// chrono.diff_chrono();








	/* [] @ */
	chrono.stl_start_chrono();
	ret_at = map[convert<type_key_map>("@")];
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_ret_at = ft_map[convert<type_key_map>("@")];
	chrono.ft_end_chrono();

	str_comp( tostr(ret_at), tostr(ft_ret_at), "[](\"@\")");
	chrono.diff_chrono();




	/* [] s */
	chrono.stl_start_chrono();
	ret_at = map[convert<type_key_map>("s")];
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_ret_at = ft_map[convert<type_key_map>("s")];
	chrono.ft_end_chrono();

	str_comp( tostr(ret_at), tostr(ft_ret_at), "[](\"s\")");
	chrono.diff_chrono();



	/* [] inexist */
	chrono.stl_start_chrono();
	ret_at = map[convert<type_key_map>("inexist")];
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_ret_at = ft_map[convert<type_key_map>("inexist")];
	chrono.ft_end_chrono();

	str_comp( tostr(ret_at), tostr(ft_ret_at), "[](\"inexist\")");
	chrono.diff_chrono();



	comp_map(map, ft_map, "map");

	// // ft_map.display_tree();






	/* ***************************************************** */
	/*                      tests size                       */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	
	std::cout << MAG "\n\nTEST size - max_size" END << std::endl;

	str_comp( tostr(map.size()), tostr(ft_map.size()), "map.size()");
	str_comp( tostr(map_cp.size()), tostr(ft_map_cp.size()), "map_cp.size()");

	str_comp( tostr(map_construct3.size()), tostr(ft_map_construct3.size()), "map_construct3.size()");
	str_comp( tostr(empty_map.size()), tostr(ft_empty_map.size()), "map_construct3.size()");
	map_construct3.clear();
	ft_map_construct3.clear();
	str_comp( tostr(map_construct3.size()), tostr(ft_map_construct3.size()), "empty() after clear()");



	str_comp(tostr(map.max_size()), tostr(ft_map.max_size()), "max_size()");
	str_comp(tostr(map_cp.max_size()), tostr(ft_map_cp.max_size()), "max_size()");
	str_comp(tostr(map_construct3.max_size()), tostr(ft_map_construct3.max_size()), "max_size()");








	/* ***************************************************** */
	/*                        LOOKUP                         */
	/*                  pair< string, int >                  */
	/* ***************************************************** */


	std::cout << MAG "\n\nTEST count" END << std::endl;

	str_comp( tostr(map.count(convert<type_key_map>("@"))), tostr(ft_map.count(convert<type_key_map>("@"))), "count(@)" );
	str_comp( tostr(map.count(convert<type_key_map>("a"))), tostr(ft_map.count(convert<type_key_map>("a"))), "count(a)" );
	str_comp( tostr(map.count(convert<type_key_map>("l"))), tostr(ft_map.count(convert<type_key_map>("l"))), "count(l)" );
	str_comp( tostr(map.count(convert<type_key_map>("y"))), tostr(ft_map.count(convert<type_key_map>("y"))), "count(y)" );
	str_comp( tostr(map.count(convert<type_key_map>("z"))), tostr(ft_map.count(convert<type_key_map>("z"))), "count(z)" );
	str_comp( tostr(map.count(convert<type_key_map>("no"))), tostr(ft_map.count(convert<type_key_map>("no"))), "count(no)" );
	



	// ft_map.display_tree();



	/* ***************************************************** */
	/*                        LOOKUP                         */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	
	std::cout << MAG "\n\nTEST equal_range()" END << std::endl;

	std::pair<it_type, it_type> 			ret_equal_range;
	ft::pair<ft_it_type, ft_it_type> ft_ret_equal_range;


	// /* l */
	// chrono.stl_start_chrono();
	// ret_equal_range 	= map.equal_range(convert<type_key_map>("l"));
	// chrono.stl_end_chrono();
	// chrono.ft_start_chrono();
	// ft_ret_equal_range = ft_map.equal_range(convert<type_key_map>("l"));
	// chrono.ft_end_chrono();

	// str_comp( tostr(ret_equal_range.first->first), tostr(ft_ret_equal_range.first->first), "equal_range first first(\"l\")");
	// str_comp( tostr(ret_equal_range.first->second), tostr(ft_ret_equal_range.first->second), "equal_range first second(\"l\")");
	// str_comp( tostr(ret_equal_range.second->first), tostr(ft_ret_equal_range.second->first), "equal_range second first(\"l\")");
	// str_comp( tostr(ret_equal_range.second->second), tostr(ft_ret_equal_range.second->second), "equal_range second second(\"l\")");
	// chrono.diff_chrono();




	/* @ */
	chrono.stl_start_chrono();
	ret_equal_range = map.equal_range(convert<type_key_map>("@"));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_ret_equal_range = ft_map.equal_range(convert<type_key_map>("@"));
	chrono.ft_end_chrono();

	str_comp( tostr(ret_equal_range.first->first), tostr(ft_ret_equal_range.first->first), "equal_range(\"@\")");
	str_comp( tostr(ret_equal_range.first->second), tostr(ft_ret_equal_range.first->second), "equal_range(\"@\")");
	str_comp( tostr(ret_equal_range.second->first), tostr(ft_ret_equal_range.second->first), "equal_range(\"@\")");
	str_comp( tostr(ret_equal_range.second->second), tostr(ft_ret_equal_range.second->second), "equal_range(\"@\")");
	chrono.diff_chrono();


	// ft_map.display_tree();


	/* y bad alloc */
	// chrono.stl_start_chrono();
	// ret_equal_range = map.equal_range(convert<type_key_map>("y"));
	// chrono.stl_end_chrono();
	// chrono.ft_start_chrono();
	// ft_ret_equal_range = ft_map.equal_range(convert<type_key_map>("y"));
	// chrono.ft_end_chrono();

	// str_comp( tostr(ret_equal_range.first->first), tostr(ft_ret_equal_range.first->first), "equal_range(\"y\")");
	// str_comp( tostr(ret_equal_range.first->second), tostr(ft_ret_equal_range.first->second), "equal_range(\"y\")");
	// str_comp( tostr(ret_equal_range.second->first), tostr(ft_ret_equal_range.second->first), "equal_range(\"y\")");
	// str_comp( tostr(ret_equal_range.second->second), tostr(ft_ret_equal_range.second->second), "equal_range(\"y\")");
	// chrono.diff_chrono();




	// /* zshu SEGV*/
	// // chrono.stl_start_chrono();
	// // ret_equal_range = map.equal_range("zshu");
	// // chrono.stl_end_chrono();
	// // chrono.ft_start_chrono();
	// // ft_ret_equal_range = ft_map.equal_range("zshu");
	// // chrono.ft_end_chrono();

	// // str_comp( tostr(ret_equal_range.first->first), tostr(ft_ret_equal_range.first->first), "equal_range(\"zshu\")");
	// // str_comp( tostr(ret_equal_range.first->second), tostr(ft_ret_equal_range.first->second), "equal_range(\"zshu\")");
	// // str_comp( ret_equal_range.second->first, ft_ret_equal_range.second->first, "equal_range(\"zshu\")");
	// // str_comp( tostr(ret_equal_range.second->second), tostr(ft_ret_equal_range.second->second), "equal_range(\"zshu\")");
	// // chrono.diff_chrono();




	// /* z SEGV */
	// // ret_equal_range = map.equal_range("z");
	// // ft_ret_equal_range = ft_map.equal_range("z");
	// // str_comp( tostr(ret_equal_range.first->first), tostr(ft_ret_equal_range.first->first), "equal_range(\"z\")");
	// // str_comp( tostr(ret_equal_range.first->second), tostr(ft_ret_equal_range.first->second), "equal_range(\"z\")");
	
	// // std::cout << "ret first first = " << ret_equal_range.first->first << std::endl;
	// // std::cout << "ft first first = " << ft_ret_equal_range.first->first << std::endl;
	// // std::cout << "ret second first = " << ret_equal_range.second->first << std::endl;
	// // std::cout << "ft second first= " << ft_ret_equal_range.second->first << std::endl;

	// // std::cout << "ret second first = " << ret_equal_range.second->first << std::endl;
	// // std::cout << "ft_ret second first = " << ft_ret_equal_range.second->first << std::endl;
	// // std::cout << "ret second second = " << ret_equal_range.second->second << std::endl;
	// // std::cout << "ft_ret second second = " << ft_ret_equal_range.second->second << std::endl;

	// // str_comp( tostr(ret_equal_range.second->first), tostr(ft_ret_equal_range.second->first), "equal_range(\"z\")");
	// // str_comp( tostr(ret_equal_range.second->second), tostr(ft_ret_equal_range.second->second), "equal_range(\"z\")");



	// ft_map.display_tree();










	std::cout << MAG "\n\nTEST lower_bound()" END << std::endl;
	
	it_type 		ret_lower_bound;
	ft_it_type 	ft_ret_lower_bound;


	
	// /* insert ("aaaaaaaaa", 123) */
	// chrono.stl_start_chrono();
	// ret_insert_value 	= map.insert(pair(
	// 	convert<type_key_map>("aaaaaaaaa"),
	// 	convert<type_value_map>("123")));
	// chrono.stl_end_chrono();

	// chrono.ft_start_chrono();
	// ft_ret_insert_value = ft_map.insert(ft_pair(
	// 	convert<type_key_map>("aaaaaaaaa"),
	// 	convert<type_value_map>("123")));
	// chrono.ft_end_chrono();

	// str_comp(tostr(ret_insert_value.first->first), tostr(ft_ret_insert_value.first->first), "insert(value(ft_pair(\"aaaaaaaaa\", 123))) -> first -> first");
	// str_comp(tostr(ret_insert_value.first->second), tostr(ft_ret_insert_value.first->second), "insert(value(ft_pair(\"aaaaaaaaa\", 123)))  -> first -> second");
	// str_comp(tostr(ret_insert_value.second), tostr(ft_ret_insert_value.second), "insert(value(ft_pair(\"aaaaaaaaa\", 123))) -> second");
	// chrono.diff_chrono();

	// /* first */
	// chrono.stl_start_chrono();
	// ret_lower_bound = map.lower_bound(convert<type_key_map>("aaaaaaaaa"));
	// chrono.stl_end_chrono();
	// chrono.ft_start_chrono();
	// ft_ret_lower_bound = ft_map.lower_bound(convert<type_key_map>("aaaaaaaaa"));
	// chrono.ft_end_chrono();

	// str_comp( tostr(ret_lower_bound->first), tostr(ft_ret_lower_bound->first), "lower_bound(\"first\")");
	// str_comp( tostr(ret_lower_bound->second), tostr(ft_ret_lower_bound->second), "lower_bound(\"first\")");
	// std::cout << "ret_lower_bound->first = " << ret_lower_bound->first << std::endl;
	// std::cout << "ft_ret_lower_bound->first = " << ft_ret_lower_bound->first << std::endl;
	// chrono.diff_chrono();



	/* @ */
	chrono.stl_start_chrono();
	ret_lower_bound = map.lower_bound(convert<type_key_map>("@"));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_ret_lower_bound = ft_map.lower_bound(convert<type_key_map>("@"));
	chrono.ft_end_chrono();

	str_comp( tostr(ret_lower_bound->first), tostr(ft_ret_lower_bound->first), "lower_bound(\"@\")");
	str_comp( tostr(ret_lower_bound->second), tostr(ft_ret_lower_bound->second), "lower_bound(\"@\")");
	chrono.diff_chrono();



	/* s */
	chrono.stl_start_chrono();
	ret_lower_bound = map.lower_bound(convert<type_key_map>("s"));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_ret_lower_bound = ft_map.lower_bound(convert<type_key_map>("s"));
	chrono.ft_end_chrono();

	str_comp( tostr(ret_lower_bound->first), tostr(ft_ret_lower_bound->first), "lower_bound(\"s\")");
	str_comp( tostr(ret_lower_bound->second), tostr(ft_ret_lower_bound->second), "lower_bound(\"s\")");
	chrono.diff_chrono();



	// /* z */
	// // ret_lower_bound = map.lower_bound("z");
	// // ft_ret_lower_bound = ft_map.lower_bound("z");

	// // str_comp( tostr(ret_lower_bound->first), tostr(ft_ret_lower_bound->first), "lower_bound(\"z\")");
	// // str_comp( tostr(ret_lower_bound->second), tostr(ft_ret_lower_bound->second), "lower_bound(\"z\")");






	// ft_map.display_tree();





	std::cout << MAG "\n\nTEST upper_bound()" END << std::endl;
	
	it_type 		ret_upper_bound;
	ft_it_type 	ft_ret_upper_bound;


	/* @ */
	chrono.stl_start_chrono();
	ret_upper_bound = map.upper_bound(convert<type_key_map>("@"));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_ret_upper_bound = ft_map.upper_bound(convert<type_key_map>("@"));
	chrono.ft_end_chrono();

	// std::cout << "ret first = " << ret_upper_bound->first << std::endl;
	// std::cout << "ft first = " << ft_ret_upper_bound->first << std::endl;
	// std::cout << "ret second = " << ret_upper_bound->second << std::endl;
	// std::cout << "ft second = " << ft_ret_upper_bound->second << std::endl;

	str_comp( tostr(ret_upper_bound->first), tostr(ft_ret_upper_bound->first), "upper_bound(\"@\")");
	str_comp( tostr(ret_upper_bound->second), tostr(ft_ret_upper_bound->second), "upper_bound(\"@\")");
	chrono.diff_chrono();





	/* r */
	chrono.stl_start_chrono();
	ret_upper_bound = map.upper_bound(convert<type_key_map>("r"));
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_ret_upper_bound = ft_map.upper_bound(convert<type_key_map>("r"));
	chrono.ft_end_chrono();

	str_comp( tostr(ret_upper_bound->first), tostr(ft_ret_upper_bound->first), "upper_bound(\"r\")");
	str_comp( tostr(ret_upper_bound->second), tostr(ft_ret_upper_bound->second), "upper_bound(\"r\")");
	chrono.diff_chrono();






	// /* y */
	// // ret_upper_bound = map.upper_bound("y");
	// // ft_ret_upper_bound = ft_map.upper_bound("y");

	// // str_comp( ret_upper_bound->first, ft_ret_upper_bound->first, "upper_bound(\"y\")");
	// // str_comp( tostr(ret_upper_bound->second), tostr(ft_ret_upper_bound->second), "upper_bound(\"y\")");

	// /* z */
	// // ret_upper_bound = map.upper_bound("z");
	// // ft_ret_upper_bound = ft_map.upper_bound("z");

	// // str_comp( ret_upper_bound->first, ft_ret_upper_bound->first, "upper_bound(\"z\")");
	// // str_comp( tostr(ret_upper_bound->second), tostr(ft_ret_upper_bound->second), "upper_bound(\"z\")");




	/* ***************************************************** */
	/*                      key_comp()                       */
	/*                  pair< string, int >                  */
	/* ***************************************************** */

	std::cout << MAG "\n\nTEST key_comp()" END << std::endl;

	/* key_comp()("a", "b") */
	chrono.stl_start_chrono();
	bool ret_map_key_comp = map.key_comp()(
		convert<type_key_map>("a"),
		convert<type_key_map>("b")
	);
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	bool ft_ret_map_key_comp = ft_map.key_comp()(
		convert<type_key_map>("a"),
		convert<type_key_map>("b")
	);
	chrono.ft_end_chrono();

	str_comp(tostr(ret_map_key_comp), tostr(ft_ret_map_key_comp), "key_comp()");
	chrono.diff_chrono();



	/* key_comp()("b", "a") */
	chrono.stl_start_chrono();
	ret_map_key_comp = map.key_comp()(
		convert<type_key_map>("b"),
		convert<type_key_map>("a")
	);
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_ret_map_key_comp = ft_map.key_comp()(
		convert<type_key_map>("b"),
		convert<type_key_map>("a")
	);
	chrono.ft_end_chrono();
	
	str_comp(tostr(ret_map_key_comp), tostr(ft_ret_map_key_comp), "key_comp()");
	chrono.diff_chrono();



	/* key_comp()("a", "a") */
	chrono.stl_start_chrono();
	ret_map_key_comp = map.key_comp()(
		convert<type_key_map>("a"),
		convert<type_key_map>("a")
	);
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_ret_map_key_comp = ft_map.key_comp()(
		convert<type_key_map>("a"),
		convert<type_key_map>("a")
	);
	chrono.ft_end_chrono();

	str_comp(tostr(ret_map_key_comp), tostr(ft_ret_map_key_comp), "key_comp()");
	chrono.diff_chrono();





	/* key_comp()("b", "b") */
	chrono.stl_start_chrono();
	ret_map_key_comp = map.key_comp()(
		convert<type_key_map>("b"),
		convert<type_key_map>("b")
	);
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_ret_map_key_comp = ft_map.key_comp()(
		convert<type_key_map>("b"),
		convert<type_key_map>("b")
	);
	chrono.ft_end_chrono();

	str_comp(tostr(ret_map_key_comp), tostr(ft_ret_map_key_comp), "key_comp()");
	chrono.diff_chrono();



	/* key_comp()("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz1") */
	chrono.stl_start_chrono();
	ret_map_key_comp = map.key_comp()(
		convert<type_key_map>("abcdefghijklmnopqrstuvwxyz"),
		convert<type_key_map>("abcdefghijklmnopqrstuvwxyz1")
	);
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_ret_map_key_comp = ft_map.key_comp()(
		convert<type_key_map>("abcdefghijklmnopqrstuvwxyz"),
		convert<type_key_map>("abcdefghijklmnopqrstuvwxyz1")
	);
	chrono.ft_end_chrono();

	str_comp(tostr(ret_map_key_comp), tostr(ft_ret_map_key_comp), "key_comp()");
	chrono.diff_chrono();
	




	/* ***************************************************** */
	/*                     value_comp()                      */
	/*                  pair< string, int >                  */
	/* ***************************************************** */

	std::cout << MAG "\n\nTEST value_comp()" END << std::endl;


	/* value_comp()((a, 1)", "(b, 1")) */
	pair 	ret_map_vc1 	= std::make_pair(
		convert<type_key_map>("a"),
		convert<type_value_map>("1")
	);
	pair 	ret_map_vc2 	= std::make_pair(
		convert<type_key_map>("b"),
		convert<type_value_map>("1")
	);
	ft_pair ft_ret_map_vc1 = ft::make_pair(
		convert<type_key_map>("a"),
		convert<type_value_map>("1")
	);
	ft_pair ft_ret_map_vc2 = ft::make_pair(
		convert<type_key_map>("b"),
		convert<type_value_map>("1")
	);

	chrono.stl_start_chrono();
	bool ret_map_value_comp_ret     = map.value_comp()(ret_map_vc1, ret_map_vc2);
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	bool ft_ret_map_value_comp_ret  = ft_map.value_comp()(ft_ret_map_vc1, ft_ret_map_vc2);
	chrono.ft_end_chrono();

	str_comp(tostr(ret_map_value_comp_ret), tostr(ft_ret_map_value_comp_ret), "value_comp()");
	chrono.diff_chrono();



	/* value_comp()((b, 1)", "(a, 1")) */
	ret_map_vc1 	= std::make_pair(
		convert<type_key_map>("b"),
		convert<type_value_map>("1")
	);
	ret_map_vc2 	= std::make_pair(
		convert<type_key_map>("a"),
		convert<type_value_map>("1")
	);
	ft_ret_map_vc1 = ft::make_pair(
		convert<type_key_map>("b"),
		convert<type_value_map>("1")
	);
	ft_ret_map_vc2 = ft::make_pair(
		convert<type_key_map>("a"),
		convert<type_value_map>("1")
	);

	chrono.stl_start_chrono();
	ret_map_value_comp_ret    = map.value_comp()(ret_map_vc1, ret_map_vc2);
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_ret_map_value_comp_ret = ft_map.value_comp()(ft_ret_map_vc1, ft_ret_map_vc2);
	chrono.ft_end_chrono();

	str_comp(tostr(ret_map_value_comp_ret), tostr(ft_ret_map_value_comp_ret), "value_comp()");
	chrono.diff_chrono();



	/* value_comp()((a, 1)", "(a, 1")) */
	ret_map_vc1 	= std::make_pair(
		convert<type_key_map>("a"),
		convert<type_value_map>("1")
	);
	ret_map_vc2 	= std::make_pair(
		convert<type_key_map>("a"),
		convert<type_value_map>("1")
	);
	ft_ret_map_vc1 = ft::make_pair(
		convert<type_key_map>("a"),
		convert<type_value_map>("1")
	);
	ft_ret_map_vc2 = ft::make_pair(
		convert<type_key_map>("a"),
		convert<type_value_map>("1")
	);
	
	chrono.stl_start_chrono();
	ret_map_value_comp_ret    = map.value_comp()(ret_map_vc1, ret_map_vc2);
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_ret_map_value_comp_ret = ft_map.value_comp()(ft_ret_map_vc1, ft_ret_map_vc2);
	chrono.ft_end_chrono();

	str_comp(tostr(ret_map_value_comp_ret), tostr(ft_ret_map_value_comp_ret), "value_comp()");
	chrono.diff_chrono();










	/* ***************************************************** */
	/*                       clear()                         */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST clear" END << std::endl;

	chrono.stl_start_chrono();
	map.clear();
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_map.clear();
	chrono.ft_end_chrono();

	comp_map(map, ft_map, "clear()");
	chrono.diff_chrono();


	std_map_t empty_map2;
	ft_map_t ft_empty_map2;
	chrono.stl_start_chrono();
	empty_map2.clear();
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_empty_map2.clear();
	chrono.ft_end_chrono();

	comp_map(empty_map2, ft_empty_map2, "clear()");
	chrono.diff_chrono();


	/* AVERAGE TIME */
	chrono.display_average();

}

