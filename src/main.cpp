#include "../include/gameService.hpp"
#include "../include/gameIO.hpp"
#include <iostream>
#include <array>

int main()
{
    try
    {
      char round[9] { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

      std::array<char, 2> players { setPlayerOrderService(setPlayerOrderInput()) };

      printGameBoard(round);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}