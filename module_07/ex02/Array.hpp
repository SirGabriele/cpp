/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:31:38 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/05 15:38:05 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <string>
# include <exception>

template<typename T>
class	Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &src);
		~Array(void);

		Array	&operator=(const Array &src);
		T		&operator[](int index);

//		int	size(void) const;

	private:
		T	*_array;
		int	_length;
};

/*
• Construction with no parameter: Creates an empty array.
*/
template<typename T>
Array<T>::Array(void): _array(new T[0])
{

}

/*
• Construction with an unsigned int n as a parameter: Creates an array of n elements
initialized by default.
*/
template<typename T>
Array<T>::Array(unsigned int n): _array(new T[n])
{

}

template<typename T>
Array<T>::~Array(void)
{
	delete [] this->_array;
}

/*
• Construction by copy and assignment operator. In both cases, modifying either the
original array or its copy after copying musn’t affect the other array.
*/
template<typename T>
Array<T>::Array(const Array &src)
{
	*this = src;
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array &src)
{
	if (this != &src)
	{
		delete [] this->_array;
		this->_array = new T[src._length];
		for (int i = 0; i < src._length; i++)
			this->_array[i] = src._array[i];
	}
	return (*this);
}

template<typename T>
T	&Array<T>::operator[](int index)
{
	if (index < 0 || index >= this->_length)
		throw std::out_of_range("This index is out of range");
	return (this->_array[index]);
}

#endif /*ARRAY_TPP*/
