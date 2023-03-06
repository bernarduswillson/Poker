#include "Card.hpp"
#include <cmath>

Card::Card() {
    value = 0;
}

Card::Card(int number, std::string color) {
    double vals = number * 0.1;
    this->number = number;
    this->color = color;

    if (color == "green") {
        this->value = vals;
    }
    else if (color == "blue") {
        this->value = vals + 0.03;
    }
    else if (color == "yellow") {
        this->value = vals + 0.06;
    }
    else if (color == "red") {
        this->value = vals + 0.09;
    }
    else {
        std::cout << "kartu anda salah goblok" << std::endl;
        this->value = 0;
    }
}

double Card::getValue() {
    return this->value;
}

void Card::displaycard() {
    double x=this->value;
    if (floor(x*10)==1){
        if(round(fmod(x*100,10))==3){
            std::cout << "\033[34m" << "1" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==6){
            std::cout << "\033[33m" << "1" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==9){
            std::cout << "\033[31m" << "1" << "\033[0m" << std::endl;
        }
        else if (round(fmod(x*100,10))==0){
            std::cout << "\033[32m" << "1" << "\033[0m" << std::endl;
        }
    }
    else if (floor(x*10)==2){
        if(round(fmod(x*100,10))==3){
            std::cout << "\033[34m" << "2" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==6){
            std::cout << "\033[33m" << "2" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==9){
            std::cout << "\033[31m" << "2" << "\033[0m" << std::endl;
        }
        else if (round(fmod(x*100,10))==0){
            std::cout << "\033[32m" << "2" << "\033[0m" << std::endl;
        }
    }
    else if (floor(x*10)==3){
        if(round(fmod(x*100,10))==3){
            std::cout << "\033[34m" << "3" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==6){
            std::cout << "\033[33m" << "3" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==9){
            std::cout << "\033[31m" << "3" << "\033[0m" << std::endl;
        }
        else if (round(fmod(x*100,10))==0){
            std::cout << "\033[32m" << "3" << "\033[0m" << std::endl;
        }
    }
    else if (floor(x*10)==4){
        if(round(fmod(x*100,10))==3){
            std::cout << "\033[34m" << "4" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==6){
            std::cout << "\033[33m" << "4" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==9){
            std::cout << "\033[31m" << "4" << "\033[0m" << std::endl;
        }
        else if (round(fmod(x*100,10))==0){
            std::cout << "\033[32m" << "4" << "\033[0m" << std::endl;
        }
    }
    else if (floor(x*10)==5){
        if(round(fmod(x*100,10))==3){
            std::cout << "\033[34m" << "5" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==6){
            std::cout << "\033[33m" << "5" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==9){
            std::cout << "\033[31m" << "5" << "\033[0m" << std::endl;
        }
        else if (round(fmod(x*100,10))==0){
            std::cout << "\033[32m" << "5" << "\033[0m" << std::endl;
            }
    }
    else if (floor(x*10)==6){
        if(round(fmod(x*100,10))==3){
            std::cout << "\033[34m" << "6" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==6){
            std::cout << "\033[33m" << "6" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==9){
            std::cout << "\033[31m" << "6" << "\033[0m" << std::endl;
        }
        else if (round(fmod(x*100,10))==0){
            std::cout << "\033[32m" << "6" << "\033[0m" << std::endl;
            }

    }
    else if (floor(x*10)==7){
        if(round(fmod(x*100,10))==3){
            std::cout << "\033[34m" << "7" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==6){
            std::cout << "\033[33m" << "7" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==9){
            std::cout << "\033[31m" << "7" << "\033[0m" << std::endl;
        }
        else if (round(fmod(x*100,10))==0){
            std::cout << "\033[32m" << "7" << "\033[0m" << std::endl;
            }
    }
    else if (floor(x*10)==8){
        if(round(fmod(x*100,10))==3){
            std::cout << "\033[34m" << "8" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==6){
            std::cout << "\033[33m" << "8" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==9){
            std::cout << "\033[31m" << "8" << "\033[0m" << std::endl;
        }
        else if (round(fmod(x*100,10))==0){
            std::cout << "\033[32m" << "8" << "\033[0m" << std::endl;
            }
    }
    else if (floor(x*10)==9){
        if(round(fmod(x*100,10))==3){
            std::cout << "\033[34m" << "9" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==6){
            std::cout << "\033[33m" << "9" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==9){
            std::cout << "\033[31m" << "9" << "\033[0m" << std::endl;
        }
        else if (round(fmod(x*100,10))==0){
            std::cout << "\033[32m" << "9" << "\033[0m" << std::endl;
            }
    }
    else if (floor(x*10)==10){
        if(round(fmod(x*100,10))==3){
            std::cout << "\033[34m" << "10" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==6){
            std::cout << "\033[33m" << "10" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==9){
            std::cout << "\033[31m" << "10" << "\033[0m" << std::endl;
        }
        else if (round(fmod(x*100,10))==0){
            std::cout << "\033[32m" << "10" << "\033[0m" << std::endl;
            }
    }
    else if (floor(x*10)==11){
        if(round(fmod(x*100,10))==3){
            std::cout << "\033[34m" << "11" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==6){
            std::cout << "\033[33m" << "11" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==9){
            std::cout << "\033[31m" << "11" << "\033[0m" << std::endl;
        }
        else if (round(fmod(x*100,10))==0){
            std::cout << "\033[32m" << "11" << "\033[0m" << std::endl;
            }
    }
    else if (floor(x*10)==12){
        if(round(fmod(x*100,10))==3){
            std::cout << "\033[34m" << "12" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==6){
            std::cout << "\033[33m" << "12" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==9){
            std::cout << "\033[31m" << "12" << "\033[0m" << std::endl;
        }
        else if (round(fmod(x*100,10))==0){
            std::cout << "\033[32m" << "12" << "\033[0m" << std::endl;
            }
    }
    else if (floor(x*10)==13){
        if(round(fmod(x*100,10))==3){
            std::cout << "\033[34m" << "13" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==6){
            std::cout << "\033[33m" << "13" << "\033[0m" << std::endl;
        }
        else if(round(fmod(x*100,10))==9){
            std::cout << "\033[31m" << "13" << "\033[0m" << std::endl;
        }
        else if (round(fmod(x*100,10))==0){
            std::cout << "\033[32m" << "13" << "\033[0m" << std::endl;
            }
    }
}
// int main(int argc, char const *argv[])
// {
//     double x;
//     std::string y;
//     std::cin >> x >> y;
//     Card card(x, y);
//     std::cout << card.getValue() << std::endl;
//     return 0;
// }