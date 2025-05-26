#include "../include/PhoneBook.hpp"
#include <iostream>
#include <string>

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


void    promptContact(Contact &contact)
{
    std::string input;

    std::cout << "First Name: ";
    std::getline(std::cin, input);
    contact.setFirstName(input);

    std::cout << "Last Name: ";
    std::getline(std::cin, input);
    contact.setLastName(input);

    std::cout << "Nickname: ";
    std::getline(std::cin, input);
    contact.setNickName(input);

    std::cout << "Phone Number: ";
    std::getline(std::cin, input);
    contact.setPhoneNumber(input);

    std::cout << "Darkest Secret: ";
    std::getline(std::cin, input);
    contact.setDarkestSecret(input);
}

int main(void)
{
    PhoneBook   phoneBook;
    std::string temp;
    std::string command;

    while (1)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, temp);

        size_t i = 0;

        command.clear();
        while (i < temp.length())
        {
            command += std::toupper(temp[i]);
            i++;
        }
        if (command == "ADD")
        {
            Contact contact;

            promptContact(contact);
            phoneBook.addContact(contact);
        }
        else if (command == "SEARCH")
        {
            phoneBook.displayContacts();
            std::cout << "Enter index to view details: ";

            int index;

            std::cin >> index;
            clearInputBuffer();
            phoneBook.displayContactDetails(index);
        }
        else if (command == "EXIT")
            return (0);
        else
            std::cout << command << " : command not found." << std::endl;
    }
    return (0);
}
