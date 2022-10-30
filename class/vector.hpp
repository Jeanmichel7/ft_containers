/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:06:29 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/30 20:39:26 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#define BLU "\033[0;34m"
#define GRN "\033[0;32m"
#define REDE "\033[0;31m"
#define ERASE "\033[2K\r"
#define END "\033[0m"

// #include "main.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "utils/iterator_vector.hpp"

#include <stdexcept>

namespace ft
{

template <
		typename T,
		typename Allocator = std::allocator<T> 
>
class vector
{

public:
	/* Typedef */
	typedef T 									value_type;
	typedef std::size_t 				size_type;
	typedef Allocator 					allocator_type;
	typedef T 									&reference;
	typedef const T 						&const_reference;
	typedef T 									*pointer;
	typedef const T 						*const_pointer;

	typedef ft::iterator_vector<T> 								iterator;
	typedef ft::iterator_vector<const T> 					const_iterator;
	typedef ft::reverse_iterator<iterator> 				reverse_iterator;
	typedef ft::reverse_iterator<const_iterator> 	const_reverse_iterator;

	typedef typename ft::iterator_traits<iterator>::difference_type difference_type;

	

	// typedef ft::iterator_vector< value_type > 					iterator;
	// typedef ft::iterator_vector< const value_type > 		const_iterator;
	// typedef ft::reverse_iterator< iterator > 						reverse_iterator;
	// typedef ft::reverse_iterator< const_iterator > 			const_reverse_iterator;


private:
	Allocator _alloc;
	pointer 	_start;
	pointer 	_finish;
	size_type _nb_elems;
	size_type _capacity;


public:
	/* *************************************************** */
	/*                                                     */
	/*                     CONSTRUCTION                    */
	/*                                                     */
	/* *************************************************** */

	vector() 
	:
		_start(NULL),
		_finish(NULL),
		_nb_elems(0),
		_capacity(0)
	{
		// std::cout << "Constructor" << std::endl;
	};

	explicit vector(const Allocator &alloc)
	:
		_alloc(alloc),
		_start(_alloc.allocate(0)),
		_finish(_start),
		_nb_elems(0),
		_capacity(0)
	{
		// std::cout << "Constructor with allocator" << std::endl;
	};

	explicit vector(size_type count,
									const T &value = T(),
									const Allocator &alloc = Allocator())
	:
		_alloc(alloc),
		_start(_alloc.allocate(count)),
		_finish(_start + count),
		_nb_elems(count),
		_capacity(count)
	{
		// std::cout << "Constructor with count" << std::endl;
		for (size_type i = 0; i < count; i++) {
			_alloc.construct(_start + i, value);
			_nb_elems = i + 1;
		}
	};

	template <class InputIt>
	vector(InputIt first,
				typename enable_if<!ft::is_integral<InputIt>::value, InputIt>::type last,
				const Allocator &alloc = Allocator())
	:
		_alloc(alloc)
	{
		// std::cout << "Constructor with iterator" << std::endl;
		difference_type n = ft::distance(first, last);
		
		_start = _alloc.allocate(n);
		_finish = _start;
		_nb_elems = 0;
		_capacity = 0;
		while (first != last) {
			push_back(*first);
			first++;
		}
		// insert(begin(), first, last);
		// std::uninitialized_copy(first, last, _start);
	};
	vector(const vector &other)
	:
		_alloc(Allocator()),
		_start(_alloc.allocate(other._nb_elems)),
		_finish(_start + other._nb_elems),
		_nb_elems(other._nb_elems),
		_capacity(other._capacity)
	{
		// std::cout << "Copy constructor" << std::endl;
		// std::uninitialized_copy(other._start, other._finish, _start);
		for (size_type i = 0; i < other._nb_elems; i++) {
			_alloc.construct(_start + i, other._start[i]);
		}
	};

