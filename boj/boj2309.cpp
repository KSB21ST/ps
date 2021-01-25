#include<bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int sum = 0;
    vector<int>v(9);
    vector<int>num(101);
    for(auto &k:v){
        cin >> k;
        num[k] += 1;
        sum += k;
    }
    sum = sum - 100;
    int ans1, ans2;
    for(auto k:v){
        if (num[sum - k] >= 1){
            num[k] -= 1;
            num[sum - k] -= 1;
            break;
        }
    }
    sort(v.begin(), v.end());
    for(auto k:num){
        cout << k << "\n";
        for(int i=0;i<num[k];i++){
            cout << k << "\n";
        }
    }

}