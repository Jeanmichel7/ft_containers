/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendu_tester_vector.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:39:23 by jrasser           #+#    #+#             */
/*   Updated: 2022/11/04 21:12:23 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.hpp"



template < typename V >
void display_vector(V &vector) {
	std::cout << std::endl << "----------------------------------------"
	<< "----------------------------------------" << std::endl;

	std::cout << "size 	: " << vector.size() << std::endl;
	std::cout << "max_size: " << vector.max_size() << std::endl;
	std::cout << "empty	: " << vector.empty() << std::endl;
	// std::cout << "front	: " << vector.front() << std::endl;
	// std::cout << "back	: " << vector.back() << std::endl;
	std::cout << "content : ";

	typename V::iterator it = vector.begin();
	while (it != vector.end())
	{
		if (it != --vector.end())
			std::cout << *it << ", ";
		else
			std::cout << *it;
		it++;
	}
	std::cout << std::endl << "----------------------------------------"
	<< "----------------------------------------\n\n" << std::endl;
}



void rendu_tester_vector( void ) {
	display_title("VECTOR < string >");
	rendu_tester_vector_type< std::string >();

	display_title("VECTOR < int >");
	rendu_tester_vector_type< int >();

	display_title("VECTOR < char >");
	rendu_tester_vector_type< char >();

	display_title("VECTOR < float >");
	rendu_tester_vector_type< float >();
}


template< typename vector_type >
void rendu_tester_vector_type() {

	typedef vector_type 						T;
	typedef STL_TYPE::vector< vector_type >									std_vector_t;

	/* define type pointer */
	typedef typename std_vector_t::pointer 								std_ptr_t;
	typedef typename std_vector_t::const_pointer 					std_cptr_t;
	
	/* define type reference */
	typedef typename std_vector_t::reference							std_ref_t;
	typedef typename std_vector_t::const_reference				std_cref_t;

	/* define type iterator */
	typedef typename std_vector_t::iterator 							std_it_type;
	typedef typename std_vector_t::const_iterator 				std_cit_type;
	typedef typename std_vector_t::reverse_iterator 			std_rit_type;
	typedef typename std_vector_t::const_reverse_iterator std_rcit_type;




	std::cout <<  "\n\nTEST constructor vector() "  << std::endl;
	std_vector_t stl_vector;
	std_vector_t stl_vector_count(5);
	std_it_type stl_it;
	stl_it = stl_vector_count.insert( stl_vector_count.end(), convert<T>("123") );
	stl_it = stl_vector.insert( stl_vector.begin(), convert<T>("a") );
	stl_it = stl_vector.insert( stl_vector.begin(), convert<T>("b") );
	stl_it = stl_vector.insert( stl_vector.end(), convert<T>("c") );
	stl_it = stl_vector.insert(stl_vector.begin() + 1, convert<T>("d"));
	stl_it = stl_vector.insert(stl_vector.begin() + 2, convert<T>("e"));
	stl_vector.insert(stl_vector.end(), convert<T>("ff"));
	stl_vector.insert(stl_vector.end(), convert<T>("fff"));
	std_vector_t stl_vector_copy(stl_vector);
	stl_vector_copy.insert(stl_vector_copy.begin(), convert<T>("a"));
	stl_vector_copy.insert(stl_vector_copy.begin(), convert<T>("b"));
	stl_vector_copy.push_back(convert<T>("f"));

	display_vector(stl_vector);
	display_vector(stl_vector_count);
	display_vector(stl_vector_copy);




	std::cout <<  "\n\nTEST insert(pos, cout, value) "  << std::endl;
	stl_vector.insert(stl_vector.end(), 2, convert<T>("123"));
	stl_vector.insert(stl_vector.begin(), 2, convert<T>("000"));
	stl_vector.insert(stl_vector.begin() + 2, 2, convert<T>("42"));
	std_vector_t stl_vector2(stl_vector.begin(), stl_vector.end());
	stl_vector2[0] = convert<T>("zZz");
	std_vector_t stl_vector3(stl_vector.begin() + 2, stl_vector.end() - 2);
	std_vector_t stl_vector4(stl_vector);
	stl_vector4[0] = convert<T>("zZz");
	std_vector_t stl_vector5 = stl_vector;
	stl_vector5[0] = convert<T>("zZz123");
	stl_vector_count = stl_vector;
	stl_vector_count[0] = convert<T>("zZzaa123");

	display_vector(stl_vector);
	display_vector(stl_vector2);
	display_vector(stl_vector3);
	display_vector(stl_vector4);
	display_vector(stl_vector5);
	display_vector(stl_vector_count);




	std::cout <<  "\n\nTEST assign()"  << std::endl;
	std_vector_t stl_vector_assign(100, convert<T>("42"));
	stl_vector_assign.assign(10, convert<T>("24"));
	std_vector_t stl_vector_assign2(1, convert<T>("a"));

	stl_vector_assign2.assign(100, convert<T>("b"));
	stl_vector_assign2.assign(stl_vector.begin(), stl_vector.begin() + 2);
	stl_vector_assign2.assign(stl_vector.begin(), stl_vector.end());

	display_vector(stl_vector_assign);
	display_vector(stl_vector_assign2);




	std::cout <<  "\n\nTEST operator []"  << std::endl;
	stl_vector[0] = convert<T>("r");
	std_ref_t stl_ref = stl_vector[0];
	stl_vector[stl_vector.size() - 1] = convert<T>("bla");
	std_ref_t stl_ref2 = stl_vector[stl_vector.size() - 1];
	std_cref_t stl_cref = stl_vector[0];
	std_cref_t stl_cref2 = stl_vector[1] = convert<T>("bli");

	std::cout << "stl_ref = " << stl_ref << std::endl;
	std::cout << "stl_ref2 = " << stl_ref2 << std::endl;
	std::cout << "stl_cref = " << stl_cref << std::endl;
	std::cout << "stl_cref2 = " << stl_cref2 << std::endl;




	std::cout <<  "\n\nTEST operator at()"  << std::endl;
	std_ref_t stl_ref3 = stl_vector.at(0) = convert<T>("m");
	std_ref_t stl_ref4 = stl_vector.at(stl_vector.size() - 1) = convert<T>("bla");
	std_cref_t stl_cref3 = stl_vector.at(0);
	std_cref_t stl_cref4 = stl_vector.at(2) = convert<T>("blibli");

	std::cout << "stl_ref3 = " << stl_ref3 << std::endl;
	std::cout << "stl_ref4 = " << stl_ref4 << std::endl;
	std::cout << "stl_cref3 = " << stl_cref3 << std::endl;
	std::cout << "stl_cref4 = " << stl_cref4 << std::endl;




	std::cout <<  "\n\nTEST front - back"  << std::endl;
	std_ref_t stl_ref5 = stl_vector.front();
	std_ref_t stl_ref6 = stl_vector.front() = convert<T>("front");
	std_cref_t stl_cref5 = stl_vector.front();
	std_cref_t stl_cref6 = stl_vector.front() = convert<T>("cfront");
	std_ref_t stl_ref7 = stl_vector.back();
	std_ref_t stl_ref8 = stl_vector.back() = convert<T>("back");
	std_cref_t stl_cref7 = stl_vector.back();
	std_cref_t stl_cref8 = stl_vector.back() = convert<T>("cback");

	std::cout << "stl_ref5 = " << stl_ref5 << std::endl;
	std::cout << "stl_ref6 = " << stl_ref6 << std::endl;
	std::cout << "stl_cref5 = " << stl_cref5 << std::endl;
	std::cout << "stl_cref6 = " << stl_cref6 << std::endl;
	std::cout << "stl_ref7 = " << stl_ref7 << std::endl;
	std::cout << "stl_ref8 = " << stl_ref8 << std::endl;
	std::cout << "stl_cref7 = " << stl_cref7 << std::endl;
	std::cout << "stl_cref8 = " << stl_cref8 << std::endl;
	


	std::cout <<  "\n\nTEST data"  << std::endl;

	std_ptr_t stl_ptr1 = stl_vector.data();
	std_ptr_t stl_ptr2 = stl_vector.data();
	std_cptr_t stl_cptr1 = stl_vector.data();

	std::cout << "stl_ptr1 = " << *stl_ptr1 << std::endl;
	std::cout << "stl_ptr2 = " << *stl_ptr2 << std::endl;
	std::cout << "stl_cptr1 = " << *stl_cptr1 << std::endl;






	std::cout <<  "\n\nTEST iterator "  << std::endl;

	std_rit_type		stl_rit;
	std_cit_type		stl_cit;
	std_rcit_type		stl_rcit;

	stl_it = stl_vector.begin();
	std::cout << "stl_it = " << *stl_it << std::endl;
	stl_it = stl_vector.end(); stl_it--;
	std::cout << "stl_it = " << *stl_it << std::endl;
	stl_it = stl_vector.begin() + 4;
	std::cout << "stl_it = " << *stl_it << std::endl;
	stl_rit = stl_vector.rbegin();
	std::cout << "stl_rit = " << *stl_rit << std::endl;
	stl_rit = stl_vector.rend(); stl_rit--;
	std::cout << "stl_rit = " << *stl_rit << std::endl;
	stl_rit = stl_vector.rbegin() + 4;	
	std::cout << "stl_rit = " << *stl_rit << std::endl;




	std::cout <<  "\n\nTEST capacity "  << std::endl;

	bool stl_bool;
	size_t stl_size;

	stl_bool = stl_vector.empty();
	std::cout << "stl_bool = " << stl_bool << std::endl;
	std_vector_t stl_vector_empty;
	stl_bool = stl_vector_empty.empty();
	std::cout << "stl_bool = " << stl_bool << std::endl;
	stl_size = stl_vector.size();
	std::cout << "stl_size = " << stl_size << std::endl;
	stl_size = stl_vector_empty.size();
	std::cout << "stl_size = " << stl_size << std::endl;
	stl_size = stl_vector.max_size();
	std::cout << "stl_size = " << stl_size << std::endl;
	stl_vector.reserve(100);





	std::cout <<  "\n\nTEST erase "  << std::endl;

	stl_it = stl_vector2.erase(stl_vector2.begin());
	stl_it = stl_vector2.erase(stl_vector2.begin() + 2);
	stl_it = stl_vector2.erase(stl_vector2.begin() + 2, stl_vector2.begin() + 4);
	display_vector(stl_vector2);
	stl_vector2.insert(stl_vector2.begin(), 1, convert<T>("42"));
	stl_it = stl_vector2.erase(stl_vector2.begin(), stl_vector2.end());
	display_vector(stl_vector2);




	std::cout <<  "\n\nTEST clear "  << std::endl;

	stl_vector.clear();
	display_vector(stl_vector);

	stl_vector2.push_back(convert<T>("10"));
	stl_vector2.pop_back();
	display_vector(stl_vector2);
	stl_vector2.resize(10);
	stl_vector2.resize(15, convert<T>("42"));
	display_vector(stl_vector2);
	stl_vector2.swap(stl_vector);
	display_vector(stl_vector2);



  std::cout <<  "\n\nTEST Relational "  << std::endl;

	std_vector_t 	stl_vector10;
	std_vector_t 	stl_vector11;

	for (int i = 0; i < 10; i++)
	{
		stl_vector10.push_back(convert<T>(tostr(i)));
		stl_vector11.push_back(convert<T>(tostr(i)));
	}

	std::cout << "stl_vector10 == stl_vector11 : " << (stl_vector10 == stl_vector11) << std::endl;
	std::cout << "stl_vector10 != stl_vector11 : " << (stl_vector10 != stl_vector11) << std::endl;
	std::cout << "stl_vector10 < stl_vector11 : " << (stl_vector10 < stl_vector11) << std::endl;
	std::cout << "stl_vector10 <= stl_vector11 : " << (stl_vector10 <= stl_vector11) << std::endl;
	std::cout << "stl_vector10 > stl_vector11 : " << (stl_vector10 > stl_vector11) << std::endl;
	std::cout << "stl_vector10 >= stl_vector11 : " << (stl_vector10 >= stl_vector11) << std::endl;

	stl_vector11.pop_back();

	std::cout << "stl_vector10 == stl_vector11 : " << (stl_vector10 == stl_vector11) << std::endl;
	std::cout << "stl_vector10 != stl_vector11 : " << (stl_vector10 != stl_vector11) << std::endl;
	std::cout << "stl_vector10 < stl_vector11 : " << (stl_vector10 < stl_vector11) << std::endl;
	std::cout << "stl_vector10 <= stl_vector11 : " << (stl_vector10 <= stl_vector11) << std::endl;
	std::cout << "stl_vector10 > stl_vector11 : " << (stl_vector10 > stl_vector11) << std::endl;
	std::cout << "stl_vector10 >= stl_vector11 : " << (stl_vector10 >= stl_vector11) << std::endl;

	stl_vector11.push_back(convert<T>("42"));

	std::cout << "stl_vector10 == stl_vector11 : " << (stl_vector10 == stl_vector11) << std::endl;
	std::cout << "stl_vector10 != stl_vector11 : " << (stl_vector10 != stl_vector11) << std::endl;
	std::cout << "stl_vector10 < stl_vector11 : " << (stl_vector10 < stl_vector11) << std::endl;
	std::cout << "stl_vector10 <= stl_vector11 : " << (stl_vector10 <= stl_vector11) << std::endl;
	std::cout << "stl_vector10 > stl_vector11 : " << (stl_vector10 > stl_vector11) << std::endl;
	std::cout << "stl_vector10 >= stl_vector11 : " << (stl_vector10 >= stl_vector11) << std::endl;






	std::cout <<  "\n\nTEST Relation iterator "  << std::endl;



	stl_it = stl_vector.begin();
	typename std_vector_t::iterator stl_it2 = stl_vector.end();

	std::cout << "stl_it == stl_it2 : " << (stl_it == stl_it2) << std::endl;
	std::cout << "stl_it != stl_it2 : " << (stl_it != stl_it2) << std::endl;
	std::cout << "stl_it < stl_it2 : " << (stl_it < stl_it2) << std::endl;
	std::cout << "stl_it <= stl_it2 : " << (stl_it <= stl_it2) << std::endl;
	std::cout << "stl_it > stl_it2 : " << (stl_it > stl_it2) << std::endl;
	std::cout << "stl_it >= stl_it2 : " << (stl_it >= stl_it2) << std::endl;

	stl_it2--;

	std::cout << "stl_it == stl_it2 : " << (stl_it == stl_it2) << std::endl;
	std::cout << "stl_it != stl_it2 : " << (stl_it != stl_it2) << std::endl;
	std::cout << "stl_it < stl_it2 : " << (stl_it < stl_it2) << std::endl;
	std::cout << "stl_it <= stl_it2 : " << (stl_it <= stl_it2) << std::endl;
	std::cout << "stl_it > stl_it2 : " << (stl_it > stl_it2) << std::endl;
	std::cout << "stl_it >= stl_it2 : " << (stl_it >= stl_it2) << std::endl;

	stl_cit = stl_vector.begin();

	std::cout << "stl_cit == stl_it2 : " << (stl_cit == stl_it2) << std::endl;
	std::cout << "stl_cit != stl_it2 : " << (stl_cit != stl_it2) << std::endl;
	std::cout << "stl_cit < stl_it2 : " << (stl_cit < stl_it2) << std::endl;
	std::cout << "stl_cit <= stl_it2 : " << (stl_cit <= stl_it2) << std::endl;
	std::cout << "stl_cit > stl_it2 : " << (stl_cit > stl_it2) << std::endl;
	std::cout << "stl_cit >= stl_it2 : " << (stl_cit >= stl_it2) << std::endl;

};