	vector &operator=(const vector &other)
	{
		// std::cout << "Assignment operator" << std::endl;

		// del
		for (size_type i = 0; i < _nb_elems; i++) {
			_alloc.destroy(_start + i);
		}
		_alloc.deallocate(_start, _capacity);
		// affec
		_start = _alloc.allocate(other._nb_elems);
		_finish = _start + other._nb_elems;
		_nb_elems = other._nb_elems;
		_capacity = other._capacity;
		for (size_type i = 0; i < other._nb_elems; i++) {
			_alloc.construct(_start + i, other._start[i]);
		}
		return *this;
	};

	~vector()
	{
		// std::cout << "Destructor" << std::endl;
		for (size_type i = 0; i < _nb_elems; i++) {
			_alloc.destroy(_start + i);
		}
		_alloc.deallocate(_start, _capacity);
	};

	allocator_type get_allocator() const
	{
		return _alloc;
	};







	/* *************************************************** */
	/*                                                     */
	/*                    ELEMENT ACCESS                   */
	/*                                                     */
	/* *************************************************** */

	reference at(size_type pos)
	{
		if (pos > _nb_elems)
			throw std::out_of_range("out_of_range exception!");
		return _start[pos];
	};

	const_reference at(size_type pos) const
	{
		if (pos > _nb_elems)
			throw std::out_of_range("out of range");
		return const_cast<vector *>(this)->at(pos);
	};

	reference operator[](size_type pos)
	{
		// std::cout << "operator[]" << std::endl;
		// try {
			if (pos > _nb_elems)
				throw std::out_of_range("out of range");
			return _start[pos];
		// }
		// catch (const std::exception &e) {
			// std::cerr << REDE << e.what() << END "\n";
			// std::terminate();
		// }
	};

	const_reference operator[](size_type pos) const
	{
		// std::cout << "const_reference operator[]" << std::endl;
		// try {
			if (pos > _nb_elems)
				throw std::out_of_range("out of range");
			return const_cast<vector *>(this)->operator[](pos);
		// }
		// catch (const std::exception &e) {
			// std::cerr << REDE << e.what() << END "\n";
			// std::terminate();
		// }
	};

	reference front()
	{
		// std::cout << "front" << std::endl;
		return _start[0];
	};

	const_reference front() const
	{
		// std::cout << "const_reference front" << std::endl;
		return const_cast<vector *>(this)->front();
	};

	reference back()
	{
		// std::cout << "back" << std::endl;
		return _start[_nb_elems - 1];
	};

	const_reference back() const
	{
		// std::cout << "const_reference back" << std::endl;
		return const_cast<vector *>(this)->back();
	};

	T *data()
	{
		// std::cout << "data" << std::endl;
		return _start;
	};

	const T *data() const
	{
		// std::cout << "const_data" << std::endl;
		return const_cast<vector *>(this)->data();
	};

	/*
	Basic guarantee: if an exception is thrown, the container is in a valid state.
	If allocator_traits::construct is not supported with the appropriate arguments
	for the element constructions, or if the range specified by [first,last) is not valid,
	it causes undefined behavior.
	*/
	void assign(size_type count, const T &value)
	{
		// std::cout << "assign()" << std::endl;
		for (size_type i = 0; i < _nb_elems; i++) {
			_alloc.destroy(_start + i);
		}
		_alloc.deallocate(_start, _capacity);

		_start = _alloc.allocate(count);
		_finish = _start + count;
		_nb_elems = count;
		_capacity = count;
		for (size_type i = 0; i < count; i++) {
			_alloc.construct(_start + i, value);
		}
	};

