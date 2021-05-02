#include "WindLoad.h"

class FlatRoofWindLoad : public WindLoad{
    private:
    double roof_angle, ridge_gap, parapet_height, friction_factor;
    bool side_deflectors;

    public:
    FlatRoofWindLoad();													//default constructor
	FlatRoofWindLoad(double alpha, double gap, double ppt_height, double friction, bool deflectors);		//constructor
	FlatRoofWindLoad(const FlatRoofWindLoad&);									//copy constructor
	FlatRoofWindLoad& operator = (const FlatRoofWindLoad&);						//copy assignment
							
								//A DESTRUCTOR needs to be added!!

    double pitch_angle_correction(double alpha, double friction);
    double ridge_gap_correction(double gap);
    double parapet_correction(bool deflectors, double ppt_height);
};