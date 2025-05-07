#include <iostream> 
 using namespace std; 
 // Node structure 
 struct Node { 
    int data; 
    Node* left; 
    Node* right; 
    Node(int value) { 
        data = value; 
        left = right = nullptr; 
    } 
 }; 
 // Insert a new node into BST 
 Node* insert(Node* root, int data) { 
    if (root == nullptr) 
        return new Node(data); 
    if (data < root->data) 
        root->left = insert(root->left, data); 
    else 
        root->right = insert(root->right, data); 
    return root; 
 } 
 // Find height (number of nodes in longest path from root) 
 int height(Node* root) { 
    if (root == nullptr) 
        return 0; 
    int leftHeight = height(root->left); 
    int rightHeight = height(root->right); 
    return max(leftHeight, rightHeight) + 1; 
 } 
 // Find minimum value in BST 
 int findMin(Node* root) { 
    if (root == nullptr) { 
        cout << "Tree is empty\n"; 
        return -1; 
    } 
    while (root->left != nullptr) 
        root = root->left; 
    return root->data; 
 } 
// Mirror the tree (swap left and right) 
 void mirror(Node* root) { 
    if (root == nullptr) 
        return; 
    swap(root->left, root->right); 
    mirror(root->left); 
    mirror(root->right); 
 } 
 // Search a value in the BST 
 bool search(Node* root, int key) { 
    if (root == nullptr) 
        return false; 
    if (root->data == key) 
        return true; 
    else if (key < root->data) 
        return search(root->left, key); 
    else 
        return search(root->right, key); 
 } 
 // Inorder traversal to display the tree 
 void inorder(Node* root) { 
    if (root == nullptr) 
        return; 
    inorder(root->left); 
    cout << root->data << " "; 
    inorder(root->right); 
 } 
 int main() { 
    Node* root = nullptr; 
    // Initial values 
    int values[] = {50, 30, 70, 20, 40, 60, 80}; 
    for (int val : values) 
        root = insert(root, val); 
    cout << "Inorder Traversal of Original BST:\n"; 
    inorder(root); 
    cout << "\n"; 
    // i. Insert new node (25) 
    root = insert(root, 25); 
    cout << "After inserting 25:\n"; 
    inorder(root); 
    cout << "\n"; 
    // ii. Longest path from root (height in terms of nodes) 
    int longestPath = height(root); 
    cout << "Number of nodes in longest path from root: " << longestPath << "\n"; 
    // iii. Minimum data value 
    int minValue = findMin(root); 
    cout << "Minimum value in the tree: " << minValue << "\n"; 
    // iv. Mirror the tree 
    mirror(root); 
cout << "Inorder Traversal of Mirrored Tree:\n"; 
inorder(root); 
cout << "\n"; 
// v. Search for value 60 
int searchValue = 60; 
cout << "Searching for " << searchValue << ": "; 
if (search(root, searchValue)) 
cout << "Found\n"; 
else 
cout << "Not Found\n"; 
return 0; 
}