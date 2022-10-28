/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_vector.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:23:50 by jrasser           #+#    #+#             */
/*   Updated: 2022/10/27 22:11:00 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_VECTOR
# define ITERATOR_VECTOR

# include "../enable_if.hpp"

namespace ft
{

template <typename T>
class iterator_vector : ft::iterator<ft::random_access_iterator_tag, T>
{
public :
	typedef T    value_type;
	typedef typename ft::iterator<ft::random_access_iterator_tag, value_type>::iterator_category 	iterator_category;
	typedef typename ft::iterator<ft::random_access_iterator_tag, value_type>::difference_type 		difference_type;
	typedef typename ft::iterator<ft::random_access_iterator_tag, value_type>::pointer						pointer;
	typedef typename ft::iterator<ft::random_access_iterator_tag, value_type>::reference 					reference;

private :
	pointer _ptr;

public :
	iterator_vector() : _ptr(NULL) {}
	iterator_vector(pointer ptr) : _ptr(ptr) {}
	iterator_vector(const iterator_vector &src) : _ptr(src._ptr) {}
	~iterator_vector() {}

	iterator_vector &operator=(const iterator_vector &rhs)
	{
		if (this != &rhs)
			this->_ptr = rhs._ptr;
		return (*this);
	}

	reference operator*() const { return (*this->_ptr); }
	pointer operator->() const { return (this->_ptr); }
	iterator_vector &operator++() { ++this->_ptr; return (*this); }
	iterator_vector operator++(int) { iterator_vector tmp(*this); ++this->_ptr; return (tmp); }
	iterator_vector &operator--() { --this->_ptr; return (*this); }
	iterator_vector operator--(int) { iterator_vector tmp(*this); --this->_ptr; return (tmp); }

	iterator_vector operator+(difference_type n) const { return (iterator_vector(this->_ptr + n)); }
	iterator_vector &operator+=(difference_type n) { this->_ptr += n; return (*this); }
	iterator_vector operator-(difference_type n) const { return (iterator_vector(this->_ptr - n)); }
	iterator_vector &operator-=(difference_type n) { this->_ptr -= n; return (*this); }

	difference_type operator-(const iterator_vector &rhs) const { return (this->_ptr - rhs._ptr); }

	reference operator[](difference_type n) { return (this->_ptr[n]); }

	bool operator==(const iterator_vector &rhs) const { return (this->_ptr == rhs._ptr); }
	bool operator!=(const iterator_vector &rhs) const { return (this->_ptr != rhs._ptr); }
	bool operator<(const iterator_vector &rhs) const { return (this->_ptr < rhs._ptr); }
	bool operator<=(const iterator_vector &rhs) const { return (this->_ptr <= rhs._ptr); }
	bool operator>(const iterator_vector &rhs) const { return (this->_ptr > rhs._ptr); }
	bool operator>=(const iterator_vector &rhs) const { return (this->_ptr >= rhs._ptr); }

};


template <typename T>
class const_iterator_vector : ft::iterator<ft::random_access_iterator_tag, T>
{
public :
	typedef T    value_type;
	typedef typename ft::iterator<ft::random_access_iterator_tag, value_type>::iterator_category 	iterator_category;
	typedef typename ft::iterator<ft::random_access_iterator_tag, value_type>::difference_type 		difference_type;
	typedef typename ft::iterator<ft::random_access_iterator_tag, value_type>::pointer						pointer;
	typedef typename ft::iterator<ft::random_access_iterator_tag, value_type>::reference 					reference;

private :
	pointer _ptr;

public :
	const_iterator_vector() : _ptr(NULL) {}
	const_iterator_vector(pointer ptr) : _ptr(ptr) {}
	const_iterator_vector(const const_iterator_vector &src) : _ptr(src._ptr) {}
	~const_iterator_vector() {}

	const_iterator_vector &operator=(const const_iterator_vector &rhs)
	{
		if (this != &rhs)
			this->_ptr = rhs._ptr;
		return (*this);
	}
	
	reference operator*() const { return (*this->_ptr); }
	pointer operator->() const { return (this->_ptr); }
	const_iterator_vector &operator++() { ++this->_ptr; return (*this); }
	const_iterator_vector operator++(int) { const_iterator_vector tmp(*this); ++this->_ptr; return (tmp); }
	const_iterator_vector &operator--() { --this->_ptr; return (*this); }
	const_iterator_vector operator--(int) { const_iterator_vector tmp(*this); --this->_ptr; return (tmp); }

	const_iterator_vector operator+(difference_type n) const { return (const_iterator_vector(this->_ptr + n)); }
	const_iterator_vector &operator+=(difference_type n) { this->_ptr += n; return (*this); }
	const_iterator_vector operator-(difference_type n) const { return (const_iterator_vector(this->_ptr - n)); }
	const_iterator_vector &operator-=(difference_type n) { this->_ptr -= n; return (*this); }

	difference_type operator-(const const_iterator_vector &rhs) const { return (this->_ptr - rhs._ptr); }

	reference operator[](difference_type n) { return (this->_ptr[n]); }

	bool operator==(const const_iterator_vector &rhs) const { return (this->_ptr == rhs._ptr); }
	bool operator!=(const const_iterator_vector &rhs) const { return (this->_ptr != rhs._ptr); }
	bool operator<(const const_iterator_vector &rhs) const { return (this->_ptr < rhs._ptr); }
	bool operator<=(const const_iterator_vector &rhs) const { return (this->_ptr <= rhs._ptr); }
	bool operator>(const const_iterator_vector &rhs) const { return (this->_ptr > rhs._ptr); }
	bool operator>=(const const_iterator_vector &rhs) const { return (this->_ptr >= rhs._ptr); }

};






	// class iterator_vector
	// {
	// 	public:
	// 		typedef T value_type;
	// 		typedef T* pointer;
	// 		typedef T& reference;
	// 		typedef std::ptrdiff_t difference_type;
	// 		typedef std::random_access_iterator_tag iterator_category;

	// 	private:
	// 		pointer _ptr;

	// 	public:
	// 		iterator_vector() : _ptr(NULL) {}
	// 		iterator_vector(pointer ptr) : _ptr(ptr) {}
	// 		iterator_vector(const iterator_vector &src) : _ptr(src._ptr) {}
	// 		~iterator_vector() {}

	// 		iterator_vector &operator=(const iterator_vector &rhs)
	// 		{
	// 			if (this != &rhs)
	// 				this->_ptr = rhs._ptr;
	// 			return (*this);
	// 		}

	// 		iterator_vector &operator++()
	// 		{
	// 			_ptr++;
	// 			return (*this);
	// 		}

	// 		iterator_vector operator++(int)
	// 		{
	// 			iterator_vector tmp(*this);
	// 			operator++();
	// 			return (tmp);
	// 		}

	// 		iterator_vector &operator--()
	// 		{
	// 			_ptr--;
	// 			return (*this);
	// 		}

	// 		iterator_vector operator--(int)
	// 		{
	// 			iterator_vector tmp(*this);
	// 			operator--();
	// 			return (tmp);
	// 		}

	// 		iterator_vector operator+(difference_type n) const
	// 		{
	// 			return (iterator_vector(_ptr + n));
	// 		}

	// 		iterator_vector operator-(difference_type n) const
	// 		{
	// 			return (iterator_vector(_ptr - n));
	// 		}

	// 		iterator_vector &operator+=(difference_type n)
	// 		{
	// 			_ptr += n;
	// 			return (*this);
	// 		}

	// 		iterator_vector &operator-=(difference_type n)
	// 		{
	// 			_ptr -= n;
	// 			return (*this);
	// 		}

	// 		reference operator*() const
	// 		{
	// 			return (*_ptr);
	// 		}

	// 		pointer operator->() const
	// 		{
	// 			return (_ptr);
	// 		}

	// 		reference operator[](difference_type n) const
	// 		{
	// 			return (_ptr[n]);
	// 		}

	// 		bool operator==(const iterator_vector &rhs) const
	// 		{
	// 			return (_ptr == rhs._ptr);
	// 		}

	// 		bool operator!=(const iterator_vector &rhs) const
	// 		{
	// 			return (_ptr != rhs._ptr);
	// 		}

	// 		bool operator<(const iterator_vector &rhs) const
	// 		{
	// 			return (_ptr < rhs._ptr);
	// 		}

	// 		bool operator<=(const iterator_vector &rhs) const
	// 		{
	// 			return (_ptr <= rhs._ptr);
	// 		}

	// 		bool operator>(const iterator_vector &rhs) const
	// 		{
	// 			return (_ptr > rhs._ptr);
	// 		}

	// 		bool operator>=(const iterator_vector &rhs) const
	// 		{
	// 			return (_ptr >= rhs._ptr);
	// 		}

	// 		difference_type operator-(const iterator_vector &rhs) const
	// 		{
	// 			return (_ptr - rhs._ptr);
	// 		}

	// 		pointer getPtr() const
	// 		{
	// 			return (_ptr);
	// 		}

	// 		void setPtr(pointer ptr)
	// 		{
	// 			_ptr = ptr;
	// 		}

	// };
	// {
	// 	protected:
	// 		T* it;
	// 	public:
	// 		typedef T* iterator_type;
	// 		typedef ft::iterator_traits<iterator_type> traits_type;

	// 		typedef typename traits_type::iterator_category iterator_category;
	// 		typedef typename traits_type::value_type value_type;
	// 		typedef typename traits_type::difference_type difference_type;
	// 		typedef typename traits_type::pointer pointer;
	// 		typedef typename traits_type::reference reference;

	// 		iterator_vector() : it() {}
	// 		iterator_vector(iterator_type it) : it(it) {}
	// 		iterator_vector(const iterator_vector &src) : it(src.it) {}
	// 		~iterator_vector() {}

	// 		iterator_type base() const { return (it); }

	// 		iterator_vector &operator=(const iterator_vector &rhs)
	// 		{
	// 			if (this != &rhs)
	// 				this->it = rhs.it;
	// 			return (*this);
	// 		}

	// 		reference operator*() const { return (*it); }
	// 		pointer operator->() const { return (&*it); }
	// 		reference operator[](difference_type n) const { return (it[n]); }

	// 		iterator_vector &operator++() { ++it; return (*this); }
	// 		iterator_vector operator++(int) { iterator_vector tmp(*this); ++it; return (tmp); }
	// 		iterator_vector &operator--() { --it; return (*this); }
	// 		iterator_vector operator--(int) { iterator_vector tmp(*this); --it; return (tmp); }

	// 		iterator_vector &operator+=(difference_type n) { it += n; return (*this); }
	// 		iterator_vector &operator-=(difference_type n) { it -= n; return (*this); }
	// 		iterator_vector operator+(difference_type n) const { return (iterator_vector(it + n)); }
	// 		iterator_vector operator-(difference_type n) const { return (iterator_vector(it - n)); }

	// 		difference_type operator-(const iterator_vector &rhs) const { return (it - rhs.it); }
	// 		bool operator==(const iterator_vector &rhs) const { return (it == rhs.it); }
	// 		bool operator!=(const iterator_vector &rhs) const { return (it != rhs.it); }
	// 		bool operator<(const iterator_vector &rhs) const { return (it < rhs.it); }
	// 		bool operator<=(const iterator_vector &rhs) const { return (it <= rhs.it); }
	// 		bool operator>(>
	// {
	// 	public :
	// 		typedef typename T::value_type    value_type;
	// 		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category 	iterator_category;
	// 		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type 	difference_type;
	// 		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
	// 		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference 			reference;




} // namespace ft



#endif