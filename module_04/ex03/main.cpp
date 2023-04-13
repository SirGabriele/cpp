/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:08:52 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/13 19:33:10 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

static void	line(void)
{
	std::cout << "\n-------------------------------------------------------------------\n" << std::endl;
}

static void	cure(void)
{
//	return ;
	std::cout << "AMateria *A = new Cure();" << '\n';

	AMateria	*A = new Cure();

	std::cout << "type = " << A->getType() << std::endl;
	std::cout << "AMateria *B = A->clone();" << '\n';

	AMateria	*B = A->clone();

	std::cout << "delete A;" << '\n';
	delete A;
	std::cout << "type = " << B->getType() << std::endl;
	delete B;
}

static void	ice(void)
{
//	return ;
	std::cout << "AMateria *A = new Ice();" << '\n';

	AMateria	*A = new Ice();

	std::cout << "type = " << A->getType() << std::endl;
	std::cout << "AMateria *B = A->clone();" << '\n';

	AMateria	*B = A->clone();

	std::cout << "delete A;" << '\n';
	delete A;
	std::cout << "type = " << B->getType() << std::endl;
	delete B;
}

static void	character(void)
{
	std::cout << "Character A;" << std::endl;

	Character	A;

	A.equip(new Ice());
	for (int i = 0; i < INVENTORYSLOTS; i++)
		if (A.getSlot(i) != NULL)
			std::cout << "Inventory Slot " << i << " : " << A.getSlot(i)->getType() << std::endl;
}

int	main(void)
{
		line();
	ice();
		line();
	cure();
		line();
	character();
		line();
/*tester Character A avec 0 items = Character B avec full items*/
	return (0);
}
