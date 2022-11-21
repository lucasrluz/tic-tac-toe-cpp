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

/*
* SetPlayPositionService Tests
*/

TEST(SetPlayPositionService, ShouldSetXInRound)
{
    char round[9] { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    setPlayPositionService(1, 'x', round);

    char array[9] { 'x', '2', '3', '4', '5', '6', '7', '8', '9' };
    EXPECT_EQ(round[0], array[0]);
}

TEST(SetPlayPositionService, ShouldReturnInvalidArgumentException)
{
    try
    {
        char round[9] { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        setPlayPositionService(10, 'x', round);
        FAIL();
    }
    catch(const std::exception& e)
    {
        EXPECT_EQ(e.what(), std::string("Opção inválida. Posições válidas de 1 a 9."));
    }
}

TEST(SetPlayPositionService, shouldReturnInvalidArgumentException)
{
    try
    {
        char round[9] { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        setPlayPositionService(1, 'x', round);
        setPlayPositionService(1, 'o', round);
        FAIL();
    }
    catch(const std::exception& e)
    {
        EXPECT_EQ(e.what(), std::string("Opção inválida. Posição já  ocupada."));
    }
}