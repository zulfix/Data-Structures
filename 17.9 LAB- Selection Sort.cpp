#include <iostream>
#include <vector>
using namespace std;

void displayVector(const vector<int> &vec){
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void selectionSort(vector<int> &vec){
    int i, j, smallestIndex, temp;
    for (i = 0; i < vec.size() - 1; ++i) {
        smallestIndex = i;
        for (j = i + 1; j < vec.size(); ++j) {
            if (vec[j] < vec[smallestIndex]) {
                smallestIndex = j;
            }
        }
        temp = vec[i];
        vec[i] = vec[smallestIndex];
        vec[smallestIndex] = temp;
    }
}

int main(int argc, const char * argv[]) {
    vector<int> myVec {2, 1, 9, 5, 3, 10, 4};
    
    selectionSort(myVec);
    cout << "My sorted vector is : "<< endl;
    displayVector(myVec);
    
    myVec = {90, 80, 70, 60, 50, 40, 30, 20, 10, 0};
    selectionSort(myVec);
    cout << "My sorted vector is : "<< endl;
    displayVector(myVec);
    
    return 0;
}

/*17.9 LAB Week#12 - Selection Sort
Complete the code for void selectionSort(vector & vec), as instructed in the class. Run the program, your code should display the following output.

My sorted vector is :
 1 2 3 4 5 9 10
My sorted vector is :
0 10 20 30 40 50 60 70 80 90*/
