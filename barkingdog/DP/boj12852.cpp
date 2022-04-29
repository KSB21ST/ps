#include<bits/stdc++.h>
using namespace std;
int n = 0;
int d[1000002];
int t[1000002];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[0] = 0;
    t[0] = 0;
    d[1] = 0;
    t[1] = 1;
    for(int i=2;i<=n;i++){
        d[i] = d[i-1] + 1;
        t[i] = i-1;
        if(i % 2 == 0){
            if(d[i] > d[i/2] + 1){
                d[i] = d[i/2] + 1;
                t[i] = i/2;
            }
        }
        if(i % 3 == 0){
            if(d[i] > d[i/3] + 1){
                d[i] = d[i/3] + 1;
                t[i] = i/3;
            }
        }
    }
    cout << d[n] << "\n" << n << " ";
    int cur = n;
    while(d[n]--){
        cout << t[cur] << " ";
        cur = t[cur];
    }
}
/*
바킹독 연습문제
23번째 줄의 if(i % 3 == 0) ... 을 쓸데없이 'else if' 로 해버려서 한 번 틀림
*/