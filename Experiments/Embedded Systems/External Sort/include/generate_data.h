#include <iostream>
#include <arpa/inet.h>
#include <fstream>
#include <algorithm>
#include <vector>
#include <limits>
#include <typeinfo>
#include <cstdlib>


template <typename T>
class GenerationObject
{
public:

    //TODO: write in big-endian format
    GenerationObject(const std::size_t number_of_items, const std::string file_name)
        :
            file_name(file_name)
    {
        generate_data(number_of_items);
        const bool write_result = write_data_to_file();
        std::cout << "GenerationObject Created. Write Result: " << write_ret_code(write_result) << '\n';
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
        const bool write_r = write_data_to_file();
        std::cout << "[" << write_ret_code(write_r) << "]: Regenerated data containing " 
            << number_of_items << " items written to " << file_name << '\n'; 
    }

    void print_generated_data()
    {
        std::cout << "Data randomly generated for " << file_name << ":\n";
        for (auto &v : data_to_write)
            std::cout << v << "\n";
        std::cout << std::endl;
    }

protected:
    std::string write_ret_code(const bool &v)
    {
        return (v) ? "SUCCESS" : "FAILURE";
    }
private:

    void generate_data(const std::size_t number_of_items)
    {
        //May be bug prone if T is some weird type. Using static_assert to mitigate this as much as possible
        static_assert(std::is_arithmetic<T>{}, "Datatype is not arithmetic type. RNG type must be numeric.");
        
        std::cout << "[" << number_of_items * sizeof(T) << " Bytes Total]: Generating " << number_of_items << " of datatype " << typeid(T).name() << " which are " << sizeof(T) << " Bytes each.\n";
        data_to_write.clear();
        data_to_write.resize(number_of_items);
        
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

