#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(int arr[], int n, int k)
{
    int i = n - 1;
    vector<int> ans(n - k + 1, 0);
    int neg = n;
    while (i >= 0)
    {
        if (arr[i] < 0)
            neg = i;
        if (i < n - k + 1 && neg < i + k)
            ans[i] = arr[neg];
        i--;
    }
    for (int i : ans)
        cout << i << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        solve(arr, n, k);
    }
    return 0;
}