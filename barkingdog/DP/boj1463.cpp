#include <bits/stdc++.h>
using namespace std;
int N = 0;
int d[1000001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    d[0] = 0;
    d[1] = 0;
    for(int i=2;i<=N;i++){
        d[i] = d[i-1] + 1;
        if(i % 3 == 0) d[i] = min(d[i], d[i/3]+1);
        if(i % 2 == 0) d[i] = min(d[i], d[i/2]+1);
    }
    cout << d[N];
}
/*
바킹독 연습문제. 다시풀기
*/