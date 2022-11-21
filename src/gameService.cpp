#include "../include/gameService.hpp"
#include <cstdlib>
#include <array>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>

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

void setPlayPositionService(int position, char player, char* round)
{
    const int index { position - 1};

    if (index < 0 || index > 8)
    {
        throw std::invalid_argument("Opção inválida. Posições válidas de 1 a 9.");
    }

    if (round[index] == 'x' || round[index] == 'o') 
    {
        throw std::invalid_argument("Opção inválida. Posição já  ocupada.");
    }
    
    round[index] = player;
}

bool checkForAWinner(char* round)
{
    if (
        (round[0] == round[3] && round[3] == round[6]) ||
        (round[0] == round[4] && round[4] == round[8]) || 
        (round[0] == round[1] && round[1] == round[2]) ||
        (round[1] == round[4] && round[4] == round[7]) ||
        (round[2] == round[4] && round[4] == round[6]) || 
        (round[2] == round[5] && round[5] == round[8]) ||
        (round[3] == round[4] && round[4] == round[5]) ||
        (round[6] == round[7] && round[7] == round[8]) 
    ){
        return true;
    }
    
    return false;
}