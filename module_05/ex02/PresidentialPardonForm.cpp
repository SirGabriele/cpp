/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:47:00 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/18 18:09:13 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", false, 25, 5)
{
	this->_target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", false, 25, 5)

{
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src): AForm("PresidentialPardonForm", false, 25, 5)
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{

}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
	{
		this->_isSigned = src._isSigned;
		this->_target = src._target;
	}
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->_isSigned == false)
	{
		std::cout << "This form has not been signed yet. Therefore it can not be executed" << std::endl;
		return ;
	}
	else if (executor.getGrade() > (unsigned int)this->_minGradeToExecute)
		throw GradeTooLowException("This bureaucrat could not execute the form.");

	std::cout << this->_target << " has been pardonned by Zaphod Beeblebrox." << std::endl;
	std::cout << executor.getName() << " executed " << this->_name << std::endl;
}
