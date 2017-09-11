#include <stdio.h>

using namespace std;

class Node
{
        private:
                int value;
                Node* link;
        public:
                Node() {}

                int getValue();
                Node* getLink();
                void setValue(int _value, Node*_link);
                void setLink(Node* _link);
};

int Node::getValue()
{
        return value;
}

Node* Node::getLink()
{
        return link;
}

void Node::setValue(int _value, Node* _link)
{
        value = _value;
        link = _link;
}

void Node::setLink(Node* _link)
{
        link = _link;
}

class LinkedList
{
public:
        Node *head;
        LinkedList()
        {
                head = NULL;
        }
        void add_end(int value);
        void display();
        void delete_end();
};

void LinkedList::add_end(int value)
{
        Node *n = head;
        while (n->getLink() != NULL) {
                n = n->getLink();
        }
        Node newNode;
        newNode.setValue(value, NULL);
        n->setLink(&newNode);
}

void LinkedList::display()
{
        Node *n = head;
        printf("-----\n");
        while (n != NULL)
        {
                printf("%d\t", n->getValue());
        }
        printf("\n");
        printf("-----\n");
}

void LinkedList::delete_end()
{
        Node* n = head;

        if (n->getLink() == NULL) {
                head = NULL;
        }

        while ((n->getLink())->getLink() != NULL) {
                n = n->getLink();
        }
        n->setLink(NULL);
}

int main()
{
        return 0;
}
