#include "doctest.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

using namespace doctest;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("test stacksize() with draw") {
    cout << "testing..." << endl;

    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    for (int i = 0; i < 5; i++) {
        game.playTurn();
    }
    
    int result = p1.stacksize();
    REQUIRE(result != 21);
    cout << "there was a draw - " << result << endl;
}

TEST_CASE("test stacksize() with draw") {
    cout << "testing..." << endl;

    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    for (int i = 0; i < 5; i++) {
        game.playTurn();
    }
    
    REQUIRE(p1.stacksize() == p2.stacksize());
    cout << "Player1 has " << p1.stacksize() << " cards, Player2 has " << p2.stacksize() << " cards";
}

TEST_CASE("test stacksize() without draw") {
    cout << "testing..." << endl;

    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    for (int i = 0; i < 5; i++) {
        game.playTurn();
    }
    
    int result = p1.stacksize();
    REQUIRE(result == 21);
    cout << "there was no draw - " << result << endl;
}

TEST_CASE("test stacksize() alice wins") {
    cout << "testing..." << endl;

    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    for (int i = 0; i < 5; i++) {
        game.playTurn();
    }
    
    REQUIRE(p1.stacksize() > p2.stacksize());
    cout << "Player1 has " << p1.stacksize() << " cards, Player2 has " << p2.stacksize() << " cards";
}

TEST_CASE("test stacksize() bob wins") {
    cout << "testing..." << endl;

    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    for (int i = 0; i < 5; i++) {
        game.playTurn();
    }
    
    REQUIRE(p1.stacksize() < p2.stacksize());
    cout << "Player1 has " << p1.stacksize() << " cards, Player2 has " << p2.stacksize() << " cards";
}

TEST_CASE("test cardesTaken() with draw") {
    cout << "testing..." << endl;

    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    for (int i = 0; i < 5; i++) {
        game.playTurn();
    }
    
    int result = p1.cardesTaken();
    REQUIRE(result != 5);
    cout << "there was a draw - " << result << endl;
}

TEST_CASE("test cardesTaken()") {
    cout << "testing..." << endl;

    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    for (int i = 0; i < 5; i++) {
        game.playTurn();
    }
    

    int result = p1.cardesTaken();
    REQUIRE(result == 5);
    cout << "there was no draw - " << result << endl;
}

TEST_CASE("test valid card") {
    cout << "testing..." << endl;

    Player p1("Alice");
    Player p2("Bob");

    int result = p1.getLastCardTaken().getNumber();
    REQUIRE(result >=1);
    REQUIRE(result <=13);
    cout << "card's valid = " << result << endl;
}

TEST_CASE("test two different players") {
    cout << "testing..." << endl;

    Player p1("Alice");
    Player p2("Bob");

    REQUIRE(p1.getPlayerName().compare(p2.getPlayerName()) == -1);

    cout << "Player1 name = " << p1.getPlayerName() << ", Player2 name = " << p2.getPlayerName() << endl;
}

TEST_CASE("test same players names") {
    cout << "testing..." << endl;

    Player p1("Alice");
    Player p2("Alice");

    REQUIRE(p1.getPlayerName().compare(p2.getPlayerName()) == 0);

    cout << "Player1 name = " << p1.getPlayerName() << ", Player2 name = " << p2.getPlayerName() << endl;
}

TEST_CASE("test alice wins") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    for (int i = 0; i < 5; i++) {
        game.playTurn();
    }

    REQUIRE(p1.getLastCardTaken().getNumber() > p2.getLastCardTaken().getNumber());

    cout << "Player1 last card = " << p1.getLastCardTaken().getNumber() << ", Player2 last card = " << p2.getLastCardTaken().getNumber();
}

TEST_CASE("test bob wins") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    for (int i = 0; i < 5; i++) {
        game.playTurn();
    }

    REQUIRE(p1.getLastCardTaken().getNumber() < p2.getLastCardTaken().getNumber());

    cout << "Player1 last card = " << p1.getLastCardTaken().getNumber() << ", Player2 last card = " << p2.getLastCardTaken().getNumber();
}

TEST_CASE("test draw") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    for (int i = 0; i < 5; i++) {
        game.playTurn();
    }

    REQUIRE(p1.getLastCardTaken().getNumber() == p2.getLastCardTaken().getNumber());

    cout << "Player1 last card = " << p1.getLastCardTaken().getNumber() << ", Player2 last card = " << p2.getLastCardTaken().getNumber();
}

TEST_CASE("alice has cards objects") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    for (int i = 0; i < 5; i++) {
        game.playTurn();
    }

    REQUIRE(p1.getCardsTaken() != NULL);

    cout << "Player1 last card = " << p1.getLastCardTaken().getNumber();
}

TEST_CASE("bob has cards objects") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    for (int i = 0; i < 5; i++) {
        game.playTurn();
    }

    REQUIRE(p1.getCardsTaken() != NULL);

    cout << "Player2 last card = " << p2.getLastCardTaken().getNumber();
}

TEST_CASE("two different player objects") {
    Player p1("Alice");
    Player p2("Bob");

    REQUIRE(&p1 != &p2);

    cout << "Player1 address = " << &p1 << ", Player2 address = " << &p2;
}

TEST_CASE("valid play rounds") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    for (int i = 0; i < 5; i++) {
        game.playTurn();
    }

    REQUIRE(game.getPlayRounds() == 5);

    cout << "game play rounds = " << game.getPlayRounds();
}

TEST_CASE("valid player1") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    for (int i = 0; i < 5; i++) {
        game.playTurn();
    }

    REQUIRE(game.getPlayer1().getPlayerName() == p1.getPlayerName());

    cout << "game's Player1 name = " << game.getPlayer1().getPlayerName() << "Player1 actual name = " << p1.getPlayerName();
}

TEST_CASE("valid player2") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 
    for (int i = 0; i < 5; i++) {
        game.playTurn();
    }

    REQUIRE(game.getPlayer2().getPlayerName() == p2.getPlayerName());

    cout << "game's Player2 name = " << game.getPlayer2().getPlayerName() << "Player2 actual name = " << p2.getPlayerName();
}

TEST_CASE("valid game's players addresses") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2); 

    Player gameP1 = game.getPlayer1();
    REQUIRE(&gameP1 != &p1);

    cout << "game's Player1 address = " << &gameP1 << "Player1 actual address = " << &p1;

}