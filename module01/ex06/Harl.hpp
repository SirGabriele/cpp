/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:45:42 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/13 17:59:56 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_H
# define HARL_H

# include <string>
# include <iostream>
# define NB_FUNC 4

class	Harl
{
public:

	Harl(void);
	~Harl(void);

	void				complain(std::string level);

private:

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};

#endif /*HARL_H*/
