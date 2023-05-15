/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:39:41 by kbrousse          #+#    #+#             */
/*   Updated: 2023/05/15 16:44:11 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>

int	main(void)
{
	{
		std::cout << "...Using MutantStack...\n";
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "mstack.top() = " << mstack.top() << '\n';

		mstack.pop();

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		std::cout << "mstack.size() = " << mstack.size() << '\n';

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int>	s(mstack);
		std::cout << "\nstd::stack<int> s(mstack)\n";
		while (s.empty() != true)
		{
			std::cout << s.top() << '\n';
			s.pop();
		}
	}


	{
		std::cout << "\n...Using vector...\n";
		std::vector<int>	mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << "mstack.top() = " << mstack.back() << '\n';

		mstack.pop_back();

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		std::cout << "mstack.size() = " << mstack.size() << '\n';

		std::vector<int>::iterator it = mstack.begin();
		std::vector<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	{
		std::cout << "\n...Using list...\n";
		std::vector<int>	mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << "mstack.top() = " << mstack.back() << '\n';

		mstack.pop_back();

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		std::cout << "mstack.size() = " << mstack.size() << '\n';

		std::vector<int>::iterator it = mstack.begin();
		std::vector<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return 0;
}
