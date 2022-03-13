#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define x first
#define y second
int main(){
    while(1){
        int n;
        cin >> n;
        if(n==0) return 0;
        stack< pair<ll, ll> >s; //((height, number of same heighted graph)
        ll max_total = 0;
        for(int i=1;i<n+1;i++){
            ll h;
            cin >> h;
            ll cnt = 0;
            while(!s.empty() && s.top().x >= h){
                cnt += s.top().y;
                if(max_total < cnt*s.top().x) max_total = cnt*s.top().x;
                s.pop();
            }
            s.push(make_pair(h, cnt+1));
            cout << "push: " << s.top().x << " " << s.top().y << "\n";
        }
        ll cnt = 0;
        while(!s.empty()){
            cnt += s.top().y;
            if(max_total < s.top().x*cnt) max_total = cnt*s.top().x;
            s.pop();
        }
        cout << max_total << "\n";
    }
}
/*
온전히 내 힘으로 맞춤! (2시간 걸림.. 흐어엉 ㅠㅠ)
키 아이디어는 우선 스택을 (다른 스택 문제들과 달리) 오름차순으로 정렬하는 것이다. (다른 유형은 거의 내림차순이었다)
그 이유는 내림차순으로 정렬하면, 예를 들어
4 3 1
이런식으로 정렬하면 1을 pop 할 때 1의 height 를 기억해줬다가 1*3 이 큰지, 3*2 이 큰지, 4*1 이 큰지를 비교해줘야 하는데 매우 불편하기 떄문이다.
그 대신
1 3 4
이런식으로 정렬하면 초기 cnt = 0 으로 두고 4 를 pop 할 때 cnt+=1 한 후 cnt*4 의 값을 글로벌 max 값과 비교해주고.
그 후에 3이 pop 할 때 cnt += 1 한 후 다시 cnt*3 의 값을 글로벌 max 값과 비교해주는 식으로 하면
cnt 에 이미 pop이 되었고 지금의 나보다 높이가 높은 애들의 개수를 누적해서 저장해둘 수 있다.
이 부분이 바로 27번째 줄부터 31번째 줄 까지의 내용이다.

그리고
1 3 5 에서 2 가 더 들어오려고 할 때 2보다 큰 값인 3 과 5를 pop 해주어야 하는데,
이 때 3 과 5 모두 크기가 2인 막대를 포함할 수 있으므로
3과 5를 pop 할 때마다 cnt++ 하여 마치 2 짜리 막대가 여러가지 있는 것처럼 만들어줄 수 있다.
또한, 3 과 5를 pop 할 때마다 아까처럼 5가 Pop 한 후 그 값을 누적하여 3이 pop 할 때는 3*2 이렇게 계산할 수 있다.
만약 이 값이 기존의 max_size 보다 크면 max_size 를 갱신한다.
이런 식으로 어떤 수 A 가 스택에 삽입될 때 A 보다 큰 막대들은 A 와 같은 크기들의 막대가 여러개 있는것처럼 생각해서 A 개수를 늘려주고.
필요하면 max_size 를 갱신할 수 있다
*/