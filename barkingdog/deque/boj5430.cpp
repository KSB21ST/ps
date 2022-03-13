#include <bits/stdc++.h>

using namespace std;
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int N;
    cin >> N;
    while(N--){
        deque<int>D;
        string cmd;
        string arr;
        int n;
        int error = 0;
        int ch = 0;
        cin >> cmd;
        cin >> n;
        cin >> arr;
        /*파싱할 때 두 자리수, 세자리수일 경우 생각해주기*/
        int cur_c = 0;
        for(auto c : arr){
            if(c == '[') continue;
            else if((c == ',' || c == ']') && n != 0) {
                D.push_back(cur_c);
                cur_c = 0;
            }else{
                cur_c = 10*cur_c + (int)(c - '0');
            }
        }
        for(auto k:cmd){
            if(k == 'R'){
                if(ch)  ch = 0;
                else ch = 1;
            }else if(k == 'D'){
                if(D.empty()){error = 1;break;}
                if(!ch)
                    D.pop_front();
                else
                    D.pop_back();
            }
        }
        if(!error){
            if(ch)
                reverse(D.begin(), D.end());
            cout << "[";
            for(int j=0;j<D.size();j++){
                cout << D[j];
                if(j != D.size()-1)
                    cout << ",";
            }
            cout << "]\n";
        }else{
            cout << "error" << "\n";
        }
    }
}

/*
방법론은 쉬웠지만, (R 이 나왔을 때 deque를 실제로 뒤집는 게 아니라 ch 변수만 바꿔주기 마치 스위치처럼)
파싱과 프린트하는 게 쓸데없이 까다로웠다.
특히 input을 deque로 파싱할 때 두 자리수를 생각 못했다.
*/