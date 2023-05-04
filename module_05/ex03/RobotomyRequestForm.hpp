/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:42:38 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/18 18:10:56 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		~RobotomyRequestForm(void);

		RobotomyRequestForm	&operator=(const RobotomyRequestForm &src);

		virtual void	execute(const Bureaucrat &executor) const;
	
	private:
		std::string	_target;
};

#endif /*ROBOTOMYREQUESTFORM_HPP*/
