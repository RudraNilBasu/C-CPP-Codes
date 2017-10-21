#include <stdio.h>
#include <limits.h>

class Node {
        public:
        int data;
        Node* next;
};

class Stack
{
        public:
                Node* head;
                int size;

                Stack()
                {
                        head = NULL;
                        size = 0;
                }

                ~Stack()
                {
                        delete head;
                }

                void push(int data)
                {
                        Node *n = new Node;
                        n->data = data;
                        n->next = head;
                        if (n->next != NULL)
                                printf("Last was: %d\n", head->data);
                        head = n;
                        size++;
                }

                int pop()
                {
                        if (head == NULL)
                                return -1;

                        int data = head->data;
                        head = head->next;
                        size--;
                        return data;
                }

                bool isEmpty()
                {
                        return size == 0;
                }

                int peek()
                {
                        return head == NULL ? -1 : head->data;
                }
};

int main()
{
        Stack *st = new Stack();
        return 0;
}
