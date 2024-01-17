#include<iostream>
using namespace std ;

int main()
{
	cout << "MONTHLY INSTALLMENT CALCULATOR" << endl ;
	
	int period;
	double income, carPrice, downPay, rate;
	
	//input all informations
	cout << "\nEnter your income(month): RM" ;
	cin >> income ;
	cout << "\nEnter car price : RM" ;
	cin >> carPrice ;
	cout << "Enter down payment (RM) : " ;
	cin >> downPay ;
	cout << "Enter loan period (years) : " ;
	cin >> period ;
	cout << "Enter rate (%): " ;
	cin >> rate ;
	
	//calculate monthly installment
	double totalInter, loanAmount, monthInter, monthInstall;
	loanAmount = carPrice - downPay ;
	totalInter = (rate/100) * loanAmount * period ;
	monthInter = totalInter / (period*12);
	monthInstall = (loanAmount+totalInter) / (period*12) ;
	
	cout << "\nMONTHLY INSTALLMENT : RM" << monthInstall << endl;
	
	
	double extraIncome;                
	char extra; 
	
	//ask extra income
	cout << "\nDo you have extra income? [y or n] : " ;
	cin >> extra ;
	
	if (extra == 'y'){
		cout << "Enter extra income(month) : RM" ;
		cin >> extraIncome;
	}
	else {
		extraIncome = 0 ;
	}
	
	if ((income+extraIncome) > monthInstall){
			cout << "Your budget is sufficient" << endl;
		}
	else{
			cout << "Your budget is not enough" << endl;
		}

	return 0;
}
