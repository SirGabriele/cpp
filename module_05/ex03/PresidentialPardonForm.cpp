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

void	PresidentialPardonForm::beSigned(Bureaucrat &employee)
{
	if (employee.getGrade() > (unsigned int)this->_minGradeToSign)
		throw GradeTooLowException("This bureaucrat could not sign the form.");
	else
		this->_isSigned = true;
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	std::cout << executor.getName() << " has been pardonned by Zaphod Beeblebrox." << std::endl;
	std::cout << executor.getName() << " executed " << this->_name << std::endl;
}
