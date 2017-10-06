import java.util.*;

class Node
{
        protected int data;
        protected Node link;

        public Node()
        {
                data = 0;
                link = null;
        }

        public Node(int _data, Node _link)
        {
                data = _data;
                link = _link;
        }

        public void setData(int _data)
        {
                data = _data;
        }

        public void setLink(Node _link)
        {
                link = _link;
        }

        public int getData()
        {
                return data;
        }

        public Node getLink()
        {
                return link;
        }
}

class LinkedList
{
        Node start;
        int size;

        public LinkedList()
        {
                start = null;
                size = 0;
        }

        public boolean isEmpty()
        {
                return size == 0;
        }

        public int getSize()
        {
                return size;
        }

        public void insertAtStart(int val)
        {
                Node n = new Node(val, start.link);
                start = n;
        }

        public void insertAtEnd(int val)
        {
                Node newNode = new Node(val, null);
                Node n = start;
                while (n.link != null)
                        n = n.link;
                n.link = newNode;
        }

        public void insertAtPos(int val, int pos)
        {
                if (pos > getSize()) {
                        System.out.println("OutOfBounds");
                        return;
                }

                int currentPos = 0;
                Node n = start;
                while (currentPos != pos - 1) {
                        n = n.next;
                        currentPos++;
                }
                Node newNode = new Node(val, n.next);
                n.next = newNode;
        }

        public void deleteAtPos(int pos)
        {
                if (pos > getSize()) {
                        System.out.println("OutOfBounds");
                        return;
                }

                int currentPos = 0;
                Node n = start;
                while (currentPos != pos - 1) {
                        n = n.next;
                        currentPos++;
                }
                n.next = n.next.next;
        }

        public void display()
        {
                if (isEmpty()) {
                        System.out.println("List is empty");
                        return;
                }

                Node n = start;
                while (n != null) {
                        System.out.print(n.data + " ");
                }
                System.out.println();
        }
}

class SinglyLinkedList
{
        public static void main(String args[])
        {
                Scanner sc = new Scanner();
        }
}
