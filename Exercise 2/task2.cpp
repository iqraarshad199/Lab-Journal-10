#include <iostream>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    TreeNode* root;

    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

private:
    TreeNode* insertRec(TreeNode* node, int value) {
        if (node == NULL) return new TreeNode(value);
        if (value < node->value)
            node->left = insertRec(node->left, value);
        else if (value > node->value)
            node->right = insertRec(node->right, value);
        return node;
    }
};

// Function to print the path from root to a given node
bool printPath(TreeNode* root, int value) {
    if (root == NULL)
        return false;

    // Print current node's value
    cout << root->value << " ";

    // Check if current node is the target
    if (root->value == value)
        return true;

    // Check both subtrees
    if (printPath(root->left, value) || printPath(root->right, value))
        return true;

    // If not found in either subtree, print current node's value again
    cout << " <- backtrack from " << root->value;
    return false;
}

// Function to find the maximum value in the BST
int findmax(TreeNode* root) {
    if (root == NULL)
        return -1;

    while (root->right != NULL) {
        root = root->right;
    }
    return root->value;
}

// Function to find sibling of a given node
TreeNode* findSibling(TreeNode* current, int value, TreeNode* parent) {
    if (current == NULL)
        return NULL;

    if (current->value == value) {
        // If parent exists and has a child that is not current, return that child
        if (parent != NULL) {
            if (parent->left == current)
                return parent->right; // Return right child as sibling
            else
                return parent->left; // Return left child as sibling
        }
        return NULL; // No sibling found or it's the root node
    }

    // Recursively search in left and right subtrees
    TreeNode* leftSibling = findSibling(current->left, value, current);
    if (leftSibling != NULL) // If found in left subtree
        return leftSibling;

    return findSibling(current->right, value, current); // Search in right subtree
}

// Wrap function for finding sibling that uses the BST's root
TreeNode* findSiblingWrap(BST& tree, int value) {
    return findSibling(tree.root, value, NULL);
}

int main() {
    BST tree;

    // Insert nodes into the BST
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(3);
    tree.insert(7);
    tree.insert(15);

    int searchValue = 7;

    cout << "\n\n\tPath to " << searchValue << ": ";

    if (!printPath(tree.root, searchValue)) {
        cout << "\tValue " << searchValue << " not found in the tree." << endl;
    }
    else {
        cout << endl;
    }

    int max = findmax(tree.root);
    if (max != -1)
        cout << "\tMaximum Value in BST: " << max << endl;

    int siblingValue = 5; // Change this for different tests
    TreeNode* sibling = findSiblingWrap(tree, siblingValue);

    if (sibling != NULL)
        cout << "\tSibling of " << siblingValue << ": " << sibling->value << endl;
    else
        cout << "\tNo sibling found for " << siblingValue << endl;
    cout << endl;

    return 0;
}
