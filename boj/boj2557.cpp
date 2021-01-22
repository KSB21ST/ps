#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    int mini = 100;
    for(int i=0;i<7;i++){
        int n;
        cin >> n;
        if(n % 2 != 0){
            sum += n;
            mini = min(n, mini);
        }
    }
    if(sum == 0){
        cout << -1;
    }else{
        cout << sum << endl << mini << endl;
    }
    
}