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

#include <map>

void find_intersection(Node* n1, Node* n2)
{
        std::map<Node*, bool> mp;

        while (n1 != NULL) {
                mp[n1] = true;
                n1 = n1->next;
        }

        while (n2 != NULL) {
                if (mp[n2]) {
                        printf("Intersection point: %d\n", n2->data);
                        return ;
                }
                n2 = n2->next;
        }
}

void find_intersection_new(LinkedList l1, LinkedList l2)
{
        int len_1 = l1.get_length();
        int len_2 = l2.get_length();

        int diff = 0;

        Node *l1_head = l1.head, *l2_head = l2.head;
        if (len_1 > len_2) {
                diff = len_1 - len_2;
                l1_head = l1.get_node_from_index(diff + 1);
        } else if (len_2 > len_1) {
                diff = len_2 - len_1;
                l2_head = l2.get_node_from_index(diff + 1);
        }

        while (l1_head != NULL) {
                if (l1_head == l2_head) {
                        printf("Intersection point found at: %d\n", l1_head->data);
                        return;
                }
                l1_head = l1_head->next;
                l2_head = l2_head->next;
        }
        printf("No Intersection point found\n");
        return;
}

int main()
{
        LinkedList num_1;
        num_1.add_element_end(1);
        num_1.add_element_end(2);
        num_1.add_element_end(3);
        num_1.add_element_end(4);
        num_1.add_element_end(5);

        LinkedList num_2;
        num_2.add_element_end(10);
        Node* i = num_2.head;
        while (i->next != NULL) {
                i = i->next;
        }

        Node* temp = num_1.get_node_from_index(3);
        i->next = temp;

        num_1.display_list();
        num_2.display_list();

        find_intersection(num_1.head, num_2.head);

        find_intersection_new(num_1, num_2);
        return 0;
}
