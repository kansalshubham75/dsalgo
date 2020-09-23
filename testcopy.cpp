#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    //index 0->freq,1->first occ,2=last occ
    unordered_map<int,vector<int>> m;
    int max_=0;
    for(int i=0;i<n;i++){
        if(m.find(arr[i])==m.end()){
            m[arr[i]].assign(3,0);
            m[arr[i]][1]=i;
        }
        m[arr[i]][0]++;
        m[arr[i]][2]=i;
        if(max_<m[arr[i]][0]){
            max_=m[arr[i]][0];
        }
    }
    int s=n,si,ei;
    for(auto& e:m){
        if(e.second[0]==max_){
            if((e.second[2]-e.second[1]+1)<s){
                s=(e.second[2]-e.second[1]+1);
                si=e.second[1];
                ei=e.second[2];
            }else if((e.second[2]-e.second[1]+1)==s && e.second[1]<si){
                si=e.second[1];
                ei=e.second[2];
            }
        }
    }
    for(int i=si;i<=ei;i++)cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}