#include <iostream>
#include <arpa/inet.h>
#include <fstream>
#include <algorithm>
#include <vector>
#include <limits>
#include <cstdlib>


template <typename T>
class GenerationObject
{
public:
    
    GenerationObject(const std::size_t number_of_items, const std::string file_name)
        :
            file_name(file_name)
    {
        generate_data(number_of_items);
        const bool write_result = write_data_to_file();
        const std::string res = (write_result) ? "SUCCESS" : "FAILURE";
        std::cout << "GenerationObject Created. Write Result: " << res << '\n';
    }
    GenerationObject()
    {
        std::cout << "Empty GenerationObject Created\n";
    }
    

    void set_file_name(const std::string name)
    {
        file_name = name;
    }

    void regenerate_data(const std::size_t number_of_items)
    {
        generate_data(number_of_items);
    }

private:

    void generate_data(const std::size_t number_of_items)
    {
        std::cout << "[" << number_of_items * sizeof(T) << " Bytes Total]: Generating " << number_of_items << " of datatype " << typeid(T).name() << " which are " << sizeof(T) << " Bytes each.\n";
        data_to_write.clear();
        data_to_write.resize(number_of_items);

        //May be bug prone if T is some weird type
        std::generate(data_to_write.begin(), data_to_write.end(), []()
                {
                    return std::rand() % std::numeric_limits<T>::max();
                });
    }
    
    bool write_data_to_file()
    {
        try
        {
            file_writer.open(file_name, std::ios::out | std::ios::binary | std::ios::trunc);
            if(!file_writer.is_open())
                throw std::runtime_error("IO Error! File failed to open.");
            std::cout << "File " << file_name << " opened for writing\n";
            for(auto &elem : data_to_write)
            {
                file_writer.write(reinterpret_cast<char *>(&elem), sizeof(elem));
               // file_writer << elem << '\n';
            }
            file_writer.close();
            std::cout << "Done writing data to " << file_name << '\n';
        } 
        catch(const std::exception &e)
        {
            std::cerr << "An error occurred while trying to write the file: " << e.what() << std::endl;
            return false;
        }

        return true;        
    }
private:
    std::vector<T> data_to_write;
    std::string file_name;
    std::ofstream file_writer;
};

