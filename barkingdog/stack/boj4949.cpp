#include <bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        string a;
        getline(cin, a);
        stack<char>s;
        int succ = 1;
        if(a == ".") return 0;
        for(auto l : a){
            if(l == '('){
                s.push('(');
            }else if(l == '['){
                s.push('[');
            }else if(l == ')'){
                if(s.empty()){
                    succ = 0;
                    break;
                }
                if(s.top() != '('){
                    succ = 0;
                    break;
                }
                s.pop();
            }else if(l == ']'){
                if(s.empty()){
                    succ = 0;
                    break;
                }
                if(s.top() != '['){
                    succ = 0;
                    break;
                }
                s.pop();
            }
        }
        if(succ && s.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }

}
/*
방법론은 이미 스택을 써야한다는 걸 안다면 쉬웠지만, 마지막에 디테일로
40번째 줄에서 s.empty() 인지 확인하는 것을 잊었다. 주의하자.
*/