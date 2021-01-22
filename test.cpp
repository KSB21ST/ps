#include <iostream>

using namespace std;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    string s;
    getline(cin, s);
    cout << s;
}