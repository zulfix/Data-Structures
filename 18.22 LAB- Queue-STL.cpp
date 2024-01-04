#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Create a queue
    queue<int> myQueue;

    // Push 10 integers onto the queue
    myQueue.push(5);
    myQueue.push(6);
    myQueue.push(7);
    myQueue.push(10);
    myQueue.push(3);
    myQueue.push(2);
    myQueue.push(0);
    myQueue.push(9);
    myQueue.push(15);
    myQueue.push(23);

    // Output the size of the queue
    cout << "Size of myQueue is: " << myQueue.size() << endl;

    // Output the front of the queue
    cout << "Front of myQueue is: " << myQueue.front() << endl;

    // Output the back of the queue
    cout << "Back of myQueue is: " << myQueue.back() << endl;

    // Remove three integers from the queue (FIFO)
    for (int i = 0; i < 3; ++i) {
        myQueue.pop();
    }

    // Print out all elements in the queue
    cout << "";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;

    return 0;
}

/*18.22 LAB Lecture#8 - Queue-STL
Complete the code to perform the following operations on the stack myQueue.



push 10 integers onto the queue: 5,6,7,10,3,2,0,9,15,23


Write a program that outputs the following. (1 pt)
(1) The size of the queue after performing above operations. Your output should be as shown:

Size of myQueue is:  10

(2) The front of the queue after performing above operations. Your output should be as shown:

Front of myQueue is: 5

(3) The back of the queue after performing above operations. Your output should be as shown:

Back of myQueue is: 23
Then, remove the three integers from the queue (FIFO).

(4) Print out all elements in the queue. Your output should be as shown:

10 3 2 0 9 15 23*/
