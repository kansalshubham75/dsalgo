#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int m, n;
		cin >> m >> n;

		int rootn = m <=2 ? n : sqrt(n) + 1;
		vector<int> arr(rootn+1,0);

		for(int i=2;i*i<=rootn;i++){
			if(arr[i]==0){
				for(int j=2*i;j<=rootn;j+=i)
					arr[j]=1;
			}
		}
		
		if(m<=2){
			for(int i=2;i<arr.size();i++)
			{
				if(arr[i]==0)
					cout<<i<<endl;
			}
			cout<<endl;
			continue;
		}

		vector<int> ans(n-m+1,0);
		for(int i=2;i<arr.size();i++){
			if(arr[i]==0){
				for(int j=0;j<ans.size();j++){
					int num=j+m;
					if(num%i==0)
						ans[j]=1;
				}
			}
		}

		for(int i=0;i<ans.size();i++){
			if(ans[i]==0)
				cout<<i+m<<endl;
		}
		cout<<endl;
	}
	return 0;
}