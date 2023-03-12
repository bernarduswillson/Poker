#include "Package.hpp"
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

Package::Package() {
    this->value.push_back(0.1);
    this->value.push_back(0.2);
    this->value.push_back(0.3);
    this->value.push_back(0.4);
    this->value.push_back(0.5);
    this->value.push_back(0.6);
    this->value.push_back(0.7);
}

std::tuple<int, int> Package::isStraightFlush(std::vector<double> value) {
    std::vector<int> H;
    std::vector<int> B;
    std::vector<int> K;
    std::vector<int> M;
    std::vector<int> sameColor;
    std::tuple<int, int> result;
    for (int i = 0; i < value.size(); i++) {
        if (round(fmod(value[i] * 100, 10)) == 0) {
            H.push_back(round(value[i]*100));
        }
        else if (round(fmod(value[i] * 100, 10)) == 3) {
            round(value[i]);
            B.push_back(round(value[i]*100));
        }
        else if (round(fmod(value[i] * 100, 10)) == 6) {
            round(value[i]);
            K.push_back(round(value[i]*100));
        }
        else if (round(fmod(value[i] * 100, 10)) == 9) {
            round(value[i]);
            M.push_back(round(value[i]*100));
        }
    }

    if (H.size() >= 5){
        sameColor = H;
    }
    else if (B.size() >= 5){
        sameColor = B;
    }
    else if (K.size() >= 5){
        sameColor = K;
    }
    else if (M.size() >= 5){
        sameColor = M;
    }

    sort(sameColor.begin(), sameColor.end());

    int count = 0;
    if (sameColor.size() >= 5){
        for (int i = 0; i < sameColor.size() - 1; i++){
            if (count == 4){
                result = std::make_tuple(9, sameColor[i+1]);
                return result;
            }
            if (sameColor[i] == sameColor[i+1] - 10){
                std::cout << sameColor[i] << " " << sameColor[i+1] << std::endl;
                std::cout << "T" << std::endl;
                count++;
            }
            else {
                std::cout << sameColor[i] << " " << sameColor[i+1] << std::endl;
                std::cout << "F" << std::endl;
                count = 0;
            }
        }
    }

    return std::make_tuple(-1, -1);
}

std::tuple<int, int> Package::isFourKind(std::vector<double> value) {
    std::vector<int> sameValue;
    std::tuple<int, int> result;
    for (int i = 0; i < value.size(); i++) {
        sameValue.push_back(floor(value[i]*10)*10);
    }

    sort(sameValue.begin(), sameValue.end());

    int count = 0;
    for (int i = 0; i < sameValue.size() - 1; i++){
        if (count == 3){
            result = std::make_tuple(8, sameValue[i-1]);
            return result;
        }
        if (sameValue[i] == sameValue[i+1]){
            count++;
        }
        else {
            count = 0;
        }
    }

    return std::make_tuple(-1, -1);
}

std::tuple<int, int> Package::isFullHouse(std::vector<double> value) {
    std::map<int, int> freq;
    for (auto v : value) {
        int val = static_cast<int>(v * 100);
        if (freq.find(val) == freq.end()) {
            freq[val] = 1;
        } else {
            freq[val]++;
        }
    }
    int triple = -1;
    int pair = -1;
    for (auto [val, count] : freq) {
        if (count == 3 && val > triple) {
            triple = val;
        } else if (count >= 2 && val > pair) {
            pair = val;
        }
    }
    if (triple >= 0 && pair >= 0) {
        return std::make_tuple(9, (triple > pair) ? triple : pair);
    } else {
        return std::make_tuple(-1, -1);
    }
}



int main() {
    std::vector<double> v;
    Package p;
    v.push_back(0.59);
    v.push_back(1.09);
    v.push_back(0.49);
    v.push_back(0.40);
    v.push_back(0.26);
    v.push_back(0.29);
    v.push_back(0.23);
    std::tuple<int, int> result = p.isStraightFlush(v);
    std::tuple<int, int> result2 = p.isFourKind(v);
    std::tuple<int, int> result3 = p.isFullHouse(v);
    std::cout << std::get<0>(result) << " " << std::get<1>(result) << std::endl;
    std::cout << std::get<0>(result2) << " " << std::get<1>(result2) << std::endl;
    std::cout << std::get<0>(result3) << " " << std::get<1>(result3) << std::endl;
}