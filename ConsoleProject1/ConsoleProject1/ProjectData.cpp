#include "ProjectData.h"
#include <math.h>

ProjectData::ProjectData(){
    building_height = 0.0; 
    roof_angle = 0.0;
    module_length = 0.0;
    module_width = 0.0;
    frame_thickness = 0.0;
    module_mass = 0.0;
    module_angle = 0.0;
    project_name = "";
    project_country = "";
    person_in_charge = "";
    PLZ = 0;
}

ProjectData::ProjectData(double bldg_height, double alpha, double pv_length, double pv_width, double pv_thickness, double pv_mass, double pv_angle, string pjct_name, string pjct_country, string person, int plz){
    building_height = bldg_height; 
    roof_angle = alpha;
    module_length = pv_length;
    module_width = pv_width;
    frame_thickness = pv_width;
    module_mass = pv_mass;
    module_angle = pv_angle;
    project_name = pjct_name;
    project_country = pjct_country;
    person_in_charge = person;
    PLZ = plz;
}
ProjectData::ProjectData(const ProjectData& PD){
    building_height = PD.building_height;
    roof_angle = PD.roof_angle;
    module_length = PD.module_length;
    module_width = PD.module_width;
    frame_thickness = PD.frame_thickness;
    module_mass = PD.module_mass;
    module_angle = PD.module_angle;
    project_name = PD.project_name;
    project_country = PD.project_country;
    person_in_charge = PD.person_in_charge;
    PLZ = PD.PLZ;
}									//copy constructor
ProjectData& ProjectData::operator = (const ProjectData& PD){
    if (this != &PD){
        building_height = PD.building_height;
        roof_angle = PD.roof_angle;
        module_length = PD.module_length;
        module_width = PD.module_width;
        frame_thickness = PD.frame_thickness;
        module_mass = PD.module_mass;
        module_angle = PD.module_angle;
        project_name = PD.project_name;
        project_country = PD.project_country;
        person_in_charge = PD.person_in_charge;
        PLZ = PD.PLZ;
    }
    return *this;
}					//copy assignment


string ProjectData::set_project_name(){
    string name;
    cout << "Please Type in the Project details: " << endl;
    cout << "Enter please the Project's General Data:\n";
	cout << "Project Name:  "; cin >> name;

    return name;
}
int ProjectData::set_PLZ(){
	int plz;
    cout << "Postal Code: "; cin >> plz;

    return plz;
}
string ProjectData::set_project_country(){
    string country;
	cout << "Project Country: "; cin >> country;

    return country;
}
string ProjectData::set_person_in_charge(){
    string name;
	cout << "Person in Charge of this Project: "; cin >> name;

    return name;
}

double ProjectData::set_roof_height_above_ground_level(){
    double height;
	cout << "Height of the Building in meters = "; cin >> height;

    return height;
}
double ProjectData::set_roof_angle(){
    double alpha;
    int angle_trial = 0; 
    int total_trials = 10;
	while (angle_trial < total_trials) {
		cout << "Roof's Angle in degrees - in the range between -5 and 5 = "; cin >> alpha;
		if (alpha < -5 || alpha>5) {
			cout << "trial# " << angle_trial + 1 << "/" << total_trials << endl;
			cout << "You entered an out-of-range Angle, please check with the Client/Technician again for the right Angle" << endl;
		}
		else { break; }
		angle_trial++;
	}
	if (angle_trial == total_trials) {
		cout << "										STOP!" << endl;
		cout << "you have reached the maximum number of trials, please restart and try again" << endl;
		return 0;
	}
    return alpha;
}

double ProjectData::set_module_length(){
    double length;
    cout << "Enter please the Solar Modules' Data:\n";
	cout << "Module length in milli-meters = "; cin >> length;
	
    return length;
}
double ProjectData::set_module_width(){
    double width;
	cout << "Module width in milli-meters = "; cin >> width;
	
    return width;
}
double ProjectData::set_frame_thickness(){
    double thickness;
	cout << "Module's frame thickness in milli-meters = "; cin >> thickness;

    return thickness;
}
double ProjectData::set_module_mass(){
    double mass;
	cout << "Module mass in kilogramms = "; cin >> mass;

    return mass;
}
double ProjectData::set_module_angle(){
    double beta;
	cout << "Type in please additional information necessary for the system installation:" << endl;
	cout << "System Inclination in degrees = "; cin >> beta;

    return beta;
}

void ProjectData::review_ProjectData(double bldg_height,double bldg_angle,double pv_length,double pv_width,double pv_thickness,double pv_mass,double pv_angle,string pjct_name,string pjct_country,string person,int plz){
    building_height = bldg_height; 
    roof_angle = bldg_angle;
    module_length = pv_length;
    module_width = pv_width;
    frame_thickness = pv_thickness;
    module_mass = pv_mass;

    project_name = pjct_name;
    project_country = pjct_country;
    person_in_charge = person;
    PLZ = plz;

    cout << "\nProject Summary:\n\nProject Definition:" << endl;
    cout << "Project Name: " << pjct_name << endl;
    cout << "PLZ: " << plz << endl;
    cout << "Project Country: " << pjct_country << endl;
    cout << "Person in Charge: " << person << "\n" << endl;

    cout << "Building Information Summary:\n" << endl;
    cout << "Building Height = " << bldg_height << "m" << endl;
    cout << "Roof Angle = " << bldg_angle << "°\n" << endl;

    cout << "Solar Module Definition:\n" << endl;
    cout << "Module Length = " << pv_length << "mm" << endl;
    cout << "Module Width = " << pv_width << "mm" << endl;
    cout << "Module Thickness = " << pv_thickness << "mm" << endl;
    cout << "Module Mass = " << pv_mass << "kg" << endl;
    cout << "Module Angle = " << pv_angle << "°" << endl;

}
