#include <iostream>
#include <string>
#include <iomanip>
#include "Mortgage.h"
using namespace std;

bool parseFloat(string sval, float &val);

int main()
{
	//format output for money
	cout << fixed << showpoint << setprecision(2);
	//flag to track input parsing success
	bool success = true;
	//strings for the user to enter their values into without crashing the program
	string years, rate, loan;
	//floats to store the parsed values of the above strings
	float parsedYears, parsedRate, parsedLoan;

	//get loan amount from the user.
	cout << "Enter your loan amount : ";
	getline(cin, loan);
	success = parseFloat(loan, parsedLoan);

	while (!success)
	{
		cout << "Error, Re-Enter your loan amount: ";
		getline(cin, loan);
		success = parseFloat(loan, parsedLoan);
	}

	//get how many years the loan is for from the user
	cout << "Enter how many years your loan is for: ";
	getline(cin, years);
	success = parseFloat(years, parsedYears);

	while (!success)
	{
		cout << "Error, Re-Enter how many years your loan is for: ";
		getline(cin, years);
		success = parseFloat(years, parsedYears);
	}

	//get interest rate from the user
	cout << "Enter your interest rate : ";
	getline(cin, rate);
	success = parseFloat(rate, parsedRate);

	while (!success)
	{
		cout << "Error, Re-Enter your interest rate: ";
		getline(cin, rate);
		success = parseFloat(rate, parsedRate);
	}
	//check and account for how the user entered the interest rate E.G. 2% vs .02
	if (parsedRate > .8)
		parsedRate /= 100.0f;

	//construct instance of Mortgage class, passing the parsed user values.
	Mortgage m(parsedLoan, parsedRate, parsedYears);

	//display values
	cout << "Your monthly payment is                      $" << setw(20) << m.getPayment() << endl
		 << "The total amount you will pay to the bank is $" << setw(20) << m.getTotalAmountPaid() << endl;

	//chastise the user for making an irresponsible financial decision
	if (m.getTotalAmountPaid() > (parsedLoan * 1.5f))
		cout << "'Sell the car, NOW' - Dave Ramsey\n";
	return 0;
}

/*=================================================================
	parseFloat - converts safe input from string to an integer
				catches an exception if the user did not enter an integer into the string
	parameters: string sval - stores user input in a string (for safety)
				float& val - reference to the float value where the converted float will be stored
	returns a bool for the status of the conversion
=================================================================*/
bool parseFloat(string sval, float &val)
{
	//local float for conversion rather (safer then converting straight into the referance
	float num;
	//bool for conversion success
	bool success = true;
	//try to convert from string to float
	try
	{
		num = stof(sval);
		val = num;
	}
	//catch exception if input was not an integer
	catch (const std::exception&)
	{
		success = false;
	}
	return success;
}