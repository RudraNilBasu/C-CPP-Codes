#include <stdio.h>
#include <limits.h>

class Node
{
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

class MinStack : public Stack
{
        public:
                Stack *min_st;

                MinStack();
                void push(int);
                int pop();
                int min();
};

MinStack::MinStack() : Stack()
{
        min_st = new Stack;
        min_st->push(INT_MAX);
}

void MinStack::push(int data)
{
        if (data < min_st->peek()) {
                min_st->push(data);
        }

        Stack::push(data);
}

int MinStack::pop()
{
        int data = Stack::pop();
        if (data == min_st->peek()) {
                min_st->pop();
        }
        return data;
}

int MinStack::min()
{
        return min_st->peek();
}

int main()
{
        MinStack *st = new MinStack;
        int ch, data;
        while (1) {
                scanf("%d", &ch);
                if (ch == 1) {
                        scanf("%d", &data);
                        st->push(data);
                } else if (ch == 2) {
                        st->pop();
                } else if (ch == 3) {
                        printf("Head: %d\n", st->peek());
                } else if (ch == 4) {
                        printf("Min: %d\n", st->min());
                } else if (ch == 5) {
                        break;
                }
        }
        return 0;
}
