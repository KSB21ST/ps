#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[9];
int isused[9];
void func(int k){
    if(k == m){
        for(int i=0;i<m;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1;i<n+1;i++){
        if(!isused[i]){
            arr[k] = i;
            isused[i] = true;
            func(k+1);
            isused[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}
/*
백트래킹 첫 번째 문제.
바킹독 풀이 봄.
재귀를 사용하는 부분이 참신함
*/