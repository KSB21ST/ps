#include <bits/stdc++.h>

using namespace std;
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     int n;
//     cin >> n;
//     for(int j = 0;j<n;j++){
//         string s;
//         cin >> s;
//         list<char>ans;

//         auto pointer = ans.end();
//         for(auto k:s){
//             if(k == '<'){
//                 if(pointer != ans.begin()){
//                     pointer--;
//                 }
//             }
//             else if(k == '>'){
//                 if(pointer != ans.end()){pointer++;}
//             }
//             else if(k == '-'){
//                 if(pointer != ans.begin()){
//                     pointer--;
//                     pointer = ans.erase(pointer);
//                 }
//             }
//             else{
//                 // cout<<"endter else"<<endl;
//                 ans.insert(pointer, k);
//                 // cout << "finish else" << endl;
//             }
//             // cout << "ans : " ;
//         }
//         for(auto in: ans){cout << in;}
//         cout << "\n";
//     }
// }
/*
boj1406(에디터)문제와 연관이 크다
처음에는 입력된 s 를 list로 옮겨서 동시에 두 개의 list 를 다루려고 했다는 것이 실수였다
그것 때문에 많이 헤맸다
결국에는 입력되 s 를 한 번씩 돌면서 명령어가 나오면 ans list에 따로 처리해줌
*/

/*----------------------- 2nd try 2022.3.6 ---------------------*/
int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        list<char>L;
        list<char>ans;
        cin >> s;
        for(auto k:s){L.push_back(k);}
        auto cursor = ans.end();
        auto index = L.begin();
        for(auto index:s){
            if(index == '<'){
                if(cursor != ans.begin()){cursor--;}
            }else if(index == '>'){
                if(cursor != ans.end()){cursor++;}
            }else if(index == '-'){
                if(cursor != ans.begin()){ /******이 부분을 놓쳤다*/
                    cursor--;
                    cursor = ans.erase(cursor);
                }
            }else{
                ans.insert(cursor, index);
            }
        }
        for(auto m:ans){cout << m;}
        cout << "\n"; /*얘 안 넣으면 틀림... 왜 때문에????*/
    }
}  
/*
구현하는데 겁나 오래걸림.. ㅠㅠㅠㅠㅠ 왜 ㅠㅠㅠㅠㅠㅠ
1. 아이디어는 대략적으로 알겠으나, 실제 구현 - 특히 iterator를 이용한 cursor 때문에 애를 먹음
2. cursor의 위치를 확실하게 정해두고 (얘를 들어 cursor가 A라고 나오면 A 앞쪽에 커서 있는 것으로 생각) 디버깅하는게 좋았을 듯
3. 예외 케이스들 - 커서가 맨 앞에 있을 떄, 맨 뒤에 있을 때 주의해서 짜기
4. 틀만 정립할 수 있다면 아이디어는 쉬웠다
*/