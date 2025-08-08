#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class   Harl
{
    private:
        std::string         _className;
        static void         (Harl::*_ft[4])(void);
        static std::string  _levels[4];
        
        void                debug(void);
        void                info(void);
        void                warning(void);
        void                error(void);
    
    public:
                            Harl();
                            ~Harl();
        void                complain(const std::string level);
};

#endif