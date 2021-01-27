#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s1, s2;
    vector<int>v1(26);
    vector<int>v2(26);
    cin >> s1;
    cin >> s2;
    for(auto k1:s1){v1[(int)k1-'a']++;}
    for(auto k2:s2){v2[(int)k2-'a']++;}
    int sum = 0;
    for(int i=0;i<26;i++){
        sum+=max(v1[i], v2[i]) - min(v1[i], v2[i]);
    }
    cout << sum;
}

/*
알파벳을 대표하는 26개 원소를 가진 배열을 만들고
두 string에 알파벳이 각각 몇 개씩 있는지 세준 다음
두 리스트의 오차를 빼주면 구할 수 있다.
O(N+M+26)
*/