#include "Ability.hpp"

Ability::Ability(){ 
    this->idAbility = 0 ;
}

Ability::~Ability(){}

int Ability::getAbility(){
    return this->idAbility ;
}

void Ability::setAbility(int idAbility){
    this->idAbility = idAbility ;
}

template <typename T>
ReRoll<T>::ReRoll() {}

template <typename T>
void ReRoll<T>::use(int index1, int index2) {
        Deck<T>  d = ReRoll::getDeck();
        Player p =  ReRoll::getPlayer();
        if (d.cardBuffer.size() >= 2) {
            std::cout << "Buang kartu " << index1 << " dan kartu " << index2 << std::endl;
            p.hand.erase(p.hand.begin() + index1);
            p.hand.erase(p.hand.begin() + index2);
            std::cout << "Ambil 2 kartu" << std::endl;
            for (int i = 0; i < 2; i++) {
                T newCard = d.cardBuffer.back();
                d.cardBuffer.pop_back();
                p.hand.push_back(newCard);
            }
        }
}

template <typename T>
Deck<T> ReRoll<T>::getDeck(){
    return d;
}

template <typename T>
Player ReRoll<T>::getPlayer(){
    return p;
}

int main(){
    std::cout<<"sayu"<<std::endl;
}
