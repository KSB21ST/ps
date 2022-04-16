#include <bits/stdc++.h>
using namespace std;
queue<pair<int, int> >s;

void hanoi(int a, int b, int n, int c){ //a에서 b로 n개의 탑을 옮기고 싶다
    if(n == 2){
        s.push({a, c});
        s.push({a, b});
        s.push({c, b});
        return;
    }
    hanoi(a, c, n-1, b);
    s.push({a, b});
    hanoi(c, b, n-1, a);
    return;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if(n == 1){
        s.push({1, 3});
    }else{
        hanoi(1, 3, n, 2);
    }
    
    cout << s.size() << "\n";
    while(!s.empty()){
        pair<int, int> k = s.front(); s.pop();
        cout << k.first << " " << k.second << "\n";
    }
}
/*
스스로 힘으로 맞음!
키 포인트는 n 개의 탑이 있을 때
1. 위에 n-1 개의 탑을 1->2로 옮긴다
2. 맨 바닥에 있는 애를 1->3으로 옮긴다.
3. 2에 옮겨져 있는 n-1개 탑을 1->3으로 옮긴다.

의 과정 3개를 재귀로 짜는 방식이다.
초기 조건 n == 1 일 때 때문에 거의 100% 맞았는데 2번이나 틀렸다 ㅠㅠ
*/