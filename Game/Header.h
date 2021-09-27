#include <iostream>
#include <string>
#include <fstream>

using namespace std;
#define COUNT 10
struct Node {
    string data;
    bool isFullChild;
    Node* left;
    Node* right;
};

bool canAddNode(Node* node) {
    return node == NULL || node->isFullChild == false;
}

Node* add(Node* root, string s, bool& isAdded) {
    if (root == NULL) {
        root = new Node{ s, true, NULL, NULL };
        if (s[1] == 'Q') root->isFullChild = false;
        isAdded = true;
        return root;
    }
    if (root->isFullChild) return root;

    if (canAddNode(root->left)) {
        root->left = add(root->left, s, isAdded);
    }

    if (!isAdded && canAddNode(root->right)) {
        root->right = add(root->right, s, isAdded);
    }

    if (!canAddNode(root->left) && !canAddNode(root->right)) root->isFullChild = true;

    return root;
}

void print(Node* root) {
    if (root == NULL) return;
    cout << root->data << endl;
    print(root->left);
    print(root->right);
}

void print2DUtil(Node* root, int space)
{
    if (root == NULL)
        return;

    space += COUNT;

    print2DUtil(root->right, space);

    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << "\n";

    print2DUtil(root->left, space);
}

void print2D(Node* root)
{
    print2DUtil(root, 0);
}