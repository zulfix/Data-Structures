#ifndef BOOKH
#define BOOKH

#include <string>
using namespace std;

class Book{
   public:
      Book();

      Book(string userBookTitle, string userBookAuthor, long userBookISBN);

      long long GetBookISBN() const;

      void PrintInfo() const;
   
   private:
      string bookTitle;
      string bookAuthor;
      long long bookISBN;
};

#endif

#include "Book.h"
#include <iostream>

Book::Book() {
   bookTitle = "";
   bookAuthor = "";
   bookISBN = 0;
}

Book::Book(string userBookTitle, string userBookAuthor, long userBookISBN) {
   bookTitle = userBookTitle;
   bookAuthor = userBookAuthor;
   bookISBN = userBookISBN;
}

long long Book::GetBookISBN() const{
   return bookISBN;
}

void Book::PrintInfo() const{
   cout << "Title: " << bookTitle << endl;
   cout << "Author: " << bookAuthor << endl;
   cout << "ISBN: " << bookISBN << endl;
}

#ifndef BOOKNODEH
#define BOOKNODEH

#include <string>
using namespace std;

class BookNode {
   public:
      BookNode();

      // Constructor
      BookNode(string bookTitleInit, string bookAuthorInit, long bookISBNInit);

      // Constructor
      BookNode(string bookTitleInit, string bookAuthorInit, long bookISBNInit, BookNode* nextLoc);

      // inserAfter
      void insertAfter(BookNode* nodeLoc);
      
      //setNext
      void SetNext(BookNode* nodeLoc);

      // Get location pointed by nextNodePtr
      BookNode* GetNext() const;

      long long GetBookISBN() const;

      // Print book information
      void PrintBookInfo() const;
   
   private:
      string bookTitle;
      string bookAuthor;
      long long bookISBN;
      BookNode* nextNodePtr; // Reference to the next node
};
#endif

#include "BookNode.h"
#include <iostream>

BookNode::BookNode() {
   bookTitle = "";
   bookAuthor = "";
   bookISBN = 0;
   nextNodePtr = nullptr;
}

// Constructor
BookNode::BookNode(string bookTitleInit, string bookAuthorInit, long bookISBNInit) {
   bookTitle = bookTitleInit;
   bookAuthor = bookAuthorInit;
   bookISBN = bookISBNInit;
   nextNodePtr = nullptr;
}

// Constructor
BookNode::BookNode(string bookTitleInit, string bookAuthorInit, long bookISBNInit, BookNode* nextLoc) {
   bookTitle = bookTitleInit;
   bookAuthor = bookAuthorInit;
   bookISBN = bookISBNInit;
   nextNodePtr = nextLoc;
}
// insertAfter
void BookNode::insertAfter(BookNode* nodeLoc){
   BookNode* tmpNext;

   tmpNext = nextNodePtr;
   nextNodePtr = nodeLoc;
   nodeLoc->nextNodePtr = tmpNext;
}

// setNext
void BookNode::SetNext(BookNode* nodeLoc) {
   nextNodePtr = nodeLoc;
}

// Get location pointed by nextNodePtr
BookNode* BookNode::GetNext() const{
   return nextNodePtr;
}

long long BookNode::GetBookISBN() const{
   return bookISBN;
}

// Print book information
void BookNode::PrintBookInfo() const{
   cout << "Title: " << bookTitle << endl;
   cout << "Author: " << bookAuthor << endl;
   cout << "ISBN: " << bookISBN << endl;
}

#ifndef VECTORLIBRARYH
#define VECTORLIBRARYH

#include "Book.h"
#include <vector>
using namespace std;

class VectorLibrary {
   public:
      VectorLibrary();

      int InsertSorted(const Book &newBook, int counter);

      void PrintLibrary() const;
   
   private:
   // vector library
   vector<Book> library;

};

#endif

#include "VectorLibrary.h"
#include <iostream>

VectorLibrary::VectorLibrary() {
      vector<Book> library;
}

int VectorLibrary::InsertSorted(const Book &newBook, int counter) {
   Book currBook;

   // Add an empty element at end of list
   Book emptyBook;
   library.push_back(emptyBook);

   // Loop through elements starting at the end
   for (int i = library.size() - 2; i >=0; --i) {
      currBook = library.at(i);

      // If the current book's ISBN is larger than newBook's ISBN, shift
      // the current book down 1, count shift operation
      if(currBook.GetBookISBN() > newBook.GetBookISBN()){
         library.at(i + 1) = currBook;
         ++counter;
      }

      // Otherwise, place newBook at the next location (empty slot),
      // count insert operation
      else {
         library.at(i + 1) = newBook;
         ++counter;
         return counter;
      }
   }

   // If we get to the top of the list, place newBook on top
   library.at(0) = newBook;
   ++counter;
   return counter;
}

void VectorLibrary::PrintLibrary() const {
   for (size_t i = 0; i < library.size(); ++i) {
      library.at(i).PrintInfo();
      cout << endl;
   }
}

