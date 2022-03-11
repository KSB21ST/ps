#include <bits/stdc++.h>

using namespace std;
int n, m, temp;
int arr_p[3000000000];
int arr_n[3000000000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> temp;
        if (temp > 0) arr_p[temp]++;
        else arr_n[temp]++;
    }
    cin >> m;
    for(int j=0;j<m;j++){
        cin >> temp;
        if(arr_p[temp] > 0 || arr_n[temp] > 0) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}

/*
O(N^2)으로 짰는데 시간복잡도가 너무 크다
이를 위해서 정렬을 사용해야 하는데 이건 나중에.. 
백준 문제집 단기간 실력 올리가 Day1
https://www.acmicpc.net/workbook/view/10443
*/