#include <iostream>
#include <string>
using namespace std;

//base class called Vehicle 
class Vehicle {
public:
    string make;
    string model;
    int year;

    // Virtual function to calculate rental cost
    virtual double calculateRentalCost(int days) const = 0;

    // Function to display vehicle details
    virtual void display() const {
        cout << "Make: " << make << ",Type of the model: " << model << ", Year introduced: " << year << endl;
    }
};
// Derived class called Car
class Car : public Vehicle {
public:
    int numDoors;

    //function to calculate rental cost of Car
    double calculateRentalCost(int days) const override {
        return 150.0 * days;//example cost calculation :$150 per day
    }

    // function to display Car details i.e number of doors 
    void display() const override {
        Vehicle::display();
        cout << "Number of doors: " << numDoors << endl;
    }
};
// derived class called SUV
class SUV : public Vehicle {
public:
    string enginetype;  // Is the SUV a petrol or diesel engine driven 

    // Function to calculate rental cost for the SUV
    double calculateRentalCost(int days) const override {
        return 200.0 * days; // Example cost calculation: $200 per day
    }

    // Function to display SUV details, including enginetype
    void display() const override {
        Vehicle::display();
        cout << "Engine Driven Type: " << enginetype<< endl;
    }
};
//derived class called Truck
class Truck : public Vehicle {
public:
    double cargoCapacity; // Cargo capacity of the truck in tonnes

    // Function to calculate rental cost for the truck
    double calculateRentalCost(int days) const override {
        return 300.0 * days; // Example cost calculation: $300 per day
    }

    // Function to display truck details, including cargo capacity
    void display() const override {
        Vehicle::display();
        cout << "Cargo Capacity: " << cargoCapacity << " tons" << endl;
    }
};
// main function 
int main() {
    // Creating a Car object and setting its attributes
    Car car1;
    car1.make = "\n Volkswagen";
    car1.model = "Golfwagen";
    car1.year = 2018;
    car1.numDoors = 4;

    // Display car details and calculate rental cost
    car1.display();
    cout << "Rental Cost for 5 days: $ " << car1.calculateRentalCost(5) << endl;

    // Creating an SUV object and setting its attributes
    SUV suv1;
    suv1.make = "\n Aeolus";
    suv1.model = "Haoji";
    suv1.year = 2022;
    suv1.enginetype="petrol-driven";

    // Display SUV details and calculate rental cost
    suv1.display();
    cout << "Rental Cost for 5 days: $ " << suv1.calculateRentalCost(5) << endl;

    // Creating a Truck object and setting its attributes
    Truck truck1;
    truck1.make = "\n GMC";
    truck1.model = "GMC Canyon";
    truck1.year = 2004;
    truck1.cargoCapacity = 20;

    // Display truck details and calculate rental cost
    truck1.display();
    cout << "Rental Cost for 5 days: $ " << truck1.calculateRentalCost(5) << endl;

    return 0;
};