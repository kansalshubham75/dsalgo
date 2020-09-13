public class client{
    public static void main(String[] args) throws Exception {
        dynamicStack st=new dynamicStack(2);
        st.push(10);
        st.push(20);
        int size=st.Size();
        for(int i=0;i<size;i++){
            System.out.println(st.top());
        }
        System.out.println("size:"+size);
        st.push(4);
        System.out.println(st.top());
        size=st.Size();
        System.out.println("size:"+size);
        System.out.println("maxsize:"+st.maxSize());

    }
}