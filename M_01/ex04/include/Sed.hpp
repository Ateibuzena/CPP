#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>  //ifstream and ofstream

class   Sed
{
    private:
        std::string     _fileName;
        std::string     _target;
        std::string     _replacement;
        std::ifstream   _inFile;
        std::ofstream   _outFile;
    
    public:
                        Sed(const std::string& fileNameValue, const std::string& targetValue, const std::string& replacementValue);
        bool            openFile(void);
        std::string     readFile(void);
        bool            replace(std::string& fileContent) const;
        bool            writeFile(const std::string& fileContent);
};

#endif