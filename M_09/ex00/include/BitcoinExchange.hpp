#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream> // para std::cout y std::cerr para imprimir mensajes
# include <fstream> // para std::ifstream para leer archivos
# include <sstream> // para std::istringstream para parsear líneas

class BitcoinExchange
{
    private:
        // map keep date sorted automatically
        // easy to find closest previous date with lower_bound
        std::map<std::string, float>    _database;

        // Disable copy constructor and assignment operator
                                        BitcoinExchange(const BitcoinExchange& object)
                                            :   _database(object._database)
                                        { 

                                        }

        // Disable assignment operator
                                        BitcoinExchange& operator=(const BitcoinExchange& object)
                                        { 
                                            if (this != &object)
                                            {
                                                this->_database = object._database;
                                            }
                                            return (*this);
                                        }

        float                           getExchangeRate(const std::string& date) const;

        void                            printDatabase(void) const
        {
            std::map<std::string, float>::const_iterator    it = _database.begin();
            std::map<std::string, float>::const_iterator    ite = _database.end();

            while (it != ite)
            {
                std::cout << it->first
                        << " => "
                        << it->second
                        << std::endl;
                it++;
            }
        }
    
    public:
        // Default constructor and destructor enabled
        // because we only want one instance of the class
                                        BitcoinExchange();
                                        ~BitcoinExchange();

        // I need to load the database and process input in main
        void                            loadDatabase(const std::string& filename);
        void                            processInput(const std::string& filename) const;

        // Error class
        class Exception : public std::exception
        {
            private:
                std::string     _message;

            public:
                Exception(const std::string& message)
                    :   _message(message)
                {

                }
                // Override what() of std::exception
                virtual const char* what() const throw()
                {
                    return (_message.c_str());
                }
                // Destructor virtual if herits from this class
                virtual ~Exception() throw()
                {

                }
        };
};

#endif