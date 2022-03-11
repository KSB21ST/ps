#include <bits/stdc++.h>

using namespace std;

int N, n, arr[20000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> n;
        arr[n+10000000]++;
    }

    cin >> n;
    int temp;
    for (int j=0;j<n;j++){
        cin >> temp;
        if (arr[temp+10000000]){
            cout << 1 << ' ';
        }else{
            cout << 0 << ' ';
        };
    }
}