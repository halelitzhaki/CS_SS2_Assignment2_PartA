#include "player.hpp"

using namespace ariel;

Player::Player() {
    //TO DO
}

Player::Player(string name) {
    //TO DO
}

Player::~Player() {
    //TO DO
}

int Player::stacksize() {
    //TO DO
    return 0;
}

int Player::cardesTaken() {
    //TO DO
    return 0;
}

Card* Player::getCardsTaken() {
    return cardsTaken;
}

Card Player::getLastCardTaken() {
    //TO DO
    return NULL;
}

string Player::getPlayerName() {
    return name;
}