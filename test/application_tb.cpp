#include <gtest/gtest.h>

#include "application.h"

TEST(Application_TB, TestConstruction)
{
    TTT::Configuration config;
    TTT::Application app(config);

    ASSERT_FALSE(app.IsRunning());
}
