#include <bits/stdc++.h>

using namespace std;
int main(){
    int N;
    cin >> N;
    queue<int>q;
    while(N--){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int n;
            cin >> n;
            q.push(n);
        }else if(cmd == "pop"){
            if(!q.empty()) {cout << q.front() << "\n";q.pop();}
            else cout << -1 << "\n";
        }else if(cmd == "size"){
            cout << q.size() << "\n";
        }else if(cmd == "front"){
            if(!q.empty()) cout << q.front() << "\n";
            else cout << -1 << "\n";
        }else if(cmd == "back"){
            if(!q.empty()) cout << q.back() << "\n";
            else cout << -1 << "\n";
        }else if(cmd == "empty"){
            if(q.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}