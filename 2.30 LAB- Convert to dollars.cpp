/*2.30 LAB: Convert to dollars

Given three input values representing counts of nickels, dimes, and quarters, output the total amount as dollars and cents.

Output each floating-point value with two digits after the decimal point using the following statement once before all other cout statements:
cout << fixed << setprecision(2);

Ex: If the input is:

3 1 4
where 3 is the number of nickels (at $0.05 each), 1 is the number of dimes (at $0.10 each), and 4 is the number of quarters (at $0.25 each), the output is:

Amount: $1.25
For simplicity, assume input is non-negative.*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   double dollars;
   int quarters;
   int dimes;
   int nickels;
   
   cin >> nickels;
   cin >> dimes;
   cin >> quarters;
   
   dollars = (quarters * 25 + dimes * 10 + nickels * 5) / 100.0;
   cout << fixed << setprecision(2);
   cout << "Amount: $" << dollars << endl;
   
   return 0;
}