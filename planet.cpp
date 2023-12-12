#include <string>

#include "planet.h"

using namespace std;

Planet::Planet()
{
    name = "";
    surfaceGravity = 0;
    distanceFromSun = 0;
}
Planet::Planet(std::string nameInput, float surfaceGravityInput, double distanceFromSunInput)
{
    name = nameInput;
    surfaceGravity = surfaceGravityInput;
    distanceFromSun = distanceFromSunInput;
}

string Planet::getName() const { return name; }
void Planet::setName(std::string newName) { name = newName; }

double Planet::getSurfaceGravity() const { return surfaceGravity; }
void Planet::setSurfaceGravity(double surfaceGravityInput) { surfaceGravity = surfaceGravityInput; }

double Planet::getDistanceFromSun() const { return distanceFromSun; }
void Planet::setDistanceFromSun(double distanceFromSunInput) { distanceFromSun = distanceFromSunInput; }

double Planet::calculateDistanceFromEarth() const
{
    return abs(distanceFromSun - EARTH_DISTANCE_FROM_SUN);
}

double Planet::calculateWeightOnPlanet(uint16_t weightOnEarth) const
{
    return weightOnEarth * surfaceGravity;
}
