#include<bits/stdc++.h>
using namespace std;
int t = 0;
int d[12];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i=4;i<12;i++){
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }
    while(t--){
        int n;
        cin >> n;
        cout << d[n] << "\n";
    }
}
/*
바킹독 연습문제
..지만, 풀이 안 보고 한 번에 풀었다.
*/