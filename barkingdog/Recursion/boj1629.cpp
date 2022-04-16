#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll recur(ll a, ll b, ll c){
    if(b == 1){
        return a % c;
    }
    ll val = recur(a, b/2, c);
    ll ans = val * val % c;
    if(b % 2 == 0){ //b가 짝수일 때
        return ans;
    }else{ //b가 홀수일 떄
        return ans * a % c;
    }
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(b == 0){
        cout << a % c;
        return 0;
    }
    int ans = recur(a, b, c);
    cout << ans;
}
/*
바킹독보고 맞춤..
*/