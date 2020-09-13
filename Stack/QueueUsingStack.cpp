#include <iostream>
#include <stack>
using namespace std;
class que
{
    stack<int> st;
public:
    void push_(int val){         //O(1)
        st.push(val);
    }
    int pop_(){
        if(st.empty()){
            return 0;
        }                  //O(n)
        stack<int> st2;
        while(st.size()>1){
            // cout<<"push in st2"<<st.top()<<endl;
            st2.push(st.top());
            st.pop();
        }
        // cout<<"in res "<<st2.top()<<endl;
        int res=st.top();
        st.pop();
        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
        return res;
    }
    bool empty_(){
        return st.empty();
    }

    int size_(){
        return st.size();
    }
};
int main(){
    que q;
    q.push_(10);
    q.push_(20);
    cout<<q.pop_()<<endl<<q.pop_();
    return 0;
}