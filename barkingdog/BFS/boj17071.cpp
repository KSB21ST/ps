/*
#include <bits/stdc++.h>
using namespace std;
dist[500001];
int n, k;
int t = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    if(n == k){
        cout << 0;
        return 0;
    }
    queue<tuple<int, int, int> > Q;
    Q.push({n, 0, k});
    while(!Q.empty()){
        int cur, time, cur_k;
        tie(cur, time, cur_k) = Q.front(); Q.pop();
        for(auto nxt : {cur -1, cur+1, cur*2}){
            if(nxt < 0 || nxt > 500000) continue;
            int nt = time + 1;
            int nk = cur_k + nt;
            if(nk > 500000) continue;
            if(nk == nxt){
                cout << nt;
                return 0;
            }
            Q.push({nxt, nt, nk});
        }
    }
    // cout << dist[15];
    // int t = 1;
    // while(k < 500001){
    //     k += t;
    //     if(k > 500000){
    //         break;
    //     }
    //     if(t < dist[k]) {
    //         t++;
    //         continue;
    //     }
    //     else if(t == dist[k]){
    //         cout << t;
    //         return 0;
    //     }
    //     else{
    //         int gap = t - dist[k];
    //         if(gap % 2 == 0){
    //             cout << t;
    //             return 0;
    //         }
    //     }
    //     t++;
    // }
    cout << -1;
}
*/
/*
엄청나게 오래 고민했는데 (거의 며칠...) 결국 포기하고 풀이를 본다.
기존에 했던 방식대로 bfs 사용해서 큐에 시간 하나 지날 때마다 가능한 수빈이의 위치를 넣어주면 계속 메모리 초과가 난다.
계속 겹치는 위치가 생겨서 그런 것 같다.
그래서 t라는 시간에 d 라는 위치에 수빈이가 도달했다고 했을 때 그 뒤로 t+2, t+4, ... 에는 수빈이가 d에 있을 수 있으므로
(t+1 에는 한 칸 뒤로 갔다가 t+2에는 다시 한 칸 앞으로 오는 식으로)
.. 까지 생각했는데 구현이 잘 안되고 엄밀하지 않은 것 같아서 계속 고민하다가 결국 정답을 검색해봄. 
*/
#include <bits/stdc++.h>
using namespace std;
int vis[2][500001]; /*vis[0]은 짝수 시간에 도착한 시간을 기록, vis[1]은 홀수 시간에 도착한 시간을 기록*/
int sis, bro;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> sis >> bro;
    if(sis == bro){
        cout << 0;
        return 0;
    }
    for(int i=0;i<2;i++) fill(vis[i], vis[i] + 500001, -1);
    queue<pair<int, int> >Q; /*(위치, 그 위치에 도달한 시간)*/
    vis[0][sis] = 0;
    Q.push({sis, 0});
    while(!Q.empty()){ //먼저 sis iteration을 쫙 돈다 -> 어느 칸에 도착했는지 시간을 기록
        int d, t;
        tie(d, t) = Q.front(); Q.pop();
        int nt = t+1;
        for(auto nd : {d+1, d-1, d*2}){
            if(nd > 500000 || nd < 0) continue;
            if(vis[nt % 2][nd] > -1) continue;
            vis[nt % 2][nd] = nt;
            Q.push({nd, nt});
        }
    }

    //bro iteration을 돈다.
    int time = 1;
    while(bro <= 500000){
        bro += time;
        if(bro > 500000){
            cout << -1;
            return 0;
        }
        if(time >= vis[time%2][bro]){
            cout << time;
            return 0;
        }
        time++;
    }
    cout << -1;
}
/*
설명 읽은 후 다시 풀어보고 한 방에 맞음.
키 포인트는 시간의 짝수, 홀수로 vis 를 나눈다는 것, 
그리고 vis 에 도착한 시간을 저장해두고 그 시간이 동생 보다 먼저기만 하면 된다는 것.
항상, 답은 너무나 간단했는데.. 난 왜 이렇게 어렵게 생각한 걸까.
*/