/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:50:28 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/05 12:14:55 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WHATEVER_HPP
# define WHATEVER_HPP

/*
• swap: Swaps the values of two given arguments. Does not return anything.
*/
template<typename A>
void	swap(A& x, A& y)
{
	A	temp;

	temp = x;
	x = y;
	y = temp;
}

/*
• min: Compares the two values passed in its arguments and returns the smallest
one. If the two of them are equal, then it returns the second one.
*/
template<typename A>
A	&min(A& x, A& y)
{
	return (x < y ? x : y);
}

/*
• max: Compares the two values passed in its arguments and returns the greatest one.
If the two of them are equal, then it returns the second one.
*/
template<typename A>
A	&max(A&x, A&y)
{
	return (x > y ? x : y);
}

#endif /*WHATEVER_HPP*/
