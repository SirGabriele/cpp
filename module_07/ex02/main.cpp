/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:18:13 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/06 17:01:36 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <ctime>
#include <cstdlib>
#define MAX_VAL 750

static void	mainSchool(void)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    std::srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return ; 
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = std::rand();
    }
    delete [] mirror;
}

int	main(void)
{
    std::srand(time(NULL));

	Array<int>	a;
	std::cout << "a:\nsize = " << a.size() << '\n';
	try
	{
		std::cout << "a[" << 0 << "] = " << a[0] << '\n';
	}
	catch(std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	std::cout << std::endl;


	Array<int>	b(10);
	for (int i = 0; i < 10; i++)
		b[i] = std::rand();
	std::cout << "b:\nsize = " << b.size() << '\n';
	for (int i = 0; i < 10; i++)
		std::cout << "b[" << i << "] = " << b[i] << '\n';
	std::cout << std::endl;


	std::cout << "b = a" << '\n';
	b = a;
	std::cout << "b:\nsize = " << b.size() << '\n';
	try
	{
		for (int i = 0; i < 10; i++)
			std::cout << "b[" << i << "] = " << b[i] << '\n';
	}
	catch(std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	std::cout << std::endl;


	Array<int>	c(5);
	for (int i = 0; i < 5; i++)
		c[i] = std::rand();
	Array<int>	d(c);
	try
	{
		std::cout << "c:\nsize = " << c.size() << '\n';
		std::cout << "d:\nsize = " << d.size() << '\n';
		for (int i = 0; i < 5; i++)
		{
			std::cout << "c[" << i << "] = " << c[i] << '\n';
			std::cout << "d[" << i << "] = " << d[i] << '\n';
		}
	}
	catch(std::exception &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	mainSchool();
	return (0);
}
