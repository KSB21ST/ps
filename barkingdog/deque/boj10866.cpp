#include <bits/stdc++.h>

using namespace std;
int main(){
    int N;
    cin >> N;
    deque<int>D;
    while(N--){
        string s;
        cin >> s;
        if(s == "push_front"){
            int n;
            cin >> n;
            D.push_front(n);
        }else if(s == "push_back"){
            int n;
            cin >> n;
            D.push_back(n);
        }else if(s == "pop_front"){
            if(D.empty()) cout << -1 << "\n";
            else {
                cout << D.front() << "\n";
                D.pop_front();
            }
        }else if(s == "pop_back"){
            if(D.empty()) cout << -1 << "\n";
            else {
                cout << D.back() << "\n";
                D.pop_back();
            }
        }else if(s == "size"){
            cout << D.size() << "\n";
        }else if(s == "empty"){
            cout << D.empty() << "\n";
        }else if(s == "front"){
            if(D.empty()) cout << -1 << "\n";
            else cout << D.front() << "\n";
        }else if(s == "back"){
            if(D.empty()) cout << -1 << "\n";
            else cout << D.back() << "\n";
        }
    }
}
/*(쉬움)*/