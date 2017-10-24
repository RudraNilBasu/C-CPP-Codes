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

                void pop()
                {
                        if (head == NULL)
                                return ;

                        T data = head->data;
                        head = head->next;
                        size--;
                        return;// data;
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
                void pop();
                int getSize();
                int peek();
                void popAt(int);
};

SetOfStacks::SetOfStacks()
{
        stack_set = new Stack<Stack<int> >;
}

void SetOfStacks::push(int data)
{
        if (stack_set->head == NULL) {
                printf("No Stack available, creating a new one\n");
                Stack<int>* st = new Stack<int>;
                stack_set->push(*st);
        } else if (stack_set->head->data.getSize() >= MAX_PLATES) {
                printf("Previous stack is full, creating a new one\n");
                Stack<int>* st = new Stack<int>;
                stack_set->push(*st);
        }
        stack_set->head->data.push(data);
}

void SetOfStacks::pop()
{
        if (stack_set->head == NULL) return;
        stack_set->head->data.pop();
        if (stack_set->head->data.getSize() == 0)
                stack_set->pop();
}

int SetOfStacks::getSize()
{
        return stack_set->getSize();
}

int SetOfStacks::peek()
{
        if (stack_set->head == NULL) return -1;
        return stack_set->head->data.peek();
}

void SetOfStacks::popAt(int _index)
{
        Node< Stack<int> >* st = stack_set->head;
        int index = 0;
        while (st != NULL) {
                index++;
                if (index == _index) {
                        st->data.pop();
                        break;
                }
                st = st->next;
        }
}

int main()
{
        SetOfStacks* st = new SetOfStacks;
        int ch, data;
        while (1) {
                scanf("%d", &ch);
                if (ch == 1) {
                        scanf("%d", &data);
                        st->push(data);
                }
                if (ch == 2) {
                        st->pop();
                        printf("Popped\n");
                        //printf("Current top: %d\n", st->peek());
                }
                if (ch == 3)
                        printf("Current top: %d\n", st->peek());
                if (ch == 4)
                        break;
        }
        return 0;
}
