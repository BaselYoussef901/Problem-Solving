#include <bits/stdc++.h>
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
    //Two Pointers Solution
    int n;      cin>>n;
    string str; cin>>str;
    set<char> st;
    loop0(i,n)
        st.insert(str[i]);

    int l=0,r=0,mn=1e6;
    set<char> tmp;
    map<char,int> take;
    while(l<n){
        if(tmp.size()==st.size()){
            mn=min(mn,r-l);
            take[str[l]]--;
            if(take[str[l]]==0)
                tmp.erase(str[l]);
            l++;
        }else{
            if(r>=n)    break;
            take[str[r]]++;
            tmp.insert(str[r]);
            r++;
        }
    }
    cout<<mn<<endl;


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
 