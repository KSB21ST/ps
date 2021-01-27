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
    int n1 = n-k+1;
    while(n--){
        ans.push_back(*cursor);
        // cout << endl<< "erasing " << *cursor << endl;
        // cout << "last element "<< L.back() << endl;
        if(*cursor == L.back()){
            cursor = L.erase(cursor);
            cursor = L.begin();
        }
        else{cursor = L.erase(cursor);}
        // cout << "after erasing, cursor: " << *cursor << endl;
        // for(auto k:L){cout << k << " ";}
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