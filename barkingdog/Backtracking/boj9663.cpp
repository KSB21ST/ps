#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;
bool isused_c[16];
bool isused_d1[31];
bool isused_d2[31];
void func(int row){
    if(row == n){ //row==n-1가 아닌 이유는 func(n-1) 이 불려야 n-1줄까지 놓은 것이기 때문이다
        cnt++;
        return;
    }
    for(int col=0;col<n;col++){
        if(isused_c[col] || isused_d1[col + row] || isused_d2[row - col + n -1])
            continue;
        isused_c[col] = true;
        isused_d1[col + row] = true;
        isused_d2[row - col + n -1] = true;
        func(row+1);
        isused_c[col] = false;
        isused_d1[col + row] = false;
        isused_d2[row - col + n -1] = false;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << cnt;
}
/*
바킹독 풀이를 보고 풀었음.
바둑판을 다 훑는 O(n^2) 의 시간을 절약하려고
y = x + k, y = -x + k 꼴의 대각선도 isused 함수를 설정해놓는다는 것,
그리고 일단은 1개의 열에 1개만 놓일 수 있기 때문에 열 단위로 끊어서 iterate 한다는 발상이 참신했다
*/