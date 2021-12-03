#include <gtest/gtest.h>

#include "application.h"

TEST(Application_TB, TestConstruction) {
    Application app;

    ASSERT_FALSE(app.IsRunning());
}
