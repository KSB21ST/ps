#include <bits/stdc++.h>
using namespace std;
int board[20];
int vis[1000001];
int N = 0;
queue<int>Q;
queue<int> NQ;

int make_bin(int t, int *bin, int s){
    fill(bin, bin + s, 0);
    int idx = 0;
    while(t){
        bin[idx] = t % 2;
        idx++;
        t = t / 2;
    }
    return idx;
}

int cnt_diff(int *a, int *b, int s){
    int cnt = 0;
    for(int i=0;i<s;i++){
        if(a[i] != b[i]){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 0;
    int t = 0;
    cin >> N;
    cin >> n;
    vector<int>tv;
    while(n--){
        cin >> t;
        tv.push_back(t);
    }
    int init[20];
    int max_len = make_bin(N, init, 20);
    vector<int *>v;
    for(auto k:tv){
        int arr[max_len];
        make_bin(k, arr, max_len);
        v.push_back(arr);
    }
}

/*
풀이
https://imksh.com/47
c++ 로 짠 코드
https://geniusjo-story.tistory.com/503
https://blog.naver.com/PostView.naver?blogId=jinhan814&logNo=222649636251&categoryNo=11&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView
*/