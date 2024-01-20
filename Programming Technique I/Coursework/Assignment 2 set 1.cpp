#include <iostream>
using namespace std;

int main () {
	
	//defined variables
	char g, ans; //g=gender
	int age;
	float w, h; //w=weight, h=height
	float BMR, BMI;
	
	//input
	cout << "Enter gender (M or F): ";
	cin >> g;
	cout << "Enter age: ";
	cin >> age;
	cout << "Enter weight: ";
	cin >> w;
	cout << "Enter height: ";
	cin >> h;
	
	//callculate BMR 
	if (g=='M')
		BMR = (10 * w) + (6.25 * h) - (5 * age) + 5;
	else
		BMR = (10 * w) + (6.25 * h) - (5 * age) - 161;
		
	//display BMR
	cout << BMR << endl;
	
	//loop for calculating BMI
	cout << "Do you want to calculate your BMI? (Y or N)" << endl;
	cin >> ans;
	
	while (ans=='Y'){
		BMI = w /(h * h);
		cout << BMI << endl;
		cout << "Do you want to calculate your BMI? (Y or N)" << endl;
		cin >> ans;
	}
}


