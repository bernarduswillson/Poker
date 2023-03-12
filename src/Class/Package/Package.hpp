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


};

#endif