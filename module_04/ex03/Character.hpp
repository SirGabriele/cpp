/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:44:38 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/13 18:59:22 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# define INVENTORYSLOTS 4

class	Character: public ICharacter
{
	public:
		Character(void);
		Character(const std::string &name);
		Character(const Character &src);
		~Character(void);

		Character	&operator=(const Character &src);

		const AMateria		*getSlot(int i) const;
		const std::string	&getName(void) const;
		void				equip(AMateria *m);
		
//		virtual void				unequip(int idx) = 0;
//		virtual void				use(int idx, ICharacter &target) = 0;

	private:
		AMateria	*_inventory[INVENTORYSLOTS];
		std::string	_name;
};

#endif /*CHARACTER_HPP*/
