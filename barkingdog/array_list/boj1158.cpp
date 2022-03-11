#include <bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    list<int>L;
    list<int>ans;
    for(int i=1;i<=n;i++){L.push_back(i);}

    auto cursor = L.begin();
    for(int j=0;j<k-1;j++){cursor++;}
    while(n--){
        ans.push_back(*cursor);
        if(*cursor == L.back()){
            cursor = L.erase(cursor);
            cursor = L.begin();
        }
        else{cursor = L.erase(cursor);}
        for(int j=0;j<k-1;j++){
            if(*cursor == L.back()){cursor++;}
            cursor++;
        }
    }
    cout << "<";
    auto iter = ans.begin();
    for(int i=0;i<ans.size();i++){
        if(i == ans.size()-1){cout << *iter;}
        else{cout << *iter << ", ";}
        iter++;
    }
    cout << ">";
}
/*
오랫동안 풀었다(거의 1시간 반?)
원래는 큐 로 구현하면 쉽게 될 것을, 연결 리스트로 구현하느라 힘들었다
연결 리스트 iterator 가 생각보다 불편하게 구현되어 있다
dummy 노드 때문에 힘들었다
그리고 끝 원소가 바로 시작 노드를 가리키고 있지 않다 -> cursor가 마지막
노드에 오면 두 번 점프해주어야 한다
마지막 cursor를 지우고 리턴하는 cursor도 임의로 return하기 때문에 굳이 굳이 
cursor = L.begin()으로 설정을 다시 해준다
*/

/*--------------------------- 2nd try 2022.3.6 -----------------------*/
#include<bits/stdc++.h>

using namespace std;
int n, k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    int prev[n+1], next[n+1];
    int len = 0;
    vector<int>v;

    for(int i=1;i<n+1;i++){
        prev[i] = (i == 1) ? n : i - 1;
        next[i] = (i == n) ? 1 : i + 1;
        len++;
    }

    int cnt = 1;
    for(int cur=1;len > 0;cur=next[cur]){
        if(cnt == k){
            next[prev[cur]] = next[cur];
            prev[next[cur]] = prev[cur];
            len--;
            cnt = 1;
            v.push_back(cur);
            if(len == 0) break;
        }else{cnt++;}
    }

    cout << "<";
    for(auto k:v){
        if(k != v.back())
            cout << k << ", ";
        else
            cout << k;
    }
    cout << ">";
}

/*
바킹독 알고리즘을 참고해서 짰다. 
https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x04/solutions/1158.cpp
핵심은 21번째 줄 cur=next[cur] 에 있는 것 같다. 
내가 전에 짰던 방법들은 모두 k번쨰를 지우고 나서 그것이 list.end() 인지 아닌지 확인을 해야 했다. 
그래서 list.begin() 으로 가거나 그런 식으로 짰다. (그럼 엄청 불편!)
연결리스트를 간소하게 짠 방법이다.
https://github.com/encrypted-def/basic-algo-lecture/blob/master/workbook/0x04.md
별해도 있으니 나중에 다 배우고 나서 다시 참고하자
*/