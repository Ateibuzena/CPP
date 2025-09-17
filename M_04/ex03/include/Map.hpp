#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "Character.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

# define WIDTH 10
# define HEIGHT 10
# define MATERIAS 6

class   Map
{
    private:
        AMateria*   _grid[HEIGHT][WIDTH];
        std::string _world;

    public:
                            Map();
                            Map(const std::string& worldValue);
                            Map(const Map& object);
        Map&                operator=(const Map& object);

                            ~Map();

        const std::string&  getWorld(void) const;
        AMateria*           getMateria(int x, int y) const;

        void                setWorld(const std::string& worldValue);
        void                setMateria(AMateria* materiaValue, int x, int y);
        
        void                showMap(Character* players[], int playersSize, Character* enemies[], int enemiesSize);
};

#endif