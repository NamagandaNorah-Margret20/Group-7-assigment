#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

vector<int> add(vector<int> regular_hours, vector<int> overtime_hours);
vector<double> Overtimepercentage(vector<int> regular_hours, vector<int> overtime_hours);

int main()
{
    vector<string> employees = {"A", "B", "C", "D", "E"};
    vector<int> regular_hours = {40, 35, 40, 38, 36};
    vector<int> overtime_hours = {5, 3, 8, 2, 4};
    vector<int> hourly_rate = {5000, 6000, 5000, 5500, 4500};

    vector<int> total_hours = add(regular_hours, overtime_hours);
    vector<double> Overtime_percentage = Overtimepercentage(regular_hours, overtime_hours);
    cout << "Overtime hour percentage:" << endl;
    for (int i = 0; i < Overtime_percentage.size(); i++)
    {
        cout << "Employee" << " " << employees[i] << " " << "-" << " ";
        cout << fixed << setprecision(2) << Overtime_percentage[i] << "%" << endl;
    }
    return 0;
}
vector<int> add(vector<int> regular_hours, vector<int> overtime_hours)
{
    vector<int> result;
    for (int i = 0; i < regular_hours.size(); i++)
    {
        result.push_back(regular_hours[i] + overtime_hours[i]);
    }
    return result;
}

vector<double> Overtimepercentage(vector<int> regular_hours, vector<int> overtime_hours)
{
    vector<double> WorkerOvertimePercentage;
    vector<int> sumHours = add(regular_hours, overtime_hours);
    for (int i = 0; i < overtime_hours.size(); i++)
    {
        WorkerOvertimePercentage.push_back(double(regular_hours[i]) / sumHours[i] * 100);
    }
    return WorkerOvertimePercentage;
}