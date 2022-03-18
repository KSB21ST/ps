#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int board[2000002];
int vis[2000002];
int  f, s, g, u, d;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> f >> s >> g >> u >> d;
    fill(vis[0], vis[0] + f + 1, -1);
    queue<int>Q;
    vis[s] = 1;
    Q.push(s);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        int nx;
        for(int dir=0;dir<2;dir++){
            if(dir == 1){
                nx = cur + u;
            }else{
                nx = cur - d;
            }
            if(nx < 1 || nx > f) continue;
            if(vis[nx] == 1) continue;
            vis[nx] = vis[cur] + 1;
        }   
    }
    if(vis[g] >= 0)
        cout << vis[g];
    else
        cout << "use the stairs";
}