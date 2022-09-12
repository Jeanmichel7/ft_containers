/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:14:05 by jrasser           #+#    #+#             */
/*   Updated: 2022/09/12 19:06:57 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __MAP_HPP__
# define __MAP_HPP__

#include "map_iterator.hpp"

// #include <memory>
// #include <cstddef>
// #include <iterator>
#include <iostream>
// #include <limits>

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
	typename Allocator = std::allocator<std::pair<const Key, T> >
>
class map
{

public:

	typedef 	Key 											key_type;
	typedef 	T 												mapped_type;
	typedef 	Compare 										key_compare;
	typedef 	Allocator 										allocator_type;
	typedef 	std::pair<const Key, T> 						value_type;

	typedef 	value_type& 									reference;
	typedef 	const value_type& 								const_reference;

// 	static_assert((is_same<typename allocator_type::value_type, value_type>::value),
//                   "Allocator::value_type must be same type as value_type");

// 	class value_compare : public binary_function<value_type, value_type, bool>
//     {
//         friend class map;
//     protected:
//         key_compare comp;

//         value_compare(key_compare c) : comp(c) {}
//     public:
//         bool operator()(const value_type& __x, const value_type& __y) const
//             {return comp(__x.first, __y.first);}
//     };

// private:
// 	typedef std::__value_type<key_type, mapped_type>						__value_type;
//     typedef __map_value_compare<key_type, __value_type, key_compare> 		__vc;
//     typedef typename __rebind_alloc_helper<allocator_traits<allocator_type>,
//                                                  __value_type>::type 		__allocator_type;
//     typedef __tree<__value_type, __vc, __allocator_type>  					__base;
//     typedef typename __base::__node_traits                					__node_traits;
//     typedef allocator_traits<allocator_type>              					__alloc_traits;

//     __base __tree_;





public:
	typedef 	std::size_t 									size_type;
	typedef 	std::ptrdiff_t								 	difference_type;

	typedef 	typename Allocator::pointer 					pointer;
	typedef 	typename Allocator::const_pointer 				const_pointer;

	// typedef std::LegacyBidirectionalIterator 		iterator;
	// typedef __gnu_cxx::__normal_iterator<const_pointer, vector> const_iterator;
	
	// typedef std::random_access_ifnag							iterator;
	// typedef std::random_access_iterator_tag const			const_iterator;

	// typedef std::reverse_iterator<iterator>					reverse_iterator;
	// typedef std::reverse_iterator<const_iterator> const		const_reverse_iterator;


	typedef ft::__map_iterator<pointer>             			iterator;
    typedef ft::__map_const_iterator<const_pointer> 			const_iterator;

    typedef _VSTD::reverse_iterator<iterator>               	reverse_iterator;
    typedef _VSTD::reverse_iterator<const_iterator>         	const_reverse_iterator;




private:

	allocator_type		_alloc;
	key_compare			_comp;
	size_type			_size;
	pointer				_map;

	



	/*
	FAQ FabLab
	
	Nos projets doivent-ils etre en lien avec les projets de LabHidouille ?
	Non, vous pouvez realiser tout types de projets independant.

	Les projets sont-ils obligatoirement en groupes ?
	Non, vous pouvez realiser vos projets perso. Des projets de groupes seront proposes.

	A t'on un acces libre au FabLab ?
	Il faut etre membre du Club DIY et reserver un creneau sur leur site. 
	Les places dans un groupe sont limites (~5p).
	Details a venir.

	L'utilisation des machines sont-elles gratuites ?
	Oui les machines sont a disposition gratuitment.

	Les machines sont-elles en libre service?
	Apres une courte formation, vous pouvez utiliser les machines en autonomie.

	Les consommables sont-ils gratuit (filament 3D, boisserie, fraise... )?
	42 prend en charge une partie des consommables (filament 3D, etains, liste a definir).
	Le reste est a votre charge.

	Concernant l'electronique ?
	Les systeme embarques type Arduino sont a disposition le temps de votre projet.
	Pour les consommables de types LED, boutons, resistances, etc..., rien n'est encore defini.

	
	*/




public:
	map() : _root(NULL), _size(0)
	{
		std::cout << "Map constructor" << std::endl;

	};
	~map()
	{
		std::cout << "Map destructor" << std::endl;
	};

	explicit map( const Compare& comp,
				  const Allocator& alloc = Allocator() )
	{
		
	};

	template <class InputIt>
	map(InputIt first,
		InputIt last,
		const Compare &comp = Compare(),
		const Allocator &alloc = Allocator())
	{
		
	}

	map( const map& other )
	{
		
	};
};


	
}


#endif