/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:19:05 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/11 19:21:48 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class	WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &src);
		virtual ~WrongAnimal(void);

		WrongAnimal	&operator=(const WrongAnimal &src);

		void	makeSound(void);

		std::string	getType(void);

	protected:
		std::string	type;
};

#endif /*WRONGANIMAP_HPP*/
