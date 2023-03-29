#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
using namespace std;

namespace ariel {
    class Card {
        private:
            int number;
        public:
            Card();
            Card(int);
            ~Card();
            
            int getNumber();
    };
}

#endif