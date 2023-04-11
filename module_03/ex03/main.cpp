/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:18:23 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/11 13:54:23 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	A("Didier");
	A.whoAmI();
	std::cout << "I have " << A.getHitPoints() << " Hit Points, "
			<< A.getEnergyPoints() << " Energy Points, and "
			<< A.getAttackDamage() << " attack damage points\n\n" << std::endl;


	DiamondTrap	B;
	B.whoAmI();
	std::cout << "I have " << B.getHitPoints() << " Hit Points, "
			<< B.getEnergyPoints() << " Energy Points, and "
			<< B.getAttackDamage() << " attack damage points\n\n" << std::endl;


	DiamondTrap	C = A;
	C.whoAmI();
	std::cout << "I have " << B.getHitPoints() << " Hit Points, "
			<< B.getEnergyPoints() << " Energy Points, and "
			<< B.getAttackDamage() << " attack damage points\n";
	C.highFivesGuys();
	C.guardGate();
	std::cout << std::endl;
	return (0);
}
