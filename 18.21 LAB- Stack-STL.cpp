#include <iostream>
#include <stack>
using namespace std;

int main() {

stack<int> myStack;

myStack.push(4);
myStack.push(5);
myStack.push(8);
myStack.pop();
myStack.push(9);
myStack.push(8);
myStack.push(7);
myStack.pop();
myStack.pop();

cout << "Size of my stack is: " << myStack.size() << endl;

if (!myStack.empty()) {
   cout << "Top of my stack is: " << myStack.top() << endl;
} else {
   cout << "Stack is empty." << endl;
}

   //Push 4, push 5, push 8, pop, push 9, push 8, push 7, pop, pop
    
    return 0;
}

/*18.21 LAB Lecture#8 - Stack-STL
Complete the code to perform the following operations on the stack myStack.



push 4, push 5, push 8, pop, push 9, push 8, push 7, pop, pop


Write a program that outputs the following. (1 pt)
(1) The size of the stack after performing above operations. Your output should be as shown:

Size of my stack is: 3

(2) The top of the stack after performing above operations. Your output should be as shown:

Top of my stack is: 9*/
