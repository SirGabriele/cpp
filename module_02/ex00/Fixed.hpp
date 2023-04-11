/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:38:49 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/04 19:40:19 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &src);
		~Fixed(void);
		Fixed &operator=(const Fixed &src);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		static int const	_binaryPoint = 8;
		int					_value;
};

#endif /*FIXED_HPP*/
