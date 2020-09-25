#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
void read(vector<int>& arr){
    for(int i=0;i<arr.size();i++)
        cin>>arr[i];
}
vector<int> par;
vector<int> s;
int find(int u){
    return par[u]=par[u]==u?par[u]:find(par[u]);
}

void merge(int p1,int p2){
    if(s[p1]<s[p2]){
        par[p1]=p2;
        s[p1]+=s[p2];
    }else{
        par[p2]=p2;
        s[p2]+=s[p1];
    }
}

void solve(int numUsers,map<string,vector<string>> userBooksList,
int numGenres,map<string,vector<string>> bookGenres){
    unordered_map<string,string> map_book_to_genre;
    for(auto& p:bookGenres){
        for(int i=0;i<p.second.size();i++)map_book_to_genre[p.second[i]]=p.first;
    }
    unordered_map<string,unordered_map<string,int>> freqmap;
    unordered_map<string,int> max_freq_of_genre;
    for(auto& user:userBooksList){
        vector<string>& books=user.second;
        for(int i=0;i<books.size();i++){
            string genre=map_book_to_genre[books[i]];
            freqmap[user.first][genre]++;
            if(max_freq_of_genre.count(user.first))
            max_freq_of_genre[user.first]=max(max_freq_of_genre[user.first],freqmap[user.first][genre]);
            else    max_freq_of_genre[user.first]=1;
        }
    }
    map<string,vector<string>> ans;
    for(auto& user:userBooksList){
        string name=user.first;
        int max_freq=max_freq_of_genre[name];
        for(auto& genre:freqmap[name]){
            if(genre.second==max_freq)ans[name].push_back(genre.first);
        }
    }

    for(auto& person:ans){
        cout<<person.first<<" : ";
        vector<string>& genres=ans[person.first];
        for(int i=0;i<genres.size();i++)cout<<genres[i]<<", ";
        cout<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    int numUsers=3;
    map<string,vector<string>> userBooksList;
    int numGenres=3;
    map<string,vector<string>> bookGenres;
    userBooksList["Fred"].pb("mass");
    userBooksList["Fred"].pb("world");
    userBooksList["Fred"].pb("stress");
    userBooksList["Jenie"].pb("happy");
    userBooksList["Jenie"].pb("pride");
    userBooksList["Rone"].pb("alexender");
    bookGenres["Horror"].pb("mass");
    bookGenres["Horror"].pb("stress");
    bookGenres["Comedy"].pb("happy");
    bookGenres["Romance"].pb("world");
    bookGenres["Romance"].pb("alexender");
    bookGenres["Romance"].pb("pride");
    solve(numUsers,userBooksList,numGenres,bookGenres);
    return 0;
}