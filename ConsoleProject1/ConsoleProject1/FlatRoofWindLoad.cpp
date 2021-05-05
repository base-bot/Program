#include "FlatRoofWindLoad.h"
#include <math.h>
#define PI 3.14159265

FlatRoofWindLoad::FlatRoofWindLoad(){
    roof_angle=0;
    ridge_gap=0;
    parapet_height=0;
    friction_factor=0;
    side_deflectors=false;
}

FlatRoofWindLoad::FlatRoofWindLoad(double alpha, double gap, double ppt_height, double friction, bool deflectors){
    roof_angle= alpha;
    ridge_gap= gap;
    parapet_height= ppt_height;
    friction_factor= friction;
    side_deflectors= deflectors;
}		

FlatRoofWindLoad::FlatRoofWindLoad(const FlatRoofWindLoad& FR){
    roof_angle= FR.roof_angle;
    ridge_gap= FR.ridge_gap;
    parapet_height= FR.parapet_height;
    friction_factor= FR.friction_factor;
    side_deflectors= FR.side_deflectors;
}									//copy constructor
FlatRoofWindLoad& FlatRoofWindLoad::operator = (const FlatRoofWindLoad& FR){
    if (this != &FR){
        roof_angle= FR.roof_angle;
        ridge_gap= FR.ridge_gap;
        parapet_height= FR.parapet_height;
        friction_factor= FR.friction_factor;
        side_deflectors= FR.side_deflectors;
    }
    return *this;
}					//copy assignment
							
								//A DESTRUCTOR needs to be added!!

double FlatRoofWindLoad::pitch_angle_correction(double alpha, double friction){
    roof_angle = alpha;
    friction_factor = friction;
    double uplift;
    double sliding;
    std::vector<double> correction_coeff(uplift, sliding);

    while (abs(alpha) > 5.0) {
		cout << "you have entered a false angle for a flat roof study, please try again using a value between -5.0 and 5.0,\nThank you" << endl;
        cout << "Roof Angle (in degrees) = "; cin >> alpha;
	}
    string downhill;
    cout << "is the downhill of this project's roof negligeable?    "; cin >> downhill;

    while (downhill!= "Yes" && downhill!= "yes" && downhill!= "YES" && downhill!= "Y" && downhill!= "y" && downhill!= "No" && downhill!= "no" && downhill!= "NO" && downhill!= "N" && downhill!= "n"){
        cout << "please retry your answer by yes or no: ";
        cin >> downhill;
    }

    if (downhill== "Yes" || downhill== "yes" || downhill== "YES" || downhill== "Y" || downhill== "y"){
        uplift = 1.0;
        sliding = 1.0;
    }
    else {
        uplift = 1.0/cos(alpha/(180*PI));    
        sliding = friction/(friction * cos(alpha/(180*PI)) - sin(alpha/(180*PI)));
    }
    return correction_coeff(uplift, sliding);
}
double FlatRoofWindLoad::ridge_gap_correction(double gap){

}
double FlatRoofWindLoad::parapet_correction(bool deflectors, double ppt_height){

}