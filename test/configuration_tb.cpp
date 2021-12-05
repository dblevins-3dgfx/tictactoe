#include <gtest/gtest.h>

#include <configuration.h>

inline bool file_exists(const std::string &name)
{
    return (access(name.c_str(), F_OK) != -1);
}

TEST(Configuration_TB, TestConstruction)
{
    TTT::Configuration config;

    ASSERT_TRUE(file_exists(config.GetBoardPNGPath()));
}
