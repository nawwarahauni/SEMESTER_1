//Programmer: Nawwarah Auni binti Nazrudin
//Matric Number: A23CS0143
//Date: 31/12/2023

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//function prototype
void readFile(ifstream&, float[], int&);
void computeC(float[], float[], int);
float average(float[], int);
char grade(char[], float[], int, int[]);
void writeFile(ofstream&, float[], float[], int, char[]);

int main()
{
	const int SIZE = 8;
	float F[SIZE];
	float C[SIZE];
	char G[SIZE];
	
	int count[3] = {0};
	int numData = 0;
	
	ifstream in;
	in.open("inputFile.txt");
	ofstream out;
	out.open("outputFile.txt");
	
	//Function call 1 - read data and store in array
	readFile (in, F, numData);

	//Function call 2 - computes the values of C
	computeC (F, C, numData);
	
	//Printing summary
	cout << "Average of the temperature in Celcius: " << fixed << setprecision(1) 
	//Function 3 - computes the average of a list of numbers stored in an array
	<< average (C, numData) << endl;
	//Function 4 - determines whether the temperature (C) is high or medium or low
	grade(G, C, numData, count);
	cout << "Number of high temperature: " << count[0] << endl;
	cout << "Number of medium temperature: " << count[1] << endl;
	cout << "Number of low temperature: " << count[2] << endl;
	
	//Function call 5 - prints the output file 
	writeFile (out, F, C, numData, G);
}

//Function 1 - This function reads in a list of numbers from a text file and stores them into a one dimensional array.
void readFile (ifstream& inF, float f[], int& x)
{
	float num;
	
	//Check if file exist
	if(!inF.is_open())
	{
		cout << "File could not be opened" << endl;
	}
	
	//copying data from file into array
	while (!inF.eof())
	{
		for(int i = 0; i < 8; i++)
		{
			inF >> num;
			f[i] = num;
			x = x + 1;
		}
	}
}

//Function 2 - This function computes the values of C
void computeC (float F[], float C[],int x)
{
	for (int i = 0; i < x; i++)
	{
		C[i] = (5.0 / 9.0) * (F[i] - 32);
	}
}

//Function 3 - This function computes the average of a list of numbers stored in an array
float average (float C[], int x) 
{
	float sum = 0;
	for (int i = 0; i < x; i++)
		sum += C[i];
		
	float ave  = sum / x;
	return ave;
}

//Function 4 - This function determines either temperature (C) is high or medium or low. 
char grade (char G[], float C[], int x, int count[])
{
	for (int i = 0; i < x; i++)
	{
		if (C[i] >= 35)
		{	
			G[i] = 'H';
			count[0]++;
		}
		else if (C[i] >= 20)
		{
			G[i] = 'M';
			count[1]++;
		}
		else
		{
			G[i] = 'L';
			count[2]++;
		}
	}
}

//Function 5 - This function prints the output file as in Figure 7.
void writeFile (ofstream& outF, float F[], float C[], int x, char G[])
{ 
	if(!outF.is_open())
	{
		cout << "File could not be opened" << endl;
	}

	outF << setw (14) << "C(Celcius)" << setw(16) << "F(Farenheit)" << setw(15) << "Description" << endl;
	outF << setw (14) << "==========" << setw(16) << "============" << setw(15) << "===========" << endl;
	
	for (int i = 0; i < x; i++)
	{
		outF << fixed << setprecision(2);
		outF << setw(11) << C[i] << setw(16) << F[i] << setw(13) << G[i] << endl;
	}
	
	outF.close();
}
