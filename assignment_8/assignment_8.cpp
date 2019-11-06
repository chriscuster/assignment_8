/*
Christopher Custer
Assignment 8
Description: create code that will output images using different functions.

*/

// Code provided for assignment 8
// no main function algorithm required.

#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

// prototype for student written 
// functions
void fish();
double mysteryY(double);
double mysteryX(double);
void mystery();
void archimedean();

// provided
void genPlotScript(string);

// Global named constant
const double PI = 3.14159;

int main()
{
	char selection = ' ';

	while (true) {
		cout << "Parametric Equation Plotter" << endl;
		cout << "---------------------------" << endl;
		cout << "F/f - Fish Curve " << endl;
		cout << "A/a - Archimedean " << endl;
		cout << "M/m - Mystery" << endl;
		cout << "Q/q - quit" << endl;
		cout << "Selection: ";

		cin >> selection;

		switch (selection)
		{
		case 'F':
		case 'f':

			fish();
			genPlotScript("fish");
			system("gnuplot fish_plot.me");
			break;

		case 'A':
		case 'a':
			archimedean();
			genPlotScript("archimedean");
			system("gnuplot archimedean_plot.me");
			break;

		case 'm':
		case 'M':
			cout << "Mystery Equation plotter" << endl;
			mystery();
			genPlotScript("mystery");
			system("gnuplot mystery_plot.me");
			break;

		case 'q':
		case 'Q':
			cout << "Exiting ... " << endl;
			exit(0);

		default:
			cout << "Error -  try again" << endl;
		}
	}
}

//function algorithm here along with function documentation


void fish()
{
	const string filename = "fish.txt";
	ofstream outfile;
	outfile.open(filename);

	if (!outfile.is_open())
	{
		cout << "Could not open " << filename << endl;
		exit(0);
	}

	int size = 1;
	int rotation = 1;
	int count = 5;
	double offset = 1.2;

	for (double t = 0; t <= (10 * PI); t += 0.1)
	{
		double x = size * (cos(t) + 2.0 * rotation * cos(t / 2.0));
		double y = size * sin(t);

	}


}


//function algorithm here along with function documentation
void archimedean()
{
	const string filename = "archimedean.txt";
	ofstream outfile;
	outfile.open(filename);

	if (!outfile.is_open())
	{
		cout << "Could not open " << filename << endl;
		exit(0);
	}

	int count = 3;
	int size = 1;
	for (double t = 0; t < (count * 2 * PI); t += 0.1)
	{
		double x = size * t * cos(t + size);
		double y = size * t * sin(t + size);

		outfile << x << " " << y << endl;
	}



}

//function algorithm here along with function documentation
void mystery()
{
	for (int t = -8; t <= 8; t += 0.001)
	{

	}

}

//function algorithm here along with function documentation
double mysteryX(double t)
{

	double x = (abs(t) / t)
		* ((0.3) * abs(t) + 0.2
			* abs(abs(t) - 1) + 2.2
			* abs(abs(t) - 2) - 2.7
			* abs(abs(t) - 3) - 3
			* abs(abs(t) - 5) + 3
			* abs(abs(t) - 7)
			+ 5 * sin((PI / 4) * (abs(abs(t) - 3) - abs(abs(t) - 4) + 1))
			+ (5 / 4) * pow((abs(abs(t) - 4) - abs(abs(t) - 5) - 1), 3)
			- 5.3 * cos(((PI / 2) + asin(47 / 53)) * ((abs(abs(t) - 7) - abs(abs(t) - 8) - 1) / 2)) + 2.8);

	return x;

}

//function algorithm here along with function documentation
double mysteryY(double t)
{

	double y = (3 / 2)
		* abs(abs(t) - 1)
		- (3 / 2) * abs(abs(t) - 2)
		- (29 / 4) * abs(abs(t) - 4)
		+ (29 / 4) * abs(abs(t) - 5)
		+ (7 / 16) * pow(abs(abs(t) - 2) - abs(abs(t) - 3) - 1, 4)
		+ (4.5 * sin((PI / 4) * (abs(abs(t) - 3) - abs(abs(t) - 4) - 1)))
		- ((3 * sqrt(2)) / 5) * pow(abs(abs(abs(t) - 5) - abs(abs(t) - 7)), 5 / 2)
		+ 6.4 * sin((PI / 2 + asin(47 / 53)) * ((abs(abs(t) - 7) - abs(abs(t) - 8) + 1) / 2)
			+ asin(56 / 64)) + 4.95;

	return y;
}

/* genPlotScript
   Creates a gnuplot script to plot the specified file.
   argument
	str - contains the filename of the text file to be plotted.

   return
	none
*/
void genPlotScript(string str)
{
	string first = "set terminal png size 640, 480 font \"Helvetica,8\" \nset output ";
	string second = " using 1:2 with lines notitle\n";

	ofstream oFile;

	oFile.open(str + "_plot.me");
	if (oFile.is_open()) {
		oFile << first;
		oFile << '\"' << str + ".png" << '\"' << endl;
		oFile << "plot " << '\"' << str + ".txt" << '\"';
		oFile << second;
		oFile.close();
	}
}



