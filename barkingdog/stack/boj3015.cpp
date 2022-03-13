#include <bits/stdc++.h>

using namespace std;
#define x first
#define y second
int main(){
    int N;
    cin >> N;
    stack< pair<long long, int> >s;
    int sum = 0;
    for(int i=0;i<N;i++){
        long long height;
        cin >> height;
        int cnt = 1;
        while(!s.empty() && s.top().x <= height){
            sum += s.top().y;
            if(s.top().x == height) cnt += s.top().y;
            s.pop();
        }
        if(!s.empty()) sum++;
        s.push(make_pair(height, cnt));
    }
    cout << sum;
}

/*
많이 헷갈리는 문제였고, 다시 풀어보아야 하는 문제이다.
가장 기본적인 뼈대는 
while(!s.empty() && s.top().first < h){
    s.pop();
}
s.push(make_pair(h, cnt));
에서 시작한다. 다만 (first, second) 에서 first 값은 주어진 height,
그리고 second 값이 ****같은 height인 원소가 연속으로 나오면 그 개수를 세주는 역할*** 을 한다.
처음에는 index 라고 생각해서 헷갈렸다. stack 에 같은 값의 원소가 연속으로 두 개 이상 저장되지 않기 위한 장치이다.
while 룹 안에 있는 sum += ~; 와 while 룹 바깥에 있는 sum++;는 각각 뒤와 앞의 숫자와의 쌍을 세준다.
예를 들어
4 1 2
이렇게 수열이 있을 때 처음에 스택에 1이 추가되었을 때 20번째 줄 sum++; 로 (4, 1) 개수를 세주고,
나중에 2가 들어와서 1 이 pop() 될 때 16번째 줄 sum+=~; 로 (1, 2) 개수를 세준다.

암튼 헷갈리는 문제이니 한 번 더 풀어봐야 한다!
*/