#include <iostream>

using namespace std;

class SnowLoad {
protected:
    float snow_zone;
    double roof_angle;
    double height_above_sea_level;

public:
    SnowLoad();
    SnowLoad(float zone, double angle, double sea_level);
    SnowLoad(const SnowLoad&);
    SnowLoad& operator = (const SnowLoad&);

    double calculate_form_factor(double angle);
    double calculate_sk(float zone, double sea_level);

    double calculate_s(float zone, double angle, double sea_level);
};