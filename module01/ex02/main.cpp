/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:45:36 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/10 14:54:46 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	line = "HI THIS IS BRAIN";
	std::string	*stringPTR = &line;
	std::string	&stringREF = line;

	std::cout << "The memory address of the string variable: " << &line
			<< "\nThe memory address held by stringPTR: " << stringPTR
			<< "\nThe memory address held by stringREF: " << &stringREF
			<< "\n\nThe value of the string variable: " << line
			<< "\nThe value pointed to by stringPTR: " << *stringPTR
			<< "\nThe value pointed to by stringREF: " << stringREF << std::endl;
	return (0);
}
