#ifndef __REROLL_HPP__
#define __REROLL_HPP__

#include "../Deck/Deck.hpp"
#include "Ability.hpp"

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

#endif