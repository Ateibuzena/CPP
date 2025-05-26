#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
    public:

        PhoneBook();

        void addContact(const Contact &contact);
        void displayContacts() const;
        void displayContactDetails(int index) const;

    private:

        Contact _contacts[8];
        int     _size;
        int     _oldest;
};

#endif