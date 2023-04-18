/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:10:57 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/18 16:30:09 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void): _name("Default"), _isSigned(false), _minGradeToSign(75), _minGradeToExecute(75)
{

}

AForm::AForm(std::string name, bool isSigned, const int minGradeToSign, const int minGradeToExecute): _name(name), _isSigned(isSigned), _minGradeToSign(minGradeToSign), _minGradeToExecute(minGradeToExecute)
{
	if (this->_minGradeToSign < 1 || this->_minGradeToExecute < 1)
		throw GradeTooHighException("This form's grades are not valid.");
	else if (this->_minGradeToSign > 150 || this->_minGradeToExecute > 150)
		throw GradeTooLowException("This form's grades are not valid.");
}

AForm::AForm(const AForm &src): _name(src.getName()), _isSigned(src.getSignStatus()), _minGradeToSign(src.getMinGradeToSign()), _minGradeToExecute(src.getMinGradeToExecute())
{
	*this = src;
}

AForm::~AForm(void)
{

}

AForm	&AForm::operator=(const AForm &src)
{
	if (this != &src)
	{
		this->_isSigned = src._isSigned;
	}
	return (*this);
}

const std::string	&AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSignStatus(void) const
{
	return (this->_isSigned);
}

void	AForm::setSignStatus(bool status)
{
	this->_isSigned = status;
}

int	AForm::getMinGradeToSign(void) const
{
	return (this->_minGradeToSign);
}

int AForm::getMinGradeToExecute(void) const
{
	return (this->_minGradeToExecute);
}

AForm::GradeTooHighException::GradeTooHighException(void) throw(): _errorMsg("Grade is too high.")
{

}

AForm::GradeTooHighException::GradeTooHighException(std::string error) throw(): _errorMsg(error + " Grade is too high.")
{

}

AForm::GradeTooHighException::~GradeTooHighException(void) throw()
{

}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return (this->_errorMsg.c_str());
}

AForm::GradeTooLowException::GradeTooLowException(void) throw(): _errorMsg("Grade is too low.")
{

}

AForm::GradeTooLowException::GradeTooLowException(std::string error) throw(): _errorMsg(error + " Grade is too low.")
{

}

AForm::GradeTooLowException::~GradeTooLowException(void) throw()
{

}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return (this->_errorMsg.c_str());
}

std::ostream	&operator<<(std::ostream &out, const AForm &src)
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
