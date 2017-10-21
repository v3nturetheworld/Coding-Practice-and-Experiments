#include "gtest/gtest.h"
#include "generate_data.h"
#include "read_data.h"

#include <iostream>
#include <fstream>
#include <vector>




namespace {

class GenerationTestClass : public ::testing::Test
{
protected:

    GenerationTestClass()
    {
        //setup work
        number_of_items = 30;
        
        f1_name = "unsigned_int_test.bin";
        f2_name = "int_test.bin";
        f3_name = "unsigned_test.bin";
    }
    virtual ~GenerationTestClass()
    {
        //virtual destructor
    }

    virtual void SetUp()
    {
        

        g1.set_file_name(f1_name);
        g1.regenerate_data(number_of_items);
        g1.print_generated_data();
        
        g2.set_file_name(f2_name);
        g2.regenerate_data(number_of_items);

        g3.set_file_name(f3_name);
        g3.regenerate_data(number_of_items);

    }

    virtual void TearDown() {}
    

    GenerationObject<unsigned int> g1;
    GenerationObject<int> g2;
    GenerationObject<unsigned> g3;

private:
    std::string f1_name, f2_name, f3_name;
    std::size_t number_of_items;

};

TEST_F(GenerationTestClass, BasicGenerateTest)
{
    ReadDataObject<unsigned int> r("unsigned_int_test.bin");
    auto f_size = r.size();
    EXPECT_NE(f_size, std::size_t(0));
    r.print_file();
    EXPECT_EQ(0,1);
}


} //End of anonymous namespace

