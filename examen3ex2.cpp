#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class GPSCords{
    private:
    int latitude;
    int longitude;
    int elevation;

    public:
    GPSCords(int latitude, int longitude, int elevation){
        this->latitude = latitude;
        this->longitude = longitude;
        this->elevation = elevation;
    }

    int getLatitude() {return latitude;}
    int getLongitude() {return longitude;}
    int getElevation() {return elevation;}
    string toString() { return "GPS(" + to_string(getLatitude()) + ", " + to_string(getLongitude()) + ", " + to_string(getElevation()) + ")"; }
};



/** EXERCISE #3 -- COMPLETE Building Abstract CLASS
 *
 * Re-factor FamilyHouse and OfficePark classes.
 * An abstract class that holds the properties and implements the methods that are
 * common to existing FamilyHouse and OfficePark classes. All the moved properties must remain
 * PRIVATE and the moved methods PUBLIC. A common method that behaves different in the subclasses
 * should be a pure virtual method in this abstract superclass and then defined in the
 * subclasses, unless the methods behave equally in both subclasses.
 *
 * The abstract class should supply an appropriate constructor to be used by subclasses
 * constructors to initialize the private properties defined in the abstract class.
 */
class Building{

    // YOUR CODE HERE
private:
    GPSCords cords;
    double builtArea;
    double landArea;

public: 
    GPSCords getCords() { return cords; }
    double getBuiltArea() { return  builtArea; }
    double getLandArea()  { return landArea; }

    Building(GPSCords c, double ba, double la) : cords(c){
        cords = c;
        builtArea  = ba;
        landArea = la;
    }

    virtual double getPeopleCapacity() = 0;
    virtual double estimateRent() = 0;

}; // End of abstract Building class

/**
 * Exercise #4 (Part A)
 * Re-factor this FamilyHouse class to remove any property or method that was
 * moved to the abstract Building class. You should modify the
 * constructor to call the super constructor appropriately.
 *
 * This class represents FamilyHouse
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

    string  toString()
    {
        return "FamilyHouse [" 
            + getCords().toString() +  ","
            + to_string(getBaths()) + ","
            + to_string(getBedRooms()) + ","
            + to_string(isFurnished()) + ","
            + to_string(getBuiltArea()) + ","
            + to_string(getLandArea()) + ","
            +  "]";
    }

    double getPeopleCapacity();
    double estimateRent();
};


/**
 * Exercise #4 (Part B)
 * Re-factor this OfficePark class to remove any property or method that was
 * moved to the abstract Building class. You should modify the
 * constructor to call the super constructor appropriately.
 *
 * This class represents a OfficePark Building
 *
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

    string  toString()
    {
        return "OfficePark [" 
            + getName() + ","
            + getCords().toString() +  ","
            + to_string(getBuiltArea()) + ","
            + to_string(getLandArea()) + ","
            + to_string(getVolume()) + ","
            + to_string(getOfficeSpaces())
            +  "]";
    }

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

// int main() 
// {
//     cout << "Hello World" << endl;

//     FamilyHouse* a1 = new FamilyHouse(GPSCords(50, -40, 5000),1,3,false,200, 600);
//     FamilyHouse* a2 = new FamilyHouse(GPSCords(70, -10, 1400),1.5,3,true,250, 650);
//     FamilyHouse* a3 = new FamilyHouse(GPSCords(50, -40, 5000),1.5,4,false,300, 700);
//     FamilyHouse* a4 = new FamilyHouse(GPSCords(70, -10, 1400),2,3,true,350, 750);
//     FamilyHouse* a5 = new FamilyHouse(GPSCords(50, -40, 5000),2,4,false,400, 800);

//     //OfficePark(string n, GPSCords c, double ba, double la, double v, int o) : name(n), cords(c) {
//     OfficePark* p1 = new OfficePark("OP1", GPSCords(30, -40, 15000),600, 1000, 6000,5);
//     OfficePark* p2 = new OfficePark("OP2", GPSCords(-50, 90, 2500),700, 1100, 6100,7);
//     OfficePark* p3 = new OfficePark("OP3", GPSCords(30, -40, 15000),800, 1300, 6300,9);
//     OfficePark* p4 = new OfficePark("OP4", GPSCords(-50, 90, 2500),1000, 2000, 12000,12);
//     OfficePark* p5 = new OfficePark("OP5", GPSCords(30, -40, 15000),2000, 2500, 12500,18);

//     // Test Exercises #3 and #4
//     // This exercise will be graded mostly manually

//     vector<Building*> familyHouses{a1, a2, a3, a4, a5};
//     cout << "FamilyHouses: " << familyHouses.size() << endl;

//     vector<Building*> officeParks{p1, p2, p3, p4, p5};
//     cout << "OfficeParks: " << officeParks.size() << endl;

//     vector<Building*> aircrafts{a1, a2, a3, a4, a5, p1, p2, p3, p4, p5};
//     cout << "Aircrafts: " << aircrafts.size() << endl;
// }