#include <bits/stdc++.h>
using namespace std;
string s1 = "***";
string s2 = "* *";
vector<string>v;
void star(int n){
    if(n == 3){
        v.push_back(s1);
        v.push_back(s2);
        v.push_back(s1);
        return;
    }
    star(n/3);
    int nn = n/3;
    vector<string>nv;
    for(int i=0;i<nn;i++){
        // cout << "\npush back1\n";
        // cout << v[i] + v[i] + v[i];
        nv.push_back(v[i] + v[i] + v[i]);
    }
    for(int i=nn;i<nn*2;i++){
        string t = "";
        for(int j=0;j<nn;j++) t+= " ";
        // cout << "\npush back2\n";
        // cout << v[i-nn] + t + v[i-nn];
        nv.push_back(v[i-nn] + t + v[i-nn]);
    }
    for(int i=nn*2;i<n;i++){
        // cout << "\npush back3\n";
        // cout << v[i -nn*2] + v[i -nn*2] + v[i -nn*2];
        nv.push_back(v[i -nn*2] + v[i -nn*2] + v[i -nn*2]);
    }
    v = nv;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    star(N);
    for(auto k:v){
        cout << k << "\n";
    }
}

/*
한 번에 맞아서 기분이 좋다
평행하게 이어붙일 수 있는 방법이 무엇이 있을까 생각해보았다.
결국에는 각 줄을 vector에 string으로 넣어두고 
각 줄을 iterate 하면서 N * N 으로 크게 보고 9사분면으로 보았을때 
첫째 줄은 3개 111 이런식으로 이어붙이고
둘째 줄은 101 이런식으로
막줄은 111 이렇게 이어붙이는 것으로 재귀를 짰다
주의할 건 여기서 1은 9사분면에서 1사분면 (제일 왼쪽 제일 위) 에 해당하는 패턴이라는 것이다
*/