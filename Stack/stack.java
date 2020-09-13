
public class stack {
    private int arr[];
    private int size = 0;
    private int tos = -1;

    public stack() {
        resize(10);
    }

    public stack(int size) {
        resize(size);
    }
    protected void reassign(int[] temp){
        arr=temp;
    }
    protected void resize(int size) {
        arr = new int[size];
        this.size = 0;
        this.tos = -1;
    }

    public int maxSize() {
        return this.arr.length;
    }

    protected void push_(int e) {
        arr[++tos] = e;
        this.size++;
    }

    public void push(int e) throws Exception {
        if (Size() == maxSize()) {
            throw new Exception("Overflow");
        }
        push_(e);
    }

    protected int top_() {
        return arr[tos];
    }

    public int top() throws Exception {
        if (size == 0)
            throw new Exception("Empty Stack");
        return top_();
    }

    protected void pop_() {
        this.arr[tos--]=0;
        this.size--;
    }

    public void pop() throws Exception {
        if (size == 0)
            throw new Exception("Empty Stack");
        pop_();
    }

    public int Size() {
        return this.size;
    }

    public boolean isEmpty() {
        return this.size == 0;
    }
}