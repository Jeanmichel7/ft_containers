/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_vector.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:05:46 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/26 10:03:19 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

// template< typename T1, typename T2>
// void sstr_comp(T1 it, T2 ft_it, std::string msg) {

// 	std::stringstream sstr;
// 	std::stringstream ft_sstr;

// 	sstr << it->first << " " << it->second;
// 	ft_sstr << ft_it->first << " " << ft_it->second;
// 	str_comp(sstr.str(), ft_sstr.str(), msg);
// 	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
// }



// void str_comp(std::string str, std::string ft_str, std::string msg) {
// 	if (str.compare(ft_str) != 0)
// 	{
// 		std::cout << RED "\n[KO] " END << msg << std::endl;
		
// 		std::cout << "std::map = " << str << std::endl;
// 		std::cout << "ft::map  = " << ft_str << std::endl << std::endl;
// 	}
// 	else {
// 		std::cout << GRN "[OK] " END ;
// 		// std::cout << str << std::endl << ft_str << std::endl << msg << std::endl;
// 	}
// }

template < typename V1, typename V2 >
void	comp_vector( V1 &stl_vector, V2 &ft_vector, std::string msg ) {
	std::stringstream sstr;
	std::stringstream ft_sstr;

	typename V1::iterator stl_it = stl_vector.begin();
	typename V2::iterator ft_it = ft_vector.begin();

	for(; stl_it != stl_vector.end(); stl_it++) {
		sstr << *stl_it << " ";
		// std::cout << " " << *stl_it;
	}
	// std::cout << std::endl;
	for(; ft_it != ft_vector.end(); ft_it++) {
		ft_sstr << *ft_it << " ";
		// std::cout << *ft_it << " ";
	}

	str_comp(sstr.str(), ft_sstr.str(), msg);
	sstr.str(""); sstr.clear(); ft_sstr.str(""); ft_sstr.clear();
}




template < typename V >
void stl_display (std::vector<V> &v) {
	std::cout << "\n------------------- std vector ---------------------" << std::endl;
	std::cout << "nb_elems 	: " << v.size()<< std::endl;
	std::cout << "capacity 	: " << v.capacity() << std::endl;
	std::cout << "content 	: ";
	typename std::vector<V>::iterator it = v.begin();
	for(; it != v.end(); it++) {
		if (it != --v.end())
			std::cout << *it << ", ";
		else
			std::cout << *it;
		// std::cout << *it << ", ";
	}
	std::cout << std::endl
						<< "----------------------------------------\n\n"
						<< std::endl;
}











void tester_vector(void)
{
	display_title("VECTOR < string >");
	tester_vector_type< std::string >();

	display_title("VECTOR < int >");
	tester_vector_type< int >();

	display_title("VECTOR < char >");
	tester_vector_type< char >();

	// display_title("VECTOR < float >");
	// tester_vector_type< float >();
}


