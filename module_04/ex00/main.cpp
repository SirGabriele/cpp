/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:30:59 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/13 14:15:47 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

static void	line(void)
{
	std::cout << "\n-------------------------------------------------------------------\n" << std::endl;
}

static void	defaultConstructors(void)
{
//	return ;
	{
		line();
		std::cout << "Animal A;" << '\n';
		Animal	A;
		std::cout << "A.makeSound()" << '\n';
		A.makeSound();
		std::cout << "type = " << A.getType() << '\n';
	}
	{
		line();
		std::cout << "Cat A;" << '\n';
		Cat	A;
		std::cout << "A.makeSound()" << '\n';
		A.makeSound();
		std::cout << "type = " << A.getType() << '\n';
	}
	{
		line();
		std::cout << "Dog A;" << '\n';
		Dog	A;
		std::cout << "A.makeSound()" << '\n';
		A.makeSound();
		std::cout << "type = " << A.getType() << '\n';
	}
	{
		line();
		std::cout << "WrongAnimal A" << '\n';
		WrongAnimal	A;
		std::cout << "A.makeSound()" << '\n';
		A.makeSound();
		std::cout << "type = " << A.getType() << '\n';
	}
	{
		line();
		std::cout << "WrongCat A" << '\n';
		WrongCat	A;
		std::cout << "A.makeSound()" << '\n';
		A.makeSound();
		std::cout << "type = " << A.getType() << '\n';
	}
}

static void	copyConstructors(void)
{
//	return ;
	{
		line();
		std::cout << "Animal *A = new Animal();" << '\n';
		Animal	*A = new Animal();
		std::cout << "Animal B = new Cat();" << '\n';
		Animal *B = new Cat();
		std::cout << "*A = *B;" << '\n';
		*A = *B;
		std::cout << "delete B;" << '\n';
		delete B;
		std::cout << "A.makeSound()" << '\n';
		A->makeSound();
		std::cout << "type = " << A->getType() << '\n';
		delete A;
	}
	{
		line();
		std::cout << "Animal *A = new Animal();" << '\n';
		Animal	*A = new Animal();
		std::cout << "Animal B = new Dog();" << '\n';
		Animal *B = new Dog();
		std::cout << "*A = *B;" << '\n';
		*A = *B;
		std::cout << "delete B;" << '\n';
		delete B;
		std::cout << "A.makeSound()" << '\n';
		A->makeSound();
		std::cout << "type = " << A->getType() << '\n';
		delete A;
	}
	{
		line();
		std::cout << "WrongAnimal *A = new WrongAnimal();" << '\n';
		WrongAnimal	*A = new WrongAnimal();
		std::cout << "WrongAnimal B = new WrongCat();" << '\n';
		WrongAnimal *B = new WrongCat();
		std::cout << "*A = *B;" << '\n';
		*A = *B;
		std::cout << "delete B;" << '\n';
		delete B;
		std::cout << "A.makeSound()" << '\n';
		A->makeSound();
		std::cout << "type = " << A->getType() << '\n';
		delete A;
	}
}

static void	polymorphism(void)
{
//	return ;
	{
		line();
		std::cout << "Animal *A = new Animal()" << '\n';
		Animal	*A = new Animal();
		std::cout << "A.makeSound()" << '\n';
		A->makeSound();
		std::cout << "type = " << A->getType() << '\n';
		delete A;
	}
	{
		line();
		std::cout << "dfkohnfodnhfdphAnimal *A = new Cat()" << '\n';
		Animal	*A = new Cat();
		std::cout << "A.makeSound()" << '\n';
		A->makeSound();
		std::cout << "type = " << A->getType() << '\n';
		delete A;
	}
	{
		line();
		std::cout << "Animal *A = new Dog()" << '\n';
		Animal	*A = new Dog();
		std::cout << "A.makeSound()" << '\n';
		A->makeSound();
		std::cout << "type = " << A->getType() << '\n';
		delete A;
	}
/*	Does not compile since WrongCat does not inherit from Animal class	*/
/*	{
		line();
		std::cout << "Animal *A = new WrongAnimal()" << '\n';
		Animal	*A = new WrongCat();
		std::cout << "A.makeSound()" << '\n';
		A->makeSound();
		std::cout << "type = " << A->getType() << '\n';
		delete A;
	}*/
	{
		line();
		std::cout << "WrongAnimal *A = new WrongCat()" << '\n';
		WrongAnimal	*A = new WrongCat();
		std::cout << "A.makeSound()" << '\n';
		A->makeSound();
		std::cout << "type = " << A->getType() << '\n';
		delete A;
	}
}

static void	deepCopy(void)
{
//	return ;
	{
		line();
		std::cout << "Animal A;" << '\n';
		Animal	A;
		{
			std::cout << "Animal B;" << '\n';
			Animal	B;
			std::cout << "A = B" << std::endl;
			A = B;
		}
		std::cout << "A.makeSound()" << '\n';
		A.makeSound();
		std::cout << "type = " << A.getType() << '\n';
	}
	{
		line();
		std::cout << "Cat A;" << '\n';
		Cat	A;
		{
			std::cout << "Cat B;" << '\n';
			Cat	B;
			std::cout << "A = B" << std::endl;
			A = B;
		}
		std::cout << "A.makeSound()" << '\n';
		A.makeSound();
		std::cout << "type = " << A.getType() << '\n';
	}
	{
		line();
		std::cout << "Dog A;" << '\n';
		Dog	A;
		{
			std::cout << "Dog B" << '\n';
			Dog	B;
			std::cout << "A = B" << std::endl;
			A = B;
		}
		std::cout << "A.makeSound()" << '\n';
		A.makeSound();
		std::cout << "type = " << A.getType() << '\n';
	}
	{
		line();
		std::cout << "WrongAnimal A;" << '\n';
		WrongAnimal	A;
		{
			std::cout << "WrongAnimal B;" << '\n';
			WrongAnimal	B;
			std::cout << "A = B" << std::endl;
			A = B;
		}
		std::cout << "A.makeSound()" << '\n';
		A.makeSound();
		std::cout << "type = " << A.getType() << '\n';
	}
	{
		line();
		std::cout << "WrongCat A;" << '\n';
		WrongCat	A;
		{
			std::cout << "WrongCat B" << '\n';
			WrongCat	B;
			std::cout << "A = B" << std::endl;
			A = B;
		}
		std::cout << "A.makeSound()" << '\n';
		A.makeSound();
		std::cout << "type = " << A.getType() << '\n';
	}
}

int	main(void)
{
	defaultConstructors();
	copyConstructors();
	polymorphism();
	deepCopy();
	line();
	return (0);
}
