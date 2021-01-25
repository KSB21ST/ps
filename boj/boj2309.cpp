#include<bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int sum = 0;
    vector<int>v(9);
    vector<int>num(101);
    for(auto &k:v){
        cin >> k;
        num[k] += 1;
        sum += k;
    }
    sum = sum - 100;
    sort(v.begin(), v.end());
    for(auto k:v){
        if (num[sum - k] >= 1){
            num[k] -= 1;
            num[sum - k] -= 1;
            break;
        }
    }
    for(int count = 0;count<101;count++){
        for(int i=1;i<=num[count];i++){
            cout << count << "\n";
        }
        // cout << num[count] << endl;
    }

}

/*
O(n) 으로 코드를 작성하기 위해 num(101) 짜리 벡터를 씀
헷갈렸던 부분 > 중복되는 요소가 여러개 있으면 한 번만 -1 을 해줘야 하고,
중복된 만큼 프린트해줘야 한다.
*/