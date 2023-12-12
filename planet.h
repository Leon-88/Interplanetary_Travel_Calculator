#pragma once // used to ensure that the header file is only included once during compilation

#include <string>

// global constants that have been declared to the preprocessor typically use less memory than regular variables
#define PI 3.14159

// surface gravity info taken from:             https://nssdc.gsfc.nasa.gov/planetary/factsheet/planet_table_ratio.html
// distance from sun averages are taken from:   https://www.jpl.nasa.gov/edu/pdfs/scaless_reference.pdf
// moon distance from sun taken from:           https://www.universetoday.com/20566/how-far-is-the-moon-from-the-sun/
// pluto distance from sun taken from           https://science.nasa.gov/dwarf-planets/pluto/facts/#hds-sidebar-nav-2

#define MERCURY_SURFACE_GRAVITY 0.378
#define MERCURY_DISTANCE_FROM_SUN 57900000 // 57,900,000 km

#define VENUS_SURFACE_GRAVITY 0.907
#define VENUS_DISTANCE_FROM_SUN 108200000 // 108,200,000 km

#define EARTH_SURFACE_GRAVITY 1
#define EARTH_DISTANCE_FROM_SUN 149600000 // 149,600,000 km

#define MOON_SURFACE_GRAVITY 0.166
#define MOON_DISTANCE_FROM_SUN 150000000 // 150,000,000 km

#define MARS_SURFACE_GRAVITY 0.377
#define MARS_DISTANCE_FROM_SUN 227900000 // 227,900,000 km

#define JUPITER_SURFACE_GRAVITY 2.36
#define JUPITER_DISTANCE_FROM_SUN 778600000 // 778,600,000 km

#define SATURN_SURFACE_GRAVITY 0.916
#define SATURN_DISTANCE_FROM_SUN 1433500000 // 1,433,500,000 km

#define URANUS_SURFACE_GRAVITY 0.889
#define URANUS_DISTANCE_FROM_SUN 2872500000 // 2,872,500,000 km

#define NEPTUNE_SURFACE_GRAVITY 1.12
#define NEPTUNE_DISTANCE_FROM_SUN 4495100000 // 4,495,100,000 km

#define PLUTO_SURFACE_GRAVITY 0.071
#define PLUTO_DISTANCE_FROM_SUN 5834316957 // 5,834,316,957 km

class Planet
{

private:
    std::string name;
    float surfaceGravity;
    double distanceFromSun;
    // double distanceFromEarth = ;

public:
    Planet();
    Planet(std::string nameInput, float surfaceGravityInput, double distanceFromSunInput);

    std::string getName() const;
    void setName(std::string newName);

    double getSurfaceGravity() const;
    void setSurfaceGravity(double surfaceGravityInput);

    double getDistanceFromSun() const;
    void setDistanceFromSun(double distanceFromSunInput);

    double calculateDistanceFromEarth() const;

    double calculateWeightOnPlanet(uint16_t weightOnEarth) const;
};
