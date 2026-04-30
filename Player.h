#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

struct Player {
    std::string game;
    std::string nickname;
    std::string rank;
    float XP;
    int wins;
    int total_games;
    int years_playing;

    //Compare 2 players by game experience
    bool operator<(const Player& other) const;
    bool operator>(const Player& other) const;
    bool operator==(const Player& other) const;
    bool operator!=(const Player& other) const;
    bool operator<=(const Player& other) const;
    bool operator>=(const Player& other) const;
};



#endif //PLAYER_H