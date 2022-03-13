#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int main(){
    int N;
    cin >> N;
    stack< pair<int, int> >s;
    int ans[N+1];
    s.push(make_pair(1000001, 0));
    for(int i=1;i<N+1;i++){
        ans[i] = 0;
        int A;
        cin >> A;
        while(s.top().x < A){
            ans[s.top().y] = A;
            s.pop();
        }
        s.push(make_pair(A, i));
    }
    for(int j=1;j<N+1;j++){
        if(!ans[j]){cout << "-1 ";}
        else{cout << ans[j] << " ";}
    }
}
/*
처음으로 한 방에 온전히 내가 짠 코드로 맞음. 
while(s.top()<height){
    s.pop()
}
s.push(A)
이 꼴, 이 유형을 외워두면 유용하다.
또한 답이 되는 수열이 저장이 필요한지 안 한지 판단해서
별도의 답을 위한 자료구조를 만드는 게 좋다
*/