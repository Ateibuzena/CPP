#include "Sed.hpp"

Sed::Sed(const std::string& fileNameValue, const std::string& targetValue, const std::string& replacementValue)
    :   _fileName(fileNameValue),
        _target(targetValue),
        _replacement(replacementValue)
{

}

bool    Sed::openFile(void)
{
    std::string     fileNameValue = _fileName;

    if (_inFile.is_open())
        _inFile.close();
    
    _inFile.open(fileNameValue.c_str(), std::ios::in);
    if (!_inFile.is_open())
    {
        std::cout
            << "❌ Error: could not open file "
            << fileNameValue
            << std::endl;
        return (false);
    }
    std::cout
        << "✅ Success: could open file "
        << fileNameValue
        << std::endl;
    return (true);
}

std::string Sed::readFile(void)
{
    std::string fileNameValue = _fileName;
  
    if (!openFile())
    {
        std::cout
            << "❌ Error: could not read file "
            << fileNameValue
            << std::endl;
        return ("");
    }

    std::string fileContent;
    std::string fileLine;

    std::getline(_inFile, fileLine);
    while (_inFile)
    {
        fileContent += fileLine + "\n";
        std::getline(_inFile, fileLine);
    }
    _inFile.close();

    std::cout
        << "✅ Success: could read file "
        << fileNameValue
        << std::endl;
    return (fileContent);
}

bool    Sed::replace(std::string& fileContent) const
{
    if (_target.empty())
    {
        std::cout
            << "❌ Error: could not replace \""
            << _target
            << "\" with \""
            << _replacement
            << "\""
            << std::endl;
        return (false);
    }
    size_t      i = 0;
    size_t      targetLen = _target.length();
    size_t      j = fileContent.find(_target, i);
    std::string result;

    while (j != std::string::npos)
    {
        result += fileContent.substr(i, j - i);
        result += _replacement;
        i = j + targetLen;
        j = fileContent.find(_target, i);
    }

    result += fileContent.substr(i);
    fileContent = result;
    std::cout
        << "✅ Success: could replace \""
        << _target
        << "\" with \""
        << _replacement
        << "\""
        << std::endl;
    return (true);
}

bool    Sed::writeFile(const std::string& fileContent)
{
    std::string     fileNameValue = _fileName + ".replace";

    if (_outFile.is_open())
        _outFile.close();

    _outFile.open(fileNameValue.c_str(), std::ios::out);
    if (!_outFile.is_open())
    {
        std::cout
            << "❌ Error: could not create file "
            << fileNameValue
            << std::endl;
        return (false);
    }
    _outFile << fileContent;
    _outFile.close();
    std::cout
        << "✅ Success: could write file "
        << fileNameValue
        << std::endl;
    return (true);
}
