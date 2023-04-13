/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:50:13 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/11 18:52:43 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog: public Animal
{
	public:
		Dog(void);
		Dog(const Dog &src);
		~Dog(void);

		Dog	&operator=(const Dog &src);

		void	makeSound(void);

		Brain	&getBrain(void);

	private:
		Brain	*_brain;
};

#endif /*DOG_HPP*/
