/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:00:56 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/12 17:56:25 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <set>
# include <exception>
# include <string>
# include <iostream>

class	Span
{
	public:
		Span(void);
		Span(unsigned int);
		Span(const Span &src);
		~Span(void);

		Span	&operator=(const Span &src);

		unsigned int	getLength(void) const;

		void	printMultiset(void) const;

		void	addNumber(int);
		template<typename T>
		void	addNumbers(const T &first, const T &last);
		
		void	shortestSpan(void);
		void	longestSpan(void);
	
	private:
		void	printValue(void) const;

		std::multiset<int>	_multiset;
		unsigned int	_length;

	/*	START OF EXCEPTIONS	*/
	class	isFull : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};
	class	isNotBigEnough : public std::exception
	{
		public:
			const char	*what(void) const throw();
	};
	/*	END OF EXCEPTIONS	*/
};

template<typename T>
void	Span::addNumbers(const T &first, const T &last)
{
	if (this->_multiset.size() + std::distance(first, last) > this->_length)
		throw isNotBigEnough();
	std::copy(first, last, std::inserter(this->_multiset, this->_multiset.end()));
}
#endif /*SPAN_HPP*/
