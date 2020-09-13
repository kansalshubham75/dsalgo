import java.util.NoSuchElementException;

public class linkedlist {
    public class Node {
        int data;
        Node next;

        public Node(int data) {
            this.data = data;
        }

        public String toString() {
            return (this.data + "");
        }
    }

    Node head;
    Node tail;
    int size;

    public linkedlist() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    // ========================UTIL=======================
    @Override
    public String toString(){
        if(this.size==0) return "";
        StringBuilder sb=new StringBuilder();
        Node n=this.head;
        while(n.next!=null){
            sb.append(n.data+" -> ");
            n=n.next;
        }
        sb.append(n.data);
        return sb.toString();
    }

    public int size() {
        return this.size;
    }

    public boolean isEmpty() {
        return this.size == 0;
    }

    private Node getNodeAt(int idx) {
        if (idx < 0 || idx >= this.size)
            throw new NullPointerException();
        if (idx == 0)
            return this.head;
        if (idx == this.size - 1)
            return this.tail;
        Node temp = head;
        while (idx-- != 0) {
            temp = temp.next;
        }
        return temp;
    }

    private Node getMidNode(){
        
    }
    // ====================================ADD=================================
    private void addFirstNode(Node node) {
        if (this.size == 0) {
            this.tail = node;
        } else
            node.next = head;
        head = node;
        size++;
    }

    public void addFirst(int data) {
        Node node = new Node(data);
        addFirstNode(node);
    }

    private void addLastNode(Node node) {
        if (this.size == 0) {
            this.head = node;
        } else
            tail.next = node;
        tail = node;
        size++;
    }

    public void addLast(int data) {
        Node node = new Node(data);
        addLastNode(node);
    }

    private void addAtNode(Node node, int idx) {
        Node prev = getNodeAt(idx - 1);
        node.next = prev.next;
        prev.next = node;
        this.size++;
    }

    public void addAt(int data, int idx) {
        if (idx < 0 || idx > size)
            throw new NullPointerException();
        if (idx == 0)
            addFirst(data);
        if (idx == this.size)
            addLast(data);

        Node node = new Node(data);
        addAtNode(node, idx);
    }

    // =============================== GET===================================
    public Node getFirst() {
        if (this.size() == 0)
            throw new NoSuchElementException();
        return this.head;
    }

    public Node getLast() {
        if (this.size() == 0)
            throw new NoSuchElementException();
        return this.tail;
    }

    public Node getAt(int idx) {
        if (this.size() == 0)
            throw new NoSuchElementException();
        return getNodeAt(idx);
    }

    // ======================REMOVE===========================================

    private Node removeFirstNode() {
        if (this.size == 0)
            this.tail = null;
        Node temp = head;
        head = head.next;
        temp.next = null;
        this.size--;
        return temp;
    }

    public int removeFirst() {
        if (this.size() == 0)
            throw new NoSuchElementException();

        return removeFirstNode().data;
    }

    private Node removeLastNode() {
        if (this.size == 1)
            head = null;
        Node temp = tail;
        tail = tail.next;
        temp.next = null;
        this.size--;
        return temp;
    }

    public int removeLast() {
        if (this.size() == 0)
            throw new NoSuchElementException();

        return removeLastNode().data;
    }

    private Node removeAtNode(int idx) {
        Node prev = getNodeAt(idx - 1);
        Node rnode = prev.next;
        prev.next = rnode.next;
        rnode.next = null;
        this.size--;
        return rnode;
    }

    public int removeAt(int idx) {
        if (this.size() == 0)
            throw new NoSuchElementException();

        if (idx < 0 || idx >= this.size)
            throw new NullPointerException();

        if (idx == 0)
            return removeFirst();

        if (idx == size - 1)
            return removeLast();

        return removeAtNode(idx).data;
    }
}