/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:30:59 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/13 16:23:38 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbsAnimal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int	main(void)
{
	{
		AbsAnimal	*A[ARR_SIZE];

		for (int i = 0; i < ARR_SIZE / 2; i++)
			A[i] = new Cat();
		for (int i = ARR_SIZE / 2; i < ARR_SIZE; i++)
			A[i] = new Dog();
		for (int i = 0; i < ARR_SIZE; i++)
			delete A[i];
	}
	{
		Dog	*A = new Dog();

		std::cout << "A brain after construction:" << '\n';
		for (int i = 0; i < 100; i++)
			std::cout << i << " : " << A->getBrain().getIdea(i) << '\n';
		std::string idea = "*";
		std::cout << "Filling A brain..." << '\n';
		for (int i = 0; i < 100; i++)
		{
			A->getBrain().setIdea(i, idea);
			if (i % 2 == 0)
				idea += "~";
			else
				idea += "*";
		}
		std::cout << "Filled A brain :" << '\n';
		for (int i = 0; i < 100; i++)
			std::cout << i << " : " << A->getBrain().getIdea(i) << '\n';

		Dog	*B = new Dog();
		std::cout << "B brain after construction:" << '\n';
		for (int i = 0; i < 100; i++)
			std::cout << i << " : " << B->getBrain().getIdea(i) << '\n';
		std::cout << "*B = *A" << '\n';
		*B = *A;
		std::cout << "delete A" << '\n';
		delete A;
		std::cout << "Filled B brain :" << '\n';
		for (int i = 0; i < 100; i++)
			std::cout << i << " : " << B->getBrain().getIdea(i) << '\n';
		delete B;
	}
	{
/*	Will not compile since AbsAnimal is an abstract class	*/
/*		AbsAnimal	A;

		A.makeSound();*/
	}
	return (0);
}
