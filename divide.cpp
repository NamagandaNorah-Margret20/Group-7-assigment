#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <iomanip>

int main() {
    vector<string> employees = {"A", "B", "C", "D", "E"};
    vector<double> totalPay = {225000, 228000, 240000, 220000, 180000};
    vector<double> totalHours = {45, 38, 48, 40, 40};
    vector<double> hourlyRate(employees.size());

    
    cout << "Hourly Rate\n";
    cout << "-------------------------------------------------------------------------\n";
    

    // Perform division: Total pay / Total hours
    for (int i = 0; i < employees.size(); ++i) {
        if (totalHours[i] != 0) {
        hourlyRate[i] = totalPay[i] / totalHours[i];
        cout  <<"Employee" <<" "<<employees[i] <<" "<<"-"<<" "
        << hourlyRate[i] << " UGX/hour\n";
        }
    }

    return 0;
}