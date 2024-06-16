#include <iostream>

struct Node 
{
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preorder(Node* root) 
{
    if (root == nullptr) 
    {
        return;
    }

    std::cout << root->val << " ";
    
    preorder(root->left);
    
    preorder(root->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    preorder(root);

    return 0;
}