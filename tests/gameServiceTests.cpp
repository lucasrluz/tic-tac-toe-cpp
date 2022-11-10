#include <gtest/gtest.h>
#include "../include/gameService.hpp"
#include <array>
#include <string>

TEST(GameServiceTest, shouldReturnPlayerXAndO)
{
    std::array<char, 2> players {'x', 'o'};
    EXPECT_EQ(setPlayerOrderService(1), players);
}

TEST(GameServiceTest, shouldReturnPlayerOAndX)
{
    std::array<char, 2> players {'o', 'x'};
    EXPECT_EQ(setPlayerOrderService(2), players);
}

TEST(GameServiceTest, shouldReturnExit)
{
    std::array<char, 2> players {'o', 'x'};
    EXPECT_EXIT(setPlayerOrderService(0), testing::ExitedWithCode(0), "");
}

TEST(GameServiceTest, shouldReturnInvalidArgumentException)
{
    try
    {
        setPlayerOrderService(3);
        FAIL();
    }
    catch(const std::exception& e)
    {
        EXPECT_EQ(e.what(), std::string("Opção inválida."));
    }
}