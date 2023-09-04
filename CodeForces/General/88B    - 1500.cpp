#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define T           long long T=1;  cin>>T; while(T--)
#define Super_Beso  ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define endl        '\n'
#define loop(n)     for(ll i=0; i<n; ++i)
#define loop2(n)    for(ll j=0; j<n; ++j)
#define loopv(n)    for(ll i=n-1; i>=0; --i)
#define sortAll(x)  sort(x.begin(),x.end());
#define revAll(x)   reverse(x.begin(),x.end());

using namespace std;
void files(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

void solve() {
    int n,m,x;  cin>>n>>m>>x;
    vector<string> keyWord(n);
    vector<pair<int,int>>shift;
    vector<bool> lc(26),uc(26);
    loop(n)
        cin>>keyWord[i];
    loop(n){
        loop2(m){
            if(keyWord[i][j]=='S')
                shift.push_back(make_pair(i,j));
            else
                lc[keyWord[i][j]-'a']=true;
        }
    }
    loop(n){
        loop2(m){
            if(keyWord[i][j]!='S'){
                for(auto tmp:shift){
                    if( pow((i-tmp.first),2)  +  pow((j-tmp.second),2)  <=pow(x,2))
                        uc[keyWord[i][j]-'a']=true;
                }
            }
        }
    }

    int q;  cin>>q;
    string str;   cin>>str;
    int ans=0;
    for(char c:str){
        if('a'<=c && c<='z'){
            if(!lc[c-'a']){
                cout<<-1<<endl;
                return;
            }
        }else if(!lc[c-'A'] || shift.empty()){
            cout<<-1<<endl;
            return;
        }else if(!uc[c-'A']){
            ans++;
        }
    }
    cout<<ans<<endl;


}

int main(void){
    Super_Beso
    //T{ solve(); }
    solve();
}

/*
 *
 * 1. READ problem statement carefully !!!!!!!
 * 2. use memset to initialize array with 0 or -1
 * 3. Big test cases, and test cases on the border!!
 *
 */