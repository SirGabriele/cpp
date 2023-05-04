/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:16:30 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/18 17:00:30 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "fstream"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", false, 145, 137)
{
	this->_target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", false, 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): AForm("ShrubberyCreationForm", false, 145, 137)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{

}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		this->_isSigned = src._isSigned;
		this->_target = src._target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (this->_isSigned == false)
	{
		std::cout << "This form has not been signed yet. Therefore it can not be executed" << std::endl;
		return ;
	}
	else if (executor.getGrade() > (unsigned int)this->_minGradeToExecute)
		throw GradeTooLowException("This bureaucrat could not execute the form.");

	std::ofstream			outfile;
	std::string				fileName;
	fileName = this->_target + "_shrubbery";

	outfile.open(fileName.c_str(), std::ios::app);
	outfile << "          &&& &&  & &&\n"
			<< "      && &\\/&\\|& ()|/ @, &&\n"
			<< "      &\\/(/&/&||/& /_/)_&/_&\n"
			<< "  &() &\\/&|()|/&\\/ '%\" & ()\n"
			<< "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
			<< "&&   && & &| &| /& & % ()& /&&			       ###\n"
			<< " ()&_---()&\\&\\|&&-&&--%---()~			      #o###\n"
			<< "     &&     \\|||				    #####o###\n"
			<< "             |||				   #o#\\#|#/###\n"
			<< "             |||				    ###\\|/#o#\n"
			<< "             |||				     # }|{  #\n"
			<< "       , -=-~  .-^- _				       }|{\n" << std::endl;
	outfile.close();
	std::cout << executor.getName() << " executed " << this->_name << std::endl;
}
