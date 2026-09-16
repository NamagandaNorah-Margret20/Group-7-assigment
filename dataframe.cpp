//Implementation of the operations given on a dataframe(group 7)
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

// Addition function (total hours)
vector<int> add(vector<int> regular_hours, vector<int> overtime_hours)
{
    vector<int> result;
    for(int i = 0; i < regular_hours.size(); i++){
        result.push_back(regular_hours[i] + overtime_hours[i]);
    }
    return result;
}


// Multiplication function
double multiply(double totalHours, double hourlyRate){
    return totalHours * hourlyRate;
}


// Function handles calculation only and returns a vector of rates
vector<double> calculateHourlyRates(const vector<double>& totalPay,
                                    const vector<double>& totalHours)
{
    vector<double> rates(totalPay.size(), 0.0);
    for(size_t i = 0; i < totalPay.size(); ++i){
        if(totalHours[i] != 0){
            rates[i] = totalPay[i] / totalHours[i];
        }
    }
    return rates;
}


// Function for subtracting overtime hours from total hours
// to get regular hours
vector<int> subtract(vector<int> total_hours, vector<int> overtime_hours)
{
    vector<int> result;
    for(int i = 0; i < total_hours.size(); i++){
      result.push_back(total_hours[i] - overtime_hours[i]);
    }
    return result;
}


// Function to calculate the percentage of overtime hours
// for each employee
vector<double> Overtimepercentage(vector<int> regular_hours,
                                  vector<int> overtime_hours){
    vector<double> WorkerOvertimePercentage;

    vector<int> sumHours = add(regular_hours, overtime_hours);

    for(int i = 0; i < overtime_hours.size(); i++){
        WorkerOvertimePercentage.push_back(
            double(overtime_hours[i]) / sumHours[i] * 100
        );
    }
    return WorkerOvertimePercentage;}



int main()
{
    // Employee data
    vector<string> employees = {"A", "B", "C", "D", "E"};

    vector<int> regular_hours = {40, 35, 40, 38, 36};

    vector<int> overtime_hours = {5, 3, 8, 2, 4};

    vector<double> hourlyRate = {5000, 6000, 5000, 5500, 4500};

    // Calculate total hours using addition function
    vector<int> total_hours = add(regular_hours, overtime_hours);

    // Vectors for total pay and total hours
    vector<double> totalPay(regular_hours.size());
    vector<double> totalHours(regular_hours.size());


    // Displaying total hours for each employee
    cout <<endl<< "Total hours worked:" << endl;

    for(int i = 0; i < total_hours.size(); i++)
    {
        cout << "Employee " << employees[i] << " - "
             << total_hours[i] << " hours" << endl;
    }


    // Calculates and prints total pay for each employee
    cout<<endl<<"Total Pay"<<endl;
    for(int i = 0; i < regular_hours.size(); i++)
    {
        totalHours[i] = total_hours[i];

        totalPay[i] = multiply(totalHours[i], hourlyRate[i]);

       cout << "Employee " << employees[i] << " - " ;
        cout  << totalPay[i] << " UGX" << endl;
    }


    // Calculate rates using the function
    vector<double> calculatedRates =
        calculateHourlyRates(totalPay, totalHours);


    // Calculate overtime percentage using the function
    vector<double> Overtime_percentage =
        Overtimepercentage(regular_hours, overtime_hours);


    // Prints the hourly rates for each employee
cout <<endl<< "Hourly Rate:" << endl;
    

    for(size_t i = 0; i < employees.size(); ++i)
    {
        if(totalHours[i] != 0)
        {
            cout << "Employee " << employees[i] << " - "
                 << fixed << setprecision(2)
                 << calculatedRates[i]
                 << " UGX/hour" << endl;
        }
    }


    // Prints regular hours for each employee
    regular_hours = subtract(total_hours, overtime_hours);

   cout <<endl<< "Recalculated regular hours:" << endl;

    for(int i = 0; i < regular_hours.size(); i++)
    {
        std::cout << "Employee " << employees[i] << " - "
             << regular_hours[i] << " hours" << endl;
    }


    // Displaying the overtime hour percentage
    cout <<endl<< "Overtime hour percentage:" << endl;

    for(int i = 0; i < Overtime_percentage.size(); i++)
    {
        cout << "Employee " << employees[i] << " - "
             << fixed << setprecision(2)
             << Overtime_percentage[i] << "%" << endl;
    }


    return 0;
}