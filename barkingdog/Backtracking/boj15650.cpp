#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[10];
void func(int cnt, int idx){
    // cout << "func cnt: " << cnt << " idx: " << idx << "\n";
    if(cnt == m){
        for(int i=0;i<m;i++) cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    if(idx > n) return;
    arr[cnt] = idx;
    // cout << "store in arr: cnt: " << cnt << " idx: " << idx << "\n";
    func(cnt+1, idx+1);
    func(cnt, idx+1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0, 1);
}
/*
boj15649 (N과 M(1)) 과 유형이 비슷
*/

//next_permutation 이용
// #include <bits/stdc++.h>
// using namespace std;
// int n, m=0;
// vector<int>v;
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n >> m;
//     for(int i=0;i<n;i++) v.push_back(i < m ? 0 : 1);
//     do{
//         for(int i=0;i<n;i++){
//             if(!v[i]){
//                 cout << i+1 << " ";
//             }
//         }
//         cout << "\n";
//     }while(next_permutation(v.begin(), v.end()));
// }