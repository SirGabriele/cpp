/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:18:23 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/08 18:38:30 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	A;
	ClapTrap	B("Jean-Eude");
	ClapTrap	C("Jean-Damien");

	for (int i = 0; i < 11; i++)
		A.attack("Dummy");
	A.beRepaired(5);

	std::cout << '\n';
	
	B.takeDamage(1);
	B.takeDamage(1);
	B.takeDamage(1);
	B.takeDamage(5);
	B.takeDamage(2);
	B.takeDamage(1);
	B.beRepaired(5);

	std::cout << '\n';
	
	C.takeDamage(7);
	C.beRepaired(0);
	C.beRepaired(1);
	C.beRepaired(8);
	C.beRepaired(-1);
	C.takeDamage(0);
	return (0);
}
