#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <sstream>
# include "AForm.hpp"

class Bureaucrat;

class   PresidentialPardonForm: public AForm
{
    private:
        std::string                 _target;
    public:
                                    PresidentialPardonForm();
                                    PresidentialPardonForm(const std::string& targetValue);
                                    PresidentialPardonForm(const PresidentialPardonForm& object);
        PresidentialPardonForm&     operator=(const PresidentialPardonForm& object); //anybody must use it

        virtual                     ~PresidentialPardonForm();

        const std::string&          getTarget(void) const;

        void                        setTarget(const std::string& targetValue);

        void                        execute(const Bureaucrat& object) const;
};

/*std::ostream&   operator<<(std::ostream& fd, const PresidentialPardonForm& object);*/

# endif