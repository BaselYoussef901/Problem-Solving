#include <bits/stdc++.h>
#define T long long T=1;  cin>>T; while(T--)
typedef long long ll;
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define debug(x) cout<<"["<<#x<<" is: "<<x<<"]"<<endl;
void files(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}
using namespace std;


vector<ll>lucky;
void generate_permutations(ll n,ll four,ll seven){
    if(n > 1e10)  return;
    lucky.push_back(n);
    generate_permutations(n*10 + 4,four+1, seven);
    generate_permutations(n*10 + 7,four,seven+1);
}
void solve(){
    //generate_permutations(4,1,0);
    //generate_permutations(7,0,1);
    //sort(lucky.begin(),lucky.end());
    int vp,vd,t,f,c;    cin>>vp>>vd>>t>>f>>c;
    if(vp>=vd)   {cout<<0<<endl; return;}
    double distance = (double)(vp*t) , Normaltime=0.0;
    int coins=0,v=vd-vp;
    while(true){
        Normaltime=distance/v;
        distance+=vp*Normaltime;
        if(distance>=c) break;
        else{
            coins++;
            distance+=(f+Normaltime)*vp;
        }
    }
    cout<<coins<<endl;

}

int main(void){
    //IOS
    //T{ solve(); }
    solve();
}

/*
 * << bitmasks >>
 *  A 	 		= 		5  (00101)
 *  A<<1		= 		10 (01010)
 *  B 	 		= 		12 (001100)
 *  B<<2		= 		48 (110000)
 *  Check a bit
 *      (mask >> bitIndx) & 1 == 1;
 *  Set a bit to one
 *      mask = mask | (1 << bitIndx);
 *  Set a bit to zero
        mask = mask & ~(1 << bitIndx);
 *  Flip a bit
        mask = mask ^ (1 << bitIndx);
 *  Check if a number if odd  num & 1 == 1;
 *  Xor tricks
        x ^ y ^ x = y
        x ^ y false when (x == y)
 *  Number of ones
        __builtin_popcount(num);
        __builtin_popcountll(num);
 * if( n & (-n) == n) return true if the number is power of two else return false
 */