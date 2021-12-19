#include <gtest/gtest.h>

#include "application.h"
#include "mocksdl.h"

using namespace testing;

TEST(Application_TB, TestConstruction)
{
    MockSDL mockSdl;
    TTT::Configuration config;
    //SDL_Window dummyWindow;

    EXPECT_CALL(mockSdl, Init(SDL_INIT_VIDEO)).WillOnce(Return(0));
    EXPECT_CALL(mockSdl, CreateWindow(StrEq("Tic Tac Toe"), 20, 20, 640, 480, SDL_WINDOW_SHOWN)).WillOnce(Return(&mockSdl.dummySdlWindow));
    EXPECT_CALL(mockSdl, CreateRenderer(NotNull(), -1, SDL_RENDERER_ACCELERATED)).WillOnce(Return(&mockSdl.dummySdlRenderer));

    TTT::Application app(mockSdl, config);
    ASSERT_FALSE(app.IsRunning());
}
