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

TEST(CheckForAWinner, ShouldReturnFalse)
{
    char round[9] { 'x', 'x', 'o', '4', '5', '6', '7', '8', '9' };

    EXPECT_EQ(checkForAWinner(round), false);
}

TEST(CheckForAWinner, ShouldReturnTrueIn036)
{
    char round[9] { 'x', '2', '3', 'x', '5', '6', 'x', '8', '9' };

    EXPECT_EQ(checkForAWinner(round), true);
}

TEST(CheckForAWinner, ShouldReturnTrueIn048)
{
    char round[9] { 'x', '2', '3', '4', 'x', '6', '7', '8', 'x' };

    EXPECT_EQ(checkForAWinner(round), true);
}

TEST(CheckForAWinner, ShouldReturnTrueIn012)
{
    char round[9] { 'x', 'x', 'x', '4', '5', '6', '7', '8', '9' };

    EXPECT_EQ(checkForAWinner(round), true);
}

TEST(CheckForAWinner, ShouldReturnTrueIn147)
{
    char round[9] { '1', 'x', '3', '4', 'x', '6', '7', 'x', '9' };

    EXPECT_EQ(checkForAWinner(round), true);
}

TEST(CheckForAWinner, ShouldReturnTrueIn246)
{
    char round[9] { '1', '2', 'x', '4', 'x', '6', 'x', '8', '9' };

    EXPECT_EQ(checkForAWinner(round), true);
}

TEST(CheckForAWinner, ShouldReturnTrueIn258)
{
    char round[9] { '1', '2', 'x', '4', '5', 'x', '7', '8', 'x' };

    EXPECT_EQ(checkForAWinner(round), true);
}

TEST(CheckForAWinner, ShouldReturnTrueIn345)
{
    char round[9] { '1', '2', '3', 'x', 'x', 'x', '7', '8', '9' };

    EXPECT_EQ(checkForAWinner(round), true);
}

TEST(CheckForAWinner, ShouldReturnTrueIn678)
{
    char round[9] { '1', '2', '3', '4', '5', '6', 'x', 'x', 'x' };

    EXPECT_EQ(checkForAWinner(round), true);
}