#include "Player.hpp"
#include <cmath>
#include <bits/stdc++.h>

// === CONSTRUCTOR DESTRUCTOR ==================================
Player::Player()
{
    this->points = 0;
}

void Player::operator=(const Player &other)
{
    this->name = other.name;
    this->points = other.points;
    for (int i = 0; i < 2; i++)
    {
        this->hands[i] = other.hands[i];
    }
    // this->highestCombo = other.highestCombo;
}

Player::~Player() {}

// === GETTER SETTER ===========================================
std::string Player::getName()
{
    return this->name;
}

long long int Player::getPoints()
{
    return this->points;
}

std::vector<Card> Player::getHands()
{
    return this->hands;
}

Card Player::getHands(int idx)
{
    return this->hands[idx];
}

void Player::setHands(std::vector<Card> hands)
{
    this->hands = hands;
}

// === OPERATOR OVERLOADING ====================================
Player Player::operator+(long long int addedPoints)
{
    this->points += addedPoints;
    return *this;
}

Player Player::operator+(Card addedCard)
{
    this->hands.push_back(addedCard);
    return *this;
}

// void Player::operator-(Card removedCard) {

// }

// === METHOD ==================================================
void Player::inputName()
{
    std::string inputName;
    std::cout << "Enter player name: ";
    std::cin >> inputName;
    this->name = inputName;
}


std::pair<bool, Card> Player::isPair(std::vector<Card> card)
{
    std::vector<double> value;
    for (int i = 0; i < card.size(); i++)
    {
        value.push_back(card[i].getValue());
    }
    std::sort(value.begin(), value.end(), std::greater<double>());
    for (int i = 0; i < value.size(); i++)
    {
        for (int j = i + 1; j < value.size(); j++)
        {
            if (floor(value[i] * 10) == floor(value[j] * 10))
            {
                for (int k = 0; k < card.size(); k++)
                {
                    if (value[i] == card[k].getValue()) {
                        return std::make_pair(true, card[k]);
                    }
                }
            }
        }
    }
    return std::make_pair(false, card[0]);
}

std::pair<bool, Card> Player::isTwoPair(std::vector<Card> card)
{   
    std::vector<double> value;
    for (int i = 0; i < card.size(); i++)
    {
        value.push_back(card[i].getValue());
    }
    std::sort(value.begin(), value.end());
    int maxValue = 0;
    int count = 0;
    for (int i = 0; i < value.size(); i++)
    {
        for (int j = i + 1; j < value.size(); j++)
        {
            if (floor(value[i] * 10) == floor(value[j] * 10))
            {
                maxValue = round(value[j] * 100);
                count++;
            }
        }
    }
    if (count >= 2)
    {
        for (int k = 0; k < card.size(); k++)
        {
            if (maxValue == round(card[k].getValue() * 100))
            {
                return std::make_pair(true, card[k]);
            }
        }
    }
    return std::make_pair(false, card[0]);
}

std::pair<bool, Card> Player::isThreeOfAKind(std::vector<Card> card)
{
    std::vector<double> value;
    for (int i = 0; i < card.size(); i++)
    {
        value.push_back(card[i].getValue());
    }
    std::vector<int> sameValue;
    std::tuple<int, int> result;
    bool trip = false;
    int tripValue;
    for (int i = 0; i < value.size(); i++)
    {
        sameValue.push_back(round(value[i] * 100));
    }
    sort(sameValue.begin(), sameValue.end(), std::greater<int>());
    int count = 0;
    for (int i = 0; i < sameValue.size() - 1; i++)
    {
        if (floor(sameValue[i] / 10) == floor(sameValue[i + 1] / 10))
        {
            count++;
        }
        else
        {
            count = 0;
        }
        if (count == 2)
        {
            trip = true;
            tripValue = sameValue[i - 1];
            break;
        }
    }
    if (trip)
    {
        for (int i = 0; i < card.size(); i++)
        {
            if (tripValue == round(card[i].getValue() * 100))
            {
                return std::make_pair(true, card[i]);
            }
        }
    }
    return std::make_pair(false, card[0]);
}

