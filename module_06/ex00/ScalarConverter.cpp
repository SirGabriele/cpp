/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:37:46 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/28 15:10:49 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string ScalarConverter::_type = "";
bool ScalarConverter::_separatorFound = false;
bool ScalarConverter::_digitFound = false;
bool ScalarConverter::_signFound = false;
bool ScalarConverter::_fFound = false;

ScalarConverter::ScalarConverter(void)
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter(void)
{

}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	std::cout << "This action is not possible for ScalarConverter is a static class" << std::endl;
	return (*this);
}

void	ScalarConverter::_checkFlags(void)
{
	if (ScalarConverter::_separatorFound == false && ScalarConverter::_fFound == false)
	{
		ScalarConverter::_type = "int";
		return ;
	}
	else if (ScalarConverter::_fFound == true)
	{
		ScalarConverter::_type = "float";
		return ;
	}
	else if (ScalarConverter::_separatorFound == true && ScalarConverter::_fFound == false)
	{
		ScalarConverter::_type = "double";
		return ;
	}
}

void	ScalarConverter::_setFlags(const std::string &input)
{
	int	ascii_0 = 48;
	int	ascii_9 = 57;

	for (size_t i = 0; i < input.length(); i++)
	{
		int	conv = static_cast<int>(input[i]);

		if (conv < ascii_0 || conv > ascii_9)
		{
			if (input[i] == 'f')
			{
				if (ScalarConverter::_digitFound == false || ScalarConverter::_fFound == true)
					throw InvalidInput();
				else
					ScalarConverter::_fFound = true;
			}
			else if (input[i] == '-' || input[i] == '+')
			{
				if (ScalarConverter::_separatorFound == true || ScalarConverter::_digitFound == true || ScalarConverter::_fFound == true)
					throw InvalidInput();
				if (ScalarConverter::_signFound == true)
					throw InvalidInput("Please provide only one sign <-> or <+>");
				else
					ScalarConverter::_signFound = true;
			}
			else if (input[i] == '.' || input[i] == ',')
			{
				if (ScalarConverter::_fFound == true)
					throw InvalidInput();
				else if (ScalarConverter::_separatorFound == true)
					throw InvalidInput("Please provide only one separator <,> or <.>");
				else
					ScalarConverter::_separatorFound = true;
			}
			else
				throw InvalidInput("The only non digit characters allowed are <f> to specify that your value is of type float and <+> or <-> to specify the sign");
		}
		else if (conv >= ascii_0 && conv <= ascii_9 && ScalarConverter::_digitFound == false)
			ScalarConverter::_digitFound = true;
	}
	if (ScalarConverter::_digitFound == false)
		throw InvalidInput();
}

bool	ScalarConverter::_isTypeObvious(const std::string &input)
{
	int	ascii_0 = 48;
	int	ascii_9 = 57;

	if (input.length() == 0)
		throw InvalidInput("Input is empty");
	else if (input.length() == 1)
	{
		int	conv = static_cast<int>(input[0]);

		if (conv < ascii_0 || conv > ascii_9)
			ScalarConverter::_type = "char";
		else
			ScalarConverter::_type = "int";
		return (true);
	}
	else if (input == "-inff" || input == "+inff" || input == "nanf")
	{
		ScalarConverter::_type = "float";
		return (true);
	}
	else if (input == "-inf" || input == "+inf" || input == "nan")
	{
		ScalarConverter::_type = "double";
		return (true);
	}
	return (false);
}

void	ScalarConverter::convert(const std::string &input)
{
	if (ScalarConverter::_isTypeObvious(input) != true)
	{
		ScalarConverter::_setFlags(input);
		ScalarConverter::_checkFlags();
	}
	ScalarConverter::_convertToChar(input);
	ScalarConverter::_convertToInt(input);
	ScalarConverter::_convertToFloat(input);
	ScalarConverter::_convertToDouble(input);
}

void	ScalarConverter::_convertToChar(std::string input)
{
	long	conv = strtol(input.c_str(), NULL, 10);

	std::cout << "char: ";
	if (ScalarConverter::_type == "char")
		std::cout << '\'' <<  input << '\'' << std::endl;
	else if (conv < 32 || conv > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << '\'' << static_cast<char>(conv) << '\'' << std::endl;
}

void	ScalarConverter::_convertToInt(std::string input)
{
	long	conv = strtol(input.c_str(), NULL, 10);

	std::cout << "int: ";
	if (conv == std::numeric_limits<long>::max() || conv == std::numeric_limits<long>::min())
		std::cout << "Non displayable" << std::endl;
	else if (conv > 2147483647 || conv < -2147483648)
		std::cout << "conversion is impossible" << std::endl;
	else
		std::cout << conv << std::endl;
}

void	ScalarConverter::_convertToFloat(std::string input)
{
	float	conv = strtof(input.c_str(), NULL);

	std::cout << "float: ";
	if (conv == std::numeric_limits<float>::max() || conv == std::numeric_limits<float>::min())
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << conv << 'f' << std::endl;
}

void	ScalarConverter::_convertToDouble(std::string input)
{
	double	conv = strtod(input.c_str(), NULL);

	std::cout << "double: ";
	if (conv == std::numeric_limits<double>::max() || conv == std::numeric_limits<double>::min())
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << conv << std::endl;
}
