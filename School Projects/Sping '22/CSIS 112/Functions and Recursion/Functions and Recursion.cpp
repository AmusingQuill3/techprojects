//CSIS 112 Functions and Recursion Assignment -- brief statement as to the file’s purpose
//CSIS 112-B02
//<Citations if necessary> -- citations are required
//for any references you used (outside of your book,
//the website associated with your book, or references
//provided in class).
 #include <iostream>
#include <fstream>
#include<cmath>
#include<iomanip>
using namespace std;

//Declare Functions

//Calculate Payment
double CalcPayment(double, double, int);



//Create Amortization Schedule
void Amortize(int, int, double, double, double);



int main()
{
	//Introduction
	cout << "Elijah Bixby -- Functions and Recursion\n\n";


	//Declare Variables
	double Payment, Interest, Principal;
	int Term, Period;



	//Set Variable
	Period = 1;

	

	//Ask User for Principal
	cout << "Enter Loan Principal\nMust be a positive number\n";
	cin >> Principal;

	//Ensure Principal is positive
	while (cin.fail() || Principal < 0)
	{
		cout << "You must enter a number, and that number must be positive. Please try again." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> Principal;
	}



	//Ask User for Annual Interest Rate
	cout << "Enter Interest Rate in Percent Form\nFor Example, 45, 3.99, and 99\n";
	cin >> Interest;

	//Ensure Interest is positive
	while (cin.fail() || Interest < 0)
	{
		cout << "You must enter a number, and that number must be positive. Please try again." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> Interest;
	}

	// Convert Interest into Decimal
	Interest = (Interest / 100) / 12;



	//Ask User for Loan Term
	cout << "Enter Loan Term\nTerms are 10, 15, or 30\n";
	cin >> Term;

	//Ensure Term is Valid
	while (Term != 10 && Term != 15 && Term != 30)
	{
		cout << "You must enter a number that is 10, 15 or 30. Please try again." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> Term;
	}

	//Perform Calculation
	Term = Term * 12;



	//Calculate Payment Amount via Function
	Payment = CalcPayment(Principal, Interest, Term);

	

	//Call on Amortization Function
	Amortize(Period, Term, Payment, Interest, Principal);

	

	system("pause");
	return 0;
}



double CalcPayment(double Principal, double Interest, int Term)
{
	//Declare Variables
	double Payment, Interest1;



	//Create Number for Calculation
	Interest1 = Interest + 1;



	//Calculate Payment
	Payment = Principal * (Interest * (pow(Interest1, Term)) / (pow(Interest1, Term) - 1));

	return Payment;
}



void Amortize(int currentPeriod, int totalPeriods, double paymentAmount, double monthlyInterestRate, double currentBalance)
{
	int loanLife;
	double annualInterestRate, interestAmount, principalAmount;



	annualInterestRate = (monthlyInterestRate * 12) * 100;
	loanLife = totalPeriods / 12;



	//Round to the nearest cent
	paymentAmount = paymentAmount * 100;
	paymentAmount = round(paymentAmount);
	paymentAmount = paymentAmount / 100;



	//Round to the nearest cent
	currentBalance = currentBalance * 100;
	currentBalance = round(currentBalance);
	currentBalance = currentBalance / 100;



	//Display Information
	cout << "\n\nPrincipal:" << setw(30) << "" << currentBalance << endl;
	cout << "Life of Loan (10, 15 or 30 years):" << setw(6) << "" << loanLife << endl;
	cout << "Annual Interest Rate:" << setw(19) << "" << annualInterestRate << "%" << endl;
	cout << "Monthly Payment:" << setw(24) << "" << paymentAmount << endl << endl;



	cout << setw(9) << "Payment" << setw(9) << "Amount" << setw(9) << "Interest" << setw(10) << "Principal" << setw(11) << "Balance\n";
	cout << setw(47) << currentBalance << endl;



	do
	{
		interestAmount = currentBalance * monthlyInterestRate;
		principalAmount = paymentAmount - interestAmount;



		//Round to the nearest cent
		interestAmount = interestAmount * 100;
		interestAmount = round(interestAmount);
		interestAmount = interestAmount / 100;



		//Round to the nearest cent
		principalAmount = principalAmount * 100;
		principalAmount = round(principalAmount);
		principalAmount = principalAmount / 100;



		cout << setw(9) << currentPeriod 
			<< setw(9) << paymentAmount 
			<< setw(9) << fixed << setprecision(2) << interestAmount 
			<< setw(10) << fixed << setprecision(2) << principalAmount 
			<< setw(10) << fixed << setprecision(2) << currentBalance << endl;



		currentPeriod++;
		currentBalance = currentBalance - paymentAmount;
	} while (currentBalance >= 0);

	return;
}