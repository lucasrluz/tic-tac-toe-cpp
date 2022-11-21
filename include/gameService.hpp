#ifndef GAME_SERVICE_HPP
#define GAME_SERVICE_HPP

#include <array>

std::array<char, 2> setPlayerOrderService(int option);
void setPlayPositionService(int position, char player, char* round);

#endif