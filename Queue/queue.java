public class queue{
    protected int[] q;
    protected int front=0;
    protected int rear=0;
    protected int size;
    public queue(){
        resize(10);
    }
    public queue(int size){
        resize(size);
    }
    protected void resize(int size){
        q=new int[size];
        front=0;
        rear=0;
        this.size=0;
    }
    // public void display(){
        
    // }
    public boolean isEmpty(){
        return size==0;
    }
    public int size(){
        return this.size;
    }

    public int capacity(){
        return this.q.length;
    }
    protected void push_(int val){
    q[rear]=val;
    rear=(rear+1)%capacity();
    size++;
}
    public void push(int val) throws Exception{
        if(capacity()==size()){
            throw new Exception("Overflow");
        }
        push_(val);
    }
    protected void pop_(){
        q[front]=0;
        front=(front+1)%capacity();
        size--;
    }
    public int pop() throws Exception{
        if(size()==0){
            throw new Exception("Underflow");
        }
        pop_();
    }

    public int top() throws Exception{
        if(size==0){
            throw new Exception("Empty Queue");
        }
        return q[front];
    }
}