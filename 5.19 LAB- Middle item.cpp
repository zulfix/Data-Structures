#include <iostream>
#include <vector>   // Must include vector library to use vectors
using namespace std;

int main() {

const int maxNums = 9;

vector<int> nums;
int input;

while(true) {
   cin >> input ;
   
   if (input < 0) {
      break;
   }
   
   if (nums.size() >= maxNums) {
      cout << "Too many numbers" << endl;
      return 1;
   }
   nums.push_back(input);
}
int middleIndex = nums.size() / 2;
int middleItem = nums.at(middleIndex);

cout << "Middle item: " << middleItem << endl;

   return 0;
}

/*5.19 LAB: Middle item
Given a sorted list of integers, output the middle integer. A negative number indicates the end of the input (the negative number is not a part of the sorted list). Assume the number of integers is always odd.

Ex: If the input is:

2 3 4 8 11 -1 
the output is:

Middle item: 4
The maximum number of list values for any test case should not exceed 9. If exceeded, output "Too many numbers".

Hint: First read the data into a vector. Then, based on the number of items, find the middle item.*/