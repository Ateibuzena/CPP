#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <algorithm>

class   Brain
{
    private:
        std::string         _ideas[100];
    
    public:
                            Brain();
                            Brain(const std::string (&ideasValue)[100]);
                            Brain(const Brain& object);
        Brain&              operator=(const Brain& object);

                            ~Brain();

        const std::string   (&getIdeas(void) const)[100];

        void                setIdeas(const std::string (&ideasValue)[100]);
};

#endif