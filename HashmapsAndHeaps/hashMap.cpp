#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solve(vector<vector<int>> &q, int k)
{
    vector<int> cakes(10, 0);
    int count = 0;
    for (vector<int> a : q)
    {
        cakes[a[0]]++;
        if (a[1] != 9)
            cakes[a[1] + 1]--;
    }
    vector<int> kc(10, 0);
    vector<int> kp1(10, 0);
    for (int i = 1; i < 10; i++)
    {
        cakes[i] += cakes[i - 1];

        if (cakes[i] == k)
            count++;

        kc[i] = cakes[i] == k ? kc[i - 1] + 1 : kc[i - 1];
        kp1[i] = cakes[i] == k + 1 ? kp1[i - 1] + 1 : kp1[i - 1];
        cout<<kc[i]<<" "<<kp1[i]<<endl;
    }
    int max_ = -(1e8);
    for (vector<int> a : q)
    {
        int dk = kc[a[1]] - (a[0] == 0 ? 0 : kc[a[0] - 1]);
        int ik = kp1[a[1]] - (a[0] == 0 ? 0 : kp1[a[0] - 1]);
        // cout<<dk<<" "<<ik<<endl;
        max_ = max(max_, count + ik - dk);
    }
    return max_;
}
int main()
{
    
        vector<vector<int>> q={{2,6},{4,9},{1,4}};
        // for (vector<int> a : q)
        // {
        //     cin >> a[0] >> a[1];
        // }

        cout << solve(q, 2) << endl;
    
    return 0;
}
