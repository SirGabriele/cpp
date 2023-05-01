/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:53:27 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/01 12:13:14 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{

}

Serializer::Serializer(const Serializer &src)
{
	*this = src;
}

Serializer::~Serializer(void)
{

}

Serializer	&Serializer::operator=(const Serializer &src)
{
	(void)src;
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t	serialized = reinterpret_cast<uintptr_t>(ptr);

	return (serialized);
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	Data	*deserialized = reinterpret_cast<Data *>(raw);

	return (deserialized);
}
