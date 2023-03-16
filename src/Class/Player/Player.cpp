#include "Player.hpp"
#include <bits/stdc++.h>

// === CONSTRUCTOR DESTRUCTOR ==================================
Player::Player()
{
    this->points = 0;
    this->isDisable = false;
}

void Player::operator=(const Player &other)
{
    this->name = other.name;
    this->points = other.points;
    this->isDisable = other.isDisable;
    for (int i = 0; i < 2; i++)
    {
        this->hands[i] = other.hands[i];
    }
    this->highestCombo = other.highestCombo;
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

bool Player::getIsDisable()
{
    return this->isDisable;
}

void Player::setIsDisable()
{
    this->isDisable = !this->isDisable;
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

bool Player::operator>=(Player &other)
{
    return this->points >= other.points;
}

bool Player::operator>(Player &other)
{
    return this->points > other.points;
}

bool Player::operator<(Player &other)
{
    return this->points < other.points;
}

// void Player::operator-(Card removedCard) {

// }

std::vector<Card> Player::sortCard(std::vector<Card> card)
{
    std::vector<double> value;
    std::vector<Card> result;

    for (int i = 0; i < card.size(); i++)
    {
        value.push_back(card[i].getValue());
    }
    std::sort(value.begin(), value.end(), std::greater<double>());
    for (int i = 0; i < value.size(); i++)
    {
        for (int j = 0; j < card.size(); j++)
        {
            if (value[i] == card[j].getValue())
            {
                result.push_back(card[j]);
            }
        }
    }
    return result;
}

// === METHOD ==================================================
void Player::inputName()
{
    std::string inputName;
    std::cout << "Enter player name: ";
    std::cin >> inputName;
    this->name = inputName;
}
// void findCombo(Package table) {

void Player::resetHands()
{
    this->hands.clear();
}

std::pair<bool, std::vector<Card>> Player::isPair(std::vector<Card> card)
{
    std::vector<Card> result;
    card = sortCard(card);
    for (int i = 0; i < card.size(); i++)
    {
        for (int j = i + 1; j < card.size(); j++)
        {
            if (card[i].getNumber() == card[j].getNumber())
            {
                result.push_back(card[i]);
                result.push_back(card[j]);
                return std::make_pair(true, result);
            }
        }
    }
    return std::make_pair(false, result);
}

std::pair<bool, std::vector<Card>> Player::isTwoPair(std::vector<Card> card)
{
    std::vector<Card> result;
    card = sortCard(card);
    int maxValue = 0;
    int count = 0;
    for (int i = 0; i < card.size(); i++)
    {
        for (int j = i + 1; j < card.size(); j++)
        {
            if (card[i].getNumber() == card[j].getNumber())
            {
                result.push_back(card[i]);
                result.push_back(card[j]);
                count++;
                i++;
                j++;
                if (count == 2)
                {
                    return std::make_pair(true, result);
                }
            }
        }
    }
    return std::make_pair(false, result);
}

std::pair<bool, std::vector<Card>> Player::isThreeOfAKind(std::vector<Card> card)
{
    std::vector<Card> result;
    card = sortCard(card);
    bool trip = false;
    int tripValue;
    int count = 0;
    for (int i = 0; i < card.size() - 1; i++)
    {
        if (card[i].getNumber() == card[i + 1].getNumber())
        {
            result.push_back(card[i]);
            count++;
            if (count == 2)
            {
                result.push_back(card[i + 1]);
                trip = true;
                break;
            }
        }
        else
        {
            result.clear();
            count = 0;
        }
    }
    if (trip)
    {
        return std::make_pair(true, result);
    }
    return std::make_pair(false, result);
}

std::pair<bool, std::vector<Card>> Player::isStraight(std::vector<Card> card)
{
    std::vector<Card> result;
    card = sortCard(card);
    for (int i = 0; i < card.size(); i++)
    {
        for (int j = 0; j < card.size(); j++)
        {
            if (card[i].getNumber() == card[j].getNumber() && i != j)
            {
                card.erase(card.begin() + j);
            }
        }
    }
    int count = 0;
    for (int i = 0; i < card.size() - 1; i++)
    {
        if (card[i].getNumber() == card[i + 1].getNumber() + 1)
        {
            result.push_back(card[i]);
            count++;
            if (count == 4)
            {
                result.push_back(card[i + 1]);
                return std::make_pair(true, result);
            }
        }
        else
        {
            result.clear();
            count = 0;
        }
    }
    return std::make_pair(false, result);
}

std::pair<bool, std::vector<Card>> Player::isFlush(std::vector<Card> card)
{
    std::vector<Card> result;
    std::vector<Card> H, B, K, M;
    card = sortCard(card);
    for (int i = 0; i < card.size(); i++)
    {
        if (card[i].getColor() == 3)
        {
            M.push_back(card[i]);
        }
        else if (card[i].getColor() == 2)
        {
            K.push_back(card[i]);
        }
        else if (card[i].getColor() == 1)
        {
            B.push_back(card[i]);
        }
        else if (card[i].getColor() == 0)
        {
            H.push_back(card[i]);
        }
    }

    if (M.size() >= 5)
    {
        return std::make_pair(true, M);
    }
    else if (K.size() >= 5)
    {
        return std::make_pair(true, K);
    }
    else if (B.size() >= 5)
    {
        return std::make_pair(true, B);
    }
    else if (H.size() >= 5)
    {
        return std::make_pair(true, H);
    }

    return std::make_pair(false, result);
}

std::pair<bool, std::vector<Card>> Player::isFullHouse(std::vector<Card> card)
{
    std::vector<Card> result;
    bool trip = false, doub = false;
    card = sortCard(card);
    int progress = 0;
    int count = 0;
    std::vector<Card> temp;
    // kalo 3 dulu yang muncul
    for (int i = 0; i < card.size() - 1; i++)
    {
        if (card[i].getNumber() == card[i + 1].getNumber())
        {
            result.push_back(card[i]);
            count++;
            if (count == 2)
            {
                result.push_back(card[i + 1]);
                progress = i;
                trip = true;
                break;
            }
        }
        else
        {
            result.clear();
            count = 0;
            trip = false;
        }
    }
    count = 0;
    if (trip)
    {
        for (int i = progress + 2; i < card.size() - 1; i++)
        {
            if (card[i].getNumber() == card[i + 1].getNumber())
            {
                temp.push_back(card[i]);
                count++;
                if (count == 1)
                {
                    temp.push_back(card[i + 1]);
                    doub = true;
                    break;
                }
            }
            else
            {
                temp.clear();
                count = 0;
                doub = false;
            }
        }
    }

    for (int i = 0; i < temp.size(); i++)
    {
        result.push_back(temp[i]);
    }

    // kalo 2 dulu yang muncul
    if (!doub)
    {
        result.clear();
        temp.clear();
        count = 0;
        trip = false, doub = false;
        progress = 0;

        for (int i = 0; i < card.size() - 1; i++)
        {
            if (card[i].getNumber() == card[i + 1].getNumber())
            {
                temp.push_back(card[i]);
                count++;
                if (count == 1)
                {
                    temp.push_back(card[i + 1]);
                    progress = i;
                    doub = true;
                    break;
                }
            }
            else
            {
                temp.clear();
                count = 0;
                doub = false;
            }
        }
        count = 0;
        if (doub)
        {
            for (int i = progress + 2; i < card.size() - 1; i++)
            {
                if (card[i].getNumber() == card[i + 1].getNumber())
                {
                    result.push_back(card[i]);
                    count++;
                    if (count == 2)
                    {
                        result.push_back(card[i + 1]);
                        trip = true;
                        break;
                    }
                }
                else
                {
                    result.clear();
                    count = 0;
                    trip = false;
                }
            }
        }
        for (int i = 0; i < temp.size(); i++)
        {
            result.push_back(temp[i]);
        }
    }

    if (trip && doub)
    {
        return std::make_pair(true, result);
    }
    return std::make_pair(false, result);
}

std::pair<bool, std::vector<Card>> Player::isFourOfAKind(std::vector<Card> card)
{
    std::vector<Card> result;
    card = sortCard(card);

    int count = 0;
    for (int i = 0; i < card.size() - 1; i++)
    {
        if (card[i].getNumber() == card[i + 1].getNumber())
        {
            result.push_back(card[i]);
            count++;
            if (count == 3)
            {
                result.push_back(card[i + 1]);
                return std::make_pair(true, result);
            }
            else
            {
            }
        }
        else
        {
            result.clear();
            count = 0;
        }
    }

    return std::make_pair(false, result);
}

std::pair<bool, std::vector<Card>> Player::isStraightFlush(std::vector<Card> card)
{
    std::vector<Card> result;
    std::vector<Card> H, B, K, M;
    std::vector<Card> sameColor;
    for (int i = 0; i < card.size(); i++)
    {
        if (card[i].getColor() == 3)
        {
            M.push_back(card[i]);
        }
        else if (card[i].getColor() == 2)
        {
            K.push_back(card[i]);
        }
        else if (card[i].getColor() == 1)
        {
            B.push_back(card[i]);
        }
        else if (card[i].getColor() == 0)
        {
            H.push_back(card[i]);
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

    card = sortCard(sameColor);

    int count = 0;
    if (card.size() >= 5)
    {
        for (int i = 0; i < card.size() - 1; i++)
        {
            if (card[i].getNumber() == card[i + 1].getNumber() + 1)
            {
                result.push_back(card[i]);
                count++;
                if (count == 4)
                {
                    result.push_back(card[i + 1]);
                    return std::make_pair(true, result);
                }
            }
            else
            {
                result.clear();
                count = 0;
            }
        }
    }

    return std::make_pair(false, result);
}

// int main() {
//     Player player;
//     Table table;
//     std::vector<Card> card;
//     // card.push_back(Card(1, 1));
//     card.push_back(Card(1, 2));
//     card.push_back(Card(2, 3));
//     // card.push_back(Card(5, 1));
//     // card.push_back(Card(4, 1));
//     table.push(Card(1, 3));
//     table.push(Card(5, 3));
//     table.push(Card(4, 3));
//     table.push(Card(3, 3));
//     table.push(Card(6, 3));
//     //add hand
//     player.setHands(card);
//     // std::pair<bool, std::vector<Card>> pair = player.isPair(card);
//     // std::cout << pair.first << std::endl;
//     // std::cout << pair.second.getValue() << std::endl;
//     // std::cout << pair.second.getNumber() << std::endl;
//     // std::cout << pair.second.getColor() << std::endl;
//     // player.getHighestCombo() = new Pair(pair.second);
//     player.findCombo(table);
//     std::cout << player.getHighestCombo().getValue() << std::endl;
// }

void Player::findCombo(Table river)
{
    Package *p;
    Package *p2;
    std::vector<Card> table;
    std::vector<Card> card;
    for (int i = 0; i < river.getLength(); i++)
    {
        card.push_back(river.getElmt(i));
        table.push_back(river.getElmt(i));
    }

    table = sortCard(table);

    std::pair<bool, std::vector<Card>> tpair = this->isPair(table);
    std::pair<bool, std::vector<Card>> tdoub = this->isTwoPair(table);
    std::pair<bool, std::vector<Card>> ttrip = this->isThreeOfAKind(table);
    std::pair<bool, std::vector<Card>> tstra = this->isStraight(table);
    std::pair<bool, std::vector<Card>> tflush = this->isFlush(table);
    std::pair<bool, std::vector<Card>> tfull = this->isFullHouse(table);
    std::pair<bool, std::vector<Card>> tfour = this->isFourOfAKind(table);
    std::pair<bool, std::vector<Card>> tstraFlush = this->isStraightFlush(table);

    if (tstraFlush.first)
    {
        p = new StraightFlush(tstraFlush.second);
    }
    else if (tfour.first)
    {
        p = new FourOfAKind(tfour.second);
    }
    else if (tfull.first)
    {
        p = new FullHouse(tfull.second);
    }
    else if (tflush.first)
    {
        p = new Flush(tflush.second);
    }
    else if (tstra.first)
    {
        p = new Straight(tstra.second);
    }
    else if (ttrip.first)
    {
        p = new ThreeOfAKind(ttrip.second);
    }
    else if (tdoub.first)
    {
        p = new TwoPair(tdoub.second);
    }
    else if (tpair.first)
    {
        p = new Pair(tpair.second);
    }
    else
    {
        p = new HighCard(table);
    }

    // cek tangan

    card.push_back(this->hands[0]);
    card.push_back(this->hands[1]);

    card = sortCard(card);

    std::pair<bool, std::vector<Card>> pair = this->isPair(card);
    std::pair<bool, std::vector<Card>> doub = this->isTwoPair(card);
    std::pair<bool, std::vector<Card>> trip = this->isThreeOfAKind(card);
    std::pair<bool, std::vector<Card>> stra = this->isStraight(card);
    std::pair<bool, std::vector<Card>> flush = this->isFlush(card);
    std::pair<bool, std::vector<Card>> full = this->isFullHouse(card);
    std::pair<bool, std::vector<Card>> four = this->isFourOfAKind(card);
    std::pair<bool, std::vector<Card>> straFlush = this->isStraightFlush(card);

    bool found = false;

    if (straFlush.first && !found)
    {
        p2 = new StraightFlush(straFlush.second);
        if (p2->getValue() == p->getValue())
        {
            delete p2;

            p2 = new StraightFlush(straFlush.second);
            if (p2->getValue() == p->getValue())
            {
                delete p2;
                straFlush.second.erase((straFlush.second.begin()));
                std::vector<Card> temp, temp2, temp3, temp4;
                // temp 1 buat straight
                temp = table;
                if (hands[0].getNumber() == 13 || hands[1].getNumber() == 13)
                {
                    temp.erase(temp.begin());
                }
                for (int i = 0; i < temp.size(); i++)
                {
                    if (temp[i].getNumber() == this->hands[0].getNumber())
                    {
                        temp.erase(temp.begin() + i);
                    }
                }
                for (int i = 0; i < temp.size(); i++)
                {
                    if (temp[i].getNumber() == this->hands[1].getNumber())
                    {
                        temp.erase(temp.begin() + i);
                    }
                }

                temp.push_back(this->hands[0]);
                temp.push_back(this->hands[1]);
                temp = sortCard(temp);
                stra = this->isStraight(temp);

                // temp2 buat flush
                temp2 = table;
                sortCard(temp2);
                temp2.erase(temp2.begin());
                temp2.push_back(this->hands[0]);
                temp2.push_back(this->hands[1]);
                flush = this->isFlush(temp2);

                // temp3 buat straight flush
                temp3 = table;
                sortCard(temp3);
                // check if hand have the before or after card with the same colour
                if (this->hands[0].getNumber() == temp3[4].getNumber() - 1 && this->hands[0].getColor() == temp3[4].getColor())
                {
                    temp3.erase(temp3.begin());
                }
                if (this->hands[1].getNumber() == temp3[4].getNumber() - 1 && this->hands[1].getColor() == temp3[4].getColor())
                {
                    temp3.erase(temp3.begin());
                }
                temp3.push_back(this->hands[0]);
                temp3.push_back(this->hands[1]);
                temp4 = card;
                if (this->hands[0].getNumber() == this->hands[1].getNumber())
                {
                    pair = this->isPair(temp4);
                }
                std::pair<bool, std::vector<Card>> nstraFlush = this->isStraightFlush(temp3);
                if (nstraFlush.first)
                {
                    p2 = new StraightFlush(nstraFlush.second);
                    if (p2->getValue() == p->getValue())
                    {
                        delete p2;
                    }
                    else
                    {
                        found = true;
                    }
                }
                else
                {
                    found = false;
                }
            }
            else
            {
                found = true;
            }
        }
        else
        {
            found = true;
        }
    }
    if (four.first && !found)
    {
        p2 = new FourOfAKind(four.second);
        if (p2->getValue() == p->getValue())
        {
            delete p2;
        }
        else
        {
            found = true;
        }
    }
    if (full.first && !found)
    {
        p2 = new FullHouse(full.second);
        if (p2->getValue() == p->getValue())
        {
            delete p2;
            std::vector<Card> temp;
            temp = table;
            temp.erase((temp.begin()));
            temp.push_back(this->hands[0]);
            temp.push_back(this->hands[1]);
            temp = sortCard(temp);
            // for (int i = 0; i < temp.size(); i++)
            // {
            //     std::cout << temp[i].getValue() << std::endl;
            // }
            std::pair<bool, std::vector<Card>> nfull = this->isFullHouse(temp);
            if (nfull.first)
            {
                p2 = new FullHouse(nfull.second);
                if (p2->getValue() == p->getValue())
                {
                    delete p2;
                }
                else
                {
                    found = true;
                }
            }
            else
            {
                found = false;
            }
        }
        else
        {
            found = true;
        }
    }
    if (flush.first && !found)
    {
        p2 = new Flush(flush.second);
        if (p2->getValue() == p->getValue())
        {
            delete p2;
        }
        else
        {
            found = true;
        }
    }
    if (stra.first && !found)
    {
        p2 = new Straight(stra.second);
        if (p2->getValue() == p->getValue())
        {
            delete p2;
            std::vector<Card> temp;
            temp = stra.second;
            for (int i = 0; i < temp.size(); i++)
            {
                if (temp[i].getNumber() == this->hands[0].getNumber())
                {
                    temp.erase(temp.begin() + i);
                }
            }
            for (int i = 0; i < temp.size(); i++)
            {
                if (temp[i].getNumber() == this->hands[1].getNumber())
                {
                    temp.erase(temp.begin() + i);
                }
            }
            temp.push_back(this->hands[0]);
            temp.push_back(this->hands[1]);
            temp = sortCard(temp);
            // print temp
            for (int i = 0; i < temp.size(); i++)
            {
                std::cout << temp[i].getValue() << std::endl;
            }
            std::pair<bool, std::vector<Card>> nstra = this->isStraight(temp);
            // print nstra.second
            for (int i = 0; i < nstra.second.size(); i++)
            {
                std::cout << nstra.second[i].getValue() << std::endl;
            }
            if (nstra.first)
            {
                p2 = new Straight(nstra.second);
                if (p2->getValue() == p->getValue())
                {
                    delete p2;
                }
                else
                {
                    found = true;
                }
            }
            else
            {
                found = false;
            }
        }
        else
        {
            found = true;
        }
    }
    if (trip.first && !found)
    {
        p2 = new ThreeOfAKind(trip.second);
        if (p2->getValue() == p->getValue())
        {
            delete p2;
            // erase element in temp which is in trip.second
            for (int i = 0; i < trip.second.size() - 1; i++)
            {
                for (int j = 0; j < card.size(); j++)
                {
                    if (trip.second[i].getNumber() == card[j].getNumber())
                    {
                        card.erase((card.begin() + j));
                    }
                }
            }
            // print temp
            card = sortCard(card);
            for (int i = 0; i < card.size(); i++)
            {
                std::cout << card[i].getValue() << std::endl;
            }
            std::pair<bool, std::vector<Card>> ntrip = this->isThreeOfAKind(card);
            if (ntrip.first)
            {
                p2 = new ThreeOfAKind(ntrip.second);
                if (p2->getValue() == p->getValue())
                {
                    delete p2;
                }
                else
                {
                    found = true;
                }
            }
            else
            {
                std::pair<bool, std::vector<Card>> npair = this->isPair(card);
                std::pair<bool, std::vector<Card>> ndoub = this->isTwoPair(card);
                if (npair.first)
                {
                    p2 = new Pair(npair.second);
                    if (p2->getValue() == p->getValue())
                    {
                        delete p2;
                    }
                    else
                    {
                        found = true;
                    }
                }
                else if (ndoub.first)
                {
                    p2 = new TwoPair(ndoub.second);
                    if (p2->getValue() == p->getValue())
                    {
                        delete p2;
                    }
                    else
                    {
                        found = true;
                    }
                }
                else
                {
                    p2 = new HighCard(hands);
                    if (p2->getValue() == p->getValue())
                    {
                        delete p2;
                    }
                    else
                    {
                        found = true;
                    }
                }
            }
        }
        else
        {
            found = true;
        }
    }
    if (doub.first && !found)
    {
        p2 = new TwoPair(doub.second);
        if (p2->getValue() == p->getValue())
        {
            delete p2;
        }
        else
        {
            found = true;
        }
    }
    if (pair.first && !found)
    {
        p2 = new Pair(pair.second);
        if (p2->getValue() == p->getValue())
        {
            delete p2;
        }
        else
        {
            found = true;
        }
    }
    if (!found)
    {
        p2 = new HighCard(hands);
        if (p2->getValue() == p->getValue())
        {
            delete p2;
        }
        else
        {
            found = true;
        }
    }

    //     if (p->getValue() == p2->getValue())
    //     {
    //         if (straFlush.first)
    //         {
    //             p2 = new StraightFlush(straFlush.second);
    //             if (p2->getValue() < p->getValue())
    //             {
    //                 p2 = new StraightFlush(straFlush.second);
    //             }
    //         }
    //         else if (four.first && p2->getValue() < p->getValue())
    //         {
    //             p2 = new FourOfAKind(four.second);
    //         }
    //         else if (full.first && p2->getValue() < p->getValue())
    //         {
    //             p2 = new FullHouse(full.second);
    //         }
    //         else if (flush.first && p2->getValue() < p->getValue())
    //         {
    //             p2 = new Flush(flush.second);
    //         }
    //         else if (stra.first && p2->getValue() < p->getValue())
    //         {
    //             p2 = new Straight(stra.second);
    //         }
    //         else if (trip.first && p2->getValue() < p->getValue())
    //         {
    //             p2 = new ThreeOfAKind(trip.second);
    //         }
    //         else if (doub.first && p2->getValue() < p->getValue())
    //         {
    //             p2 = new TwoPair(doub.second);
    //         }
    //         else if (pair.first && p2->getValue() < p->getValue())
    //         {
    //             p2 = new Pair(pair.second);
    //         }
    //         else
    //         {
    //             p2 = new HighCard(card);
    //         }
    //     }
    this->highestCombo = *p2;
    std::cout << p2->getName() << std::endl;
}

Package Player::getHighestCombo()
{
    return this->highestCombo;
}

// === DISPLAY =================================================
void Player::displayHands()
{
    this->hands[0].displayCard();
    std::cout << " ";
    this->hands[1].displayCard();
}
