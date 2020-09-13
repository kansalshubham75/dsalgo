#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int find(vector<int>& par,int u){
    if(par[u]==u)
        return u;
    
    int res=find(par,par[u]);
    par[u]=res;
    
    return res;
}

void merge(int p1,int p2,vector<int>& size,vector<int>& par){
    if(size[p1]<size[p2]){
        par[p1]=p2;
        size[p2]+=size[p1];
    }else{
        par[p2]=p1;
        size[p1]+=size[p2];
    }
}
int solve(vector<int>& arr){
    vector<int> par(15,0);
    vector<int> size(15,0);
    for(int i=1;i<arr.size();i++){
        par[arr[i]]=arr[i];
        size[arr[i]]=1;
    }
    

    for(int i=2;i<arr.size();i++){
        if(arr[i]-arr[i-1]<=2){
            int p1=find(par,arr[i]);
            int p2=find(par,arr[i-1]);
            merge(p1,p2,size,par);
        }
    }
    int min_=1e8,max_=1;
    for(int i=1;i<arr.size();i++){
        if(arr[i]==par[arr[i]]){
            max_=max(max_,size[arr[i]]);
            min_=min(min_,size[arr[i]]);
        }
    }
    
    cout<<min_<<" "<<max_<<endl;
    
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
        // cout<<endl<<"n:"<<n<<endl;
	    vector<int> arr(n+1);
	    for(int i=1;i<n+1;i++){
	        cin>>arr[i];
	    }
        // for(int i:arr)
        //     cout<<i<<" ";
	    solve(arr);
	}
	return 0;
}
