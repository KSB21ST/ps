#include <bits/stdc++.h>
using namespace std;
int board[100001];
int vis[100001];
int t;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        int n;
        int total_n = 0;
        cin >> n;
        for(int i=1;i<n+1;i++) cin >> board[i];
        for(int i=1;i<n+1;i++){
            if(vis[i] == 1) continue;
            int team_n = 0;
            queue<int>Q;
            queue<int> temp;
            vis[i] = 1;
            Q.push(i);
            while(!Q.empty()){
                int cur = Q.front(); Q.pop();
                team_n++;
                int nxt = board[cur];
                if(vis[nxt] == 1){
                    if(nxt == i){ //team 성공
                        total_n += team_n;
                    }else{ //team이 될 수 없다
                        while(!temp.empty()){
                            int temp1 = temp.front(); temp.pop();
                            team_n--;
                            if(temp1 == nxt){
                                total_n += team_n;
                                break;
                            }
                        }
                    }
                    break;
                }
                vis[nxt] = 1;
                Q.push(nxt);
                temp.push(nxt);
            }
        }
        cout << n - total_n << "\n";
        fill(vis, vis + n+1, 0);
    }
}
/*
스스로 힘으로 맞았음!
중요한 건 지나온 애들을 queue에 넣어놓고, 팀이 만들어질 수 없는 상황이어도,
되짚어 가면서 중간에 loop 이 생기는지 체크하고, 생기면 걔네를 팀으로 생각해준다.
그렇게 하면 한 번 visited 하면 무조건 두 번 다시 방문할 필요가 없다. (팀이 된 애들은 됐고, 팀이 안된 애들도 얘네는 어차피 안되는 걸 알기 때문에 다시 visit 할 필요가 없다)
*/