	template <class InputIt>
	void assign(InputIt first,
							typename enable_if<!ft::is_integral<InputIt>::value, InputIt>::type last)
	{
		// std::cout << "template assign()" << std::endl;
		pointer new_start;
		size_type new_capacity = 0;
		size_type new_nb_elems = 0;

		try {
			for (InputIt it = first; it != last; it++) {
				new_capacity++;
			}
			new_start = _alloc.allocate(new_capacity);
			for (InputIt it = first; it != last; it++) {
				_alloc.construct(new_start + new_nb_elems, *it);
				new_nb_elems++;
			}
			for (size_type i = 0; i < _nb_elems; i++) {
				_alloc.destroy(_start + i);
			}
			_alloc.deallocate(_start, _capacity);
			_start = new_start;
			_finish = _start + new_nb_elems;
			_nb_elems = new_nb_elems;
			_capacity = new_capacity;
		} 
		catch (const std::exception &e) {
			throw;
		}


		// try {
		// 	_alloc = Allocator();
		// 	new_start = _alloc.allocate(last - first);
		// 	for (size_type i = 0; i < _nb_elems; i++) {
		// 		_alloc.destroy(_start + i);
		// 	}
		// 	_alloc.deallocate(_start, _capacity);

		// 	// _alloc = Allocator();
		// 	_start = new_start;
		// 	_finish = _start + (last - first);
		// 	_nb_elems = last - first;
		// 	_capacity = last - first;
		// 	std::uninitialized_copy(first, last, _start);
		// }
		// catch (const std::exception &e) {
		// 	std::cerr << REDE << e.what() << END "\n";
		// }
	};







	/* *************************************************** */
	/*                                                     */
	/*                       ITERATOR                      */
	/*                                                     */
	/* *************************************************** */

	iterator begin()
	{
		// std::cout << "iterator begin()" << std::endl;
		return iterator(this->_start);
	};

	const_iterator begin() const
	{
		// std::cout << "const_iterator begin()" << std::endl;
		return const_iterator(this->_start);
		// return const_cast<vector*>(this)->_start;
	};

	iterator end()
	{
		return iterator(this->_finish);
	};

	const_iterator end() const
	{
		return const_iterator(this->_finish);
		// return const_cast<vector*>(this)->_finish;
	};

	reverse_iterator rbegin()
	{
		return reverse_iterator(this->_finish);
	};

	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(this->_finish);
	};

