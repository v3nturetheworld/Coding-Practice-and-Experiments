#include <iostream>
#include <fstream>
#include <array>
#include <arpa/inet.h>


#define READ_BUFFER_SIZE (1 << 8) // 64 Bytes


class ExternalSort
{
public:
    ExternalSort();
    ~ExternalSort();

private:
    std::array<int, READ_BUFFER_SIZE> rb;
};
