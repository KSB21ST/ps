#include<bits/stdc++.h>
using namespace std;
int N = 0;
int R[1001];
int G[1001];
int B[1001];
int d[1001][3];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> R[i] >> G[i] >> B[i];
    }
    d[0][0] = R[0];
    d[0][1] = G[0];
    d[0][2] = B[0];
    for(int i=1;i<N;i++){
        d[i][0] = min(d[i-1][1], d[i-1][2]) + R[i];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + G[i];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + B[i];
    }
    cout << min(d[N-1][0], min(d[N-1][1], d[N-1][2]));
}
/*
바킹독 연습문제.
핵심은 R, G, B 각각에 array 를 만들어주고
d[집 개수][R, G, B 각각에 대한 index] 로 만들어주어야 한다.
*/