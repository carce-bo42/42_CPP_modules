#include "Account.hpp"
#include <time.h>
#include <iostream>
#include <iomanip>

static void		write_formatted_arg(std::string name, int value, bool endline) {

	std::cout << name << ":" << value;
	if (endline == 1)
		std::cout << std::endl;
	else
		std::cout << ";";
}

Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts), 
										_amount(initial_deposit),
										_nbDeposits(0),
										_nbWithdrawals(0) {
	
	Account::_displayTimestamp();
	write_formatted_arg("index", this->_accountIndex, 0);
	write_formatted_arg("amount", this->checkAmount(), 0);
	std::cout << "created" << std::endl;

	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
	return ;
}

Account::Account(void) : _accountIndex(Account::_nbAccounts), 
										_amount(0),
										_nbDeposits(0),
										_nbWithdrawals(0) {
	
	Account::_displayTimestamp();
	write_formatted_arg("index", this->_accountIndex, 0);
	write_formatted_arg("amount", this->checkAmount(), 0);
	std::cout << "created" << std::endl;

	Account::_nbAccounts += 1;
	return ;
}

Account::~Account(void) {

	Account::_displayTimestamp();
	write_formatted_arg("index", this->_accountIndex, 0);
	write_formatted_arg("amount", this->checkAmount(), 0);
	std::cout << "closed" << std::endl;

	return ;

}

void	Account::makeDeposit( int deposit ) {

	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;

	Account::_displayTimestamp();
	write_formatted_arg("index", this->_accountIndex, 0);
	write_formatted_arg("p_amount", this->checkAmount(), 0);
	write_formatted_arg("deposit", deposit, 0);

	this->_amount += deposit;
	Account::_totalAmount += deposit;

	write_formatted_arg("amount", this->checkAmount(), 0);
	write_formatted_arg("nb_deposits", this->_nbDeposits, 1);

}

bool	Account::makeWithdrawal(int withdrawal) {

	Account::_displayTimestamp();
	write_formatted_arg("index", this->_accountIndex, 0);
	write_formatted_arg("p_amount", this->checkAmount(), 0);

	if (withdrawal > this->checkAmount()) {
		std::cout << "withdrawal:refused" << std::endl;
		return 1 ;
	}
	else {

		this->_nbWithdrawals += 1;
		Account::_totalNbWithdrawals += 1;

		write_formatted_arg("withdrawal", withdrawal, 0);

		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;

		write_formatted_arg("amount", this->checkAmount(), 0);
		write_formatted_arg("nb_withdrawals", this->_nbWithdrawals, 1);

		return 0 ;

	}
}

void	Account::displayAccountsInfos(void) {

	Account::_displayTimestamp();
	write_formatted_arg("accounts", Account::getNbAccounts(), 0);
	write_formatted_arg("total", Account::getTotalAmount(), 0);
	write_formatted_arg("deposits", Account::getNbDeposits(), 0);
	write_formatted_arg("withdrawals", Account::getNbWithdrawals(), 1);

}

void	Account::displayStatus(void) const {

	Account::_displayTimestamp();
	write_formatted_arg("index",  this->_accountIndex, 0);
	write_formatted_arg("amount", this->checkAmount(), 0);
	write_formatted_arg("deposits", this->_nbDeposits, 0);
	write_formatted_arg("withdrawals", this->_nbWithdrawals, 1);

}

void	Account::_displayTimestamp(void) {

	std::time_t	now = time(0);
	std::tm	*ltm = std::localtime(&now);

	std::cout << "[";
	std::cout << ltm->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << ltm->tm_mon + 1;;
	std::cout << std::setfill('0') << std::setw(2) << ltm->tm_mday;
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << ltm->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << ltm->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << ltm->tm_sec;
	std::cout << "] ";
	return ;
}

int	Account::checkAmount(void) const {

	return this->_amount ;

}

int	Account::getNbAccounts(void) {

	return Account::_nbAccounts ;

}

int	Account::getTotalAmount(void) {

	return Account::_totalAmount ;

}

int	Account::getNbDeposits(void) {

	return Account::_totalNbDeposits ;

}

int	Account::getNbWithdrawals(void) {

	return Account::_totalNbWithdrawals ;

}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
