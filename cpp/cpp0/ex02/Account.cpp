#include "Account.hpp"
#include <iostream>
#include <sys/time.h>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}
int	Account::getTotalAmount( void )
{
	return _totalAmount;
}
int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout<<"accounts:"<<Account::getNbAccounts()<<";total:"<<getTotalAmount()<<";deposits:"<<getNbDeposits()<<";withdrawals:"<<getNbWithdrawals()<<"\n";
}


Account::Account( int initial_deposit ) : _accountIndex(getNbAccounts()), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) 
{
	_totalAmount += _amount;
	_nbAccounts++;
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";created\n";
}
Account::~Account( void ) {
	_totalAmount -= _amount;
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";closed\n";

};

void	Account::makeDeposit( int deposit )
{
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount<<";deposit:"<<deposit<<";amount:";
	_amount += deposit;
	std::cout<<_amount<<";nb_deposits:"<<_nbDeposits<<"\n";
}
bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount<<";withdrawal:refused\n";
		return false;
	}
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount<<";withdrawal:"<<withdrawal;
	_amount -= withdrawal;
	std::cout<<";amount:"<<_amount<<";nb_withdrawals:"<<_nbWithdrawals<<"\n";

	return true;
}
int		Account::checkAmount( void ) const
{
	return _amount;
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";deposits:"<<_nbDeposits<<";withdrawals:"<<_nbWithdrawals<<"\n";
};

void	Account::_displayTimestamp( void )
{
	struct timeval tp;
	gettimeofday(&tp, NULL);
	std::cout<<"["<<tp.tv_sec<<"_"<<tp.tv_usec<<"] ";
};