#ifndef LINKEDLISTLIBRARYH
#define LINKEDLISTLIBRARYH

#include "BookNode.h"
using namespace std;

class LinkedListLibrary {
   public:
      //Linked list node
      BookNode* headNode;

      LinkedListLibrary();

      ~LinkedListLibrary();

      int InsertSorted(BookNode* newNode, int counter);

      void PrintLibrary() const;
};

#endif

#include "LinkedListLibrary.h"
#include <iostream>

LinkedListLibrary::LinkedListLibrary() {
   // Front of nodes list
   headNode = nullptr;
}

LinkedListLibrary::~LinkedListLibrary() {
   while(headNode != nullptr) {
      BookNode* tempNode = headNode->GetNext();
      delete headNode;
      headNode = tempNode;
   }
}

int LinkedListLibrary::InsertSorted(BookNode* newNode, int counter) {
   BookNode* currNode, nextNode;

   // Special case for head node
   if (headNode == nullptr || headNode->GetBookISBN() >= newNode->GetBookISBN()) {
      newNode->SetNext(headNode);
      headNode = newNode;
   }
   else {
      // Locate the node before insertion point
      currNode = headNode;

      while (currNode->GetNext() && currNode->GetNext()->GetBookISBN() < newNode->GetBookISBN()) {
         currNode = currNode->GetNext();
      }
      currNode->insertAfter(newNode);
   }

   ++counter;
   return counter;
}

void LinkedListLibrary::PrintLibrary() const {
   BookNode* currNode;

   currNode = headNode->GetNext();
   while (currNode != nullptr) {
      currNode->PrintBookInfo();
      cout << endl;
      currNode = currNode->GetNext();
   }
}

#include "LinkedListLibrary.h"
#include "VectorLibrary.h"
#include "BookNode.h"
#include "Book.h"
#include <fstream>
#include <iostream>
using namespace std;

void FillLibraries(LinkedListLibrary &linkedListLibrary, VectorLibrary &vectorLibrary) {
   ifstream inputFS; // File input stream
   int linkedListOperations = 0;
   int vectorOperations = 0;

   BookNode* currNode;
   Book tempBook;

   string bookTitle;
   string bookAuthor;
   long long bookISBN;

   // Try to open file
   inputFS.open("books.txt");

   while(getline(inputFS, bookTitle)) {
      inputFS >> bookISBN;
      inputFS.ignore(1, '\n');
      getline(inputFS, bookAuthor);

      // Insert into linked list
      currNode = new BookNode(bookTitle, bookAuthor, bookISBN);
      linkedListOperations = linkedListLibrary.InsertSorted(currNode, linkedListOperations);

      // Insert into vector
      tempBook = Book(bookTitle, bookAuthor, bookISBN);
      vectorOperations = vectorLibrary.InsertSorted(tempBook, vectorOperations);
   }

   inputFS.close(); // close() may throw ios_base::failure if fails
}

int main () {
   int linkedListOperations = 0;
   int vectorOperations = 0;

   // Create libraries
   LinkedListLibrary linkedListLibrary = LinkedListLibrary();
   VectorLibrary vectorLibrary;

   // Fill libraries with 100 books
   FillLibraries(linkedListLibrary, vectorLibrary);

   // Create new book to insert into libraries
   BookNode* currNode;
   Book tempBook;

   string bookTitle;
   string bookAuthor;
   long bookISBN;

   getline(cin, bookTitle);
   cin >> bookISBN;
   cin.ignore();
   getline(cin, bookAuthor);

   // Insert into linked list
   // No need to delete currNode, deleted by LinkedListLibrary destructor
   currNode = new BookNode(bookTitle, bookAuthor, bookISBN);
   linkedListOperations = linkedListLibrary.InsertSorted(currNode, linkedListOperations);

   // Insert into VectorList
   tempBook  = Book(bookTitle, bookAuthor, bookISBN);
   vectorOperations = vectorLibrary.InsertSorted(tempBook, vectorOperations);

cout << "Number of linked list book copy operations: " << linkedListOperations << endl;

cout << "Number of vector book copy operations: " << vectorOperations << endl;

}

/*8.13 LAB: Library book sorting
Two sorted lists have been created, one implemented using a linked list (LinkedListLibrary class) and the other implemented using the built-in Vector class (VectorLibrary class). Each list contains 100 books (title, ISBN number, author), sorted in ascending order by ISBN number.

Complete main() by inserting a new book into each list using the respective LinkedListLibrary and VectorLibrary InsertSorted() functions and outputting the number of book copy operations the computer must perform to insert the new book. Each InsertSorted() returns the number of book copy operations the computer performs.

Ex: If the input is:

Their Eyes Were Watching God
9780060838676
Zora Neale Hurston
the output is:

Number of linked list book copy operations: 1
Number of vector book copy operations: 95
Which list do you think will require the most operations? Why?*/