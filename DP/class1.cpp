#include <iostream>
#include <vector>
#include <list>
using namespace std;

//===========================Util===========================================

// int fib_helper(){
//     if()
// }
// int fib(int n){
//     int a[2][2]={{1,1},{1,0}};

// }
void display2D(vector<vector<int>> &dp)
{
    for (vector<int> v : dp)
    {
        for (int i : v)
            cout << i << " ";
        cout << "\n";
    }
}
//================================MazePath==================================================

//1.Memoized Hvd moves
int mazePathHVD_MEMO(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    if (sr == er && sc == ec)
    {
        dp[sr][sc] = 1;
        return 1;
    }
    if (dp[sr][sc] != 0)
        return dp[sr][sc];
    int count = 0;
    if (sr + 1 <= er)
    {
        count += mazePathHVD_MEMO(sr + 1, sc, er, ec, dp);
    }
    if (sr + 1 <= er && sc + 1 <= ec)
    {
        count += mazePathHVD_MEMO(sr + 1, sc + 1, er, ec, dp);
    }
    if (sc + 1 <= ec)
    {
        count += mazePathHVD_MEMO(sr, sc + 1, er, ec, dp);
    }

    return dp[sr][sc] = count;
}

//2. Tabulated Hvd moves
int mazePathHVD_TAB(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    for (sr = er; sr >= 0; sr--)
    {
        for (sc = ec; sc >= 0; sc--)
        {
            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }

            int count = 0;
            if (sr + 1 <= er)
            {
                count += dp[sr + 1][sc];
            }
            if (sr + 1 <= er && sc + 1 <= ec)
            {
                count += dp[sr + 1][sc + 1];
            }
            if (sc + 1 <= ec)
            {
                count += dp[sr][sc + 1];
            }

            dp[sr][sc] = count;
        }
    }
    return dp[0][0];
}

//3. Multi jump hvd Memoized
int mazePathHvdMulti_memo(int sr, int sc, int er, int ec, vector<vector<int>> &dp, int rad)
{
    if (sr == er && sc == ec)
    {
        dp[sr][sc] = 1;
        return 1;
    }
    if (dp[sr][sc] != 0)
        return dp[sr][sc];
    int count = 0;
    for (int i = 1; i <= rad; i++)
    {
        if (sr + i <= er)
        {
            count += mazePathHvdMulti_memo(sr + i, sc, er, ec, dp, rad);
        }
        if (sr + i <= er && sc + i <= ec)
        {
            count += mazePathHvdMulti_memo(sr + i, sc + i, er, ec, dp, rad);
        }
        if (sc + i <= ec)
        {
            count += mazePathHvdMulti_memo(sr, sc + i, er, ec, dp, rad);
        }
    }
    return dp[sr][sc] = count;
}

//4. Multi jump Hvd Tabulated
int mazePathHVDMulti_TAB(int sr, int sc, int er, int ec, vector<vector<int>> &dp, int rad)
{
    for (sr = er; sr >= 0; sr--)
    {
        for (sc = ec; sc >= 0; sc--)
        {
            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }

            int count = 0;
            for (int i = 1; i <= rad; i++)
            {
                if (sr + i <= er)
                {
                    count += dp[sr + i][sc];
                }
                if (sr + i <= er && sc + i <= ec)
                {
                    count += dp[sr + i][sc + i];
                }
                if (sc + i <= ec)
                {
                    count += dp[sr][sc + i];
                }
            }
            dp[sr][sc] = count;
        }
    }
    return dp[0][0];
}

