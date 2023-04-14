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
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

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

static void	inventory(void)
{
//	return ;
	std::cout << "Character A(\"Mickey Mouse\");" << std::endl;

	Character	A("Mickey Mouse");

	std::cout << "A's name is : " << A.getName() << std::endl;
	std::cout << "A.equip(new Ice());" << std::endl;
	std::cout << "A.equip(new Ice());" << std::endl;
	A.equip(new Ice());
	A.equip(new Ice());
	std::cout << "A.equip(new Cure());" << std::endl;
	std::cout << "A.equip(new Cure());" << std::endl;
	A.equip(new Cure());
	A.equip(new Cure());
/*
	Will induce a memory leak since the subject says:
		In case they try to add a Materia to a full inventory, or use/unequip an unexisting Materia, don’t do anything
*/
/*
	std::cout << "A.equip(new Cure());" << std::endl;
	A.equip(new Cure());
*/
	for (int i = 0; i < INVENTORYSLOTS; i++)
		if (A.getSlot(i) != NULL)
			std::cout << "Inventory Slot " << i << " : " << A.getSlot(i)->getType() << std::endl;
		else
			std::cout << "Inventory Slot " << i << " : empty" << std::endl;

	std::cout << "Trying to access the slot number 4, the index of which is incorrect" << std::endl;
	const AMateria	*B = A.getSlot(4);
	if (B != NULL)
		std::cout << "Inventory Slot 4 : " << B->getType() << std::endl;


	line();


	Character	C("Pagia");
	A.use(0, C);
	A.use(1, C);
	A.use(2, C);
	A.use(3, C);
	A.use(4, C);

	
	line();


	const AMateria	*one;
	const AMateria	*two;
	const AMateria	*three;
	const AMateria	*four;

	one = A.getSlot(0);
	two = A.getSlot(1);
	three = A.getSlot(2);
	four = A.getSlot(3);
	std::cout << "Unequipping slots 0 to 3" << std::endl;
	A.unequip(0);
	A.unequip(1);
	A.unequip(2);
	A.unequip(3);
	for (int i = 0; i < INVENTORYSLOTS; i++)
		if (A.getSlot(i) != NULL)
			std::cout << "Inventory Slot " << i << " : " << A.getSlot(i)->getType() << std::endl;
		else
			std::cout << "Inventory Slot " << i << " : empty" << std::endl;

	std::cout << "Trying to unequip the slot number 0, the index of which is already empty" << std::endl;
	A.unequip(0);
	std::cout << "Trying to unequip the slot number 4, the index of which is incorrect" << std::endl;
	A.unequip(4);

	
	line();


	C.equip(new Cure());
	C.equip(new Ice());
	C.equip(new Cure());
	C.equip(new Ice());
	A = C;
	for (int i = 0; i < INVENTORYSLOTS; i++)
		if (A.getSlot(i) != NULL)
			std::cout << "Inventory Slot " << i << " : " << A.getSlot(i)->getType() << std::endl;
		else
			std::cout << "Inventory Slot " << i << " : empty" << std::endl;

	delete one;
	delete two;
	delete three;
	delete four;
}

static void	materiaSource(void)
{
//	return ;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

int	main(void)
{
		line();
	ice();
		line();
	cure();
		line();
	inventory();
		line();
	materiaSource();
		line();
	return (0);
}
