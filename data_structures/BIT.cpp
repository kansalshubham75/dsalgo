#include <bits/stdc++.h>
using namespace std;
class BIT{
    private : 
    int sum(int i){     //get prefix sum [1.....i]
        int ans=0;
        i+=1;
        while(i>0){
            ans+=bit[i];
            i-=(i&-i);
        }
        return ans;
    }
    public:
    int size;
    vector<int> bit;
    BIT(int n){
        size=n+1;
        bit.resize(size,0);
    }
    void update(int i,int delta){
        i+=1;
        while(i<size){
            bit[i]+=delta;
            i+=(i&-i);
        }
    }
    
    int rangeSum(int l,int r){      //range sum[l....r]
        return sum(r)-sum(l-1);
    }
};

int main(){
    BIT b(5);
    vector<int> arr{5,6,4,2,8};
    for(int i=0;i<5;i++)b.update(i,arr[i]);
    cout<<b.rangeSum(2,4);
    return 0;
}