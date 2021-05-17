// ConsoleProject1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
#include <ios>
#include "FlatRoofWindLoad.cpp"
#include "SnowLoad.cpp"

using namespace std;

int main()
{
	//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
	//-----------------------------------------------------------------------------PAGE 1&2 (Excel Sheet)----------------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

	
	// double PLZ, building_length, building_width, building_height, slope_roof, roof_edge_distance, roof_area;
	// string project_name, project_site, project_country, person_in_charge;


	// double z, alpha, module_length, module_width, frame_thickness, module_mass, module_angle, friction_factor;
	// int plz;
	// string project_name, project_country, person_in_charge;
	// roof_area = building_length * building_width;
	// cout << "Your Roof Surface Area in meters squared is = " << roof_area << endl;
	ProjectData PD;
	string project_name = PD.set_project_name();
    int plz = PD.set_PLZ();
    string project_country = PD.set_project_country();
    string person_in_charge = PD.set_person_in_charge();

    double z = PD.set_roof_height_above_ground_level();
    double alpha = PD.set_roof_angle();
    
    double module_length = PD.set_module_length();
    double module_width = PD.set_module_width();
    double module_thickness = PD.set_frame_thickness();
    double module_mass = PD.set_module_mass();
    double module_angle = PD.set_module_angle();
    // double friction_factor = PD.set_friction_factor_value();
	
	PD.review_ProjectData(z, alpha, module_length, module_width, module_thickness, module_mass, module_angle, project_name, project_country, person_in_charge, plz);
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------PAGE 3 (Excel Sheet)----------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------

	//Characteristic of PV System
	/*double surface_dead_weight, ridge_gap;
	bool side_deflector;*/

	// double mounting_system_surface_weight = 1.9; //This needs to be updated depending on the new system and if a new middle rail is added....basically taking into consideration all possible varieties
	// // surface_dead_weight = (module_weight / (module_length * module_width)) + mounting_system_surface_weight;
	
	WindLoad WL;
	int w_zone = WL.set_zone();
	double hasl = WL.set_height_above_sea_level();
	string tc = WL.set_terrain_category(); 
	
	double qp1 = WL.calculate_qp1(z, tc, w_zone);
	double qp2 = WL.calculate_qp2(z, tc, w_zone);
	

	
	SnowLoad SL;

	float s_zone = SL.set_snow_load_zone(); 
	double s = SL.calculate_s(s_zone, module_angle, hasl);

	FlatRoofWindLoad FR;

	double gap = FR.set_roof_edge_distance();
	double ppt = FR.set_parapet_height();
	double fric = FR.set_friction_factor_value();
	// double building_length = FR.set_building_length();
	// double building_width = FR.set_building_width();

	FR.update_qp(alpha, gap, ppt, fric);

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
