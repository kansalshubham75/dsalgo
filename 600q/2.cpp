#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum = 0, i = 0, j = 0;
    while (j < n)
    {
        if (sum < t)
        {
            sum += arr[j];
            j++;
        }
        while (sum > t)
        {
            if (i < j)
            {
                sum -= arr[i];
            }
            else
            {
                sum = 0;
                j++;
            }
            i++;
        }
        if (sum == t)
        {
            cout << i + 1 << " " << j << endl;
            return;
        }
    }
    cout << -1 << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}