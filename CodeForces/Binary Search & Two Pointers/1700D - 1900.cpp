#include <bits/stdc++.h>
#include <numeric>
typedef long long ll;
typedef long double ld;
using namespace std;

#define int         long long int
#define all(x)      x.begin(),x.end()
#define allr(x)     x.rbegin(),x.rend()
#define Super_Beso  ios_base::sync_with_stdio(false),cin.tie(__null),cout.tie(__null);
#define endl        '\n'
#define loop0(i,n)  for(ll i=0; i<(ll)n; ++i)
#define loop1(i,n)  for(ll i=1; i<=(ll)n; ++i)
#define loopE(j,n)  for(ll i=j; i<n; ++i)
#define loopv(n)    for(ll i=(ll)(n-1); i>=0; --i)
#define isEven(m)   m%2==0
#define yes         cout<<"YES\n";
#define no          cout<<"NO\n";
#define print(n,v)  loop0(i,n)  cout<<v[i]<<' ';    cout<<endl;
/**                                 Head Functions                                 **/
void files();                                   //[02]
void prime();                                   //[03]
long long fastPower(ll base,ll power);          //[04]
long long gcd(ll a,ll b);                       //[05]
long long lcm(ll a,ll b);                       //[06]
long long SetBit    (ll n, ll X);               //[07]
long long ClearBit  (ll n, ll X);               //[08]
long long ToggleBit (ll n, ll X);               //[09]
bool CheckBit       (ll n, ll X);               //[10]
bool sortBy1st_then_2nd(const pair<int,int>&a , const pair<int,int>&b); //[11]



/**                                 Constrains                                     **/
const int Z=1e6+10;
bool primes[Z];
int dx[8] = {+0, -0, +1, -1, +1, +1, -1, -1};
int dy[8] = {+1, -1, +0, -0, +1, -1, +1, -1};

/**                                 Main Program                                   **/
bool check(vector<ll>&locks,ll seconds){
    int total_seconds=0;
    loop0(i,locks.size()){
        total_seconds+=seconds;
        if(total_seconds<locks[i])  return false;
    }
    return true;
}
void solve() {
    int n,q;  cin>>n;
    vector<int> locks(n);   //prefix
    loop0(i,n){
        cin>>locks[i];
        if(i==0)    locks[i] =locks[i];
        else        locks[i]+=locks[i-1];
    }
    //locks[0] has the minimum liters
    int l=locks[0],r=1e9,mid;
    while(r-l>1){
        mid=(r+l)/2;
        if(check(locks,mid))    r=mid;
        else                l=mid;
    }
    if(check(locks,l))  mid=l;
    else                           mid=r;
    cin>>q;
    while(q--){
        int x;  cin>>x;
        int ans=-1;
        if(x>=mid)
            ans = (locks[n-1]+x-1)/x;
        cout<<ans<<endl;
    }

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
void prime(){//                                                     [02]-Primes
    for(ll i=2; i<=Z; i++)
        primes[i]=true;
    for(ll i=2; i*i<=Z; i++) {
        if (!primes[i])
            continue;
        for(ll j=2*i; j<Z; j+=i)
            primes[j]=false;
    }
}
ll fastPow(ll base,ll power){//                                     [03]-fastPower
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
ll gcd(ll a,ll b){//                                                [04]-Greatest Common Divisor
    if(a==0)
        return b;
    return gcd(b%a,a);
}
ll lcm(ll a,ll b){//                                                [05]-lowest Common
    return (a/gcd(a,b))*b;
}
bool palindromic(int n){//                                          [06]-Palindromic
    string str1=to_string(n),str2;
    str2=str1;
    reverse(str2.begin(),str2.end());
    if(str1==str2)
        return true;
    else return false;
}
ll SetBit       (ll n, ll X) { return n | (1 << X); }//             [07]-SetBit
ll ClearBit     (ll n, ll X) { return n & ~(1 << X); }//            [08]-ClearBit
ll ToggleBit    (ll n, ll X) { return n ^ (1 << X); }//             [09]-ToggleBit
bool CheckBit   (ll n, ll X) { return (bool)(n & (1 << X)); }//     [10]-CheckBit
bool sortBy1st_then_2nd(const pair<int,int>&a , const pair<int,int>&b){ //[11]-SortBy1st_then_2nd
    if(a.first != b.first)
        return a.first < b.first;
    else
        return a.second > b.second;
    //First ascending order , Second Descending order
}