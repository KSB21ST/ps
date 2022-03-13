#include <bits/stdc++.h>

using namespace std;
int main(){
    int n, m;
    cin >> n;
    cin >> m;
    deque<int>D;
    for(int i=1;i<n+1;i++)
        D.push_back(i);
    int total = 0;
    while(m--){
        int t;
        cin >> t;
        int cnt = 0;
        for(auto k:D){
            if(k == t) break;
            cnt++;
        }
        // cout << "cnt: " << cnt << " size: " << D.size()/2 << "\n";
        if(cnt <= D.size()/2){ //뒤로 접근해야 한다
            while(D.front() != t){
                int temp = D.front();
                D.pop_front();
                D.push_back(temp);
                total++;
            }
            D.pop_front();
            // cout << "1st total: " << total << "\n";
        }else{ //앞으로 접근해야 한다.
            while(D.front() != t){
                int temp = D.back();
                D.pop_back();
                D.push_front(temp);
                total++;
            }
            D.pop_front();
            // cout << "2nd total: " << total << "\n";
        }
    }
    cout << total;
}
/*
한 방에 맞음! (뿌듯)
다만 deque 를 쓸 수 있다는 걸 생각했기 때문에 빨리 푼듯.
실제로 순환 queue로 구현하려 했다면 오래 걸렸을 듯.
*/