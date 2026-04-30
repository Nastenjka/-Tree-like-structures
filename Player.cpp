#include "Player.h"

//Compare 2 players by game experiecne
bool Player::operator<(const Player& other) const {
    if (this->XP == other.XP) {
        return this->nickname < other.nickname;
    }
    return this->XP < other.XP;
}

bool Player::operator>(const Player& other) const {
    if (this->XP == other.XP) {
        return this->nickname > other.nickname;
    }
    return this->XP > other.XP;
}

bool Player::operator==(const Player& other) const {
    return (this->XP == other.XP) && (this->nickname == other.nickname);
}

bool Player::operator!=(const Player& other) const {
    return this->XP != other.XP;
}
bool Player::operator<=(const Player& other) const {
    return this->XP <= other.XP;
}
bool Player::operator>=(const Player& other) const {
    return this->XP >= other.XP;
}


