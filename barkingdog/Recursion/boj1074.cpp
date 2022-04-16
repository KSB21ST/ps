// #include <bits/stdc++.h>
// using namespace std;
// int cnt = 0;
// int N, r, c = 0;
// bool found = false;
// void zig(int n, int idx, int r1, int c1){
//     if(found) return;
//     if(n == 0){
//         if(r1 == r && c1 == c){
//             cout << cnt;
//             found = true;
//             return;
//         }
//         cnt++;
//         return;
//     }
//     int padding = pow(2, n-1);
//     zig(n-1, 0, r1, c1);
//     if(found) return;
//     zig(n-1, 1, r1, c1 + padding);
//     if(found) return;
//     zig(n-1, 2, r1 + padding, c1);
//     if(found) return;
//     zig(n-1, 3, r1 + padding, c1 + padding);
//     return;
// }

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> N >> r >> c;
//     if(N == 0){
//         cout << 0;
//         return 0;
//     }
//     zig(N-1, 0, 0, 0);
//     if(found) return 0;
//     zig(N-1, 1, 0, pow(2,(N-1)));
//     if(found) return 0;
//     zig(N-1, 2, pow(2, (N-1)), 0);
//     if(found) return 0;
//     zig(N-1, 3, pow(2, (N-1)), pow(2, (N-1)));
// }
/*
처음에 재귀함수 zig(...)를 짜서 성실하게 한 칸 한칸 방문하는 식으로 짰는데, 시간초과가 났다
바킹독 풀이를 보니, 굳이 함수로 한 칸 한 칸 방문할 필요가 없다는 생각이 들었다.
*/


#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int N, r, c = 0;
int find_idx(int r, int c, int n, int sr, int sc){
    if(n == 0){
        return 0;
    }
    int cr = sr + pow(2, n-1);
    int cc = sc + pow(2, n-1);
    int unit = pow(2, 2*n-2);
    if(r < cr){ //1, 2사분면
        if(c < cc){ //1사분면
            return find_idx(r, c, n-1, sr, sc);
        }else{ //2사분면
            return unit + find_idx(r, c, n-1, sr, cc);
        }
    }else{//3, 4분면
        if(c < cc){ //3사분면
            return unit*2 + find_idx(r, c, n-1, cr, sc);
        }else{ //4사분면
            return unit*3 + find_idx(r, c, n-1, cr, cc);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> r >> c;
    if(N == 0){
        cout << 0;
        return 0;
    }
    int ans = find_idx(r, c, N, 0, 0);
    cout << ans;
}
/*
계속 시간초과 나다가 바킹독 영상 보고 힌트 얻어서 한방에 맞음!
키 포인트는 모든 칸을 차례 차례 방문하면 시간이 너무 오래걸리고 (시간초과남)
칸의 위치를 통해 몇 번째 사분면에 속했는지 구하고, 
그럼 사분면에 따라 큰 뭉탱이 인덱스는 해치워버리고
그 사분면을 다시 4 뭉탱이로 쪼개는 방식으로 재귀적으로 인덱스를 구하는 방식이다
*/