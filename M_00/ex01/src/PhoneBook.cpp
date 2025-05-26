#include "../include/PhoneBook.hpp"
#include <iostream>
#include <iomanip>

/*Contructor function*/
PhoneBook::PhoneBook() : _size(0), _oldest(0)
{

}

/*Methods functions*/

void PhoneBook::addContact(const Contact &contact)
{
    _contacts[_oldest] = contact;
    _oldest = (_oldest + 1) % 8;
    if (_size < 8)
        _size++;
}

void PhoneBook::displayContacts() const
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(20) << "First Name" << "|"
              << std::setw(20) << "Last Name" << "|"
              << std::setw(20) << "Nick Name"
              << std::endl;

    int i = 0;
    while (i < _size)
    {
        std::string firstName = _contacts[i].getFirstName();
        std::string lastName = _contacts[i].getLastName();
        std::string nickName = _contacts[i].getNickName();

        if (firstName.length() > 10)
            firstName = firstName.substr(0, 9) + ".";
        if (lastName.length() > 10)
            lastName = lastName.substr(0, 9) + ".";
        if (nickName.length() > 10)
            nickName = nickName.substr(0, 9) + ".";
        
        std::cout << std::setw(10) << i << "|"
                  << std::setw(20) << firstName << "|"
                  << std::setw(20) << lastName << "|"
                  << std::setw(20) << nickName
                  << std::endl;

        i++;
    }
}

void PhoneBook::displayContactDetails(int index) const
{
    if (index < 0 || index >= _size)
    {
        std::cout << "Invalid index." << std::endl;
        return ;
    }

    const Contact &contact = _contacts[index];

    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nick Name: " << contact.getNickName() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}