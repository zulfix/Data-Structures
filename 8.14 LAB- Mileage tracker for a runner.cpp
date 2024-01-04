#ifndef MILEAGETRACKERNODEH
#define MILEAGETRACKERNODEH

#include <string>
using namespace std;

class MileageTrackerNode {
   public:
      // Constructor
      MileageTrackerNode();

      // Destructor
      ~MileageTrackerNode();

      // Constructor
      MileageTrackerNode(double milesInit, string dateInit);

      // Constructor
      MileageTrackerNode(double milesInit, string dateInit, MileageTrackerNode* nextLoc);

      /* Insert node after this node.
      Before: this -- next
      After:  this -- node -- next
      */
      void InsertAfter(MileageTrackerNode* nodeLoc);

      // Get location pointed by nextNodeRef
      MileageTrackerNode* GetNext();

      void PrintNodeData();
   
   private:
      double miles;         // Node data
      string date;          // Node data
      MileageTrackerNode* nextNodeRef; // Reference to the next node
};

#endif

#include "MileageTrackerNode.h"
#include <iostream>

// Constructor
MileageTrackerNode::MileageTrackerNode() {
   miles = 0.0;
   date = "";
   nextNodeRef = nullptr;
}

// Destructor
MileageTrackerNode::~MileageTrackerNode() {
   if(nextNodeRef != nullptr) {
      delete nextNodeRef;
   }
}

// Constructor
MileageTrackerNode::MileageTrackerNode(double milesInit, string dateInit) {
   miles = milesInit;
   date = dateInit;
   nextNodeRef = nullptr;
}

// Constructor
MileageTrackerNode::MileageTrackerNode(double milesInit, string dateInit, MileageTrackerNode* nextLoc) {
   miles = milesInit;
   date = dateInit;
   nextNodeRef = nextLoc;
}

/* Insert node after this node.
Before: this -- next
After:  this -- node -- next
*/
void MileageTrackerNode::InsertAfter(MileageTrackerNode* nodeLoc) {
   MileageTrackerNode* tmpNext;

   tmpNext = nextNodeRef;
   nextNodeRef = nodeLoc;
   nodeLoc->nextNodeRef = tmpNext;
}

// Get location pointed by nextNodeRef
MileageTrackerNode* MileageTrackerNode::GetNext() {
   return nextNodeRef;
}

void MileageTrackerNode::PrintNodeData(){
   cout << miles << ", " << date << endl;
}

#include "MileageTrackerNode.h"
#include <string>
#include <iostream>
using namespace std;

int main () {
   // References for MileageTrackerNode objects
   int numNodes;
   cin >> numNodes;
   MileageTrackerNode* headNode;
   MileageTrackerNode* currNode;
   MileageTrackerNode* lastNode;

   double miles;
   string date;

   // Front of nodes list
   headNode = new MileageTrackerNode();
   lastNode = headNode;
   
   for (int i = 0; i < numNodes; ++i) {
      cin >> miles;
      cin.ignore();
      getline(cin, date);
      
      currNode = new MileageTrackerNode(miles, date);
      lastNode->InsertAfter(currNode);
      lastNode = currNode;
   }

  currNode = headNode->GetNext();
  while (currNode != nullptr) {
     currNode->PrintNodeData();
     currNode = currNode->GetNext();
  }

   // MileageTrackerNode Destructor deletes all
   //       following nodes
   delete headNode;
}

/*8.14 LAB: Mileage tracker for a runner
Given the MileageTrackerNode class, complete main() to insert nodes into a linked list (using the InsertAfter() function). The first user-input value is the number of nodes in the linked list. Use the PrintNodeData() function to print the entire linked list. DO NOT print the dummy head node.

Ex. If the input is:

3
2.2
7/2/18
3.2
7/7/18
4.5
7/16/18
the output is:

2.2, 7/2/18
3.2, 7/7/18
4.5, 7/16/18*/
