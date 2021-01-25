#include <bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long a, b;
    int gap;
    cin >> a >> b;
    long long big = max(a, b);
    long long small = min(a, b);
    if(big != small){
        gap = (int)(big - small - 1);
    }else{gap = 0;}
    cout << gap << '\n';
    for(long long i=small+1;i<big;i++){
        cout << i << " ";
    }
}

//long long 이 문제였다. 1<= a, b <= 10^15 인데 int의 최댓값은 10^10 이다.