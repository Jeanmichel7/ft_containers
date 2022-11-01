/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_vector.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:23:50 by jrasser           #+#    #+#             */
/*   Updated: 2022/11/01 23:35:48 by jrasser          ###   ########.fr       */
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
	typedef typename ft::iterator< ft::random_access_iterator_tag, value_type >::iterator_category 	iterator_category;
	typedef typename ft::iterator< ft::random_access_iterator_tag, value_type >::difference_type 		difference_type;
	typedef value_type 																																							*pointer;
	typedef value_type 																																							&reference;

private :
	pointer _ptr;

public :
	/* Constructor */
	iterator_vector() 
	: _ptr(NULL) 
	{}
	iterator_vector(pointer ptr) 
	: _ptr(ptr) 
	{}
	iterator_vector(const iterator_vector &src) 
	: _ptr(src._ptr) 
	{}

	iterator_vector &operator=(const iterator_vector &rhs)
	{
		if (this == &rhs)
			return (*this);
    this->_ptr = &(*rhs._ptr);
    return (*this);
	}

	pointer base() const 
	{ return (this->_ptr); }
	
	virtual ~iterator_vector() {}


	/* operator */
	reference operator*() const { return (*this->_ptr); }
	pointer operator->() const { return (this->_ptr); }

	iterator_vector &operator++() { 
		++this->_ptr;
		return (*this);
	}
	iterator_vector operator++(int) { 
		iterator_vector tmp(*this);
		++this->_ptr; 
		return (tmp); 
	}
	iterator_vector &operator--() { 
		--this->_ptr; 
		return (*this); 
	}
	iterator_vector operator--(int) { 
		iterator_vector tmp(*this);
	 	--this->_ptr; 
	 	return (tmp); 
	}

	iterator_vector operator+(difference_type n) const { 
		return (iterator_vector(this->_ptr + n)); 
	}

	iterator_vector &operator+=(difference_type n) {
		this->_ptr += n;
		return (*this); 
	}
	iterator_vector operator-(difference_type n) const { 
		return (iterator_vector(this->_ptr - n));
	}

	iterator_vector &operator-=(difference_type n) { 
		this->_ptr -= n; 
		return (*this); 
	}

	difference_type operator+(const iterator_vector &rhs) const { 
		return (this->_ptr + rhs._ptr); 
	}

	difference_type operator-(const iterator_vector &rhs) const { 
		return (this->_ptr - rhs._ptr); 
	}

	reference operator[](difference_type n) { 
		return (this->_ptr[n]); 
	}

	reference operator[](difference_type n) const { 
		return (this->_ptr[n]); 
	}


	operator iterator_vector< const T >() const {
		return (iterator_vector< const T >(this->_ptr));
	}

	/* Comparaison */
	bool operator==(const iterator_vector< const T > &rhs) const { return (this->_ptr == rhs.base()); }
	bool operator!=(const iterator_vector< const T > &rhs) const { return (this->_ptr != rhs.base()); }
	bool operator<(const iterator_vector< const T > &rhs) const { return (this->_ptr < rhs.base()); }
	bool operator<=(const iterator_vector< const T > &rhs) const { return (this->_ptr <= rhs.base()); }
	bool operator>(const iterator_vector< const T > &rhs) const { return (this->_ptr > rhs.base()); }
	bool operator>=(const iterator_vector< const T > &rhs) const { return (this->_ptr >= rhs.base()); }
};


template <typename T>
iterator_vector<T> operator+(typename iterator_vector<T>::difference_type n, const iterator_vector<T> &rhs) { 
	return (iterator_vector<T>(rhs.base() + n)); 
}

template <typename T>
iterator_vector<T> operator-(typename iterator_vector<T>::difference_type n, const iterator_vector<T> &rhs) { 
	return (iterator_vector<T>(rhs.base() - n)); 
}

template <typename T>
typename iterator_vector<T>::difference_type operator+(const iterator_vector<T> &lhs, const iterator_vector<T> &rhs) { 
	return (lhs.base() + rhs.base()); 
}

template <typename T>
typename iterator_vector<T>::difference_type operator-(const iterator_vector<T> &lhs, const iterator_vector<T> &rhs) { 
	return (lhs.base() - rhs.base()); 
}

} // namespace ft

#endif