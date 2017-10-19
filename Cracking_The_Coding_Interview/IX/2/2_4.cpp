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

        void insert_front(Node* node)
        {
                node->next = head;
                head = node;
        }

        void partition(int value)
        {
                Node* i = head;
                Node* prev = NULL;
                while (i != NULL) {
                        if (i->data < value) {
                                if (prev == NULL) {
                                        i = i->next;
                                        continue;
                                }
                                // move i to head
                                Node* lesser_node = i;
                                i = i->next;
                                prev->next = i;
                                insert_front(lesser_node);
                        } else {
                                prev = i;
                                i = i->next;
                        }
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

int main()
{
        LinkedList list;

        list.add_element_end(3);
        list.add_element_end(5);
        list.add_element_end(8);
        list.add_element_end(5);
        list.add_element_end(10);
        list.add_element_end(2);
        list.add_element_end(1);

        list.display_list();

        list.partition(5);

        list.display_list();
        return 0;
}
