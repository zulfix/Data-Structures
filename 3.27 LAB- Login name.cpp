#include <iostream>
#include <string>
using namespace std;

int main() {
	string firstName;
	string lastName;
	int number;
	
   cin >> firstName;
   cin >> lastName;
   cin >> number;
   
   string loginName = lastName.substr(0, min(5, static_cast<int>(lastName.length())));
   loginName += firstName[0];

   loginName += to_string(number % 100);

   cout << "Your login name: " << loginName << endl;
   
   return 0;
   
}

/*3.27 LAB: Login name
Write a program that creates a login name for a user, given the user's first name, last name, and a four-digit integer as input. Output the login name, which is made up of the first five letters of the last name, followed by the first letter of the first name, and then the last two digits of the number (use the % operator). If the last name has less than five letters, then use all letters of the last name.

Hint: Use the to_string() function to convert numerical data to a string.

Ex: If the input is:

Michael Jordan 1991
the output is:

Your login name: JordaM91
Ex: If the input is:

Kanye West 2024
the output is:

Your login name: WestK24*/