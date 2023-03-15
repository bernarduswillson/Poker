#include "PlayerManipulation.hpp"

PlayerManipulation::PlayerManipulation(int id) : Ability(id)
{
    this->id = id;
    if (id == 3)
    {
        this->name = "Abilityless";
    }
}

PlayerManipulation::~PlayerManipulation() {}

long long int PlayerManipulation::use(long long int prize)
{
    return prize;
}

void PlayerManipulation::use(PlayerList &players, Deck<Card> &playingDeck)
{
    // Abilityless
    if (this->id == 3)
    {
        std::string target;
        std::string errMsg;
        bool isValid = false;

        while (!isValid)
        {
            system("clear");
            std::cout << "\n#-----=========== ABILITYLESS ===========-----#\n"
                      << std::endl;
            std::cout << "Available target: " << std::endl;
            for (int i = 1; i < 7; i++)
            {
                std::cout << i << ". " << players.getElmt(i).getName() << std::endl;
            }

            try
            {
                std::cerr << errMsg;
                std::cout << players.getLength() << std::endl;
                std::cout << "\nChoose a target: ";
                std::cin >> target;

                if (target != "1" && target != "2" && target != "3" && target != "4" && target != "5" && target != "6" && target != "7")
                {
                    throw "Target is not available\n";
                }

                isValid = true;
                int targetIdx = std::stoi(target);
                players.getElmt(targetIdx).setIsDisable();
            }
            catch (const char *err)
            {
                errMsg = err;
            }
        }
    }
}