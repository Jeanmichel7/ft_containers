/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:06:29 by jrasser           #+#    #+#             */
/*   Updated: 2022/08/20 03:03:53 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <memory>
#include <cstddef>
#include <iterator>
#include <iostream>



// template < class T, class Alloc = allocator<T> > class vector

namespace ft
{


// Member type	Definition
// value_type				T
// allocator_type			Allocator
// size_type				Unsigned integer type (usually std::size_t)

// reference				value_type&
// const_reference			const value_type&

// pointer					Allocator::pointer
// const_pointer			Allocator::const_pointer	(until C++11)

// iterator					LegacyRandomAccessIterator and LegacyContiguousIterator to value_type
// const_iterator			LegacyRandomAccessIterator and LegacyContiguousIterator to const value_type

// reverse_iterator			std::reverse_iterator<iterator>
// const_reverse_iterator	std::reverse_iterator<const_iterator>


	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{

	public:



		/* Typedef */
		typedef std::size_t									size_type;
		typedef Allocator 									allocator_type;

		typedef T											&reference;
		typedef const T										&const_reference;

		typedef  T*									pointer;
		typedef const  T*							const_pointer;
		

		typedef std::random_access_iterator_tag				iterator;
		typedef std::random_access_iterator_tag const		const_iterator;

		typedef std::reverse_iterator<iterator>				reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const	const_reverse_iterator;


	private:
		pointer _start;
		pointer _finish;
		pointer _end_of_storage;
		unsigned int _nb_elem;



	public:


		/* ******* CONSTRUCTION ******* */
		//https://en.cppreference.com/w/cpp/container/vector/vector
		
		vector() {
			std::cout << "0" << std::endl;

		};
		explicit vector( const Allocator &alloc ) {				//(2)
			std::cout << "1" << std::endl;

		};

		explicit vector( size_type count,						//(3)
						const T &value = T(),
						const Allocator &alloc = Allocator() ) :
						
		_start( alloc.allocate(const_cast<size_type&>(count)) )
		{
			std::cout << "2" << std::endl;


		};

		template <class InputIt>								//(5)
		vector( InputIt first, InputIt last,
		const Allocator &alloc = Allocator() ) {
			std::cout << "3" << std::endl;
		};

		vector( const vector& other ) {							//(6)
			std::cout << "4" << std::endl;
		};

		~vector() {};
		
		vector &operator=( const vector & );



		
		allocator_type get_allocator() const;



		/* ******* ELEMENT ACCESS ******* */
		reference at( size_type pos );
		const_reference at( size_type pos ) const;

		reference operator[]( size_type pos );
		const_reference operator[]( size_type pos ) const;
		
		reference front();
		const_reference front() const;
		
		reference back();
		const_reference back() const;

		T* data();
		const T* data() const;

		void assign( size_type count, const T& value );

		template <class InputIt>
			void assign( InputIt first, InputIt last );



		/* ******* ITERATOR ******* */
		iterator begin();
		const_iterator begin() const;

		iterator end();
		const_iterator end() const;

		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;

		reverse_iterator rend();
		const_reverse_iterator rend() const;



		/* ******* CAPACITY ******* */
		bool empty() const;

		size_type size() const;

		size_type max_size() const;

		void reserve( size_type new_cap );
		
		size_type capacity() const;





		/* ******* MODIFIERS ******* */
		void clear();

		iterator insert( iterator pos, const T& value );
		void insert( iterator pos, size_type count, const T& value );
		template< class InputIt >
			void insert( iterator pos, InputIt first, InputIt last );

		iterator erase( iterator pos );
		iterator erase( iterator first, iterator last );

		void push_back( const T& value );
		
		void pop_back();

		void resize( size_type count, T value = T() );

		void swap( vector& other );





		/* ******* NON MEMBER FUNCTION OVERLOAD ******* */
		// friends autorise
		template <class O, class Alloc>
		bool operator==(const vector<O, Alloc> &rhs);

		template <class O, class Alloc>
		bool operator!=(const vector<O, Alloc> &rhs);

		template <class O, class Alloc>
		bool operator<(const vector<O, Alloc> &rhs);

		template <class O, class Alloc>
		bool operator<=(const vector<O, Alloc> &rhs);

		template <class O, class Alloc>
		bool operator>(const vector<O, Alloc> &rhs);

		template <class O, class Alloc>
		bool operator>=(const vector<O, Alloc> &rhs);

		template <class O, class Alloc>
		void swap(vector<O, Alloc> &lhs,
				  vector<O, Alloc> &rhs);



	};

	// /* ******* CONSTRUCTION ******* */
	// template <typename T, typename Allocator>
	// vector<T, Allocator>::vector()
	// {
	// }

	// template <typename T, typename Allocator>
	// vector<T, Allocator>::~vector()
	// {
	// }





	// //	explicit vector( const Allocator &alloc );				//(2)
	// template <typename T, typename Allocator>
	// vector<T, Allocator>::vector( Allocator const &alloc )
	// {
		
	// }

	
	/* ******* ELEMENT ACCESS ******* */

	/* ******* ITERATOR ******* */

	/* ******* CAPACITY ******* */


	/* ******* MODIFIERS ******* */

	/* ******* NON MEMBER FUNCTION OVERLOAD ******* */

	/* ******* MES TESTs ******* */
	//template <typename T, typename Allocator>
	//T vector<T, Allocator>::getNumber()
	//{
	//	return (_nb);
	//}

}

#endif