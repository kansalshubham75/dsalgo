public class dynamicQueue extends queue{
    public dynamicQueue(){
        resize(10);
    }
    public dynamicQueue(int size){
        resize(size);
    }
    @Override
    public void push(int val){
        if(size()==capacity()){
            for(int i=0;i)
        }
    }
}