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
#define loopE(i,n)  for(ll j=i; j<=n; ++j)
#define loopv(i,n)    for(ll i=(ll)(n-1); i>=0; --i)
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
long long factorial(long long n);               //[12]



/**                                 Constrains                                     **/
const int Z=1e6+10;
const int MOD=998244353;
bool primes[Z];
int dx[8] = {+0, -0, +1, -1, +1, +1, -1, -1};
int dy[8] = {+1, -1, +0, -0, +1, -1, +1, -1};
/**                                 Main Program                                   **/
//4
//3
//0 0 1                 0 0 2
//4 3 2                 5 4 3
//5
//0 4 8 12 16
//2 6 10 14 18
//4
//0 10 10 10
//10 10 10 10
//2
//0 0
//0 0
void solve() {
    int n;  cin>>n;
    const int X = 5e6+100;
    vector<int> v(n+1),vis(X,0);
    vector<pair<int,int>> pos(X);
    loop1(i,n)  cin>>v[i];
    //loop1(i,n){
        //loop1(j,n){
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(i!=j){
                int tmp=v[i]+v[j];
                if(pos[tmp].first!=0 && pos[tmp].second!=0 &&
                   pos[tmp].first!=i && pos[tmp].first!=j &&
                   pos[tmp].second!=i && pos[tmp].second!=j)
                        {
                            cout<<"YES\n";
                            cout<<pos[tmp].first<<" "<<pos[tmp].second<<" "<<i<<" "<<j<<endl;
                            return;
                        }
                else{
                    pos[tmp].first=i;
                    pos[tmp].second=j;
                }
            }
        }
    }

    cout<<"NO\n";
}
signed main(void){
    Super_Beso
    int ts=1;
    //cin>>ts;
    //cout<<fixed<<setprecision(2);
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
    //First ascending order , Second Descending order
    if(a.first != b.first)
        return a.first < b.first;
    else
        return a.second > b.second;
    //First Descending order , Second Ascending order
//    if(a.first == b.first)
//        return a.second < b.second;
//    else
//        return a.first > b.first;

//Be aware of pair<type,type>
}
ll factorial(long long n){//                                        [12]-Factiorial
    long long factorial = 1;
    for (long long i = 2; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}