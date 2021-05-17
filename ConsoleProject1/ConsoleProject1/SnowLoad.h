#ifndef SNOWLOAD_H
#define SNOWLOAD_H
#include "ProjectData.cpp"

class SnowLoad : public ProjectData{
protected:
    float snow_zone;
    double height_above_sea_level;

public:
    SnowLoad();
    SnowLoad(float zone, double sea_level);
    SnowLoad(const SnowLoad&);
    SnowLoad& operator = (const SnowLoad&);

    double calculate_form_factor(double angle);
    double calculate_sk(float zone, double sea_level);

    double calculate_s(float zone, double angle, double sea_level);
    float set_snow_load_zone();
};
#endif