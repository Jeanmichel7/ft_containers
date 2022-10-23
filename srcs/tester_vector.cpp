/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_vector.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:05:46 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/23 23:47:35 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void tester_vector(void)
{
  std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	std::vector<int>::const_iterator itc = v.begin();
	std::cout << "itc : " << *itc << std::endl;
	itc++;
	std::cout << "itc : " << *itc << std::endl;


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

	std::cout << BLU "TEST max size : " END << test.max_size() << std::endl;

	std::vector<int>::iterator it = test.begin();
	for(; it != test.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;


	// ft::Vector<int> test123123;
	// test123123.push_back(1);
	// test123123.push_back(2);
	// test123123.push_back(3);
	// std::cout << BLU "TEST max size ici: " END << test123123.max_size() << std::endl;




	std::cout << BLU "TEST assign : " END << std::endl;
	// test.assign(1000000000000000000, 1);										//SEGV
	test.assign(10, 1);


	//std::vector<int> test_copie = test;
	//std::vector<int>::iterator it2 = test_copie.begin();
	//for(; it2 != test_copie.end(); it2++)
	//	std::cout << *it2 << std::endl;


	//std::cout << "at : " << test.at(0) << std::endl;
	//std::cout << "[2] : " << test[2] << std::endl;
	//std::cout << "data: " 			<< test.data() 	<< std::endl;



	std::cout << BLU "TEST rbegin derefenced : " END << *(test.rbegin()) << std::endl;
	std::cout << BLU "TEST rbegin : \n" END;
	std::vector<int>::reverse_iterator it2 = test.rbegin();

	for(; it2 != test.rend(); it2++)
		std::cout << *it2 << " ";
	std::cout << std::endl;



	std::cout << BLU "TEST template swap : " END << std::endl;
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


	std::cout << BLU "TEST reserve : " END <<  std::endl;
	
	std::vector<int> test_reserve_real(10, 1);
	//std::vector<int> test_reserve_real(2305843009213693952, 1);
	std::vector<int>::iterator it404 = test_reserve_real.begin();

	for(; it404 != test_reserve_real.end(); it404++)
		std::cout << *it404 ;
	std::cout << "\n";
	std::cout << "capacity : " << test_reserve_real.capacity() << std::endl;

	test_reserve_real.reserve(100);
	//test_reserve_real.reserve(test_reserve_real.max_size());
	//libc++abi.dylib: terminating with uncaught exception of type std::bad_alloc: std::bad_alloc

	it404 = test_reserve_real.begin();
	for(; it404 != test_reserve_real.end(); it404++)
		std::cout << *it404 ;
	std::cout << "\n";
	std::cout << "capacity 	: " << test_reserve_real.capacity() << std::endl;
	std::cout << "size 		: " << test_reserve_real.size() << std::endl;


	std::cout << BLU "TEST erase() : " END << std::endl;
	test.erase(test.begin());
	// test.erase(test.end());										//SEGF ABORT negative-param

	
	it404 = test.begin();
	for(; it404 != test.end(); it404++)
		std::cout << *it404 ;
	std::cout << "\n";
	std::cout << "capacity 	: " << test.capacity() << std::endl;
	std::cout << "size 		: " << test.size() << std::endl;








	std::cout << BLU "TEST clear real : " END << std::endl;
	test.clear();
	std::cout << "size : " << test.size() << std::endl;
	std::cout << "capacity : " << test.capacity() << std::endl;
	std::cout << "empty : " << test.empty() << std::endl;


	//std::cout << BLU "TEST Insert()" END << std::endl;
	//std::vector<int> test_insert1;
	//std::vector<int>::iterator iti;

	//iti = test_insert1.begin();
	//test_insert1.insert(iti, 42);

	//iti = test_insert1.begin();
	//test_insert1.insert(iti, 100000000000000, 42);

	//iti = test_insert1.begin();
	//test_insert1.insert(iti, 10000000000000, 42);













	std::cout << "\n\n\n\nMy vector : \n\n\n";






	std::cout << BLU "TEST constructor : " END << std::endl;
	ft::Vector<int> my_vector;

	my_vector.push_back(1);
	my_vector.push_back(2);
	my_vector.push_back(3);
	my_vector.push_back(4);
	my_vector.display("");

	ft::Vector<int> my_vectr(my_vector.begin(), my_vector.end());
	my_vectr.display("my_vectr(my_vector.begin(), my_vector.end())");




	std::cout << BLU "TEST constructor count : " END << std::endl;
	ft::Vector<int> my_vector_count(10, 3);
	my_vector_count.display("my_vector_count(10, 1)");

	ft::Vector<int>::iterator it_v_count_begin = my_vector_count.begin();
	ft::Vector<int>::iterator it_v_count_end = my_vector_count.end();





	std::cout << BLU "TEST constructor iterator : " END << std::endl;
	ft::Vector<int> my_vector_iterator(it_v_count_begin, it_v_count_end);
	my_vector_iterator.display(" my_vector_iterator(it_v_count_begin, it_v_count_end)");




	
	std::cout << BLU "TEST popback real : " END;
	// std::cout << my_vector.back() << std::endl; 					//SEGV
	my_vector.pop_back();
	my_vector.display("pop_back()");

	// std::cout << "get allocator 	: " << my_vector.get_allocator() << std::endl;
	std::cout << "capacity 	: " << my_vector.capacity() << std::endl;
	std::cout << "at(2)		: " << my_vector.at(2)		<< std::endl;
	my_vector.at(2) = 12000;
	my_vector.display("");
	std::cout << "at(2)		: " << my_vector.at(2) 		<< std::endl;
	std::cout << ".[2]		: " << my_vector[2] 		<< std::endl;
	std::cout << "front		: " << my_vector.front()	<< std::endl;
	std::cout << "back		: " << my_vector.back() 	<< std::endl;
	std::cout << "data		: " << my_vector.data() 	<< std::endl;


	std::cout << BLU "\n\nTEST assign : " END << std::endl;
	// my_vector.assign(100000000000000000000000000000000000000,2);			//SEGV
	// my_vector.assign(100000000000000000000000000000,2); //SEGV				//exception bad_alloc
	my_vector.assign(15,2);
	my_vector.display("assign(15,2)");


	std::cout << BLU "\n\nTEST assign template iterator : " END << std::endl;
	my_vector.assign(it_v_count_begin, it_v_count_end);
	my_vector.display("assign(it_v_count_begin, it_v_count_end)");






	std::cout << BLU "TEST Insert()" END << std::endl;
	ft::Vector<int>::iterator it_insert_begin = my_vector.begin();

	my_vector.insert(it_insert_begin, 42);
	my_vector.display("insert(it_insert_begin, 42)");


	ft::Vector<int>::iterator it_insert_end = my_vector.end();

	my_vector.insert(it_insert_end, 42);
	my_vector.display("insert(it_insert_end, 42)");



	for(int i = 0; i < 10; i++)
	{
		ft::Vector<int>::iterator it_insert_middle = my_vector.begin() + (my_vector.size() / 2);

		my_vector.insert(it_insert_middle, 21);
		my_vector.display("insert(it_insert_middle, 21)");
	}


	ft::Vector<int>::iterator it_insert_middle = my_vector.begin() + (my_vector.size() / 2);
	my_vector.insert(it_insert_middle, 2, 2);
	my_vector.display("insert(it_insert_middle, 2, 2)");


	std::cout << BLU "TEST Insert(pos, n, v) avec depassement " END << std::endl;

	it_insert_middle = my_vector.begin() + (my_vector.size() / 2);
	my_vector.insert(it_insert_middle, 20, 33);
	my_vector.display("insert(it_insert_middle, 20, 33)");

	it_insert_end = my_vector.end();
	my_vector.insert(it_insert_end, 3, 13);
	my_vector.display("insert(it_insert_end, 10, 5)");

	std::cout << BLU "TEST Insert(pos, n, v) avec depassement size_max() " END << std::endl;

	my_vector.insert(my_vector.begin(), my_vector.max_size(), 5);
	my_vector.display("insert(my_vector.begin(), my_vector.max_size(), 5)");




	// my_vector.erase(my_vector.begin(), my_vector.end());

	ft::Vector<int> my_tmp_vector(5,5);
	my_tmp_vector.display("my_tmp_vector");


	ft::Vector<int>::iterator	it_tmp_first = my_tmp_vector.begin();
	ft::Vector<int>::iterator	it_tmp_half = my_tmp_vector.begin() + (my_tmp_vector.size() / 2);



	my_vector.resize(12);
	my_vector.display("resize(12)");

	std::cout << BLU "TEST Insert(pos, first, last)" END << std::endl;

	my_vector.insert(my_vector.begin(), it_tmp_first, it_tmp_half);
	my_vector.display("insert(my_vector.begin(), it_tmp_first, it_tmp_half)");




	it_tmp_half = my_tmp_vector.begin() + (my_tmp_vector.size() / 2);
	ft::Vector<int>::iterator	it_tmp_end = my_tmp_vector.end();

	my_vector.insert(my_vector.begin(), it_tmp_half, it_tmp_end);
	my_vector.display("insert(my_vector.begin(), it_tmp_half, it_tmp_end)");





	ft::Vector<int> my_tmp_vector2(10,10);
	my_tmp_vector2.display("my_tmp_vector2(10, 10)");

	ft::Vector<int>::iterator it_tmp2_begin = my_tmp_vector2.begin();
	ft::Vector<int>::iterator it_tmp2_end = my_tmp_vector2.end();

	ft::Vector<int>::iterator it_middle = my_vector.begin() + (my_vector.size() / 2);
	my_vector.insert(it_middle, it_tmp2_begin, it_tmp2_end);
	my_vector.display("insert(it_middle, it_tmp_begin, it_tmp_end)");


	it_tmp2_begin = my_tmp_vector2.begin();
	it_tmp2_end = my_tmp_vector2.end();
	it_middle = my_vector.begin() + (my_vector.size() / 2);
	my_vector.insert(it_middle, it_tmp2_begin, it_tmp2_end);
	my_vector.display("insert(it_middle, it_tmp_begin, it_tmp_end)");


	it_tmp2_begin = my_tmp_vector2.begin();
	it_tmp2_end = my_tmp_vector2.end();
	it_middle = my_vector.begin() + (my_vector.size() / 2);
	my_vector.insert(it_middle, it_tmp2_begin, it_tmp2_end);
	my_vector.display("insert(it_middle, it_tmp_begin, it_tmp_end)");








	ft::Vector<int> test_insert1;
	ft::Vector<int>::iterator iti;

	iti = test_insert1.begin();
	test_insert1.insert(iti, 42);
	test_insert1.display("insert(iti, 42)");


	iti = test_insert1.begin();
	test_insert1.insert(iti, 42, 42);
	test_insert1.display("insert(iti, 42, 42)");

	iti = test_insert1.begin();
	// test_insert1.insert(iti, 100000000000000, 42);
	test_insert1.insert(iti, 20, 42);
	test_insert1.display("insert(iti, test_insert1.max_size(), 42)");

	iti = test_insert1.begin();
	test_insert1.insert(iti, test_insert1.max_size(), 42);
	test_insert1.display("insert(iti, test_insert1.max_size(), 42)");










	std::cout << BLU "\n\nTEST operator comparaison : " END << std::endl;
	std::cout 	<< my_vector[0] << " "
				<< (my_vector[0] > my_vector[0] ? "plus grand" : "plus petit ou egal" )
				<< " que " << my_vector[0] << std::endl;

	my_vector.display("");



	ft::Vector<char> my_vector2;
	std::cout << BLU "TEST empty	: " END << my_vector2.empty() << std::endl;
	std::cout << BLU "TEST size	: " END << my_vector2.size() << std::endl;
	std::cout << BLU "TEST max size	: " END << my_vector2.max_size() << std::endl;


	//std::cout << BLU "TEST popback : " END << my_vector2.back() << std::endl;	//SEGV
	
	std::cout << BLU "TEST push back " END<< std::endl;
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
	my_vector2.display("");


	std::cout << BLU "TEST back 	: " END << my_vector2.back() 	<< std::endl;
	std::cout << BLU "TEST empty 	: " END << my_vector2.empty() 	<< std::endl;
	std::cout << BLU "TEST size 	: " END << my_vector2.size() 	<< std::endl;


	std::cout << BLU "TEST iterator : " END << std::endl;
	ft::Vector<char>::iterator it5 = my_vector2.begin();
	for(; it5 != my_vector2.end(); it5++)
		std::cout << *it5 << " ";
	std::cout << std::endl;

	

	std::cout << BLU "TEST reverse_iterator : " END << std::endl;
	ft::Vector<char>::reverse_iterator it4 = my_vector2.rbegin();
	ft::Vector<char>::reverse_iterator it4e = my_vector2.rend();
	for(; it4 != it4e; it4++)
		std::cout << *it4 << " " ;
	std::cout << std::endl;
	my_vector2.display("");


	std::cout << BLU "TEST popback  " END;
	my_vector2.pop_back();
	my_vector2.display(""); 


	std::cout << BLU "TEST resize 15 " END;
	my_vector2.resize(15);
	my_vector2.display("");

	std::cout << BLU "TEST resize 5 " END;
	my_vector2.resize(5);
	my_vector2.display("");

	std::cout << BLU "TEST resize 20 " END;
	my_vector2.resize(20, 's');
	my_vector2.display("");


	std::cout << BLU "TEST swap : " END << std::endl;
	ft::Vector<int> test_swap(10, 1);
	ft::Vector<int> test_swap2(15,2);
	test_swap.display("");
	test_swap2.display("");
	test_swap.ft::Vector<int>::swap(test_swap2);
	test_swap.display("");
	test_swap2.display("");












	std::cout << BLU "TEST reserve : " END <<  std::endl;
	ft::Vector<long long unsigned> test_reserve(10, 1);
	ft::Vector<long long unsigned>::iterator it4040 = test_reserve.begin();

	for(; it4040 != test_reserve.end(); it4040++)
		std::cout << *it4040 ;
	std::cout << "\n";
	std::cout << "capacity : " << test_reserve.capacity() << std::endl;

	// test_reserve.reserve(test_reserve.max_size());
	// test_reserve.reserve(1000000000000000000);
	test_reserve.reserve(100);

	it4040 = test_reserve.begin();
	for(; it4040 != test_reserve.end(); it4040++)
		std::cout << *it4040 ;
	std::cout << "\n";
	std::cout << "capacity : " << test_reserve.capacity() << std::endl;









	std::cout << BLU "\nTEST erase(n) : " END <<  std::endl;
	ft::Vector<int> test_erase;
	for(int i = 0; i < 10; i++) {
		test_erase.push_back(i);
	}
	test_erase.display("test_erase");

	test_erase.erase(test_erase.begin());
	test_erase.display("test_erase.begin()");

	test_erase.erase(test_erase.begin() + 5);
	test_erase.display("test_erase.begin() + 5");

	// test_erase.erase(test_erase.end());								// segv
	test_erase.erase(test_erase.end() - 1);
	test_erase.display("test_erase.end() - 1");



	test_erase.insert(test_erase.begin(), 0);
	test_erase.insert(test_erase.begin() + 6, 6);
	test_erase.insert(test_erase.begin() + 9, 9);
	test_erase.display("");

	std::cout << BLU "\nTEST erase(first, last) : " END <<  std::endl;


	test_erase.erase(test_erase.begin() + 5, test_erase.begin() + 8);
	test_erase.display("test_erase.begin() + 5, test_erase.begin() + 8");






	std::cout << BLU "\nTEST clear : " END << std::endl;
	test_reserve.clear();
	std::cout << "size 		: " << test_reserve.size() << std::endl;
	std::cout << "capacity 	: " << test_reserve.capacity() << std::endl;
	std::cout << "empty() 	: " << test_reserve.empty() << std::endl;




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







	std::cout << BLU "\nTEST Pair() : " END << std::endl;

	std::pair<int, char> foo1(10, 'z');
	std::pair<int, char> bar1(90, 'a');

	if (foo1 == bar1)
		std::cout << "foo1 and bar1 are equal\n";
	if (foo1 != bar1)
		std::cout << "foo1 and bar1 are not equal\n";
	if (foo1 < bar1)
		std::cout << "foo1 is less than bar1\n";
	if (foo1 > bar1)
		std::cout << "foo1 is greater than bar1\n";
	if (foo1 <= bar1)
		std::cout << "foo1 is less than or equal to bar1\n";
	if (foo1 >= bar1)
		std::cout << "foo1 is greater than or equal to bar1\n";


	ft::pair<int, char> foo2(10, 'z');
	ft::pair<int, char> bar2(90, 'a');

	if (foo2 == bar2)
		std::cout << "foo2 and bar2 are equal\n";
	if (foo2 != bar2)
		std::cout << "foo2 and bar2 are not equal\n";
	if (foo2 < bar2)
		std::cout << "foo2 is less than bar2\n";
	if (foo2 > bar2)
		std::cout << "foo2 is greater than bar2\n";
	if (foo2 <= bar2)
		std::cout << "foo2 is less than or equal to bar2\n";
	if (foo2 >= bar2)
		std::cout << "foo2 is greater than or equal to bar2\n";








	std::cout << BLU "\nTEST make_pair() : " END << std::endl;

	std::pair<int, int> foo3;
	std::pair<int, int> bar3;

	foo3 = std::make_pair(10, 20);
	bar3 = std::make_pair(10.5, 'A'); // ok: implicit conversion from pair<double,char>

	std::cout << "foo3: " << foo3.first << ", " << foo3.second << '\n';
	std::cout << "bar3: " << bar3.first << ", " << bar3.second << '\n';


	ft::pair<int, int> foo4;
	ft::pair<int, int> bar4;

	foo4 = ft::make_pair(10, 20);
	bar4 = ft::make_pair(10.5, 'A'); // ok: implicit conversion from pair<double,char>

	std::cout << "foo4: " << foo4.first << ", " << foo4.second << '\n';
	std::cout << "bar4: " << bar4.first << ", " << bar4.second << '\n';


	// C++ 11
	// std::cout << BLU "\nTEST pair swap : " END << std::endl;

	// std::cout << "foo1 contains: " << foo1.first << " and " << foo1.second << '\n';
	// std::cout << "bar1 contains: " << bar1.first << " and " << bar1.second << '\n';
	// std::swap(foo1,bar1);
	// std::cout << "foo1 contains: " << foo1.first << " and " << foo1.second << '\n';
	// std::cout << "bar1 contains: " << bar1.first << " and " << bar1.second << '\n';


	// std::cout << "foo2 contains: " << foo2.first << " and " << foo2.second << '\n';
	// std::cout << "bar2 contains: " << bar2.first << " and " << bar2.second << '\n';
	// // ft::pair<int, char>::swap(foo2,bar2);
	// ft::swap(foo2,bar2);
	// std::cout << "foo2 contains: " << foo2.first << " and " << foo2.second << '\n';
	// std::cout << "bar2 contains: " << bar2.first << " and " << bar2.second << '\n';

}
