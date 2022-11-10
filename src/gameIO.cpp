#include <iostream>
#include "../include/gameIO.hpp"

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