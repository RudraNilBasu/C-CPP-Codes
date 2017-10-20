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

        void add_element_front(int _data)
        {
                Node* node = new Node;
                node->data = _data;
                node->next = head;
                head = node;
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

void add_front(LinkedList num_1, LinkedList num_2)
{
        int carry = 0;

        LinkedList res;
        Node *i, *j;
        i = num_1.head;
        j = num_2.head;

        while (i != NULL || j != NULL) {
                int left = (i == NULL) ? 0 : i->data;
                int right = (j == NULL) ? 0 : j->data;

                int sum = (left + right) + carry;
                if (sum > 9) {
                        carry = sum / 10;
                        sum = sum % 10;
                } else {
                        carry = 0;
                }

                res.add_element_end(sum);
                i = (i == NULL) ? NULL : i->next;
                j = (j == NULL) ? NULL : j->next;
        }

        if (carry != 0) {
                res.add_element_end(carry);
        }

        res.display_list();
}

int add_list_front(Node*, Node*, LinkedList*);

void pad_extra_digits(LinkedList num_1, LinkedList num_2)
{
        int len_1 = num_1.get_length();
        int len_2 = num_2.get_length();

        int diff = len_1 - len_2;
        for (int i = 1; i <= diff; i++) {
                if (len_1 > len_2) {
                        num_2.add_element_front(0);
                } else if (len_1 < len_2) {
                        num_1.add_element_front(0);
                }
        }

        LinkedList res;
        int carry = add_list_front(num_1.head, num_2.head, &res);

        if (carry != 0)
                res.add_element_front(carry);

        res.display_list();
}

int add_list_front(Node* num_1, Node* num_2, LinkedList* res)
{
        if (num_1->next == NULL) {
                int sum = num_1->data + num_2->data;
                int carry = sum / 10;
                sum = sum % 10;
                res->add_element_front(sum);
                return carry;
        }

        int prev_carry = add_list_front(num_1->next, num_2->next, res);
        int sum = num_1->data + num_2->data + prev_carry;
        int carry = sum / 10;
        sum = sum % 10;
        res->add_element_front(sum);
        return carry;
}

int main()
{
        LinkedList num_1;
        num_1.add_element_end(7);
        num_1.add_element_end(1);
        num_1.add_element_end(6);

        LinkedList num_2;
        num_2.add_element_end(5);
        num_2.add_element_end(9);
        num_2.add_element_end(2);

        add_front(num_1, num_2);

        LinkedList num_3;
        num_3.add_element_end(1);
        num_3.add_element_end(2);
        num_3.add_element_end(2);

        LinkedList num_4;
        num_4.add_element_end(9);

        pad_extra_digits(num_3, num_4);
        return 0;
}
