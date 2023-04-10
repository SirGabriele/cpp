/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainClap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:18:23 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/10 14:59:45 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

static void	frag(void)
{
	FragTrap	A("David");
	FragTrap	B("Noa");
	FragTrap	C("Yossef");

	for (int i = 0; i < 101; i++)
		A.attack("Dummy");
	A.highFivesGuys();

	std::cout << '\n';

	B.takeDamage(1);
	B.highFivesGuys();
	B.highFivesGuys();
	B.takeDamage(1);
	B.takeDamage(1);
	B.takeDamage(5);
	B.takeDamage(2);
	B.takeDamage(90);
	B.beRepaired(3);

	std::cout << '\n';
	
	C.takeDamage(7);
	C.beRepaired(0);
	C.beRepaired(1);
	C.beRepaired(8);
	C.beRepaired(50);
}

static void	scav(void)
{
	ScavTrap	A("Denis");
	ScavTrap	B("Matthieu");
	ScavTrap	C("Hervé");

	for (int i = 0; i < 51; i++)
		A.attack("Dummy");
	A.guardGate();

	std::cout << '\n';

	B.takeDamage(1);
	B.guardGate();
	B.guardGate();
	B.takeDamage(1);
	B.takeDamage(1);
	B.takeDamage(5);
	B.takeDamage(2);
	B.takeDamage(90);
	B.beRepaired(3);

	std::cout << '\n';
	
	C.takeDamage(7);
	C.beRepaired(0);
	C.beRepaired(1);
	C.beRepaired(8);
	C.beRepaired(50);
}

static void clap(void)
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
}

int	main(void)
{
	clap();
	std::cout << '\n';
	scav();
	std::cout << '\n';
	frag();
}
