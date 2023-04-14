/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:53:28 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/14 17:20:54 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include <string>
# include <iostream>

# define MEMORYSLOTS 4

class	MateriaSource: public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &src);
		~MateriaSource(void);

		MateriaSource	&operator=(const MateriaSource &src);
		void			learnMateria(AMateria *src);

	private:
		AMateria	*_memory[MEMORYSLOTS];
		AMateria	*createMateria(const std::string &type);
};

#endif /*MATERIASOURCE_HPP*/
