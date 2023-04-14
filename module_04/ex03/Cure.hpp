/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:10:45 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/13 18:30:28 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class	Cure: public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &src);
		~Cure(void);

		Cure	&operator=(const Cure &src);

		virtual AMateria	*clone(void) const;
};

#endif /*CURE_HPP*/
