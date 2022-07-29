#include "machine.h"
//-----------------------------------------------------------
// Constructor function
//-----------------------------------------------------------
Machine::Machine ()
{
  Machine_Name = "";
  Machine_Manufacturer = "";
  Make_Year = 0;
  Machine_Type = "";
}

/*Machine::Machine(string machine_name, string machine_manufacturer, int make_year, string machine_type)
{
    Machine_Name = machine_name;
    Machine_Manufacturer = machine_manufacturer;
    Make_Year = make_year;
    Machine_Type = machine_type;
}*/

//-----------------------------------------------------------
// Destructor function
//-----------------------------------------------------------
Machine::~Machine ()
{

}

//-----------------------------------------------------------
// Get machine name
//-----------------------------------------------------------
string Machine::getMachineName ()
{
  return Machine_Name;
}

//-----------------------------------------------------------
// Get manufacturer
//-----------------------------------------------------------
string Machine::getManufacturer ()
{
  return Machine_Manufacturer;
}

//-----------------------------------------------------------
// Get make year
//-----------------------------------------------------------
int
Machine::getMakeYear ()
{
  return Make_Year;
}

//-----------------------------------------------------------
// Get machine type
//-----------------------------------------------------------
string Machine::getMachineType ()
{
  return Machine_Type;
}

//-----------------------------------------------------------
// Set machine name
//-----------------------------------------------------------
void
Machine::setMachineName (string machine_name)
{
  Machine_Name = machine_name;
}

//-----------------------------------------------------------
// Set manufacturer
//-----------------------------------------------------------
void
Machine::setManufacturer (string machine_manufacturer)
{
  Machine_Manufacturer = machine_manufacturer;
}

//-----------------------------------------------------------
// Set make year
//-----------------------------------------------------------
void
Machine::setMakeYear (int make_year)
{
  Make_Year = make_year;
}

//-----------------------------------------------------------
// Set machine type
//-----------------------------------------------------------
void
Machine::setMachineType (string machine_type)
{
  Machine_Type = machine_type;
}

//-----------------------------------------------------------
// Read Machine from text file
//-----------------------------------------------------------
void
Machine::read_file (string filename)
{
  ifstream din;
  string Mn, Man, Mt, My;	//Mn(Machine name) Man(Manufacturer name) Mt(Machine type) My(Machine year)
  din.open (filename.c_str ());
  if (din.fail ())
    {
      cout << "Error";
    }

  while (!din.eof ())
    {
      Machine data;
      getline (din, Mn, ',');
      getline (din, Man, ',');
      getline (din, My, ',');
      getline (din, Mt);
      data.setMachineName (Mn);
      data.setManufacturer (Man);
      data.setMakeYear (stoi (My));
      data.setMachineType (Mt);
      gameMachines.push_back (data);

    }
  // Close input file
  din.close ();
}

//-----------------------------------------------------------
// Recursive search
//-----------------------------------------------------------
int
Machine::recursiveSearch (string machineNames, int min, int max)
{
  int mid = (min + max) / 2;	// Midpoint
  if (min > max)
    {
      return -1;
    }
  else if (gameMachines[mid].Machine_Name == machineNames)
    {
      return mid;		// Look if value is found
    }
  else if (gameMachines[mid].Machine_Name > machineNames)
    {
      return recursiveSearch (machineNames, min, mid - 1);	// Left
    }
  else
    {
      return recursiveSearch (machineNames, mid + 1, max);	// Right
    }
}

//-----------------------------------------------------------
// Iterative search
//-----------------------------------------------------------
int
Machine::iterativeSearch (int machineYear, int x, int target)
{
  int low = 0, high = x - 1;
  while (low <= high)
    {
      int mid = (low + high) / 2;	// Find mid value   
      if (target == gameMachines[mid].Make_Year == machineYear)
	{
	  return mid;		// Value is found
	}
      else if (target < gameMachines[mid].Make_Year)
	{
	  high = mid - 1;	// Get rid of right
	}
      else
	{
	  low = mid + 1;	// Get rid of left
	}
    }
  return -1;
}

//-----------------------------------------------------------
// Print all data
//-----------------------------------------------------------
void
Machine::printAll ()
{
  for (int i = 0; i < gameMachines.size (); i++)
    cout << gameMachines[i].Machine_Name;
}

//-----------------------------------------------------------
// Print one piece of data
//-----------------------------------------------------------
void
Machine::printSingle (int position)
{
  cout << gameMachines[position].Machine_Name;
}
