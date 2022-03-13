#include <bits/stdc++.h>

using namespace std;
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int k;
    cin >> k;
    stack<int>s;
    for(int i=0;i<k;i++){
        int n;
        cin >> n;
        if(n == 0){
            if(!s.empty())s.pop();
        }else{
            s.push(n);
        }
    }
    int sum = 0;
    while(!s.empty()){
        sum += s.top();
        s.pop();    
    }
    cout << sum;
}
/*
스택 자료구조만 알고 있으면 너무 쉽다. 
다만 스택 iteration은 for(auto k:s){} 이런 형태로 안 되는 것을 기억할 것!
*/