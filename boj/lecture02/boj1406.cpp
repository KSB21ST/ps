#include <bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s("");
    int n;
    cin >> s;
    cin >> n;
    int cursor = s.length();

    char cmd;
    string cmd2;
    for(int i=0;i<n;i++){
        cin >> cmd;
        if((int)cmd == 80){
            cin >> cmd2;
            s.insert(cursor, cmd2);
            cursor++;
        }
        else if((int)cmd == 76){
            if(cursor == 0){continue;}
            cursor--;
        }
        else if((int)cmd == 68){
            if(cursor == s.length()){continue;}
            cursor++;
        }
        else if((int)cmd == 66){
            if(cursor == 0){continue;}
            s.erase(cursor-1, 1);
            cursor--;
        }
    }
    cout << s;
    // cout << endl << s << " cursor: " << cursor;
    // cout << (int)'P' << endl << (int)'L' << endl << (int)'D' << endl << (int)'B';
    //(int)'P' = 80, (int)'L' = 76, (int)'D' = 68, (int)'B' = 66
}