#include <stdio.h>
#include <map>

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

        void remove_duplicates()
        {
                std::map<int, bool> occ;
                Node* i = head;

                int index = 0;
                while (i != NULL) {
                        index++;
                        if (!occ[i->data]) {
                                occ[i->data] = true;
                        } else {
                                printf("EXTRA: %d\n", i->data);
                                delete_from_index(index);
                                index--;
                        }
                        i = i->next;
                }
        }

        void remove_duplicates_iteration()
        {
                Node* i = head;
                Node* j;

                int curr_index = 0;
                int next_index;

                while(i != NULL) {
                        j = i;
                        while (j->next != NULL) {
                                if (j->next->data == i->data) {
                                        j->next = j->next->next;
                                }
                                j = j->next;
                                if (j == NULL)
                                        break;
                        }
                        i = i->next;
                }
        }
};

int main()
{
        LinkedList list;

        list.add_element_end(5);
        list.add_element_end(5);
        list.add_element_end(15);
        list.add_element_end(5);
        list.add_element_end(15);

        list.display_list();

        list.remove_duplicates_iteration();

        list.display_list();
        return 0;
}
