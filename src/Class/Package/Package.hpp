#include "../Calculable/Calculable.hpp"
#include "../Card/Card.hpp"
#include <vector>

class Package : virtual public Calculable
{
    private:
        std::vector<Card> cardBuffer;
        const double highestHigh = 1.39;
        const double highestPair = 2.78;
        const double highestTwoPair = 4.17;
        const double highestThreeOfAKind = 5.65;
        const double highestStraight = 7.64;
        const double highestFlush = 8.43;
        const double highestFullHouse = 0;
        const double highestFourOfAKind = 0;
        int vallll;

    public:
        //constructor
        Package();
        //destructor
        ~Package();
        virtual double getValue() = 0;
        std::vector<Card> getCardBuffer();
        void addCard(Card);
        virtual void setValue(double value);
        
};