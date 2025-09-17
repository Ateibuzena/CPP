#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class   Form
{
    private:
        const std::string   _name;
        const int           _writeGrade;
        const int           _executeGrade;
        bool                _signed;
    
    public:
                            Form();
                            Form(const std::string& nameValue, int writeGradeValue, int executeGradeValue);
                            Form(const Form& object);
        Form&               operator=(const Form& object) = delete; //anybody can use it

                            ~Form();

        const std::string&  getName(void) const;
        bool                getSigned(void) const;
        const int           getWriteGrade(void) const;
        const int           getExecuteGrade(void) const;
        
        /*void                setName(const std::string& nameValue);*/ //name is immutable
        /*void                setSigned(void);*/ //  is immutable
        /*void                setWriteGrade(const int);*/ // writegrade is immutable
        /*void                setExecuteGrade(const int);*/ // executegrade is immutable
        /*void                setSigned(bool signedValue);*/ //can't be set by the face

        void                beSigned(const Bureaucrat &object);
        void                
        /*void                incrementGrade(void);
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
        };*/
};

/*std::ostream&   operator<<(std::ostream& fd, const Form& object);*/

# endif