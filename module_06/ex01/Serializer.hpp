/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:43:05 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/01 12:38:04 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include "Data.hpp"
# include <stdint.h>

class	Serializer
{
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);

	private:
		Serializer(void);
		Serializer(const Serializer &src);
		~Serializer(void);

		Serializer	&operator=(const Serializer &src);
};

#endif /*SERIALIZER_HPP*/
