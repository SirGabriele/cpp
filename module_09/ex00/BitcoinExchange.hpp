/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:28:51 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/18 17:48:36 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <string>

class	BitcoinExchange
{
	public:
		static void	openDBFile(void);
		static void	closeDBFile(void);
		static void	analyseDB(void);

	private:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange(void);

		BitcoinExchange	&operator=(const BitcoinExchange &src);

		static void	formatError(unsigned int i, const std::string &line);
		static bool	analyseLine(const std::string &line);
		static bool	analyseDate(const std::string &date);
//		static void	analyseExchangeRate();

		static std::ifstream	_infile;

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
