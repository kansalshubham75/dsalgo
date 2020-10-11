#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector

void solve(){
	vector<string> cities = {"c1", "c2", "c3", "c4", "c5", "c6", "c7"}, queries = {"c1", "c2", "c3", "c4", "c5", "c6", "c7"};
    vector<int> xCoordinates = {3,2,1,3,4,1,0}, yCoordinates = {3,2,3,1,3,1,1};
    int numOfCities = 7, numOfQueries = 7;
	unordered_map<string,pair<int,int>> city_to_xy;
	unordered_map<int,map<int,string>> xvy;
	unordered_map<int,map<int,string>> yvx;
	for(int i=0;i<numOfCities;i++){
		city_to_xy[cities[i]]={xCoordinates[i],yCoordinates[i]};
		xvy[xCoordinates[i]][yCoordinates[i]]=cities[i];
		yvx[yCoordinates[i]][xCoordinates[i]]=cities[i];
	}
	for(int i=0;i<numOfQueries;i++){
		int x=city_to_xy[queries[i]].first;
		int y=city_to_xy[queries[i]].second;
		auto xptr=yvx[y].find(x);
		auto yptr=xvy[x].find(y);
		int dist=INT_MAX;
		string res;
		if(xptr!=yvx[y].begin()){
			auto prevCity=prev(xptr);
			int currdist=abs(xptr->first-prevCity->first);
			if(currdist<dist){
				dist=currdist;
				res=prevCity->second;
			}
		}
		if(xptr!=yvx[y].end() && next(xptr)!=yvx[y].end()){
			auto nextCity=next(xptr);
			int currdist=abs(nextCity->first-xptr->first);
			if(currdist<dist){
				dist=currdist;
				res=nextCity->second;
			}else if(currdist==dist){
				res=min(res,nextCity->second);
			}
		}
		if(yptr!=xvy[x].begin()){
			auto prevCity=prev(yptr);
			int currdist=abs(prevCity->first-yptr->first);
			if(currdist<dist){
				dist=currdist;
				res=prevCity->second;
			}else if(currdist==dist){
				res=min(res,prevCity->second);
			}
		}
		if(yptr!=xvy[x].end() && next(yptr)!=xvy[x].end()){
			auto nextCity=next(yptr);
			int currdist=abs(nextCity->first-yptr->first);
			if(currdist<dist){
				dist=currdist;
				res=nextCity->second;
			}else if(currdist==dist){
				res=min(res,nextCity->second);
			}
		}
		if(dist!=INT_MAX)cout<<res<<endl;
		else cout<<"None"<<endl;
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}