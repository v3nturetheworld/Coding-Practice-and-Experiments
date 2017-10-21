#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

template <typename T>
class ReadDataObject
{
public:
    ReadDataObject()
        : file_size(0)
    {
        std::cout << "Default Read Data Object Constructed\n";
    }
    ReadDataObject(const std::string file_name)
        : file_name(file_name), file_size(0)
    {
        try
        {
            reader.open(file_name, std::ios::binary | std::ios::ate | std::ios::in);
            if(!reader.is_open())
            {
                throw std::runtime_error("Failed to open file.");
            }
            reader.unsetf(std::ios::skipws); //Skip new line characters
            file_size = reader.tellg();
            std::cout << "[Success!]: Opened file " << file_name << " which is " << size() << " Bytes.\n";
            
            reader.seekg(0, std::ios::beg); //Move to start of file
            static_assert(std::is_standard_layout<T>{}, "Data Type is not of standard layout");
            file_items.resize(size());
            reader.read(reinterpret_cast<char *>(&file_items[0]), file_size);
            
            std::cout << "All items read into file_items vector. The vector size is: " << file_items.size() << '\n';
        }
        catch(const std::exception &e)
        {
            std::cerr << "Error! The following exception occurred while reading file " << file_name << ": " << e.what() << std::endl;
        }
    }
    virtual ~ReadDataObject()
    {
        if(reader.is_open())
            reader.close();
        file_items.clear();
    }
    std::size_t size() const
    {
        return file_size / sizeof(T);
    }
    std::vector<T> &get_items() const
    {
        return file_items;
    }

    void print_file()
    {
        std::cout << "Contents of " << file_name << ":\n";
        for(auto &v : file_items)
            std::cout << v << "\n";
        std::cout << std::endl;
    }


private:
    std::string file_name;
    std::ifstream reader;
    std::size_t file_size;
    std::vector<T> file_items;

};
