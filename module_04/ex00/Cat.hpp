/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:59:35 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/11 19:06:38 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat: public Animal
{
	public:
		Cat(void);
		Cat(const Cat &src);
		~Cat(void);

		Cat	&operator=(const Cat &src);

		virtual void	makeSound(void);
};

#endif /*CAT_HPP*/
