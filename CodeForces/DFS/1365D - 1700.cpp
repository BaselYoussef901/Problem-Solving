#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;
typedef long double ld;
#define print(n,v)      for(int i{}; i<n; i++)  cout<<v[i]<<" \n"[i+1==n];
#define printPair(n,v)  for(int i{}; i<n; i++)  cout<<"("<<v[i].first<<","<<v[i].second<<")"<<" \n"[i+1==n];
#define printVectors(sol)   for(int i{}; i<(int)sol.size(); i++){   cout<<"[ "; for(int j{}; j<(int)sol[i].size(); j++){    cout<<sol[i][j]<<","[j+1==(int)sol[i].size()];   }   cout<<"]"<<"\n "[i+1==(int)sol.size()];  };
#define third(X)        get<2>(X)
#define endl '\n'
#define int long long

void Beso() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setiosflags(ios::fixed) << setprecision(30);
#ifdef Clion
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}
/**                                 Constrains                                      **/
int dx8[] = {+0, -0, +1, -1, +1, +1, -1, -1};
int dy8[] = {+1, -1, +0, -0, +1, -1, +1, -1};
int dx[] = {+0, +0, -1, +1};
int dy[] = {-1, +1, +0, +0};
const double PI = 3.14159265358979323846264338327;
const int INF = LONG_LONG_MAX;
const ll OO = 0X3F3F3F3F3F3F3F3F;
const int MOD = 1000000007;        //1e9+7;
const int N = 1e5 + 5;






/**                              Solution Starts                                    **/
/**                              From Here:"  ^^                                    **/
int n,m,goodPerson,cnt;
char v[55][55];
bool vis[55][55];

void clear(){
    for(int i=0; i<55; i++)
        for(int j=0; j<55; j++)
            vis[i][j] = false;

    goodPerson=0;
    cnt=0;
}

bool valid(int i,int j){
    return i>=0 && i<n && j>=0 && j<m;
}

void DFS(int i,int j){
    vis[i][j] = true;
    cnt += (v[i][j]=='G');
    for(int k=0; k<4; k++){
        int ii = i+dx[k];
        int jj = j+dy[k];
        if(valid(ii,jj)){
            if(!vis[ii][jj] && v[ii][jj]!='#')
                DFS(ii,jj);
        }
    }

}

void Super_Beso(int tc) {
    clear();
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>v[i][j];


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j]=='G')    goodPerson++;
            //If Person is bad (Wall him up - 4 directions)
            if(v[i][j]=='B'){
                for(int k=0; k<4; k++){
                    int ii = i + dx[k];
                    int jj = j + dy[k];
                    if(valid(ii,jj)){
                        //if a G is neighbor with B
                        if(v[ii][jj] == 'G')
                            return cout<<"NO\n" , void();
                    }
                    if(v[ii][jj]=='.')
                        v[ii][jj] = '#';
                }
            }
        }
    }


    if(v[n-1][m-1]=='#')
        return cout<<(goodPerson>0?"NO\n":"YES\n") , void();

    DFS(n-1,m-1);
    cout<<(cnt==goodPerson?"YES\n" : "NO\n");


}



//Tip: [Sub: ((a-b)%MOD+MOD)%MOD ]      [Add: (a+b)%MOD ]     (Mul: (a*b)%MOD ]
signed main(void) {
    //Beso();
    int tc=1;
    cin>>tc;
    for(int i=1; i<=tc; i++)
        Super_Beso(i);
}