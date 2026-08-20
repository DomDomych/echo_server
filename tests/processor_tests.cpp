#include <gtest/gtest.h>

#include "protocol/command_processor.hpp"
#include "protocol/request.hpp"
#include <unordered_map>
#include <string>


TEST(ProcessorTest,GetCommand)
{
    std::unordered_map<std::string,std::string> storage{
        {"key","value"}
    };

    Request req{"GET","key"};

    EXPECT_EQ(process(req,storage),"value\n");
}

TEST(ProcessorTest,SetCommand)
{

    Request req{"SET","key","value"};
    std::unordered_map<std::string,std::string> storage;

    EXPECT_EQ(process(req,storage),"OK!\n");
    ASSERT_NE(storage.find("key"),storage.end());
    EXPECT_EQ(storage.at("key"),"value");

}

TEST(ProcessorTest,DelCommand)
{
    std::unordered_map<std::string,std::string> storage{
        {"key","value"}
    };

    Request req{"DEL","key"};

    EXPECT_EQ(process(req,storage),"OK!\n");
    EXPECT_EQ(storage.find("key"),storage.end());
}