#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int>a;
int arr[8];
bool isused[8];
void func(int cnt){
    if(cnt == m){
        for(int i=0;i<m;i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(cnt > 0 && a[i] == arr[cnt-1]) continue;
        if(!isused[i]){
            arr[cnt] = a[i];
            isused[i] = true;
            func(cnt+1);
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
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    fill(isused, isused+8, 0);
    func(0);
}
/*
스스로 맞음.
동일한 원소를 순서를 바꾸어서 뽑을 때 isused[] 사용하면 유용한듯
boj15649 (N과 M(1)) 과 그냥 동일한 문제
*/