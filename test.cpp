#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector

class BIT{
    public:
    int size;
    vector<int> bit;
    BIT(int n){
        size=n+1;
        bit.assign(size,0);
    }
    int sum(int i){     //get prefix sum [1.....i]
        int ans=0;
        while(i>0){
            ans+=bit[i];
            i-=(i&-i);
        }
        return ans;
    }
    void update(int i,int delta){
        while(i<size){
            bit[i]+=delta;
            i+=(i&-i);
        }
    }
    
    int rangeSum(int l,int r){      //range sum[l....r]
        return sum(r)-sum(l-1);
    }
};


int bSearch(int lo,ll val,vector<ll>& arr){
	int hi=arr.size()-1;
	while(lo<hi){
		int mid=lo+((hi-lo)/2);
		if(arr[mid]<val){
			lo=mid+1;
		}else{
			hi=mid;
		}
	}
	return hi;
}
int main(){
	int n,k;
	cin>>n>>k;
	vc<int> arr(n);
	for(int &a:arr)cin>>a;
	vector<int> original_array(n);
    for(int i=0;i<n;i++)original_array[i]=arr[i];
	sort(arr.begin(),arr.end());
	unordered_map<int,int> m;
	int i=1,val=1;
	m[arr[0]]=1;
	for(;i<n;i++){
		if(arr[i]!=arr[i-1])val++;
		m[arr[i]]=val;
	}
    // for(int i=0;i<n;i++)cout<<m[arr[i]]<<" ";
    // cout<<endl;
	BIT bit(val);
    // for(int i=0;i<n;i++)cout<<m[arr[i]]<<" ";
	for(i=0;i<n;i++){
		bit.update(m[arr[i]],1);
	}
	vector<ll> bigger(n,0);
	for(int i=0;i<n;i++){
		bigger[i]=bit.rangeSum(m[original_array[i]]+1,val);
		bit.update(m[original_array[i]],-1);
	}
    ll ans=0;
	sort(bigger.begin(),bigger.end());
    // cout<<bSearch(8,bigger);
    // for(int i:bigger)cout<<i<<" ";
	for(int i=0;i<n;i++){
        // cout<<bigger[i]<<" ";
		ll search_val=k-bigger[i];
		int idx=bSearch(i+1,search_val,bigger);
        if(bigger[idx]<search_val || idx==i)idx++;
        // cout<<n-idx<<endl;
		ans+=(n-idx);
	}
	cout<<ans;
	return 0;
}