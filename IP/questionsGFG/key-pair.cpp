#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        unordered_map<int,int> arr;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            arr[a]++;
        }
        bool found = false;
        for(pair<int,int> p:arr){
            if(x-p.first==p.first){
                if(p.second>1){
                found=true;
                break;
                }
            }else{
                if(arr.find(x-p.first)!=arr.end()){
                    found=true;
                    break;
                }
            }
        }
        string ans = found ? "YES" : "NO";
        cout << ans << endl;
    }
    return 0;
}