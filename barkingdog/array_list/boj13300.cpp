#include <bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int>v(12);
    while(n--){
        int s, y;
        cin >> s >> y;
        if(s==0){v[y*2-2]++;}
        else{v[y*2-1]++;}
    }
    int room = 0;
    for(auto num:v){
        if(num == 0)continue;
        if(num%k != 0){room += num/k + 1;}
        else{room += num/k;}
    }
    cout << room;
}