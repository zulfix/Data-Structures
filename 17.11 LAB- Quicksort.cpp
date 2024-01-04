#include <iostream>
#include <vector>
using namespace std;

void displayVector(const vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }
    cout << endl;
}

int partition(vector<int> &numbers, int lowIndex, int highIndex) {
    int midpoint, pivot, temp;
    
    midpoint = lowIndex + (highIndex - lowIndex) / 2;
    pivot = numbers[midpoint];
    
    bool done = false;
    while (!done) {
        while (numbers[lowIndex] < pivot) {
            lowIndex++;
        }
        
        while (pivot < numbers[highIndex]) {
            highIndex--;
        }
        
        if (lowIndex >= highIndex) {
            done = true;
        } else {
            // Swap numbers[lowIndex] and numbers[highIndex]
            temp = numbers[lowIndex];
            numbers[lowIndex] = numbers[highIndex];
            numbers[highIndex] = temp;
            
            lowIndex++;
            highIndex--;
        }
    }
    
    return highIndex;
}

void quicksort(vector<int> &numbers, int lowIndex, int highIndex) {
    int lowEndIndex;
    
    if (lowIndex >= highIndex) {
        return;
    }
    
    lowEndIndex = partition(numbers, lowIndex, highIndex);
    
    // Recursively sort low partition (lowIndex to lowEndIndex) 
    // and high partition (lowEndIndex + 1 to highIndex)
    quicksort(numbers, lowIndex, lowEndIndex);
    quicksort(numbers, lowEndIndex + 1, highIndex);
}

int main() {

    vector<int> myVec {3, 2, 1, 4, 7, 0};
    cout << "UNSORTED : " << endl;
    displayVector(myVec);
    quicksort(myVec, 0, (int)myVec.size() - 1);
    cout << "SORTED : " << endl;
    displayVector(myVec);
    cout << endl;

    myVec = {45, 23, 12, 68, 50, 52, 25, 77, 92, 84};
    cout << "UNSORTED : " << endl;
    displayVector(myVec);
    quicksort(myVec, 0, (int)myVec.size() - 1);
    cout << "SORTED : " << endl;
    displayVector(myVec);
    cout << endl;

    myVec = {8, 1, 4, 9, 0, 3, 5, 2, 7, 6};
    cout << "UNSORTED : " << endl;
    displayVector(myVec);
    quicksort(myVec, 0, (int)myVec.size() - 1);
    cout << "SORTED : " << endl;
    displayVector(myVec);
    cout << endl;

    myVec = {3, 2, 5, 9, 4, 7, 8, 13, 10, 17, 11, 1, 13, 34, 100, 32, 27, 29, 55, 68, 43, 31};
    cout << "UNSORTED : " << endl;
    displayVector(myVec);
    quicksort(myVec, 0, (int)myVec.size() - 1);
    cout << "SORTED : " << endl;
    displayVector(myVec);
    cout << endl;

    return 0;
}

/*17.11 LAB Week#13 - Quicksort
Complete the code for void quicksort(vector & numbers, int lowIndex, int highIndex) and int partition(vector & numbers, int lowIndex, int highIndex) functions. Run the program, your code should display the following output.

UNSORTED : 
3 2 1 4 7 0 
SORTED : 
0 1 2 3 4 7 

UNSORTED : 
45 23 12 68 50 52 25 77 92 84 
SORTED : 
12 23 25 45 50 52 68 77 84 92 

UNSORTED : 
8 1 4 9 0 3 5 2 7 6 
SORTED : 
0 1 2 3 4 5 6 7 8 9 

UNSORTED : 
3 2 5 9 4 7 8 13 10 17 11 1 13 34 100 32 27 29 55 68 43 31 
SORTED : 
1 2 3 4 5 7 8 9 10 11 13 13 17 27 29 31 32 34 43 55 68 100*/
