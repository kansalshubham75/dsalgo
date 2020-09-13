#include<bits/stdc++.h>
using namespace std;

pair<int, int> memo(vector<int>& arr, vector<vector<pair<int, int>>>& dp, int i, int j) {
    if (i>j) return { 0, 0 };
    if (i==j && i<arr.size()) return dp[i][j] ={ arr[i], 0 };
    if (dp[i][j].first != -1) return dp[i][j];

    pair<int, int> ans ={ INT_MAX, INT_MAX }; // current val, final cost

    for (int k=i;k<j;k++) {
        auto la = memo(arr, dp, i, k);
        auto ra = memo(arr, dp, k+1, j);

        if (ans.second >(la.first+ra.first+la.second + ra.second)) {
            ans.first = la.first+ra.first;
            ans.second = la.first+ra.first+la.second+ra.second;
        }

    }

    return dp[i][j] = ans;
}

int main() {
    vector<int> arr ={ 3, 2, 4, 1 };
    vector<vector<pair<int, int>>> dp(arr.size()+1, vector<pair<int, int>>(arr.size()+1, { -1, -1 }));
    auto a = memo(arr, dp, 0, arr.size()-1);
    for (auto i:dp) {
        for (auto j:i) cout<<" {"<<j.first<<" , "<<j.second<<"} ";
        cout<<endl;
    }
    cout<<a.second<<endl;
    return 0;
}
