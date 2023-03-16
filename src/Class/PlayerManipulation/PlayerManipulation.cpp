#include "PlayerManipulation.hpp"

PlayerManipulation::PlayerManipulation(int id) : Ability(id) {}

PlayerManipulation::~PlayerManipulation() {}

long long int PlayerManipulation::use(long long int prize)
{
    return prize;
}

void PlayerManipulation::use(PlayerList &players, Deck<Card> &playingDeck, int &turn)
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
                std::cout << "\nChoose a target: ";
                std::cin >> target;

                if (target != "1" && target != "2" && target != "3" && target != "4" && target != "5" && target != "6" && target != "7")
                {
                    throw TargetException();
                }

                isValid = true;
                int targetIdx = std::stoi(target);
                players.getElmt(targetIdx).setIsDisable();
            }
            catch (TargetException err)
            {
                errMsg = err.what();
            }
        }
    }

    // Reroll
    else if (this->id == 4)
    {
        std::vector<Card> temp;
        for (int i = 0; i < 2; i++)
        {
            temp.push_back(playingDeck.roll());
        }
        players.getElmt(0).setHands(temp);
    }

    else if (this->id == 5)
    {
        std::vector<Player> remains;
        for (int i = 0; i < 7 - turn; i++)
        {
            remains.push_back(players.getElmt(i + 1));
        }
        std::reverse(remains.begin(), remains.end());

        std::vector<Player> complete;
        for (int i = 0; i < turn - 1; i++)
        {
            complete.push_back(players.getElmt(8 - turn + i));
        }
        std::reverse(complete.begin(), complete.end());

        int i = 1;
        for (auto p : remains)
        {
            players.setElmt(i, p);
            i++;
        }
        for (auto p : complete)
        {
            players.setElmt(i, p);
        }

        // for (int i = 1; i < 7 - turn; i++)
        // {
        //     players.setElmt(i, remains[i - 1]);
        // }
        // for (int i = 0; i < turn - 1; i++)
        // {
        //     players.setElmt(8 - turn + i, complete[i]);
        // }
    }
}