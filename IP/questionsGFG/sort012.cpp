#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(vector<int> &arr)
{
    int i = -1, k = arr.size();
    while (i < k && arr[i + 1] == 0)
        i++;
    cout << i << endl;
    int j = i + 1;
    while (k > 0 && arr[k - 1] == 2)
        k--;
    cout << k << endl;
    while (j < k)
    {   
        // cout<<"i : "<<i<<" j :"<<j<<" k : "<<k<<endl;
        if (arr[j] == 1)
        {
            j++;
        }
        else if (arr[j] == 0)
        {
            if(j==i+1){
                j++;
                continue;
            }
            i++;
            swap(arr[i], arr[j]);
        }
        else
        {
            if(j==k-1){
                j++;
                continue;
            }
            k--;
            swap(arr[k], arr[j]);
        }
    }
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        solve(arr);
    }
    return 0;
}