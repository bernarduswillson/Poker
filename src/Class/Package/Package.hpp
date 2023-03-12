#ifndef __PACKAGE_HPP__
#define __PACKAGE_HPP__

#include <vector>
#include "../PlayerList/PlayerList.hpp"
#include "../Player/Player.hpp"

class Package
{
private:
    int packageType;
    int straightFlushValue;

    std::vector<double> value;

public:
    Package();
    int identifyPackage(std::vector<Card> table, Player player);
    std::tuple<int, int> isStraightFlush(std::vector<double>);
    std::tuple<int, int> isFourKind(std::vector<double>);
    std::tuple<int, int> isFullHouse(std::vector<double>);
    std::tuple<int, int> isFlush(std::vector<double>);
    std::tuple<int, int> isStraight(std::vector<double>);
    std::tuple<int, int> isThreeKind(std::vector<double>);
    std::tuple<int, int> isTwoPair(std::vector<double>);
    std::tuple<int, int> isPair(std::vector<double>);


};

#endif