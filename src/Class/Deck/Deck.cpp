#include "Deck.hpp"
#include "../Card/Card.cpp"
#include "../Ability/Ability.cpp"
#include <algorithm>
// #include "../Player/Player.hpp"

template <typename T>
Deck<T>::Deck() {
    this->length = 0;
}

template <typename T>
Deck<T>::~Deck() {
    this->length = 0;
}

template <typename T>
void Deck<T>::addCard(T card) {
    this->cardBuffer.push_back(card);
    this->length++;
}

template <typename T>
void Deck<T>::shuffle() {
    std::random_shuffle(this->cardBuffer.begin(), this->cardBuffer.end());
}

template <typename T>
void Deck<T>::roll() {
    this->cardBuffer.push_back(T());
    this->length++;
}

template <typename T>
void Deck<T>::getValues() {
    for (int i = 0; i < this->length; i++) {
        this->cardBuffer[i].displaycard();
    }
}

int main()
{
    Deck<Card> deck;
    Deck<Ability> tot;
    int k = 1;
    for (int i = 1; i < 14 ; i++) {
        deck.addCard(Card(i, "green"));
        deck.addCard(Card(i, "blue"));
        deck.addCard(Card(i, "yellow"));
        deck.addCard(Card(i, "red"));
    }
    tot.addCard(1);
    tot.addCard(2);
    deck.getValues();
    tot.getValues();
    
    return 0;
}
