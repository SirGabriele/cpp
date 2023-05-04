/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:21:25 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/02 15:45:27 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Default"), _grade(75)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade <= 0)
		throw GradeTooHighException("Could not create this Bureaucrat.");
	else if (grade > 150)
		throw GradeTooLowException("Could not create this Bureaucrat.");
	else
		_grade = grade;
}

Bureaucrat::~Bureaucrat(void)
{

}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src._name)
{
	*this = src;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
	{
		this->_grade = src._grade;
	}
	return (*this);
}

const std::string	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

const unsigned int	&Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::promote(void)
{
	if (this->_grade > 1)
		this->_grade--;
	else
		throw GradeTooHighException("Could not promote this Bureaucrat.");
}

void	Bureaucrat::demote(void)
{
	if (this->_grade < 150)
		this->_grade++;
	else
		throw GradeTooLowException("Could not demote this Bureaucrat.");
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void) throw(): _errorMsg("Grade is too high.")
{

}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string error) throw(): _errorMsg(error + " Grade is too high.")
{

}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw()
{

}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (this->_errorMsg.c_str());
}



Bureaucrat::GradeTooLowException::GradeTooLowException(void) throw(): _errorMsg("Grade is too low.")
{

}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string error) throw(): _errorMsg(error + " Grade is too low.")
{

}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw()
{

}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (this->_errorMsg.c_str());
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (out);
}
