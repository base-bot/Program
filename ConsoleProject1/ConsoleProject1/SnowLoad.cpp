#include "SnowLoad.h"
#include <math.h>

SnowLoad::SnowLoad() {
	snow_zone = 0.0;
	height_above_sea_level = 0.0;
	roof_angle = 0.0;
}

SnowLoad::SnowLoad(float zone, double angle, double sea_level) {
	snow_zone = zone;
	height_above_sea_level = sea_level;
	roof_angle = angle;
}

SnowLoad::SnowLoad(const SnowLoad& SL) {
	snow_zone = SL.snow_zone;
	height_above_sea_level = SL.height_above_sea_level;
	roof_angle = SL.roof_angle;
}

SnowLoad& SnowLoad::operator = (const SnowLoad& SL) {
	if (this != &SL) {
		snow_zone = SL.snow_zone;
		height_above_sea_level = SL.height_above_sea_level;
		roof_angle = SL.roof_angle;
	}
	return *this;
}

double SnowLoad::calculate_form_factor(double angle){
    double mu;
    roof_angle = angle;
    bool outside = false;

    outside = 0.0 > abs(angle) && abs(angle) > 90.0;
    while (outside) {
		cout << "you have entered a False Roof Angle, please retry in the range of 0.0° and 90.0°" << endl;
		cout << "Roof Angle = "; cin >> angle;
	}

    if (abs(angle)<30.0){
    mu = 0.8;
    }
    else if (30.0<=abs(angle)<60.0){
    mu = 0.8*((60-abs(angle))/30);
    }
    else if (abs(angle)>= 60.0){
    mu = 0.0;
    }
    return mu;
}
double SnowLoad::calculate_sk(float zone, double sea_level){
    double sk;
    snow_zone = zone;
    height_above_sea_level = sea_level;

    while (zone != 1.0 && zone != 1.5 && zone != 2.0 && zone != 2.5 && zone != 3.0) {
		cout << "you have entered a False Snow Zone, please retry using 1, 1.5, 2, 2.5 or 3" << endl;
		cout << "Snow Zone = "; cin >> zone;
	}

    if (zone == 1.0 || zone == 1){
        if (sea_level<=400.0){
            sk=0.65;
        }
        else{
            sk = 0.19 + 0.91 * pow((sea_level + 140)/760, 2);
        }
    }
    else if (zone == 1.5){
        if (sea_level<=400.0){
            sk=0.65*1.25;
        }
        else{
            sk = 1.25 * (0.19 + 0.91 * pow((sea_level + 140)/760, 2));
        }
    }
    else if (zone == 2.0 || zone == 2){
        if (sea_level<=285.0){
            sk=0.85;
        }
        else{
            sk = 0.25 + 1.91 * pow((sea_level + 140)/760, 2);
        }
    }
    else if (zone == 2.5){
        if (sea_level<=285.0){
            sk=0.85*1.25;
        }
        else{
            sk = 1.25 * (0.19 + 0.91 * pow((sea_level + 140)/760, 2));
        }
    }
    else if (zone == 3.0 || zone == 3){
        if (sea_level<=255.0){
            sk=1.1;
        }
        else{
            sk = 0.31 + 2.91 * pow((sea_level + 140)/760, 2);
        }
    }
    return sk;
}

double SnowLoad::calculate_s(float zone, double angle, double sea_level){
    snow_zone = zone;
    roof_angle = angle;
    height_above_sea_level = sea_level;

    double s;
    double temperature_coeff = 1.0;
    double surrounding_coeff = 1.0;
    double expectancy_coeff;

    string a;
    cout << "Is the project location in the \"Norddeutsches Tiefland\"?";
    cin >> a;

    while (a!= "Yes" && a!= "yes" && a!= "YES" && a!= "Y" && a!= "y" && a!= "No" && a!= "no" && a!= "NO" && a!= "N" && a!= "n"){
        cout << "please retry your answer by yes or no: ";
        cin >> a;
    }

    if (a== "Yes" || a== "yes" || a== "YES" || a== "Y" || a== "y"){
        expectancy_coeff = 2.3;
    }
    else {
        expectancy_coeff = 1.0;
    }

    double mu = calculate_form_factor(angle);
    double sk = calculate_sk(zone, sea_level);
    
    s = temperature_coeff * surrounding_coeff * expectancy_coeff * mu * sk;
    cout << "The Snow Load turned out to be = " << s << "kN/m2" << endl;
    return s;
}