#include <iostream>

class Node
{
        public:
                int value;
                Node* left;
                Node* right;

                Node() {}

                void add_left(Node*);
                void add_right(Node*);
                void add_value(int);
};

void Node::add_left(Node* node)
{
        left = node;
}

void Node::add_right(Node* node)
{
        right = node;
}

void Node::add_value(int value)
{
        this->value = value;
}

typedef struct check
{
        bool isBST;
        int min;
        int max;
}check;

bool ValidateBST(Node* root)
{
        if (root == NULL)
                return true;
        if (root->left && root->left->value > root->value)
                return false;
        if (root->right && root->right->value <= root->value)
                return false;
        return ValidateBST(root->left) && ValidateBST(root->right);
}

int main()
{
        return 0;
}
