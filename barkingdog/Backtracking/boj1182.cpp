#include <bits/stdc++.h>
using namespace std;
int n, s = 0;
int _cnt = 0;
int arr[21];
void func(int _sum, int idx){
    string s1 = "";
    for(int i=0;i<idx;i++) s1 += "_";
    if(_sum == s){
        _cnt++;
    }
    if(_sum > 1000000 && idx == 0) {_sum = 0;}
    for(int i=idx;i<n;i++){
        string s = "";
        for(int j=0;j<idx;j++) {s += "_";}
        int nsum = _sum + arr[i];
        func(nsum, i+1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i=0;i<n;i++) cin >> arr[i];
    func(1000001, 0);
    cout << _cnt;
}
/*
거의 1시간동안 고민했는데..맞았다!!!!!
중간에 바킹독 풀이를 보긴 했지만, 결국 내 방식대로 풀어냈다.
나는 for 문을 써서 풀었고,
바킹독은 포문 안 쓰고 sum, no sum 이런식으로 원소를 포함/포함 안시키는 두 개 func를 불렀다.
하지만 바킹독 풀이가 훨씬 간단하기 때문에 꼭 기억해두어야겠다
어쨌든 이 문제는 순서가 상관 없기 때문에 오로지 앞으로만 나아가면 되고,
그래서 func 에 누적해서 idx 를 주고 그 idx 부터 끝까지 돌도록 했다
간단한 문제였는데, 재귀 함수 때문에 디버깅이 오래걸렸다.
*/