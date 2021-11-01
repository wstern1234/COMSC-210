#include <iostream>
#include <assert.h>
using namespace std;




struct BSTNode {

    int value = 0;
    BSTNode* left = NULL;
    BSTNode* right = NULL;

};



class BST {

private:
    BSTNode* root = nullptr;

public:
    BST() {
        root = NULL;
    }

    void insert(int data);
    void remove(int data);
    void removeFromTree(BSTNode*& p);
    BSTNode* finMin() const;
    BSTNode* finMax() const;
    void preOrderTraversal() const;
    void preOrderTraversal(BSTNode* node) const;
    void inOrderTraversal() const;
    void inOrderTraversal(BSTNode* node) const;
    void postOrderTraversal() const;
    void postOrderTraversal(BSTNode* node) const;

};



// inserts node into binary search tree
void BST::insert(int data)
{
    BSTNode* current; // pointer for traversing tree
    BSTNode* trailCurrent = nullptr; // pointer behind current
    BSTNode* newNode = new BSTNode;

    assert(newNode != NULL); // ends if newNode is NULL

    newNode->value = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL)
        root = newNode;

    // utilizes current to loop through iteratively and add node
    else {
        current = root;
        while (current != NULL) {
            trailCurrent = current;
            if (current->value == data) {
                cout << "The insert item is already in the list. Duplicate: " << data << endl;
                return;
            }
            else if (current->value > data)
                current = current->left;
            else
                current = current->right;
        }
        if (trailCurrent->value > data)
            trailCurrent->left = newNode;
        else
            trailCurrent->right = newNode;
    }
}



// removes node into binary search tree
void BST::remove(int data)
{
    BSTNode* current; // pointer to traverse the tree
    BSTNode* trailCurrent; // pointer behind current
    bool found = false;

    if (root == NULL)
        cout << "Cannot delete from the empty tree." << endl;

    // utilizes current to loop through recursively and and removeFromTree to remove node
    else {
        current = root;
        trailCurrent = root;
        while (current != NULL && !found) {
            if (current->value == data)
                found = true;
            else {
                trailCurrent = current;
                if (current->value > data)
                    current = current->left;
                else
                    current = current->right;
            }
        }
        if (current == NULL)
            cout << "The delete item is not in the tree." << endl;
        else if (found) {
            if (current == root)
                removeFromTree(root);
            else if (trailCurrent->value > data)
                removeFromTree(trailCurrent->left);
            else
                removeFromTree(trailCurrent->right);
        }
    }
}



// helper function for BST::remove()
void BST::removeFromTree(BSTNode*& p) {

    BSTNode* current; // pointer to traverse the tree
    BSTNode* trailCurrent; // pointer behind current
    BSTNode* temp;
    
    if (p == NULL)
        cout << "Error: The node to be deleted is NULL." << endl;

    // if both NULL, p is NULL
    else if (p->left == NULL && p->right == NULL) {
        temp = p;
        p = NULL;
        delete temp;
    }

    // if left is NULL, p is right leaf
    else if (p->left == NULL) {
        temp = p;
        p = temp->right;
        delete temp;
    }

    // if right is NULL, p is left leaf
    else if (p->right == NULL) {
        temp = p;
        p = temp->left;
        delete temp;
    }
    else {
        current = p->left;
        trailCurrent = NULL;
        while (current->right != NULL) {
            trailCurrent = current;
            current = current->right;
        }
        p->value = current->value;
        if (trailCurrent == NULL)
            p->left = current->left;

        else
            trailCurrent->right = current->left;
        delete current;
    }
}



// finds minimum value in binary search tree
BSTNode* BST::finMin() const {

    if (root == NULL)
        return root;

    BSTNode* current = root;

    // loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;

}



// finds maximum value in binary search tree
BSTNode* BST::finMax() const {
    
    if (root == NULL)
        return root;

    BSTNode* current = root;

    // loop down to find the leftmost leaf
    while (current && current->right != NULL)
        current = current->right;

    return current;

}



// go to the root, traverse the left subtree, traverse the right subtree
void BST::preOrderTraversal() const {

    cout << "preOrderTraversal: ";
    preOrderTraversal(root);
    cout << endl;

}



// overloaded version of preOrderTraversal, acts as helper function
void BST::preOrderTraversal(BSTNode* node) const {

    if (node != NULL) {
        cout << node->value << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

}



// traverse the left subtree, go to the root, traverse the right subtree
void BST::inOrderTraversal() const {

    cout << "inOrderTraversal: ";
    inOrderTraversal(root);
    cout << endl;

}



// overloaded version of inOrderTraversal, acts as helper function
void BST::inOrderTraversal(BSTNode* node) const {

    if (node != NULL) {
        inOrderTraversal(node->left);
        cout << node->value << " ";
        inOrderTraversal(node->right);
    }

}



// traverse the left subtree, traverse the right subtree, go to the root
void BST::postOrderTraversal() const {

    cout << "postOrderTraversal: ";
    postOrderTraversal(root);
    cout << endl;

}



// overloaded version of postOrderTraversal, acts as helper function
void BST::postOrderTraversal(BSTNode* node) const {

    if (node != NULL) {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->value << " ";
    }

}



const int SIZE = 15;


int main() {

    BST bst;
    int values[SIZE] = { 5, 2, 12, -4, 3, 9, 21, -7, 19, 25, -8, -6, -4, 3, 12 };
    for (int i = 0; i < SIZE; i++)
        bst.insert(values[i]);

    cout << endl;

    bst.preOrderTraversal(); /// should be 5 2 -4 -7 -8 -6 3 12 9 21 19 25
    bst.inOrderTraversal(); /// should be -8 -7 -6 -4 2 3 5 9 12 19 21 25
    bst.postOrderTraversal(); /// should be -8 -6 7 -4 3 2 9 19 25 21 12 5

    cout << "\nFind maximum: " << bst.finMax()->value;
    cout << endl;
    cout << "\nFind minimum: " << bst.finMin()->value;
    cout << endl;
    cout << endl;

    bst.remove(3); /// Node 3 has 0 children --> delete the node and make it NULL;
    bst.remove(-4); /// Node -4 has 1 children --> Link parent to child --> delete the node and make it NULL;
    bst.remove(12); /// Node 12 has 2 children --> findMin for the right subtree --> swap value -> delete

    bst.preOrderTraversal(); /// should be 5 2 -7 -8 -6 19 9 21 25
    bst.inOrderTraversal(); /// should be -8 -7 -6 2 5 9 19 21 25
    bst.postOrderTraversal(); /// should be -8 -6 7 2 9 25 21 19 5

    cout << "\nFind maximum: " << bst.finMax()->value;
    cout << endl;
    cout << "\nFind minimum: " << bst.finMin()->value;
    cout << endl;
    cout << endl;
    
    return 0;

}