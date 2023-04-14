/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:34:38 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/14 17:01:29 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <string>
# include <iostream>

class	AMateria;

class	IMateriaSource
{
	public:
		virtual	~IMateriaSource();
		virtual AMateria	*createMateria(const std::string &type) = 0;
		virtual void		learnMateria(AMateria *src) = 0;
};

#endif /*IMATERIASOURCE_HPP*/
