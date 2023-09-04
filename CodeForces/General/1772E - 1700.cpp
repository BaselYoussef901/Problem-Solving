#include <bits/stdc++.h>
using namespace std;
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());  //Classes (OOP)
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef long long   ll;
typedef long double ld;
#define print(n,v)      for(int i=0; i<n; i++)  cout<<v[i]<<" \n"[i+1==n];
#define printPair(n,v)  for(int i=0; i<n; i++)  cout<<"("<<v[i].first<<","<<v[i].second<<")"<<" \n"[i+1==n];
#define endl '\n'
#define int long long
/**                                 Constrains                                      **/
const int MOD = 1000000007;        //1e9+7;
const double pi = acos(-1);
string Pi = "3.14159265358979323846264338327";
const int N = 1e9 + 5;
int dx8[] = { +0, -0, +1, -1, +1, +1, -1, -1 };
int dy8[] = { +1, -1, +0, -0, +1, -1, +1, -1 };
int dx4[] = { 0, 1, 0, -1 };
int dy4[] = { 1, 0, -1, 0 };



/**                              Solution Starts                                    **/
/**                              From Here:"  ^^                                    **/
vector<int>dp;
void DP(int i,int sum) {

}


void Super_Beso(int cases) {
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    int t1=0,t2=0,t3=0;
    for(int i=0; i<n; i++){
        int curr = v[i];
        if(curr != i+1 && curr !=n-i)
            t1++;
        else if(curr != i+1)
            t2++;
        else if(curr != n-i)
            t3++;
    }
    if(t1+t2 <= t3)
        cout<<"First\n";
    else if(t1+t3 < t2)
        cout<<"Second\n";
    else
        cout<<"Tie\n";

}




//Tip: [Sub: ((a-b)%MOD+MOD)%MOD ]      [Add: (a+b)%MOD ]     (Mul: (a*b)%MOD ]
signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setiosflags(ios::fixed) << setprecision(15);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int ts = 1, cases = 1;
    cin >> ts;
    while (ts--)
        Super_Beso(cases++);


}