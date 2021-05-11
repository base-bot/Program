#include "FlatRoofWindLoad.h"
#include <math.h>
#include <vector>
#define PI 3.14159265

FlatRoofWindLoad::FlatRoofWindLoad(){
    roof_angle=0;
    ridge_gap=0;
    parapet_height=0;
    friction_factor=0;
}

FlatRoofWindLoad::FlatRoofWindLoad(double alpha, double gap, double ppt_height, double friction){
    roof_angle= alpha;
    ridge_gap= gap;
    parapet_height= ppt_height;
    friction_factor= friction;
}		

FlatRoofWindLoad::FlatRoofWindLoad(const FlatRoofWindLoad& FR){
    roof_angle= FR.roof_angle;
    ridge_gap= FR.ridge_gap;
    parapet_height= FR.parapet_height;
    friction_factor= FR.friction_factor;
}									//copy constructor
FlatRoofWindLoad& FlatRoofWindLoad::operator = (const FlatRoofWindLoad& FR){
    if (this != &FR){
        roof_angle= FR.roof_angle;
        ridge_gap= FR.ridge_gap;
        parapet_height= FR.parapet_height;
        friction_factor= FR.friction_factor;
    }
    return *this;
}					//copy assignment
							
								//A DESTRUCTOR needs to be added!!

double *FlatRoofWindLoad::pitch_angle_correction(double alpha, double friction){
    roof_angle = alpha;
    friction_factor = friction;
    double uplift;
    double sliding;
    double* angle_correction_coeff = new double[2];

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
    angle_correction_coeff[0] = uplift;
    angle_correction_coeff[1] = sliding;
    return angle_correction_coeff;
}
double FlatRoofWindLoad::ridge_gap_correction(double gap){
    ridge_gap = gap;

    double ridge_gap_1 = 50.0;
    double coeff_1 = 1.2;
    double ridge_gap_2 = 94.3;
    double coeff_2 = 1.0;
    double ridge_gap_3 = 300.0;
    double coeff_3 = 1.0;

    double correction_coefficient_1 = coeff_2 + (coeff_1/coeff_2-1)*((gap-ridge_gap_2)/(ridge_gap_1-ridge_gap_2));
    double correction_coefficient_2 = coeff_2 + (coeff_3/coeff_2-1)*((gap-ridge_gap_2)/(ridge_gap_3-ridge_gap_2));

    double gap_correction;
    if (gap<ridge_gap_2){
        gap_correction = correction_coefficient_1;
    }
    else if (gap == ridge_gap_2){
        gap_correction = coeff_2;
    }
    else{
        gap_correction = correction_coefficient_2;
    }
    return gap_correction;
}

