//Programmer: Nawwarah Auni binti Nazrudin
//Matric number: A23CS0143
//Date: 5/11/2023

#include <iostream>
using namespace std;

int main() {
	
	//define variables
	int oriNum, product, newNum;
	product = 1;
	
	//input
	cout << "Enter an integer number: "; 
	cin >> oriNum; 
	
	//pre-test loop
	//to find product
	while (oriNum != 0){	
		newNum = oriNum % 10;
		product *= newNum; 
		oriNum /= 10;	
		// output product 
		 if (oriNum != 0) 
            cout << newNum << " * ";
		else 
            cout << newNum << " = " << product << endl; 
    }	
	
	//to identify whether the product is multiple of 4,5 or 7 and display messages
	if (product % 4 == 0 && product % 5 == 0 && product % 7 == 0) 
		cout << product << " is multiples of 4, 5 and 7" << endl;
	else if (product % 4 == 0 && product % 5 == 0) 
		cout << product << " is multiples of 4 and 5" << endl;
	else if (product % 7 == 0 && product % 4 == 0 ) 
		cout << product << " is multiples of 7 and 4" << endl;
	else if (product % 7 == 0 && product % 5 == 0 ) 
		cout << product << " is multiples of 7 and 5" << endl;
	else if (product % 4 == 0) 
		cout << product << " is multiples of 4" << endl;
	else if (product % 5 == 0)
		cout << product << " is multiples of 5" << endl;
	else if (product % 7 == 0) 
		cout << product << " is multiples of 7" << endl;
	else  
		cout << product << " is not multiples of 4, 5 and 7" << endl;
		
}


