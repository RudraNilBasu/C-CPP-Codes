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
        {}

        public void deleteAtPos(int pos)
        {}

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
