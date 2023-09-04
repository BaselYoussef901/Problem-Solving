#include <bits/stdc++.h>
#include <numeric>
using namespace std;
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());  //Classes (OOP)
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef long long   ll;
typedef long double ld;
#define print(n,v)      for(int i=0; i<n; i++)  cout<<v[i]<<" \n"[i+1==n];
#define printPair(n,v)  for(int i=0; i<n; i++)  cout<<"("<<v[i].first<<","<<v[i].second<<")"<<" \n"[i+1==n];
#define int long long
/**                                 Constrains                                     **/
const int MOD=1000000007;        //1e9+7;
const double pi = 3.1415926535897932;
const int N = 5005;
int dx[8] = {+0, -0, +1, -1, +1, +1, -1, -1};
int dy[8] = {+1, -1, +0, -0, +1, -1, +1, -1};

int ver,edge;
vector<bool>vis;
vector<vector<int>>adj;
void DFS(int node){
    ver++;
    vis[node]=true;
    for(auto &in:adj[node]){
        edge++;
        if(!vis[in])    DFS(in);
    }
}

void Super_Beso(){
    int n,m,x,y;
    cin>>n>>m;
    adj.resize(n);
    vis.resize(n,false);
    while(m--){
        cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool ok=false;
    for(int i=0; i<n; i++){
        ver=edge=0;
        if(!vis[i])
            DFS(i);
        ok+=(ver*(ver-1)/2 != edge/2);
        //if(ver*(ver-1)/2 != edge/2)   ok!=ok;
    }
    cout<<(ok?"NO\n":"YES\n");


}

signed main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<setiosflags(ios::fixed)<<setprecision(15);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ts=1;
    //cin>>ts;
    while(ts--)
        Super_Beso();

}