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
# define OPERATORS "+-*/"

# include <iostream>
# include <string>
# include <cstring>

class	RPN
{
	public:
		static bool	isInputValid(const std::string &);

	private:
		RPN(void);
		RPN(const RPN &src);
		~RPN(void);

		RPN	&operator=(const RPN &src);
};

#endif /*RPN_HPP*/
