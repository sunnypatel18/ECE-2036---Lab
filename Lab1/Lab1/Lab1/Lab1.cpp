
#include "stdafx.h"
#include <iostream>
#include <string>


class GardenGnome
{
public:
	int height; //initialize the variable that will allow the user input to set a value to this bariable
	GardenGnome(string); //prompts that the contructor will have an input of a string
	// initializes all the varibles with the type and the expected input
	void setName(string); 
	void setHeight(double);
	string getName();
	double getHeight();
	void inputHeight();

private:
	//initializes the variables with the type. these variables are private because they cannot be changed unless in class GardenGnome
	double gnomeHeight; 
	string gnomeName;
};


GardenGnome::GardenGnome(string name) //sets up the constructor that has a parameter which has a type string and store into variable name
{
	gnomeName = name; //set variable name to gnomeName
	gnomeHeight = 0; //initialize gnomeHeight to zero
}

void GardenGnome::setName(string name) //member function to set gnomeName
{
	gnomeName = name;
}

void GardenGnome::setHeight(double hgt) //member function to set gnomeHeight
{
	gnomeHeight = hgt;
}

string GardenGnome::getName() //member function to get gnomeHeight
{
	return gnomeName;
}

double GardenGnome::getHeight() //implement getHeight which will be used for comparing the heights of the two gnomes
{
	return gnomeHeight;
}

void GardenGnome::inputHeight() //imputing the heights for each of the gnomes. 
{
	cout << "Please enter the height of gnome " << gnomeName << ", in inches: "; //promots the user to set the height for the gnomes
	cin >> height; //sets the user input and stores the value into variable height
	gnomeHeight = height; // sets gnomeHeight to the value of height
}

int main()
{
	GardenGnome gnome1("Michael"); //sets the value of gnome1 as Michael
	GardenGnome gnome2("Melissa"); //sets the value of gnome2 as Melissa

	gnome1.inputHeight(); //stores the first user input as the height of Michael 
	gnome2.inputHeight(); //stores the second user input as the height of Melissa

	if (gnome1.getHeight() > gnome2.getHeight()) //compare all the possible scenarios for the various gnome heights
		cout << gnome1.getName() << " is taller than " << gnome2.getName(); //taller scenario
	else if (gnome1.getHeight() < gnome2.getHeight())
		cout << gnome1.getName() << " is shorter than " << gnome2.getName(); //shorter scenario
	else if (gnome1.getHeight() == gnome2.getHeight())
		cout << gnome1.getName() << " is equally tall as " << gnome2.getName(); //equal scenario
	cout << "\n";
	return 0; 

}