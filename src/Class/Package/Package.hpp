#ifndef __PACKAGE_HPP__
#define __PACKAGE_HPP__

#include <vector>
#include "../PlayerList/PlayerList.hpp"
#include "../Player/Player.hpp"

class Package
{
private:
    int packageType;

    std::vector<double> value;

public:
    Package();
    std::tuple<int, int> identifyPackage(std::vector<double> table, std::vector<double> player);
    void identifyWinner(std::vector<std::vector<double>>, std::vector<double> table); //masukannya harusnya playerlist
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