/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:07:49 by kbrousse          #+#    #+#             */
/*   Updated: 2023/04/24 10:11:18 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

# include <exception>
# include <string>
# include <iostream>
# include "AForm.hpp"

class	Intern
{
	public:
		Intern(void);
		Intern(const Intern &src);
		~Intern(void);

		Intern	&operator=(const Intern &src);

		AForm	*makeForm(std::string form, std::string target);

	/*	START OF EXCEPTIONS	*/
	class	StringIsEmpty : public std::exception
	{
		public:
			StringIsEmpty(void) throw();
			~StringIsEmpty(void) throw();
			const char	*what(void) const throw();

		private:
			const std::string	_errorMsg;
	};

	class	StringIsInvalid : public std::exception
	{
		public:
			StringIsInvalid(void) throw();
			~StringIsInvalid(void) throw();
			const char	*what(void) const throw();

		private:
			const std::string	_errorMsg;
	};
	/*	END OF EXCEPTIONS	*/
};

#endif /*INTERN_HPP*/
