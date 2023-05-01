/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:50:22 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/01 17:38:23 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BASE_HPP

class	Base
{
	public:
		virtual ~Base(void);
		
		Base	*generate(void);
};

#endif /*BASE_HPP*/
