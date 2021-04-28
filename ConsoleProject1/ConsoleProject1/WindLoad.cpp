#include "WindLoad.h"
#include <math.h>

WindLoad::WindLoad() {
	wind_zone = 0;
	height_structure = 0;
	height_above_sea_level = 0.0;
	terrain_category = "null";
}

WindLoad::WindLoad(int zone, double sea_level, double z, string category) {
	wind_zone = zone;
	height_structure = z;
	height_above_sea_level = sea_level;
	terrain_category = category;
}

WindLoad::WindLoad(const WindLoad& WL) {
	wind_zone = WL.wind_zone;
	height_above_sea_level = WL.height_above_sea_level;
	height_structure = WL.height_structure;
	terrain_category = WL.terrain_category;
}

WindLoad& WindLoad::operator = (const WindLoad& WL) {
	if (this != &WL) {
		wind_zone = WL.wind_zone;
		height_above_sea_level = WL.height_above_sea_level;
		height_structure = WL.height_structure;
		terrain_category = WL.terrain_category;
	}
	return *this;
}

double WindLoad::calculate_turbulence_intensity(double z, string category) {
	height_structure = z;
	terrain_category = category;
	
	double z_min;
	double Iv;

	while (category != "I" && category != "II" && category != "III" && category != "IV") {
		if (category == "null"){
			cout << "you have entered a false terrain category for Germany, please try again using I, II, III or IV,\nThank you" << endl;
			cout << "Terrain Category = "; cin >> category;
		}
		else {
			cout << "you have entered a False Terrain Category, please retry using I, II, III, IV" << endl;
			cout << "Terrain Category = "; cin >> category;
		}
	}
		
	if (category == "I"){
		z_min = 2;
		if (z < z_min) {
			Iv = 0.17;
			return Iv;
		}
		else {
			Iv = 0.14 * pow(z / 10, -0.12);
			return Iv;
		}
	}
		
	else if(category == "II"){
		z_min = 4;
		if (z < z_min) {
			Iv = 0.22;
			return Iv;
		}
		else {
			Iv = 0.19 * pow(z / 10, -0.16);
			return Iv;
		}
	}
		
	else if (category == "III"){
		z_min = 8;
		if (z < z_min) {
			Iv = 0.29;
			return Iv;
		}
		else {
			Iv = 0.28 * pow(z / 10, -0.22);
			return Iv;
		}
	}
	else if (category == "IV"){
		z_min = 16;
		if (z < z_min) {
			Iv = 0.37;
			return Iv;
		}
		else {
			Iv = 0.43 * pow(z / 10, -0.3);
			return Iv;
		}
	}
	
}

