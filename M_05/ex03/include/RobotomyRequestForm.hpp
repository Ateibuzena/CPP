#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <sstream>
# include "AForm.hpp"


class Bureaucrat;

class   RobotomyRequestForm: public AForm
{
    private:
        std::string                 _target;
    public:
                                    RobotomyRequestForm();
                                    RobotomyRequestForm(const std::string& targetValue);
                                    RobotomyRequestForm(const RobotomyRequestForm& object);
        RobotomyRequestForm&        operator=(const RobotomyRequestForm& object); //anybody must use it

        virtual                     ~RobotomyRequestForm();

        const std::string&          getTarget(void) const;

        void                        setTarget(const std::string& targetValue);

        void                        execute(const Bureaucrat& object) const;
};

/*std::ostream&   operator<<(std::ostream& fd, const RobotomyRequestForm& object);*/

# endif