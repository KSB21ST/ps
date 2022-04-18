#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[9];
void func(int cnt, int idx){
    if(cnt == m){
        for(int i=0;i<m;i++) cout << a[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=idx;i<=n;i++){
        if(cnt >= 1 && i >= a[cnt-1]){
            a[cnt] = i;
            func(cnt+1, i);
        }else{
            a[cnt] = i;
            func(cnt+1, i);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0, 1);
}
/*
for 문 안 쓰려고 하다가 쓰니까 바로 됨..
idx 넣어서 시작하는 지점 조절해주기
*/