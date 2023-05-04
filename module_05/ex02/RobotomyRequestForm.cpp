/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:44:40 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/18 18:17:47 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", false, 72, 45)
{
	this->_target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", false, 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src): AForm("RobotomyRequestForm", false, 72, 45)
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{

}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (this->getSignStatus() == false)
	{
		std::cout << "This form has not been signed yet. Therefore it can not be executed" << std::endl;
		return ;
	}
	else if (executor.getGrade() > (unsigned int)this->getMinGradeToExecute())
		throw GradeTooLowException("This bureaucrat could not execute the form.");

	int	randomValue = std::rand();

	if (randomValue % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->_target << "'s robotomy failed." << std::endl;
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}
