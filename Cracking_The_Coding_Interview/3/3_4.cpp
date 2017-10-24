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

class MyQueue
{
        private:
                Stack<int> insert;
                Stack<int> remove;
        public:
                MyQueue();
                Stack<int> reverse(Stack<int>);
                void push(int);
                int pop();
};

MyQueue::MyQueue() {}

void MyQueue::push(int value)
{
        insert.push(value);
        remove = reverse(insert);
}

int MyQueue::pop()
{
        int data = remove.pop();
        insert = reverse(remove);
        return data;
}

Stack<int> MyQueue::reverse(Stack<int> st)
{
        Stack<int> rev;
        while (!st.isEmpty()) {
                int extracted_value = st.pop();
                rev.push(extracted_value);
        }
        return rev;
}

int main()
{
        MyQueue* q = new MyQueue;
        int ch, data;
        while (1) {
                scanf("%d", &ch);
                if (ch == 1) {
                        scanf("%d", &data);
                        q->push(data);
                }
                if (ch == 2) {
                        printf("Element Popped: %d\n", q->pop());
                }
                if (ch == 3)
                        break;
                        //printf("Current top: %d\n", st->peek());
                if (ch == 4)
                        break;
        }
        return 0;
}
