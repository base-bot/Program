#include "WindLoad.h"
#include <math.h>

WindLoad::WindLoad() {
	wind_zone = 0;
	height_above_sea_level = 0.0;
	terrain_category = "null";
}

WindLoad::WindLoad(int zone, double sea_level, string category) {
	wind_zone = zone;
	height_above_sea_level = sea_level;
	terrain_category = category;
}

WindLoad::WindLoad(const WindLoad& WL) {
	wind_zone = WL.wind_zone;
	height_above_sea_level = WL.height_above_sea_level;
	terrain_category = WL.terrain_category;
}

WindLoad& WindLoad::operator = (const WindLoad& WL) {
	if (this != &WL) {
		wind_zone = WL.wind_zone;
		height_above_sea_level = WL.height_above_sea_level;
		terrain_category = WL.terrain_category;
	}
	return *this;
}

double WindLoad::calculate_turbulence_intensity(double z, string category) {
	double z_min;
	double Iv;
	switch (category) {
	case "null":
		cout << "you have entered a false terrain category for Germany, please try again using I, II, III or IV,\nThank you" << endl;

	case "I":
		z_min = 2;
		if (z < z_min) {
			Iv = 0.17;
			return Iv;
		}
		else {
			Iv = 0.14 * pow(z / 10, -0.12);
			return Iv;
		}
		break;
	case "II":
		z_min = 4;
		if (z < z_min) {
			Iv = 0.22;
			return Iv;
		}
		else {
			Iv = 0.19 * pow(z / 10, -0.16);
			return Iv;
		}
		break;
	case "III":
		z_min = 8;
		if (z < z_min) {
			Iv = 0.29;
			return Iv;
		}
		else {
			Iv = 0.28 * pow(z / 10, -0.22);
			return Iv;
		}
		break;
	case "IV":
		z_min = 16;
		if (z < z_min) {
			Iv = 0.37;
			return Iv;
		}
		else {
			Iv = 0.43 * pow(z / 10, -0.3);
			return Iv;
		}
		break;
	}
}

double WindLoad::calculate_mean_wind_velocity_NA1(double z, double v_basic_0, string category) {
	double mean_velocity_1, z_min;
	double probability_factor = 1; //This should be then adapted based on the return period: 5,10, 15, 25, 50 years...

	double return_period;
	cout << "please enter the return period used to obtain the basic wind velocity (usually 50 years) = "; cin >> return_period;
	if (return_period < 2) {
		probability_factor = pow((1-0.2*log(-log(1-0.5)))/(1-0.2*log(-log(0.98))),0.5);
	}
	else{
		probability_factor =  pow((1-0.2*log(-log(1-(1/return_period))))/(1-0.2*log(-log(0.98))),0.5);
	}
	double v_b = v_basic_0 * probability_factor;
	
	switch (category) {
	case "null":
		cout << "you have entered a false terrain category for Germany, please try again using I, II, III or IV,\nThank you" << endl;

	case "I":
		z_min = 2;
		if (z < z_min) {
			mean_velocity_1 = 0.97*v_b;
			return mean_velocity_1;
		}
		else {
			mean_velocity_1 = 1.18 * v_b * pow(z / 10, 0.12);
			return mean_velocity_1;
		}
		break;
	case "II":
		z_min = 4;
		if (z < z_min) {
			mean_velocity_1 = 0.86 * v_b;
			return mean_velocity_1;
		}
		else {
			mean_velocity_1 = v_b * pow(z / 10, 0.16);
			return mean_velocity_1;
		}
		break;
	case "III":
		z_min = 8;
		if (z < z_min) {
			mean_velocity_1 = 0.74 * v_b;
			return mean_velocity_1;
		}
		else {
			mean_velocity_1 = 0.77 * v_b * pow(z / 10, 0.22);
			return mean_velocity_1;
		}
		break;
	case "IV":
		z_min = 16;
		if (z < z_min) {
			mean_velocity_1 = 0.64 * v_b;
			return mean_velocity_1;
		}
		else {
			mean_velocity_1 = 0.56 * v_b * pow(z / 10, 0.3);
			return mean_velocity_1;
		}
		break;
	}
}

double WindLoad::calculate_mean_wind_velocity_NA2(double z, double v_basic_0, string category) {
	double vm1 = calculate_mean_wind_velocity_NA1(z, v_basic_0, category);
	double topography_factor = 1;   //This should be then updated with a function based on Annex A.3
	
	double mean_velocity_2 = vm1 * topography_factor;
	
	return mean_velocity_2;
}

double WindLoad::calculate_q_p(double mean_velocity, double Iv){

}