/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:14:05 by jrasser           #+#    #+#             */
/*   Updated: 2022/08/30 20:52:49 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_HPP__
# define __MAP_HPP__

//#include <memory>
//#include <cstddef>
#include <iterator>
//#include <iostream>
//#include <limits>

namespace ft
{

/*
Member type					Definition
key_type					Key
mapped_type					T
value_type					std::pair<const Key, T>

size_type					Unsigned integer type (usually std::size_t)
difference_type				Signed integer type (usually std::ptrdiff_t)
key_compare					Compare
allocator_type				Allocator
reference					value_type&
const_reference	const 		value_type&

pointer	 					Allocator::pointer
 
const_pointer	  			Allocator::const_pointer
 
iterator					LegacyBidirectionalIterator to value_type
const_iterator				LegacyBidirectionalIterator to const value_type

reverse_iterator			std::reverse_iterator<iterator>
const_reverse_iterator		std::reverse_iterator<const_iterator>
*/

template <
	typename Key,
	typename T,
	typename Compare = std::less<Key>,
	typename _Alloc = std::allocator<std::pair<const Key, T> >
>
class map
{

public:
	typedef 	Key 							key_type;
	typedef 	T 								mapped_type;
	typedef 	std::pair<const Key, T> 		value_type;
	//typedef 	std::size_t 					size_type;
	//typedef 	std::ptrdiff_t					difference_type;

	typedef 	Compare 						key_compare;
	typedef 	_Alloc							allocator_type;


private:
	typedef typename __gnu_cxx::__alloc_traits<_Alloc>::template
		rebind<value_type>::other _Pair_alloc_type;

	typedef _Rb_tree<key_type, value_type, _Select1st<value_type>, key_compare, _Pair_alloc_type> _Rep_type;
	
	//_Rep_type _M_t;
	
	typedef __gnu_cxx::__alloc_traits<_Pair_alloc_type> _Alloc_traits;

	//Compare _comp;



public:
	/* Typedef */
	typedef typename _Alloc_traits::pointer		 		pointer;
    typedef typename _Alloc_traits::const_pointer		const_pointer;
    typedef typename _Alloc_traits::reference			reference;
    typedef typename _Alloc_traits::const_reference		const_reference;
    typedef typename _Rep_type::iterator				iterator;
    typedef typename _Rep_type::const_iterator			const_iterator;
    typedef typename _Rep_type::size_type				size_type;
    typedef typename _Rep_type::difference_type			difference_type;
    typedef typename _Rep_type::reverse_iterator		reverse_iterator;
    typedef typename _Rep_type::const_reverse_iterator 	const_reverse_iterator;

/*
	typedef 	Key 											key_type;
	typedef 	T 												mapped_type;
	typedef 	std::pair<const Key, T> 						value_type;
	typedef 	std::size_t 									size_type;
	typedef 	std::ptrdiff_t								 	difference_type;

	typedef 	Compare 										key_compare;
	typedef 	Allocator 										allocator_type;

	typedef 	value_type& 									reference;
	typedef 	const value_type& 								const_reference;

	typedef 	typename Allocator::pointer 					pointer;
	typedef 	typename Allocator::const_pointer 				const_pointer;

	typedef __gnu_cxx::__normal_iterator<pointer, vector> 		iterator;
	typedef __gnu_cxx::__normal_iterator<const_pointer, vector> const_iterator;
	
	// typedef std::random_access_ifnag							iterator;
	// typedef std::random_access_iterator_tag const			const_iterator;

	typedef std::reverse_iterator<iterator>						reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const			const_reverse_iterator;
*/



public:
	map() {
		std::cout << "Map constructor" << std::endl;
	};
	~map() {
		std::cout << "Map destructor" << std::endl;
	};

	explicit map(const key_compare &comp = key_compare(),
				 const allocator_type &alloc = allocator_type());

	template <class InputIterator>
	map(InputIterator first, InputIterator last,
		const key_compare &comp = key_compare(),
		const allocator_type &alloc = allocator_type());

	map(const map &x);
};


	
}


#endif