#include <bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, v;
    cin >> n;
    vector<int>num(n);
    for(auto &k:num){
        cin >> k;
    }
    cin >> v;
    int sum = 0;
    for(auto k:num){
        if(k == v){sum++;}
    }
    cout << sum;
}