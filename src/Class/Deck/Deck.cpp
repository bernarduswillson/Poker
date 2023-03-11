#include "Deck.hpp"

template <typename T>
Deck<T>::Deck()
{
    this->length = 0;
}

template <typename T>
Deck<T>::~Deck()
{
    this->length = 0;
}

template <typename T>
void Deck<T>::addCard(T card)
{
    this->cardBuffer.push_back(card);
    this->length++;
}

template <typename T>
void Deck<T>::shuffle()
{
    std::srand(time(0));
    std::random_shuffle(this->cardBuffer.begin(), this->cardBuffer.end());
}

// template <>
// void Deck<Card>::roll(PlayerList &players, std::vector<Card> &table)
// {
//     for (int j = 0; j < 2; j++)
//     {
//         for (int i = 0; i < players.getNumOfPlayers(); i++)
//         {
//             Card card = this->cardBuffer.back();
//             this->cardBuffer.pop_back();
//             players.getPlayer(i).setHand(card);
//         }
//     }
//     for (int i = 0; i < 5; i++)
//     {
//         Card card = this->cardBuffer.back();
//         this->cardBuffer.pop_back();
//         table.push_back(card);
//     }
// }

template <typename T>
void Deck<T>::getValues()
{
    for (int i = 0; i < cardBuffer.size(); i++)
    {
        this->cardBuffer[i].displaycard();
    }
}

template <typename T>
T Deck<T>::drawCard()
{
    T card = this->cardBuffer.back();
    this->cardBuffer.pop_back();
    return card;
}

template <typename T>
void Deck<T>::displayDeck()
{
    for (int i = 0; i < this->cardBuffer.size(); i++)
    {
        this->cardBuffer[i].displaycard();
    }
}

