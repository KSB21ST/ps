#include <bits/stdc++.h>
//2440 ~ 2443

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    /*
    for(int i=1;i<=n;i++){
        string s = "";
        int k = 2*i-1;
        s.append(i, '*');
        s.append(2*(n-i), ' ');
        s.append(i, '*');
        cout << s << "\n";
    }
    for(int i=n-1;i>=1;i--){
        string s = "";
        int k = 2*i-1;
        s.append(i, '*');
        s.append(2*(n-i), ' ');
        s.append(i, '*');
        cout << s << "\n";
    }
    */
    for(int i=n;i>=2;i--){
        string s = "";
        int k = 2*i-1;
        s.append(n-i, ' ');
        s.append(k, '*');
        cout << s << "\n";
    }
    for(int i=1;i<=n;i++){
        string s = "";
        int k = 2*i-1;
        s.append(n-i, ' ');
        s.append(k, '*');
        cout << s << "\n";
    }
   
}