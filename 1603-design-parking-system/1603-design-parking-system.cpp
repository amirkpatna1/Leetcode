class ParkingSystem {
public:
    int p=0,q=0,r=0;
    ParkingSystem(int big, int medium, int small) {
        p=big;
        q=medium;
        r=small;
    }
    
    bool addCar(int c) {
        if(c==1){
            return --p>=0;
        }
        if(c==2)return --q>=0;
        return --r>=0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */