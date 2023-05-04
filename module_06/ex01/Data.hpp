/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:15:48 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/01 14:36:31 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DATA_HPP
# define DATA_HPP

# include <string>

class	Data
{
	public:
		Data(void);
		Data(const std::string &name, int age, bool alive);
		Data(const Data &src);
		~Data(void);

		Data	&operator=(const Data &src);

		const std::string	&getName(void) const;
		void				setName(const std::string &);
		int					getAge(void) const;
		void				setAge(int);
		bool				getAlive(void) const;
		void				setAlive(bool);

	private:
		std::string	_name;
		int			_age;
		bool		_alive;
};

#endif /*DATA_HPP*/
