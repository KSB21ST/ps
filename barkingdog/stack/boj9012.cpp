#include <bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    while(N--){
        string a;
        cin >> a;
        stack<char>s;
        int isValid = 1;
        for(auto l : a){
            if(l == '(') s.push(l);
            else{
                if(s.empty() || s.top() != '(') {
                    isValid = 0;
                    break;
                }
                s.pop();
            }
        }
        if(isValid && s.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
}
/*
스택 써야 한다는 것을 알 수만 있다면 쉬운 문제
*/