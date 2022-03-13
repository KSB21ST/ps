#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin >> n;
    queue<int>q;
    for(int i=1;i<n+1;i++){
        q.push(i);
    }
    while(1){
        if(q.size() == 1){
            cout << q.front();
            return 0;
        }
        q.pop();
        if(q.size() == 1){
            cout << q.front();
            return 0;
        }
        int front = q.front();
        q.pop();
        q.push(front);
    }
}
/*
한 방에 맞음!(뿌듯)
그러나 문제는 쉬움
*/