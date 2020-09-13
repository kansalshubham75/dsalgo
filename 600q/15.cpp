#include <bits/stdc++.h>
using namespace std;
int max_sum(int arr[],int n)
{
    /*Solution : for any array : a b c d,
    the sum of elements is : a+b+c+d
    sum of i*arr[i]:0*a + 1*b + 2*c + 3*d
    in order to calculate the sum for next rotation, we can just  add sum of elements to the sum of i*arr[i]
    and then subtract n times the first element of the next rotation (last element of current rotation)
    sum of next rotation->   0*a + 1*b + 2*c + 3*d + (a+b+c+d) - 4*d
                        ->   0*d + 1*a + 2*b + 3*c
    */
    int sum=0,tsum=0;
    for(int i=0;i<n;i++){       
        sum+=arr[i];        
        tsum+=(i*arr[i]);
    }
    int max_=tsum;
    for(int i=n-2;i>=0;i--){
        tsum=tsum+sum-(n*arr[i+1]);
        max_=max(max_,tsum);
    }
    return max_;
}
void solve(){
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}