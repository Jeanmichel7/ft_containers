/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:06:29 by jrasser           #+#    #+#             */
/*   Updated: 2022/08/14 22:28:04 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

// modèle < classe T, classe Alloc = allocator<T> > vecteur de classe ; // modèle générique

template< typename T, typename Alloc = std::allocator<T> >
class Vector
{
private:
    /* data */
public:
    vector(/* args */);
    ~vector();
};

vector::vector(/* args */)
{
}

vector::~vector()
{
}










#endif