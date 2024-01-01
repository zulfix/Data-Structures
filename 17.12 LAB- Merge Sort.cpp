#include <iostream>
#include <vector>
using namespace std;

void displayVector(const vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }
    cout << endl;
}

void merge(vector<int> &numbers, int i, int j, int k) {
    int leftPos, rightPos; // position of elements in left and right partition
    int mergePos = 0;      // position to insert merged number
    int mergedSize = k - i + 1; // size of merged partition
    vector<int> mergedNumbers(mergedSize); // temporary vector for merged numbers
    leftPos = i; // initialize left partition position
    rightPos = j + 1; // initialize right partition position

    // Add smallest element from left or right partition to merged numbers
    while (leftPos <= j && rightPos <= k) {
        if (numbers[leftPos] < numbers[rightPos]) {
            mergedNumbers[mergePos] = numbers[leftPos];
            ++leftPos;
        } else {
            mergedNumbers[mergePos] = numbers[rightPos];
            ++rightPos;
        }
        ++mergePos;
    }

    // If left partition is not empty, add remaining elements to merged numbers
    while (leftPos <= j) {
        mergedNumbers[mergePos] = numbers[leftPos];
        ++leftPos;
        ++mergePos;
    }

    // If right partition is not empty, add remaining elements to merged numbers
    while (rightPos <= k) {
        mergedNumbers[mergePos] = numbers[rightPos];
        ++rightPos;
        ++mergePos;
    }

    // Copy merged numbers back to the original vector
    for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
        numbers[i + mergePos] = mergedNumbers[mergePos];
    }
}

void mergesort(vector<int> &numbers, int i, int k) {
    int j = 0;
    if (i < k) {
        // Find the midpoint in the partition
        j = (i + k) / 2;

        // Recursively sort left and right partitions
        mergesort(numbers, i, j);
        mergesort(numbers, j + 1, k);

        // Merge left and right partition in sorted order
        merge(numbers, i, j, k);
    }
}

int main() {
    vector<int> myVec {3, 2, 1, 4, 7, 0};
    cout << "UNSORTED : " << endl;
    displayVector(myVec);
    mergesort(myVec, 0, (int)myVec.size() - 1);
    cout << "SORTED : " << endl;
    displayVector(myVec);
    cout << endl;

    myVec = {45, 23, 12, 68, 50, 52, 25, 77, 92, 84};
    cout << "UNSORTED : " << endl;
    displayVector(myVec);
    mergesort(myVec, 0, (int)myVec.size() - 1);
    cout << "SORTED : " << endl;
    displayVector(myVec);
    cout << endl;

    myVec = {8, 1, 4, 9, 0, 3, 5, 2, 7, 6};
    cout << "UNSORTED : " << endl;
    displayVector(myVec);
    mergesort(myVec, 0, (int)myVec.size() - 1);
    cout << "SORTED : " << endl;
    displayVector(myVec);
    cout << endl;

    myVec = {3, 2, 5, 9, 4, 7, 8, 13, 10, 17, 11, 1, 13, 34, 100, 32, 27, 29, 55, 68, 43, 31};
    cout << "UNSORTED : " << endl;
    displayVector(myVec);
    mergesort(myVec, 0, (int)myVec.size() - 1);
    cout << "SORTED : " << endl;
    displayVector(myVec);
    cout << endl;

    return 0;
}

/*17.12 LAB Week#13 - Merge Sort
Complete the code for void mergesort(vector & numbers, int i, int k) and void merge(vector & numbers, int i, int j, int k) functions. Run the program, your code should display the following output.

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