#include <bits/stdc++.h>
#include <numeric>
typedef long long ll;
typedef long double ld;
using namespace std;

#define int         long long
#define all(x)      sort(x.begin(),x.end())
#define allr(x)     sort(x.rbegin(),x.rend())
#define rev(x)      reverse(x.begin(),x.end())
#define Super_Beso  ios_base::sync_with_stdio(false),cin.tie(__null),cout.tie(__null);
#define endl        '\n'
#define loop0(i,n)  for(ll i=0; i<(ll)n; ++i)
#define loop1(i,n)  for(ll i=1; i<=(ll)n; ++i)
#define loopE(j,n)  for(ll i=j; i<n; i++)
#define loopv(n)    for(ll i=(ll)(n-1); i>=0; --i)
#define isEven(m)   m%2==0
/**                                 Head Functions                                 **/
void files();       //[01]
void prime();       //[02]
long long fastPower(ll base,ll power);
long long gcd(ll a,ll b);
long long lcm(ll a,ll b);
long long SetBit    (ll n, ll X);
long long ClearBit  (ll n, ll X);
long long ToggleBit (ll n, ll X);
bool CheckBit       (ll n, ll X);
/**                                 Constrains                                     **/
const int Z=1e6+10;
bool primes[Z];

/**                                 Main Program                                   **/
const int N=1e5+5;
vector<int> pos[N];
int vis[N];
void dfs(int node){
    vis[node]=true;
    for(auto i:pos[node])
        if(!vis[i])
            dfs(i);
}

void solve() {
    int n,m,sum=0;    cin>>n>>m;
    vector<pair<int,int>> v(n);
    loop0(i,n) {
        cin>>v[i].first;
        v[i].second=(i+1);
    }
    while(m--){
        int x,y;    cin>>x>>y;
        pos[x].push_back(y);
        pos[y].push_back(x);
    }
    all(v);
    loop0(i,n){
        if(!vis[v[i].second]){
            sum+=v[i].first;
            dfs(v[i].second);
        }
    }
    cout<<sum<<endl;

}
signed main(void){
    Super_Beso
    int ts=1;
    //cin>>ts;
    while(ts--)
        solve();

}









/**                                     Functions                                 **/
void files(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}
void prime(){//                                                 [02]-Primes
    for(ll i=2; i<=Z; i++)
        primes[i]=true;
    for(ll i=2; i*i<=Z; i++) {
        if (!primes[i])
            continue;
        for(ll j=2*i; j<Z; j+=i)
            primes[j]=false;
    }
}
ll fastPow(ll base,ll power){//                                 [03]-fastPower
    const int MOD = 1e9+7;
    ll result=1;
    while(power>0){
        if(power&1)
            result = (result*base)%MOD;
        base = (base*base)%MOD;
        power >>=1;
    }
    return result;
}
ll gcd(ll a,ll b){//                                            [04]-Greatest Common Divisor
    if(a==0)
        return b;
    return gcd(b%a,a);
}
ll lcm(ll a,ll b){//                                            [05]-lowest Common
    return (a/gcd(a,b))*b;
}
bool palindromic(int n){//                                      [06]-Palindromic
    string str1=to_string(n),str2;
    str2=str1;
    reverse(str2.begin(),str2.end());
    if(str1==str2)
        return true;
    else return false;
}
ll SetBit       (ll n, ll X) { return n | (1 << X); }//            [07]-SetBit
ll ClearBit     (ll n, ll X) { return n & ~(1 << X); }//         [08]-ClearBit
ll ToggleBit    (ll n, ll X) { return n ^ (1 << X); }//         [09]-ToggleBit
bool CheckBit   (ll n, ll X) { return (bool)(n & (1 << X)); }// [10]-CheckBit