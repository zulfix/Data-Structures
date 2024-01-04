#include <iostream>
using namespace std;

int main() {

char inputChar;

while (true) {
   cout << "Enter a character: ";
   cin >> inputChar;
   
   if (inputChar == 'Z') {
      cout << "Bye!" << endl;
      break;
   } else {
   cout << inputChar << endl;
   }

}
   return 0;
}

/*4.15 LAB: Display a character
Create a while loop to display a character that is entered by a user each time until he/she types in a Z, then print out Bye!.

Enter a character: a
a
Enter a character: b
b
Enter a character: A
A
Enter a character: z
z
Enter a character: Z
Bye!*/
