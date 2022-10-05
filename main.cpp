/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:19:53 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/06 01:29:39 by jrasser          ###   ########.fr       */
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
}

template < class T_map, class T_pair>
void fill_map(T_map *map) {
	map->insert(T_pair("g", 1));
	map->insert(T_pair("h", 1));
	map->insert(T_pair("i", 1));
	map->insert(T_pair("j", 1));
	map->insert(T_pair("k", 1));
	map->insert(T_pair("l", 1));
	map->insert(T_pair("m", 1));
	map->insert(T_pair("n", 1));
	map->insert(T_pair("o", 1));
	map->insert(T_pair("p", 1));
	map->insert(T_pair("q", 1));
	map->insert(T_pair("r", 1));
	map->insert(T_pair("s", 1));
	map->insert(T_pair("t", 1));
	map->insert(T_pair("u", 1));
	map->insert(T_pair("v", 1));
	map->insert(T_pair("w", 1));
	map->insert(T_pair("x", 1));
	map->insert(T_pair("y", 1));
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
	/*                          MAPS                         */
	/*                                                       */
	/* ***************************************************** */

/*
	std::cout << BLU "\nTEST insert(first, last) : " END << std::endl;
	map.insert(map.begin(), map.end());
	ft_map.insert(ft_map.begin(), ft_map.end());

	std::cout << BLU "\nTEST insert(hint, value) : " END << std::endl;
	map.insert(map.begin(), std::pair<std::string, int>("f", 6));
	ft_map.insert(ft_map.begin(), ft::pair<std::string, int>("f", 6));

	std::cout << BLU "\nTEST erase(pos) : " END << std::endl;
	map.erase(map.begin());
	ft_map.erase(ft_map.begin());

	std::cout << BLU "\nTEST erase(key) : " END << std::endl;
	map.erase("a");
	ft_map.erase("a");

	std::cout << BLU "\nTEST erase(first, last) : " END << std::endl;
	map.erase(map.begin(), map.end());
	ft_map.erase(ft_map.begin(), ft_map.end());

	std::cout << BLU "\nTEST swap() : " END << std::endl;
	map.swap(map);
	ft_map.swap(ft_map);

	std::cout << BLU "\nTEST clear() : " END << std::endl;
	map.clear();
	ft_map.clear();

	std::cout << BLU "\nTEST find() : " END << std::endl;
	map.find("a");
	ft_map.find("a");

	std::cout << BLU "\nTEST count() : " END << std::endl;
	map.count("a");
	ft_map.count("a");

	std::cout << BLU "\nTEST lower_bound() : " END << std::endl;
	map.lower_bound("a");
	ft_map.lower_bound("a");

	std::cout << BLU "\nTEST upper_bound() : " END << std::endl;
	map.upper_bound("a");
	ft_map.upper_bound("a");

	std::cout << BLU "\nTEST equal_range() : " END << std::endl;
	map.equal_range("a");
	ft_map.equal_range("a");

	std::cout << BLU "\nTEST key_comp() : " END << std::endl;
	map.key_comp();
	ft_map.key_comp();

	std::cout << BLU "\nTEST value_comp() : " END << std::endl;
	map.value_comp();
	ft_map.value_comp();

	std::cout << BLU "\nTEST operator[] : " END << std::endl;
	std::cout << map["a"] << std::endl;
	std::cout << ft_map["a"] << std::endl;
*/

	typedef std::map<std::string, int>::iterator 					it_type;
	typedef std::map<std::string, int>::const_iterator 				const_it_type;
	typedef std::map<std::string, int>::reverse_iterator 			r_it_type;
	typedef std::map<std::string, int>::const_reverse_iterator 		const_r_it_type;

	typedef  ft::map<std::string, int>::iterator 					ft_it_type;
	typedef  ft::map<std::string, int>::const_iterator 				const_ft_it_type;
	typedef  ft::map<std::string, int>::reverse_iterator 			ft_r_it_type;
	typedef  ft::map<std::string, int>::const_reverse_iterator 		const_ft_r_it_type;

	typedef std::pair<std::string, int> 			pair;
	typedef  ft::pair<std::string, int> 			ft_pair;



	typedef std::map<int, int>::iterator 							it_type2;
	typedef std::map<int, int>::const_iterator 						const_it_type2;
	typedef std::map<int, int>::reverse_iterator 					r_it_type2;
	typedef std::map<int, int>::const_reverse_iterator 				const_r_it_type2;

	typedef  ft::map<int, int>::iterator 							ft_it_type2;
	typedef  ft::map<int, int>::const_iterator 						const_ft_it_type2;
	typedef  ft::map<int, int>::reverse_iterator 					ft_r_it_type2;
	typedef  ft::map<int, int>::const_reverse_iterator 				const_ft_r_it_type2;

	typedef std::pair<int, int> 			pair2;
	typedef  ft::pair<int, int> 			ft_pair2;



	/* ***************************************************** */
	/*                                                       */
	/*                          MAP                          */
	/*                   pair< STRING, INT>                  */
	/*                                                       */
	/* ***************************************************** */

	std::cout << BLU "Create map<string, int> " END << std::endl;

	/* Creation de map, ca devrait pas merde ca */
	std::map<std::string, int> map;
	 ft::map<std::string, int> ft_map;



	/* ***************************************************** */
	/*                     INSERT(value)                     */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	// ft_map.display_tree();
	std::cout << MAG "\n\nTEST insert( value )" END << std::endl;

	/* insert ("b", 2) */
	std::pair< it_type, bool > ret_insert_value = map.insert(pair("b", 2));
	ft::pair< ft_it_type, bool > ft_ret_insert_value = ft_map.insert(ft_pair("b", 2));

	str_comp(ret_insert_value.first->first, ft_ret_insert_value.first->first, "insert(value(ft_pair(\"b\", 2)))");
	str_comp(to_string(ret_insert_value.first->second), to_string(ft_ret_insert_value.first->second), "insert(value(ft_pair(\"b\", 2)))");

	/* insert ("a", 1) */
	ret_insert_value 	= map.insert(pair("a", 1));
	ft_ret_insert_value = ft_map.insert(ft_pair("a", 1));

	str_comp(ret_insert_value.first->first, ft_ret_insert_value.first->first, "insert(value(ft_pair(\"a\", 1))) -> first");
	str_comp(to_string(ret_insert_value.first->second), to_string(ft_ret_insert_value.first->second), "insert(value(ft_pair(\"a\", 1))) -> second");

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

	/* insert ("d", 4) */
	ret_insert_value 	= map.insert(pair("d", 4));
	ft_ret_insert_value = ft_map.insert(ft_pair("d", 4));

	str_comp(ret_insert_value.first->first, ft_ret_insert_value.first->first, "test doublon insert(value(ft_pair(\"d\", 4))) -> first");
	str_comp(to_string(ret_insert_value.first->second), to_string(ft_ret_insert_value.first->second), "test doublon insert(value(ft_pair(\"d\", 4))) -> second");


	/* insert many value */
	fill_map< std::map<std::string, int>, pair >(&map);
	fill_map< ft::map<std::string, int>, ft_pair >(&ft_map);
	for (it_type it = map.begin(); it != map.end(); it++)
		sstr << it->first << ":" << it->second << " ";
	for (ft_it_type it = ft_map.begin(); it != ft_map.end(); it++)
		ft_sstr << it->first << ":" << it->second << " ";
	
	str_comp(sstr.str(), ft_sstr.str(), "insert many values");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();









	/* ***************************************************** */
	/*                  INSERT(hint, value)                  */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST insert( hint, value )" END << std::endl;



	/* insert(begin(), 1) */
	it_type it_insert_hint = map.insert(map.begin()++, pair("A", 1));
	ft_it_type ft_it_insert_hint = ft_map.insert(ft_map.begin()++, ft_pair("A", 1));

	str_comp(it_insert_hint->first, ft_it_insert_hint->first, "insert(begin(), value(ft_pair(\"A\", 1))) -> first");
	str_comp(to_string(it_insert_hint->second), to_string(ft_it_insert_hint->second), "insert(begin(), value(ft_pair(\"A\", 1))) -> second");


	/* insert(begin(), 1) */
	it_insert_hint = map.insert(map.begin(), pair("AA", 1));
	ft_it_insert_hint = ft_map.insert(ft_map.begin(), ft_pair("AA", 1));

	str_comp(it_insert_hint->first, ft_it_insert_hint->first, "insert(begin(), value(ft_pair(\"z\", 1))) -> first");
	str_comp(to_string(it_insert_hint->second), to_string(ft_it_insert_hint->second), "insert(begin(), value(ft_pair(\"z\", 1))) -> second");

	/* insert(begin(), "z") */
	it_insert_hint = map.insert(map.begin(), pair("yz", 1));
	ft_it_insert_hint = ft_map.insert(ft_map.begin(), ft_pair("yz", 1));

	str_comp(it_insert_hint->first, ft_it_insert_hint->first, "insert(begin(), value(ft_pair(\"z\", 1))) -> first");
	str_comp(to_string(it_insert_hint->second), to_string(ft_it_insert_hint->second), "insert(begin(), value(ft_pair(\"z\", 1))) -> second");




	/* insert(end(), 1) */
	it_insert_hint = map.insert(map.end(), pair("z", 1));
	ft_it_insert_hint = ft_map.insert(ft_map.end(), ft_pair("z", 1));

	str_comp(it_insert_hint->first, ft_it_insert_hint->first, "insert(end(), value(ft_pair(\"z\", 1))) -> first");
	str_comp(to_string(it_insert_hint->second), to_string(ft_it_insert_hint->second), "insert(end(), value(ft_pair(\"z\", 1))) -> second");

	
	/* insert(end(), "a") */
	it_insert_hint = map.insert(map.end(), pair("za", 1));
	ft_it_insert_hint = ft_map.insert(ft_map.end(), ft_pair("za", 1));

	str_comp(it_insert_hint->first, ft_it_insert_hint->first, "insert(end(), value(ft_pair(\"za\", 1))) -> first");
	str_comp(to_string(it_insert_hint->second), to_string(ft_it_insert_hint->second), "insert(end(), value(ft_pair(\"za\", 1))) -> second");

	/* insert(end(), "z") */
	it_insert_hint = map.insert(map.end(), pair("c", 1));
	ft_it_insert_hint = ft_map.insert(ft_map.end(), ft_pair("c", 1));

	str_comp(it_insert_hint->first, ft_it_insert_hint->first, "insert(end(), value(ft_pair(\"c\", 1))) -> first");
	str_comp(to_string(it_insert_hint->second), to_string(ft_it_insert_hint->second), "insert(end(), value(ft_pair(\"c\", 1))) -> second");



	/* insert begin()+5, "e" */
	std::string val_to_insert = "e";
	int 		pos_to_insert = 5;

	it_type it_test = map.begin();
	for(int i = 0; i < pos_to_insert; i++)
		it_test++;
	ft_it_type ft_it_test = ft_map.begin();
	for(int i = 0; i < pos_to_insert; i++)
		ft_it_test++;

	it_type it_test2 = map.insert(it_test, pair(val_to_insert, 26));
	sstr << "ret_insert(hint, value) " << it_test2->first << std::endl;

	ft_it_type ft_it_test2 = ft_map.insert(ft_it_test, ft_pair(val_to_insert, 26));
	ft_sstr << "ret_insert(hint, value) " << ft_it_test2->first << std::endl;

	str_comp(sstr.str(), ft_sstr.str(), "begin() -> end()");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();



	/* insert many value */
	for (it_type it = map.begin(); it != map.end(); it++)
		sstr << it->first << ":" << it->second << " ";
	for (ft_it_type it = ft_map.begin(); it != ft_map.end(); it++)
		ft_sstr << it->first << ":" << it->second << " ";
	
	str_comp(sstr.str(), ft_sstr.str(), "insert many values");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();


	// ft_map.display_tree();


	/* ***************************************************** */
	/*                  INSERT(first, last)                  */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST insert( first, last )" END << std::endl;












	/* ***************************************************** */
	/*                                                       */
	/*                         MAP                           */
	/*                   pair< INT, INT >                    */
	/*                                                       */
	/* ***************************************************** */
	std::cout << BLU "Create map<int, int> " END << std::endl;

	std::map<int, int> map2;
	 ft::map<int, int> ft_map2;

	// std::cout << BLU "\nTEST insert(value) : " END << std::endl;
	map2.insert(pair2(1, 1));
	map2.insert(pair2(2, 2));
	map2.insert(pair2(3, 3));
	map2.insert(pair2(4, 4));
	map2.insert(pair2(5, 5));

	ft_map2.insert(ft_pair2(1, 1));
	ft_map2.insert(ft_pair2(2, 2));
	ft_map2.insert(ft_pair2(3, 3));
	ft_map2.insert(ft_pair2(4, 4));
	ft_map2.insert(ft_pair2(5, 5));
	



std::cout << MAG "\n\nTEST iterator" END << std::endl;
	/* ***************************************************** */
	/*                       ITERATOR                        */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	

	/* begin() */
	it_type 	it		= map.begin();
	ft_it_type 	ft_it 	= ft_map.begin();
	sstr_comp< it_type, ft_it_type >(it, ft_it, "begin()");

	/* end() */
	it 		= map.end(); it--;
	ft_it 	= ft_map.end(); ft_it--;
	sstr_comp< it_type, ft_it_type >(it, ft_it, "end()--");

	// it 		= map.end(); it++;
	// ft_it 	= ft_map.end(); ft_it++;
	// sstr_comp< it_type, ft_it_type >(it, ft_it, "end()++");

																						// gerer test segfault
	// it = map.end(); it++; it++;
	// ft_it = ft_map.end(); ft_it++; ft_it++;
	// sstr_comp< it_type, ft_it_type >(it, ft_it, "end()++");

	/* begin() -> end() */
	for (it = map.begin(); it != map.end(); it++)
		sstr << it->first << ":" << it->second << " ";
	for (ft_it = ft_map.begin(); ft_it != ft_map.end(); ft_it++)
		ft_sstr << ft_it->first << ":" << ft_it->second << " ";

	str_comp(sstr.str(), ft_sstr.str(), "begin() -> end()");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();


	/* ***************************************************** */
	/*                   REVERSE_ITERATOR                    */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	

	/* rbegin() */
	r_it_type 		r_it 	= map.rbegin();
	ft_r_it_type 	ft_r_it = ft_map.rbegin();
	sstr_comp< r_it_type, ft_r_it_type >(r_it, ft_r_it, "rbegin()");

	/* rend()-- */
	r_it 	= map.rend(); r_it--;
	ft_r_it = ft_map.rend(); ft_r_it--;
	sstr_comp< r_it_type, ft_r_it_type >(r_it, ft_r_it, "rend()--");

	/* rend()++ */
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
	/*                    CONST_ITERATOR                     */
	/*                  pair< string, int >                  */
	/* ***************************************************** */

	

	/* begin() */
	const_it_type 		const_it 	= map.begin();
	const_ft_it_type 	const_ft_it = ft_map.begin();
	sstr_comp< const_it_type, const_ft_it_type >(const_it, const_ft_it, "const begin()");

	/* end() */
	const_it 	= map.end(); const_it--;
	const_ft_it = ft_map.end(); const_ft_it--;
	sstr_comp< const_it_type, const_ft_it_type >(const_it, const_ft_it, "const end()--");

	// const_it 	= map.end(); const_it++;
	// const_ft_it = ft_map.end(); const_ft_it++;
	// sstr_comp< const_it_type, const_ft_it_type >(const_it, const_ft_it, "const end()++");

	/* begin() -> end() */
	for (const_it = map.begin(); const_it != map.end(); const_it++)
		sstr << const_it->first << ":" << const_it->second << " ";
	for (const_ft_it = ft_map.begin(); const_ft_it != ft_map.end(); const_ft_it++)
		ft_sstr << const_ft_it->first << ":" << const_ft_it->second << " ";
	
	str_comp(sstr.str(), ft_sstr.str(), "const begin() -> end()");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();



	/* ***************************************************** */
	/*                REVERSE_CONST_ITERATOR                 */
	/*                  pair< string, int >                  */
	/* ***************************************************** */
	

	/* rbegin() */
	const_r_it_type 	const_r_it 		= map.rbegin();
	const_ft_r_it_type 	const_ft_r_it 	= ft_map.rbegin();
	sstr_comp< const_r_it_type, const_ft_r_it_type >(const_r_it, const_ft_r_it, "const rbegin()");

	/* rend()-- */
	const_r_it 		= map.rend(); const_r_it--;
	const_ft_r_it 	= ft_map.rend(); const_ft_r_it--;
	sstr_comp< const_r_it_type, const_ft_r_it_type >(const_r_it, const_ft_r_it, "const rend()--");

	// /* rend()++ */
	// const_r_it 		= map.rend(); const_r_it++;
	// const_ft_r_it 	= ft_map.rend(); const_ft_r_it++;
	// sstr_comp< const_r_it_type, const_ft_r_it_type >(const_r_it, const_ft_r_it, "const rend()++");

	/* rbegin() -> rend() */
	for (const_r_it = map.rbegin(); const_r_it != map.rend(); const_r_it++)
		sstr << const_r_it->first << ":" << const_r_it->second << " ";
	for (const_ft_r_it = ft_map.rbegin(); const_ft_r_it != ft_map.rend(); const_ft_r_it++)
		ft_sstr << const_ft_r_it->first << ":" << const_ft_r_it->second << " ";
	
	str_comp(sstr.str(), ft_sstr.str(), "const rbegin() -> rend()");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();

	






















/* ***************************************************** */
/*                                                       */
/*                     pair<INT, INT>                    */
/*                                                       */
/* ***************************************************** */
std::cout << MAG "\n\nTEST iterator" END << std::endl;


	/* ***************************************************** */
	/*                       ITERATOR                        */
	/*                    pair< int, int >                   */
	/* ***************************************************** */
	

	/* begin() */
	it_type2 it2 		= map2.begin();
	ft_it_type2 ft_it2 	= ft_map2.begin();
	sstr_comp< it_type2, ft_it_type2 >(it2, ft_it2, "begin()");

	/* end()-- */
	it2 = map2.end(); it2--;
	ft_it2 = ft_map2.end(); ft_it2--;
	sstr_comp< it_type2, ft_it_type2 >(it2, ft_it2, "end()--");

	/* end()++ */
	// it2 = map2.end(); it2++;
	// ft_it2 = ft_map2.end(); ft_it2++;
	// sstr_comp< it_type2, ft_it_type2 >(it2, ft_it2, "end()++");

																						// gerer test segfault
	// it2 = map2.end(); it2++; it2++;
	// ft_it2 = ft_map2.end(); ft_it2++; ft_it2++;
	// sstr_comp< it_type2, ft_it_type2 >(it2, ft_it2, "end()++");

	/* begin() -> end() */
	for (it2 = map2.begin(); it2 != map2.end(); it2++)
		sstr << it2->first << ":" << it2->second << " ";
	for (ft_it2 = ft_map2.begin(); ft_it2 != ft_map2.end(); ft_it2++)
		ft_sstr << ft_it2->first << ":" << ft_it2->second << " ";
	
	str_comp(sstr.str(), ft_sstr.str(), "begin() -> end()");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();






	/* ***************************************************** */
	/*                    REVERSE_ ITERATOR                  */
	/*                    pair< int, int >                   */
	/* ***************************************************** */
	

	/* rbegin() */
	r_it_type2 		r_it2 		= map2.rbegin();
	ft_r_it_type2 	ft_r_it2 	= ft_map2.rbegin();
	sstr_comp< r_it_type2, ft_r_it_type2 >(r_it2, ft_r_it2, "rbegin()");

	/* rend()-- */
	r_it2 		= map2.rend(); r_it2--;
	ft_r_it2 	= ft_map2.rend(); ft_r_it2--;
	sstr_comp< r_it_type2, ft_r_it_type2 >(r_it2, ft_r_it2, "rend()--");

	/* rend()++ */
	// r_it2 		= map2.rend(); r_it2++;
	// ft_r_it2 	= ft_map2.rend(); ft_r_it2++;
	// sstr_comp< r_it_type2, ft_r_it_type2 >(r_it2, ft_r_it2, "rend()++");

	/* rbegin() -> rend() */
	for (r_it2 = map2.rbegin(); r_it2 != map2.rend(); r_it2++)
		sstr << r_it2->first << ":" << r_it2->second << " ";
	for (ft_r_it2 = ft_map2.rbegin(); ft_r_it2 != ft_map2.rend(); ft_r_it2++)
		ft_sstr << ft_r_it2->first << ":" << ft_r_it2->second << " ";

	str_comp(sstr.str(), ft_sstr.str(), "rbegin() -> rend()");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();












	/* ***************************************************** */
	/*                    CONST_ITERATOR                     */
	/*                    pair<int, int>                     */
	/* ***************************************************** */
	

	/* begin() */
	const_it_type2 		const_it2 		= map2.begin();
	const_ft_it_type2 	const_ft_it2 	= ft_map2.begin();
	sstr_comp< const_it_type2, const_ft_it_type2 >(const_it2, const_ft_it2, "const begin()");

	/* end()-- */
	const_it2 		= map2.end(); const_it2--;
	const_ft_it2 	= ft_map2.end(); const_ft_it2--;
	sstr_comp< const_it_type2, const_ft_it_type2 >(const_it2, const_ft_it2, "const end()--");

	/* end()++ */
	// const_it2 		= map2.end(); const_it2++;
	// const_ft_it2 	= ft_map2.end(); const_ft_it2++;
	// sstr_comp< const_it_type2, const_ft_it_type2 >(const_it2, const_ft_it2, "const end()++");

	/* begin() -> end() */
	for (const_it2 = map2.begin(); const_it2 != map2.end(); const_it2++)
		sstr << const_it2->first << ":" << const_it2->second << " ";
	for (const_ft_it2 = ft_map2.begin(); const_ft_it2 != ft_map2.end(); const_ft_it2++)
		ft_sstr << const_ft_it2->first << ":" << const_ft_it2->second << " ";

	str_comp(sstr.str(), ft_sstr.str(), "const begin() -> end()");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();




	/* ***************************************************** */
	/*                CONST_REVERSE_ITERATOR                 */
	/*                    pair<int, int>                     */
	/* ***************************************************** */
	


	/* rbegin() */
	const_r_it_type2 	const_r_it2 = map2.rbegin();
	const_ft_r_it_type2 const_ft_r_it2 = ft_map2.rbegin();
	sstr_comp< const_r_it_type2, const_ft_r_it_type2 >(const_r_it2, const_ft_r_it2, "const rbegin()");
	
	/* rend()-- */
	const_r_it2 	= map2.rend(); const_r_it2--;
	const_ft_r_it2	= ft_map2.rend(); const_ft_r_it2--;
	sstr_comp< const_r_it_type2, const_ft_r_it_type2 >(const_r_it2, const_ft_r_it2, "const rend()--");

	/* rend()++ */
	// const_r_it2 	= map2.rend(); const_r_it2++;
	// const_ft_r_it2 	= ft_map2.rend(); const_ft_r_it2++;
	// sstr_comp< const_r_it_type2, const_ft_r_it_type2 >(const_r_it2, const_ft_r_it2, "const rend()++");

	/* rbegin() -> rend() */
	for (const_r_it2 = map2.rbegin(); const_r_it2 != map2.rend(); const_r_it2++)
		sstr << const_r_it2->first << ":" << const_r_it2->second << " ";
	for (const_ft_r_it2 = ft_map2.rbegin(); const_ft_r_it2 != ft_map2.rend(); const_ft_r_it2++)
		ft_sstr << const_ft_r_it2->first << ":" << const_ft_r_it2->second << " ";
	
	str_comp(sstr.str(), ft_sstr.str(), "const rbegin() -> rend()");
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();














	// std::cout << BLU "\nTEST reverse_iterator : " END << std::endl;
	// std::map<std::string, int>::reverse_iterator rit = map.rbegin();
	// std::cout << rit->first << " " << rit->second << std::endl;

	// ft::map<std::string, int>::reverse_iterator ft_rit = ft_map.rbegin();
	// std::cout << ft_rit->first << " " << ft_rit->second << std::endl;

	// std::cout << "REAL map : " << std::endl;
	// // (1) Default constructor
	// std::map<std::string, int> map1;


	// std::cout << "TEST insert(pair) : " << std::endl;

	// map1.insert(std::pair<std::string, int>("a", 1));
	// map1.insert(std::pair<std::string, int>("b", 1));
	// map1.insert(std::pair<std::string, int>("c", 1));
	// map1.insert(std::pair<std::string, int>("d", 1));
	// map1.insert(std::pair<std::string, int>("e", 1));


	// std::cout << "DISPLAY MAP : " << std::endl;
	// for(std::map<string, int>::iterator it = map1.begin();
    // it != map1.end(); ++it)
	// {
	// 	std::cout << it->first << " : " << it->second << "\n";
	// }



	// std::cout << "TEST iterator : " << std::endl;

	// std::map<std::string, int>::iterator r_it = map1.begin();
	// std::cout << r_it->first << " " << r_it->second << std::endl;
	
	// std::map<std::string, int>::iterator r_it2 = map1.end();
	// r_it2--;
	// std::cout << r_it2->first << " " << r_it2->second << std::endl;



	// std::cout << "TEST const iterator : " << std::endl;

	// std::map<std::string, int>::const_iterator r_it3 = map1.begin();
	// std::cout << r_it3->first << " " << r_it3->second << std::endl;
	// std::map<std::string, int>::const_iterator r_it4 = map1.end();
	// r_it4--;
	// std::cout << r_it4->first << " " << r_it4->second << std::endl;


	
	// // std::cout << "TEST insert(hint, pair) : " << std::endl;
	// // map1.insert(map1.begin(), std::pair<std::string, int>("b", 2));







	// std::cout << "\n\nMy map : " << std::endl;

	// ft::map<std::string, int> map2;
	// map2.insert(ft::pair<std::string, int>("a", 1));
	// map2.insert(ft::pair<std::string, int>("b", 1));
	// map2.insert(ft::pair<std::string, int>("c", 1));
	// map2.insert(ft::pair<std::string, int>("d", 1));
	// map2.insert(ft::pair<std::string, int>("e", 1));
	// map2.insert(ft::pair<std::string, int>("f", 1));
	// map2.insert(ft::pair<std::string, int>("g", 1));
	// map2.insert(ft::pair<std::string, int>("h", 1));
	// map2.insert(ft::pair<std::string, int>("i", 1));


	// // map2.insert(ft::pair<std::string, int>("f", 1));
	// // map2.insert(ft::pair<std::string, int>("g", 1));
	// // map2.insert(ft::pair<std::string, int>("h", 1));
	// // map2.insert(ft::pair<std::string, int>("i", 1));
	// // map2.insert(ft::pair<std::string, int>("j", 1));
	// // map2.insert(ft::pair<std::string, int>("k", 1));
	// // map2.insert(ft::pair<std::string, int>("l", 1));
	// // map2.insert(ft::pair<std::string, int>("m", 1));
	// // map2.insert(ft::pair<std::string, int>("n", 1));
	// // map2.insert(ft::pair<std::string, int>("o", 1));
	// // map2.insert(ft::pair<std::string, int>("p", 1));
	// // map2.insert(ft::pair<std::string, int>("q", 1));
	// // map2.insert(ft::pair<std::string, int>("r", 1));
	// // map2.insert(ft::pair<std::string, int>("s", 1));
	// // map2.insert(ft::pair<std::string, int>("t", 1));
	// // map2.insert(ft::pair<std::string, int>("u", 1));
	// // map2.insert(ft::pair<std::string, int>("v", 1));
	// // map2.insert(ft::pair<std::string, int>("w", 1));
	// // map2.insert(ft::pair<std::string, int>("x", 1));
	// // map2.insert(ft::pair<std::string, int>("y", 1));
	// // map2.insert(ft::pair<std::string, int>("z", 1));
	// // map2.insert(ft::pair<std::string, int>("aa", 1));
	// // map2.insert(ft::pair<std::string, int>("ab", 1));
	// // map2.insert(ft::pair<std::string, int>("za", 1));
	// // map2.insert(ft::pair<std::string, int>("zaa", 1));
	// // map2.insert(ft::pair<std::string, int>("zab", 1));
	// // map2.insert(ft::pair<std::string, int>("zac", 1));
	// // map2.insert(ft::pair<std::string, int>("zad", 1));
	// // map2.insert(ft::pair<std::string, int>("zae", 1));
	// // map2.insert(ft::pair<std::string, int>("zaf", 1));
	// // map2.insert(ft::pair<std::string, int>("zag", 1));
	// // map2.insert(ft::pair<std::string, int>("zah", 1));
	// // map2.insert(ft::pair<std::string, int>("zai", 1));
	// // map2.insert(ft::pair<std::string, int>("zaj", 1));
	// // map2.insert(ft::pair<std::string, int>("zak", 1));
	// // map2.insert(ft::pair<std::string, int>("zal", 1));
	// // map2.insert(ft::pair<std::string, int>("zb", 1));
	// // map2.insert(ft::pair<std::string, int>("zbq", 1));
	// // map2.insert(ft::pair<std::string, int>("zs", 1));
	// // map2.insert(ft::pair<std::string, int>("zs", 1));
	// // map2.insert(ft::pair<std::string, int>("zsa", 1));
	// // map2.insert(ft::pair<std::string, int>("zsb", 1));
	// // map2.insert(ft::pair<std::string, int>("zsc", 1));
	// // map2.insert(ft::pair<std::string, int>("zsd", 1));
	// // map2.insert(ft::pair<std::string, int>("zse", 1));
	// // map2.insert(ft::pair<std::string, int>("zsf", 1));
	// // map2.insert(ft::pair<std::string, int>("zsg", 1));
	// // map2.insert(ft::pair<std::string, int>("zsh", 1));
	// // map2.insert(ft::pair<std::string, int>("zsha", 1));
	// // map2.insert(ft::pair<std::string, int>("zshb", 1));
	// // map2.insert(ft::pair<std::string, int>("zshc", 1));
	// // map2.insert(ft::pair<std::string, int>("zshd", 1));
	// // map2.insert(ft::pair<std::string, int>("zshq", 1));
	// // map2.insert(ft::pair<std::string, int>("zshw", 1));
	// // map2.insert(ft::pair<std::string, int>("zshe", 1));
	// // map2.insert(ft::pair<std::string, int>("zshr", 1));
	// // map2.insert(ft::pair<std::string, int>("zsht", 1));
	// // map2.insert(ft::pair<std::string, int>("zshy", 1));
	// // map2.insert(ft::pair<std::string, int>("zshu", 1));
	// // map2.insert(ft::pair<std::string, int>("zshi", 1));
	// // map2.insert(ft::pair<std::string, int>("zsho", 1));
	// // map2.insert(ft::pair<std::string, int>("zshp", 1));
	// // map2.insert(ft::pair<std::string, int>("zsha", 1));
	// // map2.insert(ft::pair<std::string, int>("zshs", 1));
	// // map2.insert(ft::pair<std::string, int>("zshd", 1));
	// // map2.insert(ft::pair<std::string, int>("zshf", 1));
	// // map2.insert(ft::pair<std::string, int>("zshg", 1));
	// // map2.insert(ft::pair<std::string, int>("zshh", 1));
	// // map2.insert(ft::pair<std::string, int>("zshj", 1));
	// // map2.insert(ft::pair<std::string, int>("zshk", 1));
	// // map2.insert(ft::pair<std::string, int>("zci", 1));

	// map2.display_tree();

	// // map2.insert(ft::pair<std::string, int>("c", 3));
	// // std::cout << "size : " << map2.size() << std::endl;
	// // std::cout << "map2[\"a\"] : " << map2["a"] << std::endl;
	// // std::cout << "map2[\"b\"] : " << map2.at("a") << std::endl;


	// std::cout << "TEST iterator : " << std::endl;

	// ft::map<std::string, int>::iterator m_it = map2.begin();
	// std::cout << m_it->first << " " << m_it->second << std::endl;
	// ft::map<std::string, int>::iterator m_it2 = map2.end();
	// m_it2--;
	// std::cout << m_it2->first << " " << m_it2->second << std::endl;




	// std::cout << "TEST const iterator : " << std::endl;

	// ft::map<std::string, int>::const_iterator m_it3 = map2.begin();
	// std::cout << m_it3->first << " " << m_it3->second << std::endl;
	// ft::map<std::string, int>::const_iterator m_it4 = map2.end();
	// m_it4--;
	// std::cout << m_it4->first << " " << m_it4->second << std::endl;





	// // find
	// // ft::map<std::string, int>::iterator it2 = map2.find("a");

	// // map2.insert(ft::pair<std::string, int>("b", 2));
	// // std::cout << "size : " << map2.size() << std::endl;

	// // ft::map<std::string, int>::iterator it2 = map2.find("a");
	// // std::cout << it2->first << " " << it2->second << std::endl;

	// // std::cout << "map2[\"a\"] : " << map1["a"] << std::endl;

	// // map2["something"] = 69;
	// // std::cout << "map1[\"something\"] = " << map2["something"] << std::endl;
}

	

	


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