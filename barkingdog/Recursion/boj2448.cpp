#include <bits/stdc++.h>
using namespace std;
vector<string>v;
void star(int n){
    if(n == 3){
        v.push_back("  *  ");
        v.push_back(" * * ");
        v.push_back("*****");
        return;
    }
    star(n/2);
    string blank = "";
    vector<string>nv;
    for(int i=0;i<n/2;i++){
        blank = "";
        for(int j=0;j<n/2;j++) blank += " ";
        nv.push_back(blank + v[i] + blank);
    }
    for(int i=n/2;i<n;i++){
        nv.push_back(v[i-n/2] + " " + v[i-n/2]);
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
한 방에 맞음. boj2447 별 찍기 - 10 처럼 한 줄 한 줄 vector에 넣어주면 됨.
삼각형을 둘러싼 사각형 단위로 움직인다고 생각.
그러면 삼각형을 둘러싼 사각형을 위, 아래 반으로 나눌 수 있는데
위쪽 직사각형에는 삼각형 1개 있고, 아래쪽에는 2개 삼각형 (실제로는 그 삼각형을 둘러싼 사각형이 서로 붙어 있는 형태)
*/