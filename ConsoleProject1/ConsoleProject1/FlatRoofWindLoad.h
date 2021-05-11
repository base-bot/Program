#include "WindLoad.h"


class FlatRoofWindLoad : public WindLoad{
    protected:
    double roof_angle, ridge_gap, parapet_height, friction_factor;

    public:
    FlatRoofWindLoad();													//default constructor
	FlatRoofWindLoad(double alpha, double gap, double ppt_height, double friction);		//constructor
	FlatRoofWindLoad(const FlatRoofWindLoad& FR);									//copy constructor
	FlatRoofWindLoad& operator = (const FlatRoofWindLoad& FR);						//copy assignment
							
								//A DESTRUCTOR needs to be added!!

    double *pitch_angle_correction(double alpha, double friction);
    double ridge_gap_correction(double gap);
    double *parapet_correction(double ppt_height, double z);

    void update_qp(double alpha, double gap, double ppt_height, double friction);
};