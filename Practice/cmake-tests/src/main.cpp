#include <iostream>
#include "hello-world.h"

int main()
{
    std::cout << "Main method called!\n";
    HelloWorldClass h;
    std::string s("What is the Answer to everything?");
    const int n = 42;
    h.set_message(s);
    h.set_number(n);
    std::cout << "[main]: " << h.get_message() << " " << h.get_number() << '\n';
}
