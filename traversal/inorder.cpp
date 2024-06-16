#include <iostream>

struct Node 
{
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(Node* root) 
{
    if (root == nullptr) 
    {
        return;
    }
    
    inorder(root->left);
    
    std::cout << root->val << " ";
    
    inorder(root->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    inorder(root);

    return 0;
}