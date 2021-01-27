#include <bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string n;
    cin >> n;

    vector<int>v(10);
    for(auto k: n){v[(int)k-'0']++;}
    if(v[9]>=v[6]){v[9] = (v[9] - v[6] + 1) / 2 + v[6];}
    else{v[6] = (v[6] - v[9] + 1) / 2 + v[9];}
    int max_n = 0;
    for(auto k:v){max_n = max(max_n, k);}
    cout << max_n;
}