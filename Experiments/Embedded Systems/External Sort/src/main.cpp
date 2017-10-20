#include "external-sort.h"
#include "generate_data.h"


int main()
{
    GenerationObject<unsigned> g(10, "test.bin");
    //GenerationObject<unsigned> g;
    //g.set_file_name("foo.bin");
    //g.regenerate_data(10);
    std::cout << "Hello World\n";
}
