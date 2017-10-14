#include <iostream>
#pragma once

class HelloWorldClass
{
public:
    HelloWorldClass();
    ~HelloWorldClass();

    void set_message(const std::string &s);
    const std::string& get_message();
    void set_number(const int& num);
    const int& get_number();

private:
    std::string some_message;
    int some_num;
};