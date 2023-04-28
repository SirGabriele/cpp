/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InvalidInput.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:04:30 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/27 10:17:41 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::InvalidInput::InvalidInput(void) throw(): _errMsg("Invalid Input")
{

}

ScalarConverter::InvalidInput::InvalidInput(const std::string &str) throw(): _errMsg("Invalid Input\n" + str)
{

}

ScalarConverter::InvalidInput::~InvalidInput(void) throw()
{

}

const char	*ScalarConverter::InvalidInput::what(void) const throw()
{
	return (this->_errMsg.c_str());
}
