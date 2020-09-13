public class dynamicStack extends stack{
    public dynamicStack(){
        resize(10);
    }
    public dynamicStack(int size){
        resize(size);
    }
    @Override
    public void push(int val) throws Exception{
        if(Size()==maxSize()){
            int[] temp=new int[Size()];
            for(int i=temp.length-1;i>=0;i--){
                temp[i]=top();
                pop();
            }
            resize(2*temp.length);
            for(int i: temp){
                push_(i);
            }
        }
        super.push(val);
    }
    // @Override
    // public void push(int val) throws Exception{
    //     if(Size()==maxSize()){
    //         int[] temp=new int[Size()*2];
    //         for(int i=temp.length-1;i>=0;i--){
    //             temp[i]=top();
    //             pop();
    //         }
    //         reassign(temp);
    //         // resize(2*temp.length);
    //         // for(int i: temp){
    //         //     push_(i);
    //         // }
    //     }
    //     super.push(val);
    // }
}