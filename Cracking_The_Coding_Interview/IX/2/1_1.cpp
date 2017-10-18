#include <stdio.h>

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
};

int main()
{
        LinkedList list;

        list.add_element_end(5);
        list.add_element_end(101);
        list.add_element_end(15);
        list.add_element_end(5);

        list.display_list();

        return 0;
}
