# Project 1 OOP TOT
First Project for Object Oriented Programming Course at Institut Teknologi Bandung. We are assigned to make a card game with c++. 


  
- [Project 1 OOP TOT](#project-1-oop-tot)
  - [Authors](#authors)
  - [Requirements](#requirements)
  - [Dependencies](#dependencies)
  - [usage](#usage)
  - [Compile](#compile)
  - [Structure](#structure)

## Authors

<!-- make a table for author with nim dan nama -->
| NIM | Nama |
| :---: | :----: |
| 13521005 | Kelvin Rayhan A. |
| 13521019 | Ditra Rizqa A. |
| 13521020 | Varraz Hazzandra A. |
| 13521021 | Bernardus Willson |
| 13521022 | Raditya Naufal A. |
| 13521023 | Kenny Benaya N. |


## Requirements
- C++ 17.0


## Dependencies
- iostream
- vector
- algorithm
- bits/stdc++.h
- chrono
- string
- random
- cmath
- fstream
- utility
- map
- pair
- iterator
- ctime

## usage
- Clone the repository
- Run the command in [compile](#compile) section
- Enjoy the game
## Compile
- Run the command below
```
g++ -std=c++17 ./src/main.cpp ./src/Class/GameState/GameState.cpp ./src/Class/Ability/Ability.cpp ./src/Class/Multiplier/Multiplier.cpp ./src/Class/PlayerManipulation/PlayerManipulation.cpp ./src/Class/PlayerList/PlayerList.cpp ./src/Class/Player/Player.cpp ./src/Class/Deck/Deck.cpp ./src/Class/Card/Card.cpp ./src/Class/Table/Table.cpp ./src/Class/InventoryHolder/InventoryHolder.cpp ./src/Class/Calculable/Calculable.cpp ./src/Class/Package/Package.cpp ./src/Class/Combination/Flush/Flush.cpp ./src/Class/Combination/FourOfAKind/FourOfAKind.cpp ./src/Class/Combination/StraightFlush/StraightFlush.cpp ./src/Class/Combination/FullHouse/FullHouse.cpp ./src/Class/Combination/Straight/Straight.cpp ./src/Class/Combination/ThreeOfAKind/ThreeOfAKind.cpp ./src/Class/Combination/TwoPair/TwoPair.cpp ./src/Class/Combination/Pair/Pair.cpp ./src/Class/Combination/HighCard/HighCard.cpp ./src/Class/Exception/Exception.cpp ./src/Class/GArray/GArray.cpp -o ./bin/candyCard.out
```


## Structure
```
.
|____bin
| |____candyCard.out
|____config
| |____deck.txt
|____README.md
|____.gitignore
|____doc
| |____dummy.pdf
|____.vscode
| |____settings.json
| |____c_cpp_properties.json
| |____launch.json
| |____tasks.json
|____src
| |____.DS_Store
| |____Class
| | |____Multiplier
| | | |____Multiplier.hpp
| | | |____Multiplier.cpp
| | |____PlayerList
| | | |____PlayerList.hpp
| | | |____PlayerList.cpp
| | |____.DS_Store
| | |____Card
| | | |____Card.hpp
| | | |____Card.cpp
| | |____PlayerManipulation
| | | |____PlayerManipulation.cpp
| | | |____PlayerManipulation.hpp
| | |____Combination
| | | |____FourOfAKind
| | | | |____FourOfAKind.cpp
| | | | |____FourOfAKind.hpp
| | | |____Flush
| | | | |____Flush.cpp
| | | | |____Flush.hpp
| | | |____Straight
| | | | |____Straight.cpp
| | | | |____Straight.hpp
| | | |____HighCard
| | | | |____HighCard.cpp
| | | | |____HighCard.hpp
| | | |____ThreeOfAKind
| | | | |____ThreeOfAKind.hpp
| | | | |____ThreeOfAKind.cpp
| | | |____StraightFlush
| | | | |____StraightFlush.cpp
| | | | |____StraightFlush.hpp
| | | |____TwoPair
| | | | |____TwoPair.cpp
| | | | |____TwoPair.hpp
| | | |____FullHouse
| | | | |____FullHouse.cpp
| | | | |____FullHouse.hpp
| | | |____Pair
| | | | |____Pair.hpp
| | | | |____Pair.cpp
| | |____InventoryHolder
| | | |____InventoryHolder.hpp
| | | |____InventoryHolder.cpp
| | |____GArray
| | | |____GArray.cpp
| | | |____GArray.hpp
| | |____Calculable
| | | |____Calculable.cpp
| | | |____Calculable.hpp
| | |____Table
| | | |____Table.cpp
| | | |____Table.hpp
| | |____Ability
| | | |____Ability.cpp
| | | |____Ability.hpp
| | |____GameState
| | | |____GameState.hpp
| | | |____GameState.cpp
| | |____Exception
| | | |____Exception.cpp
| | | |____Exception.hpp
| | |____Deck
| | | |____Deck.cpp
| | | |____Deck.hpp
| | |____Package
| | | |____Package.hpp
| | | |____Package.cpp
| | |____Player
| | | |____Player.cpp
| | | |____Player.dSYM
| | | | |____Contents
| | | | | |____Resources
| | | | | | |____DWARF
| | | |____Player.hpp
| |____main.cpp
```




