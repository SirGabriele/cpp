/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:53:34 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/14 17:21:10 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < MEMORYSLOTS; i++)
		this->_memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < MEMORYSLOTS; i++)
		delete this->_memory[i];
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &src)
{
	if (this != &src)
	{
		for (int i = 0; i < MEMORYSLOTS; i++)
		{
			if (this->_memory[i] != NULL)
				delete this->_memory[i];
			if (src._memory[i] != NULL)
				this->_memory[i] = src._memory[i]->clone();
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *src)
{
	int i = 0;

	while (i < MEMORYSLOTS && this->_memory[i] != NULL)
		i++;
	if (i == MEMORYSLOTS)
	{
		std::cerr << "Can not memorise another Materia for the current memory is full" << std::endl;
		delete src;
		return ;
	}
	else
		this->_memory[i] = src;
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	AMateria	*m;
	int 		i = 0;
	int			save = -1;
	
	while (i < MEMORYSLOTS && this->_memory[i] != NULL)
	{
		if (this->_memory[i]->getType() == type)
			save = i;
		i++;
	}
	if (save == -1)
		return (NULL);
	else
		m = this->_memory[save]->clone();
	return (m);
}
