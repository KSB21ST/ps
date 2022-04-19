#include <bits/stdc++.h>
using namespace std;
char arr[16];
char ans[16];
int l, c;
void func(int cnt, int idx, int vowl){
    if(cnt == l && vowl > 0 && (l - vowl) > 1){
        for(int i=0;i<l;i++) cout << ans[i];
        cout << "\n";
        return;
    }
    if(idx > c) return;
    for(int i=idx;i<c;i++){
        ans[cnt] = arr[i];
        int _vowl = vowl;
        if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
            _vowl++;
        func(cnt+1, i+1, _vowl);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> c;
    for(int i=0;i<c;i++){
        cin >> arr[i];
    }
    sort(arr, arr+c);
    func(0, 0, 0);
}
/*
스스로 맞았지만
최소 1개의 모음, 최소의 2개 자음이라는 조건을 놓쳐서 한 번 틀림.
문제 잘 읽자
*/