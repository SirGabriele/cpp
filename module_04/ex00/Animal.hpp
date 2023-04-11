/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:37:26 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/11 19:16:33 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class	Animal
{
	public:
		Animal(void);
		Animal(const Animal &src);
		virtual ~Animal(void);

		Animal	&operator=(const Animal &src);

		virtual void	makeSound(void);

		std::string	getType(void);

	protected:
		std::string	type;
};

#endif /*ANIMAP_HPP*/
