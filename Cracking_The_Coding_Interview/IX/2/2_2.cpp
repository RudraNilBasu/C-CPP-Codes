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
                        printf("%d ", i->data);
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

        int kth_to_last(int k)
        {
                Node* i = head;
                int n = 0;
                while (i != NULL) {
                        n++;
                        i = i->next;
                }

                int return_index = n - k + 1;
                if (return_index <= 0 || return_index > n)
                        return -1;

                int index = 1;

                i = head;
                while (index != return_index) {
                        index++;
                        i = i->next;
                }

                return i->data;
        }

        int kth_to_last_recursive(Node* node, int k)
        {
                int no_from_back = 1 + (node->next == NULL ? 0 : kth_to_last_recursive(node->next, k));
                if (no_from_back == k) {
                        printf("%dth element: %d\n", k, node->data);
                }
                return no_from_back;
        }
};

int main()
{
        LinkedList list;

        list.add_element_end(1);
        list.add_element_end(2);
        list.add_element_end(3);
        list.add_element_end(4);
        list.add_element_end(5);

        list.display_list();


        std::cout << "2nd from last: " << list.kth_to_last(2) << std::endl;
        std::cout << "3rd from last: " << list.kth_to_last(3) << std::endl;

        list.kth_to_last_recursive(list.head, 2);
        list.kth_to_last_recursive(list.head, 3);
        return 0;
}
