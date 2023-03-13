#include "Package.hpp"
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>



Package::Package() {
}

std::tuple<int, int> Package::identifyPackage(std::vector<double> table, std::vector<double> player) {
    std::vector<double> allCards;
    for (int i = 0; i < table.size(); i++) {
        allCards.push_back(table[i]);
    }
    for (int i = 0; i < player.size(); i++) {
        allCards.push_back(player[i]);
    }

    if (std::get<0>(isStraightFlush(allCards)) == 9) {
        std::cout << "Straight Flush" << std::endl;
        return std::make_tuple(9, std::get<1>(isStraightFlush(allCards)));
    }
    else if (std::get<0>(isFourKind(allCards)) == 8) {
        std::cout << "Four of a Kind" << std::endl;
        return std::make_tuple(8, std::get<1>(isFourKind(allCards)));
    }
    else if (std::get<0>(isFullHouse(allCards)) == 7) {
        std::cout << "Full House" << std::endl;
        return std::make_tuple(7, std::get<1>(isFullHouse(allCards)));
    }
    else if (std::get<0>(isFlush(allCards)) == 6) {
        std::cout << "Flush" << std::endl;
        return std::make_tuple(6, std::get<1>(isFlush(allCards)));
    }
    else if (std::get<0>(isStraight(allCards)) == 5) {
        std::cout << "Straight" << std::endl;
        return std::make_tuple(5, std::get<1>(isStraight(allCards)));
    }
    else if (std::get<0>(isThreeKind(allCards)) == 4) {
        std::cout << "Three of a Kind" << std::endl;
        return std::make_tuple(4, std::get<1>(isThreeKind(allCards)));
    }
    else if (std::get<0>(isTwoPair(allCards)) == 3) {
        std::cout << "Two Pair" << std::endl;
        return std::make_tuple(3, std::get<1>(isTwoPair(allCards)));
    }
    else if (std::get<0>(isPair(allCards)) == 2) {
        std::cout << "Pair" << std::endl;
        return std::make_tuple(2, std::get<1>(isPair(allCards)));
    }
    else {
        std::cout << "High Card" << std::endl;
        return std::make_tuple(1, 0);
    }
}

void Package::identifyWinner(std::vector<std::vector<double>> playerList, std::vector<double> table) {
    //identify package per player
    std::vector<std::tuple<int, int>> packageList;
    for (int i = 0; i < playerList.size(); i++) {
        packageList.push_back(identifyPackage(table, playerList[i]));
    }

    //compare package
    int winner = 0;
    for (int i = 0; i < packageList.size(); i++) {
        if (std::get<0>(packageList[i]) > std::get<0>(packageList[winner])) {
            winner = i;
        }
        else if (std::get<0>(packageList[i]) == std::get<0>(packageList[winner])) {
            if (std::get<1>(packageList[i]) > std::get<1>(packageList[winner])) {
                winner = i;
            }
        }
    }
    std::cout << std::endl;
    std::cout << "Winner is player " << winner + 1 << std::endl;
}

std::tuple<int, int> Package::isStraightFlush(std::vector<double> value) {
    std::vector<int> H, B, K, M;
    std::vector<int> sameColor;
    std::tuple<int, int> result;
    for (int i = 0; i < value.size(); i++) {
        if (round(fmod(value[i] * 100, 10)) == 9) {
            M.push_back(round(value[i]*100));
        }
        else if (round(fmod(value[i] * 100, 10)) == 6) {
            K.push_back(round(value[i]*100));
        }
        else if (round(fmod(value[i] * 100, 10)) == 3) {
            B.push_back(round(value[i]*100));
        }
        else if (round(fmod(value[i] * 100, 10)) == 0) {
            H.push_back(round(value[i]*100));
        }
    }

    if (M.size() >= 5){
        sameColor = M;
    }
    else if (K.size() >= 5){
        sameColor = K;
    }
    else if (B.size() >= 5){
        sameColor = B;
    }
    else if (H.size() >= 5){
        sameColor = H;
    }

    sort(sameColor.begin(), sameColor.end());

    int count = 0;
    if (sameColor.size() >= 5){
        for (int i = 0; i < sameColor.size() - 1; i++){
            if (sameColor[i] == sameColor[i+1] - 10){
                count++;
            }
            else {
                count = 0;
            }
            if (count == 4){
                result = std::make_tuple(9, sameColor[i]);
                return result;
            }
        }
    }

    return std::make_tuple(-1, -1);
}

