/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:10:53 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/17 19:52:18 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class	Form
{
	public:
		Form(void);
		Form(std::string name, bool isSigned, const int minGradeToSign, const int minGradeToExecute);
		Form(const Form &src);
		~Form(void);

		Form	&operator=(const Form &src);

		const std::string	&getName(void) const;
		bool				getSignStatus(void) const;
		void				setSignStatus(bool status);
		int					getMinGradeToSign(void) const;
		int					getMinGradeToExecute(void) const;

		void	beSigned(Bureaucrat &employee);

	private:
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

std::ostream	&operator<<(std::ostream &out, const Form &src);

#endif /*FORM_HPP*/
