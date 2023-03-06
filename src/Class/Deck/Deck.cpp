#include "Deck.hpp"
#include "../Card/Card.cpp"
#include <algorithm>
#include <vector>
#include<iostream>
using namespace std;
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
    std::srand(time(0));
    std::random_shuffle(this->cardBuffer.begin(), this->cardBuffer.end());
}


template <>
void Deck<Card>::roll(PlayerList &players, std::vector <Card> &table) {
    for (int j=0; j<2;j++){
        for (int i = 0; i < players.getNumOfPlayers(); i++) {
            Card card = this->cardBuffer.back();
            this->cardBuffer.pop_back();
            players.getPlayer(i).setHand(card);
        }
    }
    for (int i = 0; i < 5; i++) {
        Card card = this->cardBuffer.back();
        this->cardBuffer.pop_back();
        table.push_back(card);
    }
}

template <typename T>
void Deck<T>::getValues() {
    for (int i = 0; i < cardBuffer.size(); i++) {
        this->cardBuffer[i].displaycard();
    }
}

int main()
{
    Deck<Card> deck;
    // Deck<Ability> tot;
    int k = 1;
    for (int i = 1; i < 14 ; i++) {
        deck.addCard(Card(i, "green"));
        deck.addCard(Card(i, "blue"));
        deck.addCard(Card(i, "yellow"));
        deck.addCard(Card(i, "red"));
    }
    // tot.addCard(1);
    // tot.addCard(2);
    deck.shuffle();
    deck.getValues();
    cout << "hhahaha"<< endl;
    // deck.roll();
    cout << endl;
    deck.getValues();
    
    // tot.getValues();
    
    return 0;
}
