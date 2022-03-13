#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int cnt = 0;
    while(N--){
        string a;
        cin >> a;
        stack<char>s;
        for(auto l : a){
            if(l == 'A'){
                if(s.empty() || s.top() == 'B') s.push(l);
                else s.pop();
            }else if(l == 'B'){
                if(s.empty() || s.top() == 'A') s.push(l);
                else s.pop();
            }
        }
        if(s.empty()) cnt++;
    }
    cout << cnt;
}
/*
한 방에 맞음!
핵심은 stack.top() 이 input 으로 들어온 숫자랑 동일하면 바로 pop 해주고. 아니면 push -> '좋은문자' 면 끝에 stack 이 empty 여야한다.
*/