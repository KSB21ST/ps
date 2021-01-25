#include <bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int>v(20);

    for(int i = 0;i<20;i++){
        v[i] = i+1;
    }

    for(int j=0;j<10;j++){
        int start, end;
        cin >> start >> end;
        // cout << start << " " << end << "\n";
        reverse(v.begin() + start - 1, v.begin() + end);
    }

    for(auto k:v){
        cout << k << " ";
    }
}

//vector의 reverse 함수 주의