double WindLoad::calculate_qp1(double z, string category) {
	double mean_velocity_1, z_min;
	double v_b;
	double q_p;

	
	/*double v_b = v_basic_0 * probability_factor;*/
	
	while (category != "I" && category != "II" && category != "III" && category != "IV") {
		if (category == "null"){
			cout << "you have entered a false terrain category for Germany, please try again using I, II, III or IV,\nThank you" << endl;
			cout << "Terrain Category = "; cin >> category;
		}
		else {
			cout << "you have entered a False Terrain Category, please retry using I, II, III, IV" << endl;
			cout << "Terrain Category = "; cin >> category;
		}
	}
	int zone = get_zone();
	double sea_level = get_sea_level();
	
	v_b = calculate_vb(zone, sea_level, z);

	if (category == "I"){
		z_min = 2;

		if (z < z_min) {
			mean_velocity_1 = 0.97*v_b;
			cout << "The mean velocity turned out to be v_m = " << mean_velocity_1 << endl;
			q_p = 1.9 * 0.5 * 1.245 * pow(v_b,2) / 1000;
			return q_p;
		}
		else {
			mean_velocity_1 = 1.18 * v_b * pow(z / 10, 0.12);
			cout << "The mean velocity turned out to be v_m = " << mean_velocity_1 << endl;
			q_p = 2.6 * 0.5 * 1.245 * pow(v_b,2) / 1000 * pow(z/10,0.19);
			return q_p;
		}
	}
	else if (category == "II"){
		z_min = 4;
		
		if (z < z_min) {
			mean_velocity_1 = 0.86 * v_b;
			cout << "The mean velocity turned out to be v_m = " << mean_velocity_1 << endl;
			q_p = 1.7 * 0.5 * 1.245 * pow(v_b,2) / 1000;
			return q_p;
		}
		else {
			mean_velocity_1 = v_b  * pow(z / 10, 0.16);
			cout << "The mean velocity turned out to be v_m = " << mean_velocity_1 << endl;
			q_p = 2.1 * 0.5 * 1.245 * pow(v_b,2) / 1000 * pow(z/10,0.24);
			return q_p;
		}
	}	
	else if (category == "III"){
		z_min = 8;

		if (z < z_min) {
			mean_velocity_1 = 0.74 * v_b ;
			cout << "The mean velocity turned out to be v_m = " << mean_velocity_1 << endl;
			q_p = 1.5 * 0.5 * 1.245 * pow(v_b,2) / 1000;
			return q_p;
		}
		else {
			mean_velocity_1 = 0.77 * v_b  * pow(z / 10, 0.22);
			cout << "The mean velocity turned out to be v_m = " << mean_velocity_1 << endl;
			q_p = 1.6 * 0.5 * 1.245 * pow(v_b,2) / 1000 * pow(z/10,0.31);
			return q_p;
		}
	}
	else if (category == "IV"){
		z_min = 16;

		if (z < z_min) {
			mean_velocity_1 = 0.64 * v_b ;
			cout << "The mean velocity turned out to be v_m = " << mean_velocity_1 << endl;
			q_p = 1.3 * 0.5 * 1.245 * pow(v_b,2) / 1000;
			return q_p;
		}
		else {
			mean_velocity_1 = 0.56 * v_b  * pow(z / 10, 0.3);
			cout << "The mean velocity turned out to be v_m = " << mean_velocity_1 << endl;
			q_p = 1.1 * 0.5 * 1.245 * pow(v_b,2) / 1000 * pow(z/10,0.4);
			return q_p;
		}
	}
}

double WindLoad::calculate_mean_wind_velocity_NA2(double z, string category){
	// double *qp1 = calculate_qp1(z, category)->mean_velocity_1;
	// double topography_factor = 0.9;   //This should be then updated with a function based on Annex A.3
	
	// cout << *qp1 << endl;
	 double mean_velocity_2 = 1.0;
	
	 return mean_velocity_2;
}

double calculate_vb(int zone, double sea_level, double z){
	double v_b_0;
	
	while (zone != 1 && zone != 2 && zone != 3 && zone != 4) {
		cout << "you have entered a False Wind Zone, please retry using 1, 2, 3 or 4" << endl;
		cout << "Wind Zone = "; cin >> zone;
	}

	switch (zone){
	case 1:
		v_b_0 = 22.5;
	case 2:
		v_b_0 = 25;
	case 3:
		v_b_0 = 27.5;
	case 4:
		v_b_0 = 30;
	}
	if (sea_level > 800) {
		v_b_0 = v_b_0 * sqrt(0.2 + (sea_level/1000));
	}
	double probability_factor = 1; 
	double return_period;

	cout << "please enter the return period used to obtain the basic wind velocity (usually 50 years) = "; cin >> return_period;
	if (return_period < 2.0) {
		probability_factor = pow((1-0.2*log(-log(1-0.5)))/(1-0.2*log(-log(0.98))),0.5);
	}
	else{
		probability_factor =  pow((1-0.2*log(-log(1-(1/return_period))))/(1-0.2*log(-log(0.98))),0.5);
	}
	cout << "Your probability factor turned out to be = " << probability_factor << endl;

	return v_b_0*probability_factor;
}