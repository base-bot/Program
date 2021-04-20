#include <iostream>

struct coordinate{
    float longitude;
    float latitude;
    float altitude;
};

struct system{
    struct coordinate coord;
    struct coordinate lastCoord;
};

int main(){
    struct system system;
    struct coordinate coord1;
    coord1.longitude = 25;
    coord1.latitude = 30.23;
    coord1.altitude = 5.0;
    
    coord1.longitude = 23;
    system.coord = coord1;


    std::cout << "Longitude is " << system.coord.longitude << "\t Latitude is " << system.coord.latitude << "\t Altitude is " << system.coord.altitude << std::endl;

    return 0;
}