#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP

# include <iostream>
# include <ctime>

class   Account
{
    public:

        Account(int initial_deposit);
        ~Account();

        void        makeDeposit(int deposit);
        bool        makeWithdrawal(int withdrawal);
        int         checkAmount(void) const;
        void        displayStatus(void) const;

        static void displayAccountInfos(void);

    private:

        static int  _nbAccounts;
        static int  _totalAmount;
        static int  _totalNbDeposits;
        static int  _total_NbWithdrawals;

        static void _displayTimestamp(void);

        int         _accountIndex;
        int         _amount;
        int         _nbDeposits;
        int         _nbWithdrawals;
};

#endif