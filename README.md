#Group 7 DataFrame Assignment

Reimplementation of Column Arithmetic Operations on a Sample DataFrame in C++

Group Members

| NAME | REG NO. |
| --- | --- |
| NAMBALIRWA FLAVIA CATE | 25/U/0848 |
| NAMAGANDA NORAH MARGRET  | 25/U/0846 |
| SENGENDO CRYSTAL  ZAWEDDE | 25/U/08615/PS |
| MUGABE DESTINY | 25/U/08748/PS |
| KIZITO MARK JAMES | 25/U/30991/PS |
| KABAHAMBA JOY A MARIA  | 25/U/0830 |
| NATUKUNDA MELISSA  | 25/U/0854 |


1. Introduction

This project reimplements five column arithmetic operations , that is, `add()`, `subtract()`, `multiply()`, `divide()` and `percentage()` , on a payroll data set of five employees. A payroll dataset was chosen because the operations join eachother naturally, in that the output of one becomes the input of the next, and so on.

---

2. The DataFrame

| Employee | Regular Hours | Overtime Hours | Hourly Rate (UGX) |
| --- | --- | --- | --- |
| A | 40 | 5 | 5,000 |
| B | 35 | 3 | 6,000 |
| C | 40 | 8 | 5,000 |
| D | 38 | 2 | 5,500 |
| E | 36 | 4 | 4,500 |

Each piece of employee information is stored as a separate `vector`, but the same index refers to the same employee.

```cpp
vector<string> employees      = {"A", "B", "C", "D", "E"};
vector<int>    regular_hours  = {40, 35, 40, 38, 36};
vector<int>    overtime_hours = {5, 3, 8, 2, 4};
vector<double> hourlyRate     = {5000, 6000, 5000, 5500, 4500};
```

The `employees` vector is a label column and takes no part in arithmetic operations.

---

3. Application of Each Operation

| Operation | Function in code | Calculation | Example (Employee A) |
| --- | --- | --- | --- |
| `add()` | `add()` | Regular + overtime = total hours | 40 + 5 = 45 hours |
| `subtract()` | `subtract()` | Total − overtime = regular hours | 45 − 5 = 40 hours |
| `multiply()` | `multiply()` | Total hours × rate = total pay | 45 × 5,000 = 225,000 UGX |
| `divide()` | `calculateHourlyRates()` | Total pay ÷ total hours = rate | 225,000 ÷ 45 = 5,000 UGX/hour |
| `percentage()` | `Overtimepercentage()` | (Overtime ÷ total) × 100 | (5 ÷ 45) × 100 = 11.11% |

`subtract()` and `calculateHourlyRates()` help us to verify that the original regular-hours and hourly-rate columns match the input data exactly.

4. Object-Oriented Programming Concepts Used

The program was mostly written using functions and the following object-oriented concepts were applied.

4.1 Classes

A class is a blueprint that defines the data and operations that objects can have. In our program, we use the C++ Standard Library's `vector` class to store employee data. We used the `vector` class to create vectors of different data types.

cpp
ector<int> regular_hours = {40, 35, 40, 38, 36};
vector<double> hourlyRate = {5000, 6000, 5000, 5500, 4500};

Here, `vector<int>` and `vector<double>` represent the data types used to create our data structures.

4.2 Objects

An object is an instance of a class. In our program, variables such as `regular_hours`, `overtime_hours`, and `hourlyRate` were objects created from the `vector` class. Each object contains its own data and can use operations provided by the `vector` class.

cpp
vector<int> overtime_hours = {5, 3, 8, 2, 4};

overtime_hours.push_back(6);


Here, `overtime_hours` is an object of the `vector<int>` class. The `push_back()` function is an operation provided by the vector class that allows us to add an element.

4.3 Encapsulation

Encapsulation means keeping the internal implementation of an object hidden and allowing the user to interact with it through defined operations. In our program, we do not need to know how the `vector` stores its elements internally. We simply use functions such as `size()` and `push_back()` to interact with it.

cpp
cout << regular_hours.size();
regular_hours.push_back(45);

The internal workings of the vector are handled by the `vector` class. This demonstrates encapsulation because we interact with the object through its provided functions rather than directly accessing or modifying its internal implementation.

