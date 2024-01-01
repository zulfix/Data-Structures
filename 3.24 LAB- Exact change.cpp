#include <iostream>
using namespace std;

int main() {

   int total_change;
   int dollar_value = 100;
   int quarter_value = 25;
   int dime_value = 10;
   int nickel_value = 5;
   int penny_value = 1;

   cin >> total_change;
   
   int dollar_count = total_change / dollar_value;
   total_change %= dollar_value;
   int quarter_count = total_change / quarter_value;
   total_change %= quarter_value;
   int dime_count = total_change / dime_value;
   total_change %= dime_value;
   int nickel_count = total_change / nickel_value;
   total_change %= nickel_value;
   int penny_count = total_change;
   total_change %= penny_value;
   
   if (dollar_count > 0) {
        cout << dollar_count << " " << (dollar_count == 1 ? "Dollar" : "Dollars") << endl;
    }
    if (quarter_count > 0) {
        cout << quarter_count << " " << (quarter_count == 1 ? "Quarter" : "Quarters") << endl;
    }
   if (dime_count > 0) {
        cout << dime_count << " " << (dime_count == 1 ? "Dime" : "Dimes") << endl;
    }
    if (nickel_count > 0) {
        cout << nickel_count << " " << (nickel_count == 1 ? "Nickel" : "Nickels") << endl;
    }
   if (penny_count > 0) {
        cout << penny_count << " " << (penny_count == 1 ? "Penny" : "Pennies") << endl;
    }

   return 0;
}

/*3.24 LAB: Exact change
Write a program with total change amount as an integer input, and output the change using the fewest coins, one coin type per line. The coin types are Dollars, Quarters, Dimes, Nickels, and Pennies. Use singular and plural coin names as appropriate, like 1 Penny vs. 2 Pennies.

Ex: If the input is:

0 
(or less than 0), the output is:

No change 
Ex: If the input is:

45
the output is:

1 Quarter
2 Dimes */