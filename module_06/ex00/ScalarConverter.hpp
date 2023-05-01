/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:19:58 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/27 16:00:58 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <limits>
# include <exception>
# include <cstdlib>	/*	strtol(), strtod()	*/
# include <cmath>	/*	floor()	*/

class	ScalarConverter
{
	public:
		static void	convert(const std::string &input); 

	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter(void);

		ScalarConverter	&operator=(const ScalarConverter &src);

		static bool		_isTypeObvious(const std::string &input);
		static void		_setFlags(const std::string &input);
		static void		_checkFlags(void);

		static void	_convertToChar(std::string input);
		static void	_convertToInt(std::string input);
		static void	_convertToFloat(std::string input);
		static void	_convertToDouble(std::string input);

		static std::string	_type;
		static bool			_separatorFound;
		static bool			_digitFound;
		static bool			_signFound;
		static bool			_fFound;

	/*	START OF EXCEPTION	*/
	class	InvalidInput : public std::exception
	{
		public:
			InvalidInput(void) throw();
			InvalidInput(const std::string &str) throw();
			~InvalidInput(void) throw();
			const char	*what(void) const throw();

		private:
			std::string	_errMsg;
	};
	/*	END OF EXCEPTION	*/
};

#endif /*SCALARCONVERTER_HPP*/
