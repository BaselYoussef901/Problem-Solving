#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define endl    '\n'
int dx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = {+1, -1, +0, +0, +1, -1, -1, +1};

int n,m,k;
vector<vector<int>>dis(2005,vector<int>(2005,-1));
bool valid(int x,int y){
    return x>=0 && x<n && y>=0 && y<m;
}

void Super_Beso() {
    cin>>n>>m>>k;
    queue<pair<int,int>>q;

    int lastX=-1,lastY=-1;
    for(int i=0; i<k; i++){
        int x,y;    cin>>x>>y;
        x--,y--;
        q.push({x,y});
        dis[x][y]=0;
        lastX=x , lastY=y;
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(valid(xx,yy) && dis[xx][yy]==-1){
                q.push({xx,yy});
                dis[xx][yy] = dis[x][y]+1;
                lastX=xx;
                lastY=yy;
            }
        }
    }

    cout<<++lastX<<' '<<++lastY<<endl;


}

signed main(void) {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << setiosflags(ios::fixed) << setprecision(10);
    int ts=1;
    //cin>>ts;
    while(ts--)
        Super_Beso();
}
//Tip: [Sub: ((a-b)%MOD+MOD)%MOD ]      [Add: (a+b)%MOD ]     (Mul: (a*b)%MOD ]
 