template< typename vector_type >
void tester_vector_type()
{
	std::stringstream 	sstr;
	std::stringstream 	ft_sstr;
	std::string 				str;
	std::string 				ft_str;
	struct s_time_diff 	chrono;

	/* define type vector */
	typedef vector_type 						T;

	typedef std::vector< vector_type >										std_vector_t;
	typedef ft::vector< vector_type > 										ft_vector_t;

	/* define type pointer */
	typedef typename std_vector_t::pointer 								std_ptr_t;
	typedef typename std_vector_t::const_pointer 					std_cptr_t;
	
	typedef typename ft_vector_t::pointer 								ft_ptr_t;
	typedef typename ft_vector_t::const_pointer 					ft_cptr_t;

	/* define type reference */
	typedef typename std_vector_t::reference							std_ref_t;
	typedef typename std_vector_t::const_reference				std_cref_t;

	typedef typename ft_vector_t::reference								ft_ref_t;
	typedef typename ft_vector_t::const_reference					ft_cref_t;

	/* define type iterator */
	typedef typename std_vector_t::iterator 							std_it_type;
	typedef typename std_vector_t::const_iterator 				std_cit_type;
	typedef typename std_vector_t::reverse_iterator 			std_rit_type;
	typedef typename std_vector_t::const_reverse_iterator std_rcit_type;

	typedef typename ft_vector_t::iterator 								ft_it_type;
	typedef typename ft_vector_t::const_iterator 					ft_cit_type;
	typedef typename ft_vector_t::reverse_iterator 				ft_rit_type;
	typedef typename ft_vector_t::const_reverse_iterator 	ft_crit_type;






	/* ***************************************************** */
	/*                                                       */
	/*                       CONSTRUCTORS                    */
	/*                                                       */
	/* ***************************************************** */

	std::cout << MAG "\n\nTEST constructor vector() " END << std::endl;

	/* empty */
	chrono.stl_start_chrono();
	std_vector_t stl_vector;
	chrono.stl_end_chrono();
	chrono.ft_start_chrono();
	ft_vector_t ft_vector;
	chrono.ft_end_chrono();

	comp_vector(stl_vector, ft_vector, "empty constructor");
	chrono.diff_chrono();



	// /* construcotr with alloc */
	// chrono.stl_start_chrono();
	// std_vector_t std_vector_alloc(std::allocator< vector_type >());
	// chrono.stl_end_chrono();

	// chrono.ft_start_chrono();
	// ft_vector_t ft_vector_alloc(std::allocator< vector_type >());
	// chrono.ft_end_chrono();

	// chrono.diff_chrono();



	/* constructor with count */
	chrono.stl_start_chrono();
	std_vector_t stl_vector_count(5);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_vector_t ft_vector_count(5);
	chrono.ft_end_chrono();

	comp_vector(stl_vector_count, ft_vector_count, "constructor with count");
	chrono.diff_chrono();









	/* ***************************************************** */
	/*                                                       */
	/*                   Insert( pos, value )                */
	/*                                                       */
	/* ***************************************************** */
	
	std::cout << MAG "\n\nTEST insert(pos, value) " END << std::endl;

	std_it_type stl_it;
	ft_it_type 	ft_it;

	/* insert end 123 */
	chrono.stl_start_chrono();
	stl_it = stl_vector_count.insert( stl_vector_count.end(), convert<T>("123") );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it = ft_vector_count.insert( ft_vector_count.end(), convert<T>("123") );
	chrono.ft_end_chrono();
	
	str_comp(tostr(*stl_it), tostr(*ft_it), "ret insert end 123");
	comp_vector(stl_vector_count, ft_vector_count, "insert end 123");
	chrono.diff_chrono();



	/* insert begin a */
	chrono.stl_start_chrono();
	stl_it = stl_vector.insert( stl_vector.begin(), convert<T>("a") );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it = ft_vector.insert( ft_vector.begin(), convert<T>("a") );
	chrono.ft_end_chrono();


	str_comp(tostr(*stl_it), tostr(*ft_it), "ret insert begin a");
	comp_vector(stl_vector, ft_vector, "insert begin a");
	chrono.diff_chrono();



	/* insert begin b */
	chrono.stl_start_chrono();
	stl_it = stl_vector.insert( stl_vector.begin(), convert<T>("b") );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it = ft_vector.insert( ft_vector.begin(), convert<T>("b") );
	chrono.ft_end_chrono();

	str_comp(tostr(*stl_it), tostr(*ft_it), "ret insert begin b");
	comp_vector(stl_vector, ft_vector, "insert begin b");
	chrono.diff_chrono();



	/* insert end c */
	chrono.stl_start_chrono();
	stl_it = stl_vector.insert( stl_vector.end(), convert<T>("c") );
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it = ft_vector.insert( ft_vector.end(), convert<T>("c") );
	chrono.ft_end_chrono();

	str_comp(tostr(*stl_it), tostr(*ft_it), "ret insert end c");
	comp_vector(stl_vector, ft_vector, "insert end c");
	chrono.diff_chrono();



	/* insert middle d */
	chrono.stl_start_chrono();
	stl_it = stl_vector.insert(stl_vector.begin() + 1, convert<T>("d"));
	chrono.stl_end_chrono();
	
	chrono.ft_start_chrono();
	ft_it = ft_vector.insert(ft_vector.begin() + 1, convert<T>("d"));
	chrono.ft_end_chrono();

	// std::cout << "stl it : " << *stl_it << std::endl;
	// std::cout << "ft it : " << *ft_it << std::endl;

	str_comp(tostr(*stl_it), tostr(*ft_it), "ret insert middle d");
	comp_vector(stl_vector, ft_vector, "insert middle d");
	chrono.diff_chrono();



	/* insert middle e */
	chrono.stl_start_chrono();
	stl_it = stl_vector.insert(stl_vector.begin() + 2, convert<T>("e"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it = ft_vector.insert(ft_vector.begin() + 2, convert<T>("e"));
	chrono.ft_end_chrono();

	str_comp(tostr(*stl_it), tostr(*ft_it), "ret insert middle e");
	comp_vector(stl_vector, ft_vector, "insert middle e");
	chrono.diff_chrono();















	/* ***************************************************** */
	/*                                                       */
	/*                 insert(pos, cout, value)              */
	/*                                                       */
	/* ***************************************************** */
	
	std::cout << MAG "\n\nTEST insert(pos, cout, value) " END << std::endl;

	/* insert( end, 2, "123" */
	chrono.stl_start_chrono();
	stl_vector.insert(stl_vector.end(), 2, convert<T>("123"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_vector.insert(ft_vector.end(), 2, convert<T>("123"));
	chrono.ft_end_chrono();

	comp_vector(stl_vector, ft_vector, "insert end, 2, 123");
	chrono.diff_chrono();



	/* insert( begin, 2, "000" */
	chrono.stl_start_chrono();
	stl_vector.insert(stl_vector.begin(), 2, convert<T>("000"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_vector.insert(ft_vector.begin(), 2, convert<T>("000"));
	chrono.ft_end_chrono();

	comp_vector(stl_vector, ft_vector, "insert begin, 2, 000");
	chrono.diff_chrono();



	/* insert begin + 2, "42" */
	chrono.stl_start_chrono();
	stl_vector.insert(stl_vector.begin() + 2, 2, convert<T>("42"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_vector.insert(ft_vector.begin() + 2, 2, convert<T>("42"));
	chrono.ft_end_chrono();

	comp_vector(stl_vector, ft_vector, "insert begin + 2, 2, 42");
	chrono.diff_chrono();

 


	// stl_display<T>(stl_vector);
	// ft_vector.display("");





	/* ***************************************************** */
	/*                                                       */
	/*                  Constructor first last               */
	/*                                                       */
	/* ***************************************************** */

	std::cout << MAG "\n\nTEST constructor( first, last) " END << std::endl;

	/* constructor( first, last) */
	chrono.stl_start_chrono();
	std::vector<T> stl_vector2(stl_vector.begin(), stl_vector.end());
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft::vector<T> ft_vector2(ft_vector.begin(), ft_vector.end());
	chrono.ft_end_chrono();

	comp_vector(stl_vector2, ft_vector2, "constructor( first, last)");
	chrono.diff_chrono();
	/* check copy */
	stl_vector2[0] = convert<T>("zZz");
	ft_vector2[0] = convert<T>("zZz");
	comp_vector(stl_vector, ft_vector, "constructor( first, last) original");
	comp_vector(stl_vector2, ft_vector2, "constructor( first, last) copy");



	/* constructor (begin + 2, end - 2) */
	chrono.stl_start_chrono();
	std::vector<T> stl_vector3(stl_vector.begin() + 2, stl_vector.end() - 2);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft::vector<T> ft_vector3(ft_vector.begin() + 2, ft_vector.end() - 2);
	chrono.ft_end_chrono();

	comp_vector(stl_vector3, ft_vector3, "constructor( begin + 2, end - 2)");
	chrono.diff_chrono();






	/* ---------------------- */
	/*    constructor copy    */
	/* ---------------------- */

	chrono.stl_start_chrono();
	std::vector<T> stl_vector4(stl_vector);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft::vector<T> ft_vector4(ft_vector);
	chrono.ft_end_chrono();

	comp_vector(stl_vector4, ft_vector4, "constructor copy");
	chrono.diff_chrono();
	/* check copy */
	stl_vector4[0] = convert<T>("zZz");
	ft_vector4[0] = convert<T>("zZz");
	comp_vector(stl_vector, ft_vector, "constructor copy original");
	comp_vector(stl_vector4, ft_vector4, "constructor copy copy");






	/* ---------------------- */
	/*       affectation      */
	/* ---------------------- */

	/* new vector */
	chrono.stl_start_chrono();
	std::vector<T> stl_vector5 = stl_vector;
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft::vector<T> ft_vector5 = ft_vector;
	chrono.ft_end_chrono();

	comp_vector(stl_vector5, ft_vector5, "affectation");
	chrono.diff_chrono();

	/* check copy */
	stl_vector5[0] = convert<T>("zZz123");
	ft_vector5[0] = convert<T>("zZz123");
	comp_vector(stl_vector, ft_vector, "affectation original");
	comp_vector(stl_vector5, ft_vector5, "affectation copy");






	/* old vector */
	chrono.stl_start_chrono();
	stl_vector_count = stl_vector;
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_vector_count = ft_vector;
	chrono.ft_end_chrono();

	comp_vector(stl_vector_count, ft_vector_count, "affectation old vector");
	chrono.diff_chrono();

	/* check copy */
	stl_vector_count[0] = convert<T>("zZzaa123");
	ft_vector_count[0] = convert<T>("zZzaa123");
	comp_vector(stl_vector, ft_vector, "affectation old vector original");
	comp_vector(stl_vector_count, ft_vector_count, "affectation old vector copy");







	/* *************************************************** */
	/*                                                     */
	/*                    ELEMENT ACCESS                   */
	/*                                                     */
	/* *************************************************** */

	std::cout << MAG "\n\nTEST element access" END << std::endl;


	/* ---------------------- */
	/*       operator []      */
	/* ---------------------- */

	/* [0] = r */
	chrono.stl_start_chrono();
	stl_vector[0] = convert<T>("r");
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_vector[0] = convert<T>("r");
	chrono.ft_end_chrono();

	comp_vector(stl_vector, ft_vector, "operator[]");
	chrono.diff_chrono();



	/* [0] */
	chrono.stl_start_chrono();
	std_ref_t stl_ref = stl_vector[0];
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ref_t ft_ref = ft_vector[0];
	chrono.ft_end_chrono();

	str_comp(tostr(stl_ref), tostr(ft_ref), "operator[0]");
	chrono.diff_chrono();



	/* [size - 1] = bla */
	chrono.stl_start_chrono();
	stl_vector[stl_vector.size() - 1] = convert<T>("bla");
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_vector[ft_vector.size() - 1] = convert<T>("bla");
	chrono.ft_end_chrono();

	comp_vector(stl_vector, ft_vector, "operator[]");
	chrono.diff_chrono();



	/* [size - 1] */
	chrono.stl_start_chrono();
	std_ref_t stl_ref2 = stl_vector[stl_vector.size() - 1];
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ref_t ft_ref2 = ft_vector[ft_vector.size() - 1];
	chrono.ft_end_chrono();

	str_comp(tostr(stl_ref2), tostr(ft_ref2), "operator[size - 1]");
	chrono.diff_chrono();



	/* const ref []*/
	chrono.stl_start_chrono();
	std_cref_t stl_cref = stl_vector[0];
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_cref_t ft_cref = ft_vector[0];
	chrono.ft_end_chrono();

	str_comp(tostr(stl_cref), tostr(ft_cref), "operator[0] const ref");
	chrono.diff_chrono();



	/* const ref [1] = "bli" */
	chrono.stl_start_chrono();
	std_cref_t stl_cref2 = stl_vector[1] = convert<T>("bli");
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_cref_t ft_cref2 = ft_vector[1] = convert<T>("bli");
	chrono.ft_end_chrono();

	str_comp(tostr(stl_cref2), tostr(ft_cref2), "operator[1] const ref");
	chrono.diff_chrono();




	/* check overflow */
	// chrono.stl_start_chrono();
	// str = tostr(stl_vector[stl_vector.size()]);
	// chrono.stl_end_chrono();

	// chrono.ft_start_chrono();
	// ft_str = tostr(ft_vector[ft_vector.size()]);
	// chrono.ft_end_chrono();

	// str_comp(str, ft_str, "operator[overflow]");
	// chrono.diff_chrono();




	/* ---------------------- */
	/*           at          */
	/* ---------------------- */

	/* [0] = m */
	chrono.stl_start_chrono();
	std_ref_t stl_ref3 = stl_vector.at(0) = convert<T>("m");
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ref_t ft_ref3 = ft_vector.at(0) = convert<T>("m");
	chrono.ft_end_chrono();

	str_comp(tostr(stl_ref3), tostr(ft_ref3), "at[0]");
	chrono.diff_chrono();



	/* [size - 1] = bla */
	chrono.stl_start_chrono();
	std_ref_t stl_ref4 = stl_vector.at(stl_vector.size() - 1) = convert<T>("bla");
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ref_t ft_ref4 = ft_vector.at(ft_vector.size() - 1) = convert<T>("bla");
	chrono.ft_end_chrono();

	str_comp(tostr(stl_ref4), tostr(ft_ref4), "at[size - 1]");
	chrono.diff_chrono();



	/* const ref [0] */
	chrono.stl_start_chrono();
	std_cref_t stl_cref3 = stl_vector.at(0);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_cref_t ft_cref3 = ft_vector.at(0);
	chrono.ft_end_chrono();

	str_comp(tostr(stl_cref3), tostr(ft_cref3), "at[0] const ref");
	chrono.diff_chrono();



	/* const ref [2] = "blibli" */
	chrono.stl_start_chrono();
	std_cref_t stl_cref4 = stl_vector.at(2) = convert<T>("blibli");
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_cref_t ft_cref4 = ft_vector.at(2) = convert<T>("blibli");
	chrono.ft_end_chrono();

	str_comp(tostr(stl_cref4), tostr(ft_cref4), "at[1] const ref");
	chrono.diff_chrono();







	// stl_display<T>(stl_vector);
	// ft_vector.display("");




	/* ---------------------- */
	/*          front         */
	/* ---------------------- */

	/* front */
	chrono.stl_start_chrono();
	std_ref_t stl_ref5 = stl_vector.front();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ref_t ft_ref5 = ft_vector.front();
	chrono.ft_end_chrono();

	str_comp(tostr(stl_ref5), tostr(ft_ref5), "front");
	chrono.diff_chrono();



	/* front = "front" */
	chrono.stl_start_chrono();
	std_ref_t stl_ref6 = stl_vector.front() = convert<T>("front");
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ref_t ft_ref6 = ft_vector.front() = convert<T>("front");
	chrono.ft_end_chrono();

	str_comp(tostr(stl_ref6), tostr(ft_ref6), "front = front");
	chrono.diff_chrono();



	/* const ref front */
	chrono.stl_start_chrono();
	std_cref_t stl_cref5 = stl_vector.front();
	chrono.stl_end_chrono();
	
	chrono.ft_start_chrono();
	ft_cref_t ft_cref5 = ft_vector.front();
	chrono.ft_end_chrono();

	str_comp(tostr(stl_cref5), tostr(ft_cref5), "front const ref");
	chrono.diff_chrono();



	/* const ref front = "cfront" */
	chrono.stl_start_chrono();
	std_cref_t stl_cref6 = stl_vector.front() = convert<T>("cfront");
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_cref_t ft_cref6 = ft_vector.front() = convert<T>("cfront");
	chrono.ft_end_chrono();

	str_comp(tostr(stl_cref6), tostr(ft_cref6), "front const ref = cfront");
	chrono.diff_chrono();









	/* ---------------------- */
	/*           back         */
	/* ---------------------- */

	/* back */
	chrono.stl_start_chrono();
	std_ref_t stl_ref7 = stl_vector.back();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ref_t ft_ref7 = ft_vector.back();
	chrono.ft_end_chrono();

	str_comp(tostr(stl_ref7), tostr(ft_ref7), "back");
	chrono.diff_chrono();



	/* back = "back" */
	chrono.stl_start_chrono();
	std_ref_t stl_ref8 = stl_vector.back() = convert<T>("back");
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ref_t ft_ref8 = ft_vector.back() = convert<T>("back");
	chrono.ft_end_chrono();

	str_comp(tostr(stl_ref8), tostr(ft_ref8), "back");
	chrono.diff_chrono();



	/* const ref back */
	chrono.stl_start_chrono();
	std_cref_t stl_cref7 = stl_vector.back();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_cref_t ft_cref7 = ft_vector.back();
	chrono.ft_end_chrono();

	str_comp(tostr(stl_cref7), tostr(ft_cref7), "back const ref");
	chrono.diff_chrono();



	/* const ref back = "cback" */
	chrono.stl_start_chrono();
	std_cref_t stl_cref8 = stl_vector.back() = convert<T>("cback");
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_cref_t ft_cref8 = ft_vector.back() = convert<T>("cback");
	chrono.ft_end_chrono();

	str_comp(tostr(stl_cref8), tostr(ft_cref8), "back const ref = cback");
	chrono.diff_chrono();







	/* ---------------------- */
	/*           data         */
	/* ---------------------- */

	/* data */
	chrono.stl_start_chrono();
	std_ptr_t stl_ptr1 = stl_vector.data();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ptr_t ft_ptr1 = ft_vector.data();
	chrono.ft_end_chrono();

	str_comp(tostr(*stl_ptr1), tostr(*ft_ptr1), "data");
	chrono.diff_chrono();



	/* data = "data" */
	chrono.stl_start_chrono();
	std_ptr_t stl_ptr2 = stl_vector.data();
	*stl_ptr2 = convert<T>("data");
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_ptr_t ft_ptr2 = ft_vector.data();
	*ft_ptr2 = convert<T>("data");
	chrono.ft_end_chrono();

	str_comp(tostr(*stl_ptr2), tostr(*ft_ptr2), "data = data");
	chrono.diff_chrono();



	/* const ref data */
	chrono.stl_start_chrono();
	std_cptr_t stl_cptr1 = stl_vector.data();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_cptr_t ft_cptr1 = ft_vector.data();
	chrono.ft_end_chrono();

	str_comp(tostr(*stl_cptr1), tostr(*ft_cptr1), "data const ref");
	chrono.diff_chrono();













	stl_display<T>(stl_vector);
	ft_vector.display("");

	/* ***************************************************** */
	/*                                                       */
	/*                        Iterator                       */
	/*                                                       */
	/* ***************************************************** */

	std::cout << MAG "\n\nTEST iterator " END << std::endl;

	std_rit_type		stl_rit;
	std_cit_type		stl_cit;
	std_rcit_type		stl_rcit;

	ft_rit_type			ft_rit;
	ft_cit_type			ft_cit;
	ft_crit_type		ft_crit;

	/* begin */
	chrono.stl_start_chrono();
	stl_it = stl_vector.begin();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it = ft_vector.begin();
	chrono.ft_end_chrono();

	str_comp(tostr(*stl_it), tostr(*ft_it), "iterator begin");
	chrono.diff_chrono();



	/* end -- */
	chrono.stl_start_chrono();
	stl_it = stl_vector.end(); stl_it--;
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it = ft_vector.end(); ft_it--;
	chrono.ft_end_chrono();

	str_comp(tostr(*stl_it), tostr(*ft_it), "iterator end");
	chrono.diff_chrono();



	/* begin + 4 */
	chrono.stl_start_chrono();
	stl_it = stl_vector.begin() + 4;
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it = ft_vector.begin() + 4;
	chrono.ft_end_chrono();

	str_comp(tostr(*stl_it), tostr(*ft_it), "iterator begin + 4");
	chrono.diff_chrono();


	/* ---------------------------- */
	/*           reverse it         */
	/* ---------------------------- */

	/* rbegin */
	chrono.stl_start_chrono();
	stl_rit = stl_vector.rbegin();
	chrono.stl_end_chrono();
	
	chrono.ft_start_chrono();
	ft_rit = ft_vector.rbegin();
	chrono.ft_end_chrono();

	str_comp(tostr(*stl_rit), tostr(*ft_rit), "iterator rbegin");
	chrono.diff_chrono();



	/* rend -- */
	chrono.stl_start_chrono();
	stl_rit = stl_vector.rend(); stl_rit--;
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_rit = ft_vector.rend(); ft_rit--;
	chrono.ft_end_chrono();

	str_comp(tostr(*stl_rit), tostr(*ft_rit), "iterator rend");
	chrono.diff_chrono();



	/* rbegin + 4 */
	chrono.stl_start_chrono();
	stl_rit = stl_vector.rbegin() + 4;
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_rit = ft_vector.rbegin() + 4;
	chrono.ft_end_chrono();

	str_comp(tostr(*stl_rit), tostr(*ft_rit), "iterator rbegin + 4");
	chrono.diff_chrono();




	/* ---------------------------- */
	/*           const it           */
	/* ---------------------------- */

	/* cbegin */
	// chrono.stl_start_chrono();
	// stl_cit = stl_vector.begin();
	// chrono.stl_end_chrono();

	// chrono.ft_start_chrono();
	// ft_cit = ft_vector.begin();
	// chrono.ft_end_chrono();

	// str_comp(tostr(*stl_cit), tostr(*ft_cit), "iterator cbegin");
	// chrono.diff_chrono();

















	/* ***************************************************** */
	/*                                                       */
	/*                        push_back                      */
	/*                                                       */
	/* ***************************************************** */
	std::cout << MAG "\n\nTEST push_back() " END << std::endl;


	chrono.stl_start_chrono();
	stl_vector.push_back(convert<T>("10"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_vector.push_back(convert<T>("10"));
	chrono.ft_end_chrono();

	comp_vector(stl_vector, ft_vector, "insert 10");
	chrono.diff_chrono();





/* 
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
*/



}
