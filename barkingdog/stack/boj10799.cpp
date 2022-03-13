#include <bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a;
    cin >> a;
    stack<char>s;
    int cnt = 0;
    int lazer = 0;
    int total = 0;
    char prev = 0;
    for(auto l:a){
        if(l=='(') {s.push(l);total++;prev=1;}
        else{
            s.pop();
            if(prev) {lazer++;cnt += s.size();}
            prev = 0;
        }
    }
    int stick = total - lazer;
    int ans = stick + cnt;
    cout << ans;
}

/*
스스로 풀어서 한 번에 맞춤 (뿌듯)
핵심은 레이저가 나올 떄마다 스택에 쌓여 있는 막대의 개수만큼 더해주는 거다.
막대를 한 번 자르면 1개 -> 2개 가 되기 떄문이다. (반드시 한 번 자르면 하나가 늘어남 -> 레이저 개수로 늘어난 막대 개수 = 잘린 막대의 개수 = 스택에 아직 묶여있는 막대 개수)
+ 기존의 막대 개수를 나중에 더해주어야 하기 때문에 (총 쌍의 개수) - (레이저 개수) 를 22번째 줄에 해준다.
*/