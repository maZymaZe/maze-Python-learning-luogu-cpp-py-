class ParkingSystem {
public:

    ParkingSystem(int big, int medium, int small) {
        c[1]=big,c[2]=medium,c[3]=small;
    }
    
    bool addCar(int carType) {
        if(c[carType]){
            c[carType]--;
            return true;
        }
        return false;
    }
private:
    int c[4];
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */