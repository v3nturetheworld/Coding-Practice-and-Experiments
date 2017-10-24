#include <iostream>
#include <functional>
#include <algorithm>
#include <array>
#include <vector>

template <typename T, std::size_t BufferSize>
class RadixSort
{
public:
    RadixSort(std::array<T, BufferSize> &buffer, std::function<T> ComparisonFunc)
        : sorted_buffer(buffer)
    {
        std::cout << "RadixSort Instance Created.\n";
        static_assert(buffer.size() > 0, "Error! The buffer size must contain values to sort.");
        //TODO: Implement Radix Sort
    }
    ~RadixSort()
    {
    }

    std::array<T, BufferSize> &sort()
    {
        //TODO: BucketSort/CountSort
        sorted_buffer.sort(sorted_buffer.begin(), sorted_buffer.end(), [](auto a, auto b){ return a < b; }); 
    }
private:
    std::array<T, BufferSize> sorted_buffer;
};
