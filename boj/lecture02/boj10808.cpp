#include <bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    // char char_array[s.length()];
    vector<int>v(26);
    // strcpy(char_array, s.c_str());
    //ascii code (int)'a' = 97
    for(auto k:s){
        v[(int)k - 97] += 1;
    }
    for(auto k:v){
        cout << k << " ";
    }
}

/*처음에는 s 에 있는 char 들을 char_array에 넣으려고 했다. 자꾸만 
런타임 에러(invalid pointer)가 난다. 대체 왜??
s를 for(auto k:s) 로 돌려서 벡터에 넣었더니 잘 된다.
왜 런타임 에러가 난거지???
*/