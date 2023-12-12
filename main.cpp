#include <iostream> // for cout and cin
#include <iomanip>
#include <cmath>   // for abs() function
#include <cstdint> // for precise control of the memory allocation of integers
#include <string>
#include <thread> // std::this_thread::sleep_for
#include <chrono> // std::chrono::seconds

#include "planet.h"

using namespace std;

int main()
{
    // Humans weigh less than 2^16-1 lbs (65,535 lbs) so a 16 bit integer is enough memory allocation
    uint16_t weightOnEarthLB;

    // According to https://www.guinnessworldrecords.com/world-records/66135-fastest-spacecraft-speed ,
    // the fastest spaceship flew at a speed of 586,800 km/h. Therefore, an unsigned 32-bit integer is appropiate
    // because it can hold a maximum value of 4,294,967,295, which is more than we enough digits
    uint32_t speedKMH;

    // these values will exceed 6 significant decimal digits of precision,
    // so a double is needed. (which can handle 15)
    double
        travelTimeToPlanetHours,
        travelTimeToPlanetDays,
        travelTimeToPlanetYears;

    uint16_t menuChoice;

    Planet planet = Planet();

    // While loop acts as a guard clause to make sure the user types in a valid input.
    // If the user types in a valid input, than the string variable planetName will be given a value,
    // making the length not equal to zero anymore, breaking the loop.
    while (planet.getName().length() == 0)
    {
        cout << "------------------------------" << endl;
        cout << "| INTERPLANETARY TRAVEL MENU |" << endl;
        cout << "------------------------------" << endl;
        cout << "1) Mercury" << endl;
        cout << "2) Venus" << endl;
        cout << "3) Earth" << endl;
        cout << "4) Moon" << endl;
        cout << "5) Mars" << endl;
        cout << "6) Jupiter" << endl;
        cout << "7) Saturn" << endl;
        cout << "8) Uranus" << endl;
        cout << "9) Neptune" << endl;
        cout << "10) Pluto" << endl;
        cout << "0) Quit" << endl;
        cout << endl;

        cout << "Select a planet to travel to or type 0 to end the program: ";
        cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            planet = Planet("Mercury", MERCURY_SURFACE_GRAVITY, MERCURY_DISTANCE_FROM_SUN);
            break;
        case 2:
            planet = Planet("Venus", VENUS_SURFACE_GRAVITY, VENUS_DISTANCE_FROM_SUN);
            break;
        case 3:
            planet = Planet("Earth", EARTH_SURFACE_GRAVITY, EARTH_DISTANCE_FROM_SUN);
            break;
        case 4:
            planet = Planet("Moon", MOON_SURFACE_GRAVITY, MOON_DISTANCE_FROM_SUN);
            break;
        case 5:
            planet = Planet("Mars", MARS_SURFACE_GRAVITY, MARS_DISTANCE_FROM_SUN);
            break;
        case 6:
            planet = Planet("Jupiter", JUPITER_SURFACE_GRAVITY, JUPITER_DISTANCE_FROM_SUN);
            break;
        case 7:
            planet = Planet("Saturn", SATURN_SURFACE_GRAVITY, SATURN_DISTANCE_FROM_SUN);
            break;
        case 8:
            planet = Planet("Uranus", URANUS_SURFACE_GRAVITY, URANUS_DISTANCE_FROM_SUN);
            break;
        case 9:
            planet = Planet("Neptune", NEPTUNE_SURFACE_GRAVITY, NEPTUNE_DISTANCE_FROM_SUN);
            break;
        case 10:
            planet = Planet("Pluto", PLUTO_SURFACE_GRAVITY, PLUTO_DISTANCE_FROM_SUN);
            break;
        case 0:
            cout << "You typed " << menuChoice << " to quit, exiting program." << endl;
            return EXIT_SUCCESS;
            break;
        default:
            cout << "Invalid input. Please enter a valid number. Restarting . . ." << endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
        }
    }

    cout << endl;

    cout << "Please enter your weight on Earth: ";
    cin >> weightOnEarthLB;
    cout << endl;

    cout << "Please enter your average travel speed in km/h: ";
    cin >> speedKMH;
    cout << endl;

    travelTimeToPlanetHours = planet.calculateDistanceFromEarth() / speedKMH;
    travelTimeToPlanetDays = travelTimeToPlanetHours / 24;
    travelTimeToPlanetYears = travelTimeToPlanetHours / 8760; // 8760 hours in a year

    // dashes used to make the GUI box around the travel message
    string dashes = "";
    dashes.resize(49 + planet.getName().length(), '-');

    cout << dashes << endl;
    cout << "| INTERPLANETARY TRAVEL CALCULATIONS: Earth to " << planet.getName() << " |" << endl;
    cout << dashes << endl;
    cout << "Your approximate weight on " << planet.getName() << ": " << fixed << setprecision(2) << planet.calculateWeightOnPlanet(weightOnEarthLB) << " lbs" << endl;
    cout << endl;
    cout << "Approximate travel time to " << planet.getName() << ":" << endl;
    cout << "\tIn Hours: " << travelTimeToPlanetHours << " hours" << endl;
    cout << "\tIn Days:  " << travelTimeToPlanetDays << " days" << endl;
    cout << "\tIn Years: " << travelTimeToPlanetYears << " years" << endl;
    return EXIT_SUCCESS;
}