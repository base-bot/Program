#ifndef FLATROOFWINDLOAD_H
#include "WindLoad.cpp"


class FlatRoofWindLoad : public WindLoad{
    protected:
    double building_length, building_width, roof_angle, ridge_gap, parapet_height, friction_factor;

    public:
    FlatRoofWindLoad();													//default constructor
	FlatRoofWindLoad(double bldg_length, double bldg_width,double alpha, double gap, double ppt_height, double friction);		//constructor
	FlatRoofWindLoad(const FlatRoofWindLoad& FR);									//copy constructor
	FlatRoofWindLoad& operator = (const FlatRoofWindLoad& FR);						//copy assignment
							
								//A DESTRUCTOR needs to be added!!

    double *pitch_angle_correction(double alpha, double friction);
    double ridge_gap_correction(double gap);
    double *parapet_correction(double ppt_height, double z);

    double *update_qp(double alpha, double gap, double ppt_height, double friction);

    double determine_ballast(double* wind_load, double *angle_coeff);

    double set_friction_factor_value();
    double set_building_length();
    double set_building_width();
    double set_parapet_height();
    double set_roof_edge_distance();
    double get_module_area(double pv_length, double pv_width);
};
#endif