#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vehicle {
private:
    string regNumber;
    string model;
    string type;
    int capacity;
    string assignedDriver;

public:
    Vehicle(const string& reg, const string& mdl, const string& tp, int cap)
        : regNumber(reg), model(mdl), type(tp), capacity(cap), assignedDriver("None") {}

    const string& getRegNumber() const { return regNumber; }
    const string& getModel() const { return model; }
    const string& getType() const { return type; }
    int getCapacity() const { return capacity; }
    const string& getAssignedDriver() const { return assignedDriver; }

    void assignDriver(const string& driverName) {
        assignedDriver = driverName;
    }
};

class Driver {
private:
    string name;
    string licenseNumber;

public:
    Driver(const string& n, const string& lic) : name(n), licenseNumber(lic) {}

    const string& getName() const { return name; }
    const string& getLicenseNumber() const { return licenseNumber; }
};

class TransportManagementSystem {
private:
    vector<Vehicle> vehicles;
    vector<Driver> drivers;

public:
    void addVehicle(const string& reg, const string& model, const string& type, int capacity) {
        vehicles.emplace_back(reg, model, type, capacity);
        cout << "Vehicle added successfully!" << endl;
    }

    void addDriver(const string& name, const string& licenseNumber) {
        drivers.emplace_back(name, licenseNumber);
        cout << "Driver added successfully!" << endl;
    }

    void assignDriverToVehicle(const string& regNumber, const string& driverName) {
        for (auto& vehicle : vehicles) {
            if (vehicle.getRegNumber() == regNumber) {
                vehicle.assignDriver(driverName);
                cout << "Driver assigned successfully to Vehicle: " << regNumber << endl;
                return;
            }
        }
        cout << "Vehicle not found!" << endl;
    }

    void displayVehicles() {
        cout << "Registered Vehicles:" << endl;
        for (const auto& vehicle : vehicles) {
            cout << "Registration Number: " << vehicle.getRegNumber() << ", Model: " << vehicle.getModel()
                << ", Type: " << vehicle.getType() << ", Capacity: " << vehicle.getCapacity()
                << ", Assigned Driver: " << vehicle.getAssignedDriver() << endl;
        }
    }

    void displayDrivers() {
        cout << "Registered Drivers:" << endl;
        for (const auto& driver : drivers) {
            cout << "Name: " << driver.getName() << ", License Number: " << driver.getLicenseNumber() << endl;
        }
    }
};

int main() {
    TransportManagementSystem tms;

    // Adding vehicles
    tms.addVehicle("ABC123", "Toyota Camry", "Sedan", 4);
    tms.addVehicle("XYZ456", "Ford Transit", "Van", 10);

    // Adding drivers
    tms.addDriver("John Doe", "DL12345");
    tms.addDriver("Jane Smith", "DL67890");

    // Assigning driver to vehicle
    tms.assignDriverToVehicle("ABC123", "John Doe");

    // Displaying vehicles and drivers
    tms.displayVehicles();
    tms.displayDrivers();

    return 0;
}