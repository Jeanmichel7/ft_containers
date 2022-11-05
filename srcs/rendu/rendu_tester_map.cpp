/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendu_tester_map.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:36:39 by jrasser           #+#    #+#             */
/*   Updated: 2022/11/05 01:30:36 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.hpp"

// #define T_SIZE_TYPE typename STL_TYPE


void rendu_tester_map( void ) {

	display_title("MAP < String, Int >");
	rendu_tester_map_type< std::string, int >();

	display_title("MAP < Int, String >");
	rendu_tester_map_type< int, std::string >();

	display_title("MAP < String, String >");
	rendu_tester_map_type< std::string, std::string >();

	display_title("MAP < Int, Int >");
	rendu_tester_map_type< int, int >();

	display_title("MAP < Int, Float >");
	rendu_tester_map_type< int, float >();

}

template< typename type_key_map, typename type_value_map >
void rendu_tester_map_type() {

	typedef typename STL_TYPE::map< type_key_map, type_value_map > 	std_map_t;

	typedef typename std_map_t::iterator 										it_type;
	typedef typename std_map_t::const_iterator 							const_it_type;
	typedef typename std_map_t::reverse_iterator 						r_it_type;
	typedef typename std_map_t::const_reverse_iterator 			const_r_it_type;

	typedef STL_TYPE::pair< type_key_map, type_value_map > 	pair;




	std::cout << "TEST constructor map() "<< std::endl;
	std_map_t map;


	STL_TYPE::pair< it_type, bool > ret_insert_value;
	
	ret_insert_value	= map.insert(pair(
		convert<type_key_map>("b"),
		convert<type_value_map>("2")
	));
	std::cout << "inserted : " << ret_insert_value.second << " (" 
						<< ret_insert_value.first->first << ", "
						<< ret_insert_value.first->second << ")" << std::endl;

	ret_insert_value 	= map.insert(pair(
		convert<type_key_map>("a"),
		convert<type_value_map>("1")
	));
	std::cout << "inserted : " << ret_insert_value.second << " (" 
						<< ret_insert_value.first->first << ", "
						<< ret_insert_value.first->second << ")" << std::endl;

	ret_insert_value 	= map.insert(pair(
		convert<type_key_map>("c"),
		convert<type_value_map>("3")
	));
	std::cout << "inserted : " << ret_insert_value.second << " (" 
						<< ret_insert_value.first->first << ", "
						<< ret_insert_value.first->second << ")" << std::endl;

	ret_insert_value 	= map.insert(pair(
		convert<type_key_map>("e"),
		convert<type_value_map>("5")
	));
	std::cout << "inserted : " << ret_insert_value.second << " (" 
						<< ret_insert_value.first->first << ", "
						<< ret_insert_value.first->second << ")" << std::endl;

	ret_insert_value 	= map.insert(pair(
		convert<type_key_map>("d"),
		convert<type_value_map>("4")
	));
	std::cout << "inserted : " << ret_insert_value.second << " (" 
						<< ret_insert_value.first->first << ", "
						<< ret_insert_value.first->second << ")" << std::endl;

	ret_insert_value 	= map.insert(pair(
		convert<type_key_map>("d"),
		convert<type_value_map>("4")
	));
	std::cout << "inserted : " << ret_insert_value.second << " (" 
						<< ret_insert_value.first->first << ", "
						<< ret_insert_value.first->second << ")" << std::endl;

	ret_insert_value 	= map.insert(pair(
		convert<type_key_map>("d"),
		convert<type_value_map>("10")
	));
	std::cout << "inserted : " << ret_insert_value.second << " (" 
						<< ret_insert_value.first->first << ", "
						<< ret_insert_value.first->second << ")" << std::endl;


	fill_map< std_map_t, pair, type_key_map, type_value_map >(&map);
	display_map_list(map);








	std::cout << "\n\nTEST insert( hint, value )" << std::endl;

	it_type it_insert_hint;

	it_insert_hint = map.insert(
			map.begin(),
			pair(
					convert<type_key_map>("A"),
					convert<type_value_map>("1")));
	std::cout << "inserted : " << it_insert_hint->first << ", " << it_insert_hint->second << std::endl;

	it_insert_hint = map.insert(
			map.begin(),
			pair(
					convert<type_key_map>("AA"),
					convert<type_value_map>("10")));
	std::cout << "inserted : " << it_insert_hint->first << ", " << it_insert_hint->second << std::endl;

	it_insert_hint = map.insert(
			map.begin(),
			pair(
					convert<type_key_map>("z"),
					convert<type_value_map>("1")));
	std::cout << "inserted : " << it_insert_hint->first << ", " << it_insert_hint->second << std::endl;

	it_insert_hint = map.insert(
			map.end(),
			pair(
					convert<type_key_map>("z"),
					convert<type_value_map>("1")));
	std::cout << "inserted : " << it_insert_hint->first << ", " << it_insert_hint->second << std::endl;

	it_insert_hint = map.insert(
			map.end(),
			pair(
					convert<type_key_map>("za"),
					convert<type_value_map>("1")));
	std::cout << "inserted : " << it_insert_hint->first << ", " << it_insert_hint->second << std::endl;

	it_insert_hint = map.insert(
			map.end(),
			pair(
					convert<type_key_map>("c"),
					convert<type_value_map>("1")));
	std::cout << "inserted : " << it_insert_hint->first << ", " << it_insert_hint->second << std::endl;



	display_map_list(map);










	std::cout <<  "\n\nTEST insert( first, last )"  << std::endl;

	std_map_t map_insert_f_l;

	it_type it_insert_f_l_end 		= map.begin();
	for(int i = 0; i < 3; i++) { it_insert_f_l_end++; }
	map_insert_f_l.insert(map.begin(), it_insert_f_l_end);
	for (it_type it = map_insert_f_l.begin(); it != map_insert_f_l.end(); it++)
			std::cout << it->first << ":" << it->second << " ";
	display_map_list(map_insert_f_l);


	it_insert_f_l_end 		= map.begin();
	for(int i = 0; i < 7; i++) { it_insert_f_l_end++; }
	map_insert_f_l.insert(map.begin(), it_insert_f_l_end);
	for (it_type it = map_insert_f_l.begin(); it != map_insert_f_l.end(); it++)
		std::cout << it->first << ":" << it->second << " ";
	display_map_list(map_insert_f_l);


	it_type 					it_end 				= map.begin();
	for(int i = 0; i < 6; i++) { it_end++; }
	const_it_type 		cit_end1 			= it_end;
	const_it_type 		cit_begin 		= map.begin();
	map_insert_f_l.insert(cit_begin, cit_end1);
	display_map_list(map_insert_f_l);



	r_it_type 	 rit_insert_f_l 	= map.rbegin();
	for(int i = 0; i < 3; i++) { rit_insert_f_l++; }
	map_insert_f_l.insert(map.rbegin(), rit_insert_f_l);
	display_map_list(map_insert_f_l);

	map_insert_f_l.insert(map.rbegin(), map.rend());
	display_map_list(map_insert_f_l);







	std::cout <<  "\n\nTEST iterator"  << std::endl;

	it_type it;

	it = map.begin();
	std::cout << "begin : " << it->first << ", " << it->second << std::endl;
	it		= map.begin(); it++;
	std::cout << "begin++ : " << it->first << ", " << it->second << std::endl;
	it 		= map.end(); it--;
	std::cout << "end-- : " << it->first << ", " << it->second << std::endl;
	it 		= map.end(); it--; it--;
	std::cout << "end-- x2 : " << it->first << ", " << it->second << std::endl;
	for (it = map.begin(); it != map.end(); it++){
		std::cout << it->first << ":" << it->second << " ";
	}




	std::cout <<  "\n\nTEST const iterator"  << std::endl;


	const_it_type const_it3 	= map.begin();
	std::cout << "cbegin : " << const_it3->first << ", " << const_it3->second << std::endl;

	it_type 	it_to_constit		= map.begin();
	const_it_type 		const_it		= it_to_constit;
	std::cout << "const_it : " << const_it->first << ", " << const_it->second << std::endl;

	const_it_type 	 cit_end 		= map.begin(); cit_end++;
	std::cout << "const_it : " << cit_end->first << ", " << cit_end->second << std::endl;

	cit_end 		= map.begin(); cit_end++; cit_end++;
	std::cout << "const_it : " << cit_end->first << ", " << cit_end->second << std::endl;

	cit_end 			= map.end(); 	cit_end--;
	std::cout << "const_it : " << cit_end->first << ", " << cit_end->second << std::endl;

	cit_end				= map.end(); cit_end--; cit_end--;
	std::cout << "const_it : " << cit_end->first << ", " << cit_end->second << std::endl;






	std_map_t const const_map_empty;
	std_map_t const const_map(map);
	const_it_type 		const const_it4 	= const_map.begin();
	std::cout << "cmap begin : " << const_it4->first << ", " << const_it4->second << std::endl;

	const_it_type  		const_it5;
	for (const_it5 = const_map.begin(); const_it5 != const_map.end(); const_it5++){
		std::cout << const_it5->first << ":" << const_it5->second << " ";
	}



	std::cout <<  "\n\nTEST reverse iterator"  << std::endl;

	r_it_type 		r_it 	= map.rbegin();
	std::cout << "rbegin : " << r_it->first << ", " << r_it->second << std::endl;

	r_it 	= map.rend(); r_it--;
	std::cout << "rend-- : " << r_it->first << ", " << r_it->second << std::endl;

	for (r_it = map.rbegin(); r_it != map.rend(); r_it++)
		std::cout << r_it->first << ":" << r_it->second << " ";





	std::cout <<  "\n\nTEST const reverse iterator"  << std::endl;
	
	const_r_it_type 	const_r_it 		= map.rbegin();
	std::cout << "crbegin : " << const_r_it->first << ", " << const_r_it->second << std::endl;

	r_it_type			r_it4 		= map.rbegin(); r_it4++; r_it4++; r_it4++; r_it4++;
	const_r_it_type const_r_it4 	= r_it4;
	std::cout << "crbegin : " << const_r_it4->first << ", " << const_r_it4->second << std::endl;

	const_r_it_type 	const_r_it2 		= map.rend(); const_r_it2 --;
	std::cout << "crend-- : " << const_r_it2->first << ", " << const_r_it2->second << std::endl;

	for (const_r_it = map.rbegin(); const_r_it != map.rend(); const_r_it++)
		std::cout << const_r_it->first << ":" << const_r_it->second << " ";



	const_r_it_type 	const_r_it3 		= const_map.rbegin();
	std::cout << "cmap crbegin : " << const_r_it3->first << ", " << const_r_it3->second << std::endl;

	const_r_it_type 	const_r_it5 		= const_map.rbegin(); const_r_it5++; const_r_it5++; const_r_it5++; const_r_it5++;
	std::cout << "cmap crbegin ++x5 : " << const_r_it5->first << ", " << const_r_it5->second << std::endl;


	const_r_it_type 	const_r_it6 		= const_map.rend(); const_r_it6 --;
	std::cout << "cmap crend-- : " << const_r_it6->first << ", " << const_r_it6->second << std::endl;

	std::cout << "const map crit begin - end" << std::endl;
	for (const_r_it = const_map.rbegin(); const_r_it != const_map.rend(); const_r_it++)
		std::cout << const_r_it->first << ":" << const_r_it->second << " ";








	std::cout <<  "\n\nTEST find(value)"  << std::endl;

	it_type ret_find 		= map.find(convert<type_key_map>("a"));
	std::cout << "find(a) : " << ret_find->first << ", " << ret_find->second << std::endl;


	ret_find 		= map.find(convert<type_key_map>("za"));
	std::cout << "find(za) : " << ret_find->first << ", " << ret_find->second << std::endl;


	ret_find		= map.find(convert<type_key_map>("inexist"));
	if (ret_find == map.end())
		std::cout << "find(inexist)	: " << "not found" << std::endl;
	else 
		std::cout << "find(inexist)	: " << ret_find->first << ", " << ret_find->second << std::endl;





	
	const_it_type 	ret_const_find			= map.find(convert<type_key_map>("a"));
	std::cout << "find(a) : " << ret_const_find->first << ", " << ret_const_find->second << std::endl;

	const_it_type 	 ret_const_find2 		= map.find(convert<type_key_map>("za"));
	std::cout << "find(za) : " << ret_const_find2->first << ", " << ret_const_find2->second << std::endl;







	std::cout <<  "\n\nTEST erase(pos)"  << std::endl;

	map.erase(map.begin());
	display_map_list(map);

	it = map.end(); it--;
	map.erase(it);
	display_map_list(map);

	map.erase(map.find(convert<type_key_map>("z")));
	display_map_list(map);

	map.erase(map.find(convert<type_key_map>("d")));
	display_map_list(map);

	map.erase(map.find(convert<type_key_map>("AA")));
	display_map_list(map);

	map.erase(map.find(convert<type_key_map>("c")));
	display_map_list(map);

	map.erase(map.find(convert<type_key_map>("h")));
	display_map_list(map);






	std::cout <<  "\n\nTEST erase(first, last)"  << std::endl;

	it_type 		it_erase_end 		= map.begin(); it_erase_end++;

	map.erase(map.begin(), it_erase_end);
	display_map_list(map);

	it_erase_end = map.end(); it_erase_end--;
	map.erase(it_erase_end, map.end());
	display_map_list(map);

	map.erase(map.begin(), map.begin());
	display_map_list(map);

	map.erase(map.end(), map.end());
	display_map_list(map);

	it_type 		it_erase_begin 		= map.begin();
	for(int i = 0; i < 2; i++) { it_erase_begin++; }
	it_erase_end = map.begin();
	for ( int i = 0; i < 5; i++ ) { it_erase_end++;}
	map.erase(it_erase_begin, it_erase_end);
	display_map_list(map);


	it_erase_begin 		= map.begin();
	for(int i = 0; i < 5; i++) { it_erase_begin++; }
	it_erase_end 			= map.end();
	for(int i = 0; i < 5; i++) { it_erase_end--; }
	map.erase(it_erase_begin, it_erase_end);
	display_map_list(map);









	std::cout <<  "\n\nTEST erase(key)"  << std::endl;
	
	size_t ret = map.erase(convert<type_key_map>("w"));
	std::cout << "erase(w) : " << ret << std::endl;


	ret = map.erase(convert<type_key_map>("b"));
	std::cout << "erase(b) : " << ret << std::endl;

	ret =   map.erase(convert<type_key_map>("e"));
	std::cout << "erase(e) : " << ret << std::endl;

	ret =    map.erase(convert<type_key_map>("inexist"));
	std::cout << "erase(inexist) : " << ret << std::endl;







	std::cout <<  "\n\nTEST swap()"  << std::endl;

	std_map_t map_swap(map);
	map_swap.insert(pair(
		convert<type_key_map>("@"),
		convert<type_value_map>("777")
		)
	);
	display_map_list(map);
	display_map_list(map_swap);

	map.swap(map_swap);

	std_map_t map_swap2;
	map_swap.swap(map_swap2);
	display_map_list(map_swap);
	display_map_list(map_swap2);






	std::cout <<  "\n\nTEST constructor(first, last)"  << std::endl;
	
	std_map_t map_construct(map.begin(), map.end());
	display_map_list(map_construct);


	it_end = map.begin();
	for(int i = 0; i < 2; i++) { it_end++; }
	std_map_t map_construct2(map.begin(), it_end);
	display_map_list(map_construct2);

	it_type it_begin = map.begin();
	for(int i = 0; i < 2; i++) { it_begin++; }
	it_end = map.end();
	for(int i = 0; i < 2; i++) { it_end--; }
	std_map_t map_construct3(it_begin, it_end);
	display_map_list(map_construct3);




	const_it_type 	 cit_begin2 = map.begin();
	const_it_type 	 cit_end2 = map.end();
	std_map_t map_construct10(cit_begin2, cit_end2);
	display_map_list(map_construct10);

	std_map_t map_construct4(map.rbegin(), map.rend());
	display_map_list(map_construct4);


	r_it = map.rbegin();
	for(int i = 0; i < 2; i++) { r_it++; }
	r_it_type 	 r_it_end = map.rend();
	for(int i = 0; i < 2; i++) { r_it_end--; }
	std_map_t map_construct5(r_it, r_it_end);
	display_map_list(map_construct5);





	std::cout <<  "\n\nTEST copy constructor"  << std::endl;

	std_map_t map_cp(map);
	display_map_list(map_cp);

	std_map_t map_cp_cp(map_cp);
	display_map_list(map_cp_cp);




	std::cout <<  "\n\nTEST empty"  << std::endl;

	std_map_t empty_map;
	std::cout << "empty_map.empty() : " << empty_map.empty() << std::endl;
	std::cout << "map.empty() : " << map.empty() << std::endl;
	std::cout << "map_cp.empty() : " << map_cp.empty() << std::endl;
	std::cout << "map_cp_cp.empty() : " << map_cp_cp.empty() << std::endl;




	std::cout <<  "\n\nTEST at"  << std::endl;

	type_value_map ret_at = map.at(convert<type_key_map>("@"));
	std::cout << "map.at(@) : " << ret_at << std::endl;

	ret_at = map.at(convert<type_key_map>("s"));
	std::cout << "map.at(s) : " << ret_at << std::endl;



	it_type it_at = map.end(); it_at--;
	ret_at = map.at((it_at->first));
	std::cout << "map.at(it_at->first) : " << ret_at << std::endl;





	std::cout <<  "\n\nTEST []"  << std::endl;

	ret_at = map[convert<type_key_map>("@")];
	std::cout << "map[@] : " << ret_at << std::endl;

	ret_at = map[convert<type_key_map>("s")];
	std::cout << "map[s] : " << ret_at << std::endl;






	std::cout <<  "\n\nTEST size - max_size"  << std::endl;

	std::cout << "map.size() : " << map.size() << std::endl;
	std::cout << "map.max_size() : " << map.size() << std::endl;
	std::cout << "map_construct3.size() : " << map_construct3.size() << std::endl;
	map_construct3.clear();
	std::cout << "map_construct3.size() : " << map_construct3.size() << std::endl;

	std::cout << "max size : " << map.max_size() << std::endl;
	std::cout << "max size : " << map_cp.max_size() << std::endl;
	std::cout << "max size : " << map_construct4.max_size() << std::endl;



	std::cout <<  "\n\nTEST count"  << std::endl;

	std::cout << "map.count(@) : " << map.count(convert<type_key_map>("@")) << std::endl;
	std::cout << "map.count(s) : " << map.count(convert<type_key_map>("s")) << std::endl;
	std::cout << "map.count(0) : " << map.count(convert<type_key_map>("0")) << std::endl;
	std::cout << "map.count(1) : " << map.count(convert<type_key_map>("1")) << std::endl;
	





	std::cout <<  "\n\nTEST equal_range()"  << std::endl;
	STL_TYPE::pair<it_type, it_type> 			ret_equal_range;
	ret_equal_range = map.equal_range(convert<type_key_map>("-10"));
	std::cout << "map.equal_range(-10) first  : " << ret_equal_range.first->first << " " << ret_equal_range.second->first << std::endl;
	std::cout << "map.equal_range(-10) second : " << ret_equal_range.first->second << " " << ret_equal_range.second->second << std::endl;


	ret_equal_range = map.equal_range(convert<type_key_map>("0"));
	std::cout << "map.equal_range(0) first  : " << ret_equal_range.first->first << " " << ret_equal_range.second->first << std::endl;
	std::cout << "map.equal_range(0) second : " << ret_equal_range.first->second << " " << ret_equal_range.second->second << std::endl;

	ret_equal_range = map.equal_range(convert<type_key_map>("10"));
	std::cout << "map.equal_range(10) first  : " << ret_equal_range.first->first << " " << ret_equal_range.second->first << std::endl;
	std::cout << "map.equal_range(10) second : " << ret_equal_range.first->second << " " << ret_equal_range.second->second << std::endl;
	





	STL_TYPE::pair<const_it_type, const_it_type> 			ret_cequal_range;

	ret_cequal_range = map.equal_range(convert<type_key_map>("-10"));
	std::cout << "map.equal_range(-10) first  : " << ret_cequal_range.first->first << " " << ret_cequal_range.second->first << std::endl;
	std::cout << "map.equal_range(-10) second : " << ret_cequal_range.first->second << " " << ret_cequal_range.second->second << std::endl;

	ret_cequal_range = map.equal_range(convert<type_key_map>("0"));
	std::cout << "map.equal_range(0) first  : " << ret_cequal_range.first->first << " " << ret_cequal_range.second->first << std::endl;
	std::cout << "map.equal_range(0) second : " << ret_cequal_range.first->second << " " << ret_cequal_range.second->second << std::endl;

	ret_cequal_range = map.equal_range(convert<type_key_map>("10"));
	std::cout << "map.equal_range(10) first  : " << ret_cequal_range.first->first << " " << ret_cequal_range.second->first << std::endl;
	std::cout << "map.equal_range(10) second : " << ret_cequal_range.first->second << " " << ret_cequal_range.second->second << std::endl;









	std::cout <<  "\n\nTEST lower_bound()"  << std::endl;

	it_type 		ret_lower_bound;
	ret_lower_bound = map.lower_bound(convert<type_key_map>("-10"));
	std::cout << "map.lower_bound(-10) : " << ret_lower_bound->first << " " << ret_lower_bound->second << std::endl;

	ret_lower_bound = map.lower_bound(convert<type_key_map>("@"));
	std::cout << "map.lower_bound(@) : " << ret_lower_bound->first << " " << ret_lower_bound->second << std::endl;

	ret_lower_bound = map.lower_bound(convert<type_key_map>("s"));
	std::cout << "map.lower_bound(s) : " << ret_lower_bound->first << " " << ret_lower_bound->second << std::endl;

	ret_lower_bound = map.lower_bound(convert<type_key_map>("0"));
	std::cout << "map.lower_bound(0) : " << ret_lower_bound->first << " " << ret_lower_bound->second << std::endl;

	ret_lower_bound = map.lower_bound(convert<type_key_map>("10"));
	std::cout << "map.lower_bound(10) : " << ret_lower_bound->first << " " << ret_lower_bound->second << std::endl;








	std::cout <<  "\n\nTEST upper_bound()"  << std::endl;

	it_type 		ret_upper_bound;
	
	ret_upper_bound = map.upper_bound(convert<type_key_map>("-10"));
	std::cout << "map.upper_bound(-10) : " << ret_upper_bound->first << " " << ret_upper_bound->second << std::endl;

	ret_upper_bound = map.upper_bound(convert<type_key_map>("@"));
	std::cout << "map.upper_bound(@) : " << ret_upper_bound->first << " " << ret_upper_bound->second << std::endl;

	ret_upper_bound = map.upper_bound(convert<type_key_map>("r"));
	std::cout << "map.upper_bound(r) : " << ret_upper_bound->first << " " << ret_upper_bound->second << std::endl;




	std::cout <<  "\n\nTEST key_comp()"  << std::endl;

	bool ret_map_key_comp = map.key_comp()(
		convert<type_key_map>("a"),
		convert<type_key_map>("b")
	);
	std::cout << "map.key_comp()(a, b) : " << ret_map_key_comp << std::endl;

	ret_map_key_comp = map.key_comp()(
		convert<type_key_map>("b"),
		convert<type_key_map>("a")
	);
	std::cout << "map.key_comp()(b, a) : " << ret_map_key_comp << std::endl;


	ret_map_key_comp = map.key_comp()(
		convert<type_key_map>("a"),
		convert<type_key_map>("a")
	);
	std::cout << "map.key_comp()(a, a) : " << ret_map_key_comp << std::endl;


	ret_map_key_comp = map.key_comp()(
		convert<type_key_map>("b"),
		convert<type_key_map>("b")
	);
	std::cout << "map.key_comp()(b, b) : " << ret_map_key_comp << std::endl;


	ret_map_key_comp = map.key_comp()(
		convert<type_key_map>("abcdefghijklmnopqrstuvwxyz"),
		convert<type_key_map>("abcdefghijklmnopqrstuvwxyz1")
	);
	std::cout << "map.key_comp()(abcdefghijklmnopqrstuvwxyz, abcdefghijklmnopqrstuvwxyz1) : " << ret_map_key_comp << std::endl;








	std::cout <<  "\n\nTEST value_comp()"  << std::endl;


	pair 	ret_map_vc1 	= STL_TYPE::make_pair(
		convert<type_key_map>("a"),
		convert<type_value_map>("1")
	);
	pair 	ret_map_vc2 	= STL_TYPE::make_pair(
		convert<type_key_map>("b"),
		convert<type_value_map>("1")
	);

	bool ret_map_value_comp_ret     = map.value_comp()(ret_map_vc1, ret_map_vc2);
	std::cout << "map.value_comp()(a, b) : " << ret_map_value_comp_ret << std::endl;

	ret_map_vc1 	= STL_TYPE::make_pair(
		convert<type_key_map>("b"),
		convert<type_value_map>("1")
	);
	ret_map_vc2 	= STL_TYPE::make_pair(
		convert<type_key_map>("a"),
		convert<type_value_map>("1")
	);

	ret_map_value_comp_ret    = map.value_comp()(ret_map_vc1, ret_map_vc2);
	std::cout << "map.value_comp()(b, a) : " << ret_map_value_comp_ret << std::endl;






	std::cout <<  "\n\nTEST relational operation"  << std::endl;
	std_map_t map2;
	std_map_t map3;

	/* insert 10 random value */
	for (int i = 0; i < 10; i++)
	{
		std::string key_str = tostr(i);
		std::string value_str = tostr(i);

		map2.insert(STL_TYPE::make_pair(
			convert<type_key_map>(key_str),
			convert<type_value_map>(value_str)
		));

		map3.insert(STL_TYPE::make_pair(
			convert<type_key_map>(key_str),
			convert<type_value_map>(value_str)
		));
	}

	std::cout << "map2 == map3 : " << (map2 == map3) << std::endl;
	std::cout << "map2 != map3 : " << (map2 != map3) << std::endl;
	std::cout << "map2 < map3 : " << (map2 < map3) << std::endl;
	std::cout << "map2 > map3 : " << (map2 > map3) << std::endl;
	std::cout << "map2 <= map3 : " << (map2 <= map3) << std::endl;
	std::cout << "map2 >= map3 : " << (map2 >= map3) << std::endl;

	map3.insert(STL_TYPE::make_pair(
		convert<type_key_map>("100"),
		convert<type_value_map>("100")
	));

	std::cout << "map2 == map3 : " << (map2 == map3) << std::endl;
	std::cout << "map2 != map3 : " << (map2 != map3) << std::endl;
	std::cout << "map2 < map3 : " << (map2 < map3) << std::endl;
	std::cout << "map2 > map3 : " << (map2 > map3) << std::endl;
	std::cout << "map2 <= map3 : " << (map2 <= map3) << std::endl;
	std::cout << "map2 >= map3 : " << (map2 >= map3) << std::endl;

	map3.insert(STL_TYPE::make_pair(
		convert<type_key_map>("200"),
		convert<type_value_map>("200")
	));

	std::cout << "map2 == map3 : " << (map2 == map3) << std::endl;
	std::cout << "map2 != map3 : " << (map2 != map3) << std::endl;
	std::cout << "map2 < map3 : " << (map2 < map3) << std::endl;
	std::cout << "map2 > map3 : " << (map2 > map3) << std::endl;
	std::cout << "map2 <= map3 : " << (map2 <= map3) << std::endl;
	std::cout << "map2 >= map3 : " << (map2 >= map3) << std::endl;





	std::cout <<  "\n\nTEST clear"  << std::endl;

	map.clear();
	display_map_list(map);


	std_map_t empty_map2;
	empty_map2.clear();
	display_map_list(empty_map2);

}



/* insert 20 values following*/
template < typename T_map, typename T_pair, typename type_key_map, typename type_value_map>
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
}


template <typename M1>
void	display_map_list( M1 &map ) {
	typename M1::const_iterator it = map.begin();

	std::cout << std::endl << "----------------------------------------"
	<< "----------------------------------------" << std::endl;
	
	std::cout << "map size : " << map.size() << std::endl;

	for(; it != map.end(); it++) {
		std::cout << it->first << ":" << it->second << " ";
	}

	std::cout << std::endl << "----------------------------------------"
	<< "----------------------------------------\n\n" << std::endl;

}