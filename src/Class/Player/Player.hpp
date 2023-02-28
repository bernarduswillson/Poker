#include <iostream>

class Player {
    private:
        std::string name;
        int points;
        int hand;
        int ability;
        int package;
        int gameState;
    public:
        Player();
        void playerAction();
        void winDisplay();
};