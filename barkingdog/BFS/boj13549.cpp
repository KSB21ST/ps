#include <bits/stdc++.h>
using namespace std;
int board[200002];
int vis[200002];
int dx[2] = {1, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    queue<int> Q;
    fill(vis, vis + 200002, -1);
    vis[n] = 0;
    Q.push(n);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        int twice = cur*2;
        while(twice < 200002 && vis[twice] < 0){
            vis[twice] = vis[cur];
            Q.push(twice);
            twice = twice * 2;
        }
        for(int dir=0;dir<2;dir++){
            int nx = cur + dx[dir];
            if(nx < 0 || nx >= 200002) continue;
            if(vis[nx] >= 0) continue;
            vis[nx] = vis[cur] + 1;
            Q.push(nx);
            twice = nx*2;
            while(twice < 200002 && vis[twice] < 0){
                vis[twice] = vis[nx];
                Q.push(twice);
                twice = twice * 2;
            }
        }
    }
    cout << vis[k];
}

/*
얼핏 보면 쉬운 문제 같았는데,
다시 보니 중요한 문제인 것 같다.
숨박꼭질1 (1697) 과 다른 것은 *2 할 때 이동시간이 0 이라는 것이다.
이런 경우, 무한정으로 *2 를 할 수 있기 때문에 가중치가 다르게 된다
여기서 중요함: bfs 는 원래 가중치가 같아야 사용할 수 있다고 한다 (멍청이처럼.. 이것도 모르고 있었음)
왜냐하면 가중치가 차이가 나버리면, 작은 가중치로 열심히 움직여서 먼저 visit 해버리면, 나중에 더 적은 가중치로 visit 할 수 있는데도 이미 taken 이 되어버리는.. 느낌?
대표적인 반례: input 2 7 이렇게 넣어보자.
그럼 2->4->8->7 이렇게 가중치 1로 해결가능한데
막상 해보면 queue에 1 3 4 0 6 5 8 이 순서대로 쌓여서 (즉 가중치가 작은 4, 8이 뒤로 밀린다)
2->3->6->7 이렇게 2로 나와버린다 (가중치만 다르게 하고 숨박꼭질1 풀이처럼 하면)
그래서 어떻게 하느냐.. 가중치가 적은 2^n 애들을 먼저 queue 에 push 해준다.
그리고 새로운 애들을 넣어 줄 때마다 그 애*2^n 인 애들을 queue에 push 해준다.
그럼 queue 상에서 가중치 작은 애들부터 bfs 하는 게 가능하므로 .. 문제가 풀린다.

내가 온전히 풀지 않고, 해설 대충 보다가 '우선순위 큐' 로 풀어야 한다는 말에서 힌트를 얻었다
*/