#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GPSCords {
private:
    int latitude;
    int longitude;
    int elevation;

public:
    GPSCords(int latitude, int longitude, int elevation) {
        this->latitude = latitude;
        this->longitude = longitude;
        this->elevation = elevation;
    }

    int getLatitude() { return latitude; }
    int getLongitude() { return longitude; }
    int getElevation() { return elevation; }
    string toString() { return "GPS(" + to_string(getLatitude()) + ", " + to_string(getLongitude()) + ", " + to_string(getElevation()) + ")"; }
};

/** EXERCISE #5 -- DEFINE A NEW Locatable INTERFACE
 * Locatable abstract class
 * Includes the following pure virtual methods:
 * getLocation() to get the Building location a GPSCords object
 * setLocation() to set Building Coordinates to a given GPSCords object.
 * More details below.
 */
class Locatable {

public:
    
    // YOUR CODE HERE
    virtual GPSCords getLocation() = 0;
    virtual void setLocation() = 0;

}; //End of Abstract class Locatable


class Building : public Locatable{

    // YOUR CODE HERE
private:
    GPSCords cords;
    double builtArea;
    double landArea;

public: 
    GPSCords getCords() { return cords; }
    double getBuiltArea() { return  builtArea; }
    double getLandArea()  { return landArea; }
    GPSCords getLocation();
    void setLocation(GPSCords);

    Building(GPSCords c, double ba, double la) : cords(c){
        cords = c;
        builtArea  = ba;
        landArea = la;
    }

    virtual double getPeopleCapacity() = 0;
    virtual double estimateRent() = 0;

}; // End of abstract Building class

/**
 * EXERCISE #6 (Part A) -- IMPLEMENT NEW Locatable INTERFACE in Building class.
 */
GPSCords Building::getLocation() {
    // YOUR CODE HERE
    return cords;
}

void Building::setLocation(GPSCords c) {
    // YOUR CODE HERE
    cords = c;
}

/**
 * EXERCISE #6 (Part B) -- Inherit from Building
 */
class OfficePark : public Building {
private:
    string name;
    double volume;
    int officeSpaces;

public:
    string getName() { return name; }
    double getVolume() { return volume; }
    int getOfficeSpaces() { return officeSpaces; }

    OfficePark(string n, GPSCords c, double ba, double la, double v, int o) : Building(c, ba, la), name(n)
    {
        volume = v;
        officeSpaces = o;
    }

    // Instance methods

    double getPeopleCapacity();
    double estimateRent();
};

/**
 * EXERCISE #6 (Part B) -- Inherit from Building
 */
class FamilyHouse : public Building {
private:
    double baths;
    int bedrooms;
    bool furnished;

public:
    int getBaths() { return baths; }
    int getBedRooms() { return bedrooms; }
    bool isFurnished() { return  furnished; }

    FamilyHouse(GPSCords c, double baths, int brooms, bool f, double  ba, double la) : Building(c, ba, la)
    {
        this->baths = baths;
        bedrooms  = brooms;
        furnished = f;
    }

    // Instance methods

    double getPeopleCapacity();
    double estimateRent();
};

double OfficePark::getPeopleCapacity() {
    return 0;
}

double OfficePark::estimateRent() {
    return 0;
}

double FamilyHouse::getPeopleCapacity() {
    return 0;
}

double FamilyHouse::estimateRent() {
    return 0;
}

// int main() {

//     cout << "Hello World" << endl;

//     FamilyHouse* fh1 = new FamilyHouse(GPSCords(50, -40, 5000),1,3,false,200, 600);
//     OfficePark* op1 = new OfficePark("OP1", GPSCords(30, -40, 15000),600, 1000, 6000,5);

//     GPSCords gp1(1, 90, 200);
//     GPSCords gp2(8, 10, 1000);
//     fh1->setLocation(gp2);
//     cout << "FH1 cords: " << fh1->getLocation().toString() << endl;
//     op1->setLocation(gp1);
//     cout << "OP1 cords: " << op1->getLocation().toString() << endl;

// }