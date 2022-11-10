#include "../include/gameService.hpp"
#include <cstdlib>
#include <array>
#include <stdexcept>

std::array<char, 2> setPlayerOrderService(int option)
{
    std::array<char, 2> players {' ', ' '};

    switch (option)
    {
        case 0:
            std::exit(0);
            break;

        case 1:
            players[0] = 'x';
            players[1] = 'o';
            break;

        case 2:
            players[0] = 'o';
            players[1] = 'x';
            break;
        
        default:
            throw std::invalid_argument("Opção inválida.");
            break;
    }
    
    return players;
}