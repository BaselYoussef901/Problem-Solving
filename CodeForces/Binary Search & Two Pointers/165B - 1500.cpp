#include <bits/stdc++.h>
#include <numeric>
typedef long long ll;
typedef long double ld;
using namespace std;

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
int  SetBit    (int n, int X);
int  ClearBit  (int n, int X);
int  ToggleBit (int n, int X);
bool CheckBit  (int n, int X);
/**                                 Constrains                                     **/
const int N=1e6+10;
bool primes[N];

/**                                 Main Program                                   **/
bool check(ll mid,ll n,ll k){
    ll ans=mid , tmp = k;
    if(ans>=n)
        return true;
    while(mid>=tmp){
        ans+=mid/tmp;
        tmp*=k;
    }
    return ans>=n;
}
void solve() {
    ll n,k,ans=-1;    cin>>n>>k;
    int l=0,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid,n,k)){
            r=mid-1;
            ans=mid;
        }else
            l=mid+1;
    }
    cout<<ans<<endl;

}
int main(void){
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
    for(ll i=2; i<=N; i++)
        primes[i]=true;
    for(ll i=2; i*i<=N; i++) {
        if (!primes[i])
            continue;
        for(ll j=2*i; j<N; j+=i)
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
int SetBit (int n, int X) { return n | (1 << X); }//            [07]-SetBit
int ClearBit (int n, int X) { return n & ~(1 << X); }//         [08]-ClearBit
int ToggleBit (int n, int X) { return n ^ (1 << X); }//         [09]-ToggleBit
bool CheckBit (int n, int X) { return (bool)(n & (1 << X)); }// [10]-CheckBit