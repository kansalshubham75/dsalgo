#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define ll long long int
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<ll> ans(n, -1);
    stack<int> st;
    int i = 0;
    while (i < n)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            int idx = st.top();
            st.pop();
            ans[idx] = arr[i];
        }

        st.push(i);
        i++;
    }
    for (ll i : ans)
        cout << i << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}