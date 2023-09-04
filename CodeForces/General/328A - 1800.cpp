#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define T long long T;  cin>>T; while(T--)
typedef long long ll;
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define debug(x) cout<<"["<<#x<<" is: "<<x<<"]"<<endl;
using namespace std;
using namespace __gnu_pbds;

void solve(){
    ll a,b,c,d;    cin>>a>>b>>c>>d;
    ll difference=b-a;
    double ratio=(double)b/(double)a;
    ///Arthmetic
    if((int)c-b==difference && (int)d-c==difference)  //checking all the differences are the same
        cout<<(d+difference)<<endl;
    ///Geometric
    else if( (double)c/(double)b==ratio && (double)d/(double)c==ratio &&(double)(d*ratio)==(ll)(d*ratio))
        cout<<(d*ratio)<<endl;
    else
        cout<<42<<endl;

}
int main(void){
    IOS

        solve();

}
