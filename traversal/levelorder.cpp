#include <iostream>
#include <queue>

struct Node 
{
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

void levelOrderTraversal(Node* root) 
{
    if (root == nullptr) 
    {
        return;
    }

    std::queue<Node*> q; 
    q.push(root);

    while (!q.empty()) 
    {
        Node* node = q.front();
        q.pop();

        std::cout << node->val << " ";  

        if (node->left != nullptr) 
        {
            q.push(node->left);
        }
        if (node->right != nullptr) 
        {
            q.push(node->right);
        }
    }
}

int main() 
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    levelOrderTraversal(root);

    return 0;
}