double *FlatRoofWindLoad::parapet_correction(double ppt_height, double z){
    parapet_height = ppt_height;
    height_structure = z;

    double* parapet_correction_coeff = new double [2];

    int number_modules_per_array_1 = 1;
    double coeff_wo_parapet_1 = 1.0;
    double coeff_parapet_1;
    
    coeff_parapet_1 = 1.15;
    coeff_wo_parapet_1 = 1.0;
    
    int number_modules_per_array_2 = 16;
    double coeff_parapet_2 = 1.0;

    int number_of_arrays;
    cout << "please enter the number of modules per array=  "; cin >> number_of_arrays;

    if (number_of_arrays > number_modules_per_array_2){
        number_of_arrays = number_modules_per_array_2;
    }

    double correction_coeff_1;
    double correction_coeff_2;

    if ((ppt_height/z)<=0.1){
        correction_coeff_1 = coeff_wo_parapet_1 + ((coeff_parapet_1/coeff_wo_parapet_1)-1)*((ppt_height/z)/0.1);
        correction_coeff_2 = coeff_parapet_2 + ((coeff_parapet_2/coeff_parapet_2)-1)*((ppt_height/z)/0.1);
    }
    else{
        correction_coeff_1 = coeff_wo_parapet_1 + ((coeff_parapet_1/coeff_wo_parapet_1)-1)*((ppt_height/z)/0.1);
        correction_coeff_2 = coeff_parapet_2 + ((coeff_parapet_2/coeff_parapet_2)-1)*((ppt_height/z)/0.1);
    }

    int double_modules_per_row_uplift;
    int number_of_rows_uplift;
    cout << "please enter the number of double modules per row which share loads for UPLIFT(1 to 8):   "; cin >> double_modules_per_row_uplift;
    cout << "now enter the number of rows which share loads (1 to 8) for UPLIFT:    "; cin >> number_of_rows_uplift;

    int double_modules_per_row_sliding;
    int number_of_rows_sliding;
    cout << "please enter the number of double modules per row which share loads for SLIDING(1 to 8):   "; cin >> double_modules_per_row_sliding;
    cout << "now enter the number of rows which share loads (1 to 8) for SLIDING:    "; cin >> number_of_rows_sliding;

    int small_arrays = 4;
    int large_arrays = 8;
    string array;
    cout << "do you have \"small\" arrays or \"large\" arrays?  "; cin >> array;
    if (array == "small"){
        if (double_modules_per_row_uplift > small_arrays){
            double_modules_per_row_uplift = small_arrays;}
        if (double_modules_per_row_sliding > small_arrays){
            double_modules_per_row_sliding = small_arrays;
        }
        if (number_of_rows_uplift > small_arrays){
            number_of_rows_uplift = small_arrays;}
        if (number_of_rows_sliding > small_arrays){
            number_of_rows_sliding = small_arrays;
        }
    } 
    if (array == "large"){
        if (double_modules_per_row_uplift > large_arrays){
            double_modules_per_row_uplift = large_arrays;}
        if (double_modules_per_row_sliding > large_arrays){
            double_modules_per_row_sliding = large_arrays;
        }
        if (number_of_rows_uplift > large_arrays){
            number_of_rows_uplift = large_arrays;}
        if (number_of_rows_sliding > large_arrays){
            number_of_rows_sliding = large_arrays;
        }
    }
    double table_uplift;
    double table_sliding;
    table_uplift = double_modules_per_row_uplift*number_of_rows_uplift;
    table_sliding = double_modules_per_row_sliding*number_of_rows_sliding;
    
    double parapet_coeff_uplift;
    if (table_uplift>=number_modules_per_array_2){
        parapet_coeff_uplift = 1.0;
    }
    else{
        parapet_coeff_uplift = correction_coeff_1-((correction_coeff_1/correction_coeff_2)-1)*(table_uplift-number_modules_per_array_1)/(number_modules_per_array_2-number_modules_per_array_1);
    }

    double parapet_coeff_sliding;
    if (table_sliding>=number_modules_per_array_2){
        parapet_coeff_sliding = 1.0;
    }
    else{
        parapet_coeff_sliding = correction_coeff_1-((correction_coeff_1/correction_coeff_2)-1)*(table_sliding-number_modules_per_array_1)/(number_modules_per_array_2-number_modules_per_array_1);
    }

    parapet_correction_coeff[0] = parapet_coeff_uplift;
    parapet_correction_coeff[1] = parapet_coeff_sliding;

    return parapet_correction_coeff;
}

void FlatRoofWindLoad::update_qp(double alpha, double gap, double ppt_height, double friction) {
    roof_angle = alpha;
    ridge_gap = gap;
    parapet_height = ppt_height;
    friction_factor = friction;

    string side_deflectors;
    double deflectors_coeff;
    cout << "does your system contain side deflectors? (Yes or No?):\t";cin >> side_deflectors;

    while (side_deflectors != "Yes" && side_deflectors != "yes" && side_deflectors != "YES" && side_deflectors != "Y" && side_deflectors != "y" && side_deflectors != "No" && side_deflectors != "no" && side_deflectors != "NO" && side_deflectors != "N" && side_deflectors != "n"){
        cout << "please retry your answer by yes or no: ";
        cin >> side_deflectors;
    }

    if (side_deflectors== "Yes" || side_deflectors== "yes" || side_deflectors== "YES" || side_deflectors== "Y" || side_deflectors== "y"){
        deflectors_coeff = 1.2;
    }
    else {
        deflectors_coeff = 1.0;
    } 

    int zone = set_zone();
    double sea_level = set_height_above_sea_level();
    double z = set_height_structure();
    string category = set_terrain_category();

    WindLoad WL(zone, sea_level, z, category);
    double qp1 = WL.calculate_qp1(z, category);
    double qp2 = WL.calculate_qp2(z, category);

    double qp;
    if (qp1>=qp2){
        qp = qp1;        
    }
    else{
        qp=qp2;
    }

    double * angle_coeff;
    angle_coeff = pitch_angle_correction(alpha, friction);
    cout << "\n\n" << *angle_coeff << "\n\n"<< endl;
    double * parapet_coeff; 
    parapet_coeff = parapet_correction(ppt_height, z);
    
    double gap_coeff = ridge_gap_correction(gap);

    cout << "\n\n" << *parapet_coeff << "\n\n"<< endl;
    cout << "\n\n" << gap_coeff << "\n\n"<< endl;
    cout << "\n\n" << deflectors_coeff << "\n\n"<< endl;
    cout << "\n\n" << qp << "\n\n"<< endl;

    
    double w_uplift = qp * angle_coeff[0] * parapet_coeff[0] * gap_coeff * deflectors_coeff;
    double w_sliding = qp * angle_coeff[1] * parapet_coeff[1] * gap_coeff * deflectors_coeff;

    cout << "your corrected uplift wind load is now equal to\nw_uplift = " << w_uplift << endl;
    cout << "your corrected sliding wind load is now equal to\nw_sliding = " << w_sliding << endl;

}