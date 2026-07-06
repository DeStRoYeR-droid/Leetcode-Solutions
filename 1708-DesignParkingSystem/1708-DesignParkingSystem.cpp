// Last updated: 06/07/2026, 19:02:02
class ParkingSystem {
private:
    array<int, 3> caps;
public:
    ParkingSystem(int big, int medium, int small) {
        caps = {big,  medium, small};
    }
    
    bool addCar(int carType) {
        if (caps[carType - 1] > 0){
            caps[carType - 1]--;
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