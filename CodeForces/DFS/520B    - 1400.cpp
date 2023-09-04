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
/**                                 Constrains                                      **/
const int MOD=1000000007;        //1e9+7;
const double pi = acos(-1);
const int N = 1e4+5;
int dx8[] = {+0, -0, +1, -1, +1, +1, -1, -1};
int dy8[] = {+1, -1, +0, -0, +1, -1, +1, -1};
int dx4[] = {0, 1, 0, -1};
int dy4[] = {1, 0, -1, 0};




/**                              Solution Starts                                    **/
/**                              From Here:"  ^^                                    **/
vector<int>adj;
vector<bool>vis;
vector<int>v,vv;
int n,m,x,y,ans=0;
bool valid(int i,int j){
    if(i>=0 && i<n && j>=0 && j<m)
        return true;
    return false;
}
bool isValid(int a){
    return a>=0 && a<=1e4 && !vis[a];
}
void DFS(int num){
    vis[num]=true;
    queue<int>q;
    q.push(num);
    while(!q.empty()){
        num = q.front();
        q.pop();
        int ADJ=num*2;
        if(isValid(ADJ)) {
            vis[ADJ]=true;
            q.push(ADJ);
            if(adj[ADJ]==-1)        adj[ADJ] = adj[num] + 1;
            else                    adj[ADJ] = min(adj[ADJ], adj[num] + 1);
        }
        ADJ=num-1;
        if(isValid(ADJ)){
            vis[ADJ]=true;
            q.push(ADJ);
            if(adj[ADJ]==-1)        adj[ADJ]=adj[num]+1;
            else                    adj[ADJ]=min(adj[ADJ], adj[num] + 1);
        }
    }
}

vector<int>dp;
int DP(int num){

}

void Super_Beso() {
    cin>>n>>m;
    vis.resize(N,false)     ,    adj.resize(N,-1);
    adj[n]=0;
    DFS(n);
    cout<<adj[m];

}




//Tip: [Sub: ((a-b)%MOD+MOD)%MOD ]      [Add: (a+b)%MOD ]     (Mul: (a*b)%MOD ]
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