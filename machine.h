#ifndef MACHINE_H
#define MACHINE_H
//-----------------------------------------------------------
// Purpose: Header file for the Machine class.
// Author:  Andrew Murphy
//-----------------------------------------------------------
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Machine
{
public:
    // Constructor methods
    Machine();
    ~Machine();
    void printAll();
    void printSingle(int position);
    void read_file(string filename);
    vector<Machine> gameMachines;
    int recursiveSearch(string machineNames, int min, int max);
    int iterativeSearch(int machineYear, int x, int target);
    
    // Get methods
    string getMachineName();
    string getManufacturer();
    int getMakeYear();
    string getMachineType();
    
    // Set methods
    void setMachineName(string machine_name);
    void setManufacturer(string machine_manufacturer);
    void setMakeYear(int make_year);
    void setMachineType(string machine_type);
    
private:
    // Object attributes
    string Machine_Name;
    string Machine_Manufacturer;
    int Make_Year;
    string Machine_Type;
};
#endif