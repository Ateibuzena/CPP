#ifndef GAME_HPP
# define GAME_HPP

//http://localhost:8080/index.html

# include <iostream>
# include <fstream>
# include <string>
# include <unistd.h>

# include "Character.hpp"
# include "Map.hpp"

# define PLAYERS 1
# define ENEMIES 1

class   Game
{
    private:
        Character*  _players[PLAYERS];
        Character*  _enemies[ENEMIES];
        Map         _map;
        bool        _game;

    public:
                    Game();
                    Game(const Map& mapValue);
                    Game(const Game& object);
        Game&       operator=(const Game& object);

                    ~Game();

        bool        getGame(void) const;

        void        setGame(bool gameValue);
        
        void        stateGame(void);

        void        saveWorld(const std::string& path) const;
        char        showMenu(void) const;

        void        loopGame(void);
};

#endif