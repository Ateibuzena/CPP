#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <sstream>
# include <fstream>
# include "AForm.hpp"

class Bureaucrat;

class   ShrubberyCreationForm: public AForm
{
    private:
        std::string                 _target;
    public:
                                    ShrubberyCreationForm();
                                    ShrubberyCreationForm(const std::string& targetValue);
                                    ShrubberyCreationForm(const ShrubberyCreationForm& object);
        ShrubberyCreationForm&      operator=(const ShrubberyCreationForm& object); //anybody must use it

        virtual                     ~ShrubberyCreationForm();

        const std::string&          getTarget(void) const;

        void                        setTarget(const std::string& targetValue);

        void                        execute(const Bureaucrat& object) const;
};

/*std::ostream&   operator<<(std::ostream& fd, const ShrubberyCreationForm& object);*/

# endif