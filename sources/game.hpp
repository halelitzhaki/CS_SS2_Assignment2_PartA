#ifndef GAME_HPP
#define GAME_HPP

#include "card.hpp"
#include "player.hpp"
#define NUM_OF_CARDS 52

namespace ariel {
    class Game
    {
        private:
            Player player1, player2;
            Card cards[NUM_OF_CARDS];
            int playRounds = 0;

        public:
            Game(Player,Player);
            ~Game();

            void playTurn();
            void printLastTurn();
            void playAll();
            void printWiner();
            void printLog(); 
            void printStats();
            int getPlayRounds();
            Player getPlayer1();
            Player getPlayer2();
    };
}

#endif