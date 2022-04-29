#include <bits/stdc++.h>
using namespace std;
int num = 0;
int s[301];
int d[301][3];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> num;
    for(int i=1;i<=num;i++)
        cin >> s[i];
    d[0][1] = 0;
    d[0][2] = 0;
    d[1][1] = s[1];
    d[1][2] = 0;
    d[2][1] = s[1] + s[2];
    d[2][2] = s[2];
    for(int i=3;i<=num;i++){
        d[i][1] = d[i-1][2] + s[i];
        d[i][2] = max(d[i-2][1], d[i-2][2]) + s[i];
    }
    cout << max(d[num][1], d[num][2]);
    
}
/*
바킹독 연습문제. 스스로 풀었다
점화식이 생각보다 뚜렷하게 잡혀있어야 한다
*/