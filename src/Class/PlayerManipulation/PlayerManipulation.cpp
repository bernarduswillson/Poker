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

                if (target != "1" && target != "2" && target != "3" && target != "4" && target != "5" && target != "6")
                {
                    throw TargetException();
                }

                isValid = true;
                int targetIdx = std::stoi(target);
                if (!players.getElmt(targetIdx).getIsDisable())
                {
                    players.getElmt(targetIdx).setIsDisable();
                }
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
    }

    else if (this->id == 6)
    {
        std::string target, errMsg;
        bool isValid = false;

        while (!isValid)
        {
            system("clear");
            std::cout << "\n#-----=========== SWITCH ===========-----#\n"
                      << std::endl;
            std::cout << "Available target :" << std::endl;
            for (int i = 1; i < 7; i++)
            {
                std::cout << i << ". " << players.getElmt(i).getName() << std::endl;
            }
            try
            {
                std::cerr << errMsg;
                std::cout << "Pilih target : ";
                std::cin >> target;
                if (target != "1" && target != "2" && target != "3" && target != "4" && target != "5" && target != "6")
                {
                    throw TargetException();
                }
                isValid = true;
                int targetIdx = std::stoi(target);
                std::vector<Card> cards1 = players.getElmt(0).getHands();
                std::vector<Card> cards2 = players.getElmt(targetIdx).getHands();
                players.getElmt(0).setHands(cards2);
                players.getElmt(targetIdx).setHands(cards1);
            }
            catch (TargetException err)
            {
                errMsg = err.what();
            }
        }
    }

    else if (this->id == 7)
    {
        std::string target1, target2, errMsg;
        bool isValid = false;

        while (!isValid)
        {
            system("clear");
            std::cout << "\n#-----=========== SWAP ===========-----#\n"
                      << std::endl;
            std::cout << "Available target :" << std::endl;
            for (int i = 1; i < 7; i++)
            {
                std::cout << i << ". " << players.getElmt(i).getName() << std::endl;
            }
            try
            {
                std::cerr << errMsg;
                std::cout << "Pilih target 1 : ";
                std::cin >> target1;
                std::cout << std::endl;
                if (target1 != "1" && target1 != "2" && target1 != "3" && target1 != "4" && target1 != "5" && target1 != "6")
                {
                    throw TargetException();
                }
                std::cout << "Pilih target 2 : ";
                std::cin >> target2;
                if (target2 != "1" && target2 != "2" && target2 != "3" && target2 != "4" && target2 != "5" && target2 != "6")
                {
                    throw TargetException();
                }
                if (target2 == target1)
                {
                    throw TargetException();
                }

                isValid = true;
                int targetIdx1 = std::stoi(target1);
                int targetIdx2 = std::stoi(target2);
                std::vector<Card> cards1 = players.getElmt(targetIdx1).getHands();
                std::vector<Card> cards2 = players.getElmt(targetIdx2).getHands();
                std::swap_ranges(cards1.begin(), cards1.begin() + 1, cards2.begin());
                players.getElmt(targetIdx1).setHands(cards1);
                players.getElmt(targetIdx2).setHands(cards2);
            }
            catch (TargetException err)
            {
                errMsg = err.what();
            }
        }
    }
}