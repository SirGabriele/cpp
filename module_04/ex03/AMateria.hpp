/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:29:06 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/13 17:17:03 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class	ICharacter;

class	AMateria
{
	protected:

	public:
		AMateria(void);
		AMateria(const AMateria &src);
		AMateria(const std::string &type);
		virtual ~AMateria(void);

		AMateria	&operator=(const AMateria &src);

		const std::string	&getType(void) const;

		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);

		protected:
			std::string	_type;
};

#endif /*AMATERIA_HPP*/
