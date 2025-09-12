
#include "Game.hpp"
#include <sstream>

static std::string  to_string(const int n)
{
    std::stringstream   str;
    str << n;
    return (str.str());
}

Game::Game()
    :   _map(Map())
{
    int i = 0;
    while (i < PLAYERS)
    {
        _players[i] = new Character("🐱");
        i++;
    }
    i = 0;
    while (i < ENEMIES)
    {
        _enemies[i] = new Character("🐶");
        i++;
    }
}

Game::Game(const Map& mapValue)
    :   _map(mapValue)
{
    int i = 0;
    while (i < PLAYERS)
    {
        _players[i] = new Character("player_0" + to_string(i));
        i++;
    }
    i = 0;
    while (i < ENEMIES)
    {
        _enemies[i] = new Character("enemy_0" + to_string(i));
        i++;
    }
}

Game::Game(const Game& object)
{
    int i = 0;
    while (i < PLAYERS)
    {
        if (_players[i])
            delete (_players[i]);
        if (object._players[i])
            _players[i] = new Character(*object._players[i]);
        else 
            _players[i] = NULL;
        i++;
    }
    i = 0;
    while (i < ENEMIES)
    {
        if (_enemies[i])
            delete (_enemies[i]);
        if (object._enemies[i])
            _enemies[i] = new Character(*object._enemies[i]);
        else 
            _enemies[i] = NULL;
        i++;
    }
}

Game&   Game::operator=(const Game& object)
{
    if (this != &object)
    {
        _map = object._map;

        int i = 0;
        while (i < PLAYERS)
        {
            if (object._players[i])
                _players[i] = new Character(*object._players[i]);
            else 
                _players[i] = NULL;
            i++;
        }
        i = 0;
        while (i < ENEMIES)
        {
            if (object._enemies[i])
                _enemies[i] = new Character(*object._enemies[i]);
            else 
                _enemies[i] = NULL;
            i++;
        }
    }
    return (*this);
}


Game::~Game()
{
    int i = 0;
    while (i < PLAYERS)
    {
        if (_players[i])
            delete (_players[i]);
        i++;
    }
    i = 0;
    while (i < ENEMIES)
    {
        if (_enemies[i])
            delete (_enemies[i]);
        i++;
    }
}

bool    Game::getGame(void) const
{
    return (_game);
}

void    Game::setGame(bool gameValue)
{
    _game = gameValue;
}

void Game::stateGame(void)
{
    std::cout << "\n---------------GAME STATE-----------------\n" << std::endl;

    for (int i = 0; i < PLAYERS; i++)
    {
        _players[i]->showCharacter();
        _players[i]->showInventary();
    }

    for (int i = 0; i < ENEMIES; i++)
    {
        _enemies[i]->showCharacter();
        _enemies[i]->showInventary();
    }

    _map.showMap(_players, PLAYERS, _enemies, ENEMIES);

    std::cout << "\n------------------------------------------\n" << std::endl;
}

void    Game::saveWorld(const std::string& path) const
{
    std::ofstream out(path.c_str());
    if (!out.is_open())
        return;

    int y = 0;
    while (y < HEIGHT)
    {
        int x = 0;
        while (x < WIDTH)
        {
            bool printed = false;

            int i = 0;
            while (i < PLAYERS)
            {
                const int* pos = _players[i]->getPosition();
                if (pos[0] == x && pos[1] == y)
                {
                    out << _players[i]->getName();
                    printed = true;
                    break;
                }
                i++;
            }

            int j = 0;
            while (!printed && j < ENEMIES)
            {
                const int* pos = _enemies[j]->getPosition();
                if (pos[0] == x && pos[1] == y)
                {
                    out << _enemies[j]->getName();
                    printed = true;
                    break;
                }
                j++;
            }

            if (!printed)
            {
                if (_map.getMateria(x, y))
                    out << _map.getMateria(x, y)->getType();
                else
                    out << "🍀";
            }

            x++;
        }
        out << "\n";
        y++;
    }

    out.close();
}

char Game::showMenu(void) const
{
    std::cout << "\n---- MENU ----\n";
    std::cout << "w: arriba\n";
    std::cout << "s: abajo\n";
    std::cout << "a: izquierda\n";
    std::cout << "d: derecha\n";
    std::cout << "q: salir\n";
    std::cout << "--------------\n";
    std::cout << "Elige acción: ";

    char c;
    std::cin >> c;
    return (c);
}

void Game::loopGame(void)
{
    int turn = 0;
    std::string worldName = "world_01";

    // Posiciones iniciales
    _map.setWorld(worldName);
    for (int i = 0; i < PLAYERS; i++)
        _players[i]->setPosition(0, i);
    for (int j = 0; j < ENEMIES; j++)
        _enemies[j]->setPosition(WIDTH - 1, HEIGHT - 1 - j);
    saveWorld("/sgoinfre/students/azubieta/CPP/M_04/ex03/maps/world_01.txt");

    _game = true;
    while (_game)
    {
        std::cout
            << "\n===== TURNO "
            << turn
            << " =====\n"
            << std::endl;

        // Turno de cada jugador
        int i = 0;
        while (i < PLAYERS)
        {
            std::cout
                << "\n==== PLAYER "
                << _players[i]->getName()
                << " ====\n"
                << std::endl;

            char input = showMenu();
            if (input == 'q')
                _game = false;

            _players[i]->move(input);

            // después de mover, revisar si hay materia en esa casilla
            const int* pos = _players[i]->getPosition();
            if (pos[0] < 0 || pos[0] >= WIDTH || pos[1] < 0 || pos[1] >= HEIGHT)
            {
                std::cout << "\n---------------GAME OVER-----------------\n";
                _game = false;
                break ;
            }

            AMateria* materia = _map.getMateria(pos[0], pos[1]);
            if (materia)
            {
                _players[i]->equip(materia);
                _map.setMateria(NULL, pos[0], pos[1]);
            }
            saveWorld("/sgoinfre/students/azubieta/CPP/M_04/ex03/maps/world_01.txt");

            i++;
        }

        // Turno de enemigos (ejemplo: se mueven a la izquierda)
        int j = 0;
        while (j < ENEMIES)
        {
            std::cout
                << "\n==== ENEMY "
                << _players[i]->getName()
                << " ====\n"
                << std::endl;

            char input = showMenu();
            if (input == 'q')
                _game = false;

            _enemies[j]->move(input);

            // después de mover, revisar si hay materia en esa casilla
            const int* pos = _enemies[j]->getPosition();
            if (pos[0] < 0 || pos[0] >= WIDTH || pos[1] < 0 || pos[1] >= HEIGHT)
            {
                std::cout << "\n---------------GAME OVER-----------------\n";
                _game = false;
                break ;
            }

            AMateria* materia = _map.getMateria(pos[0], pos[1]);
            if (materia)
            {
                _enemies[j]->equip(materia);
                _map.setMateria(NULL, pos[0], pos[1]);
            }
            saveWorld("/sgoinfre/students/azubieta/CPP/M_04/ex03/maps/world_01.txt");

            j++;
        }

        // Guardar estado
        saveWorld("/sgoinfre/students/azubieta/CPP/M_04/ex03/maps/world_01.txt");

        // Condición de salida (ejemplo: max turnos)
        turn++;
        if (turn == 20)
        {
            std::cout << "\n---------------GAME OVER-----------------\n";
            _game = false;
        }
    }
}
