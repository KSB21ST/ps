#include <bits/stdc++.h>
using namespace std;
int n, m = 0;
int a[8];
void func(int cnt){
    if(cnt == m){
        for(int i=0;i<m;i++) cout << a[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=0;i<n;i++){
        a[cnt] = i+1;
        func(cnt+1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}
/*
한 번에 맞았다. 
처음에 boj15650 처럼 풀으려고 하다가 boj15650은 한 방향으로만 나아가면 되지만,
얘는 다시 돌아와야 되는 애이기 때문에 for문으로 방향을 다시 바꿨다.
*/