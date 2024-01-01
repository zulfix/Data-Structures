#include <iostream>
#include <vector>   // Must include vector library to use vectors
using namespace std;

int main() {
   int numInts;
   cin >> numInts;

   vector<int> integers(numInts);
   
   for (int i = 0; i < numInts; ++i) {
    cin >> integers[i];
   }
   
   for (int i = numInts - 1; i >= 0; --i) {
        cout << integers[i];
        if (i > 0) {
            cout << ",";
      }
   }

   cout << endl;
   
    char finish;
    cin >> finish;
    
    if (finish != 'y' && finish != 'Y') {
       cout << endl;
    }


    return 0;
}

/*5.18 LAB: Output numbers in reverse
Write a program that reads a list of integers, and outputs those integers in reverse. The input begins with an integer indicating the number of integers that follow. For coding simplicity, follow each output integer by a comma, including the last one.

Ex: If the input is:

5 2 4 6 8 10
the output is:

10,8,6,4,2,
To achieve the above, first read the integers into a vector. Then output the vector in reverse.*/