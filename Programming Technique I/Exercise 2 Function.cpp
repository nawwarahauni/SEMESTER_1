//Programmer:Nawwarah Auni binti Nazrudin
//Matric number:A23CS0143
//Date:17/12/2023
//Purpose:to determine and display active case, status, total active cases, highest, highest state and average from state name, total cases, new cases, total death and total recovered

#include <iostream>
#include <string>
using namespace std;

//Function prototype
void getInput(int &,int &, int &, int &);
void dispOutput(int);
void dispStatus(int);
int calcAverage (int, int);

int main(){
	//declare variable
	string state, highestState; 
	int activeCases, totalCases, newCases, totalDeath, totalRecovered;
	int numStates=0, totalActiveCases=0, highest=-999;
		
	do{	
		//data 
		cout << "\n<<<<<<<<<<<<<< DATA >>>>>>>>>>>>>" << endl;
		cout << "State name: ";
		getline(cin, state);
		//function call task 2
		getInput(totalCases, newCases, totalDeath, totalRecovered);
		
		//summary
		cout << "\n<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>" << endl;
		activeCases = totalCases + newCases - totalDeath - totalRecovered;
		cout << "Active cases: " << activeCases << endl;
		//Function call task 3
		dispOutput (activeCases);
		
		//to determine highest case and highest state
		if (activeCases > highest){
			highest = activeCases;
			highestState = state;
		}
		
		totalActiveCases = totalActiveCases + activeCases;
		numStates = numStates + 1;
		
		//input to continue
		cin.ignore();
		cout << "\n\nPress <ENTER> to continue...";
		
	} while(cin.get() == '\n');
	
	//active cases
	cout << "\n<<<<<<<<< ACTIVE CASES >>>>>>>>>>" << endl;
	cout << "Total: " << totalActiveCases << endl;
	cout << "Highest: " << highest << " (" << highestState << ")" << endl;
	//display and function call task 4
	cout << "Average for " << numStates << " states: " << calcAverage(totalActiveCases, numStates);
	
	return 0;
}

//task 2 - reference variable
//Purpose: to get input of totalCases, newCases, totalDeath, totalRecovered
void getInput (int &a, int &b, int &c, int &d){
	cout << "Total cases: ";
	cin >> a;
	cout << "New cases: ";
	cin >> b;
	cout << "Total death: ";
	cin >> c;
	cout << "Total recovered: ";
	cin >> d;
}

//task 3
//Purpose: to call task 1 and display status based on activeCases
void dispOutput(int m){
	//Function call task 1
	dispStatus(m);
}

//task 1 
//Purpose: to determine and display status based on activeCases
void dispStatus(int n){
	if (n > 40) 
    	cout << "Status: Red zone";    
    else if (n >= 21 && n <= 40) 
        cout << "Status: Orange zone";
    else if (n >= 1 && n <= 20) 
        cout << "Status: Yellow zone";
    else if (n == 0) 
        cout << "Status: Green zone";
}

//task 4
//Purpose: To calculate average based on total active cases and number of states entered
int calcAverage(int x,int y){
	int ave = x/y;
	return ave;
}
