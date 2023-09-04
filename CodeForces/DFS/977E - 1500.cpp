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
const double pi = acos(-1);
const int N = 2e5+5;
//int dx[8] = {+0, -0, +1, -1, +1, +1, -1, -1};
//int dy[8] = {+1, -1, +0, -0, +1, -1, +1, -1};








int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<bool>vis(N,false);
vector<int>adj[N];
vector<ll>nodes;
int n,m;

void DFS(int num){
    vis[num]=true;
    nodes.push_back(num);
    for(auto z:adj[num])
        if(!vis[z])
            DFS(z);
}

void Super_Beso() {
    int x,y;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ans=0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            nodes.clear();
            DFS(i);
            bool ok=true;
            for(auto z:nodes)
                ok &= adj[z].size()==2;
            if(ok)  ans++;
        }
    }
    cout<<ans<<"\n";

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