#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <sstream>

class Bureaucrat;

class   AForm
{
    private:
        const std::string   _name;
        const int           _writeGrade;
        const int           _executeGrade;
        bool                _signed;
    
    public:
                            AForm();
                            AForm(const std::string& nameValue, int writeGradeValue, int executeGradeValue);
                            AForm(const AForm& object);
        AForm&               operator=(const AForm& object); //anybody must use it

        virtual             ~AForm();

        const std::string&  getName(void) const;
        bool                getSigned(void) const;
        int                 getWriteGrade(void) const;
        int                 getExecuteGrade(void) const;
        
        /*void                setName(const std::string& nameValue);*/ //name is immutable
        /*void                setWriteGrade(const int);*/ //writegrade is immutable
        /*void                setExecuteGrade(const int);*/ //executegrade is immutable
        /*void                setSigned(bool signedValue);*/ //can't be set by the face

        void                beSigned(const Bureaucrat& object);
        virtual void        execute(const Bureaucrat &object) const = 0;

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

std::ostream&   operator<<(std::ostream& fd, const AForm& object);

# endif