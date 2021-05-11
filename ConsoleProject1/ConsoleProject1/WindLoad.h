#include <iostream>

using namespace std;

class WindLoad {
protected:
	int wind_zone;
	double height_above_sea_level, height_structure;
	string terrain_category;

public:
	WindLoad();													//default constructor
	WindLoad(int zone, double sea_level, double z, string category);		//constructor
	WindLoad(const WindLoad&);									//copy constructor
	WindLoad& operator = (const WindLoad&);						//copy assignment
							
								//A DESTRUCTOR needs to be added!!

	double calculate_qp2(double z, string category);
	double calculate_qp1(double z, string category);
	
	double calculate_vb(int zone, double sea_level, double z);
	
	int get_zone(){return wind_zone;}
	double get_sea_level(){return height_above_sea_level;}

	int set_zone();
	double set_height_above_sea_level();
	double set_height_structure();
	string set_terrain_category();

};