std::pair<bool, Card> Player::isStraight(std::vector<Card> card)
{
    std::vector<double> value;
    for (int i = 0; i < card.size(); i++)
    {
        value.push_back(card[i].getValue());
    }
    std::vector<int> sameValue;
    std::tuple<int, int> result;
    for (int i = 0; i < value.size(); i++)
    {
        sameValue.push_back(floor(value[i] * 10) * 10);
    }
    sort(sameValue.begin(), sameValue.end(), std::greater<int>());
    int count = 0;
    int maxValue;
    for (int i = 0; i < sameValue.size() - 1; i++)
    {
        if (sameValue[i] == sameValue[i + 1] + 10)
        {
            count++;
            if (count == 1)
            {
                maxValue = sameValue[i];
            }
        }
        else if (sameValue[i] == sameValue[i + 1])
        {
            // do nothing
        }
        else
        {
            count = 0;
        }
        if (count == 4)
        {
            for (int j = 0; j < card.size(); j++)
            {
                if (maxValue == floor(card[j].getValue() * 10) * 10)
                {
                    return std::make_pair(true, card[j]);
                }
            }
        }
    }
    return std::make_pair(false, card[0]);
}

std::pair<bool, Card> Player::isFlush(std::vector<Card> card)
{
    std::vector<double> value;
    for (int i = 0; i < card.size(); i++)
    {
        value.push_back(card[i].getValue());
    }
    std::vector<int> H, B, K, M;
    std::tuple<int, int> result;
    sort(value.begin(), value.end(), std::greater<double>());
    for (int i = 0; i < value.size(); i++)
    {
        if (round(fmod(value[i] * 100, 10)) == 9)
        {
            M.push_back(round(value[i] * 100));
        }
        else if (round(fmod(value[i] * 100, 10)) == 6)
        {
            K.push_back(round(value[i] * 100));
        }
        else if (round(fmod(value[i] * 100, 10)) == 3)
        {
            B.push_back(round(value[i] * 100));
        }
        else if (round(fmod(value[i] * 100, 10)) == 0)
        {
            H.push_back(round(value[i] * 100));
        }
    }

    if (M.size() >= 5)
    {
        for (int i = 0; i < card.size(); i++)
        {
            if (M[0] == round(card[i].getValue() * 100))
            {
                return std::make_pair(true, card[i]);
            }
        }
    }
    else if (K.size() >= 5)
    {
        for (int i = 0; i < card.size(); i++)
        {
            if (K[0] == round(card[i].getValue() * 100))
            {
                return std::make_pair(true, card[i]);
            }
        }
    }
    else if (B.size() >= 5)
    {
        for (int i = 0; i < card.size(); i++)
        {
            if (B[0] == round(card[i].getValue() * 100))
            {
                return std::make_pair(true, card[i]);
            }
        }
    }
    else if (H.size() >= 5)
    {
        for (int i = 0; i < card.size(); i++)
        {
            if (H[0] == round(card[i].getValue() * 100))
            {
                return std::make_pair(true, card[i]);
            }
        }
    }

    return std::make_pair(false, card[0]);
}

std::pair<bool, Card> Player::isFullHouse(std::vector<Card> card)
{
    std::vector<double> value;
    for (int i = 0; i < card.size(); i++)
    {
        value.push_back(card[i].getValue());
    }
    std::vector<int> sameValue;
    std::tuple<int, int> result;
    bool trip = false, doub = false;
    int tripValue;
    for (int i = 0; i < value.size(); i++)
    {
        sameValue.push_back(round(value[i] * 100));
    }
    sort(sameValue.begin(), sameValue.end(), std::greater<int>());
    int progress = 0;
    int count = 0;
    // kalo 3 dulu yang muncul
    for (int i = 0; i < sameValue.size() - 1; i++)
    {
        if (floor(sameValue[i] / 10) == floor(sameValue[i + 1] / 10))
        {
            count++;
        }
        else
        {
            count = 0;
        }
        if (count == 2)
        {
            progress = i;
            trip = true;
            tripValue = sameValue[i - 1];
            break;
        }
    }
    count = 0;
    if (trip)
    {
        for (int i = progress; i < sameValue.size() - 1; i++)
        {
            if (floor(sameValue[i] / 10) == floor(sameValue[i + 1] / 10))
            {
                count++;
            }
            else
            {
                count = 0;
            }
            if (count == 1)
            {
                doub = true;
            }
        }
    }
    else
    { // kalo 2 dulu yang muncul
        count = 0;
        trip = false, doub = false;
        progress = 0;
        for (int i = 0; i < sameValue.size() - 1; i++)
        {
            if (floor(sameValue[i] / 10) == floor(sameValue[i + 1] / 10))
            {
                count++;
            }
            else
            {
                count = 0;
            }
            if (count == 1)
            {
                progress = i;
                doub = true;
                break;
            }
        }
        count = 0;
        if (doub)
        {
            for (int i = progress; i < sameValue.size() - 1; i++)
            {
                if (floor(sameValue[i] / 10) == floor(sameValue[i + 1] / 10))
                {
                    count++;
                }
                else
                {
                    count = 0;
                }
                if (count == 2)
                {
                    trip = true;
                    tripValue = sameValue[i - 1];
                }
            }
        }
    }

    if (trip && doub)
    {
        for (int i = 0; i < card.size(); i++)
        {
            if (tripValue == round(card[i].getValue() * 100))
            {
                return std::make_pair(true, card[i]);
            }
        }
    }
    return std::make_pair(false, card[0]);
}

