#include <bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q[2000001];
    int head = 0; // index of head
    int tail = 0; // index of tail
    int len = 0; // length of total queue
    int N;
    cin >> N;
    while(N--){
        string s;
        cin >> s;
        if(s == "push"){
            int n;
            cin >> n;
            q[head+len] = n;
            len++;
        }else if(s == "pop"){
            if(len == 0) cout << -1 << "\n";
            else{
                cout << q[head] << "\n";
                head++;
                len--;
            }
        }else if(s == "empty"){
            if(len) cout << 0 << "\n";
            else cout << 1 << "\n";
        }else if(s == "front"){
            if(len>0) cout << q[head] << "\n";
            else cout << -1 << "\n";
        }else if(s == "back"){
            if(len > 0)cout << q[head+len-1] << "\n";
            else cout << -1 << "\n";
        }else if(s == "size"){
            cout << len << "\n";
        }
    }
}
/*
10845와 거의 비슷하지만, 풀이를 그대로 쓰면 시간초과가 난다... 라고 생각해서 array버전으로 만들었건만..
결국 문제는 ios::sync_with_stdio(0); cin.tie(0); 였다.
array 버전도 제출해보니 맞음 (뿌듯)
*/