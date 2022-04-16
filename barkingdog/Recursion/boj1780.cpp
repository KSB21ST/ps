#include <bits/stdc++.h>
using namespace std;
int cnt[3] = {0, 0, 0};
int board[2200][2200];
int paper(int n, int sr, int sc){
    if(n == 1){
        if(board[sr][sc] == 0){
            cnt[0]++;
            return 0;
        }else if(board[sr][sc] == 1){
            cnt[1]++;
            return 1;
        }else{
            cnt[2]++;
            return -1;
        }
    }
    int n1 = paper(n/3, sr, sc);
    int n2 = paper(n/3, sr, sc + n/3);
    int n3 = paper(n/3, sr, sc + 2*n/3);
    int n4 = paper(n/3, sr + n/3, sc);
    int n5 = paper(n/3, sr + n/3, sc + n/3);
    int n6 = paper(n/3, sr + n/3, sc + 2*n/3);
    int n7 = paper(n/3, sr + 2*n/3, sc);
    int n8 = paper(n/3, sr + 2*n/3, sc + n/3);
    int n9 = paper(n/3, sr + 2*n/3, sc + 2*n/3);
    if(n1 == n2 && n2 == n3 && n3 == n4 && n4 == n5 && n5 == n6 && n6 == n7 && n7 == n8 && n8 == n9){
        if(n1 == 0){
            cnt[0] -= 8;
            return 0;
        }else if(n1 == 1){
            cnt[1] -= 8;
            return 1;
        }else if(n1 == -1){
            cnt[2] -= 8;
            return -1;
        }
    }
    return 2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++){
           cin >> board[i][j];
        }
    }

    paper(N, 0, 0);
    cout << cnt[2] << "\n";
    cout << cnt[0] << "\n";
    cout << cnt[1] << "\n";
}
/*
한 번에 맞을 수 있었는데, 34번째 줄을 else if가 아닌 else 로 처리해서 n1 == n2 == .. == 2 (모두 다른 경우) 에도 count[2] -= 8
하게 해버렸다 ,, 
핵심은 9구역으로 나누어서 그 9구역이 모두 같은 숫자인지 살피고, 만약 그렇다면 count -= 8 을 통해 (각각 9개 구역 보는동안 count++ 해줬을 텐데 합치면
9 개 -> 1개 되니까 -8) 하나로 합쳐주는 게 중요했다.
base case 는 한칸, 즉 n = 1 일 때..
*/