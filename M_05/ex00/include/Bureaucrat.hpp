#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class   Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
    
    public:
                            Bureaucrat();
                            Bureaucrat(const std::string& nameValue, int gradeValue);
                            Bureaucrat(const Bureaucrat& object);
        Bureaucrat&         operator=(const Bureaucrat& object);

                            ~Bureaucrat();

        const std::string&  getName(void) const;
        int                 getGrade(void) const;
        
        /*void                setName(const std::string& nameValue);*/ //name is immutable
        void                setGrade(int gradeValue);

        void                incrementGrade(void);
        void                decrementGrade(void);

        class GradeTooHighException : public std::exception
        {
            public:
                            GradeTooHighException();
                            ~GradeTooHighException() throw();
                const char* what(void) const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                            GradeTooLowException();
                            ~GradeTooLowException() throw();
                const char* what(void) const throw();
        };
};

std::ostream&   operator<<(std::ostream& fd, const Bureaucrat& object);

# endif