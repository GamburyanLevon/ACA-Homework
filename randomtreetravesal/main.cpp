#include <iostream>
#include <vector>
#include <queue>
#include <ctime>

struct Node
{
    int value;
    std::vector<Node *> children;

    Node(int val) : value(val) {}
};

int getRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

Node *createRandomTree(int depth)
{
    if (depth < 0)
        return nullptr;

    Node *root = new Node(getRandomNumber(1, 100));
    if (depth == 0)
        return root;

    int numberOfChildren = getRandomNumber(0, 3);
    for (int i = 0; i < numberOfChildren; ++i)
    {
        root->children.push_back(createRandomTree(depth - 1));
    }

    return root;
}

void traverseTree(Node *root)
{
    if (!root)
        return;

    std::queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        std::cout << current->value << " ";

        for (Node *child : current->children)
        {
            if (child)
                q.push(child);
        }
    }
}

int main()
{
    srand(time(0));

    int treeDepth = getRandomNumber(0, 10);
    Node *root = createRandomTree(treeDepth);

    traverseTree(root);
    std::cout << std::endl;

    return 0;
}
