#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int j=0;j<n;j++){
        if(v[j]<x){cout << v[j] << " ";}
    }
    
}