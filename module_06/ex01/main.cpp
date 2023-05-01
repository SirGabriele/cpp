/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:09:48 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/01 14:47:27 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	/*testing serialization*/
	Data		originSample("Michel", 47, true);
	std::cout << std::boolalpha << "originSample:\n"
			<< originSample.getName() << '\n'
			<< originSample.getAge() << '\n'
			<< originSample.getAlive() << "\n\n";
	
	uintptr_t	raw = Serializer::serialize(&originSample);

	Data		*newSample = Serializer::deserialize(raw);
	std::cout << "newSample:\n"
			<< newSample->getName() << '\n'
			<< newSample->getAge() << '\n'
			<< newSample->getAlive() << "\n\n";
	
	originSample.setName("Vercingetorix");
	originSample.setAge(2105);
	originSample.setAlive(false);

	std::cout << "originSample:\n"
			<< originSample.getName() << '\n'
			<< originSample.getAge() << '\n'
			<< originSample.getAlive() << "\n\n";

	std::cout << "newSample:\n"
			<< newSample->getName() << '\n'
			<< newSample->getAge() << '\n'
			<< newSample->getAlive() << "\n\n";

	/*testing assignment operator overload*/
	originSample.setName("Gad Elmaleh");
	originSample.setAge(52);
	originSample.setAlive(true);

	*newSample = originSample;

	std::cout << "originSample:\n"
			<< originSample.getName() << '\n'
			<< originSample.getAge() << '\n'
			<< originSample.getAlive() << "\n\n";

	std::cout << "newSample:\n"
			<< newSample->getName() << '\n'
			<< newSample->getAge() << '\n'
			<< newSample->getAlive() << "\n\n";
	
	/*testing copy constructor*/
	originSample.setName("Vnaud");
	originSample.setAge(24);
	originSample.setAlive(true);

	*newSample = Data(originSample);

	std::cout << "originSample:\n"
			<< originSample.getName() << '\n'
			<< originSample.getAge() << '\n'
			<< originSample.getAlive() << "\n\n";

	std::cout << "newSample:\n"
			<< newSample->getName() << '\n'
			<< newSample->getAge() << '\n'
			<< newSample->getAlive() << std::endl;
	
	return (0);
}
