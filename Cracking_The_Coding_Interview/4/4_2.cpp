#include <stdio.h>
#include <iostream>

class node {
        public:
        int value;
        node* left_child;
        node* right_child;
        node() {}
};

node* BuildBST(int arr[], int start, int end)
{
        if (start > end)
                return NULL;
        node *_node = new node();
        int sum = start + end;
        //sum += (sum & 1) ? 1 : 0;
        int mid = sum / 2;
        _node->value = arr[mid];
        _node->left_child = BuildBST(arr, start, mid - 1);
        _node->right_child = BuildBST(arr, mid + 1, end);
        return _node;
}

void printBST(node* root)
{
        if (root == NULL)
                return;
        std::cout << root->value << std::endl;
        //if (root->left_child != NULL)
        printBST(root->left_child);
        //if (root->right_child != NULL)
        printBST(root->right_child);
}

int main()
{
        int i, n;
        std::cin >> n;
        int arr[n];
        for (i = 0; i < n; i++)
                std::cin >> arr[i];

        node* root = BuildBST(arr, 0, n - 1);
        //std::cout << "Root: " << root->value << "\nLeft: " << (root->left_child)->value << " , " << (root->right_child)->value << std::endl;
        printBST(root);
        return 0;
}
