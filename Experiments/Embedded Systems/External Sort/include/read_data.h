#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

template <typename T>
class ReadDataObject
{
public:

    //TODO: Read data in Big-Endian format

    ReadDataObject()
        : file_size(0)
    {
        std::cout << "Default Read Data Object Constructed\n";
    }
    ReadDataObject(const std::string file_name)
        : file_name(file_name), file_size(0)
    {
        open_file(file_name);
        read_all_data();
    }
    virtual ~ReadDataObject()
    {
        if(reader.is_open())
            reader.close();
        file_items.clear();
    }

    void open_file(const std::string &f_name)
    {
        try
        {
            reader.open(f_name, std::ios::binary | std::ios::ate | std::ios::in);
            if(!reader.is_open())
            {
                throw std::runtime_error("Failed to open file.");
            }
            reader.unsetf(std::ios::skipws); //Skip new line characters
            file_size = reader.tellg();
            std::cout << "[Success!]: Opened file " << file_name << " which is " << size() << " Bytes.\n";
            
            reader.seekg(0, std::ios::beg); //Move to start of file 
            
            std::cout << "All items read into file_items vector. The vector size is: " << file_items.size() << '\n';
        }
        catch(const std::exception &e)
        {
            std::cerr << "Error! The following exception occurred while reading file " << file_name << ": " << e.what() << std::endl;
        }
    }

    void read_all_data()
    {
        try
        {
            static_assert(std::is_standard_layout<T>{}, "Data Type is not of standard layout");

            file_items.resize(size());
            reader.read(reinterpret_cast<char *>(&file_items[0]), file_size);
        }
        catch (const std::exception &e) 
        {
            std::cerr << "[Error!]: could not read_all_data because: " << e.what() << std::endl;
        }
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


protected:
    std::string file_name;
    std::ifstream reader;
    std::size_t file_size;
    std::vector<T> file_items;
};


template <typename T, std::size_t BufferSize>
class ByteReader : public ReadDataObject<T>
{
public:
    ByteReader(const std::string file_name)
    {
        std::cout << "ByteReader Constructed with file to be read: " << file_name << '\n';
        ByteReader::open_file(file_name);
    }

    /**
     * This PIA of a function reads 1 byte per line for as many bytes as the buffer
     * can hold (i.e. BufferSize), then returns a reference to the data stored in said
     * buffer. This function can be called until the end of the file has been read.
     **/
    std::array<T, BufferSize>& read_next_bytes()
    {
        static_assert(BufferSize > 0, "[Error!]: Read Buffer is too small!");
        auto start_pos = this->reader.tellg();

        for(std::size_t c = start_pos; c < BufferSize; ++c)
        {
            //if this actually works...
            this->reader.read(reinterpret_cast<char *>(&read_buffer[c % BufferSize]), sizeof(T));
            if(this->reader.rdstate() == std::ios::eofbit)
            {
                is_eof = true;
                break;
            }
        }
        if(is_eof)
        {
            std::cout << "[Debug]: End of File Reached. ";
            if(line_read_count < (sizeof(T) * sizeof(char)))
            {
                line_read_count++;
                std::cout << "Next read is " << line_read_count << " vals into each line\n";
            } 
            else
            {
                std::cout << "Finished reading file.\n";
            }
    
        }
        return read_buffer;
    }
private:
    std::size_t line_read_count;
    std::array<T, BufferSize> read_buffer;
    bool is_eof;
};
