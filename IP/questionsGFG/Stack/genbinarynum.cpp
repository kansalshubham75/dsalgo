#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i = 1;
        queue<string> q;
        q.push("1");
        while (i <= n)
        {
            string str = q.front();
            q.pop();
            cout << str << " ";
            q.push(str + "0");
            q.push(str + "1");
            i += 2;
        }
        while (!q.empty() && q.size() > i - n)
        {
            cout << q.front() << " ";
            q.pop();
        }
        // cout<<q.size();
        cout << endl;
    }

    return 0;
}