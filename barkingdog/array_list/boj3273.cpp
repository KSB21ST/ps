#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n;
    vector<int>v(n);
    for(auto &k:v){
        cin >> k;
    }
    cin >> x;
    vector<int>num(x+1);
    for(auto k:v){
        if(k<=x){
            num[k]++;
        }
    }
    
    int ans = 0;
    for(auto k:v){
        if(k<=x){
            ans += min(num[k], num[x-k]);
        }
    }
    cout << ans/2;
}