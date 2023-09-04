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
#define loopv(i,n)  for(ll i=(ll)(n-1); i>=0; --i)
#define print(n,v)  loop0(i,n)  cout<<v[i]<<' ';    cout<<endl;
#define isEven(m)   m%2==0
/**                                 Head Functions                                 **/
void files();                                   //[01]
void prime();                                   //[02]
long long fastPower(ll base,ll power);          //[03]
long long gcd(ll a,ll b);                       //[04]
long long lcm(ll a,ll b);                       //[05]
long long SetBit    (ll n, ll X);               //[06]
long long ClearBit  (ll n, ll X);               //[07]
long long ToggleBit (ll n, ll X);               //[08]
bool CheckBit       (ll n, ll X);               //[09]
bool sortBy1st_then_2nd(const pair<int,int>&a , const pair<int,int>&b); //[10]
long long factorial(long long n);               //[11]
bool isPrime(long long n);                      //[12]
void sieve(ll x);                               //[13]

/**                                 Constrains                                     **/
const int Z=1e6+10;
const int MOD=998244353;
bool primes[Z];
set<ll>sv;
int dx[8] = {+0, -0, +1, -1, +1, +1, -1, -1};
int dy[8] = {+1, -1, +0, -0, +1, -1, +1, -1};
/**                                 Main Program                                   **/


void solve() {
    string str; cin>>str;
    map<char,int>Map;
    string ans="";
    ans+=str[0];
    Map[str[0]]=1;

    int check=0;
    bool f=false;
    loop1(i,str.size()-1){
        if(!Map[str[i]]){       //first when i=1
            Map[str[i]]++;
            if(!check){
                ans=str[i]+ans;
                check=0;
            }else if(check==ans.size()-1){    //second when i=2;
                ans+=str[i];
                check=ans.size()-1;
            }else{
                f=true;
                break;
            }
        }else{
            if(check && ans[check-1]==str[i]){
                check--;
                continue;
            }if(check!=ans.size()-1 && ans[check+1]==str[i]){
                check++;
                continue;
            }
            f=true;
            break;
        }
    }
    if(f)
        cout<<"NO\n";
    else{
        cout<<"YES\n";
        for(char i='a'; i<='z'; i++){
            if(!Map[i])
                ans+=i;
        }
        cout<<ans<<endl;
    }

}
signed main(void){
    Super_Beso
    int ts=1;
    cin>>ts;
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
ll fastPower(ll base,ll power){//                                     [03]-fastPower
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
//    if(a.first != b.first)
//        return a.first < b.first;
//    else
//        return a.second > b.second;
    //First Descending order , Second Ascending order
//    if(a.first == b.first)
//        return a.second < b.second;
//    else
//        return a.first > b.first;
    //Second Descending order , First Ascending order
    if(a.second != b.second)
        return a.second > b.second;
    else
        return a.first < b.first;

//Be aware of pair<type,type>       -   Calling: sort(all(v).sortBy1st_then_2nd);
}
ll factorial(ll n){//                                        [12]-Factiorial
    ll factorial = 1;
    for (ll i = 2; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}
bool isPrime(ll n){//                                              [13]-isPrime
    if(n<=1 || (n%2==0 && n!=2))    return false;
    for(int i=3; i*i<=n; i+=2){
        if(n%i==0)  return false;
    }
    return true;
}
void sieve(ll x){//                                                 [14]-Sieve
    bool primes[x+5];
    memset(primes,false,sizeof primes);
    for (ll i = 2; i*i <=x ; ++i) {
        if(!primes[i]){
            for (ll j = i*i; j <=x ; j+=i) {
                primes[j]= true;
            }
        }
    }
    for (ll i = 2; i <=x ; ++i) {
        if(!primes[i]){
            sv.insert(i*i);
        }
    }
}