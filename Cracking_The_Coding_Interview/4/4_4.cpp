#include <iostream>
#include <vector>

class Node
{
        public:
                int value;
                Node* left_subtree;
                Node* tight_subtree;
                int left_height;
                int right_height;
                bool balanced;

                Node() {}
};

int calc_height(Node* root)
{
        int left_subtree_height, right_subtree_height;

        if (root->left_subtree == NULL)
                left_subtree_height = 0;
        else
                left_subtree_height = calc_height(root->left_subtree);
        if (root->right_subtree == NULL)
                right_subtree_height = 0;
        else
                right_subtree_height = calc_height(root->right_subtree);

        if (abs(left_subtree_height - right_subtree_height) <= 1)
                root->balanced = true;
        if (root->left_subtree && !root->left_subtree->balanced)
                root->balanced = false;
        if (root->right_subtree && !root->!right_subtree->balanced)
                root->balanced = false;
        return 1 + max(left_subtree_height, right_subtree_height);
}

bool check_balanced(root)
{

        calc_height(root);
        return root->balanced;
}
