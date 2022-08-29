/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:06:29 by jrasser           #+#    #+#             */
/*   Updated: 2022/08/29 18:51:26 by jrasser          ###   ########.fr       */
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

		//typedef __gnu_cxx::__alloc_traits<_Tp_alloc_type> _Alloc_traits;

	public:
		/* Typedef */
		typedef std::size_t								size_type;
		typedef Allocator 								allocator_type;

		typedef T										&reference;
		typedef const T									&const_reference;

		typedef  T*										pointer;
		typedef const  T*								const_pointer;

		typedef __gnu_cxx::__normal_iterator<pointer, vector> 		iterator;
		typedef __gnu_cxx::__normal_iterator<const_pointer, vector> const_iterator;
		
		// typedef std::random_access_iterator_tag				iterator;
		// typedef std::random_access_iterator_tag const		const_iterator;

		typedef std::reverse_iterator<iterator>				reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const	const_reverse_iterator;


	private:
		Allocator		_alloc;
		pointer			_start;
		pointer			_finish;
		pointer			_end_of_storage;
		
		size_type		_nb_elems;
		size_type		_capacity;



	public:

		/* TEST */
		pointer getElem() {
			return (_start);
		}

		/* ******* CONSTRUCTION ******* */
		
		vector() :
			_start(NULL), _finish(NULL),
			_end_of_storage(NULL),
			_nb_elems(0),
			_capacity(0)
			{
				std::cout << "Constructor" << std::endl;
			};

		explicit vector( const Allocator &alloc ) :
			_alloc(alloc),
			_start(_alloc.allocate(0)),
			_finish(_start),
			_end_of_storage(_start),
			_nb_elems(0),
			_capacity(0)
			{
				std::cout << "Constructor with allocator" << std::endl;
			};

		explicit vector( size_type count,						//(3)
						const T &value = T(),
						const Allocator &alloc = Allocator() ) :
			_alloc(alloc),
			_start(_alloc.allocate(count)),
			_finish(_start + count),
			_end_of_storage(_start + count),
			_nb_elems(count),
			_capacity(count)
			{
				std::cout << "Constructor with count" << std::endl;
	
				//std::uninitialized_fill_n(_start, count, value);
				for(size_type i = 0; i < count; i++) {
					_alloc.construct(_start + i, value);
					_nb_elems = i + 1;
				}
			};

		template <class InputIt>								//(5)
			vector( InputIt first, InputIt last,
				const Allocator &alloc = Allocator() ) :
			_alloc(alloc),
			_start(_alloc.allocate(first)),
			_finish(_start + first),
			_end_of_storage(_start + first),
			_nb_elems(first),
			_capacity(first)
			{
				std::cout << "Constructor with InputIt" << std::endl;

				//std::uninitialized_copy(first, last, _start);
				for(InputIt i = 0; i < first; i++) {
					_alloc.construct(_start + i, last);
					_nb_elems++;
				}
			};

		vector( const vector& other ) :							//(6)
			_alloc(Allocator()),
			_start(_alloc.allocate(other._nb_elems)),
			_finish(_start + other._nb_elems),
			_end_of_storage(_start + other._nb_elems),
			_nb_elems(other._nb_elems),
			_capacity(other._capacity)
			{
				std::cout << "Copy constructor" << std::endl;

				//std::uninitialized_copy(other._start, other._finish, _start);
				for(size_type i = 0; i < other._nb_elems; i++) {
					_alloc.construct(_start + i, other._start[i]);
				}
			};


		vector &operator=( const vector &other ) {
			std::cout << "Assignment operator" << std::endl;
			
			//del
			for(size_type i = 0; i < _nb_elems; i++) {
				_alloc.destroy(_start + i);
			}
			_alloc.deallocate(_start, _capacity);

			//affec
			_start = _alloc.allocate(other._nb_elems);
			_finish = _start + other._nb_elems;
			_end_of_storage = _start + other._nb_elems;
			_nb_elems = other._nb_elems;
			_capacity = other._capacity;
			for(size_type i = 0; i < other._nb_elems; i++) {
				_alloc.construct(_start + i, other._start[i]);
			}

			return *this;
		};

		~vector() {
			std::cout << "Destructor" << std::endl;
			for(size_type i = 0; i < _nb_elems; i++) {
				_alloc.destroy(_start + i);
			}
			_alloc.deallocate(_start, _capacity);
		};


		
		allocator_type get_allocator() const { return _alloc; };



		/* ******* ELEMENT ACCESS ******* */
		reference at( size_type pos )
		{
			//std::cout << "at" << std::endl;
			try {
				if(pos >= _nb_elems)
					throw std::out_of_range("out of range");
				return _start[pos];
			}
			catch(const std::exception& e) {
				std::cerr << e.what() << "'\n";
				std::terminate();
			}
		};
		const_reference at( size_type pos ) const {
			//std::cout << "const_reference at" << std::endl;
			return const_cast<vector*>(this)->at(pos);
		};

		reference operator[]( size_type pos ) {
			//std::cout << "operator[]" << std::endl;
			return _start[pos];
		};
		const_reference operator[]( size_type pos ) const {											//c'est utilise quand ?
			//std::cout << "const_reference operator[]" << std::endl;
			return const_cast<vector*>(this)->operator[](pos);
		};
		reference front() {
			//std::cout << "front" << std::endl;
			return _start[0];
		};
		const_reference front() const {
			//std::cout << "const_reference front" << std::endl;
			return const_cast<vector*>(this)->front();
		};
		reference back() {
			//std::cout << "back" << std::endl;
			return _start[_nb_elems - 1];
		};
		const_reference back() const {
			//std::cout << "const_reference back" << std::endl;
			return const_cast<vector*>(this)->back();
		};

		T* data(){
			//std::cout << "data" << std::endl;
			return _start;
		};
		const T* data() const{
			//std::cout << "const_data" << std::endl;
			return const_cast<vector*>(this)->data();
		};

		void assign( size_type count, const T& value ){
			std::cout << "assign" << std::endl;

			for(size_type i = 0; i < _nb_elems; i++) {
				_alloc.destroy(_start + i);
			}
			_alloc.deallocate(_start, _capacity);
			
			_start = _alloc.allocate(count);
			_finish = _start + count;
			_end_of_storage = _start + count;
			_nb_elems = count;
			_capacity = count;
			for(size_type i = 0; i < count; i++) {
				_alloc.construct(_start + i, value);
			}
		};

		template <class InputIt>
			void assign( InputIt first, InputIt last ){
				std::cout << "template assign" << std::endl;

				for(size_type i = 0; i < _nb_elems; i++) {
					_alloc.destroy(_start + i);
				}
				_alloc.deallocate(_start, _capacity);
				
				_alloc = Allocator();
				_start = _alloc.allocate(first);
				_finish = _start + first;
				_end_of_storage = _start + first;
				_nb_elems = first;
				_capacity = first;
				for(InputIt i = 0; i < first; i++) {
					_alloc.construct(_start + i, last);
				}
			};



		/* ******* ITERATOR ******* */
		iterator begin() {
			//std::cout << "begin" << std::endl;
			return iterator(this->_start);
		};
		const_iterator begin() const {
			//std::cout << "const_begin" << std::endl;
			return const_cast<vector*>(this)->begin();
		};

		iterator end(){
			//std::cout << "end" << std::endl;
			return iterator(this->_finish);
		};
		const_iterator end() const {
			//std::cout << "const_end" << std::endl;
			return const_cast<vector*>(this)->end();
		};

		reverse_iterator rbegin(){
			//std::cout << "rbegin" << std::endl;
			return reverse_iterator(end());
		};
		const_reverse_iterator rbegin() const {
			//std::cout << "const_rbegin" << std::endl;
			return const_reverse_iterator(end());
		};

		reverse_iterator rend() {
			//std::cout << "rend" << std::endl;
			return reverse_iterator(begin());
		};
		const_reverse_iterator rend() const {
			//std::cout << "const_rend" << std::endl;
			return const_reverse_iterator(begin());
		};





		/* ******* CAPACITY ******* */
		bool empty() const;

		size_type size() const;

		size_type max_size() const;

		void reserve( size_type new_cap ) {
		};

		size_type capacity() const {return _capacity;};





		/* ******* MODIFIERS ******* */
		void clear();

		iterator insert( iterator pos, const T& value ) {
			//std::cout << "insert" << std::endl;
			//std::cout << "	insert() nb elem : " << _nb_elems << std::endl;
			//std::cout << "	insert() capacity : " << _capacity << std::endl << std::endl;
			if(_nb_elems == _capacity) {
				_capacity *= 2;
				_capacity += 1;
				T* new_start = _alloc.allocate(_capacity);
				for(size_type i = 0; i < _nb_elems; i++) {
					_alloc.construct(new_start + i, _start[i]);
				}
				_alloc.deallocate(_start, _capacity);
				_start = new_start;
				_finish = _start + _nb_elems;
				_end_of_storage = _start + _capacity;
			}
			//std::cout << "	insert() capacity after: " << _capacity << std::endl<< std::endl;
			_alloc.construct(_finish, value);
			++_finish;
			++_nb_elems;
			return (pos);
		};
		void insert( iterator pos, size_type count, const T& value ) { };
		template< class InputIt >
			void insert( iterator pos, InputIt first, InputIt last ) { };

		iterator erase( iterator pos );
		iterator erase( iterator first, iterator last );

		void push_back( const T& value ) {
			//std::cout << "push_back : " << value << std::endl;
			//std::cout << "nb elem : " << _nb_elems << std::endl;

			if(_finish != _end_of_storage) {
				//std::cout << "	construct() nb elem : " << _nb_elems << std::endl;
				_alloc.construct(_finish, value);
				++_finish;
				++_nb_elems;
			}
			else {
				insert(end(), value);
			}
		};
		
		void pop_back();

		void resize( size_type count, T value = T() );

		void swap( vector& other );

		// template <class O, class Alloc>
		// bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		// 	return !(lhs == rhs);
		// };


		/* ******* OPERATORS ******* */
		// friends autorise
		template <class O, class Alloc>
		bool operator==(const vector<O, Alloc> &rhs) {
			return (this->_start == rhs._start);
		};

		template <class O, class Alloc>
		bool operator!=(const vector<O, Alloc> &rhs) {
			return !(rhs == *this);
		};

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

	/* ******* CONSTRUCTION ******* */
	
	/* ******* ELEMENT ACCESS ******* */

	/* ******* ITERATOR ******* */

	/* ******* CAPACITY ******* */

	/* ******* MODIFIERS ******* */

	/* ******* NON MEMBER FUNCTION OVERLOAD ******* */

	/* ******* MES TESTs ******* */


}

#endif