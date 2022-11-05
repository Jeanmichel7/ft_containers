/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:06:29 by jrasser           #+#    #+#             */
/*   Updated: 2022/11/05 02:24:18 by jrasser          ###   ########.fr       */
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

private:
	Allocator _alloc;
	pointer 	_start;
	pointer 	_finish;
	size_type _nb_elems;
	size_type _capacity;


public:
	size_type get_nb_elems() const { return _nb_elems; }
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
	}

	explicit vector(const Allocator &alloc)
	:
		_alloc(alloc),
		_start(_alloc.allocate(0)),
		_finish(_start),
		_nb_elems(0),
		_capacity(0)
	{
	}

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
		for (size_type i = 0; i < count; i++) {
			_alloc.construct(_start + i, value);
			_nb_elems = i + 1;
		}
	}

	template <class InputIt>
	vector(InputIt first,
				typename enable_if<!ft::is_integral<InputIt>::value, InputIt>::type last,
				const Allocator &alloc = Allocator())
	:
		_alloc(alloc)
	{
		difference_type n = ft::distance(first, last);
		
		_start = _alloc.allocate(n);
		_finish = _start;
		_nb_elems = 0;
		_capacity = 0;
		while (first != last) {
			push_back(*first);
			first++;
		}
	}

	vector(const vector &other)
	:
		_alloc(other._alloc),
		_start(_alloc.allocate(other._capacity)),
		_finish(_start + other._nb_elems),
		_nb_elems(other._nb_elems),
		_capacity(other._capacity)
	{
		for (size_type i = 0; i < other._nb_elems; i++) {
			_alloc.construct(_start + i, other._start[i]);
		}
	}

	vector &operator=(const vector &other)
	{
		for (size_type i = 0; i < _nb_elems; i++) {
			_alloc.destroy(_start + i);
		}
		_alloc.deallocate(_start, _capacity);
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
		if (pos > _nb_elems)
			throw std::out_of_range("out of range");
		return _start[pos];
	};

	const_reference operator[](size_type pos) const
	{
		if (pos > _nb_elems)
			throw std::out_of_range("out of range");
		return const_cast<vector *>(this)->operator[](pos);
	};

	reference front()
	{
		return _start[0];
	};

	const_reference front() const
	{
		return const_cast<vector *>(this)->front();
	};

	reference back()
	{
		return _start[_nb_elems - 1];
	};

	const_reference back() const
	{
		return const_cast<vector *>(this)->back();
	};

	T *data()
	{
		return _start;
	};

	const T *data() const
	{
		return const_cast<vector *>(this)->data();
	};

	
	void assign(size_type count, const T &value)
	{
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
	}







	/* *************************************************** */
	/*                                                     */
	/*                       ITERATOR                      */
	/*                                                     */
	/* *************************************************** */

	iterator begin()
	{
		return iterator(this->_start);
	}

	const_iterator begin() const
	{
		return const_iterator(this->_start);
	}

	iterator end()
	{
		return iterator(this->_finish);
	}

	const_iterator end() const
	{
		return const_iterator(this->_finish);
		// return const_cast<vector*>(this)->_finish;
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(this->_finish);
	}

	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(this->_finish);
	}

	reverse_iterator rend()
	{
		return reverse_iterator(this->_start);
	}

	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(this->_start);
	}






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

	}

	void insert(iterator pos, size_type count, const T &value)
	{
		try {
			iterator it = begin();

			for(size_t i = 0; i < count; i++) {
				pos = insert(pos, value);
			}
		}
		catch (std::exception const &e) {
			throw;
		}
	}


	template <class InputIt>
	void insert(iterator pos,
							InputIt first,
							typename enable_if<!ft::is_integral<InputIt>::value, InputIt>::type last)
	{
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

	}



	iterator erase(iterator pos)
	{
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
		--_nb_elems;
		--_finish;
		return ( pos );
	}



	iterator erase(iterator first, iterator last)
	{
		iterator 				it = begin();
		size_type 			i = 0;
		difference_type n = ft::distance(first, last);

		for (; it != first && it != end(); it++)
			i++;

		/* deplace rang de n */
		while (it != last && i + n < _nb_elems - 1 && it != end())
		{
			_alloc.construct(_start + i, *(_start + i + n));
			it++;
			i++;
		}

		/* deplace elem deriere */
		while (it != end() && i + n < _nb_elems)
		{
			_alloc.construct(_start + i, *(_start + i + n));
			_alloc.destroy(_start + i + n);
			it++;
			i++;
		}
		_nb_elems -= n;
		_finish -= n;
		return ( first );
	};



	void push_back(const T &value)
	{
		if (_nb_elems != _capacity) {
			// reserve(_nb_elems + 1);
			_alloc.construct(_finish, value);
			++_finish;
			++_nb_elems;
			return;
		}
		insert(end(), value);
	};

	void pop_back()
	{
		--_finish;
		_alloc.destroy(_finish);
		--_nb_elems;
	};

	void resize(size_type count, T value = T())
	{
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