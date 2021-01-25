#include<bits/stdc++.h>


using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, product;
    vector<int>v(10);
    string p;
    cin >> a >> b >> c;
    product = a*b*c;
    p = to_string(product);
    char char_array[p.length()];
    strcpy(char_array, p.c_str());
    for(auto k:char_array){
        int temp = (int)k - 48;
        v[temp] += 1;
    }
    for(auto k:v){
        cout << k << "\n";
    }
}