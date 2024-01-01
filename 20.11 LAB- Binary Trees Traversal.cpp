#include <iostream>
using namespace std;

struct node {
    int element;
    node *left;
    node *right;
    node(int element) {
        this->element = element;
        left = right = nullptr;
    }
};

void process(int element) {
    cout << element << " ";
}

void inorderTraversal(node *n) {
    if (n == nullptr) {
        return;
    }
    
    // Traverse the left subtree
    inorderTraversal(n->left);

    // Process the current node
    process(n->element);

    // Traverse the right subtree
    inorderTraversal(n->right);
}

void preorderTraversal(node *n) {
    if (n == nullptr) {
        return;
    }

    // Process the current node
    process(n->element);

    // Traverse the left subtree
    preorderTraversal(n->left);

    // Traverse the right subtree
    preorderTraversal(n->right);
}

void postorderTraversal(node *n) {
    if (n == nullptr) {
        return;
    }

    // Traverse the left subtree
    postorderTraversal(n->left);

    // Traverse the right subtree
    postorderTraversal(n->right);

    // Process the current node
    process(n->element);
}

int main(int argc, const char *argv[]) {
    node *root = new node(1);
    node *node2 = new node(2);
    node *node3 = new node(3);
    node *node4 = new node(4);
    node *node5 = new node(5);
    node *node6 = new node(6);
    node *node7 = new node(7);
    node *node8 = new node(8);
    node *node9 = new node(9);

    root->left = node2;
    root->right = node3;

    node2->left = node4;
    node2->right = node5;

    node5->left = node7;
    node5->right = node8;

    node3->right = node6;

    node6->right = node9;

    cout << "#### INORDER TRAVERSAL #####" << endl;

    inorderTraversal(root);

    cout << endl << "#### PREORDER TRAVERSAL #####" << endl;

    preorderTraversal(root);

    cout << endl << "#### POSTORDER TRAVERSAL #####" << endl;

    postorderTraversal(root);

    return 0;
}

/*20.11 LAB Week#14 - Binary Trees Traversal
Complete the code for all the tree traversal functions. Run the program, your code should display the following output.

#### INORDER TRAVERSAL #####
4 2 7 5 8 1 3 6 9 
#### PREORDER TRAVERSAL #####
1 2 4 5 7 8 3 6 9 
#### POSTORDER TRAVERSAL #####
4 7 8 5 2 9 6 3 1*/