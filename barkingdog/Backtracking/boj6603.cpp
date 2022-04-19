#include <bits/stdc++.h>
using namespace std;
int k = 0;
int arr[15];
int ans[6];
void func(int cnt, int idx){
    if(cnt == 6){
        for(int i=0;i<6;i++) cout << ans[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=idx;i<k;i++){
        ans[cnt] = arr[i];
        func(cnt+1, i+1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cin >> k;
        if(k == 0) return 0;
        for(int i=0;i<k;i++){
            cin >> arr[i];
        }
        sort(arr, arr+k);
        func(0, 0);
        cout << "\n";
    }
}
/*
한 방에 맞음 ㅎ히
*/