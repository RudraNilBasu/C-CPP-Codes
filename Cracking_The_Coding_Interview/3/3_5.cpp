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
                T err;

                Stack()
                {
                        head = NULL;
                        size = 0;
                }

                Stack(T err)
                {
                        head = NULL;
                        size = 0;
                        this->err = err;
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
                        if (head == NULL) {
                                printf("NULL\n");
                                return err;
                        }

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

class SortStack
{
        private:
                Stack<int> st;
                Stack<int> temp;
        public:
                SortStack();
                void push(int);
                int pop();
                int peek();
                bool isEmpty();
};

SortStack::SortStack() {}

void SortStack::push(int data)
{
        while (!st.isEmpty() && st.peek() <= data) {
                temp.push(st.pop());
        }

        st.push(data);

        while (!temp.isEmpty()) {
                st.push(temp.pop());
        }
}

int SortStack::pop()
{
        return st.pop();
}

int SortStack::peek()
{
        return st.peek();
}

bool SortStack::isEmpty()
{
        return st.isEmpty();
}

Stack<int> sort(Stack<int> st)
{
        Stack<int> temp;
        while (!st.isEmpty()) {
                int current_top = st.pop();
                int elements_inserted = 0;
                while (!temp.isEmpty() && temp.peek() > current_top) {
                        st.push(temp.pop());
                        elements_inserted++;
                }
                temp.push(current_top);
                while(elements_inserted--) {
                        temp.push(st.pop());
                }
        }

        while (!temp.isEmpty()) {
                st.push(temp.pop());
        }
}

int main()
{
        SortStack* st = new SortStack;
        int ch, data;
        while (1) {
                scanf("%d", &ch);
                if (ch == 1) {
                        scanf("%d", &data);
                        st->push(data);
                }
                if (ch == 2) {
                        printf("Element Popped: %d\n", st->pop());
                }
                if (ch == 3) {
                        while (!st->isEmpty()) {
                                printf("%d ", st->pop());
                        }
                        printf("\n");
                }
                if (ch == 4) {
                        printf("Peek element: %d\n", st->peek());
                }
                if (ch == 5)
                        break;
        }
        return 0;
}
