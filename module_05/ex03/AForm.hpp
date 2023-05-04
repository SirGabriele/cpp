/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:10:53 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/18 16:21:16 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	public:
		AForm(void);
		AForm(std::string name, bool isSigned, const int minGradeToSign, const int minGradeToExecute);
		AForm(const AForm &src);
		virtual ~AForm(void);

		AForm	&operator=(const AForm &src);

		const std::string	&getName(void) const;
		bool				getSignStatus(void) const;
		void				setSignStatus(bool status);
		int					getMinGradeToSign(void) const;
		int					getMinGradeToExecute(void) const;

		virtual void	beSigned(Bureaucrat &employee);
		virtual	void	execute(const Bureaucrat &executor) const = 0;

	protected:
		const std::string	_name;
		bool				_isSigned;
		const int			_minGradeToSign;
		const int			_minGradeToExecute;

	/*	START OF EXCEPTIONS	*/
	class	GradeTooHighException : public std::exception
	{
		public:
			GradeTooHighException(void) throw();
			GradeTooHighException(std::string error) throw();
			~GradeTooHighException(void) throw();
			const char	*what(void) const throw();

		private :
			const std::string	_errorMsg;
	};

	class	GradeTooLowException : public std::exception
	{
		public:
			GradeTooLowException(void) throw();
			GradeTooLowException(std::string error) throw();
			~GradeTooLowException(void) throw();
			const char	*what(void) const throw();

		private :
			const std::string	_errorMsg;
	};
	/*	END OF EXCEPTIONS	*/
};

std::ostream	&operator<<(std::ostream &out, const AForm &src);

#endif /*AFORM_HPP*/