std::pair<bool, Card> Player::isFourOfAKind(std::vector<Card> card)
{
    std::vector<double> value;
    for (int i = 0; i < card.size(); i++)
    {
        value.push_back(card[i].getValue());
    }
    std::vector<int> sameValue;
    std::tuple<int, int> result;
    for (int i = 0; i < value.size(); i++)
    {
        sameValue.push_back(round(value[i] * 100));
    }

    sort(sameValue.begin(), sameValue.end(), std::greater<int>());

    int count = 0;
    for (int i = 0; i < sameValue.size() - 1; i++)
    {
        if (floor(sameValue[i] / 10) == floor(sameValue[i + 1] / 10))
        {
            count++;
        }
        else
        {
            count = 0;
        }
        if (count == 3)
        {
            for (int j = 0; j < card.size(); j++)
            {
                if (sameValue[i-2] == round(card[j].getValue() * 100))
                {
                    return std::make_pair(true, card[j]);
                }
            }
        }
    }

    return std::make_pair(false, card[0]);
}

std::pair<bool, Card> Player::isStraightFlush(std::vector<Card> card)
{
    std::vector<double> value;
    for (int i = 0; i < card.size(); i++)
    {
        value.push_back(card[i].getValue());
    }
    std::vector<int> H, B, K, M;
    std::vector<int> sameColor;
    std::tuple<int, int> result;
    for (int i = 0; i < value.size(); i++)
    {
        if (round(fmod(value[i] * 100, 10)) == 9)
        {
            M.push_back(round(value[i] * 100));
        }
        else if (round(fmod(value[i] * 100, 10)) == 6)
        {
            K.push_back(round(value[i] * 100));
        }
        else if (round(fmod(value[i] * 100, 10)) == 3)
        {
            B.push_back(round(value[i] * 100));
        }
        else if (round(fmod(value[i] * 100, 10)) == 0)
        {
            H.push_back(round(value[i] * 100));
        }
    }

    if (M.size() >= 5)
    {
        sameColor = M;
    }
    else if (K.size() >= 5)
    {
        sameColor = K;
    }
    else if (B.size() >= 5)
    {
        sameColor = B;
    }
    else if (H.size() >= 5)
    {
        sameColor = H;
    }

    sort(sameColor.begin(), sameColor.end(), std::greater<int>());

    int count = 0;
    if (sameColor.size() >= 5)
    {
        for (int i = 0; i < sameColor.size() - 1; i++)
        {
            if (sameColor[i] == sameColor[i + 1] + 10)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            if (count == 4)
            {
                for (int j = 0; j < card.size(); j++)
                {
                    if (sameColor[i-3] == round(card[j].getValue() * 100))
                    {
                        return std::make_pair(true, card[j]);
                    }
                }
            }
        }
    }

    return std::make_pair(false, card[0]);
}


int main() {
    Player player;
    std::vector<Card> card;
    card.push_back(Card(1, 1));
    card.push_back(Card(2, 2));
    card.push_back(Card(3, 1));
    card.push_back(Card(5, 1));
    card.push_back(Card(4, 1));
    card.push_back(Card(6, 1));
    card.push_back(Card(7, 3));
    card.push_back(Card(7, 1));
    // card.push_back(Card(2, 2));
    std::pair<bool, Card> pair = player.isStraightFlush(card);
    std::cout << pair.first << std::endl;
    std::cout << pair.second.getValue() << std::endl;
    std::cout << pair.second.getNumber() << std::endl;
    std::cout << pair.second.getColor() << std::endl;
}



// void findCombo(Package river) {

// }

// === DISPLAY =================================================
void Player::displayHands()
{
    this->hands[0].displayCard();
    std::cout << " ";
    this->hands[1].displayCard();
}
