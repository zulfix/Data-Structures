#include <iostream>
using namespace std;

int main() {
   
   int number;

do {
   cout << "Please enter a number (1-99): " << endl;
   cin >> number;
   
} while ( number < 1 || number > 99);

for (int i = number; i <= 100; i +=5) {
   cout << i;

if (i < 100) {
   cout << " ";
   }
}
   return 0;
}

/*4.14 LAB: Increment by 5
Prompt a number from a user and with the use of a for loop, increment the number by 5 each time until the value reaches 100. Separate each number with a space as shown below:

Please enter a number (1-99): 5

5 10 15 20 25 30 35 40 45 50 55 60 65 70 75 80 85 90 95 100*/