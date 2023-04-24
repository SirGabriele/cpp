/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:10:57 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/17 19:51:48 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void): _name("Default"), _isSigned(false), _minGradeToSign(75), _minGradeToExecute(75)
{

}

Form::Form(std::string name, bool isSigned, const int minGradeToSign, const int minGradeToExecute): _name(name), _isSigned(isSigned), _minGradeToSign(minGradeToSign), _minGradeToExecute(minGradeToExecute)
{
	if (this->_minGradeToSign < 0 || this->_minGradeToExecute < 0)
	{
		std::cerr << "Please provide only positive values to create the form" << std::endl;
		throw GradeTooLowException("Could not create this Form.");
	}
	else if (this->_minGradeToSign == 0 || this->_minGradeToExecute == 0)
		throw GradeTooHighException("Could not create this Form.");
	else if (this->_minGradeToSign > 150 || this->_minGradeToExecute > 150)
		throw GradeTooLowException("Could not create this Form.");
}

Form::Form(const Form &src): _name(src.getName()), _isSigned(src.getSignStatus()), _minGradeToSign(src.getMinGradeToSign()), _minGradeToExecute(src.getMinGradeToExecute())
{
	*this = src;
}

Form::~Form(void)
{

}

Form	&Form::operator=(const Form &src)
{
	if (this != &src)
	{
		this->_isSigned = src._isSigned;
	}
	return (*this);
}

const std::string	&Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSignStatus(void) const
{
	return (this->_isSigned);
}

void	Form::setSignStatus(bool status)
{
	this->_isSigned = status;
}

int	Form::getMinGradeToSign(void) const
{
	return (this->_minGradeToSign);
}

int Form::getMinGradeToExecute(void) const
{
	return (this->_minGradeToExecute);
}

void	Form::beSigned(Bureaucrat &employee)
{
	if (employee.getGrade() > (unsigned int)this->_minGradeToSign)
		throw GradeTooLowException("This bureaucrat could not sign the form.");
	else
		this->_isSigned = true;
}

Form::GradeTooHighException::GradeTooHighException(void) throw(): _errorMsg("Grade is too high.")
{

}

Form::GradeTooHighException::GradeTooHighException(std::string error) throw(): _errorMsg(error + " Grade is too high.")
{

}

Form::GradeTooHighException::~GradeTooHighException(void) throw()
{

}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return (this->_errorMsg.c_str());
}

Form::GradeTooLowException::GradeTooLowException(void) throw(): _errorMsg("Grade is too low.")
{

}

Form::GradeTooLowException::GradeTooLowException(std::string error) throw(): _errorMsg(error + " Grade is too low.")
{

}

Form::GradeTooLowException::~GradeTooLowException(void) throw()
{

}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return (this->_errorMsg.c_str());
}

std::ostream	&operator<<(std::ostream &out, const Form &src)
{
	out << src.getName() << ", form is currently";
	if (src.getSignStatus() == true)
		out << " signed";
	else
		out << " unsigned";
	out << ". It requires a bureaucrat of grade " << src.getMinGradeToSign()
		<< " to be signed, and of grade " << src.getMinGradeToExecute()
		<< " to be executed.";
	return (out);
}
