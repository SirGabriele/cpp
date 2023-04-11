/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:29:43 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/13 16:56:59 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	obj;

	obj.complain("debug");
	obj.complain("info");
	obj.complain("warning");
	obj.complain("error");
	obj.complain("doesnt exist");
	return (0);
}
