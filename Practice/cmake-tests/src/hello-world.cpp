#include "hello-world.h"

HelloWorldClass::HelloWorldClass()
{
    std::cout << "Hello World Class constructed!!!\n";
}

HelloWorldClass::~HelloWorldClass()
{

}


void HelloWorldClass::set_message(const std::string &s)
{
    some_message = s;
}

const std::string& HelloWorldClass::get_message()
{
    return some_message;
}

void HelloWorldClass::set_number(const int &num)
{
    some_num = num;
}

const int& HelloWorldClass::get_number()
{
    return some_num;
}