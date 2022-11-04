/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_vector.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:05:46 by jrasser           #+#    #+#             */
/*   Updated: 2022/11/04 16:22:42 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

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

	if (stl_vector.size() != ft_vector.size())
	{
		std::cout << RED "\n[KO] " END << msg << std::endl;
		
		std::cout << "std::vector size = " << stl_vector.size() << std::endl;
		std::cout << "ft::vector  size = " << ft_vector.size() << std::endl << std::endl;
	}
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

	display_title("VECTOR < float >");
	tester_vector_type< float >();
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





	/* constructor with count */
	std_vector_t stl_vector_count(5);
	ft_vector_t ft_vector_count(5);

	comp_vector(stl_vector_count, ft_vector_count, "constructor with count");









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


	/* insert end*/
	stl_vector.insert(stl_vector.end(), convert<T>("ff"));
	ft_vector.insert(ft_vector.end(), convert<T>("ff"));
	stl_vector.insert(stl_vector.end(), convert<T>("fff"));
	ft_vector.insert(ft_vector.end(), convert<T>("fff"));

	comp_vector(stl_vector, ft_vector, "insert end");




	std::cout << MAG "\n\nTEST constructor copy" END << std::endl;

	/* constructor copy */
	chrono.stl_start_chrono();
	std_vector_t stl_vector_copy(stl_vector);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_vector_t ft_vector_copy(ft_vector);
	chrono.ft_end_chrono();

	comp_vector(stl_vector_copy, ft_vector_copy, "constructor copy");
	chrono.diff_chrono();

	str_comp(tostr(stl_vector_copy.size()), tostr(ft_vector_copy.size()), "size copy");



	/* add values */

	stl_vector_copy.insert(stl_vector_copy.begin(), convert<T>("a"));
	stl_vector_copy.insert(stl_vector_copy.begin(), convert<T>("b"));

	ft_vector_copy.insert(ft_vector_copy.begin(), convert<T>("a"));
	ft_vector_copy.insert(ft_vector_copy.begin(), convert<T>("b"));

	comp_vector(stl_vector_copy, ft_vector_copy, "constructor copy + insert");


	stl_vector_copy.push_back(convert<T>("f"));
	ft_vector_copy.push_back(convert<T>("f"));

	comp_vector(stl_vector_copy, ft_vector_copy, "add values");










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




	

	/* insert end 4, 124 */
	// chrono.stl_start_chrono();
	// stl_vector.insert(stl_vector.end(), 4, convert<T>("124"));
	// chrono.stl_end_chrono();

	// chrono.ft_start_chrono();
	// ft_vector.insert(ft_vector.end(), 4, convert<T>("124"));
	// chrono.ft_end_chrono();

	// comp_vector(stl_vector, ft_vector, "insert end, 4, 124");
	// chrono.diff_chrono();
 





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




	// stl_display<T>(stl_vector);
	// ft_vector.display("");


	/* *************************************************** */
	/*                                                     */
	/*                    ELEMENT ACCESS                   */
	/*                                                     */
	/* *************************************************** */
	std::cout << MAG "\n\nTEST assign()" END << std::endl;


	std_vector_t stl_vector_assign(100, convert<T>("42"));
	ft_vector_t 	ft_vector_assign(100, convert<T>("42"));


	// stl_display<T>(stl_vector_assign);
	// ft_vector_assign.display("");

	/* assign(10, "24") */
	chrono.stl_start_chrono();
	stl_vector_assign.assign(10, convert<T>("24"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_vector_assign.assign(10, convert<T>("24"));
	chrono.ft_end_chrono();

	comp_vector(stl_vector_assign, ft_vector_assign, "assign(10, \"24\")");
	chrono.diff_chrono();


	// stl_display<T>(stl_vector_assign);
	// ft_vector_assign.display("");




	std_vector_t stl_vector_assign2(1, convert<T>("a"));
	ft_vector_t 	ft_vector_assign2(1, convert<T>("a"));

	/* assign 100, "b" */
	chrono.stl_start_chrono();
	stl_vector_assign2.assign(100, convert<T>("b"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_vector_assign2.assign(100, convert<T>("b"));
	chrono.ft_end_chrono();

	comp_vector(stl_vector_assign2, ft_vector_assign2, "assign(100, \"b\")");
	chrono.diff_chrono();





	/* assign begin, begin + 2 */
	chrono.stl_start_chrono();
	stl_vector_assign2.assign(stl_vector.begin(), stl_vector.begin() + 2);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_vector_assign2.assign(ft_vector.begin(), ft_vector.begin() + 2);
	chrono.ft_end_chrono();

	comp_vector(stl_vector_assign2, ft_vector_assign2, "assign(begin, begin + 2)");
	chrono.diff_chrono();



	/* assign begin end */
	chrono.stl_start_chrono();
	stl_vector_assign2.assign(stl_vector.begin(), stl_vector.end());
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_vector_assign2.assign(ft_vector.begin(), ft_vector.end());
	chrono.ft_end_chrono();

	comp_vector(stl_vector_assign2, ft_vector_assign2, "assign(begin, end)");
	chrono.diff_chrono();







	std::cout << MAG "\n\nTEST operator []" END << std::endl;


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



	std::cout << MAG "\n\nTEST operator at()" END << std::endl;

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
	std::cout << MAG "\n\nTEST front - back" END << std::endl;

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
	std::cout << MAG "\n\nTEST data" END << std::endl;


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









	// ft::vector<int> test_const;
	// test_const.push_back(1);
	// test_const.push_back(2);
	// test_const.push_back(3);

	// test_const.display("test_const");
	// ft::vector<int>::const_iterator it_const  = test_const.begin();
	// std::cout << "const it : " << *it_const << std::endl;
	// std::cout << "const it : " << *(it_const + 1) << std::endl;
	// it_const++;
	// std::cout << "const it : " << *(it_const) << std::endl;








	/* *************************************************** */
	/*                                                     */
	/*                       CAPACITY                      */
	/*                                                     */
	/* *************************************************** */

	std::cout << MAG "\n\nTEST capacity " END << std::endl;

	bool stl_bool;
	bool ft_bool;
	size_t stl_size;
	size_t ft_size;
	




	/* ---------------------------- */
	/*            empty             */
	/* ---------------------------- */

	/* not empty */
	chrono.stl_start_chrono();
	stl_bool = stl_vector.empty();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_bool = ft_vector.empty();
	chrono.ft_end_chrono();
	// std::cout << "stl empty : " << stl_bool << std::endl;
	// std::cout << "ft empty : " << ft_bool << std::endl;

	str_comp(tostr(stl_bool), tostr(ft_bool), "not empty");
	chrono.diff_chrono();






	std::vector<T> stl_vector_empty;
	ft::vector<T>  ft_vector_empty;


	/* empty */
	chrono.stl_start_chrono();
	stl_bool = stl_vector_empty.empty();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_bool = ft_vector_empty.empty();
	chrono.ft_end_chrono();
	// std::cout << "stl empty : " << stl_bool << std::endl;
	// std::cout << "ft empty : " << ft_bool << std::endl;

	str_comp(tostr(stl_bool), tostr(ft_bool), "empty");
	chrono.diff_chrono();







	/* ---------------------------- */
	/*             size             */
	/* ---------------------------- */

	/* size vector*/
	chrono.stl_start_chrono();
	stl_size = stl_vector.size();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_size = ft_vector.size();
	chrono.ft_end_chrono();

	str_comp(tostr(stl_size), tostr(ft_size), "size");
	chrono.diff_chrono();



	/* size vector_empty */
	chrono.stl_start_chrono();
	stl_size = stl_vector_empty.size();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_size = ft_vector_empty.size();
	chrono.ft_end_chrono();

	str_comp(tostr(stl_size), tostr(ft_size), "size empty");
	chrono.diff_chrono();





	/* ---------------------------- */
	/*           max size           */
	/* ---------------------------- */

	/* max size */
	chrono.stl_start_chrono();
	stl_size = stl_vector.max_size();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_size = ft_vector.max_size();
	chrono.ft_end_chrono();

	str_comp(tostr(stl_size), tostr(ft_size), "max size");
	chrono.diff_chrono();




	/* ---------------------------- */
	/*           capacity           */
	/* ---------------------------- */	

	/* capacity */
	// chrono.stl_start_chrono();
	// stl_size = stl_vector.capacity();
	// chrono.stl_end_chrono();

	// chrono.ft_start_chrono();
	// ft_size = ft_vector.capacity();
	// chrono.ft_end_chrono();

	// str_comp(tostr(stl_size), tostr(ft_size), "capacity");
	// chrono.diff_chrono();


	
	// chrono.stl_start_chrono();
	// stl_size = stl_vector_empty.capacity();
	// chrono.stl_end_chrono();

	// chrono.ft_start_chrono();
	// ft_size = ft_vector_empty.capacity();
	// chrono.ft_end_chrono();

	// str_comp(tostr(stl_size), tostr(ft_size), "capacity empty");
	// chrono.diff_chrono();





	/* ---------------------------- */
	/*           reserve            */
	/* ---------------------------- */	

	/* reserve */
	chrono.stl_start_chrono();
	stl_vector.reserve(100);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_vector.reserve(100);
	chrono.ft_end_chrono();

	str_comp(tostr(stl_vector.capacity()), tostr(ft_vector.capacity()), "reserve");
	chrono.diff_chrono();




	




	/* ---------------------------- */
	/*             erase            */
	/* ---------------------------- */
	std::cout << MAG "\n\nTEST erase " END << std::endl;

	/* erase begin */
	chrono.stl_start_chrono();
	stl_it = stl_vector2.erase(stl_vector2.begin());
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it = ft_vector2.erase(ft_vector2.begin());
	chrono.ft_end_chrono();

	str_comp(tostr(*stl_it), tostr(*ft_it), "ret erase begin");
	comp_vector(stl_vector2, ft_vector2, "erase begin");
	chrono.diff_chrono();




	/* erase end - 1*/
	// chrono.stl_start_chrono();
	// stl_it = stl_vector2.erase(stl_vector2.end());
	// chrono.stl_end_chrono();

	// chrono.ft_start_chrono();
	// ft_it = ft_vector2.erase(ft_vector2.end());
	// chrono.ft_end_chrono();

	// str_comp(tostr(*stl_it), tostr(*ft_it), "ret erase end");
	// comp_vector(stl_vector2, ft_vector2, "erase end");
	// chrono.diff_chrono();




	/* erase middle */
	chrono.stl_start_chrono();
	stl_it = stl_vector2.erase(stl_vector2.begin() + 2);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it = ft_vector2.erase(ft_vector2.begin() + 2);
	chrono.ft_end_chrono();

	str_comp(tostr(*stl_it), tostr(*ft_it), "ret erase begin + 2");
	comp_vector(stl_vector2, ft_vector2, "erase begin + 2");
	chrono.diff_chrono();











	/* erase range b+2 b+2*/
	// chrono.stl_start_chrono();
	// stl_it = stl_vector2.erase(stl_vector2.begin() + 2, stl_vector2.begin() + 2);
	// chrono.stl_end_chrono();

	// chrono.ft_start_chrono();
	// ft_it = ft_vector2.erase(ft_vector2.begin() + 2, ft_vector2.begin() + 2);
	// chrono.ft_end_chrono();

	// str_comp(tostr(*stl_it), tostr(*ft_it), "ret erase range b+2 b+2");
	// comp_vector(stl_vector2, ft_vector2, "erase range b+2 b+2");
	// chrono.diff_chrono();






	/* erase range b+2 b+4*/
	chrono.stl_start_chrono();
	stl_it = stl_vector2.erase(stl_vector2.begin() + 2, stl_vector2.begin() + 4);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it = ft_vector2.erase(ft_vector2.begin() + 2, ft_vector2.begin() + 4);
	chrono.ft_end_chrono();

	str_comp(tostr(*stl_it), tostr(*ft_it), "ret erase range b+2 b+4");
	comp_vector(stl_vector2, ft_vector2, "erase range b+2 b+4");
	chrono.diff_chrono();







	stl_vector2.insert(stl_vector2.begin(), 1, convert<T>("42"));
	ft_vector2.insert(ft_vector2.begin(), 1, convert<T>("42"));


	// stl_display<T>(stl_vector2);
	// ft_vector2.display("");


	/* erase first last */
	chrono.stl_start_chrono();
	stl_it = stl_vector2.erase(stl_vector2.begin(), stl_vector2.end());
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_it = ft_vector2.erase(
		ft_vector2.begin(), 
		ft_vector2.end());
	chrono.ft_end_chrono();

	str_comp(tostr(*stl_it), tostr(*ft_it), "ret erase first last");
	comp_vector(stl_vector2, ft_vector2, "erase first last");
	chrono.diff_chrono();




	// stl_display<T>(stl_vector2);
	// ft_vector2.display("");









	/* *************************************************** */
	/*                                                     */
	/*                       MODIFIERS                     */
	/*                                                     */
	/* *************************************************** */
	std::cout << MAG "\n\nTEST clear " END << std::endl;

	/* ---------------------------- */
	/*             clear            */
	/* ---------------------------- */

	chrono.stl_start_chrono();
	stl_vector.clear();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_vector.clear();
	chrono.ft_end_chrono();

	str_comp(tostr(stl_vector.size()), tostr(ft_vector.size()), "clear");
	chrono.diff_chrono();



	// stl_display<T>(stl_vector2);
	// ft_vector2.display("ft_vector2");


	/* ---------------------------- */
	/*             pushback         */
	/* ---------------------------- */
	chrono.stl_start_chrono();
	stl_vector2.push_back(convert<T>("10"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_vector2.push_back(convert<T>("10"));
	chrono.ft_end_chrono();

	comp_vector(stl_vector2, ft_vector2, "insert 10");
	chrono.diff_chrono();



// stl_display<T>(stl_vector2);
// 	ft_vector2.display("ft_vector2");



	/* ---------------------------- */
	/*             popback          */
	/* ---------------------------- */

	chrono.stl_start_chrono();
	stl_vector2.pop_back();
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_vector2.pop_back();
	chrono.ft_end_chrono();

	comp_vector(stl_vector2, ft_vector2, "pop_back");
	chrono.diff_chrono();


	// stl_display<T>(stl_vector2);
	// ft_vector2.display("ft_vector2");






	/* ---------------------------- */
	/*             resize           */
	/* ---------------------------- */

	/* resize 10 */
	chrono.stl_start_chrono();
	stl_vector2.resize(10);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_vector2.resize(10);
	chrono.ft_end_chrono();

	comp_vector(stl_vector2, ft_vector2, "resize");
	chrono.diff_chrono();



	// stl_display<T>(stl_vector2);
	// ft_vector2.display("ft_vector2");





	/* resize 10, "42" */
	chrono.stl_start_chrono();
	stl_vector2.resize(15, convert<T>("42"));
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_vector2.resize(15, convert<T>("42"));
	chrono.ft_end_chrono();

	comp_vector(stl_vector2, ft_vector2, "resize");
	chrono.diff_chrono();






	// stl_display<T>(stl_vector);
	// ft_vector.display("ft_vector");
	// stl_display<T>(stl_vector2);
	// ft_vector2.display("ft_vector2");


	/* ---------------------------- */
	/*             swap            */
	/* ---------------------------- */

	/* swap */
	chrono.stl_start_chrono();
	stl_vector2.swap(stl_vector);
	chrono.stl_end_chrono();

	chrono.ft_start_chrono();
	ft_vector2.swap(ft_vector);
	chrono.ft_end_chrono();

	comp_vector(stl_vector, ft_vector, "swap");
	comp_vector(stl_vector2, ft_vector2, "swap");

	chrono.diff_chrono();







  /* *************************************************** */
  /*                     RELATIONAL                      */
  /* *************************************************** */
  std::cout << MAG "\n\nTEST Relational " END << std::endl;

	std_vector_t 	stl_vector10;
	ft_vector_t 	ft_vector10;

	std_vector_t 	stl_vector11;
	ft_vector_t 	ft_vector11;

	/* insert 10 values */
	for (int i = 0; i < 10; i++)
	{
		stl_vector10.push_back(convert<T>(tostr(i)));
		ft_vector10.push_back(convert<T> (tostr(i)));
		stl_vector11.push_back(convert<T>(tostr(i)));
		ft_vector11.push_back(convert<T> (tostr(i)));
	}

	str_comp(tostr(stl_vector10 == stl_vector11), tostr(ft_vector10 == ft_vector11), "==");
	str_comp(tostr(stl_vector10 != stl_vector11), tostr(ft_vector10 != ft_vector11), "!=");
	str_comp(tostr(stl_vector10 < stl_vector11), tostr(ft_vector10 < ft_vector11), "<");
	str_comp(tostr(stl_vector10 <= stl_vector11), tostr(ft_vector10 <= ft_vector11), "<=");
	str_comp(tostr(stl_vector10 > stl_vector11), tostr(ft_vector10 > ft_vector11), ">");
	str_comp(tostr(stl_vector10 >= stl_vector11), tostr(ft_vector10 >= ft_vector11), ">=");

	stl_vector11.pop_back();
	ft_vector11.pop_back();

	str_comp(tostr(stl_vector10 == stl_vector11), tostr(ft_vector10 == ft_vector11), "==");
	str_comp(tostr(stl_vector10 != stl_vector11), tostr(ft_vector10 != ft_vector11), "!=");
	str_comp(tostr(stl_vector10 < stl_vector11), tostr(ft_vector10 < ft_vector11), "<");
	str_comp(tostr(stl_vector10 <= stl_vector11), tostr(ft_vector10 <= ft_vector11), "<=");
	str_comp(tostr(stl_vector10 > stl_vector11), tostr(ft_vector10 > ft_vector11), ">");
	str_comp(tostr(stl_vector10 >= stl_vector11), tostr(ft_vector10 >= ft_vector11), ">=");

	stl_vector11.push_back(convert<T>("42"));
	ft_vector11.push_back(convert<T>("42"));

	str_comp(tostr(stl_vector10 == stl_vector11), tostr(ft_vector10 == ft_vector11), "==");
	str_comp(tostr(stl_vector10 != stl_vector11), tostr(ft_vector10 != ft_vector11), "!=");
	str_comp(tostr(stl_vector10 < stl_vector11), tostr(ft_vector10 < ft_vector11), "<");
	str_comp(tostr(stl_vector10 <= stl_vector11), tostr(ft_vector10 <= ft_vector11), "<=");
	str_comp(tostr(stl_vector10 > stl_vector11), tostr(ft_vector10 > ft_vector11), ">");
	str_comp(tostr(stl_vector10 >= stl_vector11), tostr(ft_vector10 >= ft_vector11), ">=");





	std::cout << MAG "\n\nTEST Relation iterator " END << std::endl;


	/* iterator */
	stl_it = stl_vector.begin();
	ft_it = ft_vector.begin();

	typename std_vector_t::iterator stl_it2 = stl_vector.end();
	typename ft_vector_t::iterator ft_it2 = ft_vector.end();

	str_comp(tostr(stl_it == stl_it2), tostr(ft_it == ft_it2), "==");
	str_comp(tostr(stl_it != stl_it2), tostr(ft_it != ft_it2), "!=");
	str_comp(tostr(stl_it < stl_it2), tostr(ft_it < ft_it2), "<");
	str_comp(tostr(stl_it <= stl_it2), tostr(ft_it <= ft_it2), "<=");
	str_comp(tostr(stl_it > stl_it2), tostr(ft_it > ft_it2), ">");
	str_comp(tostr(stl_it >= stl_it2), tostr(ft_it >= ft_it2), ">=");

	stl_it2--;
	ft_it2--;

	str_comp(tostr(stl_it == stl_it2), tostr(ft_it == ft_it2), "==");
	str_comp(tostr(stl_it != stl_it2), tostr(ft_it != ft_it2), "!=");
	str_comp(tostr(stl_it < stl_it2), tostr(ft_it < ft_it2), "<");
	str_comp(tostr(stl_it <= stl_it2), tostr(ft_it <= ft_it2), "<=");
	str_comp(tostr(stl_it > stl_it2), tostr(ft_it > ft_it2), ">");
	str_comp(tostr(stl_it >= stl_it2), tostr(ft_it >= ft_it2), ">=");



	/* comp iterator et const_iterator */
	stl_cit = stl_vector.begin();
	ft_cit = ft_vector.begin();

	str_comp(tostr(stl_it == stl_cit), tostr(ft_it == ft_cit), "==");
	str_comp(tostr(stl_it != stl_cit), tostr(ft_it != ft_cit), "!=");
	str_comp(tostr(stl_it < stl_cit), tostr(ft_it < ft_cit), "<");
	str_comp(tostr(stl_it <= stl_cit), tostr(ft_it <= ft_cit), "<=");
	str_comp(tostr(stl_it > stl_cit), tostr(ft_it > ft_cit), ">");
	str_comp(tostr(stl_it >= stl_cit), tostr(ft_it >= ft_cit), ">=");

	str_comp(tostr(stl_cit == stl_it), tostr(ft_cit == ft_it), "==");
	str_comp(tostr(stl_cit != stl_it), tostr(ft_cit != ft_it), "!=");
	str_comp(tostr(stl_cit < stl_it), tostr(ft_cit < ft_it), "<");
	str_comp(tostr(stl_cit <= stl_it), tostr(ft_cit <= ft_it), "<=");
	str_comp(tostr(stl_cit > stl_it), tostr(ft_cit > ft_it), ">");
	str_comp(tostr(stl_cit >= stl_it), tostr(ft_cit >= ft_it), ">=");



/* AVERAGE TIME */
	chrono.display_average();

}
