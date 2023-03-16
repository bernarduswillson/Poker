# DIRECTORY
SOURCE = src/Class
OUT = bin


run: all
	./$(OUT)/main

all: 
	g++												\
	src/main.cpp									\
	$(SOURCE)/GameState/*.cpp						\
	$(SOURCE)/PlayerList/*.cpp						\
	$(SOURCE)/Player/*.cpp							\
	$(SOURCE)/Deck/*.cpp							\
	$(SOURCE)/Card/*.cpp							\
	$(SOURCE)/Table/*.cpp							\
	$(SOURCE)/InventoryHolder/*.cpp					\
	$(SOURCE)/Calculable/*.cpp						\
	$(SOURCE)/Package/*.cpp							\
	$(SOURCE)/Combination/HighCard/*.cpp			\
	$(SOURCE)/Combination/Pair/*.cpp				\
	$(SOURCE)/Combination/TwoPair/*.cpp				\
	$(SOURCE)/Combination/ThreeOfAKind/*.cpp		\
	$(SOURCE)/Combination/Straight/*.cpp			\
	$(SOURCE)/Combination/Flush/*.cpp				\
	$(SOURCE)/Combination/FullHouse/*.cpp			\
	$(SOURCE)/Combination/FourOfAKind/*.cpp			\
	$(SOURCE)/Combination/StraightFlush/*.cpp		\
	$(SOURCE)/Ability/*.cpp							\
	$(SOURCE)/PlayerManipulation/*.cpp				\
	$(SOURCE)/Multiplier/*.cpp						\
	$(SOURCE)/GArray/*.cpp							\
	$(SOURCE)/Exception/*.cpp						\
	-o $(OUT)/main
