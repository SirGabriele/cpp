/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:17:04 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/30 17:20:30 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	RPN_HPP

# define RPN_HPP
# define WHITESPACES "\t\n\v\f\r "

# include <iostream>
# include <string>
# include <cstring>	/*	std::strtok	*/
# include <cstdlib>	/*	std::strtol()	*/
# include <stack>

enum	functionIndex
{
	ADD,
	SUB,
	MUL,
	DIV,
};

class	RPN
{
	public:
		static bool	isInputValid(const std::string &);
		static bool	calculate(char *);
		static void	displayResult(void);

	private:
		RPN(void);
		RPN(const RPN &src);
		~RPN(void);

		RPN	&operator=(const RPN &src);

		static bool	_add(void);
		static bool	_sub(void);
		static bool	_mul(void);
		static bool	_div(void);

		static int	getOperatorIndex(char);

		static std::stack<double>			_myStack;
		static std::string					_operatorStr;
		static char							_operatorArr[4];
		static bool							(*funcPtr[4])(void);
};

#endif /*RPN_HPP*/