std::tuple<int, int> Package::isFourKind(std::vector<double> value) {
    std::vector<int> sameValue;
    std::tuple<int, int> result;
    for (int i = 0; i < value.size(); i++) {
        sameValue.push_back(round(value[i]*100));
    }

    sort(sameValue.begin(), sameValue.end());

    int count = 0;
    for (int i = 0; i < sameValue.size() - 1; i++){
        if (floor(sameValue[i] / 10) == floor(sameValue[i+1] / 10)){
            count++;
        }
        else {
            count = 0;
        }
        if (count == 3){
            result = std::make_tuple(8, sameValue[i-1]);
            return result;
        }
    }

    return std::make_tuple(-1, -1);
}

std::tuple<int, int> Package::isFullHouse(std::vector<double> value) {
    std::vector<int> sameValue;
    std::tuple<int, int> result;
    bool trip = false, doub = false;
    int tripValue;
    for (int i = 0; i < value.size(); i++) {
        sameValue.push_back(round(value[i]*100));
    }
    sort(sameValue.begin(), sameValue.end());
    int progress = 0;
    int count = 0;
    // kalo 3 dulu yang muncul
    for (int i = 0; i < sameValue.size() - 1; i++){
        if (floor(sameValue[i] / 10) == floor(sameValue[i+1] / 10)){
            count++;
        }
        else {
            count = 0;
        }
        if (count == 2){
            progress = i;
            trip = true;
            tripValue = sameValue[i-1];
        }
    }
    if (trip == true){
        for (int i = progress; i < sameValue.size() - 1; i++){
            if (floor(sameValue[i] / 10) == floor(sameValue[i+1] / 10)){
                count++;
            }
            else {
                count = 0;
            }
            if (count == 1){
                doub = true;
            }
        }
    }
    else { // kalo 2 dulu yang muncul
        for (int i = 0; i < sameValue.size() - 1; i++){
            if (floor(sameValue[i] / 10) == floor(sameValue[i+1] / 10)){
                count++;
            }
            else {
                count = 0;
            }
            if (count == 1){
                progress = i;
                doub = true;
            }
        }
        if (doub == true){
            for (int i = progress; i < sameValue.size() - 1; i++){
                if (floor(sameValue[i] / 10) == floor(sameValue[i+1] / 10)){
                    count++;
                }
                else {
                    count = 0;
                }
                if (count == 2){
                    trip = true;
                    tripValue = sameValue[i-1];
                }
            }
        }
    }


    if (trip && doub){
        result = std::make_tuple(7, tripValue);
        return result;
    }
    return std::make_tuple(-1, -1);
}

std::tuple<int, int> Package::isFlush(std::vector<double> value) {
    std::vector<int> H, B, K, M;
    std::tuple<int, int> result;
    sort(value.begin(), value.end(), std::greater<double>());
    for (int i = 0; i < value.size(); i++) {
        if (round(fmod(value[i] * 100, 10)) == 9) {
            M.push_back(round(value[i]*100));
        }
        else if (round(fmod(value[i] * 100, 10)) == 6) {
            K.push_back(round(value[i]*100));
        }
        else if (round(fmod(value[i] * 100, 10)) == 3) {
            B.push_back(round(value[i]*100));
        }
        else if (round(fmod(value[i] * 100, 10)) == 0) {
            H.push_back(round(value[i]*100));
        }
    }

    if (M.size() >= 5){
        result = std::make_tuple(6, M[0]);
        return std::make_tuple(6, M[0]);
    }
    else if (K.size() >= 5){
        result = std::make_tuple(6, K[0]);
        return result;
    }
    else if (B.size() >= 5){
        result = std::make_tuple(6, B[0]);
        return result;
    }
    else if (H.size() >= 5){
        result = std::make_tuple(6, H[0]);
        return result;
    }
    

    return std::make_tuple(-1, -1);
}

