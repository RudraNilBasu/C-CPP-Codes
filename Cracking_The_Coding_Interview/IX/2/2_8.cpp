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

Node* get_collision_point(Node* node)
{
        Node *faster, *slower;
        faster = node->next->next;
        slower = node->next;

        while (faster != slower) {
                slower = slower->next;
                faster = faster->next->next;
        }
        printf("Collided at: %d\n", faster->data);
        return faster;
}

Node* get_loop_start(LinkedList l1)
{
        Node* collision_point = get_collision_point(l1.head);
        Node* start = l1.head;
        while (start != collision_point) {
                start = start->next;
                collision_point = collision_point->next;
        }
        return collision_point;
}

int main()
{
        LinkedList num_1;
        num_1.add_element_end(1);
        num_1.add_element_end(2);
        num_1.add_element_end(3);
        num_1.add_element_end(4);
        num_1.add_element_end(5);

        Node* i = num_1.head;
        while (i->next != NULL) {
                i = i->next;
        }

        Node* temp = num_1.get_node_from_index(3);
        i->next = temp;

        Node* loop_start = get_loop_start(num_1);
        printf("Loop starts at: %d\n", loop_start->data);
        return 0;
}
