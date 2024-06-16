#include <iostream>

struct Node 
{
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void postorder(Node* root) 
{
    if (root == nullptr) 
    {
        return;
    }

    postorder(root->left);
    
    postorder(root->right);

    std::cout << root->val << " ";
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    postorder(root);

    return 0;
}
