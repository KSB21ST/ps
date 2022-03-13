#include <bits/stdc++.h>

using namespace std;
#define x first
#define y second
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin >> n;
    cin >> l;
    deque<pair<int, int> >D;
    int end = 1;
    while(n--){
        int start = end-l+1 > 1 ? end-l+1 : 1;
        int temp;
        cin >> temp;
        if(D.empty()) D.push_back(make_pair(temp, 1));
        else{
            while(!D.empty() && D.back().x > temp)
                D.pop_back();
            D.push_back(make_pair(temp, end));
        }
        if(D.front().y < start)
            D.pop_front();
        cout << D.front().x << " ";
        // cout << "idx: " << end << " D: ";
        // for(auto k:D) cout << k << " ";
        // cout << "\n";
        end++;
    }
}
/*
스스로 풀어서 맞춤! (눈물나뮤ㅠ)
처음에는 모든 수를 D 에 받고서 순회하는 식으로 풀었는데 그러면 배열로 푸는 것과 다름이 없다 -> 시간초과 남
핵심은 마치 스택 풀 때처럼 오름차순으로 정리하는 것!
다만 스택으로는 풀 수 없는 이유는, 오른쪽으로 계속 슬라이딩을 해줘야 하기 때문에 front 를 지워줘야 한다.
그래서 (value, index) 이렇게 pair 로 저장해주고 index 가 슬라이드 안에 포함되어있지 않으면 pop_front 를 해주어야 한다.
그런데 그러면 어느 순간 D 가 empty() 가 되어버리지 않을까?
그럴 일은 없는게, 만약 pop_front() 해야 하는 수가 정녕 min 이었다면 min 이 저장된 순간부터 그 후에 계속 더 큰 값이 쌓이기 때문에 
(또한 22번째 줄에서 temp 를 push 해줬기 때문에)
pop_front() 해도 D.size() 는 적어도 1 이상이다.
*/