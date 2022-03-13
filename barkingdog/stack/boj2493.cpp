#include <bits/stdc++.h>

using namespace std;
/*
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int n;
    cin >> n;
    int index = 0;
    stack<int>s;
    stack<int>s2;
    stack<int>ans;
    while(index < n){
        int t;
        cin >> t;
        s.push(t);
        index++;
    }
    int cur_n = n;
    while(cur_n > 0){
        int cur = s.top();
        s.pop();
        int recv_n = cur_n -1;
        while(!s.empty()){
            if(s.top() > cur){
                ans.push(recv_n);
                break;
            }
            s2.push(s.top());
            s.pop();
            recv_n--;
        }
        if(recv_n <= 0){ans.push(0);}
        while(!s2.empty()){
            s.push(s2.top());
            s2.pop();
        }
        cur_n--;
    }
    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }
}
// 시간 초과 나는 풀이
*/

/*
int main(){
    int n;
    cin >> n;
    stack<int>s;
    stack<int>s2;
    stack<int>ans;
    for(int i=0;i<n;i++){
        int t;
        cin >> t;
        s.push(t);
    }
    int idx = n;
    int cnt = 0;
    while(idx > 1){
        int cur = s.top();
        while(cur>=s.top()){
            s2.push(s.top());
            s.pop();
            if(s.empty()){idx=0;break;}
            idx--;
        }
        ans.push(idx);
        while(!s2.empty() && cur != s2.top()){
            s.push(s2.top());
            s2.pop();
            idx++;
        }
    }
    cout << "0 ";
    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}
*/
/*이것도 시간초과..*/


/*
바킹독 풀이
그동안 입력받은 height들을 스택에 저장해두는데, 
만약 스택에서 얘(stack의 top)보다 오른쪽으로 입력받은 애들 중 height 더 큰 애가 있으면 지워버린다.
*/
#define X first
#define Y second

int N;
stack< pair<int,int> > tower;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;  
  tower.push(make_pair(100000001, 0));
  for (int i = 1; i <= N; i++) {
    int height;
    cin >> height;
    while (tower.top().X < height)
      tower.pop();    
    cout << tower.top().Y << " ";
    tower.push(make_pair(height, i));      
  }
}