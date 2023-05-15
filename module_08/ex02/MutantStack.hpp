/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:26:44 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/15 16:44:09 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class	MutantStack: public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack &src);
		~MutantStack(void);

		MutantStack	&operator=(const MutantStack &src);

		typedef	typename std::stack<T>::container_type::iterator	iterator;

		iterator	begin(void);
		iterator	end(void);
};

template<typename T>
MutantStack<T>::MutantStack(void)
{

}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &src)
{
	*this = src;
};

template<typename T>
MutantStack<T>::~MutantStack(void)
{

}

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack &src)
{
	this->container_type = src;
	return (*this);
}

template<typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template<typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::end(void)
{
	return (this->c.end());
}

//std::stack<T>::container_type::iterator	&end(void);
#endif /*MUTANTSTACK_HPP*/
