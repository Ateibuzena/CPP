#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <sstream>

class Form;

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
        /*void                setGrade(int gradeValue);*/ //can't be set by the face

        void                incrementGrade(void);
        void                decrementGrade(void);

        void                signForm(Form& object);

        class GradeTooHighException : public std::exception
        {
            private:
                std::string _msg;
            public:
                            GradeTooHighException(const std::string& name, int grade);
                            ~GradeTooHighException() throw();
                const char* what(void) const throw();
        };

        class GradeTooLowException : public std::exception
        {
            private:
                std::string _msg;
            public:
                            GradeTooLowException(const std::string& name, int grade);
                            ~GradeTooLowException() throw();
                const char* what(void) const throw();
        };
};

std::ostream&   operator<<(std::ostream& fd, const Bureaucrat& object);

# endif