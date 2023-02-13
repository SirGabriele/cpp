/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:04:17 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/10 18:13:01 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("knife");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("flower");
		jim.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB valentin("Valentin");
		valentin.attack();
	}
	return 0;
}
