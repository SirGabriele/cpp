/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:18:49 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/05 13:59:34 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ITER_HPP
# define ITER_HPP

/*
Implement a function template iter that takes 3 parameters and returns nothing.
• The first parameter is the address of an array.
• The second one is the length of the array.
• The third one is a function that will be call on every element of the array.
*/
template<typename A, typename B, typename C>
void	iter(A* add, B length, C func)
{
	for (B i = 0; i < length; i++)
		func(add->at(i));
}

#endif /*ITER_HPP*/
