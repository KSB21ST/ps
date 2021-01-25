#include <bits/stdc++.h>

using namespace std;
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> v(5);
    int sum = 0;
    for(auto &k:v){
        cin >> k;
        sum += k;
    }

    sort(v.begin(), v.end());
    cout << sum/5 << "\n" << v[2];
}

//ios_base::sync_with_stdio(0), cin.tie(0)
//auto 
//for(auto &k:v)
//vector algorithm sort