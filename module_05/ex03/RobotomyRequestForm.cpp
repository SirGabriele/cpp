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
	{
		this->_isSigned = src._isSigned;
		this->_target = src._target;
	}
	return (*this);
}

void	RobotomyRequestForm::beSigned(Bureaucrat &employee)
{
	if (employee.getGrade() > (unsigned int)this->_minGradeToSign)
		throw GradeTooLowException("This bureaucrat could not sign the form.");
	else
		this->_isSigned = true;
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	std::srand(std::time(NULL));

	int	randomValue = std::rand();

	if (randomValue % 2 == 0)
		std::cout << executor.getName() << " has been robotomized successfully." << std::endl;
	else
		std::cout << executor.getName() << "'s robotomy failed." << std::endl;
	std::cout << executor.getName() << " executed " << this->_name << std::endl;
}
