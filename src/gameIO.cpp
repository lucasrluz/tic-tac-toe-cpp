#include <iostream>
#include "../include/gameIO.hpp"
#include <array>

void printGameBoard(char* round)
{
    std::cout << "+ - + - + - +" << '\n';
    std::cout << "| " << round[0] << " | " << round[1] << " | " << round[2] << " |" << '\n';
    std::cout << "+ - + - + - +" << '\n';
    std::cout << "| " << round[3] << " | " << round[4] << " | " << round[5] << " |" << '\n';
    std::cout << "+ - + - + - +" << '\n';
    std::cout << "| " << round[6] << " | " << round[7] << " | " << round[8] << " |" << '\n';
    std::cout << "+ - + - + - +" << '\n';
}

int setPlayerOrderInput()
{
    std::cout << "Qual jogador vai começar?" << '\n';
    std::cout << "[1] - x" << '\n';
    std::cout << "[2] - o" << '\n';
    std::cout << "[0] - Sair" << '\n';

    int option {};

    std::cin >> option;

    return option;
}

int setPlayPositionInput(char player)
{
    std::cout << "Em qual posição o jogador (" << player << ") quer jogar?" << '\n';

    int option {};

    std::cin >> option;

    return option;
}