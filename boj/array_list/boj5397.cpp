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