	reverse_iterator rend()
	{
		return reverse_iterator(this->_start);
	};

	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(this->_start);
	};






	/* *************************************************** */
	/*                                                     */
	/*                       CAPACITY                      */
	/*                                                     */
	/* *************************************************** */

	bool empty() const
	{
		return (begin() == end());
	};

	size_type size() const
	{
		return _nb_elems;
	};

	size_type max_size() const
	{
		return _alloc.max_size();
	};

	void reserve(size_type new_cap)
	{
		// try
		// {
			// std::cout << new_cap << " : " << max_size() << std::endl;

			if (new_cap > max_size())
				throw(std::length_error("length error"));
			if (new_cap > _capacity)
			{
				T *new_start = _alloc.allocate(new_cap);
				for (size_type i = 0; i < _nb_elems; i++)
				{
					_alloc.construct(new_start + i, _start[i]);
				}
				for (size_type i = 0; i < _nb_elems; i++)
				{
					_alloc.destroy(_start + i);
				}
				_alloc.deallocate(_start, _capacity);
				_start = new_start;
				_finish = _start + _nb_elems;
				_capacity = new_cap;
			}
		// }
		// catch (const std::length_error &el)
		// {
		// 	std::cerr << REDE "length_error : " << el.what() << END "\n";
		// 	std::terminate();
		// }
		// catch (const std::exception &e)
		// {
		// 	std::cerr << REDE "error : " << e.what() << END "\n";
		// 	std::terminate();
		// }
	};

	size_type capacity() const { return _capacity; };







	/* *************************************************** */
	/*                                                     */
	/*                       MODIFIERS                     */
	/*                                                     */
	/* *************************************************** */
	void clear()
	{
		for (size_type i = 0; i < _nb_elems; i++)
		{
			_alloc.destroy(_start + i);
		}
		_alloc.deallocate(_start, _capacity);
		_start = _alloc.allocate(0);
		_finish = _start;
		_nb_elems = 0;
	};






	// If an exception is thrown when inserting a single element at the end,
	// and T is CopyInsertable or std::is_nothrow_move_constructible<T>::value is true,
	// there are no effects (strong exception guarantee).
	iterator insert(iterator pos, const T &value)
	{
		iterator it = end();
		iterator new_pos = pos;
		size_t i;
		size_t pos_index = pos - begin();

		if (_nb_elems == _capacity)
		{
			if (_capacity + 1 >= max_size() || _capacity * 2 >= max_size())
				throw std::bad_alloc();

			if (_capacity == 0)
				_capacity += 1;
			_capacity *= 2;

			T *new_start = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _nb_elems; i++) {
				_alloc.construct(new_start + i, _start[i]);
			}
			_alloc.deallocate(_start, _capacity);
			_start = new_start;
			_finish = new_start + _nb_elems;
			new_pos = iterator(_start + (pos_index));
			it = iterator(_start + _nb_elems);
		}

		i = _nb_elems;
		while (it != new_pos && i != 0)
		{
			_alloc.construct(_start + i, *(_start + i - 1));
			_alloc.destroy(_start + i - 1);
			it--;
			i--;
		}
		_alloc.construct(_start + i, value);
		++_finish;
		++_nb_elems;
		return (iterator(_start + i));

	};

	void insert(iterator pos, size_type count, const T &value)
	{
		// std::cout << "insert(pos, count, value) : " << count << std::endl;
		try {
			iterator it = begin();

			for(size_t i = 0; i < count; i++) {
				pos = insert(pos, value);
			}
		}
		catch (std::exception const &e) {
			throw;
		}
	};


	template <class InputIt>
	void insert(iterator pos,
							InputIt first,
							typename enable_if<!ft::is_integral<InputIt>::value, InputIt>::type last)
	{
		// std::cout << "insert(pos, first, last) : " << std::endl;
		try {
			InputIt it = last;
			it --;

			for(; it != first; it--) {
				pos = insert(pos, *it);
			}
			insert(pos, *it);
		}
		catch (std::exception const &e) {
			throw;
		}

		// iterator itb = begin();
		// iterator ite = end();
		// size_t i = 0;
		// size_t j = 0;
		// size_type new_capacity = _capacity;
		// // difference_type n = ft::distance(first, last);
		// size_type count = ft::distance(first, last);
		
		// iterator 	new_pos = pos;
		// size_t 		pos_index = pos - begin();


		// if (count >= max_size())
		// 	throw std::bad_alloc();

		// /* check and allocate */
		// if (_capacity < _nb_elems + count) {
		// 	while (new_capacity < _nb_elems + count)
		// 	{
		// 		if (_capacity + count >= max_size() || _capacity * 2 >= max_size())
		// 			throw std::bad_alloc();
		// 		if (_capacity == 0)
		// 			new_capacity += 1;
		// 		new_capacity *= 2;
		// 	}
		// 	T *new_start = _alloc.allocate(new_capacity);

		// 	_start = new_start;
		// 	_finish = _start + _nb_elems;
		// 	_capacity = new_capacity;
		// }





		// 	while (itb != new_pos && i != _nb_elems)
		// 	{
		// 		_alloc.construct(new_start + i, *(_start + i));
		// 		itb++;
		// 		i++;
		// 	}



		// // deplace de end a pos sur une distance count

		// j = _nb_elems + count;
		// while (ite != new_pos && j != i)
		// {
		// 	_alloc.construct(new_start + j, *(_start + j - count));
		// 	_alloc.destroy(new_start + j - count);
		// 	ite--;
		// 	j--;
		// }
		// _alloc.deallocate(_start, _capacity);
		// _start = new_start;
		// _nb_elems += count;
		// _finish = new_start + _nb_elems;
		// _capacity = new_capacity;
		// while (count != 0)
		// {
		// 	_alloc.construct(_start + i, *first);
		// 	i++;
		// 	count--;
		// 	first++;
		// }
	};



	iterator erase(iterator pos)
	{
		// std::cout << "erase(pos) : " << *pos << std::endl;
		iterator 	it = begin();
		size_type i = 0;

		for (; it != pos; it++)
			i++;
		while (it != end() && i != _nb_elems - 1)
		{
			_alloc.construct(_start + i, *(_start + i + 1));
			it++;
			i++;
		}
		_alloc.destroy(_start + i);
		// _alloc.deallocate(_start + i, 1);
		--_nb_elems;
		--_finish;
		return ( pos );
	};



	iterator erase(iterator first, iterator last)
	{
		iterator 				it = begin();
		iterator				ret = begin();
		size_type 			i = 0;
		difference_type n = ft::distance(first, last);

		for (; it != first; it++)
			i++;
		/* deplace rang de n */
		while (it != last && i != _nb_elems - 1)
		{
			_alloc.construct(_start + i, *(_start + i + n));
			_alloc.destroy(_start + i + n);
			it++;
			i++;
		}

		/* deplace elem deriere */
		while (it != end() && i != _nb_elems - 1)
		{
			_alloc.construct(_start + i, *(_start + i + n));
			it++;
			i++;
		}
		_nb_elems -= n;
		_finish -= n;

		// if (_nb_elems == 0) {
		// 	// std::cout << "nb elem : " << _nb_elems << std::endl;
		// 	return (ret);
		// }
		return ( first );
	};





	void push_back(const T &value)
	{
		if (_nb_elems != _capacity) {
			_alloc.construct(_finish, value);
			++_finish;
			++_nb_elems;
		}
		else {
			insert(end(), value);
		}
	};

	void pop_back()
	{
		// std::cout << "pop_back" << std::endl;
		--_finish;
		_alloc.destroy(_finish);
		--_nb_elems;
	};

	void resize(size_type count, T value = T())
	{
		// std::cout << "resize" << std::endl;
		if (count > _nb_elems) {
			for (size_type i = _nb_elems; i < count; i++) {
				push_back(value);
			}
		}
		else if (count < _nb_elems) {
			for (size_type i = _nb_elems; i > count; i--) {
				pop_back();
			}
		}
	};

	void swap(vector &other)
	{
		// std::cout << "swap" << std::endl;
		std::swap(_start, other._start);
		std::swap(_finish, other._finish);
		std::swap(_nb_elems, other._nb_elems);
		std::swap(_capacity, other._capacity);
	};







	/* *************************************************** */
	/*                                                     */
	/*                        MY TEST                      */
	/*                                                     */
	/* *************************************************** */
	void display(std::string msg)
	{
		std::cout << "\n------------------- " << msg << " ---------------------" << std::endl;
		// std::cout << "start 		: " << &_start << std::endl;
		// std::cout << "finish 		: " << &_finish << std::endl;
		std::cout << "nb_elems 	: " << _nb_elems << std::endl;
		std::cout << "capacity 	: " << _capacity << std::endl;
		std::cout << "content 	: ";

		iterator it = begin();
		while (it != end())
		{
			if (it != --end())
				std::cout << *it << ", ";
			else
				std::cout << *it;
			it++;
		}
		std::cout << std::endl
							<< "----------------------------------------\n\n"
							<< std::endl;
	}
};




