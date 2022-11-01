/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:15:58 by jrasser           #+#    #+#             */
/*   Updated: 2022/11/01 23:46:54 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONVERT_HPP__
# define __CONVERT_HPP__

# include "main.hpp"

template <typename T>
std::string tostr(T value)
{
	std::ostringstream os ;
	os << value ;
	return os.str() ;
}


template <typename T>
T convert(std::string str)
{
  T ret;
  // std::cout << "str = " << str << std::endl;

	if ( typeid(T).name() == typeid(1).name()){
		// std::cout << "int" << std::endl;
    T ret = 0;

    for(size_t i = 0; i < str.length(); i++){
      ret += (str[i] - '0' + i * 10);
    }
    // std::cout << "ret = " << ret << std::endl;
    return ret;
  }
  else if ( typeid(T).name() == typeid(1.1).name()) {
		// std::cout << "double" << std::endl;
  }
	else if ( typeid(T).name() == typeid(1.1F).name()) {
		// std::cout << "float" << std::endl;
  }
	else if ( typeid(T).name() == typeid(std::string("1")).name()) {
		// std::cout << "string" << std::endl;
  }
	else if ( typeid(T).name() == typeid('1').name()) {
		// std::cout << "char" << std::endl;
  }
	else if ( typeid(T).name() == typeid(true).name()) {
		// std::cout << "bool" << std::endl;
  }
  else {
    // std::cout << "unknown" << std::endl;
  }


  std::stringstream ss(str);
  ss >> ret;
  return ret;
}

#endif
