#include<bits/stdc++.h>
using namespace std;
int d[1001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    d[1] = 1;
    d[2] = 2;
    for(int i=3;i<=n;i++){
        d[i] = (d[i-1] + d[i-2]) % 10007;
    }
    cout << d[n];
}
/*
바킹독 연습문제.. 스스로 아이디어를 생각해냈다
10007로 나누는 조건을 놓쳐서 한 번 틀림
*/