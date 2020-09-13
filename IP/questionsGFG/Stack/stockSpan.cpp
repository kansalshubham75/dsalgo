#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define ll long long int
using namespace std;
void dailyTemperatures()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // int n = arr.size();
    vector<int> ans(n, 0);
    stack<int> st;
    int i = n - 1;
    while (i >= 0)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            int idx = st.top();
            st.pop();
            ans[idx] = idx - i;
        }

        st.push(i);
        i++;
    }
    for(int i:ans)
    cout<<i<<" ";
    cout<<endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        dailyTemperatures();
    }
    return 0;
}