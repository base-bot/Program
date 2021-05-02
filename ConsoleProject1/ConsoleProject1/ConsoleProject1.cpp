// ConsoleProject1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
#include <ios>
#include "WindLoad.h"
#include "SnowLoad.h"

//using namespace std;

int main()
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------PAGE 1&2 (Excel Sheet)----------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

	// cout << "Welcome to the Flat Roof System Project Definition!" << endl;
	// cout << "Please Type in the Project details: " << endl;

	// double PLZ, building_length, building_width, building_height, slope_roof, roof_edge_distance, roof_area;
	// string project_name, project_site, project_country, person_in_charge;

	// cout << "Enter please the Project's General Data:\n";
	// cout << "Project Name:  "; cin >> project_name;
	// cout << "Postal Code: "; cin >> PLZ;
	// cout << "Project Site: "; cin >> project_site;
	// cout << "Project Country: "; cin >> project_country;
	// cout << "Person in Charge of this Project: "; cin >> person_in_charge;

	// cout << person_in_charge << ", Enter please the Project's Building Data:\n";
	// cout << "Length of the Building in meters = "; cin >> building_length;
	// cout << "Width of the Building in meters = "; cin >> building_width;

	// roof_area = building_length * building_width;
	// cout << "Your Roof Surface Area in meters squared is = " << roof_area << endl;

	// cout << "Height of the Building in meters = "; cin >> building_height;
	
	// int angle_trial = 0; int total_trials = 10;
	// while (angle_trial < total_trials) {
	// 	cout << "Roof's Angle in degrees - in the range between -5 and 5 = "; cin >> slope_roof;
	// 	if (slope_roof < -5 || slope_roof>5) {
	// 		cout << "trial# " << angle_trial + 1 << "/" << total_trials << endl;
	// 		cout << "You entered an out-of-range Angle, please check with the Client/Technician again for the right Angle" << endl;
	// 	}
	// 	else { break; }
	// 	angle_trial++;
	// }
	// if (angle_trial == total_trials) {
	// 	cout << "										STOP!" << endl;
	// 	cout << "you have reached the maximum number of trials, please restart and try again" << endl;
	// 	return 0;
	// }
	// cout << "The Distance from the Edge of the Building to the Starting Panels' Corner in meters = "; cin >> roof_edge_distance;

	// string parapets;
	// double parapets_height;
	// int parapet_trial = 0;
	
	// while (parapet_trial < total_trials){
	// 	cout << "Are there parapets? "; cin >> parapets;
	// 	if (parapets == "Y" || parapets == "y" || parapets == "Yes" || parapets == "YES" || parapets == "yes") {
	// 		cout << "please specify Parapets' height in meters = "; cin >> parapets_height;
	// 		break;
	// 	}
	// 	else if (parapets == "N" || parapets == "n" || parapets == "No" || parapets == "NO" || parapets == "no") {
	// 		parapets_height = 0;
	// 		break;
	// 	}
	// 	else {
	// 		cout << "trial# " << parapet_trial+1 << "/" << total_trials << endl;
	// 		cout << "please try again and answer by \"yes\" or \"no\"" << endl;
	// 	}
	// 	parapet_trial++;
	// }
	// if (parapet_trial == total_trials) {
	// 	cout << "										STOP!" << endl;
	// 	cout << "you have reached the maximum number of trials, please restart and try again" << endl;
	// 	return 0;
	// }
	// double module_length, module_width, frame_thickness, module_weight;

	// cout << person_in_charge << ", Enter please the Solar Modules' Data:\n";
	// cout << "Module length in milli-meters = "; cin >> module_length;
	// cout << "Module width in milli-meters = "; cin >> module_width;
	// cout << "Module's frame thickness in milli-meters = "; cin >> frame_thickness;
	// cout << "Module weight in kilogramms = "; cin >> module_weight;

	// double module_angle, friction_coefficient;
	// cout << "\n\n Type in please additional information necessary for the system installation:" << endl;
	// cout << "System Inclination in degrees = "; cin >> module_angle;
	// cout << "Friction Coefficient for the surfacebetween the system and Roof = "; cin >> friction_coefficient; //This should be then updated into a value that is either given out or standard value between different materials...based on type of roof's surface

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------PAGE 3 (Excel Sheet)----------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

	//Characteristic of PV System
	/*double surface_dead_weight, ridge_gap;
	bool side_deflector;*/

	double mounting_system_surface_weight = 1.9; //This needs to be updated depending on the new system and if a new middle rail is added....basically taking into consideration all possible varieties
	// surface_dead_weight = (module_weight / (module_length * module_width)) + mounting_system_surface_weight;
	
	int w_zone;
	double hasl; double z; string tc;
	double alpha; 
	
	cout << "please enter the information below to determine the Wind Load: \nthe zone between 1,2,3 and 4: ";
	cin >> w_zone;
	cout << "the height above sea level (in m): "; cin>>hasl;
	cout << "the height of the building/structure (in m)"; cin >> z;
	cout << "the terrain category between I, II, III and IV"; cin >> tc;
	cout << "the roof angle in degrees (°): "; cin>>alpha;

	WindLoad WL(w_zone, hasl, z, alpha, tc);
	
	double qp1 = WL.calculate_qp1(z, tc);

	double qp2 = WL.calculate_qp2(z, tc);
	
	float s_zone; 

	cout << "please enter the information below to determine the Snow Load: \nthe snow zone between 1, 1.5, 2, 2.5 and 3: "; cin>> s_zone;
	
	SnowLoad SL(s_zone, alpha, hasl);

	double s = SL.calculate_s(s_zone, alpha, hasl);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
