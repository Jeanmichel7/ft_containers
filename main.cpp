/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:19:53 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/20 18:16:21 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define BLU "\033[0;34m"
#define MAG "\033[0;35m"
#define CYA "\033[0;36m"
#define END "\033[0m"

/* include vector
#include "utils.hpp"
#include "pair.hpp"

#include <vector>
#include "vector.hpp"

// #include <typeinfo>     // typeid
// #include <iostream>
*/

/* include map */
#include <map>
#include "map.hpp"

// tester
#include <sstream>
#include <string>

/*	function prediction for vector
	function pair
	bool mypredicate (int i, int j) {
	return (i==j);
	}

	bool mycomp (char c1, char c2)
	{ return std::tolower(c1)<std::tolower(c2); }


	struct Point { double x, y; };
	struct PointCmp {
		bool operator()(const Point& lhs, const Point& rhs) const {
			return lhs.x < rhs.x; // NB. intentionally ignores y
		}
	};
*/



template <typename T>
std::string to_string(T value)
{
	std::ostringstream os ;
	os << value ;
	return os.str() ;
}


void str_comp(std::string str, std::string ft_str, std::string msg) {
	// const std::string cstr 		= const_cast< std::string& >(str);
	// const std::string cft_str 	= const_cast< std::string& >(ft_str);

	// std::string test;
	// if (cstr == test || cft_str == test)
	// 	std::cout << "un des element a compar est null" << std::endl;
	if (str.compare(ft_str) != 0)
	{
		std::cout << RED "\n[KO] " END << msg << std::endl;
		std::cout << "std::map : " << str << std::endl;
		std::cout << "ft::map  : " << ft_str << std::endl << std::endl;
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



template < class T_map, class T_pair>
void fill_map(T_map *map) {
	map->insert(T_pair("g", 1));
	map->insert(T_pair("h", 2));
	map->insert(T_pair("i", 3));
	map->insert(T_pair("j", 4));
	map->insert(T_pair("k", 5));
	map->insert(T_pair("l", 6));
	map->insert(T_pair("m", 7));
	map->insert(T_pair("n", 8));
	map->insert(T_pair("o", 9));
	map->insert(T_pair("p", 10));
	map->insert(T_pair("q", 11));
	map->insert(T_pair("r", 12));
	map->insert(T_pair("s", 13));
	map->insert(T_pair("t", 14));
	map->insert(T_pair("u", 15));
	map->insert(T_pair("v", 16));
	map->insert(T_pair("w", 17));
	map->insert(T_pair("x", 18));
	map->insert(T_pair("y", 19));
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

int main()
{
	std::stringstream sstr;
	std::stringstream ft_sstr;

	std::string str;
	std::string ft_str;
{
	// std::vector<int> v;
	// v.push_back(1);
	// v.push_back(2);
	// v.push_back(3);

	// std::vector<int>::const_iterator itc = v.begin();
	// std::cout << "itc : " << *itc << std::endl;
	// itc++;
	// std::cout << "itc : " << *itc << std::endl;


	// // typedef std::iterator_traits<char> testee;

	// // testee t;
	// // std::cout << "iterator_traits<int>::iterator_category: "
	// // 	<< t.iterator_category.name() << std::endl;

	// // typedef std::iterator_traits<int>::value_type bli;
	// // std::cout << "iterator_traits<int>::value_type: "
	// // 	<< typeid(testee::value_type).name() << std::endl;

	// std::vector<int> test;
	// test.push_back(1);
	// test.push_back(2);
	// test.push_back(3);

	// std::cout << BLU "TEST max size : " END << test.max_size() << std::endl;

	// std::vector<int>::iterator it = test.begin();
	// for(; it != test.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;


	// // ft::Vector<int> test123123;
	// // test123123.push_back(1);
	// // test123123.push_back(2);
	// // test123123.push_back(3);
	// // std::cout << BLU "TEST max size ici: " END << test123123.max_size() << std::endl;




	// std::cout << BLU "TEST assign : " END << std::endl;
	// // test.assign(1000000000000000000, 1);										//SEGV
	// test.assign(10, 1);


	// //std::vector<int> test_copie = test;
	// //std::vector<int>::iterator it2 = test_copie.begin();
	// //for(; it2 != test_copie.end(); it2++)
	// //	std::cout << *it2 << std::endl;


	// //std::cout << "at : " << test.at(0) << std::endl;
	// //std::cout << "[2] : " << test[2] << std::endl;
	// //std::cout << "data: " 			<< test.data() 	<< std::endl;



	// std::cout << BLU "TEST rbegin derefenced : " END << *(test.rbegin()) << std::endl;
	// std::cout << BLU "TEST rbegin : \n" END;
	// std::vector<int>::reverse_iterator it2 = test.rbegin();

	// for(; it2 != test.rend(); it2++)
	// 	std::cout << *it2 << " ";
	// std::cout << std::endl;



	// std::cout << BLU "TEST template swap : " END << std::endl;
	// std::vector<int> test2(10, 1);


	// std::vector<int>::iterator it3 = test.begin();
	// for(; it3 != test.end(); it3++)
	// 	std::cout << *it3 ;
	// std::cout << "\n";


	// std::vector<int>::iterator it44 = test2.begin();
	// for(; it44 != test2.end(); it44++)
	// 	std::cout << *it44 ;
	// std::cout << "\n";


	// test.std::vector<int>::swap(test2);
	// std::cout << "\n\n";


	// std::vector<int>::iterator it30 = test.begin();
	// for(; it30 != test.end(); it30++)
	// 	std::cout << *it30 ;
	// std::cout << "\n";

	// std::vector<int>::iterator it40 = test2.begin();
	// for(; it40 != test2.end(); it40++)
	// 	std::cout << *it40 ;
	// std::cout << "\n";
	// //test.swap(test2);


	// std::cout << BLU "TEST reserve : " END <<  std::endl;
	
	// std::vector<int> test_reserve_real(10, 1);
	// //std::vector<int> test_reserve_real(2305843009213693952, 1);
	// std::vector<int>::iterator it404 = test_reserve_real.begin();

	// for(; it404 != test_reserve_real.end(); it404++)
	// 	std::cout << *it404 ;
	// std::cout << "\n";
	// std::cout << "capacity : " << test_reserve_real.capacity() << std::endl;

	// test_reserve_real.reserve(100);
	// //test_reserve_real.reserve(test_reserve_real.max_size());
	// //libc++abi.dylib: terminating with uncaught exception of type std::bad_alloc: std::bad_alloc

	// it404 = test_reserve_real.begin();
	// for(; it404 != test_reserve_real.end(); it404++)
	// 	std::cout << *it404 ;
	// std::cout << "\n";
	// std::cout << "capacity 	: " << test_reserve_real.capacity() << std::endl;
	// std::cout << "size 		: " << test_reserve_real.size() << std::endl;


	// std::cout << BLU "TEST erase() : " END << std::endl;
	// test.erase(test.begin());
	// // test.erase(test.end());										//SEGF ABORT negative-param

	
	// it404 = test.begin();
	// for(; it404 != test.end(); it404++)
	// 	std::cout << *it404 ;
	// std::cout << "\n";
	// std::cout << "capacity 	: " << test.capacity() << std::endl;
	// std::cout << "size 		: " << test.size() << std::endl;








	// std::cout << BLU "TEST clear real : " END << std::endl;
	// test.clear();
	// std::cout << "size : " << test.size() << std::endl;
	// std::cout << "capacity : " << test.capacity() << std::endl;
	// std::cout << "empty : " << test.empty() << std::endl;


	// //std::cout << BLU "TEST Insert()" END << std::endl;
	// //std::vector<int> test_insert1;
	// //std::vector<int>::iterator iti;

	// //iti = test_insert1.begin();
	// //test_insert1.insert(iti, 42);

	// //iti = test_insert1.begin();
	// //test_insert1.insert(iti, 100000000000000, 42);

	// //iti = test_insert1.begin();
	// //test_insert1.insert(iti, 10000000000000, 42);













	// std::cout << "\n\n\n\nMy vector : \n\n\n";






	// std::cout << BLU "TEST constructor : " END << std::endl;
	// ft::Vector<int> my_vector;

	// my_vector.push_back(1);
	// my_vector.push_back(2);
	// my_vector.push_back(3);
	// my_vector.push_back(4);
	// my_vector.display("");

	// ft::Vector<int> my_vectr(my_vector.begin(), my_vector.end());
	// my_vectr.display("my_vectr(my_vector.begin(), my_vector.end())");




	// std::cout << BLU "TEST constructor count : " END << std::endl;
	// ft::Vector<int> my_vector_count(10, 3);
	// my_vector_count.display("my_vector_count(10, 1)");

	// ft::Vector<int>::iterator it_v_count_begin = my_vector_count.begin();
	// ft::Vector<int>::iterator it_v_count_end = my_vector_count.end();





	// std::cout << BLU "TEST constructor iterator : " END << std::endl;
	// ft::Vector<int> my_vector_iterator(it_v_count_begin, it_v_count_end);
	// my_vector_iterator.display(" my_vector_iterator(it_v_count_begin, it_v_count_end)");




	
	// std::cout << BLU "TEST popback real : " END;
	// // std::cout << my_vector.back() << std::endl; 					//SEGV
	// my_vector.pop_back();
	// my_vector.display("pop_back()");

	// // std::cout << "get allocator 	: " << my_vector.get_allocator() << std::endl;
	// std::cout << "capacity 	: " << my_vector.capacity() << std::endl;
	// std::cout << "at(2)		: " << my_vector.at(2)		<< std::endl;
	// my_vector.at(2) = 12000;
	// my_vector.display("");
	// std::cout << "at(2)		: " << my_vector.at(2) 		<< std::endl;
	// std::cout << ".[2]		: " << my_vector[2] 		<< std::endl;
	// std::cout << "front		: " << my_vector.front()	<< std::endl;
	// std::cout << "back		: " << my_vector.back() 	<< std::endl;
	// std::cout << "data		: " << my_vector.data() 	<< std::endl;


	// std::cout << BLU "\n\nTEST assign : " END << std::endl;
	// // my_vector.assign(100000000000000000000000000000000000000,2);			//SEGV
	// // my_vector.assign(100000000000000000000000000000,2); //SEGV				//exception bad_alloc
	// my_vector.assign(15,2);
	// my_vector.display("assign(15,2)");


	// std::cout << BLU "\n\nTEST assign template iterator : " END << std::endl;
	// my_vector.assign(it_v_count_begin, it_v_count_end);
	// my_vector.display("assign(it_v_count_begin, it_v_count_end)");






	// std::cout << BLU "TEST Insert()" END << std::endl;
	// ft::Vector<int>::iterator it_insert_begin = my_vector.begin();

	// my_vector.insert(it_insert_begin, 42);
	// my_vector.display("insert(it_insert_begin, 42)");


	// ft::Vector<int>::iterator it_insert_end = my_vector.end();

	// my_vector.insert(it_insert_end, 42);
	// my_vector.display("insert(it_insert_end, 42)");



	// for(int i = 0; i < 10; i++)
	// {
	// 	ft::Vector<int>::iterator it_insert_middle = my_vector.begin() + (my_vector.size() / 2);

	// 	my_vector.insert(it_insert_middle, 21);
	// 	my_vector.display("insert(it_insert_middle, 21)");
	// }


	// ft::Vector<int>::iterator it_insert_middle = my_vector.begin() + (my_vector.size() / 2);
	// my_vector.insert(it_insert_middle, 2, 2);
	// my_vector.display("insert(it_insert_middle, 2, 2)");


	// std::cout << BLU "TEST Insert(pos, n, v) avec depassement " END << std::endl;

	// it_insert_middle = my_vector.begin() + (my_vector.size() / 2);
	// my_vector.insert(it_insert_middle, 20, 33);
	// my_vector.display("insert(it_insert_middle, 20, 33)");

	// it_insert_end = my_vector.end();
	// my_vector.insert(it_insert_end, 3, 13);
	// my_vector.display("insert(it_insert_end, 10, 5)");

	// std::cout << BLU "TEST Insert(pos, n, v) avec depassement size_max() " END << std::endl;

	// my_vector.insert(my_vector.begin(), my_vector.max_size(), 5);
	// my_vector.display("insert(my_vector.begin(), my_vector.max_size(), 5)");




	// // my_vector.erase(my_vector.begin(), my_vector.end());

	// ft::Vector<int> my_tmp_vector(5,5);
	// my_tmp_vector.display("my_tmp_vector");


	// ft::Vector<int>::iterator	it_tmp_first = my_tmp_vector.begin();
	// ft::Vector<int>::iterator	it_tmp_half = my_tmp_vector.begin() + (my_tmp_vector.size() / 2);



	// my_vector.resize(12);
	// my_vector.display("resize(12)");

	// std::cout << BLU "TEST Insert(pos, first, last)" END << std::endl;

	// my_vector.insert(my_vector.begin(), it_tmp_first, it_tmp_half);
	// my_vector.display("insert(my_vector.begin(), it_tmp_first, it_tmp_half)");




	// it_tmp_half = my_tmp_vector.begin() + (my_tmp_vector.size() / 2);
	// ft::Vector<int>::iterator	it_tmp_end = my_tmp_vector.end();

	// my_vector.insert(my_vector.begin(), it_tmp_half, it_tmp_end);
	// my_vector.display("insert(my_vector.begin(), it_tmp_half, it_tmp_end)");





	// ft::Vector<int> my_tmp_vector2(10,10);
	// my_tmp_vector2.display("my_tmp_vector2(10, 10)");

	// ft::Vector<int>::iterator it_tmp2_begin = my_tmp_vector2.begin();
	// ft::Vector<int>::iterator it_tmp2_end = my_tmp_vector2.end();

	// ft::Vector<int>::iterator it_middle = my_vector.begin() + (my_vector.size() / 2);
	// my_vector.insert(it_middle, it_tmp2_begin, it_tmp2_end);
	// my_vector.display("insert(it_middle, it_tmp_begin, it_tmp_end)");


	// it_tmp2_begin = my_tmp_vector2.begin();
	// it_tmp2_end = my_tmp_vector2.end();
	// it_middle = my_vector.begin() + (my_vector.size() / 2);
	// my_vector.insert(it_middle, it_tmp2_begin, it_tmp2_end);
	// my_vector.display("insert(it_middle, it_tmp_begin, it_tmp_end)");


	// it_tmp2_begin = my_tmp_vector2.begin();
	// it_tmp2_end = my_tmp_vector2.end();
	// it_middle = my_vector.begin() + (my_vector.size() / 2);
	// my_vector.insert(it_middle, it_tmp2_begin, it_tmp2_end);
	// my_vector.display("insert(it_middle, it_tmp_begin, it_tmp_end)");








	// ft::Vector<int> test_insert1;
	// ft::Vector<int>::iterator iti;

	// iti = test_insert1.begin();
	// test_insert1.insert(iti, 42);
	// test_insert1.display("insert(iti, 42)");


	// iti = test_insert1.begin();
	// test_insert1.insert(iti, 42, 42);
	// test_insert1.display("insert(iti, 42, 42)");

	// iti = test_insert1.begin();
	// // test_insert1.insert(iti, 100000000000000, 42);
	// test_insert1.insert(iti, 20, 42);
	// test_insert1.display("insert(iti, test_insert1.max_size(), 42)");

	// iti = test_insert1.begin();
	// test_insert1.insert(iti, test_insert1.max_size(), 42);
	// test_insert1.display("insert(iti, test_insert1.max_size(), 42)");










	// std::cout << BLU "\n\nTEST operator comparaison : " END << std::endl;
	// std::cout 	<< my_vector[0] << " "
	// 			<< (my_vector[0] > my_vector[0] ? "plus grand" : "plus petit ou egal" )
	// 			<< " que " << my_vector[0] << std::endl;

	// my_vector.display("");



	// ft::Vector<char> my_vector2;
	// std::cout << BLU "TEST empty	: " END << my_vector2.empty() << std::endl;
	// std::cout << BLU "TEST size	: " END << my_vector2.size() << std::endl;
	// std::cout << BLU "TEST max size	: " END << my_vector2.max_size() << std::endl;


	// //std::cout << BLU "TEST popback : " END << my_vector2.back() << std::endl;	//SEGV
	
	// std::cout << BLU "TEST push back " END<< std::endl;
	// my_vector2.push_back('a');
	// my_vector2.push_back('b');
	// my_vector2.push_back('c');
	// my_vector2.push_back('d');
	// my_vector2.push_back('e');
	// my_vector2.push_back('f');
	// my_vector2.push_back('g');
	// my_vector2.push_back('h');
	// my_vector2.push_back('i');
	// my_vector2.push_back('j');
	// my_vector2.display("");


	// std::cout << BLU "TEST back 	: " END << my_vector2.back() 	<< std::endl;
	// std::cout << BLU "TEST empty 	: " END << my_vector2.empty() 	<< std::endl;
	// std::cout << BLU "TEST size 	: " END << my_vector2.size() 	<< std::endl;


	// std::cout << BLU "TEST iterator : " END << std::endl;
	// ft::Vector<char>::iterator it5 = my_vector2.begin();
	// for(; it5 != my_vector2.end(); it5++)
	// 	std::cout << *it5 << " ";
	// std::cout << std::endl;

	

	// std::cout << BLU "TEST reverse_iterator : " END << std::endl;
	// ft::Vector<char>::reverse_iterator it4 = my_vector2.rbegin();
	// ft::Vector<char>::reverse_iterator it4e = my_vector2.rend();
	// for(; it4 != it4e; it4++)
	// 	std::cout << *it4 << " " ;
	// std::cout << std::endl;
	// my_vector2.display("");


	// std::cout << BLU "TEST popback  " END;
	// my_vector2.pop_back();
	// my_vector2.display(""); 


	// std::cout << BLU "TEST resize 15 " END;
	// my_vector2.resize(15);
	// my_vector2.display("");

	// std::cout << BLU "TEST resize 5 " END;
	// my_vector2.resize(5);
	// my_vector2.display("");

	// std::cout << BLU "TEST resize 20 " END;
	// my_vector2.resize(20, 's');
	// my_vector2.display("");


	// std::cout << BLU "TEST swap : " END << std::endl;
	// ft::Vector<int> test_swap(10, 1);
	// ft::Vector<int> test_swap2(15,2);
	// test_swap.display("");
	// test_swap2.display("");
	// test_swap.ft::Vector<int>::swap(test_swap2);
	// test_swap.display("");
	// test_swap2.display("");












	// std::cout << BLU "TEST reserve : " END <<  std::endl;
	// ft::Vector<long long unsigned> test_reserve(10, 1);
	// ft::Vector<long long unsigned>::iterator it4040 = test_reserve.begin();

	// for(; it4040 != test_reserve.end(); it4040++)
	// 	std::cout << *it4040 ;
	// std::cout << "\n";
	// std::cout << "capacity : " << test_reserve.capacity() << std::endl;

	// // test_reserve.reserve(test_reserve.max_size());
	// // test_reserve.reserve(1000000000000000000);
	// test_reserve.reserve(100);

	// it4040 = test_reserve.begin();
	// for(; it4040 != test_reserve.end(); it4040++)
	// 	std::cout << *it4040 ;
	// std::cout << "\n";
	// std::cout << "capacity : " << test_reserve.capacity() << std::endl;









	// std::cout << BLU "\nTEST erase(n) : " END <<  std::endl;
	// ft::Vector<int> test_erase;
	// for(int i = 0; i < 10; i++) {
	// 	test_erase.push_back(i);
	// }
	// test_erase.display("test_erase");

	// test_erase.erase(test_erase.begin());
	// test_erase.display("test_erase.begin()");

	// test_erase.erase(test_erase.begin() + 5);
	// test_erase.display("test_erase.begin() + 5");

	// // test_erase.erase(test_erase.end());								// segv
	// test_erase.erase(test_erase.end() - 1);
	// test_erase.display("test_erase.end() - 1");



	// test_erase.insert(test_erase.begin(), 0);
	// test_erase.insert(test_erase.begin() + 6, 6);
	// test_erase.insert(test_erase.begin() + 9, 9);
	// test_erase.display("");

	// std::cout << BLU "\nTEST erase(first, last) : " END <<  std::endl;


	// test_erase.erase(test_erase.begin() + 5, test_erase.begin() + 8);
	// test_erase.display("test_erase.begin() + 5, test_erase.begin() + 8");






	// std::cout << BLU "\nTEST clear : " END << std::endl;
	// test_reserve.clear();
	// std::cout << "size 		: " << test_reserve.size() << std::endl;
	// std::cout << "capacity 	: " << test_reserve.capacity() << std::endl;
	// std::cout << "empty() 	: " << test_reserve.empty() << std::endl;




	// std::cout << BLU "\nTEST const  : " END << std::endl;

	// // ft::Vector<int> vm(10, 10);
	// // ft::Vector<int>::const_iterator itc2 = vm.begin();
	// // std::cout << "itc : " << *itc2 << std::endl;




	// ft::Vector<int> test_const;
	// test_const.push_back(1);
	// test_const.push_back(2);
	// test_const.push_back(3);

	// test_const.display("test_const");
	// ft::Vector<int>::const_iterator it_const  = test_const.begin();
	// std::cout << "const it : " << *it_const << std::endl;
	// std::cout << "const it : " << *(it_const + 1) << std::endl;
	// it_const++;
	// std::cout << "const it : " << *(it_const) << std::endl;







	// std::cout << BLU "\nTEST equal() : " END << std::endl;
	// // bool mypredicate(int i, int j)
	// // {
	// // 	return (i == j);
	// // }

	// int myints[] = {20, 40, 60, 80, 100};		   //   myints: 20 40 60 80 100
	// std::vector<int> myvector(myints, myints + 5); // myvector: 20 40 60 80 100

	// // using default comparison:
	// if (std::equal(myvector.begin(), myvector.end(), myints))
	// 	std::cout << "The contents of both sequences are equal.\n";
	// else
	// 	std::cout << "The contents of both sequences differ.\n";

	// if (ft::equal(myvector.begin(), myvector.end(), myints))
	// 	std::cout << "The contents of both sequences are equal.\n";
	// else
	// 	std::cout << "The contents of both sequences differ.\n";

	// myvector[3] = 81; // myvector: 20 40 60 81 100

	// // using predicate comparison:
	// if (std::equal(myvector.begin(), myvector.end(), myints, mypredicate))
	// 	std::cout << "The contents of both sequences are equal.\n";
	// else
	// 	std::cout << "The contents of both sequences differ.\n";

	// if (ft::equal(myvector.begin(), myvector.end(), myints, mypredicate))
	// 	std::cout << "The contents of both sequences are equal.\n\n\n";
	// else
	// 	std::cout << "The contents of both sequences differ.\n\n\n";















	// std::cout << BLU "\nTEST lexicographically() : " END << std::endl;

	// char foo[] = "Apple";
	// char bar[] = "apartment";

	// std::cout << std::boolalpha;

	// std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

	// std::cout << "Using default comparison (operator<): ";
	// std::cout << std::lexicographical_compare(foo, foo + 5, bar, bar + 9);
	// std::cout << '\n';
	// std::cout << "Using default comparison (operator<): ";
	// std::cout << ft::lexicographical_compare(foo, foo + 5, bar, bar + 9);
	// std::cout << '\n';

	// std::cout << "Using mycomp as comparison object: ";
	// std::cout << std::lexicographical_compare(foo, foo + 5, bar, bar + 9, mycomp);
	// std::cout << '\n';
	// std::cout << "Using mycomp as comparison object: ";
	// std::cout << ft::lexicographical_compare(foo, foo + 5, bar, bar + 9, mycomp);
	// std::cout << "\n\n";







	// std::cout << BLU "\nTEST Pair() : " END << std::endl;

	// std::pair<int, char> foo1(10, 'z');
	// std::pair<int, char> bar1(90, 'a');

	// if (foo1 == bar1)
	// 	std::cout << "foo1 and bar1 are equal\n";
	// if (foo1 != bar1)
	// 	std::cout << "foo1 and bar1 are not equal\n";
	// if (foo1 < bar1)
	// 	std::cout << "foo1 is less than bar1\n";
	// if (foo1 > bar1)
	// 	std::cout << "foo1 is greater than bar1\n";
	// if (foo1 <= bar1)
	// 	std::cout << "foo1 is less than or equal to bar1\n";
	// if (foo1 >= bar1)
	// 	std::cout << "foo1 is greater than or equal to bar1\n";


	// ft::pair<int, char> foo2(10, 'z');
	// ft::pair<int, char> bar2(90, 'a');

	// if (foo2 == bar2)
	// 	std::cout << "foo2 and bar2 are equal\n";
	// if (foo2 != bar2)
	// 	std::cout << "foo2 and bar2 are not equal\n";
	// if (foo2 < bar2)
	// 	std::cout << "foo2 is less than bar2\n";
	// if (foo2 > bar2)
	// 	std::cout << "foo2 is greater than bar2\n";
	// if (foo2 <= bar2)
	// 	std::cout << "foo2 is less than or equal to bar2\n";
	// if (foo2 >= bar2)
	// 	std::cout << "foo2 is greater than or equal to bar2\n";








	// std::cout << BLU "\nTEST make_pair() : " END << std::endl;

	// std::pair<int, int> foo3;
	// std::pair<int, int> bar3;

	// foo3 = std::make_pair(10, 20);
	// bar3 = std::make_pair(10.5, 'A'); // ok: implicit conversion from pair<double,char>

	// std::cout << "foo3: " << foo3.first << ", " << foo3.second << '\n';
	// std::cout << "bar3: " << bar3.first << ", " << bar3.second << '\n';


	// ft::pair<int, int> foo4;
	// ft::pair<int, int> bar4;

	// foo4 = ft::make_pair(10, 20);
	// bar4 = ft::make_pair(10.5, 'A'); // ok: implicit conversion from pair<double,char>

	// std::cout << "foo4: " << foo4.first << ", " << foo4.second << '\n';
	// std::cout << "bar4: " << bar4.first << ", " << bar4.second << '\n';


	// // C++ 11
	// // std::cout << BLU "\nTEST pair swap : " END << std::endl;

	// // std::cout << "foo1 contains: " << foo1.first << " and " << foo1.second << '\n';
	// // std::cout << "bar1 contains: " << bar1.first << " and " << bar1.second << '\n';
	// // std::swap(foo1,bar1);
	// // std::cout << "foo1 contains: " << foo1.first << " and " << foo1.second << '\n';
	// // std::cout << "bar1 contains: " << bar1.first << " and " << bar1.second << '\n';


	// // std::cout << "foo2 contains: " << foo2.first << " and " << foo2.second << '\n';
	// // std::cout << "bar2 contains: " << bar2.first << " and " << bar2.second << '\n';
	// // // ft::pair<int, char>::swap(foo2,bar2);
	// // ft::swap(foo2,bar2);
	// // std::cout << "foo2 contains: " << foo2.first << " and " << foo2.second << '\n';
	// // std::cout << "bar2 contains: " << bar2.first << " and " << bar2.second << '\n';
}
{
/* ***************************************************** */
/*                                                       */
/*                                                       */
/*                          MAPS                         */
/*                                                       */
/*                                                       */
/* ***************************************************** */


	typedef	std::string		type_key_map1;
	typedef	int						type_value_map1;

	// typedef int						type_key_map2;
	// typedef int						type_value_map2;


	/* ***************************************************** */
	/*                                                       */
	/*                          MAPS                         */
	/*                std::map< std::string, int >           */
	/*                                                       */
	/* ***************************************************** */
	std::cout << BLU "map<string, int> " END << std::endl;

/*
	typedef const ft::RedBlackTree<ft::pair<const Key, T>, Compare>::const_iterator 
	ft::map<Key, T, Compare, Allocator>::const_iterator
*/
	/* define type map */
	typedef std::map< std::string, int > 							std_map_str_int;
	typedef  ft::map< std::string, int > 							ft_map_str_int;

	/* define type iterator */
	typedef std_map_str_int::iterator 								it_type;
	typedef std_map_str_int::const_iterator 					const_it_type;
	typedef std_map_str_int::reverse_iterator 				r_it_type;
	typedef std_map_str_int::const_reverse_iterator 	const_r_it_type;

	typedef  ft_map_str_int::iterator 								ft_it_type;
	typedef  ft_map_str_int::const_iterator 					ft_const_it_type;
	typedef  ft_map_str_int::reverse_iterator 				ft_r_it_type;
	typedef  ft_map_str_int::const_reverse_iterator  	ft_const_r_it_type;

	/* define type pair */
	typedef std::pair<std::string, int> 							pair;
	typedef  ft::pair<std::string, int> 							ft_pair;


	std::cout << MAG "TEST constructor map() " END << std::endl;
	std_map_str_int map;
	 ft_map_str_int ft_map;



	/* ***************************************************** */
	/*                     INSERT(value)                     */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	// ft_map.display_tree();
	std::cout << MAG "\n\nTEST insert( value )" END << std::endl;

	/* insert ("b", 2) */
	std::pair< it_type, bool > ret_insert_value 		= map.insert(pair("b", 2));
	ft::pair< ft_it_type, bool > ft_ret_insert_value 	= ft_map.insert(ft_pair("b", 2));
	str_comp(ret_insert_value.first->first, ft_ret_insert_value.first->first, "insert(value(ft_pair(\"b\", 2)))");
	str_comp(to_string(ret_insert_value.first->second), to_string(ft_ret_insert_value.first->second), "insert(value(ft_pair(\"b\", 2)))");


	/* insert ("a", 1) */
	ret_insert_value 	= map.insert(pair("a", 1));
	ft_ret_insert_value = ft_map.insert(ft_pair("a", 1));
	str_comp(ret_insert_value.first->first, ft_ret_insert_value.first->first, "insert(value(ft_pair(\"a\", 1))) -> first");
	str_comp(to_string(ret_insert_value.first->second), to_string(ft_ret_insert_value.first->second), "insert(value(ft_pair(\"a\", 1))) -> second");
	ft_map.display_tree();


	/* insert ("c", 3) */
	ret_insert_value 	= map.insert(pair("c", 3));
	ft_ret_insert_value = ft_map.insert(ft_pair("c", 3));
	str_comp(ret_insert_value.first->first, ft_ret_insert_value.first->first, "insert(value(ft_pair(\"c\", 3))) -> first");
	str_comp(to_string(ret_insert_value.first->second), to_string(ft_ret_insert_value.first->second), "insert(value(ft_pair(\"c\", 3))) -> second");

	/* insert ("e", 5) */
	ret_insert_value 	= map.insert(pair("e", 5));
	ft_ret_insert_value = ft_map.insert(ft_pair("e", 5));
	str_comp(ret_insert_value.first->first, ft_ret_insert_value.first->first, "insert(value(ft_pair(\"e\", 5))) -> first");
	str_comp(to_string(ret_insert_value.first->second), to_string(ft_ret_insert_value.first->second), "insert(value(ft_pair(\"e\", 5))) -> second");

	/* insert ("d", 4) */
	ret_insert_value 	= map.insert(pair("d", 4));
	ft_ret_insert_value = ft_map.insert(ft_pair("d", 4));
	str_comp(ret_insert_value.first->first, ft_ret_insert_value.first->first, "insert(value(ft_pair(\"d\", 4))) -> first");
	str_comp(to_string(ret_insert_value.first->second), to_string(ft_ret_insert_value.first->second), "insert(value(ft_pair(\"d\", 4))) -> second");

	/* insert ("d", 4) DOUBLON*/
	ret_insert_value 	= map.insert(pair("d", 4));
	ft_ret_insert_value = ft_map.insert(ft_pair("d", 4));
	str_comp(ret_insert_value.first->first, ft_ret_insert_value.first->first, "insert(value(ft_pair(\"d\", 4))) -> first");
	str_comp(to_string(ret_insert_value.first->second), to_string(ft_ret_insert_value.first->second), "insert(value(ft_pair(\"d\", 4))) -> second");

	/* insert ("d", 10) DOUBLON*/
	ret_insert_value 	= map.insert(pair("d", 10));
	ft_ret_insert_value = ft_map.insert(ft_pair("d", 10));
	str_comp(ret_insert_value.first->first, ft_ret_insert_value.first->first, "insert(value(ft_pair(\"d\", 10))) -> first");
	str_comp(to_string(ret_insert_value.first->second), to_string(ft_ret_insert_value.first->second), "insert(value(ft_pair(\"d\", 10))) -> second");


	/* insert many value */
	fill_map< std_map_str_int, pair >(&map);
	fill_map< ft_map_str_int, ft_pair >(&ft_map);
	

	/* check all maps */
	comp_map(map, ft_map, "comp map ft_map");




	ft_map.display_tree(";kjbf;kdjf;dskj");



	/* ***************************************************** */
	/*                  INSERT(hint, value)                  */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST insert( hint, value )" END << std::endl;


	/* insert(begin(), 1) */
	it_type it_insert_hint 				= map.insert(map.begin()++, pair("A", 1));
	ft_it_type ft_it_insert_hint 	= ft_map.insert(ft_map.begin()++, ft_pair("A", 1));
	str_comp(it_insert_hint->first, ft_it_insert_hint->first, "insert(begin(), value(ft_pair(\"A\", 1))) -> first");
	str_comp(to_string(it_insert_hint->second), to_string(ft_it_insert_hint->second), "insert(begin(), value(ft_pair(\"A\", 1))) -> second");


	/* insert(begin(), 1) */
	it_insert_hint 			= map.insert(map.begin(), pair("AA", 10));
	ft_it_insert_hint 	= ft_map.insert(ft_map.begin(), ft_pair("AA", 10));
	str_comp(it_insert_hint->first, ft_it_insert_hint->first, "insert(begin(), value(ft_pair(\"z\", 1))) -> first");
	str_comp(to_string(it_insert_hint->second), to_string(ft_it_insert_hint->second), "insert(begin(), value(ft_pair(\"z\", 1))) -> second");

	/* insert(begin(), "z") */
	it_insert_hint			= map.insert(map.begin(), pair("yz", 11));
	ft_it_insert_hint 	= ft_map.insert(ft_map.begin(), ft_pair("yz", 11));
	str_comp(it_insert_hint->first, ft_it_insert_hint->first, "insert(begin(), value(ft_pair(\"z\", 1))) -> first");
	str_comp(to_string(it_insert_hint->second), to_string(ft_it_insert_hint->second), "insert(begin(), value(ft_pair(\"z\", 1))) -> second");


	/* insert(end(), 1) */
	it_insert_hint			= map.insert(map.end(), pair("z", 12));
	ft_it_insert_hint 	= ft_map.insert(ft_map.end(), ft_pair("z", 12));
	str_comp(it_insert_hint->first, ft_it_insert_hint->first, "insert(end(), value(ft_pair(\"z\", 12))) -> first");
	str_comp(to_string(it_insert_hint->second), to_string(ft_it_insert_hint->second), "insert(end(), value(ft_pair(\"z\", 12))) -> second");

	/* insert(end(), "za") */
	it_insert_hint 			= map.insert(map.end(), pair("za", 13));
	ft_it_insert_hint 	= ft_map.insert(ft_map.end(), ft_pair("za", 13));
	str_comp(it_insert_hint->first, ft_it_insert_hint->first, "insert(end(), value(ft_pair(\"za\", 1))) -> first");
	str_comp(to_string(it_insert_hint->second), to_string(ft_it_insert_hint->second), "insert(end(), value(ft_pair(\"za\", 1))) -> second");

	/* insert(end(), "c") */
	it_insert_hint 			= map.insert(map.end(), pair("c", 15));
	ft_it_insert_hint 	= ft_map.insert(ft_map.end(), ft_pair("c", 15));
	str_comp(it_insert_hint->first, ft_it_insert_hint->first, "insert(end(), value(ft_pair(\"c\", 1))) -> first");
	str_comp(to_string(it_insert_hint->second), to_string(ft_it_insert_hint->second), "insert(end(), value(ft_pair(\"c\", 1))) -> second");




	/* insert begin()+5, "e" */
	std::string val_to_insert = "ee";
	int 		pos_to_insert = 5;
	int			value_to_insert = 42;

	it_type 		it_test 		= map.begin();
	ft_it_type 	ft_it_test 	= ft_map.begin();
	for(int i = 0; i < pos_to_insert; i++) it_test++;
	for(int i = 0; i < pos_to_insert; i++) ft_it_test++;

	it_type it_test2 = map.insert(it_test, pair(val_to_insert, value_to_insert));
	sstr << it_test2->first << ":" << it_test2->second << std::endl;
	ft_it_type ft_it_test2 = ft_map.insert(ft_it_test, ft_pair(val_to_insert, value_to_insert));
	ft_sstr << ft_it_test2->first << ":" << ft_it_test2->second << std::endl;

	str_comp(sstr.str(), ft_sstr.str(), "begin() -> end()");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();





	ft_map.display_tree("wtf");


	/* ***************************************************** */
	/*                  INSERT(first, last)                  */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST insert( first, last )" END << std::endl;

	std_map_str_int map_insert_f_l;
	ft_map_str_int ft_map_insert_f_l;

	/* insert(begin(), end()) */
	map_insert_f_l.insert(map.begin(), map.end());
	ft_map_insert_f_l.insert(ft_map.begin(), ft_map.end());

	for (it_type it = map_insert_f_l.begin(); it != map_insert_f_l.end(); it++)
		sstr << it->first << ":" << it->second << " ";
	for (ft_it_type it = ft_map_insert_f_l.begin(); it != ft_map_insert_f_l.end(); it++)
		ft_sstr << it->first << ":" << it->second << " ";
	str_comp(sstr.str(), ft_sstr.str(), "insert( first, last )");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	// clear map;


	/* insert with iterator + 3 */
	it_type it_insert_f_l_end 		= map.begin();
	ft_it_type ft_it_insert_f_l_end = ft_map.begin();

	for(int i = 0; i < 3; i++) { it_insert_f_l_end++; ft_it_insert_f_l_end++; }

	map_insert_f_l.insert(map.begin(), it_insert_f_l_end);
	ft_map_insert_f_l.insert(ft_map.begin(), ft_it_insert_f_l_end);

	for (it_type it = map_insert_f_l.begin(); it != map_insert_f_l.end(); it++)
		sstr << it->first << ":" << it->second << " ";
	for (ft_it_type it = ft_map_insert_f_l.begin(); it != ft_map_insert_f_l.end(); it++)
		ft_sstr << it->first << ":" << it->second << " ";
		
	str_comp(sstr.str(), ft_sstr.str(), "insert( first, first + 3 )");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
	// clear map;



	/* insert with const iterator */
	it_type 			it_end 				= map.begin();
	ft_it_type 			ft_it_end 			= ft_map.begin();
	for(int i = 0; i < 5; i++) { it_end++; ft_it_end++; }
	const_it_type 		cit_end1 		= it_end;
	ft_const_it_type 	ft_cit_end1 	= ft_it_end;
	const_it_type 		cit_begin 		= map.begin();
	ft_const_it_type 	ft_cit_begin 	= ft_map.begin();

	map_insert_f_l.insert(cit_begin, cit_end1);
	ft_map_insert_f_l.insert(ft_cit_begin, ft_cit_end1);
	comp_map(map_insert_f_l, ft_map_insert_f_l, "insert( const_iterator, const_iterator +5 )");
	// clear map;


	/* insert with reverse iterator */
	map_insert_f_l.insert(map.rbegin(), map.rend());
	ft_map_insert_f_l.insert(ft_map.rbegin(), ft_map.rend());
	comp_map(map_insert_f_l, ft_map_insert_f_l, "insert( reverse_iterator, reverse_iterator )");
	// clear map;

	
	/* insert with reverse iterator + 3 */
	r_it_type 	 rit_insert_f_l 	= map.rbegin();
	ft_r_it_type ft_rit_insert_f_l 	= ft_map.rbegin();
	for(int i = 0; i < 3; i++) { rit_insert_f_l++; ft_rit_insert_f_l++; }
	map_insert_f_l.insert(map.rbegin(), rit_insert_f_l);
	ft_map_insert_f_l.insert(ft_map.rbegin(), ft_rit_insert_f_l);
	comp_map(map_insert_f_l, ft_map_insert_f_l, "insert( reverse_iterator, reverse_iterator )");




	/* compare maps */
	comp_map(map, ft_map, "compare map - ft_map");
	comp_map(map_insert_f_l, ft_map_insert_f_l, "compare map_insert_f_l - ft_map_insert_f_l");





	/* ***************************************************** */
	/*                       ITERATOR                        */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST iterator" END << std::endl;
	

	/* begin() */
	it_type 	it		= map.begin();
	ft_it_type 	ft_it 	= ft_map.begin();
	sstr_comp< it_type, ft_it_type >(it, ft_it, "begin()");
	// std::cout << "	it->first: " << it->first << " \n	ft_it->first: " << ft_it->first << std::endl;


	// /* begin() ++*/
	it		= map.begin(); it++;
	ft_it 	= ft_map.begin(); ft_it++;
	sstr_comp< it_type, ft_it_type >(it, ft_it, "begin()++");
	// std::cout << "	it->first: " << it->first << " \n	ft_it->first: " << ft_it->first << std::endl;



	// /* end() --*/
	it 		= map.end(); it--;
	ft_it 	= ft_map.end(); ft_it--;
	// std::cout << "\n	it->first: " << it->first << " \n	ft_it->first: " << ft_it->first << std::endl;
	sstr_comp< it_type, ft_it_type >(it, ft_it, "end()--");



	/* end --; --;*/
	it 		= map.end(); it--; it--;
	ft_it 	= ft_map.end(); ft_it--; ft_it--;
	// std::cout << "\n	it->first: " << it->first << " \n	ft_it->first: " << ft_it->first << std::endl;
	sstr_comp< it_type, ft_it_type >(it, ft_it, "end()-- x2");



	// /* end --; --;*/
	it 		= map.end(); it--; it--; it--;
	ft_it 	= ft_map.end(); ft_it--; ft_it--; ft_it--;
	// std::cout << "\n	it->first: " << it->first << " \n	ft_it->first: " << ft_it->first << std::endl;
	sstr_comp< it_type, ft_it_type >(it, ft_it, "end()--x3");

	it 		= map.end(); it--; it--; it--;  it--;
	ft_it 	= ft_map.end(); ft_it--; ft_it--; ft_it--; ft_it--;
	// std::cout << "\n	it->first: " << it->first << " \n	ft_it->first: " << ft_it->first << std::endl;
	sstr_comp< it_type, ft_it_type >(it, ft_it, "end()--x3");
	
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
	for (it = map.begin(); it != map.end(); it++){
		// std::cout << it->first << " : " << it->second << std::endl;
		sstr << it->first << ":" << it->second << " ";
	}
	// std::cout << std::endl;
	for (ft_it = ft_map.begin(); ft_it != ft_map.end(); ft_it++) {
		// std::cout << ft_it->first << " : " << ft_it->second << std::endl;
		ft_sstr << ft_it->first << ":" << ft_it->second << " ";
	}

	str_comp(sstr.str(), ft_sstr.str(), "begin() -> end()");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();





	// /* ***************************************************** */
	// /*                    CONST_ITERATOR                     */
	// /*                  pair< string, int >                  */
	// /* ***************************************************** */
	std::cout << MAG "\n\nTEST const iterator" END << std::endl;

	/* const begin() */
	const_it_type 		const const_it3 	= map.begin();
	ft_const_it_type 	const const_ft_it3 	= ft_map.begin();
	// std::cout << "const_r_it: " << const_r_it->first << ":" << const_r_it->second << std::endl;
	// std::cout << "const_ft_r_it: " << const_ft_r_it->first << ":" << const_ft_r_it->second << std::endl;
	sstr_comp< const_it_type, ft_const_it_type >(const_it3, const_ft_it3, "const begin()");


	/* const begin() */
	it_type 	it_to_constit		= map.begin();
	ft_it_type 	ft_it_to_constit 	= ft_map.begin();
	
	const_it_type 		const_it		= it_to_constit;
	ft_const_it_type 	const_ft_it 	= ft_it_to_constit;
	sstr_comp< const_it_type, ft_const_it_type >(const_it, const_ft_it, "const begin()");

	/* const bengin() ++ */
	const_it_type 	 cit_end 		= map.begin(); cit_end++;
	ft_const_it_type ft_cit_end 	= ft_map.begin(); ft_cit_end++;
	sstr_comp< const_it_type, ft_const_it_type >(cit_end, ft_cit_end, "const begin()++");

	/* const bengin() ++ x2 */
	cit_end 		= map.begin(); cit_end++; cit_end++;
	ft_cit_end 	= ft_map.begin(); ft_cit_end++; ft_cit_end++;
	sstr_comp< const_it_type, ft_const_it_type >(cit_end, ft_cit_end, "const begin()++ x2");




	/*const  end()-- */
	cit_end 			= map.end(); 	cit_end--;
	ft_cit_end 	= ft_map.end(); ft_cit_end--;
	const_it_type 		const_cit_end 		= cit_end;
	ft_const_it_type 	const_ft_cit_end 	= ft_cit_end;
	sstr_comp< const_it_type, ft_const_it_type >(const_cit_end, const_ft_cit_end, "const end()--");

	/*const end()++  only linux */
	// it_end 		= map.end(); 	it_end++;
	// ft_it_end 	= ft_map.end(); ft_it_end++;
	// const_it_type 		const_it_end_p 		= it_end;
	// ft_const_it_type 	const_ft_it_end_p 	= ft_it_end;
	// sstr_comp< const_it_type, ft_const_it_type >(const_it_end_p, const_ft_it_end_p, "const end()++");

	/* const end()-- x2 */
	cit_end				= map.end(); cit_end--; cit_end--;
	ft_cit_end		= ft_map.end(); ft_cit_end--; ft_cit_end--;
	sstr_comp< const_it_type, ft_const_it_type >(cit_end, ft_cit_end, "const end()-- x2");






	// /* ***************************************************** */
	// /*                   REVERSE_ITERATOR                    */
	// /*                  pair< string, int >                  */
	// /* ***************************************************** */
	std::cout << MAG "\n\nTEST reverse iterator" END << std::endl;
	

	/* rbegin() */
	r_it_type 		r_it 	= map.rbegin();
	ft_r_it_type 	ft_r_it = ft_map.rbegin();
	sstr_comp< r_it_type, ft_r_it_type >(r_it, ft_r_it, "rbegin()");

	/* rend()  SEGV */
	// r_it 	= map.rend();
	// ft_r_it = ft_map.rend();
	// sstr_comp< r_it_type, ft_r_it_type >(r_it, ft_r_it, "rend()");

	/* rend()-- */
	r_it 	= map.rend(); r_it--;
	ft_r_it = ft_map.rend(); ft_r_it--;
	sstr_comp< r_it_type, ft_r_it_type >(r_it, ft_r_it, "rend()--");

	/* rend()++  sur linux */
	// r_it 	= map.rend(); r_it++;
	// ft_r_it = ft_map.rend(); ft_r_it++;
	// sstr_comp< r_it_type, ft_r_it_type >(r_it, ft_r_it, "rend()++");

	/* rbegin() -> rend() */
	for (r_it = map.rbegin(); r_it != map.rend(); r_it++)
		sstr << r_it->first << ":" << r_it->second << " ";
	for (ft_r_it = ft_map.rbegin(); ft_r_it != ft_map.rend(); ft_r_it++)
		ft_sstr << ft_r_it->first << ":" << ft_r_it->second << " ";
	
	str_comp(sstr.str(), ft_sstr.str(), "rbegin() -> rend()");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();






	/* ***************************************************** */
	/*                REVERSE_CONST_ITERATOR                 */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST const reverse iterator" END << std::endl;

	/* rbegin() */
	const_r_it_type 	const_r_it 		= map.rbegin();
	ft_const_r_it_type 	const_ft_r_it 	= ft_map.rbegin();
	// std::cout << "const_r_it: " << const_r_it->first << ":" << const_r_it->second << std::endl;
	// std::cout << "const_ft_r_it: " << const_ft_r_it->first << ":" << const_ft_r_it->second << std::endl;
	sstr_comp< const_r_it_type, ft_const_r_it_type >(const_r_it, const_ft_r_it, "const rbegin()");


	/* rbegin() + 4 */
	r_it_type		r_it4 		= map.rbegin(); r_it4++; r_it4++; r_it4++; r_it4++;
	ft_r_it_type	ft_r_it4 	= ft_map.rbegin(); ft_r_it4++; ft_r_it4++; ft_r_it4++; ft_r_it4++;
	const_r_it_type 	const_r_it4 	= r_it4;
	ft_const_r_it_type 	const_ft_r_it4 	= ft_r_it4;
	sstr_comp< const_r_it_type, ft_const_r_it_type >(const_r_it4, const_ft_r_it4, "const rbegin() + 4");




	/* rend()-- */
	const_r_it_type 	const_r_it2 		= map.rend(); const_r_it2 --;
	ft_const_r_it_type 	const_ft_r_it2 		= ft_map.rend(); const_ft_r_it2 --;
	sstr_comp< const_r_it_type, ft_const_r_it_type >(const_r_it2, const_ft_r_it2, "const rend()--");

	// /* rend()++  sur linux */
	// const_r_it 		= map.rend(); const_r_it++;
	// const_ft_r_it 	= ft_map.rend(); const_ft_r_it++;
	// sstr_comp< const_r_it_type, ft_const_r_it_type >(const_r_it, const_ft_r_it, "const rend()++");

	/* rbegin() -> rend() */
	for (const_r_it = map.rbegin(); const_r_it != map.rend(); const_r_it++)
		sstr << const_r_it->first << ":" << const_r_it->second << " ";
	for (const_ft_r_it = ft_map.rbegin(); const_ft_r_it != ft_map.rend(); const_ft_r_it++)
		ft_sstr << const_ft_r_it->first << ":" << const_ft_r_it->second << " ";
	
	str_comp(sstr.str(), ft_sstr.str(), "const rbegin() -> rend()");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();

	











	/* ***************************************************** */
	/*                      find(value)                      */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST find(value)" END << std::endl;

	/* find("a") */
	it_type ret_find 		= map.find("a");
	ft_it_type ft_ret_find 	= ft_map.find("a");
	str_comp(ret_find->first, ft_ret_find->first, "find(\"a\")");
	str_comp(to_string(ret_find->second), to_string(ft_ret_find->second), "find(\"a\")");


	/* find("za") */
	ret_find 		= map.find("za");
	ft_ret_find 	= ft_map.find("za");
	str_comp(ret_find->first, ft_ret_find->first, "find(\"za\")");
	str_comp(to_string(ret_find->second), to_string(ft_ret_find->second), "find(\"za\")");


	/* find("inexist") */
	ret_find		= map.find("inexist");
	ft_ret_find		= ft_map.find("inexist");

	if (ret_find == map.end() && ft_ret_find == ft_map.end())
		std::cout << GRN "[OK] " END ;
	else 
		std::cout << RED "[KO]" END << " find(\"inexist\") you're awesome" << std::endl;

	ret_find--;
	ft_ret_find--;
	str_comp(ret_find->first, ft_ret_find->first, "find(\"inexist\")--");
	str_comp(to_string(ret_find->second), to_string(ft_ret_find->second), "find(\"inexist\")--");

	// test segv sur find(inexist)





	/* ***************************************************** */
	/*                   const find(value)                   */
	/*                  pair< string, int >                  */
	/* ***************************************************** */

	/* find("a") */
	const_it_type 	ret_const_find		= map.find("a");
	ft_const_it_type ft_ret_const_find 	= ft_map.find("a");

	str_comp(ret_const_find->first, ft_ret_const_find->first, "const find(\"a\")");
	str_comp(to_string(ret_const_find->second), to_string(ft_ret_const_find->second), "const find(\"a\")");

	/* increment it */
	ret_const_find++;
	ft_ret_const_find++;
	str_comp(ret_const_find->first, ft_ret_const_find->first, "const find(\"a\")++");
	str_comp(to_string(ret_const_find->second), to_string(ft_ret_const_find->second), "const find(\"a\")++");


	/* find("za") */
	const_it_type 	 ret_const_find2 		= map.find("za");
	ft_const_it_type ft_ret_const_find2 	= ft_map.find("za");
	str_comp(ret_const_find2->first, ft_ret_const_find2->first, "const find(\"za\")");
	str_comp(to_string(ret_const_find2->second), to_string(ft_ret_const_find2->second), "const find(\"za\")");



	// ft_map.display_tree();


	/* ***************************************************** */
	/*                       erase(pos)                      */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST erase(pos)" END << std::endl;

	// ft_map.display_tree();


	/* erase("a") */
	map.erase(map.begin());
	ft_map.erase(ft_map.begin());
	// ft_map.display_tree();
	comp_map(map, ft_map, "erase begin()");
	// ft_map.display_tree();


	/* erase("inexist") SEGV */
	// map.erase(map.find("inexist"));
	// ft_map.erase(ft_map.find("inexist"));
	// comp_map(map, ft_map, "erase find(\"inexist\")");

	/* std::map SEGV */
	// map.erase(map.end());
	// ft_map.erase(ft_map.end());
	// comp_map(map, ft_map, "erase end()");


	it = map.end(); it--;
	ft_it = ft_map.end(); ft_it--;
	map.erase(it);
	ft_map.erase(ft_it);
	comp_map(map, ft_map, "erase end()--");
	// ft_map.display_tree();


	/* erase("z") */
	map.erase(map.find("z"));
	ft_map.erase(ft_map.find("z"));
	comp_map(map, ft_map, "erase find(\"z\")");
	// ft_map.display_tree();

	/* erase("n")  SEGV si existe pas*/
	// map.erase(map.find("n"));
	// ft_map.erase(ft_map.find("n"));
	// comp_map(map, ft_map, "erase find(\"n\")");
	// // ft_map.display_tree();



	/* erase("g") */
	map.erase(map.find("d"));
	ft_map.erase(ft_map.find("d"));
	comp_map(map, ft_map, "erase find(\"d\")");
	// ft_map.display_tree();

	/*erase q*/
	// map.erase(map.find("q"));
	// ft_map.erase(ft_map.find("q"));
	// comp_map(map, ft_map, "erase find(\"q\")");

	/* erase("AA") */
	map.erase(map.find("AA"));
	ft_map.erase(ft_map.find("AA"));
	comp_map(map, ft_map, "erase find(\"AA\")");
	// ft_map.display_tree();

	// /* erase("a") */
	// map.erase(map.find("a"));
	// ft_map.erase(ft_map.find("a"));
	// comp_map(map, ft_map, "erase find(\"a\")");
	// ft_map.display_tree();

	// /* erase c */
	map.erase(map.find("c"));
	ft_map.erase(ft_map.find("c"));
	comp_map(map, ft_map, "erase find(\"c\")");

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
	map.erase(map.find("h"));
	ft_map.erase(ft_map.find("h"));
	comp_map(map, ft_map, "erase find(\"h\")");









	/* ***************************************************** */
	/*                  erase(first, last)                   */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST erase(first, last)" END << std::endl;


	/* erase begin() -> begin++*/
	it_type 		it_erase_end 		= map.begin(); it_erase_end++;
	ft_it_type 	ft_it_erase_end = ft_map.begin(); ft_it_erase_end++;
	map.erase(map.begin(), it_erase_end);
	ft_map.erase(ft_map.begin(), ft_it_erase_end);
	comp_map(map, ft_map, "erase(begin(), begin()++)");
	// ft_map.display_tree();

	/*erase end()--, end()  */
	it_erase_end = map.end(); it_erase_end--;
	ft_it_erase_end = ft_map.end(); ft_it_erase_end--;
	map.erase(it_erase_end, map.end());
	ft_map.erase(ft_it_erase_end, ft_map.end());
	comp_map(map, ft_map, "erase(end()--, end())");


	/* erase begin(), begin() */
	map.erase(map.begin(), map.begin());
	ft_map.erase(ft_map.begin(), ft_map.begin());
	comp_map(map, ft_map, "erase(begin(), begin())");

	/* erase end(), end() */
	map.erase(map.end(), map.end());
	ft_map.erase(ft_map.end(), ft_map.end());
	comp_map(map, ft_map, "erase(end(), end())");


	/* erase begin() + 2, begin() + 5 */
	it_type 		it_erase_begin 		= map.begin();
	ft_it_type 	ft_it_erase_begin = ft_map.begin();
	for(int i = 0; i < 2; i++) { it_erase_begin++; ft_it_erase_begin++;	}
	it_erase_end = map.begin();
	ft_it_erase_end = ft_map.begin();
	for ( int i = 0; i < 5; i++ ) { it_erase_end++; ft_it_erase_end++; }
	map.erase(it_erase_begin, it_erase_end);
	ft_map.erase(ft_it_erase_begin, ft_it_erase_end);
	comp_map(map, ft_map, "erase(begin() + 2, begin() + 5)");



	/* erase begin() + 5 -> end() - 5 */
	it_erase_begin 		= map.begin();
	ft_it_erase_begin = ft_map.begin();
	for(int i = 0; i < 5; i++) { it_erase_begin++; ft_it_erase_begin++;	}

	it_erase_end 			= map.end();
	ft_it_erase_end 	= ft_map.end();
	for(int i = 0; i < 5; i++) { it_erase_end--; ft_it_erase_end--;	}

	map.erase(it_erase_begin, it_erase_end);
	ft_map.erase(ft_it_erase_begin, ft_it_erase_end);
	comp_map(map, ft_map, "erase(begin() + 5, end() - 5)");
	ft_map.display_tree();


	/* erase begin() -> end() */
	// it = map.end();
	// ft_it = ft_map.end();
	// map.erase(map.begin(), it);
	// ft_map.erase(ft_map.begin(), ft_it);
	// // map.erase(map.begin(), map.end());
	// // ft_map.erase(ft_map.begin(), ft_map.end());
	// comp_map(map, ft_map, "erase(begin(), end())");
	// ft_map.display_tree();







	// ft_map.display_tree();


	

	/* ***************************************************** */
	/*                      erase(key)                       */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST erase(key)" END << std::endl;


	/* erase("a") */

	size_t ret = map.erase("w");
	size_t ft_ret = ft_map.erase("w");
	str_comp(to_string(ret), to_string(ft_ret), "ret rase(\"w\")");
	comp_map(map, ft_map, "erase(\"w\")");
	// ft_map.display_tree();

	/* erase("b") */
	ret = map.erase("b");
	ft_ret = ft_map.erase("b");
	str_comp(to_string(ret), to_string(ft_ret), "ret rase(\"b\")");
	comp_map(map, ft_map, "erase(\"b\")");
	// ft_map.display_tree();

	/* erase("e") */
	ret =   map.erase("e");
	ft_ret =ft_map.erase("e");
	str_comp(to_string(ret), to_string(ft_ret), "ret rase(\"e\")");
	comp_map(map, ft_map, "erase(\"e\")");
	// ft_map.display_tree();

	/* erase("f") */
	ret =    map.erase("f");
	ft_ret = ft_map.erase("f");
	str_comp(to_string(ret), to_string(ft_ret), "ret rase(\"f\")");
	comp_map(map, ft_map, "erase(\"f inexisant\")");






	// ft_map.display_tree();






	/* ***************************************************** */
	/*                      swap()                           */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST swap()" END << std::endl;


	std_map_str_int map_swap(map);
	ft_map_str_int ft_map_swap(ft_map);

	map_swap.insert(pair("@", 777));
	ft_map_swap.insert(ft_pair("@", 777));

	/* swap() */
	// ft_map.display_tree("ft_map avant");
	// ft_map_swap.display_tree("ft_map_swap avant");
	map.swap(map_swap);
	ft_map.swap(ft_map_swap);
	// ft_map.display_tree("ft_map apres");
	// ft_map_swap.display_tree("ft_map_swap apres");
	comp_map(map, ft_map, "map swap()");
	comp_map(map_swap, ft_map_swap, "swap original");


	/* swap with empty */
	std_map_str_int map_swap2;
	ft_map_str_int ft_map_swap2;

	/* leak if not empty */
	// map_swap2.insert(pair("a", 777));
	// ft_map_swap2.insert(ft_pair("a", 777));


	// ft_map_swap.display_tree("ft_map_swap avant");
	// ft_map_swap2.display_tree("ft_map_swap2 avant");
	map_swap.swap(map_swap2);
	ft_map_swap.swap(ft_map_swap2);
	// ft_map_swap.display_tree("ft_map_swap apres");
	// ft_map_swap2.display_tree("ft_map_swap2 apres");
	comp_map(map_swap, ft_map_swap, "map swap2");
	comp_map(map_swap2, ft_map_swap2, "map_swap2 original");









	ft_map.display_tree();


	/* ***************************************************** */
	/*                constructor(first, last)               */
	/*                  pair< string, int >                  */
	/* ***************************************************** */

	std::cout << MAG "\n\nTEST constructor(first, last)" END << std::endl;

	/* constructor(first, last) */
	std_map_str_int map_construct(map.begin(), map.end());
	ft_map_str_int ft_map_construct(ft_map.begin(), ft_map.end());
	comp_map(map_construct, ft_map_construct, "constructor(first, last)");
	

	/*construct(begin, begin + 2) */
	it_end = map.begin();
	ft_it_end = ft_map.begin();
	for(int i = 0; i < 2; i++) { it_end++; ft_it_end++; }
	
	std_map_str_int map_construct2(map.begin(), it_end);
	ft_map_str_int ft_map_construct2(ft_map.begin(), ft_it_end);
	comp_map(map_construct2, ft_map_construct2, "constructor(begin, begin + 2)");


	/*construct(begin + 2, end - 2) */
	it_type it_begin = map.begin();
	ft_it_type ft_it_begin = ft_map.begin();
	for(int i = 0; i < 2; i++) { it_begin++; ft_it_begin++; }
	it_end = map.end();
	ft_it_end = ft_map.end();
	for(int i = 0; i < 2; i++) { it_end--; ft_it_end--; }

	std_map_str_int map_construct3(it_begin, it_end);
	ft_map_str_int ft_map_construct3(ft_it_begin, ft_it_end);
	comp_map(map_construct3, ft_map_construct3, "constructor(begin + 2, end - 2)");







	/* constructor const */
	const_it_type 	 cit_begin2 = map.begin();
	ft_const_it_type ft_cit_begin2 = ft_map.begin();
	const_it_type 	 cit_end2 = map.end();
	ft_const_it_type ft_cit_end2 = ft_map.end();

	std_map_str_int map_construct10(cit_begin2, cit_end2);
	ft_map_str_int ft_map_construct10(ft_cit_begin2, ft_cit_end2);
	comp_map(map_construct10, ft_map_construct10, "constructor const");






	/* construct(reverse begin, revse end) */
	std_map_str_int map_construct4(map.rbegin(), map.rend());
	ft_map_str_int ft_map_construct4(ft_map.rbegin(), ft_map.rend());
	comp_map(map_construct4, ft_map_construct4, "constructor(reverse begin, revse end)");


	/* construct(reverse begin + 2, revse end - 2) */
	r_it = map.rbegin();
	ft_r_it = ft_map.rbegin();
	for(int i = 0; i < 2; i++) { r_it++; ft_r_it++; }
	r_it_type 	 r_it_end = map.rend();
	ft_r_it_type ft_r_it_end = ft_map.rend();
	for(int i = 0; i < 2; i++) { r_it_end--; ft_r_it_end--; }

	std_map_str_int map_construct5(r_it, r_it_end);
	ft_map_str_int ft_map_construct5(ft_r_it, ft_r_it_end);
	comp_map(map_construct5, ft_map_construct5, "constructor(reverse begin + 2, revse end - 2)");






	/* ***************************************************** */
	/*                   copy constructor                    */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	
	/* test constructor copy */
	std::cout << MAG "\n\nTEST copy constructor" END << std::endl;
	
	/* cpy map */
	std_map_str_int map_cp(map);
	ft_map_str_int ft_map_cp(ft_map);
	comp_map(map_cp, ft_map_cp, "copy constructor");
	comp_map(map, ft_map, "original maps");

	/* cpy map_cp */
	std_map_str_int map_cp_cp(map_cp);
	ft_map_str_int ft_map_cp_cp(ft_map_cp);
	comp_map(map_cp_cp, ft_map_cp_cp, "copy constructor");
	comp_map(map_cp, ft_map_cp, "original maps");








	/* ***************************************************** */
	/*                    tests capacity                     */
	/*                  pair< string, int >                  */
	/* ***************************************************** */

	std::cout << MAG "\n\nTEST empty" END << std::endl;

	std_map_str_int empty_map;
	ft_map_str_int 	ft_empty_map;

	
	str_comp( to_string(map.empty()), to_string(ft_map.empty()), "empty()");
	str_comp( to_string(map_cp.empty()), to_string(ft_map_cp.empty()), "empty()");
	str_comp( to_string(map_construct2.empty()), to_string(ft_map_construct2.empty()), "empty()");
	str_comp( to_string(empty_map.empty()), to_string(ft_empty_map.empty()), "empty()");
	map_cp.clear();
	ft_map_cp.clear();
	str_comp( to_string(map_cp.empty()), to_string(ft_map_cp.empty()), "empty() after clear()");
	





	/* ***************************************************** */
	/*                      tests size                       */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	
	std::cout << MAG "\n\nTEST size - max_size" END << std::endl;

	str_comp( to_string(map.size()), to_string(ft_map.size()), "empty()");
	str_comp( to_string(map_cp.size()), to_string(ft_map_cp.size()), "empty()");

	str_comp( to_string(map_construct3.size()), to_string(ft_map_construct3.size()), "empty()");
	str_comp( to_string(empty_map.size()), to_string(ft_empty_map.size()), "empty()");
	map_construct3.clear();
	ft_map_construct3.clear();
	str_comp( to_string(map_construct3.size()), to_string(ft_map_construct3.size()), "empty() after clear()");



	str_comp(to_string(map.max_size()), to_string(ft_map.max_size()), "max_size()");
	str_comp(to_string(map_cp.max_size()), to_string(ft_map_cp.max_size()), "max_size()");
	str_comp(to_string(map_construct3.max_size()), to_string(ft_map_construct3.max_size()), "max_size()");






	/* ***************************************************** */
	/*                     test at && []                     */
	/*                  pair< string, int >                  */
	/* ***************************************************** */

	std::cout << MAG "\n\nTEST at && []" END << std::endl;

	/* at l */
	type_value_map1 ret_at = map.at("l");
	type_value_map1 ft_ret_at = ft_map.at("l");
	str_comp( to_string(ret_at), to_string(ft_ret_at), "at(\"l\")");
	str_comp( to_string(map.at("l")), to_string(ft_map.at("l")), "at(\"l\")");

	// /* at a */																																		tester excetion
	// ret_at = map.at("a");
	// ft_ret_at = ft_map.at("a");
	// str_comp( to_string(ret_at), to_string(ft_ret_at), "at(\"a\")");
	// str_comp( to_string(map.at("a")), to_string(ft_map.at("a")), "at(\"a\")");


	// /* at j */
	ret_at = map.at("j");
	ft_ret_at = ft_map.at("j");
	str_comp( to_string(ret_at), to_string(ft_ret_at), "at(\"j\")");
	str_comp( to_string(map.at("j")), to_string(ft_map.at("j")), "at(\"j\")");

	/* at @ */
	ret_at = map.at("@");
	ft_ret_at = ft_map.at("@");
	str_comp( to_string(ret_at), to_string(ft_ret_at), "at(\"@\")");
	str_comp( to_string(map.at("@")), to_string(ft_map.at("@")), "at(\"@\")");

	/* at y */
	ret_at = map.at("y");
	ft_ret_at = ft_map.at("y");
	str_comp( to_string(ret_at), to_string(ft_ret_at), "at(\"y\")");
	str_comp( to_string(map.at("y")), to_string(ft_map.at("y")), "at(\"y\")");










	/* [] l */
	ret_at = map["l"];
	ft_ret_at = ft_map["l"];
	str_comp( to_string(ret_at), to_string(ft_ret_at), "[](\"l\")");
	str_comp( to_string(map["l"]), to_string(ft_map["l"]), "[](\"l\")");

	/* [] @ */
	ret_at = map["@"];
	ft_ret_at = ft_map["@"];
	str_comp( to_string(ret_at), to_string(ft_ret_at), "[](\"@\")");
	str_comp( to_string(map["@"]), to_string(ft_map["@"]), "[](\"@\")");

	/* [] y */
	ret_at = map["y"];
	ft_ret_at = ft_map["y"];
	str_comp( to_string(ret_at), to_string(ft_ret_at), "[](\"y\")");
	str_comp( to_string(map["y"]), to_string(ft_map["y"]), "[](\"y\")");

	




	ft_map.display_tree();





	/* ***************************************************** */
	/*                        LOOKUP                         */
	/*                  pair< string, int >                  */
	/* ***************************************************** */


	std::cout << MAG "\n\nTEST count" END << std::endl;

	str_comp( to_string(map.count("@")), to_string(ft_map.count("@")), "count()" );
	str_comp( to_string(map.count("a")), to_string(ft_map.count("a")), "count()" );
	str_comp( to_string(map.count("l")), to_string(ft_map.count("l")), "count()" );
	str_comp( to_string(map.count("y")), to_string(ft_map.count("y")), "count()" );
	str_comp( to_string(map.count("z")), to_string(ft_map.count("z")), "count()" );
	


	comp_map(map, ft_map, "comp map, ft_map");


	/* ***************************************************** */
	/*                        LOOKUP                         */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	
	std::cout << MAG "\n\nTEST equal_range()" END << std::endl;

	/* l */
	std::pair<it_type, it_type> ret_equal_range = map.equal_range("l");
	ft::pair<ft_it_type, ft_it_type> ft_ret_equal_range = ft_map.equal_range("l");
	str_comp( to_string(ret_equal_range.first->first), to_string(ft_ret_equal_range.first->first), "equal_range(\"l\")");
	str_comp( to_string(ret_equal_range.first->second), to_string(ft_ret_equal_range.first->second), "equal_range(\"l\")");

	/* @ */
	ret_equal_range = map.equal_range("@");
	ft_ret_equal_range = ft_map.equal_range("@");
	str_comp( to_string(ret_equal_range.first->first), to_string(ft_ret_equal_range.first->first), "equal_range(\"@\")");
	str_comp( to_string(ret_equal_range.first->second), to_string(ft_ret_equal_range.first->second), "equal_range(\"@\")");

	/* y */
	ret_equal_range = map.equal_range("y");
	ft_ret_equal_range = ft_map.equal_range("y");
	str_comp( to_string(ret_equal_range.first->first), to_string(ft_ret_equal_range.first->first), "equal_range(\"y\")");
	str_comp( to_string(ret_equal_range.first->second), to_string(ft_ret_equal_range.first->second), "equal_range(\"y\")");

	/* z */
	// ret_equal_range = map.equal_range("z");
	// ft_ret_equal_range = ft_map.equal_range("z");
	// str_comp( to_string(ret_equal_range.first->first), to_string(ft_ret_equal_range.first->first), "equal_range(\"z\")");
	// str_comp( to_string(ret_equal_range.first->second), to_string(ft_ret_equal_range.first->second), "equal_range(\"z\")");





	





	/* ***************************************************** */
	/*                       clear()                         */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST clear" END << std::endl;

	map.clear();
	ft_map.clear();
	comp_map(map, ft_map, "clear()");
	// ft_map.display_tree();

























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
	// std::cout << "fin" << std::endl;
	std::cout << std::endl;
	return 0;
}


/*

	REGLEMENT FABLAB

	L'acces au FabLab se fait par l'adhesion au club DIY

	Les horaires d'ouvertures sont du lundi au vendredi 
	de 8h a 17h sans responsable
	de 17h a 22-23h avec responsable car pas de gerant
	horaire weekend ?

	Le soir l'acces n'est autorise que si un responsable est present
	Certaine machine ne sont utilisable qu'apres une formation (decoupe laser, CNC)

	Les responsables auront une formation sur ces machines pour superviser les membres du club.

	Des creneaux peuvent etre pris sur le site de la bidouille pour reserver des machines, 
	mais n'est pas obligatoire.

	Les membres ont obligation de s'inscrire sur le site de la bidouille (pour accepter les termes et conditions)

	La capacite du FabLab est de 7-8 personnes dont les gerants. 
	Il est donc conseiller de faire des groupes de 2-4 personnes dans la journee.

	L'utilisation de la decoupe laser et CNC est facturer a l'heure, (montant ?) 
	Les consommables tel que le filament 3D est a la charge des membres (cagnotte)



*/