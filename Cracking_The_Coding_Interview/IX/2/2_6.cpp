#include <stdio.h>
#include <map>
#include <iostream>

class Node {
        public:
        int data;
        Node *next;

        Node()
        {
                data = 0;
                next = NULL;
        }

        Node(int _data)
        {
                data = _data;
                next = NULL;
        }

        void setNext(Node *n)
        {
                next = n;
        }
};

class LinkedList
{
        public:
        Node* head;

        LinkedList()
        {
                head = NULL;
        }

        int get_length()
        {
                Node* i = head;
                int node_count = 0;

                while (i != NULL) {
                        node_count++;
                        i = i->next;
                }
                return node_count;
        }

        void add_element_end(int _data)
        {
                Node *n = new Node;
                n->data = _data;
                n->next = NULL;

                if (head == NULL) {
                        head = n;
                        return;
                }

                Node *i = head;
                while ((i->next) != NULL) {
                        i = i->next;
                }
                i->next = n;
                return;
        }

        void add_element_front(int _data)
        {
                Node* node = new Node;
                node->data = _data;
                node->next = head;
                head = node;
        }

        void display_list()
        {
                printf("DISPLAYING LIST\n");
                Node *i = head;
                while (i != NULL) {
                        printf("%d->", i->data);
                        i = i->next;
                }
                printf("\n");
        }

        void delete_from_index(int n)
        {
                // remove the nth element
                if (n == 1) {
                        head = head->next;
                        return ;
                }
                int cnt = 0;
                Node *i = head;
                while (i != NULL) {
                        cnt++;
                        if (cnt + 1 == n) {
                                if (i->next == NULL)
                                        return;
                                i->next = i->next->next;
                                return;
                        }
                        i = i->next;
                }
        }

        Node* get_node_from_index(int _index)
        {
                int index = 1;
                Node* i = head;

                while (i != NULL) {
                        if (index == _index) {
                                return i;
                        }
                        index++;
                        i = i->next;
                }
        }
};

int get_reversed_no(Node* node)
{
        if (node->next == NULL)
                return node->data;

        int reversed_number_after_node = get_reversed_no(node->next);
        return (reversed_number_after_node * 10) + node->data;
}

bool check_palindrome(LinkedList list)
{
        int reversed_number = get_reversed_no(list.head);

        Node* i = list.head;

        int original_number = 0;
        while (i != NULL) {
                original_number = (original_number * 10) + i->data;
                i = i->next;
        }

        return original_number == reversed_number;
}

LinkedList reverse_list(Node* node)
{
        LinkedList list;
        list.head = NULL;
        while (node != NULL) {
                Node *n = new Node;
                n->data = node->data;
                n->next = list.head;
                list.head = n;
                node = node->next;
        }
        list.display_list();
        return list;
}

int main()
{
        LinkedList num_1;
        num_1.add_element_end(1);
        num_1.add_element_end(2);
        num_1.add_element_end(3);
        num_1.add_element_end(4);
        num_1.add_element_end(5);

        if (check_palindrome(num_1))
                printf("Palindrome\n");
        else
                printf("Not Palindrome\n");

        reverse_list(num_1.head);
        return 0;
}
