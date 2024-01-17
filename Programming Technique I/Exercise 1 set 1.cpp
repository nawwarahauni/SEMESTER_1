//Programmer: Nawwarah Auni binti Nazrudin
//Matric number: A23CS0143
//Date: 5/11/2023

#include <iostream>
using namespace std;

int main() {
	
	//define variables
	int oriNum, sum, newNum;
	sum = 0;
	
	//input
	cout << "Enter an integer number: "; 
	cin >> oriNum; 
	
	//post-test loop
	//to find sum
	do{	
		newNum = oriNum % 10;
		sum += newNum; 
		oriNum /= 10;	
		// output sum
		 if (oriNum != 0) 
            cout << newNum << " + ";
		else 
            cout << newNum << " = " << sum << endl; 
    }	
	while (oriNum != 0);
	
	//to identify whether the sum is multiple of 3,4 or 5 and display messages
	if (sum % 3 == 0 && sum % 4 == 0 && sum % 5 == 0) 
		cout << sum << " is multiples of 3,4 and 5" << endl;
	else if (sum % 3 == 0 && sum % 5 == 0) 
		cout << sum << " is multiples of 3 and 5" << endl;
	else if (sum % 3 == 0 && sum % 4 == 0 ) 
		cout << sum << " is multiples of 3 and 4" << endl;
	else if (sum % 4 == 0 && sum % 5 == 0 ) 
		cout << sum << " is multiples of 4 and 5" << endl;
	else if (sum % 3 == 0) 
		cout << sum << " is multiples of 3" << endl;
	else if (sum % 4 == 0)
		cout << sum << " is multiples of 4" << endl;
	else if (sum % 5 == 0) 
		cout << sum << " is multiples of 5" << endl;
	else  
		cout << sum << " is not multiples of 3, 4 and 5" << endl;
		
}