/* *************************************************** */
/*                                                     */
/*                       OPERATORS                     */
/*                                                     */
/* *************************************************** */

template <class T, class Alloc>
bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	typename vector<T, Alloc>::const_iterator it1 = lhs.begin();
	typename vector<T, Alloc>::const_iterator it2 = rhs.begin();
	while (it1 != lhs.end())
	{
		if (*it1 != *it2)
			return (false);
		it1++;
		it2++;
	}
	return (true);
};

template <class T, class Alloc>
bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
	return !(rhs == lhs);
};

template <class T, class Alloc>
bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
	typename vector<T, Alloc>::const_iterator it1 = lhs.begin();
	typename vector<T, Alloc>::const_iterator it2 = rhs.begin();
	while (it1 != lhs.end() && it2 != rhs.end())
	{
		if (*it1 < *it2)
			return (true);
		else if (*it1 > *it2)
			return (false);
		it1++;
		it2++;
	}
	if (lhs.size() < rhs.size())
		return (true);
	return (false);
};

template <class T, class Alloc>
bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
	return (lhs < rhs || lhs == rhs);
};

template <class T, class Alloc>
bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
	return !(lhs <= rhs);
};

template <class T, class Alloc>
bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
	return !(lhs < rhs);
};


template <class T, class Alloc>
void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
{
	x.swap(y);
};



} // namespace ft

#endif