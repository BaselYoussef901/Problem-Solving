#include <bits/stdc++.h>
#include <numeric>
using namespace std;
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());  //Classes (OOP)
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
#define print(n, v)      for(int i=0; i<n; i++)  cout<<v[i]<<" \n"[i+1==n];
#define printPair(n, v)  for(int i=0; i<n; i++)  cout<<"("<<v[i].first<<","<<v[i].second<<")"<<" \n"[i+1==n];
const int MOD = 1000000007;        //1e9+7;
const double pi = acos(-1);
#define int long long
int dx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {+1, -1, +0, +0, +1, -1, -1, +1};
/**                              Solution Starts                                    **/
/**                              From Here:"  ^^                                    **/
const int N=1e5+5;
vector<vector<int>>adj;
vector<bool>vis(N);
vector<int>v(N),vv(N),nodes;
int temp;

void DFS(int node,int depth){


}
int DP(){

}


void Super_Beso() {
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i=0; i<n; i++)  cin>>a[i];
    for(int i=0; i<m; i++)  cin>>b[i];
    sort(a.begin(),a.end());

    for(int i=0; i<m; i++){
        int idx = upper_bound(a.begin(),a.end(),b[i])-a.begin();
        cout<<idx<<" \n"[i+1==m];
    }


}
signed main(void) {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setiosflags(ios::fixed) << setprecision(15);
    int ts=1;
    //cin>>ts;
    while (ts--) {
        /*                  Always Believe You Can Do it!                  */
        Super_Beso();
    }
}
//Tip: [Sub: ((a-b)%MOD+MOD)%MOD ]      [Add: (a+b)%MOD ]     (Mul: (a*b)%MOD ]