// implementation file for Mortgage class
#pragma once
#include "Mortgage.h"
#include <cmath>
using namespace std;
//Public Functions
/*=================================================================
	Mortgage - Constructor for mortgage
			If the user passes values data will be initialized to 
			what they passed
			otherwise the values will default to zero.
=================================================================*/
Mortgage::Mortgage(float userLoan = 0.0f, float userRate = 0.0f, float userYears = 0.0f)
{
	years = userYears;
	loan = userLoan;
	rate = userRate;
	payment = 0.0f;
	totalAmountPaid = 0.0f;
	setLoanData();
}
/*=================================================================
	setLoanData - sets the loan data eg. monthlay payent and total amount paid over course of loan
=================================================================*/
void Mortgage::setLoanData()
{
	setTerm();
	calculatePayment();
	calculateTotalAmountPaid();
}
/*=================================================================
	setLoan - sets the amount the loan is for to a value passed by the user.
=================================================================*/
void Mortgage::setLoan(float userLoan)
{
	loan = userLoan;
	setLoanData();
}
/*=================================================================
	setYears - sets the number of years the loan will be paid off in
			   with the value in userYears
=================================================================*/
void Mortgage::setYears(float userYears)
{
	years = userYears;
	setLoanData();
}
/*=================================================================
	setRate - sets the interest rate with the entered value.
=================================================================*/
void Mortgage::setRate(float userRate)
{
	rate = userRate;
	setLoanData();
}
/*=================================================================
	getPayment - returns the float value for the loans monthly payment
=================================================================*/
float Mortgage::getPayment()
{
	return payment;
}
/*=================================================================
	getTotalAmountPaid - returns the floating point value of the total 
						 amount of money paid to the bank over the course of the loan
=================================================================*/
float Mortgage::getTotalAmountPaid()
{
	return totalAmountPaid;
}

//Private Functions

/*=================================================================
	setTerm - calculates the term for the loan
=================================================================*/
void Mortgage::setTerm() 
{
	term = powf((1L + (rate / 12.0f)), (12.0f * years));
}
/*=================================================================
	calculatePayment - calculates the monthly loan payment.
=================================================================*/
void Mortgage::calculatePayment()
{
	payment = ((loan * (rate / 12.0f) * term) / (term - 1.0f));
}
/*=================================================================
	calculateTotalAmountPaid - calculates the total amount of money paid to the bank 
							   over the course of the loan.
=================================================================*/
void Mortgage::calculateTotalAmountPaid()
{
	totalAmountPaid = payment * (years * 12.0f);
}
