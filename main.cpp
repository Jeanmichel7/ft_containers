/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:19:53 by jrasser           #+#    #+#             */
/*   Updated: 2022/09/01 02:59:28 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <vector>
#include "Vector.hpp"
//#include "Iterator_traits.hpp"

#include <map>
#include "Map.hpp"

//using namespace ft;
//using namespace std;

#include <typeinfo>     // typeid

int main()
{


	// std::map<std::string, int> map;

	// map["test"] = 42;

	// std::cout << map["test"] << std::endl;
	



















































/*
	// typedef std::iterator_traits<char> testee;

	// testee t;
	// std::cout << "iterator_traits<int>::iterator_category: "
	// 	<< t.iterator_category.name() << std::endl;

	// typedef std::iterator_traits<int>::value_type bli;
	// std::cout << "iterator_traits<int>::value_type: "
	// 	<< typeid(testee::value_type).name() << std::endl;

	std::vector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	//test.assign(10, 1);

	std::cout << "TEST max size : " << test.max_size() << std::endl;

	std::vector<int>::iterator it = test.begin();
	for(; it != test.end(); it++)
		std::cout << *it << std::endl;

	//std::vector<int> test_copie = test;
	//std::vector<int>::iterator it2 = test_copie.begin();
	//for(; it2 != test_copie.end(); it2++)
	//	std::cout << *it2 << std::endl;


	//std::cout << "at : " << test.at(0) << std::endl;
	//std::cout << "[2] : " << test[2] << std::endl;
	//std::cout << "data: " 			<< test.data() 	<< std::endl;



	std::cout << *(test.rbegin()) << std::endl;
	std::cout << "rbegin : \n";
	std::vector<int>::reverse_iterator it2 = test.rbegin();

	for(; it2 != test.rend(); it2++)
		std::cout << *it2 << std::endl;



	std::cout << "test template swap : " << std::endl;
	std::vector<int> test2(10, 1);


	std::vector<int>::iterator it3 = test.begin();
	for(; it3 != test.end(); it3++)
		std::cout << *it3 ;
	std::cout << "\n";


	std::vector<int>::iterator it44 = test2.begin();
	for(; it44 != test2.end(); it44++)
		std::cout << *it44 ;
	std::cout << "\n";


	test.std::vector<int>::swap(test2);
	std::cout << "\n\n";


	std::vector<int>::iterator it30 = test.begin();
	for(; it30 != test.end(); it30++)
		std::cout << *it30 ;
	std::cout << "\n";

	std::vector<int>::iterator it40 = test2.begin();
	for(; it40 != test2.end(); it40++)
		std::cout << *it40 ;
	std::cout << "\n";
	//test.swap(test2);


	// std::cout << "TEST reserve : " <<  std::endl;
	
	// std::vector<int> test_reserve(10, 1);
	// std::vector<int>::iterator it404 = test_reserve.begin();

	// for(; it404 != test_reserve.end(); it404++)
	// 	std::cout << *it404 ;
	// std::cout << "\n";
	// std::cout << "capacity : " << test_reserve.capacity() << std::endl;

	// test_reserve.reserve(20);

	// it404 = test_reserve.begin();
	// for(; it404 != test_reserve.end(); it404++)
	// 	std::cout << *it404 ;
	// std::cout << "\n";
	// std::cout << "capacity : " << test_reserve.capacity() << std::endl;


	std::cout << "TEST clear real : " << std::endl;
	test.clear();
	std::cout << "size : " << test.size() << std::endl;
	std::cout << "capacity : " << test.capacity() << std::endl;
	std::cout << "empty : " << test.empty() << std::endl;
*/















	std::cout << "\n\n\n\nMy vector : \n\n\n";














	ft::vector<int> my_vector;


	std::cout << "TEST popback real : " ;
	// std::cout << my_vector.back() << std::endl; 					//SEGV

	my_vector.push_back(1);
	my_vector.push_back(2);
	my_vector.push_back(3);
	my_vector.push_back(4);


	//my_vector.push_back(1);
	//for(int i = 0; i < 3; i++)
	//	std::cout << *(my_vector.getElem() + i) << std::endl;

	my_vector.get_allocator();


	// ft::vector<int> test3 = my_vector;
	// for(int i = 0; i < 3; i++)
	// 	std::cout << *(test3.getElem() + i) << std::endl;

	// ft::vector<int> test_aff(5, 10);
	// for(int i = 0; i < 5; i++)
	// 	std::cout << *(test_aff.getElem() + i) << std::endl;

	// test_aff = my_vector;
	// for(int i = 0; i < 10; i++)
	// 	std::cout << *(test_aff.getElem() + i) << std::endl;


	//std::cout << "capacity : " << my_vector.capacity() << std::endl;
	//std::cout << "at : " << my_vector.at(2) << std::endl;
	//my_vector.at(2) = 12000;
	//std::cout << "at : " << my_vector.at(2) << std::endl;

	//std::cout << "my_vector[2]: "	<< my_vector[2] 		<< std::endl;
	//std::cout << "ret: " 			<< my_vector[2] 		<< std::endl;
	//std::cout << "front: " 			<< my_vector.front()	<< std::endl;
	//std::cout << "back: " 			<< my_vector.back() 	<< std::endl;
	//std::cout << "data: " 			<< my_vector.data() 	<< std::endl;

	//my_vector.assign(10,2);
	ft::vector<int>::iterator it100 = my_vector.begin();

	for(; it100 != my_vector.end(); it100++)
		std::cout << *it100 << std::endl;

	// std::cout << "TEST operator real : " << std::endl;
	// std::cout 	<< my_vector[100] << " "
	// 			<< (my_vector[0] > my_vector[0] ? "plus grand" : "plus petit" )
	// 			<< " que " << my_vector[0] << std::endl;


	ft::vector<char> my_vector2;
	std::cout << "TEST empty : " << my_vector2.empty() << std::endl;
	std::cout << "TEST size : " << my_vector2.size() << std::endl;
	std::cout << "TEST max size : " << my_vector2.max_size() << std::endl;


	//std::cout << "TEST popback : " << my_vector2.back() << std::endl;
	
	
	my_vector2.push_back('a');
	my_vector2.push_back('b');
	my_vector2.push_back('c');
	my_vector2.push_back('d');
	my_vector2.push_back('e');
	my_vector2.push_back('f');
	my_vector2.push_back('g');
	my_vector2.push_back('h');
	my_vector2.push_back('i');
	my_vector2.push_back('j');

	std::cout << "TEST popback : " << my_vector2.back() << std::endl;

	std::cout << "TEST empty : " << my_vector2.empty() << std::endl;
	std::cout << "TEST size : " << my_vector2.size() << std::endl;
	std::cout << "TEST max size : " << my_vector2.max_size() << std::endl;



	std::cout << "TEST iterator : " << std::endl;
	ft::vector<char>::iterator it5 = my_vector2.begin();
	for(; it5 != my_vector2.end(); it5++)
		std::cout << *it5 << " ";
	std::cout << std::endl;
	

	std::cout << "TEST reverse_iterator : " << std::endl;
	ft::vector<char>::reverse_iterator it4 = my_vector2.rbegin();
	ft::vector<char>::reverse_iterator it4e = my_vector2.rend();
	for(; it4 != it4e; it4++)
		std::cout << *it4 << " " ;
	std::cout << std::endl;


	// std::cout << "TEST popback : ";
	// my_vector2.pop_back();
	// my_vector2.display();


	// std::cout << "TEST resize : ";
	// my_vector2.resize(10);
	// my_vector2.display();

	// my_vector2.resize(20, 's');
	// my_vector2.display();


	std::cout << "TEST swap : " << std::endl;
	ft::vector<int> test_swap(10, 1);
	ft::vector<int> test_swap2(15,2);
	test_swap.ft::vector<int>::swap(test_swap2);
	//test_swap.swap(test_swap2);

	test_swap.display();
	test_swap2.display();




	std::cout << "TEST operator : " ;
	std::cout 	<< test_swap[0] << " "
				<< (test_swap[0] > test_swap2[0] ? "plus grand" : "plus petit" )
				<< " que " << test_swap2[0] << std::endl;




	std::cout << "TEST reserve : " <<  std::endl;
	
	ft::vector<int> test_reserve(10, 1);
	ft::vector<int>::iterator it404 = test_reserve.begin();

	for(; it404 != test_reserve.end(); it404++)
		std::cout << *it404 ;
	std::cout << "\n";
	std::cout << "capacity : " << test_reserve.capacity() << std::endl;

	test_reserve.reserve(20);

	it404 = test_reserve.begin();
	for(; it404 != test_reserve.end(); it404++)
		std::cout << *it404 ;
	std::cout << "\n";
	std::cout << "capacity : " << test_reserve.capacity() << std::endl;





	std::cout << "TEST clear : " << std::endl;
	test_reserve.clear();
	std::cout << "size : " << test_reserve.size() << std::endl;
	std::cout << "capacity : " << test_reserve.capacity() << std::endl;
	std::cout << "empty : " << test_reserve.empty() << std::endl;



	return 0;
}


