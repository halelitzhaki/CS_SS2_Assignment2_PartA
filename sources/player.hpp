#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "card.hpp"
using namespace std;
#define NUM_OF_CARDS 52

namespace ariel {
    class Player
    {
        private:
            string name;
            Card *cardsTaken;
            int getCardsTakenSize;

        public:
            Player();
            Player(string);
            ~Player();

            int stacksize();
            int cardesTaken();
            Card* getCardsTaken();
            Card getLastCardTaken();
            string getPlayerName();
    };
}

#endif