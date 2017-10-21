#include <stdio.h>

class Node {
        public:
        int data;
        Node* next;
};

class Queue
{
        public:
                Node* head;
                Node* end;
                int size;

                Queue()
                {
                        head = NULL;
                        end = NULL;
                        size = 0;
                }

                ~Queue()
                {
                        delete head;
                        delete end;
                }

                void add(int data)
                {
                        Node *n = new Node;
                        n->data = data;
                        n->next = NULL;

                        if (end != NULL) {
                                end->next = n;
                        }
                        end = n;

                        if (head == NULL) {
                                head = end;
                        }

                        size++;
                }

                int remove()
                {
                        if (head == NULL)
                                return -1;

                        int data = head->data;
                        head = head->next;
                        if (head == NULL)
                                end == NULL;
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
        Queue *q = new Queue();
        int ch, data;
        while (1) {
                scanf("%d", &ch);
                if (ch == 1) {
                        scanf("%d", &data);
                        q->add(data);
                }
                if (ch == 2) {
                        printf("Removed: %d\n", q->remove());
                        printf("Current top: %d\n", q->peek());
                }
                if (ch == 3)
                        printf("Current top: %d\n", q->peek());
                if (ch == 4)
                        break;
        }
        return 0;
}
