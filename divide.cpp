#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Function handles calculation only and returns a vector of rates
vector<double> calculateHourlyRates(const vector<double>& totalPay, 
                                   const vector<double>& totalHours) {
    vector<double> rates(totalPay.size(), 0.0);

    for (size_t i = 0; i < totalPay.size(); ++i) {
        if (totalHours[i] != 0) {
            rates[i] = totalPay[i] / totalHours[i];
        }
    }

    return rates;
}

int main() {
    vector<string> employees = {"A", "B", "C", "D", "E"};
    vector<double> totalPay = {225000, 228000, 240000, 220000, 180000};
    vector<double> totalHours = {45, 38, 48, 40, 40};

    // Calculate rates using the function
    vector<double> hourlyRate = calculateHourlyRates(totalPay, totalHours);

    // Print output inside main
    cout << "Hourly Rate\n";
    cout << "-------------------------------------------------------------------------\n";
 
    for (size_t i = 0; i < employees.size(); ++i) {
        if (totalHours[i] != 0) {
            cout << "Employee " << employees[i] << " - " 
                 << fixed << setprecision(2) << hourlyRate[i] << " UGX/hour\n";
        }
    }

    return 0;
}