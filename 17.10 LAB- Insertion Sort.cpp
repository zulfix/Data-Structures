#include <iostream>
#include <vector>
using namespace std;

void displayVector(const vector<int> &vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

void insertionSort(vector<int> &vec) {
    int n = vec.size();
    for (int i = 1; i < n; ++i) {
        int key = vec[i];
        int j = i - 1;

        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }

        vec[j + 1] = key;
    }
}

int main() {
    vector<int> myVec {2, 1, 9, 5, 3, 10, 4};
    
    insertionSort(myVec);
    cout << "My sorted vector is : ";
    displayVector(myVec);
    
    myVec = {90, 80, 70, 60, 50, 40, 30, 20, 10, 0};
    insertionSort(myVec);
    cout << "My sorted vector is : ";
    displayVector(myVec);
    
    return 0;
}

/*17.10 LAB Week#12 - Insertion Sort
Complete the code for void insertionSort(vector & vec), as instructed in the class. Run the program, your code should display the following output.

My sorted vector is :
 1 2 3 4 5 9 10
My sorted vector is :
0 10 20 30 40 50 60 70 80 90*/
