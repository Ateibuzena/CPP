#include "../include/Account.hpp"

/*init static atributes*/
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_total_NbWithdrawals = 0;

/*Constructor function*/
Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}

/*Destructor function*/
Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}

/*Public functions*/
void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";deposit:" << deposit
              << std::endl;

    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << "index:" << _accountIndex
              << ";nb_deposits:" << _nbDeposits
              << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount;

    if (withdrawal > _amount)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return (false);
    }

    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _total_NbWithdrawals++;

    std::cout << ";withdrawal:" << withdrawal
              << ";amount" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals
              << std::endl;

    return (true);
}

int Account::checkAmount(void) const
{
    return (_amount);
}

void    Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposit:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

void Account::displayAccountInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
             << ";total:" << _totalAmount
             << ";deposits:" << _totalNbDeposits
             << ":withdrawals:" << _total_NbWithdrawals
             << std::endl;          
}

/*Private functions*/
void    Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);
    std::tm*    time = std::localtime(&now);

    char        buffer[20];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", time);
    std::cout << buffer << " ";
}