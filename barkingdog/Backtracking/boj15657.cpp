#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int>v;
int ans[9];
void func(int cnt){
    if(cnt == m){
        for(int i=0;i<m;i++) cout << ans[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(cnt > 0 && ans[cnt-1] > v[i]) continue;
        ans[cnt] = v[i];
        func(cnt+1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    func(0);
}
/*
한 방에 맞음
유형 동일
*/