#ifndef PROJECTDATA_H
#define PROJECTDATA_H
#include <iostream>

using namespace std;

class ProjectData{
    protected:
    double building_height, roof_angle, module_length, module_width, frame_thickness, module_mass, module_angle;
    string project_name, project_country, person_in_charge;
    int PLZ;

    public:
    ProjectData();
    ProjectData(double bldg_height, double alpha, double pv_length, double pv_width, double pv_thickness, double pv_mass, double pv_angle, string pjct_name, string pjct_country, string person, int plz);
    ProjectData(const ProjectData&);									//copy constructor
	ProjectData& operator = (const ProjectData&);						//copy assignment
							
								//A DESTRUCTOR needs to be added!!

    string set_project_name();
    int set_PLZ();
    string set_project_country();
    string set_person_in_charge();

    double set_roof_height_above_ground_level();
    double set_roof_angle();
    
    double set_module_length();
    double set_module_width();
    double set_frame_thickness();
    double set_module_mass();
    double set_module_angle();

    void review_ProjectData(double bldg_height,double bldg_angle,double pv_length,double pv_width,double pv_thickness,double pv_mass,double pv_angle,string pjct_name,string pjct_country,string person,int plz);
};
#endif