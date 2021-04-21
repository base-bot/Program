#include "WindLoad.h"

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

double WindLoad::calculate_mean_wind_velocity_NA1(double v_basic_0, double z, double z_min) {
	double mean_velocity_1;

}