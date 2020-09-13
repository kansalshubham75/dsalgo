#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void solve(string &s)
{
    stack<char> st;
    int i = 0;
    while (i < s.length())
    {
        if (s[i] == '}' && !st.empty() && st.top() == '{')
        {
            st.pop();
            i++;
            continue;
        }
        st.push(s[i]);
        i++;
    }
    int ob = 0, cb = 0;
    while (!st.empty())
    {
        if (st.top() == '{')
            ob++;
        else
            cb++;
        st.pop();
    }
    int ans = 0;
    if ((ob + cb) & 1)
        ans = -1;
    else
    {
        ans = ob / 2 + cb / 2;
        if (ob & 1)
            ans++;
        if (cb & 1)
            ans++;
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}