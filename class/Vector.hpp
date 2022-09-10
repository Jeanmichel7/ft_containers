/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:06:29 by jrasser           #+#    #+#             */
/*   Updated: 2022/09/10 12:40:15 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#define BLU "\033[0;34m"
#define GRN "\033[0;32m"
#define RED "\033[0;31m"
#define ERASE "\033[2K\r"
#define END "\033[0m"

#include "Iterator_traits.hpp"
#include "my_iterator.hpp"
#include "my_reverse_iterator.hpp"
#include "enable_if.hpp"

#include <stdexcept>

#include <type_traits>

// #include <memory>
// #include <cstddef>
// #include <iterator>
// #include <iostream>
// #include <limits>

namespace ft
{
	
	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		public:
			/* Typedef */

			typedef std::size_t 								size_type;
			typedef Allocator 									allocator_type;

			typedef T 											&reference;
			typedef const T 									&const_reference;

			typedef T 											*pointer;
			typedef const T 									*const_pointer;

			typedef my_iterator<pointer>						iterator;
			typedef my_iterator<const_pointer> const			const_iterator;

			// typedef typename ft::iterator_traits<iterator>::difference_type   difference_type;

			typedef my_reverse_iterator<iterator> 				reverse_iterator;
			typedef my_reverse_iterator<const_iterator> const	const_reverse_iterator;


		private:
			Allocator 	_alloc;
			pointer 	_start;
			pointer 	_finish;
			pointer 	_end_of_storage;

			size_type 	_nb_elems;
			size_type 	_capacity;

		public:

			/* *************************************************** */
			/*                                                     */
			/*                     CONSTRUCTION                    */
			/*                                                     */
			/* *************************************************** */

		vector() :
			_start(NULL),
			_finish(NULL),
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

		// template <class InputIt, class = typename ft::enable_if<!ft::is_integral<InputIt>::value>::type>>								//(5)
		template <class InputIt>								//(5)
			// typename ft::enable_if<!ft::is_integral<InputIt>::value, void>::type
			vector( InputIt first, 
					typename enable_if<!std::is_integral<InputIt>::value, InputIt>::type last,
					const Allocator &alloc = Allocator() ) :
			_alloc(alloc),
			_start(_alloc.allocate(last - first)),
			_finish(_start + (last - first)),
			_end_of_storage(_start + (last - first)),
			_nb_elems(last - first),
			_capacity(last - first)
			{
				std::cout << "Constructor with InputIt" << std::endl;
				std::uninitialized_copy(first, last, _start);
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

		allocator_type get_allocator() const {
			return _alloc;
		};


		/* *************************************************** */
		/*                                                     */
		/*                    ELEMENT ACCESS                   */
		/*                                                     */
		/* *************************************************** */

		reference at( size_type pos )
		{
			//std::cout << "at" << std::endl;
			try {
				if(pos >= _nb_elems)
					throw std::out_of_range("out of range");
				return _start[pos];
			} catch(const std::exception& e) {
				std::cerr << e.what() << "'\n";
				std::terminate();
			}
		};
		const_reference at( size_type pos ) const {
			//std::cout << "const_reference at" << std::endl;
			try {
				if(pos >= _nb_elems)
					throw std::out_of_range("out of range");
				return const_cast<vector*>(this)->at(pos);
			} catch(const std::exception& e) {
				std::cerr << e.what() << '\n';
				std::terminate();
			}
		};

		reference operator[]( size_type pos ) {
			//std::cout << "operator[]" << std::endl;
			try {
				if(pos >= _nb_elems)
					throw std::out_of_range("out of range");
				return _start[pos];
			} catch(const std::exception& e) {
				std::cerr << e.what() << '\n';
				std::terminate();
			}
		};
		const_reference operator[]( size_type pos ) const {											//c'est utilise quand ?
			//std::cout << "const_reference operator[]" << std::endl;
			try {
				if(pos >= _nb_elems)
					throw std::out_of_range("out of range");
				return const_cast<vector*>(this)->operator[](pos);
			} catch(const std::exception& e) {
				std::cerr << e.what() << '\n';
				std::terminate();
			}
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

/*
Basic guarantee: if an exception is thrown, the container is in a valid state.
If allocator_traits::construct is not supported with the appropriate arguments 
for the element constructions, or if the range specified by [first,last) is not valid,
it causes undefined behavior.
*/

		void assign( size_type count, const T& value ){             /* when call ?? */
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
			void assign( InputIt first,
						 typename enable_if<!std::is_integral<InputIt>::value, InputIt>::type last )
			{
				std::cout << "template assign" << std::endl;

				pointer new_start;
				try
				{
					_alloc = Allocator();
					new_start = _alloc.allocate(last - first);

					for(size_type i = 0; i < _nb_elems; i++) {
						_alloc.destroy(_start + i);
					}
					_alloc.deallocate(_start, _capacity);
					
					// _alloc = Allocator();
					_start = new_start;
					_finish = _start + ( last - first);
					_end_of_storage = _start + ( last - first );
					_nb_elems = last - first;
					_capacity = last - first;

					std::uninitialized_copy(first, last, _start);
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}

			};



		/* ******* ITERATOR ******* */
		iterator begin() {
			//std::cout << "begin" << std::endl;
			return iterator(this->_start);
		};
		const_iterator begin() const {
			//std::cout << "const_begin" << std::endl;
			return const_iterator(this->_start);
			//return const_cast<vector*>(this)->begin();
		};

		iterator end(){
			//std::cout << "end" << std::endl;
			return iterator(this->_finish);
		};
		const_iterator end() const {
			//std::cout << "const_end" << std::endl;
			return const_iterator(this->_finish);
			//return const_cast<vector*>(this)->end();
		};

		reverse_iterator rbegin(){
			//std::cout << "rbegin" << std::endl;
			return reverse_iterator(this->_finish);
			//return reverse_iterator(end());
		};
		const_reverse_iterator rbegin() const {
			//std::cout << "const_rbegin" << std::endl;
			return const_reverse_iterator(this->_finish);
			//return const_reverse_iterator(end());
		};

		reverse_iterator rend() {
			//std::cout << "rend" << std::endl;
			return reverse_iterator(this->_start);
			//return reverse_iterator(begin());
		};
		const_reverse_iterator rend() const {
			//std::cout << "const_rend" << std::endl;
			return const_reverse_iterator(this->_start);
			//return const_reverse_iterator(begin());
		};




		/* *************************************************** */
		/*                                                     */
		/*                       CAPACITY                      */
		/*                                                     */
		/* *************************************************** */

		bool empty() const {
			return ( begin() == end() );
		};

		size_type size() const {
			return _nb_elems;
		};

		size_type max_size() const {
			return _alloc.max_size();
		};

		void reserve( size_type new_cap ) {
			try {
				//std::cout << new_cap << " : " << max_size() << std::endl;
				
				if(new_cap > max_size())
					throw (std::length_error("length blablabli"));
				if(new_cap > _capacity) {
					T* new_start = _alloc.allocate(new_cap);
					for(size_type i = 0; i < _nb_elems; i++) {
						_alloc.construct(new_start + i, _start[i]);
					}
					for(size_type i = 0; i < _nb_elems; i++) {
						_alloc.destroy(_start + i);
					}
					_alloc.deallocate(_start, _capacity);
					_start = new_start;
					_finish = _start + _nb_elems;
					_end_of_storage = _start + new_cap;
					_capacity = new_cap;
				}
			}
			catch(const std::length_error &el) {
				std::cerr << "length_error : " << el.what() << '\n';
				std::terminate();
			}
			catch(const std::exception& e) {
				std::cerr << "error : " << e.what() << '\n';
				std::terminate();
			}
		};

		size_type capacity() const {return _capacity;};




		/* *************************************************** */
		/*                                                     */
		/*                       MODIFIERS                     */
		/*                                                     */
		/* *************************************************** */

		void clear() {
			for(size_type i = 0; i < _nb_elems; i++) {
				_alloc.destroy(_start + i);
			}
			_alloc.deallocate(_start, _capacity);
			_start = _alloc.allocate(0);
			_finish = _start;
			_end_of_storage = _start;
			_nb_elems = 0;
		};


		// If an exception is thrown when inserting a single element at the end, 
		// and T is CopyInsertable or std::is_nothrow_move_constructible<T>::value is true, 
		// there are no effects (strong exception guarantee).

		iterator insert( iterator pos, const T& value ) {
			std::cout << "insert(pos, value) : " << value<< std::endl;
			try {
				iterator 	it = end();
				size_t 		i;
				
				if(_nb_elems == _capacity) {
					std::cout << "new allocation " << std::endl;
					if (_capacity + 1 >= max_size() || _capacity * 2 >= max_size())
						throw std::bad_alloc();
					if (_capacity == 0)
						_capacity += 1;
					_capacity *= 2;
					T* new_start = _alloc.allocate(_capacity);

					for(size_type i = 0; i < _nb_elems; i++) {
						_alloc.construct(new_start + i, _start[i]);
					}

					_alloc.deallocate(_start, _capacity);
					_start = new_start;
					_finish = new_start + _nb_elems;
					_end_of_storage = new_start + _capacity;
				}

				if (_nb_elems != 0)
					i = _nb_elems;
				else
					i = 0;
				while(it != pos && i != 0) {
					_alloc.construct(_start + i, *(_start + i - 1));
					_alloc.destroy(_start + i - 1);
					it--;
					i--;
				}
				_alloc.construct(_start + i, value);
				++_finish;
				++_nb_elems;
			} catch(const std::length_error &el) {
				std::cerr << "length_error : " << el.what() << '\n';
				std::terminate();
			
			} catch (std::exception const &e) {
				std::cerr << "dfddsfsdfdsfdsffsfds "<< e.what() << std::endl;
			}

			return (pos);
		};





		void insert( iterator pos, size_type count, const T& value ) { 
			std::cout << "insert(pos, count, value) : " << count << std::endl;
			try {
				// std::cout << "max_size : " << max_size() << std::endl;

				iterator 	ite = end();
				iterator	itb = begin();
				size_t 		i;
				size_t 		j;
				size_type 	new_capacity = _capacity;
				
				if (count >= max_size())
					throw std::bad_alloc();

				while (new_capacity < _nb_elems + count) 
				{
					if (_capacity + count >= max_size() || _capacity * 2 >= max_size())
						throw std::bad_alloc();
					if (_capacity == 0)
						new_capacity = _capacity + 1;
					new_capacity = _capacity * 2;
				}
				T* new_start = _alloc.allocate(new_capacity);
				i = 0;
				while(itb != pos && i != _nb_elems)
				{
					_alloc.construct(new_start + i, *(_start + i));
					itb++;
					i++;
				}
				if (_nb_elems != 0)
					j = _nb_elems + count;
				else
					j = 0;
				while(ite != pos && j != i)
				{
					_alloc.construct(new_start + j, *(_start + j - count));
					_alloc.destroy(new_start + j - count);
					ite--;
					j--;
				}
				_alloc.construct(new_start + j, *(_start + j - count));
				_alloc.destroy(new_start + j - count);
				_alloc.deallocate(_start, _capacity);
				_start = new_start;
				_nb_elems += count;
				_finish = new_start + _nb_elems;
				_end_of_storage = new_start + new_capacity;
				_capacity = new_capacity;
				while (count != 0)
				{
					_alloc.construct(_start + i, value);
					i++;
					count--;
				}
			} catch(const std::length_error &el) {
				std::cerr << "length_error : " << el.what() << '\n';
				std::terminate();
			
			} catch (std::exception const &e) {
				std::cerr << e.what() << std::endl;
			}
		};


		template< class InputIt >
			void insert( iterator pos,
						 InputIt first,
						 typename enable_if<!std::is_integral<InputIt>::value, InputIt>::type last ) { 
				std::cout << "insert(pos, first, last) " << std::endl;

				// std::cout << "it_insert_first : " << *first << std::endl;
				// std::cout << "it_insert_half : " << *last << std::endl;
				// std::cout << "dist : "	<< last - first << std::endl;

				try {
					// std::cout << "max_size : " << max_size() << std::endl;

					iterator 	ite = end();
					iterator	itb = begin();
					size_t 		i;
					size_t 		j;
					size_type 	new_capacity = _capacity;
					size_type	count = last - first;

					if (count >= max_size())
						throw std::bad_alloc();

					// reallocate
					while (new_capacity < _nb_elems + count) 
					{
						if (_capacity + count >= max_size() || _capacity * 2 >= max_size())
							throw std::bad_alloc();
						if (_capacity == 0)
							new_capacity = _capacity + 1;
						new_capacity = _capacity * 2;
					}
					T* new_start = _alloc.allocate(new_capacity);

					// copie avant pos
					i = 0;
					while(itb != pos && i != _nb_elems)
					{
						_alloc.construct(new_start + i, *(_start + i));
						itb++;
						i++;
					}

					// deplace de end a pos sur une distance count
					if (_nb_elems != 0)
						j = _nb_elems + count;
					else
						j = 0;
					while(ite != pos && j != i)
					{
						_alloc.construct(new_start + j, *(_start + j - count));
						_alloc.destroy(new_start + j - count);
						ite--;
						j--;
					}
					_alloc.construct(new_start + j, *(_start + j - count));
					_alloc.destroy(new_start + j - count);
					_alloc.deallocate(_start, _capacity);
					_start = new_start;
					_nb_elems += count;
					_finish = new_start + _nb_elems;
					_end_of_storage = new_start + new_capacity;
					_capacity = new_capacity;
					while (count != 0)
					{
						_alloc.construct(_start + i, *first);
						i++;
						count--;
						first++;
					}
				} catch(const std::length_error &el) {
					std::cerr << "length_error : " << el.what() << '\n';
					std::terminate();
				} catch (std::exception const &e) {
					std::cerr << e.what() << std::endl;
				}
			};



		iterator erase( iterator pos ) {
			std::cout << "erase(pos) " << std::endl;
			iterator it = pos;
			while (it != end() - 1)
			{
				// _alloc.construct(it, *(it + 1));
				_alloc.destroy(it + 1);
				it++;
			}
			_alloc.destroy(it);
			--_finish;
			--_nb_elems;
			return (pos);
		};

		iterator erase( iterator first, iterator last ) {
			std::cout << "erase(first, last) " << std::endl;
			iterator 	it = first;
			int			i = 0;
			while (it != last)
			{
				// _alloc.construct(it, *(it + (last - first)));
				_alloc.destroy(_start + i + (last - first));
				it++;
				i++;
			}
			_alloc.deallocate(_start, _capacity);
			_finish -= (last - first);
			_nb_elems -= (last - first);
			return (first);
		};

		void push_back( const T& value ) {
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
		
		void pop_back() {
			//std::cout << "pop_back" << std::endl;
			--_finish;
			_alloc.destroy(_finish);
			--_nb_elems;
		};

		void resize( size_type count, T value = T() ) {
			//std::cout << "resize" << std::endl;
			if(count > _nb_elems) {
				for(size_type i = _nb_elems; i < count; i++) {
					push_back(value);
				}
			}
			else if(count < _nb_elems) {
				for(size_type i = _nb_elems; i > count; i--) {
					pop_back();
				}
			}
		};

		void swap( vector& other ) {
			//std::cout << "swap" << std::endl;
			std::swap(_start, other._start);
			std::swap(_finish, other._finish);
			std::swap(_end_of_storage, other._end_of_storage);
			std::swap(_nb_elems, other._nb_elems);
			std::swap(_capacity, other._capacity);
		};


		/* *************************************************** */
		/*                                                     */
		/*                       OPERATORS                     */
		/*                                                     */
		/* *************************************************** */

		template <class O, class Alloc>
		bool operator==(const vector<O, Alloc> &rhs) {
			return (this->_start == rhs._start);
		};

		template <class O, class Alloc>
		bool operator!=(const vector<O, Alloc> &rhs) {
			return !(rhs == *this);
		};

		template <class O, class Alloc>
		bool operator<(const vector<O, Alloc> &rhs) {
			return (this->_start < rhs._start);
		};

		template <class O, class Alloc>
		bool operator<=(const vector<O, Alloc> &rhs) {
			return (this->_start <= rhs._start);
		};

		template <class O, class Alloc>
		bool operator>(const vector<O, Alloc> &rhs) {
			return (this->_start > rhs._start);
		};

		template <class O, class Alloc>
		bool operator>=(const vector<O, Alloc> &rhs) {
			return (this->_start >= rhs._start);
		};

		template <class O, class Alloc>
		void swap(vector<O, Alloc> &lhs,
				  vector<O, Alloc> &rhs)
		{
			lhs.swap(rhs);
		};



	/* *************************************************** */
	/*                                                     */
	/*                        MY TEST                      */
	/*                                                     */
	/* *************************************************** */

	void	display(std::string msg) const {

		std::cout << GRN << msg << END<< std::endl;
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "start 		: " << &_start << std::endl;
		std::cout << "finish 		: " << &_finish << std::endl;
		std::cout << "end_of_storage 	: " << &_end_of_storage << std::endl;
		std::cout << "nb_elems 	: " << _nb_elems << std::endl;
		std::cout << "capacity 	: " << _capacity << std::endl;
		std::cout << "content 	: ";
		for(size_type i = 0; i < _nb_elems; i++) {
			std::cout << _start[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "----------------------------------------\n\n" << std::endl;
	};

	};
}

#endif