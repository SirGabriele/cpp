/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:59:25 by kbrousse          #+#    #+#             */
/*   Updated: 2023/02/09 19:04:32 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
	this->_amount = initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << initial_deposit
			<< ";created" << std::endl;
	return ;
}

Account::Account(void)
{
	return ;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << Account::checkAmount()
			<< ";closed" << std::endl;
	Account::_nbAccounts -= 1;
	return ;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
			<< ";total:" << Account::_totalAmount
			<< ";deposits:" << Account::getNbDeposits()
			<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount << ";deposit:" << deposit;
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	Account::_totalAmount += deposit;
	this->_amount += deposit;
	std::cout << ";amount:" << this->_amount
			<< ";nb_deposits:" << this->_nbDeposits << std::endl;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount
			<< ";withdrawal:";
	if (this->_amount >= withdrawal)
	{
		this->_nbWithdrawals += 1;
		Account::_totalNbWithdrawals += 1;
		Account::_totalAmount -= withdrawal;
		this->_amount -= withdrawal;
		std::cout << withdrawal << ";amount:" << this->_amount
								<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	else
		std::cout << "refused" << std::endl;
	return (true);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";deposits:" << this->_nbDeposits
			<< ";withdrawals:" << this->_nbWithdrawals
			<< std::endl;
	return ;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	now;
	std::tm		time;

	now = std::time(NULL);
	time = *std::localtime(&now);
	std::cout << "[" << time.tm_year + 1900
			<< '0' << time.tm_mon + 1
			<< '0' << time.tm_mday
			<< '_' << time.tm_hour
			<< time.tm_min
			<< time.tm_sec << "] ";
}
