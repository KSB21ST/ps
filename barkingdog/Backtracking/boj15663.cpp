#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int>v;
vector<pair<int, int> >v2;
int ans[9];
bool isused[9];
void func(int cnt){
    if(cnt == m){
        for(int i=0;i<m;i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }


    for(int i=0;i<n;i++){
        if(!isused[i]){
            if(i > 0 && v[i-1] == v[i] && !isused[i-1]) continue;
            ans[cnt] = v[i];
            isused[i] = true;
            func(cnt + 1);
            isused[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    func(0);
}
/*
중복된 원소가 있을 때 자꾸 동일한 순열이 생겨서 애를 조금 먹었다.
예를 들어 1 7 9 9 가 있으면 자꾸
1 7
1 9
1 9
이런식으로 중복된 순열이 생긴다..
그래서 이전 원소랑 값이 같은데 이전 원소가 isused 가 아니면 continue하게 해주면
중복된 원소가 이전 원소 대신 쓰이는 것을 방지할 수 있다.
19번째 줄이 신의 한수였다.
그리고 vector에서 중복 제거하는 법도 배움 (아래)
*/

/*
vector에서 중복 재거하는 법
vector<int>::iterator it;
for(it = v.begin(); it != unique(v.begin(), v.end());++it){
    int c = count(v.begin(), v.end(), *it);
    v2.push_back({*it, c});
}
*/