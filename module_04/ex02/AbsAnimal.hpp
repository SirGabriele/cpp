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
#ifndef ABSANIMAL_HPP
# define ABSANIMAL_HPP

# include <string>
# include <iostream>
# define ARR_SIZE 6

class	AbsAnimal
{
	public:
		AbsAnimal(void);
		AbsAnimal(const AbsAnimal &src);
		virtual ~AbsAnimal(void);

		AbsAnimal	&operator=(const AbsAnimal &src);

		virtual void	makeSound(void) = 0;

		std::string	getType(void);

	protected:
		std::string	type;
};

#endif /*AbsANIMAP_HPP*/