std::tuple<int, int> Package::isStraight(std::vector<double> value) {
    std::vector<int> sameValue;
    std::tuple<int, int> result;
    int maxValue = -1;
    for (int i = 0; i < value.size(); i++) {
        sameValue.push_back(round(value[i]*100));
    }
    sort(sameValue.begin(), sameValue.end());
    int count = 0;
    for (int i = 0 ; i < sameValue.size() - 1 ; i++){
        if (sameValue[i+1] - sameValue[i] == 10) {
            count++;
            if (count == 4 ){
                maxValue = sameValue[i+1];
            }
        }
        else if (sameValue[i] != sameValue[i+1]){
            count = 0;
        }
    }
    if (maxValue != -1){
        result = std::make_tuple(5, maxValue);
        return result;
    }
    return std::make_tuple(-1, -1);
}


std::tuple<int, int> Package::isThreeKind(std::vector<double> value) {
    std::vector<int> sameValue;
    std::tuple<int, int> result;
    bool trip = false;
    int tripValue;
    for (int i = 0; i < value.size(); i++) {
        sameValue.push_back(round(value[i]*100));
    }
    sort(sameValue.begin(), sameValue.end());
    int count = 0;
    for (int i = 0; i < sameValue.size() - 1; i++){
        if (floor(sameValue[i] / 10) == floor(sameValue[i+1] / 10)){
            count++;
        }
        else {
            count = 0;
        }
        if (count == 2){
            trip = true;
            tripValue = sameValue[i-1];
        }
    }
    if (trip){
        result = std::make_tuple(4, tripValue);
        return result;
    }
    return std::make_tuple(-1, -1);
}

std::tuple<int, int> Package::isTwoPair(std::vector<double> value) {
    std::sort(value.begin(), value.end());
    int maxValue = 0;
    int count = 0;
    for (int i = 0; i < value.size(); i++) {
        for (int j = i + 1; j < value.size(); j++) {
            if (floor(value[i] * 10) == floor(value[j] * 10)) {
                maxValue = round(value[j]*100);
                count++;
            }
        }
    }
    if (count >= 2){
        return std::make_tuple(3, maxValue);
    }
    return std::make_tuple(-1, -1);
}

std::tuple<int, int> Package::isPair(std::vector<double> value) {
    std::sort(value.begin(), value.end(), std::greater<double>());
    for (int i = 0; i < value.size(); i++) {
        for (int j = i + 1; j < value.size(); j++) {
            if (floor(value[i] * 10) == floor(value[j] * 10)) {
                return std::make_tuple(2, value[i]*100);
            }
        }
    }
    return std::make_tuple(-1, -1);
}




int main() {
    //make vector of vector
    std::vector<std::vector<double>> hands;
    std::vector<double> hand1 = {1.33, 1.39};
    std::vector<double> hand2 = {0.93, 0.69};
    std::vector<double> hand3 = {0.36, 1.43};
    std::vector<double> hand4 = {0.23, 0.43};
    std::vector<double> hand5 = {0.5, 0.59};

    std::vector <double> table = {0.13, 0.33, 1.09, 1.36, 0.53};

    hands.push_back(hand1);
    hands.push_back(hand2);
    hands.push_back(hand3);
    hands.push_back(hand4);
    hands.push_back(hand5);

    //identify winner
    Package p;
    p.identifyWinner(hands, table);
}