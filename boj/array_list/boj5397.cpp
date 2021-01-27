#include <bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int j = 0;j<n;j++){
        string s;
        cin >> s;
        list<char>ans;

        auto pointer = ans.end();
        for(auto k:s){
            // cout << "k : " << k << endl;
            if(k == '<'){
                // cout<<"endter <"<<endl;
                if(pointer != ans.begin()){
                    pointer--;
                }
                // cout << "finish <" << endl;
            }
            else if(k == '>'){
                // cout<<"endter >"<<endl;
                if(pointer != ans.end()){pointer++;}
                // cout << "finish >" << endl;
            }
            else if(k == '-'){
                // cout<<"endter -"<<endl;
                if(pointer != ans.begin()){
                    pointer--;
                    pointer = ans.erase(pointer);
                }
                // cout << "finish -" << endl;
            }
            else{
                // cout<<"endter else"<<endl;
                ans.insert(pointer, k);
                // cout << "finish else" << endl;
            }
            // cout << "ans : " ;
        }
        for(auto in: ans){cout << in;}
        cout << "\n";
    }
}
/*
boj1406(에디터)문제와 연관이 크다
처음에는 입력된 s 를 list로 옮겨서 동시에 두 개의 list 를 다루려고 했다는 것이 실수였다
그것 때문에 많이 헤맸다
결국에는 입력되 s 를 한 번씩 돌면서 명령어가 나오면 ans list에 따로 처리해줌
*/