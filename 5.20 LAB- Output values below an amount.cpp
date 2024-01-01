#include <iostream>
#include <vector>
using namespace std;

int main() {
 int numIntegers;
 cin >> numIntegers;

    int integers[100];
    for (int i = 0; i < numIntegers; ++i) {
      cin >> integers[i];
    }

    int threshold;
    cin >> threshold;

    for (int i = 0; i < numIntegers; ++i) {
        if (integers[i] <= threshold) {
            cout << integers[i];
            if (i < numIntegers - 1) {
               cout << ",";
            }
        }
    }

    cout << endl;

    return 0;
}

/*5.20 LAB: Output values below an amount
Write a program that first gets a list of integers from input. The input begins with an integer indicating the number of integers that follow. Then, get the last value from the input, which indicates a threshold. Output all integers less than or equal to that last threshold value.

Ex: If the input is:

5 50 60 140 200 75 100
the output is:

50,60,75,
The 5 indicates that there are five integers in the list, namely 50, 60, 140, 200, and 75. The 100 indicates that the program should output all integers less than or equal to 100, so the program outputs 50, 60, and 75.

For coding simplicity, follow every output value by a comma, including the last one.

Such functionality is common on sites like Amazon, where a user can filter results.*/