/*  Program: test
Author: Kevin Quan
Class: csci140 1:45
Date: 9/13/2018
Description: Program that calculates average tests
I certify that the code below is my own work.
Exception(s): N/A
*/

#include "pch.h"
#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

void printCondition();
bool isMultiple(int n);
int qChange(int& q, double& total);
int dChange(int& d, double& total);
int nChange(int& n, double& total);
int GetQuartersForTransaction(int machineQuarters, double& neededTotal);
int GetDimesForTransaction(int machineDimes, double& neededTotal);
int GetNicklesForTransaction(int machineNickles, double& neededTotal);

int main()
{
	cout << "Author: Kevin Quan\n";

	int q, d, n;
	int qleft = 0, dleft = 0, nleft = 0, ans = 1, dollar = 0;
	double qdntotal = 0, total;

	cout << "Fill up machine with changes. Please wait . . ." << endl;
	cout << "Enter number of quarters, dimes, and nickels -->: ";
	cin >> q >> d >> n;
	cout << "There are " << q << " quarters " << d << " dimes and " << n
		<< " nickels." << endl;

	qdntotal = double(q*0.25) + (d * 0.10) + (n * 0.05);

	cout << "Initial machine balance is $" << fixed << setprecision(2) << qdntotal << ".\n";

	while (ans != 0) {
		cout << "Enter a purchase amount [0 - 100] --> ";
		cin >> ans;

		if (ans >= 0 && ans <= 100) {
			if (isMultiple(ans)) {
				total = 1 - double(ans) / 100;

				if (qdntotal > total) {
					dollar++;

					cout << "You entered a purchase amount of " << ans << " cents.\n";
					cout << "Please insert one-dollar bill.\n";
					cout << "Processing your purchase . . .\n";
					cout << " Your change of " << total << " cents is given as:";

					/*
					qleft = qChange(q, total);
					dleft = nChange(n, total);
					nleft = dChange(d, total);
					*/

					int outputQuarters, outputDimes, outputNickles;
					outputQuarters = GetQuartersForTransaction(q, total);
					outputDimes = GetDimesForTransaction(d, total);
					outputNickles = GetNicklesForTransaction(n, total);

					if (total > 0.0) {
						cout << "Cannot do the transaction." << endl;
					}
					else {
						cout << endl << endl << "Transaction Successful!" << endl << "Used Quarters: " << outputQuarters << " Dimes: " << outputDimes << " Nickles: " << outputNickles << endl << endl;
						q -= outputQuarters;
						d -= outputDimes;
						n -= outputNickles;
					}

				}
			}
		}

		else if (ans >= 0 && ans <= 100) {
			if (isMultiple(ans)) {
				total = 1 - double(ans) / 100;
				if (qdntotal < total) {
					cout << "You entered a purchase amount of " << ans << " cents.\n";
					cout << "Please insert one-dollar bill.\n";
					cout << "Processing your purchase ... \n";
					cout << "Insufficient changes!\n";
					cout << "Your transaction cannot be processed. \n";
					cout << "Please take back your dollar bill.\n\n";
				}
			}
		}

		else if (ans <= 0 || ans >= 100) {
			cout << "You entered a purchase amount of " << ans << " cents.\n";
			cout << "Invalid amount (outside valid range). Try again.\n\n";
			ans = 1;
		}

		else if (ans >= 0 && ans <= 100) {
			if (!isMultiple(ans)) {
				cout << "You entered a purchase amount of " << ans << " cents\n";
				cout << "Invalid amount (not a multiple 5). Try again.\n\n";
				ans = 1;
			}
		}

		/*
		Need to displaya
		*/

		/*
				if (ans <= 0 || ans >= 100) {
					cout << "You entered a purchase amount of " << ans << " cents.\n";
					cout << "Invalid amount (outside valid range). Try again.\n\n";
					ans = 1;
				}

				else if (ans >= 0 && ans <= 100) {
					if (!isMultiple(ans)) {
						cout << "You entered a purchase amount of " << ans << " cents\n";
						cout << "Invalid amount (not a multiple 5). Try again.\n\n";
						ans = 1;
					}
				}

				else if (ans >= 0 && ans <= 100) {
					if (isMultiple(ans)) {
						total = 1 - double(ans) / 100;
						if (qdntotal < total) {
							cout << "You entered a purchase amount of " << ans << " cents.\n";
							cout << "Please insert one-dollar bill.\n";
							cout << "Processing your purchase ... \n";
							cout << "Insufficient changes!\n";
							cout << "Your transaction cannot be processed. \n";
							cout << "Please take back your dollar bill.\n\n";
						}
					}
				}

				else if (ans >= 0 && ans <= 100){
					if (isMultiple(ans)) {
						total = 1 - double(ans) / 100;

						if (qdntotal > total) {
							dollar++;

							cout << "You entered a purchase amount of " << ans << " cents.\n";
							cout << "Please insert one-dollar bill.\n";
							cout << "Processing your purchase . . .\n";
							cout << " Your change of " << total << " cents is given as:";

							qleft = qChange(q, total);
							dleft = nChange(n, total);
							nleft = dChange(d, total);
						}
					}
				}
			}

		cout << "Final report is being generated ...\n";
		cout << "There are 2 valid transactions.\n";
		cout << left << setw(15) << "Number of dollars" << ": " << dollar<<endl;
		cout << left << setw(15) << "Number of quarters" << ": " << q << endl;
		cout << left << setw(15) << "Number of dimes" << ": " << d << endl;
		cout << left << setw(15) << "Number of nickels" << ": " << n << endl;
		cout << left << setw(15) << "Machine balance" << ": " << qdntotal << endl;
		cout << "Machine is shutting down. Good bye.";
		*/
	}
}
bool isMultiple(int n) {
	if (n % 5 == 0)
		return true;
	else
		return false;
}


