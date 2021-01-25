#include<bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int y = 0;
    int m = 0;
    vector<int>v(n);
    for(auto &k:v){
        cin >> k;
        y += (k/30 + 1)*10;
        m += (k/60 + 1)*15;
    }
    if(y == m){
        cout << "Y " << "M " << y;
    }else if(y > m){
        cout << "M " << m;
    }else{cout << "Y "<< y;}
}