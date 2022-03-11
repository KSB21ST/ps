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

/*--------------------------2nd try 2022.3.6------------------------*/
#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    char t1 = '0';
    char t2 = '0';
    string s;
    list<char>L;
    cin >> s;
    for(auto k:s){L.push_back(k);}
    auto cursor = L.end();
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> t1;
        if(t1 == 'L'){ // L
            if(cursor != L.begin()) {cursor--;}
        }else if(t1 == 'D'){ //D
            if(cursor != L.end()) {cursor++;}
        }else if(t1 == 'B'){ //B
            if(cursor != L.begin()){cursor--;cursor = L.erase(cursor);}
        }else if(t1 == 'P'){ //P
            cin >> t2;
            L.insert(cursor, t2);
        }
    }
    for(auto n:L){cout << n;}
}
/*
iterator 개념을 잘 알아두어야 할 것 같다.
B 에서 cursor--; 를 하지 않고 바로 cursor=L.erase(cursor); 을 하였더니 malloc 되지 않은 걸 access 해서 나오는 에러가 났다.
*/