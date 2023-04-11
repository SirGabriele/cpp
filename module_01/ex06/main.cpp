/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:29:43 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/13 18:05:18 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	obj;

	if (argc != 2)
	{
		std::cout << "Correct usage is ./harlFilter <level name>" << std::endl;
		return (1);
	}
	obj.complain(argv[1]);
	return (0);
}
