#include <bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> s;
    cin >> n;
    
    list<char>L;
    for(auto k:s){L.push_back(k);}
    auto cursor = L.end();

    for(int i=0;i<n;i++){
        char cmd;
        cin >> cmd;
        if((int)cmd == 80){//'P'
            char cmd2;
            cin >> cmd2;
            L.insert(cursor, cmd2);
        }
        else if((int)cmd == 76){//'L'
            if(cursor == L.begin()){continue;}
            cursor--;
        }
        else if((int)cmd == 68){//'D'
            if(cursor == L.end()){continue;}
            cursor++;
        }
        else if((int)cmd == 66){//'B'
            if(cursor == L.begin()){continue;}
            cursor--;
            cursor = L.erase(cursor);
        }
    }
    for(auto k:L){cout << k;}
    // cout << endl << s << " cursor: " << cursor;
    // cout << (int)'P' << endl << (int)'L' << endl << (int)'D' << endl << (int)'B';
    //(int)'P' = 80, (int)'L' = 76, (int)'D' = 68, (int)'B' = 66
}
//list의 insert, erase, iterator, begin, end 개념