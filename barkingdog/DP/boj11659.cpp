#include<bits/stdc++.h>
using namespace std;
int n[100001];
int d[100002];
int N, M;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++) cin >> n[i];
    d[0] = 0;
    d[1] = n[0];
    for(int i=2;i<=N;i++){
        d[i] = d[i-1] + n[i-1];
    }
    while(M--){
        int i, j;
        cin >> i >> j;
        cout << d[j] - d[i-1] << "\n";
    }
}
/*
바킹독 연습문제.
prefix sum 이라고..
미리 d[n] 까지 d[n] = d[n-1] + 1 이라는 점을 활용하여 수열의 합을 O(N) 안에 구해놓고
i 부터 j까지 합은 d[j] - d[i-1] 이라는 점을 이용!
*/