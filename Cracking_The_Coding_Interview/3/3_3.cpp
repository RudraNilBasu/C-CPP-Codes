#include <stdio.h>

template <typename T>
class Node {
        public:
        T data;
        Node* next;
};

template <typename T>
class Stack
{
        public:
                Node<T>* head;
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

                void push(T data)
                {
                        Node<T> *n = new Node<T>;
                        n->data = data;
                        n->next = head;
                        head = n;

                        size++;
                }

                T pop()
                {
                        if (head == NULL)
                                return -1;

                        T data = head->data;
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

                int getSize()
                {
                        return size;
                }
};

#define MAX_PLATES 5

class SetOfStacks
{
        private:
                Stack<Stack<int> >* stack_set;
        public:
                SetOfStacks();
                void push(int data);
                int pop();
                int getSize();
};

SetOfStacks::SetOfStacks()
{
        stack_set = new Stack<Stack<int> >;
}

void SetOfStacks::push(int data)
{
        if (stack_set->head == NULL) {
                Stack<int>* st = new Stack<int>;
                stack_set->push(*st);
        } else if (stack_set->head->getSize() >= MAX_PLATES) {
                Stack<int>* st = new Stack<int>;
                stack_set->push(*st);
        }
        stack_set->head->push(data);
        size++;
}

void SetOfStacks::pop()
{
        stack_set->head->pop();
        if (stack_set->head->getSize() == 0)
                stack_set->pop();
}

int getSize()
{
        return stack_set->getSize();
}

int main()
{
        int max_size_per_plate = 5;
        Stack<int> *st = new Stack<int>();
        int ch, data;
        while (1) {
                scanf("%d", &ch);
                if (ch == 1) {
                        scanf("%d", &data);
                        st->push(data);
                }
                if (ch == 2) {
                        printf("Popped: %d\n", st->pop());
                        printf("Current top: %d\n", st->peek());
                }
                if (ch == 3)
                        printf("Current top: %d\n", st->peek());
                if (ch == 4)
                        break;
        }
        return 0;
}
