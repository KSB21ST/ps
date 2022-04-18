#include <bits/stdc++.h>
using namespace std;
void find(int k, int l, int a, int b, int idx){
    // cout << "k: " << k << " l: " << l << " a: " << a << " b: " << b << " idx: " << idx << "\n";
    if(k == 0){
        cout << a << " " << b;
        return;
    }
    int unit = pow(2, k-1);
    int block = unit*unit;
    if(idx == 1){
        if(l <= block){
            find(k-1, l, a, b, 2);
        }else if(l > block && l <= block*2){
            find(k-1, l - block, a, b+unit, 1);
        }else if(l > block*2 && l <= block*3){
            find(k-1, l - block*2, a+unit, b+unit, 1);
        }else{
            find(k-1, l - block*3, a+unit*2-1, b+unit-1, 3);
        }
    }else if(idx == 2){
        if(l <= block){
            find(k-1, l, a, b, 1);
        }else if(l > block && l <= block*2){
            find(k-1, l - block, a+unit, b, 2);
        }else if(l > block*2 && l <= block*3){
            find(k-1, l - block*2, a+unit, b+unit, 2);
        }else{
            find(k-1, l - block*3, a+unit-1, b+unit*2-1, 4);
        }
    }else if(idx == 3){
        if(l <= block){
            find(k-1, l, a, b, 4);
        }else if(l > block && l <= block*2){
            find(k-1, l - block, a-unit, b, 3);
        }else if(l > block*2 && l <= block*3){
            find(k-1, l - block*2, a-unit, b-unit, 3);
        }else{
            find(k-1, l - block*3, a-unit+1, b-unit*2+1, 1);
        }
    }else{
        if(l <= block){
            find(k-1, l, a, b, 3);
        }else if(l > block && l <= block*2){
            find(k-1, l - block, a, b-unit, 4);
        }else if(l > block*2 && l <= block*3){
            find(k-1, l - block*2, a-unit, b-unit, 4);
        }else{
            find(k-1, l - block*3, a-unit*2+1, b-unit+1, 2);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    int k = 0;
    while(n){
        n = n/2;
        k++;
    }
    find(k-1, l, 1, 1, 1);
}

/*
스스로 힘으로 맞았지만 생각보다 오래걸림.
전체 판을 4등분해서 각 등분을 꼭짓점으로 순서대로 이으면 ㄷ자 모양이 됨.
ㄷ 자로 규칙을 만들어서 ㄷ 자를 90도씩 회전 시킨거를 각각 1, 2, 3, 4로 find의 idx에 넣어줌.
그거에 따라서 recursive 하게 몇 번째 사분면인지 파악하고, 결국 1*1이 남을 때까지 반복함.
오래 거린 이유는... 아이디어는 거의다 맞았으나 index 더해주고 빼줄 때 unit을 헷갈려서 자꾸 오차가 나게 됨 (아이디어는 맞앗음 ㅠㅠ)
*/