int pathSeries()
{
    int sr = 0, sc = 0;
    int er = 3, ec = 3;
    vector<vector<int>> dp(er + 1, vector<int>(ec + 1, 0));

    cout << mazePathHvdMulti_memo(sr, sc, er, ec, dp, 3);

    cout << endl
         << endl;

    for (int i = 0; i < er + 1; i++)
    {
        for (int j = 0; j <= ec; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}

//==========================Board Path with dice moves======================================

vector<int> dicemoves = {1, 2, 3, 4, 5, 6};

int boardPath(int sp, int ep)
{
    if (sp == ep)
    {
        return 1;
    }
    int count = 0;
    for (int i = 0; i < dicemoves.size(); i++)
    {
        if (sp + dicemoves[i] <= ep)
            count += boardPath(sp + dicemoves[i], ep);
    }
    return count;
}

int boardPath_memo(int sp, int ep, vector<int> &dp)
{
    if (sp == ep)
    {
        dp[ep] = 1;
        return 1;
    }
    if (dp[sp] != 0)
        return dp[sp];
    int count = 0;
    for (int i = 0; i < dicemoves.size(); i++)
    {
        if (sp + dicemoves[i] <= ep)
            count += boardPath_memo(sp + dicemoves[i], ep, dp);
    }

    dp[sp] = count;
    return count;
}

int boardPath_tab(int sp, int ep, vector<int> &dp)
{

    for (int i = ep; i >= sp; i--)
    {
        if (i == ep)
        {
            dp[ep] = 1;
            continue;
        }
        int count = 0;
        for (int j = 0; j < dicemoves.size(); j++)
        {
            if (i + dicemoves[j] <= ep)
                count += dp[i + dicemoves[j]];
        }
        dp[i] = count;
    }
    return dp[0];
}

int boardPath_tab_O1space(int sp, int ep)
{
    list<int> l;
    l.push_back(1);
    l.push_back(1);
    for (int i = ep - 2; i >= sp; i--)
    {
        l.push_front(l.front() * 2);
        if (l.size() == 8)
        {
            l.push_front(l.front() - l.back() + l.front());
            l.pop_back();
        }
    }
    return l.front();
}

//12/04 partition n objects in k subsets
int partition_N_in_K(int n, int k, vector<vector<int>> &dp)
{
    if (n < k)
        return 0;

    if (n == k || k == 1)
        return dp[n][k] = 1;

    if (dp[n][k] != 0)
        return dp[n][k];
    int createSetWays = partition_N_in_K(n - 1, k - 1, dp);
    int combineWithOthers = k * partition_N_in_K(n - 1, k, dp);

    return dp[n][k] = createSetWays + combineWithOthers;
}

int partition_N_in_K_TAB(int n, int k, vector<vector<int>> &dp)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i < j)
            {
                dp[i][j] = 0;
                continue;
            }
            if (i == j || j == 1)
            {
                dp[i][j] = 1;
                continue;
            }
            int createSetWays = dp[i - 1][j - 1];
            int combineWithOthers = j * dp[i - 1][j];

            dp[i][j] = createSetWays + combineWithOthers;
        }
    }
    return dp[n][k];
}

void partition()
{
    int n = 6, k = 3;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j <= k; j++)
    //         cout << dp[i][j] << " ";
    // }

    cout << partition_N_in_K_TAB(n, k, dp);

    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j <= k; j++)
    //         cout << dp[i][j] << " ";
    // }
}

//===================================Palindrome Set===================================//

vector<vector<bool>> isPalindromicSubstring(string str)
{
    int n = str.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int gap = 0; gap < n; gap++)
    {
        for (int si = 0, ei = gap; ei < n; si++, ei++)
        {
            if (gap == 0)
                dp[si][ei] = true;
            else if (gap >= 1 && str[si] == str[ei])
            {
                if (gap == 1)
                    dp[si][ei] = true;
                else if (dp[si + 1][ei - 1] == true)
                    dp[si][ei] = true;
            }
        }
    }
    return dp;
}

int longestPalindromicSubstring_Memo(string str, int si, int ei, vector<vector<int>> &dp)
{
    if (si - ei == 0)
        return dp[si][ei] = 1;
    if (ei - si == 1 && str[si] == str[ei])
        return dp[si][ei] = 2;
    if (si > ei)
        return dp[si][ei] = 0;

    if (dp[si][ei] != 0)
        return dp[si][ei];
    if (str[si] == str[ei])
    {
        int len = longestPalindromicSubstring_Memo(str, si + 1, ei - 1, dp);
        if (len > 0)
            dp[si][ei] = len + 2;
    }
    else
    {
        longestPalindromicSubstring_Memo(str, si + 1, ei, dp);
        longestPalindromicSubstring_Memo(str, si, ei - 1, dp);
    }
    return dp[si][ei];
}

int longestPalindromicSubstring_Tab(string str)
{
    int n = str.length();
    int maxLen = 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int gap = 0; gap < n; gap++)
    {
        for (int si = 0, ei = gap; ei < n; si++, ei++)
        {
            if (gap == 0)
                dp[si][ei] = 1;
            else if (gap >= 1 && str[si] == str[ei])
            {
                if (gap == 1)
                    dp[si][ei] = 2;
                else if (dp[si + 1][ei - 1] > 0)
                    dp[si][ei] = dp[si + 1][ei - 1] + 2;
            }
            maxLen = max(maxLen, dp[si][ei]);
        }
    }
    display2D(dp);
    return maxLen;
}

void palindromeSeries()
{
    string str = "abccbdef";
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // vector<vector<bool>> dp=isPalindromicSubstring("abccbdef");
    longestPalindromicSubstring_Memo(str, 0, n - 1, dp);
    display2D(dp);
}

//====================================Coin change===================================//
int permutationInfy(vector<int> &coins, int tar)
{
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= tar; i++)
    {
        for (int c : coins)
        {
            if (i - c >= 0)
                dp[i] += dp[i - c];
        }
    }
    return dp[tar];
}

int InfyComb(vector<int> &coins, int tar)
{
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;
    for (int c : coins)
    {
        for (int i = 1; i <= tar; i++)
        {
            if (i - c >= 0)
                dp[i] += dp[i - c];
        }
    }
    return dp[tar];
}

