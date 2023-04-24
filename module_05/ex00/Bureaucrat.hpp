/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:21:19 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/17 17:19:04 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class	Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name);
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat(void);

		Bureaucrat	&operator=(const Bureaucrat &src);

		const std::string	&getName(void) const;
		const unsigned int	&getGrade(void) const;

		void	promote(void);
		void	demote(void);

		/*	START OF EXCEPTIONS	*/
		class	GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(void) throw();
				GradeTooHighException(std::string error) throw();
				~GradeTooHighException(void) throw();
				const char	*what(void) const throw();

			private:
				const std::string	_errorMsg;
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(void) throw();
				GradeTooLowException(std::string error) throw();
				~GradeTooLowException(void) throw();
				const char	*what(void) const throw();

			private:
				const std::string	_errorMsg;
		};
		/*	END OF EXCEPTIONS	*/

	private:
		const std::string	_name;
		unsigned int		_grade;
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &src);

#endif /*BUREAUCRAT_HPP*/
