#include <bits/stdc++.h>
using namespace std;
char board[65][65];
stack<int>q;

int quad(int n, int a, int b){
    // cout << "N: " << n << "\n";
    int ans = 2;
    stack<int>temp1;
    if(n == 1){
        if(board[a][b] == '0'){
            q.push(0);
            ans = 0;
        }else{
            q.push(1);
            ans = 1;
        }
        // cout << "\nqueue before\n";
        // while(!q.empty()){
        //     int t = q.top(); q.pop();
        //     temp1.push(t);
        // }
        // while(!temp1.empty()){
        //     int t = temp1.top(); temp1.pop();
        //     cout << t << " ";
        //     q.push(t);
        // }
        // cout << "\n";
        return ans;
    }
    q.push(-1);
    // cout << "\nqueue before\n";
    // while(!q.empty()){
    //     int t = q.top(); q.pop();
    //     temp1.push(t);
    // }
    // while(!temp1.empty()){
    //     int t = temp1.top(); temp1.pop();
    //     cout << t << " ";
    //     q.push(t);
    // }
    // cout << "\n";

    int n1 = quad(n/2, a, b);
    int n2 = quad(n/2, a, b+n/2);
    int n3 = quad(n/2, a + n/2, b);
    int n4 = quad(n/2, a + n/2, b + n/2);
    // cout << "n: " << n << " n1: " << n1 << " n2: " << n2 << " n3: " << n3 << " n4: " << n4 << "\n";
    if(n1 == n2 && n2 == n3 && n3 == n4 && (n1 != 2)){
        // if(q.top() == -2) q.pop();
        while(q.top() == n1) {
            q.pop();
        }
        if(q.top() == -1) q.pop();
        q.push(n1);
        return n1;
    }
    q.push(-2);

    // cout << "\nqueue after\n";
    // stack<int>temp;
    // while(!q.empty()){
    //     int t = q.top(); q.pop();
    //     temp.push(t);
    // }
    // while(!temp.empty()){
    //     int t = temp.top(); temp.pop();
    //     cout << t << " ";
    //     q.push(t);
    // }
    // cout << "\n";
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);     
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> board[i][j];
        }
    }
    int ans = quad(N, 0, 0);
    // cout << "(";
    stack<int>temp;
    while(!q.empty()){
        int t = q.top(); q.pop();
        temp.push(t);
    }
    while(!temp.empty()){
        int t = temp.top(); temp.pop();
        if(t == -1)
            cout << "(";
        else if(t == -2)
            cout << ")";
        else
            cout << t;
    }
    // cout << ")";
}
/*
고생해서 풀었는데, 그래도 한 번에 맞춰서 행복하다.
괄호 순서, 개수와 합쳐야 하는 종이를 처리하는 게 제일 힘들었다.
주어진 N을 4사분면으로 나누어서 각 사분면을 iterate 한다.
각 사분면의 결과값을 스택에 저장한다.
다만 각 사분면이 하나만의 결과를 나타낸다면 괄호를 넣지 않는다.
만약 한 사분면이 또다시 4개의 결과를 쪼개진다면 괄호를 넣는다.
그 다음에 스택을 거꾸로 print 한다
*/