#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
void read(vector<int>& arr){
    for(int i=0;i<arr.size();i++)
        cin>>arr[i];
}
//abcabc
//1  1  1
void solve(string& s,int k){
    int n=s.length(),j=0,cnt=0;
    if(k>n)return;
    unordered_map<char,int> freq;
    unordered_set<string> taken;
    for(int i=0;i<k-1;i++)freq[s[i]]++;
    for(int i=k-1;i<n;i++){
        freq[s[i]]++;
        if(freq.size()==k){
            string window=s.substr(j,i-j+1);
            taken.insert(window);
        }
        if(--freq[s[j]]==0)freq.erase(s[j]);
        j++;
    }
    for(auto& sub:taken)cout<<sub<<endl;
    cout<<taken.size();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--){
        string str="awaglknagawunagwkwagl";
        int k=4;
        solve(str,k);
    }
    return 0;
}

// freq[s[j]-'a']++;
//         while(freq[s[j]-'a']>1){
//             freq[s[i]-'a']--;
//             i++;
//         }
//         if(j-i+1==k){
//             string window=s.substr(i,j-i+1);
//             freq[s[i]-'a']--;
//             i++;
//             if(taken.find(window)==taken.end())continue;
//             taken.insert(window);
//             cout<<window<<endl;
//             cnt++;
//         }
//         j++;