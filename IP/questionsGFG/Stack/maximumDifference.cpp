#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int findMaxDiff(int arr[], int n)
{
    stack<int> st;
    vector<int> nsol_(n,0);
    vector<int> nsor(n,0);
    int i = 0;
    int max_=0;
    while (i < n)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            nsor[st.top()]=arr[i];
            int top=st.top();
            st.pop();
            int nsol=st.empty()?0:arr[st.top()];
            nsol_[top]=nsol;
            max_=max(max_,abs(arr[i]-nsol));
        }
        st.push(i);
        i++;
    }
    if(!st.empty()){
        int idx=st.top();
        st.pop();
        nsol_[idx]=st.top();
        int nsol=arr[st.top()];
        max_=max(max_,abs(nsol));
        st.pop();
    }

    for(int i:nsor)
        cout<<i<<" ";
    cout<<endl;
    for(int i:nsol_)
        cout<<i<<" ";
    cout<<endl;
   return max_;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<findMaxDiff(arr,n);
    }
    return 0;
}