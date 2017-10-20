#include <iostream>
#include <fstream>
#include <string>
#include <vector>

template <typename T>
class ReadDataObject
{
public:
    ReadDataObject()
    {
        std::cout << "Default Read Data Object Constructed\n";
    }
    ReadDataObject(const std::string file_name)
        : file_name(file_name)
    {
        try
        {
            //TODO: read files
        }
        catch(const std::exception &e)
        {
            std::cerr << "Error! The following exception occurred while reading file " << file_name << ": " << e.what() << std::endl;
        }
    }

private:
    std::string file_name;
    std::ifstream reader;
};
