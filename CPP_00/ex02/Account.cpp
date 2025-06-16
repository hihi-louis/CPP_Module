/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:42:16 by tripham           #+#    #+#             */
/*   Updated: 2025/06/16 18:27:57 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

/*initialize static variable*/
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*Constructor
initialization List for initialize an account with an initialize deposits*/
Account::Account(int initial_deposit)
:
	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << initial_deposit;
	std::cout << ";created" << std::endl;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
}

/*std::strftime(char* buffer, std::size_t maxSize, 
	const char* format, const std::tm* timeStruct);
	std::tm* localtime(const time_t* timer); => that's why have to use &atTheMoment;
	Using new to malloc, and delete[] to free
*/
void	Account::_displayTimestamp( void )
{
	char *buffer = new char[20];
	std::time_t atTheMoment = std::time(0);
	std::tm* timeinfo = std::localtime(&atTheMoment);
	std::strftime(buffer, 20, "%Y%m%d_%H%M%S", timeinfo);
	std::cout << "[" << buffer << "] ";
	delete[] buffer;
}

int Account::getNbAccounts( void ) {return _nbAccounts;}
int Account::getTotalAmount( void ) {return _totalAmount;}
int Account::getNbDeposits( void ) {return _totalNbDeposits;}
int Account::getNbWithdrawals( void ) {return _totalNbWithdrawals;}
void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout  << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

/*Purpose of makeDeposit function:
Call _displayTimestamp()
Print index, p_amount (money before deposit)
Add deposit to _amount
Update _nbDeposits and _totalNbDeposits
Print result log: deposit, amount, nb_deposits*/
void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

int Account::checkAmount( void ) const {return _amount;}

/*Function Goal:
If funds are sufficient:
	Subtract withdrawal from _amount
	Update _nbWithdrawals, _totalAmount, _totalNbWithdrawals
	Print detailed log
If funds are insufficient:
	Print refused log
	Do not change data*/
bool Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	if (withdrawal <= checkAmount())
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;

		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << _amount;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
	else
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
}
/*Function Purpose:
Print information of a specific account:
index – account number
amount – current balance
deposits – number of deposits
withdrawals – number of withdrawals
With timestamp at the beginning of the line
Do not change data → use const*/
void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << checkAmount();
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

Account::Account(void) {}