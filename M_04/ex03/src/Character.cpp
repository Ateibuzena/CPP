#include "Character.hpp"

/*-------------------------------CONSTRUCTORS-------------------------------*/

Character::Character()
    :   _name("default name")
{
    _position[0] = 0;
    _position[1] = 0;

    int i = 0;
    while (i < 4)
    {
        _inventary[i] = NULL;
        i++;
    }
}

Character::Character(const std::string& nameValue)
    :   _name(nameValue)
{
    _position[0] = 0;
    _position[1] = 0;

    int i = 0;
    while (i < 4)
    {
        _inventary[i] = NULL;
        i++;
    }
}

Character::Character(const Character& object)
    :   _name(object._name)
{
    _position[0] = object._position[0];
    _position[1] = object._position[1];

    int i = 0;
    while (i < 4)
    {
        if (object._inventary[i])
            _inventary[i] = object._inventary[i]->clone();
        else
            _inventary[i] = NULL;
        i++;
    }
}

Character&  Character::operator=(const Character& object)
{
    if (this != &object)
    {
        _name = object._name;
        _position[0] = object._position[0];
        _position[1] = object._position[1];
        int i = 0;
        while (i < 4)
        {
            if (_inventary[i])
                delete (_inventary[i]);
            if (object._inventary[i])
                _inventary[i] = object._inventary[i]->clone();
            else
                _inventary[i] = NULL;
            i++;
        }
    }
    return (*this);
}

/*-------------------------------DESTRUCTOR-------------------------------*/

Character::~Character()
{
    int i = 0;
    while (i < 4)
    {
        if (_inventary[i])
            delete (_inventary[i]);
        i++;
    }
}

/*-------------------------------GETTERS-------------------------------*/

const std::string&  Character::getName(void) const
{
    return (_name);
}

const int* Character::getPosition(void) const
{
    return (_position);
}

/*-------------------------------SETTERS-------------------------------*/

void    Character::setName(const std::string& nameValue)
{
    _name = nameValue;
}

void    Character::setPosition(int x, int y)
{
    _position[0] = x;
    _position[1] = y;
}

/*-------------------------------METHODS-------------------------------*/

void    Character::showInventary(void) const
{
    int i = 0;
    while (i < 4)
    {
        if (_inventary[i])
        {
            std::cout
                << _inventary[i]->getType()
                << std::endl;
        }
        i++;
    }
    
}

void    Character::showCharacter(void) const
{
    const int* pos = getPosition();

    std::cout
        << "Name: "
        << getName()
        << "\nPosition: ("
        << pos[0]
        << ", "
        << pos[1]
        << ")\n"
        << std::endl;
        
    showInventary();
}

void    Character::equip(AMateria* m)
{
    if (!m)
        return ;
    int i = 0;
    while (i < 4)
    {
        if (!_inventary[i])
        {
            _inventary[i] = m;
            return ;
        }
        i++;
    }
    std::cout
        << _name
        << " hasn't space for it"
        << std::endl;
}

void    Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && _inventary[idx])
        _inventary[idx] = NULL;
}

void    Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && _inventary[idx])
        _inventary[idx]->use(target);
}

void Character::move(char input)
{
    int x = _position[0];
    int y = _position[1];

    if (input == 'w')
        y--;
    else if (input == 's')
        y++;
    else if (input == 'a')
        x--;
    else if (input == 'd')
        x++;

    _position[0] = x;
    _position[1] = y;
}
