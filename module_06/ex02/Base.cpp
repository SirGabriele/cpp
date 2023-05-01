/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:08:41 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/01 17:38:23 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(void)
{

}

Base	*Base::generate(void)
{
	Base	*instance;

	std::srand(std::time(NULL));
	int	randomValue = std::rand() % 3;

	switch(randomValue)
	{
		case 0:
		{
			instance = new A();
			break ;
		}
		case 1:
		{
			instance = new B();
			break ;
		}
		case 2:
		{
			instance = new C();
			break ;
		}
		default :
		{
			instance = NULL;
			break ;
		}
	}
	return (instance);	
}
