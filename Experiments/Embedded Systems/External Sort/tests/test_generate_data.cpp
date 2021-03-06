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

TEST_F(GenerationTestClass, BasicGenerateTest_UINT)
{
    ReadDataObject<unsigned int> r("unsigned_int_test.bin");
    auto f_size = r.size();
    ASSERT_NE(f_size, std::size_t(0));
    EXPECT_EQ(f_size, std::size_t(30));
}

TEST_F(GenerationTestClass, BasicGenerateTest_INT)
{
    ReadDataObject<int> r("int_test.bin");
    auto f_size = r.size();

    ASSERT_NE(f_size, std::size_t(0));
    EXPECT_EQ(f_size, std::size_t(30));
}

TEST_F(GenerationTestClass, BasicGenerateTest_UNSIGNED)
{
    ReadDataObject<int> r("unsigned_test.bin");
    auto f_size = r.size();

    ASSERT_NE(f_size, std::size_t(0));
    EXPECT_EQ(f_size, std::size_t(30));
}

TEST_F(GenerationTestClass, ByteReader_Insanity_Test)
{
    ByteReader<unsigned int, 32> r("unsigned_int_test.bin");
    r.read_all_data();
    auto f_size = r.size();
    ASSERT_NE(f_size, std::size_t(0));
    EXPECT_EQ(f_size, std::size_t(30));


}



} //End of anonymous namespace

