#include <bits/stdc++.h>
using namespace std;
int board[130][130];
int cnt_w, cnt_b = 0;
int paper(int n, int a, int b){
    if(n == 1){
        if(board[a][b] == 0){
            cnt_w++;
            return 0;
        }else{
            cnt_b++;
            return 1;
        }
    }
    int n1 = paper(n/2, a, b);
    int n2 = paper(n/2, a, b + n/2);
    int n3 = paper(n/2, a + n/2, b);
    int n4 = paper(n/2, a + n/2, b + n/2);
    if(n1 == n2 && n2 == n3 && n3 == n4){
        if(n1 == 0){
            cnt_w -= 3;
            return 0;
        }else if(n1 == 1){
            cnt_b -= 3;
            return 1;
        }
    }
    return 2;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> board[i][j];
        }
    }
    paper(N, 0, 0);
    cout << cnt_w << "\n";
    cout << cnt_b << "\n";
}
/*
boj1780 (종이의 개수) 와 완전히 일치해서 바로 맞았다
*/