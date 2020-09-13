#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(){
    
}


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
        int n,q;
        cin>>n>>q;
        char ch;
        vector<int> freq(26,0);
        int max_=0;
        for(int i=0;i<n;i++){
            cin>>ch;
            int idx=(int)(ch-'a');
            freq[idx]++;
            max_=max(max_,freq[idx]);
        }
        for(int i=0;i<q;i++){
            int c,res=0;
            cin>>c;
            if(c<max_){
                for(int i:freq)
                    res+=i<=c?0:i-c;
            }
            cout<<res<<endl;
        }

	}
	return 0;
}
