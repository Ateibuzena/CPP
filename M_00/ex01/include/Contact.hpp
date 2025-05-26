#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <cctype>

class Contact
{
    public:

        Contact();

        void setFirstName(const std::string &value);
        void setLastName(const std::string &value);
        void setNickName(const std::string &value);
        void setPhoneNumber(const std::string &value);
        void setDarkestSecret(const std::string &value);

        const std::string getFirstName() const;
        const std::string getLastName() const;
        const std::string getNickName() const;
        const std::string getPhoneNumber() const;
        const std::string getDarkestSecret() const;

    private:

        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;

};

#endif