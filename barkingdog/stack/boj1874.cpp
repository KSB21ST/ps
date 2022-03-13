#include <bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    // stack<int>s;
    vector<int>s;
    vector<char>ans;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        s.push_back(t);
    }
    int prev = 0;
    int cur = 0; 
    int len = 0;
    int index = 0;
    while(index < n){
        cur = s[index];
        if(cur > len){
            while(len < cur){
                // cout << '+' << '\n'; 
                ans.push_back('+');
                len++;
            }
            // cout << '-' << '\n';
            ans.push_back('-');
        }else{
            if(cur > prev){ /*왜 안돼지??? ㅠㅠㅠㅠㅠㅠㅠ*/
                cout << "NO" << '\n';
                return 0;
            }
            // cout << '-' << '\n';
            ans.push_back('-');
        }
        prev = cur;
        // s.pop();
        index++;
    }
    for(auto k:ans){cout << k << '\n';}
}
/*
내가 처음에 짠 풀이. 40 ~ 50분 정도 걸린 것 같다.
74 % 정도 맞는다.
32번째 줄이 문제인 것 같은데, 왜 문제인지 모르겠다 ㅠㅠ
그 후에 바킹독 정답 알고리즘 봄.
*/

/*바킹독 알고리즘이지만, 내가 다시 짜봄*/
/*
핵심은 마치 수열을 만들기 위해 시행했던 push, pop를 재연해본다는 생각으로 접근하는 것이다.
예를 들어 첫 수가 4가 출력이 되었으면,
그 전에 1, 2, 3, 4 가 먼저 push 가 된 후 pop 을 한 번 시행해줘야 하므로.
그 후에 3이 출력되기 위해서는 pop 이 다시 출력되어야 한다.
*/
#include <bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    stack<int>s;
    vector<char>ans;
    int len = 1;
    while(n--){
        int cur;
        cin >> cur;
        while(cur >= len){
            s.push(len++);
            ans.push_back('+');
        }
        if(s.top() != cur){
            cout << "NO\n";
            return 0;
        }
        s.pop();
        ans.push_back('-');
    }
    for(auto iter:ans){cout << iter << '\n';}
}