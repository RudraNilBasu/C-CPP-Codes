import java.io.*;

class Node
{
        public int value;
        public Node next = null;
        public Node(int _value)
        {
                value = _value;
        }
}

class Test
{
        public static void main(String args[]) throws IOException
        {
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                Node list = null;
                while (true) {
                        System.out.println("1. Insert at end");
                        System.out.println("2. Display");
                        System.out.println("3. Delete");
                        int choice = Integer.parseInt(br.readLine());
                        if (choice == 1) {
                                System.out.print("Enter the data to be inserted: ");
                                int data = Integer.parseInt(br.readLine());
                                Node end = new Node(data);
                                Node n = list;
                                if (n == null) {
                                        n = end;
                                        list = end;
                                } else {
                                        while (n.next != null)
                                                n = n.next;
                                        n.next = end;
                                }
                        } else if (choice == 2) {
                                System.out.println("The List is:");
                                System.out.println("----------");
                                Node n = list;
                                if (n == null) {
                                        System.out.println("Empty");
                                        continue;
                                }
                                while(n != null) {
                                        System.out.print(n.value + " ");
                                        n = n.next;
                                }
                                System.out.println();
                                System.out.println("----------");
                        } else if (choice == 3) {
                                System.out.print("Enter the data to be deleted: ");
                                int data = Integer.parseInt(br.readLine());
                                Node head = list;
                                if (head == null) {
                                        System.out.println("List Empty");
                                        continue;
                                }
                                if (head.value == data) {
                                        list = list.next;
                                        System.out.println("Deleted from HEAD: " + data);
                                        continue;
                                }
                                while (head.next != null) {
                                        if (head.next.value == data) {
                                                head.next = head.next.next;
                                                System.out.println("Deleted: " + data);
                                        } else {
                                                head = head.next;
                                        }
                                }
                        }
                }
        }
}
