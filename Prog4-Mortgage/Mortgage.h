#pragma once
// header file for Mortgage class

//mortgage class
class Mortgage
{
//Data
	public:
		float payment, 
			  totalAmountPaid;
	private:
			//loan amount
		float loan,
			//interset rate
			  rate, 
			//loan term
			  term, 
			//how many years you are paying the loan off in
			  years;
//Functions
	public:
		Mortgage(float loan, float rate, float years);
		void setLoan(float);
		void setYears(float);
		void setRate(float);
		float getPayment();
		float getTotalAmountPaid();
		void setLoanData();
	private:
		void setTerm();
		void calculatePayment();
		void calculateTotalAmountPaid();

};