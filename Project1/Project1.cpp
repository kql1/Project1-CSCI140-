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
int GetQuartersForTransaction(int machineQuarters, double& neededTotal);
int GetDimesForTransaction(int machineDimes, double& neededTotal);
int GetNicklesForTransaction(int machineNickles, double& neededTotal);

int main()
{
	cout << "Author: Kevin Quan\n";

	int q, d, n;
	int ans = 1, dollar = 0, count = 0;
	double qdntotal = 0, total=0, neededTotal;

	cout << "Fill up machine with changes. Please wait . . ." << endl;
	cout << "Enter number of quarters, dimes, and nickels -->: ";
	cin >> q >> d >> n;
	cout << "There are " << q << " quarters " << d << " dimes and " << n
		<< " nickels." << endl;

	qdntotal = double(q*0.25) + (d * 0.10) + (n * 0.05);

	cout << "Initial machine balance is $" << fixed << setprecision(2) << qdntotal << ".\n";
	printCondition();

	while (ans != 0) {
		cout << "Enter a purchase amount [0 - 100] --> ";
		cin >> ans;

		if (ans != 0) {
			if (ans > 0 && ans <= 100) {
				if (isMultiple(ans)) {
					total = 1 - double(ans) / 100;
					neededTotal = total;

					cout << "You entered a purchase amount of " << ans << " cents.\n";
					cout << "Please insert one-dollar bill.\n";
					cout << "Processing your purchase . . .\n";

					int outputQuarters, outputDimes, outputNickles;
					outputQuarters = GetQuartersForTransaction(q, neededTotal);
					outputDimes = GetDimesForTransaction(d, neededTotal);
					outputNickles = GetNicklesForTransaction(n, neededTotal);

					if (neededTotal > 0.01) {
						cout << "Insufficient change!\n";
						cout << "Your transaction cannot be processed. \n";
						cout << "Please take back your dollar bill.\n\n";
					}
					else {
						dollar++;
						count++;
						q -= outputQuarters;
						d -= outputDimes;
						n -= outputNickles;

						cout << "Your change of " << total << " cents is given as:\n";
						cout << left << setw(11) << "\tquarter(s)" << ": " << outputQuarters << "\n";
						cout << left << setw(11) << "\tdimes(s)" << ": " << outputDimes << endl;
						cout << left << setw(11) << "\tnickels(s)" << ": " << outputNickles << endl << endl;
						ans = 1;
					}
				}

				else {
					cout << "You entered a purchase amount of " << ans << " cents\n";
					cout << "Invalid amount (not a multiple 5). Try again.\n\n";
					ans = 1;
				}
			}

			else if (ans < 0 || ans > 100) {
				cout << "You entered a purchase amount of " << ans << " cents.\n";
				cout << "Invalid amount (outside valid range). Try again.\n\n";
				ans = 1;
			}
		}

		else {
			cout << "Final report is being generated ...\n";
			cout << "There are " << count << " valid transactions.\n";
			cout << left << setw(18) << "Number of dollars" << ": " << dollar << "\n";
			cout << left << setw(18) << "Number of quarters" << ": " << q <<endl;
			cout << left << setw(18) << "Number of dimes" << ": " << d << endl;
			cout << left << setw(18) << "Number of nickels" << ": " << n << endl;
			cout << left << setw(18) << "Machine balance" << ": $" << double(q*0.25) + (d * 0.10) + (n * 0.05)+dollar << "\n";
			cout << "Machine is shutting down. Good bye.\n";
		}
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
	cout << "Machine is now ready.\n\n";
}

int GetQuartersForTransaction(int machineQuarters, double& neededTotal) {

	int hypotheticalQuarters = 0;

	//0.25 is not 0.250000000000 its 0.24999999999956
	for (hypotheticalQuarters = 0; neededTotal >= 0.24 && hypotheticalQuarters < machineQuarters; hypotheticalQuarters++) {
		neededTotal -= 0.25;
	}

	return hypotheticalQuarters;

}

int GetDimesForTransaction(int machineDimes, double& neededTotal) {

	int hypotheticalDimes = 0;

	//0.1 is not 0.1000000000 its 0.10000000056
	for (hypotheticalDimes = 0; neededTotal >= 0.09 && hypotheticalDimes < machineDimes; hypotheticalDimes++) {
		neededTotal -= 0.10;
	}

	return hypotheticalDimes;

}

int GetNicklesForTransaction(int machineNickles, double& neededTotal) {

	int hypotheticalNickles = 0;

	//0.05 is not 0.05000000000 its 0.05000000000056
	for (hypotheticalNickles = 0; neededTotal >= 0.04 && hypotheticalNickles < machineNickles; hypotheticalNickles++) {
		neededTotal -= 0.05;
	}

	return hypotheticalNickles;
}



