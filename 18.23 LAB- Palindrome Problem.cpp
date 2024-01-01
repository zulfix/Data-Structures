#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

void displayNameOne(string & expr){
    //push the string onto stack
    stack<char> tempStack;
    for (int i = 0; i < expr.length(); i++){
      tempStack.push(expr.at(i));
    }

    //print from stack one by one
    while(!tempStack.empty()){
      cout << tempStack.top();
      tempStack.pop();
    }
}

void displayNameTwo(string & expr){
    //push the string onto queue
    queue<char> tempQueue;
    for (int i = 0; i < expr.length(); i++){
        tempQueue.push(expr.at(i));
    }

    while(!tempQueue.empty()){
      cout << tempQueue.front();
        tempQueue.pop();
    }

}

bool isPalindrome(string & expr){
    queue<char> tempQueue;
    stack<char> tempStack;
    for (int i = 0; i < expr.length(); i++){
      if (expr.at(i) != ' '){
        tempQueue.push(tolower(expr.at(i)));
        tempStack.push(tolower(expr.at(i)));
      }
    }
    while(!tempQueue.empty()){
      if (tempQueue.front() != tempStack.top()) {
        return false;
      }
      tempQueue.pop();
      tempStack.pop();
    }
  
    return true;
}

int main(int argc, const char * argv[]) {
    string exp = "racecar"; //"Racecar";//
    cout << "*** Stack ***" << endl;
    displayNameOne(exp);
    cout << endl;
    cout << "*** Queue ***" << endl;
    displayNameTwo(exp);
    cout << endl;
    cout << "Your expression: " << exp << " is : " << (isPalindrome(exp)? "a palindrome!": "is not a palindrome!")  << endl << endl;
}

/*18.23 LAB Lecture#8 - Palindrome Problem
Add the following on the top of the file to include the stack and queue standard template libraries.
     #include <stack>
     #include <queue>


Complete void displayNameOne(string & expr) a. push each of the characters of expr onto tempStack b. print the character from the stack starting from the top of the stack to the bottom c. observe the output
Complete void displayNameTwo(string & expr) – do the same for this function as the displayNameOne but change stack to queue.
Complete bool isPalindrome(string & expr) function! Makes use of the stack and a queue data structure to check for a palindrome.*/