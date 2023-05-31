/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:28:51 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/20 16:21:26 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <string>
# include <cstdlib>	/*	atoi	*/
# include <map>

class	BitcoinExchange
{
	public:
		static void	openFile(const std::string &name);
		static void	closeFile(const std::string &name);
		static bool	analyseDB(void);
		static void	analyseInput(void);

	private:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange(void);

		BitcoinExchange	&operator=(const BitcoinExchange &src);

		static void	DBFormatError(unsigned int i, const std::string &line);
		static void	InputFormatError(unsigned int i, const std::string &line);

		static bool	analyseLine(const std::string &line, const std::string &separator);
		static bool	analyseDate(const std::string &date);
		static bool	isDateValid(const std::string &date, std::string::size_type firstDashIndex, std::string::size_type secondDashIndex);
		static bool	analyseValue(const std::string &valueStr);

		static	std::ifstream					_infile;
		static	std::map<std::string, float>	_myMap;
		static	std::string						_date;
		static	float							_value;

				/*	START OF EXCEPTIONS	*/
		class	InvalidDB: public std::exception
		{
			public:
				InvalidDB(const std::string &str) throw();
				~InvalidDB(void) throw();
				const char	*what(void) const throw();

			private:
				const std::string	_errMsg;
		};
				/*	END OF EXCEPTIONS	*/
};

#endif /*BITCOINEXCHANGE_HPP*/
