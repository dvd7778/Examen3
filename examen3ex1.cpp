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


class OfficePark {
private:
    string name;
    GPSCords cords;
    double builtArea;
    double landArea;
    double volume;
    int officeSpaces;

public:
    string getName() { return name; }
    GPSCords getCords() { return cords; }
    double getBuiltArea() { return builtArea; }
    double getLandArea() { return landArea; }
    double getVolume() { return volume; }
    int getOfficeSpaces() { return officeSpaces; }

    OfficePark(string n, GPSCords c, double ba, double la, double v, int p) : name(n), cords(c) {
        builtArea = ba;
        landArea = la;
        volume = v;
        officeSpaces = p;
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

    // TODO EX #1 (Part A) -- Implement getPeopleCapacity() in OfficePark class
    double getPeopleCapacity();

    // TODO EX #2 (Part A) -- Implement estimateRent() in OfficePark class
    double estimateRent();
};

class FamilyHouse {
private:
    GPSCords cords;
    double baths;
    int bedrooms;
    bool furnished;
    double builtArea;
    double landArea;

public:
    GPSCords getCords() { return cords; }
    int getBaths() { return baths; }
    int getBedRooms() { return bedrooms; }
    bool isFurnished() { return  furnished; }
    double getBuiltArea() { return  builtArea; }
    double getLandArea()  { return landArea; }

    FamilyHouse(GPSCords c, double baths, int brooms, bool f, double  ba, double la) : cords(c) 
    {
        this->baths = baths;
        bedrooms  = brooms;
        furnished = f;
        builtArea  = ba;
        landArea = la;
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

    // TODO EX #1 (Part B) -- Implement getPeopleCapacity() in FamilyHouse class
    double getPeopleCapacity();

    // TODO EX #2 (Part B) -- Implement estimateRent() in FamilyHouse class
    double estimateRent();
};

/**
 * EXERCISE #1 (Part A) -- Implement getPeopleCapacity() in OfficePark class
 *
 * The people capacity for an OfficePark must allow 2 square meters per person.
 *      
 */
double OfficePark::getPeopleCapacity() {
    // YOUR CODE HERE
    double capacity = getBuiltArea()/2;
    return capacity;
}

/**
 * EXERCISE #2 (Part A) -- IMPLEMENT estimateRent() method in OfficePark class.
 *
 * The rent for an OfficePark can be estimated at $50 per square meter of built area
 *      
 *      
 */
double OfficePark::estimateRent() {
    // YOUR CODE HERE
    double rent = getBuiltArea() * 50;
    return rent;
}

/**
 * EXERCISE #1 (Part B) -- Implement getPeopleCapacity() in FamilyHouse class
 *
 * The people capacity of a FamilyHouse is 2 persons per bedroom
 *      
 */
double FamilyHouse::getPeopleCapacity() {
    // YOUR CODE HERE
    double capacity = getBedRooms()*2;
    return capacity;
}

/**
 * EXERCISE #2 (Part B) -- IMPLEMENT estimateRent() method in FamilyHouse class.
 *
 * Rent for FamilyHouse can be estimated at $1000 plus $500 per bedroom
 */
double FamilyHouse::estimateRent() {
    // YOUR CODE HERE
    double rent = 1000 + 500*getBedRooms();
    return rent;
}

// int main() 
// {
//     cout << "Hello World" << endl;

//     FamilyHouse* fh1 = new FamilyHouse(GPSCords(50, -40, 5000), 2, 3, false, 185, 500);
//     FamilyHouse* fh2 = new FamilyHouse(GPSCords(70, -10, 1400), 2.5, 4, true, 250, 800);

//     OfficePark* op1 = new OfficePark("OP1", GPSCords(30, -40, 15000), 3000, 5000, 50000, 50);
//     OfficePark* op2 = new OfficePark("OP2", GPSCords(-50, 90, 2500), 1000, 6000, 60000, 60);

//     // Test Exercise #1
//     cout << fh1->toString() << "People capacity = " << fh1->getPeopleCapacity() << endl;
//     cout << fh2->toString() << "People capacity = " << fh2->getPeopleCapacity() << endl;
//     cout << op1->toString() << "People capacity = " << op1->getPeopleCapacity() << endl;
//     cout << op2->toString() << "People capacity = " << op2->getPeopleCapacity() << endl;
//     cout << fh1->toString() << "Rent Estimate = " << fh1->estimateRent() << endl;
//     cout << fh2->toString() << "Rent Estimate = " << fh2->estimateRent() << endl;
//     cout << op1->toString() << "Rent Estimate = " << op1->estimateRent() << endl;
//     cout << op2->toString() << "Rent Estimate = " << op2->estimateRent() << endl;

// }