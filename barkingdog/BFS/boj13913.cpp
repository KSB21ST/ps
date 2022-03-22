#include <bits/stdc++.h>
using namespace std;
int board[200002];
int dist[200002];
int n, k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    if(n == k){
        cout << 0 << "\n";
        cout << n;
        return 0;
    }
    fill(dist, dist+200002, -1);
    queue<int>Q;
    stack<pair<int, int> > Q2;
    stack<int> ans;
    dist[n] = 0;
    Q.push(n);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int nx : {cur + 1, cur - 1, cur*2}){
            if(nx < 0 || nx > 200002) continue;
            if(nx == k){
                // cout << "nx: " << nx << " cur: " << cur << "\n";
                cout << dist[cur] + 1 << "\n";
                ans.push(nx);
                ans.push(cur);
                int sec = cur;
                while(!Q2.empty()){
                    pair<int, int> idx = Q2.top(); Q2.pop();
                    if(idx.second == sec){
                        // cout << "idx: " << idx.first << " " << idx.second << "\n";
                        ans.push(idx.first);
                        sec = idx.first;
                    }
                }
                while(!ans.empty()){
                    cout << ans.top() << " ";
                    ans.pop();
                }
                return 0;
            }
            if(dist[nx] >= 0) continue;
            dist[nx] = dist[cur] + 1;
            Q.push(nx);
            Q2.push({cur, nx});
        }
    } 
}
/*
한 방에 맞음
*/