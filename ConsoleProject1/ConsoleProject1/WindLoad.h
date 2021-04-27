#include <iostream>

using namespace std;

class WindLoad {
private:
	int wind_zone;
	double height_above_sea_level, height_structure;
	string terrain_category;

public:
	WindLoad();													//default constructor
	WindLoad(int zone, double sea_level, double z, string category);		//constructor
	WindLoad(const WindLoad&);									//copy constructor
	WindLoad& operator = (const WindLoad&);						//copy assignment
							
								//A DESTRUCTOR needs to be added!!

	double calculate_turbulence_intensity(double z, string category);
	double calculate_mean_wind_velocity_NA1(double z, string category);
	double calculate_mean_wind_velocity_NA2(double z, string category);
	double calculate_q_p(double mean_velocity, double Iv);

};