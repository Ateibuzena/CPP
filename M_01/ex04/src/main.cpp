#include "Sed.hpp"

static bool ft_check_args(int argc, char **argv)
{
    if (argc < 4)
    {
        std::cout
            << "❌ Error: "
            << argv[0]
            << " <filename> <target> <replacement>"
            << std::endl;
        return (false);
    }
    std::string filename = argv[1];
    if (filename.empty())
    {
        std::cout
            << "❌ Error: filename can not be empty"
            << std::endl;
        return (false);
    }
    std::string target = argv[2];
    if (target.empty())
    {
        std::cout
            << "❌ Error: target can not be empty"
            << std::endl;
        return (false);
    }
    return (true);
}

int main(int argc, char** argv)
{
    if (!ft_check_args(argc, argv))
    {
        std::cout
            << "\n❌ Replacement not made!"
            << std::endl;
        return (false);
    }
    std::string filename = argv[1];
    std::string target = argv[2];
    std::string replacement = argv[3];

    /*class sed*/
    Sed sed(filename, target, replacement);

    /*
        ifstream-> (name, std::ios::in) ->read
        ofstream-> (name, std::ios::out) ->write
        fstream-> (name, std::ios::in | std::ios::out) -> read and write
    */

    /*read file*/
    std::string fileContent = sed.readFile();
    if (fileContent.empty())
    {
        std::cout
            << "\n❌ Replacement not made!"
            << std::endl;
        return (1);
    }

    /*replace content*/
    if (!sed.replace(fileContent))
    {
        std::cout
            << "\n❌ Replacement not made!"
            << std::endl;
        return (1);
    }

    /*write file*/
    if (!sed.writeFile(fileContent))
    {
        std::cout
            << "\n❌ Replacement not made!"
            << std::endl;
        return (1);
    }
    std::cout
        << "\n✅ Replacement made!"
        << std::endl;
    return (0);
}