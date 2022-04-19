#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int>v;
int ans[9];
bool isused[9];
void func(int cnt){
    if(cnt == m){
        for(int i=0;i<m;i++) cout << ans[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(i > 0 && v[i-1] == v[i] && !isused[i-1]) continue;
        if(cnt > 0 && ans[cnt-1] > v[i]) continue;
        if(!isused[i]){
            ans[cnt] = v[i];
            isused[i] = true;
            func(cnt + 1);
            isused[i] = false;
        }
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
boj15663 와 유형 거의 비슷
*/