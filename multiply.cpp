#include <iostream>
#include <vector>
using namespace std;

// Multiplication function
double multiply(double totalHours, double hourlyRate)
{
    return totalHours * hourlyRate;
}

int main()
{
    // Employee data
    vector<double> regularHours = {40, 35, 40, 38, 36};
    vector<double> overtimeHours = {5, 3, 8, 2, 4};
    vector<double> hourlyRate = {5000, 6000, 5000, 5500, 4500};

    // Calculate total pay for each employee
    for (int i = 0; i < regularHours.size(); i++)
    {
        double totalHours = regularHours[i] + overtimeHours[i];

        double totalPay = multiply(totalHours, hourlyRate[i]);

        cout << "Employee " << char('A' + i) << endl;
        cout << "Total Hours: " << totalHours << endl;
        cout << "Hourly Rate: " << hourlyRate[i] << " UGX" << endl;
        cout << "Total Pay: " << totalPay << " UGX" << endl;
        cout << "------------------------" << endl;
    }

    return 0;
}