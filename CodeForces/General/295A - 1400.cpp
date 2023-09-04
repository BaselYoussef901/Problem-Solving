#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

#define all(x)      sort(x.begin(),x.end())
#define allr(x)     sort(x.rbegin(),x.rend())
#define rev(x)      reverse(x.begin(),x.end())
#define T           int T=1; scanf("%d",&T); while(T--)
#define Super_Beso  ios_base::sync_with_stdio(false),cin.tie(__null),cout.tie(__null);
#define endl        '\n'
#define loop0(i,n)  for(ll i=0; i<(ll)n; ++i)
#define loop1(i,n)  for(ll i=1; i<=(ll)n; ++i)
#define loopE(i,n)  for(ll j=i; j<n; j++)
#define loopv(n)    for(ll i=(ll)(n-1); i>=0; --i)
#define isEven(m)   m%2==0
/**                                 Head Functions                                 **/
void files();       //[01]
void prime();       //[02]

/**                                 Constrains                                     **/
const int N=1e6+10;
bool primes[N];

/**                                 Main Program                                   **/
void solve() {
    //Solution By mariamkhaled1212 "Not Mine"
    ll n,m,q;   cin>>n>>m>>q;
    const ll NN = 100005;
    vector<ll> v(NN);
    loop1(i,n)
        cin>>v[i];

    vector<tuple<ll,ll,ll>> Q;
    loop0(i,m){
        ll x,y,value;   cin>>x>>y>>value;
        Q.push_back(make_tuple(x,y,value));
    }
    vector<ll>freq(NN),pref(NN);
    loop0(i,q){
        ll l,r; cin>>l>>r;
        freq[l]++;
        freq[r+1]--;
    }
    loop1(i,m)
        freq[i] += freq[i-1];





    loop0(i,m){
        ll l = get<0>(Q[i]);
        ll r = get<1>(Q[i]);
        ll x = get<2>(Q[i]);
        pref[l]  += x * freq[i+1];
        pref[r+1]-= x * freq[i+1];
    }
    loop1(i,n)
        pref[i] += pref[i-1];

    loop1(i,n)
        cout<<(ll)(v[i]+pref[i])<<' ';
}
int main(void){
    Super_Beso
    //T{ solve(); }
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
 