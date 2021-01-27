#include <bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    while(n--){
        string print = "Possible";
        string s1, s2;
        vector<int>v1(26);
        vector<int>v2(26);
        cin >> s1 >> s2;
        for(auto k:s1){v1[(int)k - 'a']++;}
        for(auto k:s2){v2[(int)k - 'a']++;}
        for(int j=0;j<26;j++){
            if(v1[j] != v2[j]){
                print = "Impossible";
                break;
            }
        }
        cout << print << "\n";
    }
}