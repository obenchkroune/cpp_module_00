#include <Account.hpp>
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
    std::time_t currentTime = std::time(0);
    std::tm *localTime = std::localtime(&currentTime);

    std::cout << "["
       << (localTime->tm_year + 1900)
       << std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1)
       << std::setw(2) << std::setfill('0') << localTime->tm_mday
       << "_"
       << std::setw(2) << std::setfill('0') << localTime->tm_hour
       << std::setw(2) << std::setfill('0') << localTime->tm_min
       << std::setw(2) << std::setfill('0') << localTime->tm_sec
       << "] ";
}

Account::Account(int initial_deposit)
{
    this->_nbDeposits = 0;
    this->_accountIndex = Account::_nbAccounts++;
    this->_amount = initial_deposit;
    this->_nbWithdrawals = 0;
    Account::_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout
        << "index:" << this->_accountIndex << ";"
        << "amount:" << this->_amount << ";"
        << "created" << std::endl;
}

Account::~Account(void)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
        << "amount:" << this->_amount << ";"
        << "closed" << std::endl;
}

int Account::getNbAccounts(void)
{
    return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
    return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";"
        << "total:" << Account::_totalAmount << ";"
        << "deposits:" << Account::_totalNbDeposits << ";"
        << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int amount)
{
    int p_amount = this->_amount;

    this->_nbDeposits++;
    this->_amount += amount;
    Account::_totalNbDeposits++;
    Account::_totalAmount += amount;
    
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
        << "p_amount:" << p_amount << ";"
        << "deposit:" << amount << ";"
        << "amount:" << this->_amount << ";"
        << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int amount)
{
    int p_amount = this->_amount;
    
    if (this->_amount < amount)
    {
        std::cout << "index:" << this->_accountIndex << ";"
            << "p_amount:" << p_amount << ";"
            << "withdrawal:refused" << std::endl;
        return false;
    }
    this->_nbWithdrawals++;
    this->_amount -= amount;
    Account::_totalAmount -= amount;
    Account::_totalNbWithdrawals++;
    
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
        << "p_amount:" << p_amount << ";"
        << "withdrawal:" << amount << ";"
        << "amount:" << this->_amount << ";"
        << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount(void) const
{
    return this->_amount;
}

void Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
        << "amount:" << this->_amount << ";"
        << "deposits:" << this->_nbDeposits << ";"
        << "withdrawals:" << this->_nbWithdrawals << std::endl;
}
