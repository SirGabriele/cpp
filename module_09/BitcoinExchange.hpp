/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:28:51 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/16 16:40:58 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

class	BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange(void);

		BitcoinExchange	&operator=(const BitcoinExchange &src);
};

#endif /*BITCOINEXCHANGE_HPP*/
