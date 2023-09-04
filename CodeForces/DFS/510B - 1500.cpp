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
//int dx[8] = {+0, -0, +1, -1, +1, +1, -1, -1};
//int dy[8] = {+1, -1, +0, -0, +1, -1, +1, -1};
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};


int ver,edge;
vector<vector<bool>>vis;
vector<vector<char>>adj;
bool cycle=false;
int n,m;

bool valid(int i,int j){
    if(i>=0 && i<n && j>=0 && j<m)
        return true;
    return false;
}


void DFS(int i,int j,int prevI,int prevJ){
    if(vis[i][j]){
        cycle=true;
        return;
    }
    vis[i][j]=true;
    for(int k=0; k<4; k++){
        int ii=i+dx[k]    ,   jj=j+dy[k];
        if(  valid(ii,jj) && adj[ii][jj]==adj[i][j] && (prevJ!=jj || prevI!=ii)  )
            DFS(ii,jj,i,j);
    }
}

void Super_Beso() {
    cin >> n >> m;
    adj.resize(n + 50, vector<char>(m + 50));
    vis.resize(n + 50, vector<bool>(m + 50));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> adj[i][j];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) DFS(i, j, -1, -1);
            if (cycle) break;
        }
        if(cycle)  break;
    }
    cout<<(cycle?"Yes\n":"No\n");

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