#include <iostream>
#include <vector>

using namespace std;

class ParkingSystem {
public:
    vector<int> total;

    ParkingSystem(int big, int medium, int small) {
        total = {big, medium, small};
    }
    
    bool addCar(int carType) {
        carType -= 1;
        if (total[carType] >= 1) {
            total[carType]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */