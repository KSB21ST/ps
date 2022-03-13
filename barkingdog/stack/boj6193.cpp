#include <bits/stdc++.h>

using namespace std;

stack<int>s;

int main(){
    int N;
    cin >> N;
    long long cnt = 0;
    s.push(1000000001);
    for(int i=0;i<N;i++){
        int height;
        cin >> height;
        while(s.top() <= height){
            s.pop();
        }
        cnt += s.size()-1;
        s.push(height);
    }
    cout << cnt;
}

/*
내가 생각했던 알고리즘이 맞았다.
그러나 구현 과정에서 딱 15번에서 등호 안 붙여줘서 틀림.
알고리즘 방식은 boj2493 과 매우 비슷!
특정 방향으로 포인터가 이동하면서 작거나 큰 수의 개수를 구해야하는 문제 -> 스택
top() 과 새로 입력된 수를 비교하면서 작거나 크면 pop() 시키기
*/