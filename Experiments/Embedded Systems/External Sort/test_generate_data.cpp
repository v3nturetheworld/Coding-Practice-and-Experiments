#include "gtest/gtest.h"
#include "generate_data.h"

#include <iostream>
#include <fstream>
#include <vector>





class GenerationTestClass : ::testing::Test
{
protected:

    virtual void SetUp()
    {
        const std::size_t number_of_items = 30;
        
        const std::string f1_name = "unsigned_int_test.bin";
        const std::string f2_name = "int_test.bin";
        const std::string f3_name = "unsigned_test.bin";

        g1.set_file_name(f1_name);
        g1.regenerate_data(number_of_items);
        
        g2.set_file_name(f2_name);
        g2.regenerate_data(number_of_items);

        g3.set_file_name(f3_name);
        g3.regenerate_data(number_of_items);

    }

    //virtual void TearDown() {}
    

    GenerationObject<unsigned int> g1;
    GenerationObject<int> g2;
    GenerationObject<unsigned> g3;

};