int combSingleMemo(vector<int>& coins,int tar,int idx){

}
void coinChange()
{
    vector<int> coins = {2, 3, 5, 7};
    int tar = 10;
    // cout<<permutationInfy(coins,tar);
    cout << InfyComb(coins, tar);
}

//==============================LIS======================================//
int lis(vector<int>& arr,vector<int>& dp){      //O(n^2)
    int maxLen=1;
    dp[0]=1;
    for(int i=1;i<arr.size();i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],dp[j]);
            }
        }
        dp[i]++;
        maxLen=max(maxLen,dp[i]);
    }
    for(int i:dp)
        cout<<i<<" ";
    return maxLen;
}

//LIS O(nLogn)
 int binarySearch(vector<int> arr,int num){
        int l=0,r=arr.size()-1;
        int idx=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]<=num){
                idx=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        if(idx+1<arr.size() && arr[idx]!=num && arr[idx+1]>num)
            idx++;
        return idx;
    }
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int> I(nums.size()+1,1e8);
        I[0]*=-1;
        int max_=1,index=-1;
        vector<int> lis(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            int idx = binarySearch(I,nums[i]);
            I[idx]=nums[i];
            lis[i]=idx;
            max_=max(max_,idx);
            index=i;
        }
        cout<<nums[index]<<" ";
        for(int i=index;i>=0;i--){
            if(nums[i]<nums[index] && lis[i]==lis[index]-1){
                cout<<nums[i]<<" ";
                index=i;
            }
        }
        return max_;
    }

    
//LDS
int Lds(vector<int>& arr,vector<int>& dp){      //O(n^2)  
    int maxLen=1;
    dp[0]=1;
    for(int i=1;i<arr.size();i++){
        for(int j=0;j<i;j++){
            if(arr[i]<arr[j]){
                dp[i]=max(dp[i],dp[j]);
            }
        }
        dp[i]++;
        maxLen=max(maxLen,dp[i]);
    }
    return maxLen;
}

int Lds_01(vector<int>& arr,vector<int>& dp){      //O(n^2)
    int maxLen=1;
    dp[arr.size()-1]=1;
    for(int i=arr.size()-2;i>=0;i--){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],dp[j]);
            }
        }
        dp[i]++;
        maxLen=max(maxLen,dp[i]);
    }
    return maxLen;
}
int maxSumIncSubseq(vector<int>& arr, vector<int>& dp){
    dp[0]=arr[0];
    int max_=dp[0];
    for(int i=1;i<arr.size();i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],dp[j]);
            }
        }
        dp[i]+=arr[i];
        max_=max(max_,dp[i]);
    }
    return max_;
}

void bitonicSeq(vector<int>& arr){
        int n=arr.size();
	   
	    
	    vector<int> dp1(n,0);
	    vector<int> dp2(n,0);
	   // vector<int> dp3(n,0);
	    lis(arr,dp1);
	    Lds_01(arr,dp2);
	    int max_=0;
	    for(int i=0;i<n;i++){
	        max_=max(max_,(dp1[i]+dp2[i]-1));
	    }
	    cout<<max_<<endl;
}

void reverseBitonicSeq(vector<int>& arr){
        int n=arr.size();
        vector<int> ldsArr(n,0);
	    vector<int> lisArr(n,0);
        Lds(arr,ldsArr);


}

int minDeletionsToMakeArraySorted(vector<int>& arr,vector<int>& dp){
    int maxLen=1;
    dp[0]=1;
    for(int i=1;i<arr.size();i++){
        for(int j=0;j<i;j++){
            if(arr[i]>=arr[j]){
                dp[i]=max(dp[i],dp[j]);
            }
        }
        dp[i]++;
        maxLen=max(maxLen,dp[i]);
    }
    return arr.size()-maxLen;
}
void LISset(){
    vector<int> arr={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    // vector<int> arr={1,2,5,3,2};
    // vector<int> arr={1,11,2,0,4,5,2,1};
    // vector<int> dp(arr.size(),0);

    // cout<<lis(arr,dp);
    // cout<<Lds_01(arr,dp);
    // bitonicSeq(arr);

}

int MatrixChain(vector<int>& a,int s,int e,vector<vector<int>>& dp){
    if(s+1==e)
        return dp[s][e]=0;
    if(dp[s][e]!=-1)
        return dp[s][e];
    int min_=2147483647;
    for(int cut=s+1;cut<e;cut++){
        int left=MatrixChain(a,s,cut,dp);
        int right=MatrixChain(a,cut,e,dp);
        
        int ans=left + (a[s]*a[cut]*a[e]) +right;
        min_=min(min_,ans);
    }
    
    return dp[s][e]=min_;
}
//Optimal Binary Search Tree

int obst(){
    
}


void OBST(){

}


int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<int> dp(n,0);
    lis(arr,dp);
    cout << endl;
    return 0;
}
