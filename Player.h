#ifndef LAB4_PLAYER_H
#define LAB4_PLAYER_H

#include <iostream>

struct Player {
    std::string game;
    std::string nickname;
    std::string rank;
    float XP;
    int wins;
    int total_games;
    int years_playing;
};

#endif //LAB4_PLAYER_H