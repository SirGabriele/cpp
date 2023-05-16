/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:30:37 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/16 16:40:48 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{

};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange(void)
{

}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &src)
{
	(void)src;
/*	
	if (this != &src)
	{
		
	}
*/
	return (*this);
}
