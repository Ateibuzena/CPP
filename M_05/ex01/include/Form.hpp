#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <sstream>

class Bureaucrat;

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
        Form&               operator=(const Form& object); //anybody must use it

                            ~Form();

        const std::string&  getName(void) const;
        bool                getSigned(void) const;
        int                 getWriteGrade(void) const;
        int                 getExecuteGrade(void) const;
        
        /*void                setName(const std::string& nameValue);*/ //name is immutable
        /*void                setWriteGrade(const int);*/ //writegrade is immutable
        /*void                setExecuteGrade(const int);*/ //executegrade is immutable
        /*void                setSigned(bool signedValue);*/ //can't be set by the face

        void                beSigned(const Bureaucrat &object);

        class GradeTooHighException : public std::exception
        {
            private:
                std::string _msg;
            public:
                            GradeTooHighException(const std::string& name, int writeGrade);
                            ~GradeTooHighException() throw();
                const char* what(void) const throw();
        };

        class GradeTooLowException : public std::exception
        {
            private:
                std::string _msg;
            public:
                            GradeTooLowException(const std::string& name, int writeGrade);
                            ~GradeTooLowException() throw();
                const char* what(void) const throw();
        };
};

std::ostream&   operator<<(std::ostream& fd, const Form& object);

# endif