class ParkingSystem {
    vector<int> parking = vector<int>(6);
public:
    ParkingSystem(int big, int medium, int small) {
        parking[0] = big;
        parking[1] = medium;
        parking[2] = small;
    }
    bool addCar(int carType) {
        if (parking[carType-1]==parking[carType+2]) return false;
        else parking[carType+2]++;
        return true;
    }
};
