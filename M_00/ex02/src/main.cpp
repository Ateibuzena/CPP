#include "../include/Account.hpp"

int clearInputBuffer()
{
    int count = 0;

    while (std::cin.peek() != '\n'
            && std::cin.peek() != std::char_traits<char>::eof())
    {
        std::cin.get();
        ++count;
    }
    if (std::cin.peek() == '\n')
        std::cin.get();
    return (count);
}

void showMenu()
{
    std::cout << "\n=== MENU ===\n"
              << "1. Show global info\n"
              << "2. Create new account\n"
              << "3. Show all accounts\n"
              << "4. Make a deposit\n"
              << "5. Make a withdrawal\n"
              << "6. Exit\n"
              << "Choose an option: ";
}

int main(void)
{
    Account*    accounts[10];
    int         accountCount = 0;
    int         choice;

    do 
    {
        showMenu();
        std::cin >> choice;
        if (std::cin.fail())
        {
            std::cin.clear();
            clearInputBuffer();
            std::cout << "Invalid input. Please enter a number.\n";
            continue ;
        }
        switch (choice)
        {
            case 1:
            {
                Account::displayAccountInfos();
                break ;
            }
            case 2:
            {
                if (accountCount >= 10)
                {
                    std::cout << "Maximun number of account reached. \n";
                    break ;
                }
                int initialDeposit;

                std::cout << "Enter a initial deposit: ";
                std::cin >> initialDeposit;
                accounts[accountCount] = new Account(initialDeposit);
                std::cout << "Account created with index " << accountCount << ".\n";
                accountCount++;
                break ;
            }
            case 3:
            {
                if (accountCount == 0)
                {
                    std::cout << "No accounts created yet.\n";
                    break ;
                }
                int i = 0;
                
                while (i < accountCount)
                {
                    accounts[i]->displayStatus();
                    i++;
                }
                break ;
            }
            case 4:
            {
                int idx, amount;

                std::cout << "Enter account index: ";
                std::cin >> idx;
                std::cout << "Enter deposit amount: ";
                std::cin >> amount;
                if (idx >= 0 && idx < accountCount)
                    accounts[idx]->makeDeposit(amount);
                else
                    std::cout << "Invalid account index.\n";
                break ;
            }
            case 5:
            {
                int idx, amount;

                std::cout << "Enter account index: ";
                std::cin >> idx;
                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;
                if (idx >= 0 && idx < accountCount)
                    accounts[idx]->makeWithdrawal(amount);
                else
                    std::cout << "Invalid account index.\n";
                break ;
            }
            case 6:
            {
                std::cout << "Exiting program...\n";
                break ;
            }
            default:
                std::cout << "Invalid option.\n";
        }

    }
    while (choice != 6);
    
    int i = 0;

    while (i < accountCount)
    {
        delete (accounts[i]);
        i++;
    }
    return (0);
}