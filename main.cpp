#include <iostream>
#include "machine.h"
using namespace std;
//-----------------------------------------------------------
// Purpose: Main file for program.
// Author:  Andrew Murphy
//-----------------------------------------------------------
int main ()
{
  Machine m;
  Machine mYear;
  m.read_file("machines-100.txt");
  mYear.read_file("machines-by-year-100.txt");
  string command = "";
  while (command != "0")
    {
      // Read user command
      cout << "Welcome to the pinball and arcade machine checker.  Please choose from the following:\n";
      cout << "0) Quit\n";
      cout << "1) Use a recursive search for game title\n";
      cout << "2) Use an iterative search for all machines manufactured in a specific year\n";
      cout << "Enter command: ";
      getline(cin, command);

      // Search list based off game title
      if (command == "1")
	{
	  string title = "";
	  cout << "Please input title ";
	  getline(cin, title);
	  int searchPosition = m.recursiveSearch(title, 0, m.gameMachines.size());
	  cout << "The game is: ";
	  m.printSingle(searchPosition);
	  cout << endl;
	}

      // Search list based off target year
      if (command == "2")
	{
	  string targetYear = "";
	  cout << "Please input target year ";
	  getline(cin, targetYear);
	 
	}
    }
}