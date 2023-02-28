#include <iostream>
#include <vector>

class Package {
    private:
        std::string packageName;
        int packageValue;
        std::vector<int> packageBuffer;
    public:
        Package();
        void updatePackage(int gameState, int hand);
};