std::vector` and `std::string` are classes provided by the Standard Library. Every column in the program is an object from one of these classes. The program is therefore built out of objects that carry both their data and the operations that act on it.


5. Algorithm and Main Steps

5.1 Overall Program Flow

1. Declare and initialise the four columns: employees, regular hours, overtime hours, hourly rate.
2. Call `add()` to compute the total-hours column and display it.
3. For each row, call `multiply()` on total hours and hourly rate to make the total-pay column, and display it.
4. Call `calculateHourlyRates()` on total pay and total hours to get the hourly rate.
5. Call `Overtimepercentage()` on regular and overtime hours to get the overtime share.
6. Call `subtract()` on total hours and overtime hours to get regular hours.
7. Display the recovered rates, the recovered regular hours and the overtime percentages.

5.2 `add(regular_hours, overtime_hours)`

Create an empty result vector. For each index `i` from 0 to `regular_hours.size() - 1`, append `regular_hours[i] + overtime_hours[i]`. Return the result.

5.3 `subtract(total_hours, overtime_hours)`

Identical in structure to `add()`, appending `total_hours[i] - overtime_hours[i]`. Returns the regular-hours column.

5.4 `multiply(totalHours, hourlyRate)`

Operates on a single pair of scalars and returns their product. The loop over rows sits in `main()`, which calls the function once per employee to make the total-pay column.

5.5 `calculateHourlyRates(totalPay, totalHours)`  (the divide operation)

Construct a result vector of the same length, initially filled with `0.0`. For each index, test whether `totalHours[i]` is non-zero; if so, store `totalPay[i] / totalHours[i]`, otherwise leave the entry at `0.0`. Return the result. The zero test is what prevents a division-by-zero from entering the output.

5.6 `Overtimepercentage(regular_hours, overtime_hours)`

Call `add()`  to obtain total hours. For each index, cast `overtime_hours[i]` to `double`, divide by the total, multiply by 100, and append. The cast is essential: without it, `5 / 45` in integer arithmetic evaluates to 0.

5.7 Output Formatting

Percentages and hourly rates are printed with `fixed` and `setprecision(2)`. Hours are printed as integers. Totals are labelled with the employee identifier from the `employees` vector.


6. Possible Error Points

6.1 Unguarded Division in `Overtimepercentage()`

`Overtimepercentage()` does not check whether `sumHours[i]` is zero before dividing. If an employee has zero regular and overtime hours, the program would divide by zero and produce an undefined result. A zero check should be added, similar to the one in `calculateHourlyRates()`.

6.2 No Verification of Vector Sizes

The functions assume that the vectors have the same number of elements. If the vectors have different sizes, the program may try to access an element that does not exist, which can lead to `out_of_range` errors. The vector sizes should therefore be checked before performing the calculations.

6.3 Integer Hour Columns

`regular_hours` and `overtime_hours` are stored as `vector<int>`. This means the program cannot represent fractional hours such as `37.5`. Using `vector<double>` would allow the program to handle fractional working hours.

6.4 Signed and Unsigned Comparison

Most of the loops use an `int` counter while `vector.size()` returns a `size_t`. This can produce compiler warnings. Using `size_t` consistently, as done in `calculateHourlyRates()`, would avoid this issue.

6.5 Unnecessary Copying of Vectors

The `add()` and `subtract()` functions receive vectors by value, meaning copies of the vectors are created every time the functions are called. This is not a problem for our small dataset, but it becomes inefficient with larger datasets. Using `const vector<int>&` would avoid unnecessary copying.

6.6 Naming Inconsistency

The function `Overtimepercentage()` uses a different naming style from the other functions, while the variables also mix styles such as `regular_hours` and `hourlyRate`. This does not affect the program's output, but using one naming style throughout would make the code easier to read and maintain.

7. Conclusion

Overall, the program successfully implements the five required column operations on the payroll data using vectors and functions. It also shows some object-oriented concepts through the use of the `vector` class, objects and encapsulation.

The verification steps help confirm that the calculations are correct. For example, `subtract()` is used to get back the regular hours from the total hours, while `calculateHourlyRates()` checks the hourly rate from the total pay and total hours.

However, there are some areas that could be improved. The main ones are adding a zero check in `Overtimepercentage()`, checking that the vectors have the same size, and keeping the original `regular_hours` column instead of overwriting it during verification.

8. References

Stroustrup, B. (2014). *Programming: Principles and Practice Using C++ (2nd ed.). Addison-Wesley.
