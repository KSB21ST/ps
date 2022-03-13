#include <bits/stdc++.h>

using namespace std;
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int it;
    cin >> it;
    stack<int>s;
    int n;
    for(int i=0;i<it;i++){
        string l;
        cin >> l;
        if(l == "push"){
            cin >> n;
            s.push(n);
        }else if(l == "pop"){
            if(!s.empty()) {cout << s.top() << "\n"; s.pop();}
            else{cout << -1<< "\n";}
        }else if(l == "size"){
            cout << s.size()<< "\n";
        }else if(l == "empty"){
            if(s.empty()){cout << 1<< "\n";}
            else{cout << 0<< "\n";}
        }else if(l == "top"){
            if(!s.empty()) {cout << s.top()<< "\n";}
            else{cout << -1<< "\n";}
        }
    }
}