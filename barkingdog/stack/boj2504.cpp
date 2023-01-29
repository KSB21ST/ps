#include <bits/stdc++.h>

using namespace std;
// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     string a;
//     cin >> a;
//     stack<char>s;
//     int sum = 0;
//     int total = 0;
//     int prev = -1;
//     for(auto l : a){
//         if(l == '(' || l == '['){
//             s.push(l);
//             if(l == '(')
//                 prev = 0;
//             else
//                 prev = 1;
//         }else if(l == ')'){
//             if(!s.empty() && s.top() == '('){
//                 s.pop();
//                 if(!s.empty()) s.push('2');
//                 else{
//                     if(prev == 0)
//                         sum += 2;
//                     else
//                         sum *= 2;
//                     total += sum;
//                     sum = 0;
//                     continue;
//                 }
//             }else{
//                 while(!s.empty() && s.top() != '('){
//                     if(s.top() == '2')
//                         sum += 2;
//                     else if (s.top() == '3')
//                         sum += 3;
//                     else{cout << 0;return 0;}
//                     s.pop();
//                 }
//                 if(s.empty()){cout << 0;return 0;}
//                 s.pop();
//                 sum *= 2;
//             }
//             prev = -1;
//         }else if(l == ']'){
//             if(!s.empty() && s.top() == '['){
//                 s.pop();
//                 if(!s.empty()) s.push('3');
//                 else{
//                     if(prev == 1)
//                         sum += 3;
//                     else
//                         sum *= 3;
//                     total += sum;
//                     sum = 0;
//                     continue;
//                 }
//             }else{
//                 while(!s.empty() && s.top() != '['){
//                     if(s.top() == '2')
//                         sum += 2;
//                     else if(s.top() == '3')
//                         sum += 3;
//                     else{cout << 0;return 0;}
//                     s.pop();
//                 }
//                 if(s.empty()){cout << 0;return 0;}
//                 s.pop();
//                 sum *= 3;
//             }
//             prev = -1;
//         }
//         if(s.empty()){
//             total += sum;
//             sum = 0;
//         }
//     }
//     if(s.empty())cout << total;
//     else cout << 0;
// }
/*
위에 풀이:
생노가다로 풀었는데 풀다가 도저히 아니라고 생각해서 그만둠.
*/