void printCondition()
{
	cout << "Only one-dollar bill will be accepted.\n";
	cout << "Only amount between 0 to 100 and multiple of 5 is accepted.\n";
	cout << "Enter 0 to stop the program.\n";
	cout << "Machine is now ready.\n";
}

int GetQuartersForTransaction(int machineQuarters, double& neededTotal) {

	int hypotheticalQuarters = 0;

	for (hypotheticalQuarters = 0; neededTotal >= 0.25 && hypotheticalQuarters <= machineQuarters; hypotheticalQuarters++) {
		neededTotal -= 0.25;
	}

	return hypotheticalQuarters;

}

int GetDimesForTransaction(int machineDimes, double& neededTotal) {

	int hypotheticalDimes = 0;

	for (hypotheticalDimes = 0; neededTotal >= 0.10 && hypotheticalDimes <= machineDimes; hypotheticalDimes++) {
		neededTotal -= 0.25;
	}

	return hypotheticalDimes;

}

int GetNicklesForTransaction(int machineNickles, double& neededTotal) {

	int hypotheticalNickles = 0;

	for (hypotheticalNickles = 0; neededTotal >= 0.05 && hypotheticalNickles <= machineNickles; hypotheticalNickles++) {
		neededTotal -= 0.25;
	}

	return hypotheticalNickles;

}

int qChange(int& q, double& total)
{
	int count = 0, qC = 0;

	for (count = 0; count < q; count++) {
		if (total >= 0.25) {
			q--;
			total = total - 0.25;
			if (q > 0)
				qC++;
		}
		else {
			continue;
		}

	}
	cout << left << setw(12) << "\tquarter(s):" << qC << endl;
	return q;
}

int dChange(int& d, double& total)
{
	int count = 0, dC = 0;

	for (count = 0; count < d; count++) {
		if (total >= 0.10) {
			d--;
			total = total - 0.10;
			if (d > 0)
				dC++;
		}
		else {
			continue;
			cout << left << setw(12) << "\tdime(s):" << dC<<endl;
		}

	}
	return d;
}

int nChange(int& n, double& total)
{
	int count = 0, nC = 0;

	for (count = 0; count <= n; count++) {
		if (total >= 0.05) {
			n--;
			total = total - 0.05;

			if (n > 0)
				nC++;
		}
		else {
			continue;
			cout << left << setw(12) << "\tnickel(s):" << nC<<endl;
		}
	}
	return n;
}



