#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Vehicle {
public:
    int vehicleID;
    string vehicleType;

    Vehicle() {
        vehicleID = 0;
        vehicleType = "";
    }

    virtual void displayInfo() {
        cout << "Vehicle Type: " << vehicleType << endl;
        cout << "Vehicle ID: " << vehicleID << endl;
    }
};

class Car : virtual public Vehicle {
public:
    int numDoors;

    void displayInfo() override {
        cout << "Vehicle Type: " << vehicleType << endl;
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Number of Doors: " << numDoors << endl;
    }
};

class Truck : virtual public Vehicle {
public:
    int cargoCapacity;

    void displayInfo() override {
        cout << "Vehicle Type: " << vehicleType << endl;
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Cargo Capacity: " << cargoCapacity << endl;
    }
};

class HeavyDutyTruck : public Car, public Truck {
public:
    int maxLoad;

    void displayInfo() override {
        cout << "Vehicle Type: " << vehicleType << endl;
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Number of Doors: " << numDoors << endl;
        cout << "Cargo Capacity: " << cargoCapacity << endl;
        cout << "Max Load: " << maxLoad << endl;
    }
};

int main() {
    ofstream write("Vehicle.dat");
    HeavyDutyTruck obj[5];

    cin.ignore();  // Clear input buffer

    for (int i = 0; i < 5; i++) {
        cout << "Enter vehicle type: ";
        getline(cin, obj[i].vehicleType);
        write << obj[i].vehicleType << endl;

        cout << "Enter vehicle ID: ";
        cin >> obj[i].vehicleID;
        write << obj[i].vehicleID << endl;

        cout << "Enter number of doors: ";
        cin >> obj[i].numDoors;
        write << obj[i].numDoors << endl;

        cout << "Enter cargo capacity: ";
        cin >> obj[i].cargoCapacity;
        write << obj[i].cargoCapacity << endl;

        cout << "Enter max load: ";
        cin >> obj[i].maxLoad;
        write << obj[i].maxLoad << endl;

        cin.ignore();  // prepare for next getline
    }

    write.close();
    return 0;
}
