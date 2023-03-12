#ifndef __ABILITY_HPP__
#define __ABILITY_HPP__

#include <iostream>
#include <string>
#include "../Deck/Deck.hpp"
// #include "../Player/Player.hpp"
// #include "../Card/Card.hpp"
// #include "../PlayerList/PlayerList.hpp"


class Ability{
private:
    std::string AbilityName ;
    int idAbility ;
    // Deck<Card> deck;
    // Player hen;

public:
    Ability();
    // Ability(int); 
    ~Ability();
    int getAbility();
    void setAbility(int);
    virtual void use() = 0 ;
};

// template <typename T>
// class ReRoll : public Ability {
//     public :
//         ReRoll();
//         void use(int index1, int index2) override ;
         
// };

template <typename T>
class ReRoll : public Ability {
    private :
        Deck<T> d;
        Player p ;
    public :
        Deck<T> getDeck();
        Player getPlayer();
        ReRoll();
        void use(int index1, int index2) override ;        
};

class Mult: public Ability {
    private :
        
    public :
        void quadruple();
        void quarter();
    

};
class ReverseDirection : public Ability {
    public :
        ReverseDirection();
        
    

};
class SwapCard : public Ability {
    public :
        SwapCard();
    

};
class Switch: public Ability {
    public :
        Switch();
    

};
class Abilityless : public Ability {
    public :
        Abilityless();
    

};


#endif